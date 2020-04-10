#include "pch.h"
#include <atomic>
#include "rotlog/ro_tlog_mgr.h"
#include "util/gametime.h"
#include "tlog/tlog_mgr_local.h"
//#include "thirdparty/tglogsdk/dist/include/TGLogClient.h"
#ifdef __linux__
#include "tglogsdk/third_party/include/tsf4g/tlog/tlog.h"
#include "tglogsdk/third_party/include/tsf4g/tloghelp/tlogload.h"
#include "tglogsdk/third_party/include/tsf4g/tlog/tlog_category.h"
#include "tglogsdk/third_party/include/tb/token_bucket.h"
//#include "config.h"
#endif // __linux__

#include <curl/curl.h>
#include <iostream>
#include <chrono>

bool RoTlogMgrBase::Init()
{
    SetTlogFileNamePrefix();

    // �����߳�
    worker_thread_ = new std::thread([this]()
    {

        while (!close_thread_)
        {
            this->DoWrite();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        this->FlushFile();
    }
    );

    wait_timepoint_ = CTimerMgr::Instance()->SetTimer(
        DelegateCombination(RoTlogMgrBase, DoCheckExchange, this),
        nullptr,
        nullptr,
        1 * 5 * 1000,
        -1,
        __FILE__,
        __LINE__
    );



#ifdef __linux__
    //��Ѷsdk
    if (RoTlogMgr::Instance()->IsTlogToTx())
    {
        log_ctx_ = tlog_init_from_file("gsconf/serveronly/tlog_cfg.xml");
        if (NULL == log_ctx_)
        {
            LogError("tlog_init_from_file() failed...");
            return false;
        }
    }
#endif // __linux__
    return true;
}

void RoTlogMgrBase::Uninit()
{
    if (worker_thread_)
    {
        close_thread_ = true;
        worker_thread_->join();
        delete worker_thread_;
    }

    for (auto& v : in_buff_list_)
    {
        DeleteTlogObject(v);
    }
    in_buff_list_.clear();

    for (auto& v : out_buff_list_)
    {
        DeleteTlogObject(v);
    }
    out_buff_list_.clear();

    if (wait_timepoint_ != INVALID_HTIMER)
    {
        CTimerMgr::Instance()->KillTimer(wait_timepoint_);
        wait_timepoint_ = INVALID_HTIMER;
    }

#ifdef __linux__
    //>>>> sdk
    //�ͷ�TLog����
    if (NULL != log_ctx_)
    {
        tlog_fini_ctx(&log_ctx_);
        log_ctx_ = NULL;
    }
#endif // __linux__

}

void RoTlogMgrBase::AddTlog(ROTlogBase * tlog)  //�߳�2
{
    if (tlog)
    {
        in_buff_list_.push_back(tlog);
    }

}

void RoTlogMgrBase::WriteLocalFile(ROTlogBase * tlog)
{
    if (!tlog)
    {
        return;
    }
    uint32_t idx = NORMAL_FILE_IDX;
    if (tlog->IsSpecialUserTable())
    {
        idx = USER_FILE_IDX;
    }

    if (today_time_[idx] != tlog->day_time)
    {
        today_time_[idx] = tlog->day_time;
        //���´��ļ�

        if (tlog_ofs_[idx])
        {
            fflush(tlog_ofs_[idx]);
            fclose(tlog_ofs_[idx]);
            tlog_ofs_[idx] = nullptr;
        }
    }
    if (!tlog_ofs_[idx])
    {
        std::string filename = "./log/"+ special_tlog_file_name_prefix_[idx] + "tlog-" + tlog_file_name_prefix_ + +"-" + today_time_[idx] + ".tlog";
        tlog_ofs_[idx] = fopen(filename.c_str(), "a");
    }
    std::string log;
    tlog->BuildTlogTxt(&log);
    if (!tlog_ofs_[idx])
    {
        //�����������,��һ����־�������־�Ͷ���
        LogError("tlog_ofs_ empty  failed...%s", log.c_str());

    }
    else
    {
        fprintf(tlog_ofs_[idx], "%s", log.c_str());
    }
}

void RoTlogMgrBase::FlushFile()
{
    for (uint32_t idx =0 ; idx < MAX_FILE_IDX; idx ++)
    {
        if (tlog_ofs_[idx])
        {
            fflush(tlog_ofs_[idx]);
            fclose(tlog_ofs_[idx]);
            tlog_ofs_[idx] = nullptr;
        }
    }
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *return_str)
{
    *((std::string*)return_str) = std::string((const char*)ptr, (size_t)size * nmemb);
    return size * nmemb;
}


void RoTlogMgrBase::DoWrite()   //�߳�1  
{
    if (exchange_lock_.TryLock())
    {
        if (!worker_free_)
        {
            auto start = std::chrono::high_resolution_clock::now();

            //������־����ִ�����
            std::string log;
            for (auto * rolog : out_buff_list_)
            {

                //��Ҫ�ڴ�����ִ��curlͶ��--2019-11-02
                ////д�����ֻ�������ݣ�ͨ��д�����ļ����

#ifdef __linux__

                //д����Ѷ�ӿ�
                if (RoTlogMgr::Instance()->IsTlogToTx())
                {
                    //��ȡtlog��־���
                    rolog->BuildTlogTxt(&log);
                    LPTLOGCATEGORYINST tlog = tlog_get_category(log_ctx_, "tutorial_tlog");
                    if (!tlog)
                    {
                        LogError("tlog_get_category() failed...");
                    }
                    else
                    {
                        tlog_error(tlog, 0, 0, "%s", log.c_str());
                    }
                }
#endif // __linux__
                //д���ļ�,��һ�ֱ���
                if (RoTlogMgr::Instance()->IsTlogToLocal())
                {
                    //��־���뱾���ļ�������д������error��־
                    WriteLocalFile(rolog);             
                }
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            if (diff.count() > 0.3)
            {
                LogWarn(" handle tlog cost [%f]", float(diff.count()));
            }

            //���屾���ļ�д��
            //ÿ��д�꣬���ر��ļ�����֤��һ������������
            FlushFile();

            //�ͷų���Ȩ
            worker_free_ = true;
        }
        exchange_lock_.UnLock();
    }
}

bool RoTlogMgrBase::DoCheckExchange(IArgs *, void *)   //�߳�2  ��ʱ�� 2��
{
    if (exchange_lock_.TryLock())
    {
        if (worker_free_)
        {
            if (in_buff_list_.size() > 2000
                || out_buff_list_.size() > 2000)
            {
                LogWarn("in_buff_list_ size[%d], out_buff_list_ size[%d]", in_buff_list_.size(), out_buff_list_.size());

            }

            worker_free_ = false;
            in_buff_list_.swap(out_buff_list_);

            //�ͷ���־����
            for (auto & i : in_buff_list_)
            {
                DeleteTlogObject(i);
            }
            if (in_buff_list_.size() > 2000)
            {
                LogWarn("delete tlog object [%d]", in_buff_list_.size());

            }

            in_buff_list_.clear();


        }
        exchange_lock_.UnLock();
    }

    return true;
}
