#include <cstdlib>
#include <iostream>
#include <thread>
#include <list>
#include <chrono>
#include "robot_config.h"
#include "robot_client.h"
#include "protocol_wrap.h"
#include "internal/RoRobot.h"
#include "robot_manager/robot_table_manager.h"
#include "table/template/profession_table.h"
#include "table/template/skill_table.h"
#include "coder.h"
#include "robot_buff_manager.h"
#include "pb/pbc_common.pb.h"
#include <pb/pbc_team.pb.h>
#include "rogamelibs/scene/fight_group_config.h"
#include "pb/pbc_team.pb.h"
#include "table/template/team_target_table.h"
#include "scene/fight_group_config.h"
#include "util.h"
#include "http_handler.h"
#include "define/itemdef.h"
#include "rogamelibs/table/template/task_table.h"


std::map<uint32_t, std::vector<uint32_t>> CRobotClient::all_skill_id;
std::vector<uint32_t> CRobotClient::all_scene_id;
std::map<uint32_t, std::vector<float>> CRobotClient::all_skill_sing_time;
std::map<uint32_t, uint32_t> CRobotClient::all_skill_target;
std::map<uint32_t, std::vector<uint32_t>> CRobotClient::all_barber;
std::map<uint32_t, std::vector<uint32_t>> CRobotClient::all_eye;
std::map<uint32_t, KKSG::Vec3> CRobotClient::all_field_map;
std::vector<uint32_t> CRobotClient::all_field_id;
std::map<uint32_t, std::vector<std::pair<uint32_t, uint32_t>>> CRobotClient::patrol_way;
std::map<uint32_t, std::vector<std::pair<uint32_t, uint32_t>>> CRobotClient::patrol_gate;
std::vector<uint32_t> CRobotClient::patrol_scene;
int CRobotClient::profession_tree[10000];
bool isPvp;

uint32_t CRobotClient::added_account_count_ = 0;//本次新创建的账户数量

uint32_t CRobotClient::added_role_count_ = 0;//本次新创建的角色数量

std::map<uint32_t, uint32_t> SReadMessageDynamic::all_id_2_type;

std::map<uint32_t, uint32_t> SWriteMessage::all_id_2_type;

RobotModuleType RobotModuleBase::module_type_counter_ = 0;

void CRobotClient::OnTimer(const asio::error_code& error)
{
    //每一帧调用
    if (!error)
    {
        //if (need_reset_bt_)
        //{
        //    need_reset_bt_ = false;
        //    OnResetWorkFrame();
        //}
        //else
        {
            //std::cout << " timer handler " << std::endl;
		    //每一帧处理
            CheckBTRunTimeLate();
            OnRunWorkFrame();
        }

        if (login_2_gate_)
        {
            //保持心跳
            auto now = std::chrono::system_clock::now();
            auto diff_second = (now - send_sync_timepoint_).count() / std::chrono::microseconds::period::den / 10;
            if (diff_second >= 60 * 3)
            {
                send_sync_timepoint_ = now;
                SendSyncTime();
            }
        }


        //自己触发下一帧 
        timer_.expires_from_now(std::chrono::milliseconds(timer_elapse_milliseconds_));

        //每一帧都恢复
        if (timer_elapse_milliseconds_ != MESSAGE_HANDLER_TIMER_MILLISECOND)
        {
            PushActionName("timer wait [" + std::to_string(timer_elapse_milliseconds_) +  "]");
        }
        timer_elapse_milliseconds_ = MESSAGE_HANDLER_TIMER_MILLISECOND;
        timer_.async_wait([this](const asio::error_code& error) {this->OnTimer(error); });
    }
    else
    {
        PushActionName("CRobotClient::OnTimer error");
    }

}


//处理基础的ntf通知,不可被行为树随便丢弃
bool CRobotClient::HandleBasicNtf(SReadMessage & _t)
{
    switch (_t.GetType())
    {
    case PTCT2C_ERRORNOTIFY_TYPE:
    {
        KKSG::ErrorInfo notify;
        if (notify.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
        }
        break;
    }
    case PTCG2C_UNITAPPEAR_TYPE:
    {
        UnitAppearList appearlist;
        if (appearlist.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
           OnUnitAppear(appearlist);
           Get<CSync>()->OnUnitAppear(appearlist);
        }
        else
        {
        }
        return true;

        break;
    }
    case PTCG2C_SYNCUNIT_TYPE:
    {
        //KKSG::SyncUnit data;
        //if (data.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        //{
        //    if (data.has_role())
        //    {
        //        //設置性別 
        //        select_role_ntf_data_.mutable_roledata()->mutable_brief()->set_type(data.role().role_type());
        //    }
        //}XXXXXXXXXXXXXX
        //return true;

        break;
    }
    case PTCG2C_SYNCWALLSTATUSNOTITY_TYPE:
    {
        //墙的处理
        //current_wall_data_.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength());
        return true;

        break;
    }
    case PTCG2C_SYNCENTERWALLNOTITY_TYPE:
    {
        //墙的处理
        //current_enterwall_.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength());
        return true;

        break;
    }
    case PTCG2C_ENTERSCENENTF_TYPE:
    {
        all_monster_.clear();
        all_player_.clear();

        Get<CSync>()->ClearUnits();

        //切场景的通知,应该在底层处理
        scene_cfg_.Clear();
        scene_cfg_.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength());
        current_scene_id_ = scene_cfg_.sceneid();

        KKSG::SceneCfg scene_cfg;
        scene_cfg.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength());
        Get<CSync>()->UpdateScene(scene_cfg);

        is_enterscene_ntf_ = true;

        return true;

        break;
    }
    case PTCG2C_UNITDISAPPEAR_TYPE:
    {
        UnitDisappearData disappear;
        if (disappear.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            OnUnitDisappear(disappear);
            Get<CSync>()->OnUnitDisappear(disappear);
        }
        else
        {
        }
        return true;

        break;
    }
    case PTCG2C_SELECTROLENTF_TYPE:
    {
        if (select_role_ntf_data_.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            //职业
            //坐标
            Get<CRole>()->FillRoleAllInfo(select_role_ntf_data_.roledata());

            current_pos_x_ = select_role_ntf_data_.roledata().brief().position().x();
            current_pos_y_ = select_role_ntf_data_.roledata().brief().position().y();
            current_pos_z_ = select_role_ntf_data_.roledata().brief().position().z();
            current_pos_face_ = select_role_ntf_data_.roledata().brief().face();
            current_scene_id_ = select_role_ntf_data_.roledata().brief().sceneid();
            is_role_select_ = true;

            InitBagWhenSelectRole();

            is_selectrole_ntf_ = true;
        }

        return true;
        break;
    }

    case PTCG2C_TRANSFERPROFESSION_TYPE:
    {
        TransferProfessionData type;
        type.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength());

        Get<CRole>()->ChangeProfession(type.role_type());
        return true;
        break;
    }

    case PTCG2C_SYNCSTEPNOTIFY_TYPE:
    {
        StepSyncList syninfo;
        if (syninfo.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            OnStepSyncInfo(syninfo);
            OnUnitPostionSync(syninfo);
            Get<CSync>()->OnStepSyncInfo(syninfo);
        }
        else
        {
        }
        return true;
        break;
    }
    case PTCG2C_ITEMCHANGENTF_TYPE:
    {
        ItemChange info;
        if (info.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            OnItemChangeNtf(info);
        }
        return true;
        break;
    }
    case PTCM2C_SYNCARENAROOMBRIEFINFONTF_TYPE:
    {
        ArenaRoomInfo m_DAta;
        if (m_DAta.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            UpdataArenaRoomInfo(m_DAta);

            //现在不判断finish状态,直接副本结束踢出副本.
            if (m_DAta.state() == KKSG::Arena_Open_Playing)
            {
                is_arena_finished_ = true;
            }
        }

        return true;

        break;
    }
    case PTCM2C_ARENAROOMSTATENTF_TYPE:
    {
        //ArenaRoomStateData arg;
        //if (arg.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        //{
        //    if (arg.state() == KKSG::ARENA_ROOM_STATE_SETTLE)
        //    {
        //        is_arena_finished_ = true;
        //    }
        //}
        return true;
        break;
    }
    // 任务相关
    case PTCG2C_TASKUPDATE_TYPE:
    {
        KKSG::TaskUpdateData m_Data;
        if (m_Data.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {
            Get<CTask>()->AnalyseTaskUpdateData(m_Data);
        }
        return true;

        break;
    }
    // 任务处理
    /*case PTCG2C_TASKALLINFO_TYPE:
    {
        break;
    }*/
    // 组队处理,投票进入副本
    case PTCM2C_ASKMEMBERENTERFBNTF_TYPE:
    {
        KKSG::AskMemberEnterFBData ask_member_data;
        if (ask_member_data.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
        {

            enter_dungeon_member_ask_dungeon_id_ = ask_member_data.dungeon_id();
            enter_dungeon_member_ask_chapter_id_ = ask_member_data.chapter_id();

        }

        break;
    }
    case PTCM2C_CHATTINGMSGNOTIFY_TYPE:
    {
        //广播聊天直接无视
        return true;
        break;
    }
    case PTCT2C_CHATTINGMSGNTF_TYPE:
    {
        //广播聊天直接无视
        return true;
        break;
    }
    case 123:
    {
        break;
    }


    default:
        break;
    }

    if (team_com.ProcessTeamMsg(_t))
    {
        return true;
    }

    //任务处理
    //else if (_t.GetType() == PTCG2C_TASKALLINFO_TYPE)
    //{
    //    //完整任务更新
    //    all_task_data.Clear();
    //    if (all_task_data.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
    //    {
    //        all_acceptable_ids.clear();
    //        for (size_t i = 0; i < all_task_data.linearacceptable_size(); ++i)
    //        {
    //            all_acceptable_ids.push_back(all_task_data.linearacceptable(i).task_id());
    //        }

    //    }
    //    return true;
    //}
    //else if (_t.GetType() == PTCG2C_TASKINFOUPDATE_TYPE)
    //{  
    //    //单个任务更新
    //    KKSG::TaskInfo task_info;
    //    if (task_info.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
    //    {
    //        for (size_t i = 0 ;i < all_task_data.currenttasks_size(); ++i)
    //        {
    //            auto * task = all_task_data.mutable_currenttasks(i);
    //            if (task->task_id() == task_info.task_id())
    //            {
    //                task->CopyFrom(task_info);
    //                return true;
    //            }
    //        }
    //        auto* task = all_task_data.add_currenttasks();
    //        task->CopyFrom(task_info);
    //    }
    //}
    //else if (_t.GetType() == PTCG2C_TASKTRIGGEREVENTALLNOTIFY_TYPE)
    //{
    //    //所有触发器
    //    KKSG::TaskTriggerEventAllNotify all_trigger_data;
    //    if (all_trigger_data.ParseFromArray(_t.GetPtcBody(), _t.GetPtcLength()))
    //    {
    //        all_task_data.clear_tasktriggerevents();
    //        for (size_t i = 0; i < all_trigger_data.allevents_size(); ++i)
    //        {
    //            auto* trigger = all_task_data.add_tasktriggerevents();
    //            auto & new_trigger = all_trigger_data.allevents(i);
    //            trigger->CopyFrom(new_trigger);
    //        }
    //    }
    //}


    return false;
}


uint32_t CRobotClient::GetRandomSkillID()
{
    if(all_skill_id.empty())
    {
        return 0;
    }
    auto i = Dice(0, all_skill_id.size()-1);
    auto it = all_skill_id.begin();
    while(i-->0 && it!=all_skill_id.end())
    {
        ++it;
    }
    auto& j = it->second;
    if(j.empty())
    {
        return 0;
    }
    return j[Dice(0, j.size() - 1)];
}


//void CRobotClient::OnResetWorkFrame()//重置工作帧
//{
//    if (p_robot_bt_)
//    {
//        p_robot_bt_->btsetcurrent(xml_name.c_str());
//    }
//
//}

void CRobotClient::OnRunWorkFrame()//处理工作帧
{
	//顺序处理当前的工作帧.并发的操作留给行为树来执行
	//先执行协议包的快速head读取
    //再执行工作帧的逻辑 
	//执行状态机行为树.
    // PushActionName("++++++++++++start+++++++++++++++++++++");

    //执行行为树
	if (p_robot_bt_)
	{
		behaviac::EBTStatus status = behaviac::BT_RUNNING;

		//while (status == behaviac::BT_RUNNING)
		{
			status = p_robot_bt_->btexec();
            //if (status == behaviac::BT_FAILURE)
            //{
            //    p_robot_bt_->;
            //}
		}
	}
}

void CRobotClient::CreateRandomName()
{

    PushActionName(__func__);

    //取新的名字以后, 人数+1
    login_count_ = 0;

#ifdef WIN32
#else
    WetestHttpHandler::Instance()->statistic_robot.robot_total_num++;
#endif



    static std::default_random_engine generator(time(NULL));
    static std::uniform_int_distribution<int> dis((int)'a', (int)'z');
    char name[11] = "";
    for (size_t i = 0; i<10; i++)
    {
        name[i] = static_cast<char>(dis(generator));
    }
    SetAccountName(name);
}


void CRobotClient::StartRpc()
{
    start_rpc_timepoint_ = std::chrono::system_clock::now();
}

bool CRobotClient::IsRpcLate(uint32_t cd)//true  rpc调用超时
{
    auto now = std::chrono::system_clock::now();
    auto diff_second = std::chrono::duration_cast<std::chrono::seconds>(now - start_rpc_timepoint_);

    if ( diff_second.count() >= cd )
    {
        //std::cout<< "++++++++++++++rpc late " << diff_second.count()<<std::endl;
        //超时

        ResetBtStatus(true);
        return true;
    }
    return false;
}


bool CRobotClient::CheckBTRunTimeLate()
{
    static std::chrono::system_clock::time_point start_bt_timepoint_ = std::chrono::system_clock::now();


    auto now = std::chrono::system_clock::now();
    auto diff_second = std::chrono::duration_cast<std::chrono::seconds>(now - start_bt_timepoint_);

    if (diff_second.count() >= 1)
    {
        PushActionName("CheckBTRunTimeLate late [" + std::to_string(diff_second.count()) + "]");
    }

    start_bt_timepoint_ = now;
    return true;
}


bool CRobotClient::ParseBTFromXml(std::string xmlFile)
{
    //xml_name = xmlFile;
	p_robot_bt_ = behaviac::Agent::Create<RoRobot>(account_name_.c_str());//
	bool bRet = p_robot_bt_->btload(xmlFile.c_str());
	if (bRet)
	{
		p_robot_bt_->btsetcurrent(xmlFile.c_str());
		p_robot_bt_->SetRobotClient(this);

	}
	return bRet;
}

void CRobotClient::SendLocalGMCmd(std::string gmcmd)
{
    PushActionName(__func__);
    PushActionName(gmcmd);
    LocalGMCmdArg arg;
	{
        static int profession[5] = { 2000,3000,4000,5000,7000 };
        if ( "transprofession" == gmcmd.substr(0,15) )
        {
            std::stringstream ss;
            if ("transprofession" == gmcmd) {
                std::default_random_engine generator(time(NULL));
                std::uniform_int_distribution<int> dis(0, 4);
                static std::function<int()> dice = std::bind(dis, generator);
                int random_profession = profession[dice()];
                ss << gmcmd << " " << random_profession;
            }
            else {
                int profession = atoi(gmcmd.substr(16, gmcmd.size() - 1).c_str());
                ss << gmcmd << " " << profession;
            }
            arg.set_cmd_and_args(ss.str());
        }
        else
        {
            arg.set_cmd_and_args(gmcmd);
        }
		PACK_SEND(arg, ClientProtocolHead, PTCC2G_LOCALGMCMD_TYPE, PTC_TYPE_FLAG);
	}
}

void CRobotClient::SendGMCmdGotoMonsterPos()
{
    std::cout << "SendGMCmdGotoMonsterPos  " << std::endl;
    std::stringstream ss;
    ss << "goto " << current_target_des_x_  << " "<< current_target_des_y_ << " "<<current_target_des_z_;
    LocalGMCmdArg arg;
    arg.set_cmd_and_args(ss.str());
    PACK_SEND(arg, ClientProtocolHead, PTCC2G_LOCALGMCMD_TYPE, PTC_TYPE_FLAG);
    SetLocalPos(current_target_des_x_, current_target_des_y_, current_target_des_z_);
}

void CRobotClient::SendGMCmdAddBuff()
{
    PushActionName(__func__);
    int32_t num = BuffManager::Instance()->GetIdByLine();
    // std::cout << "addbuff buffid = "<<num << std::endl;
    SendLocalGMCmd("addbuff " + std::to_string(num));
}


void CRobotClient::PushActionName(const std::string & action_name)
{
    if (robot_id_ == 1)
    {
        //定义毫秒级别的时钟类型
        typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> microClock_type;
        //获取当前时间点，windows system_clock是100纳秒级别的所以要转换
        microClock_type tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

        std::cout << tp.time_since_epoch().count() <<std::to_string(robot_id_) << "   " << action_name << std::endl;
    }
    else
    {
        RobotConfig::Instance()->AddLog(std::to_string(robot_id_) + std::string("   ") + action_name);
    }
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //只保留最后100个动作
 //   SClientProfile s;
	//s.action = action_name;
	//s.count = 1;
 //   if (all_actions_.begin() != all_actions_.end())
 //   {
 //       auto & front = *(all_actions_.begin());
 //       if (front.action == action_name)
 //       {
 //           front.count++;
 //       }
 //       else
 //       {
 //           all_actions_.push_front(s);
 //       }
 //   }
 //   else
 //   {
 //       all_actions_.push_front(s);
 //   }
 //   if (all_actions_.size() > 100)
 //   {
 //       all_actions_.pop_back();
 //   }
}

void CRobotClient::ResetBtStatus(bool need_delay)
{
    PushActionName(__func__);
    state_ = 0;
    all_actions_count_ = 0 ;
    //will_do_profile_ = false ;
    is_dead_ = false ;
    is_login_ = false;
    is_role_select_ = false ;
    isPvP =  false ;
    is_create_ = false ;
    is_target_position_ =  false ;
    is_has_target_ = false ;
    is_patrol_ = false ;
    is_change_scene_ = false ;
    is_battle_field = true ;
    is_enterscene_ntf_ = false;
    is_selectrole_ntf_ = false;
    change_role_name_failed_ = false;
    if(need_delay)
    {
        timer_elapse_milliseconds_ = MESSAGE_HANDLER_TIMER_MILLISECOND_DELAY;
    }
}

void CRobotClient::UpdateVirtualItem(int32_t type, int32_t count)
{
    virtual_item_type_2_count[type] = count;
}

//检查数量
void CRobotClient::InitVirtualItem(int32_t type, int32_t count)
{
    if (virtual_item_type_2_count[type] != 0
        && virtual_item_type_2_count[type] != count)
    {
        std::string name = "None";
        switch (type)
        {
            case ZENY:
            {
                name = "ZENY";
            }
            break;
            case ROMONEY:
            {
                name = "ROMONEY";
            }
            break;
            case DIAMOND:
            {
                name = "DIAMOND";
            }
            break;
            case EXP:
            {
                name = "EXP";
            }
            break;
            case JOB_EXP:
            {
                name = "JOB_EXP";
            }
            break;
            case BOLI_POINT:
            {
                name = "BOLI_POINT";
            }
            break;
            case VITALITY:
            {
                name = "VITALITY";
            }
            break;
            case DELEGATION:
            {
                name = "DELEGATION";
            }
            break;
            case GUILD_CONTRIBUTION:
            {
                name = "GUILD_CONTRIBUTION";
            }
            break;
            case PRESTIGE:
            {
                name = "PRESTIGE";
            }
            break;
            case AREAN_COIN:
            {
                name = "AREAN_COIN";
            }
            break;
            case BATTLEFIELD_COIN:
            {
                name = "BATTLEFIELD_COIN";
            }
            break;
            case JIANSHI_ARMORY:
            {
                name = "JIANSHI_ARMORY";
            }
            break;
            case DAOZEI_ARMORY:
            {
                name = "DAOZEI_ARMORY";
            }
            break;
            case SHENGGEJIAOHUI_ARMORY:
            {
                name = "SHENGGEJIAOHUI_ARMORY";
            }
            break;
            case QISHITUAN_ARMORY:
            {
                name = "QISHITUAN_ARMORY";
            }
            break;
            case YUANDONGSHANGHUI_ARMORY:
            {
                name = "YUANDONGSHANGHUI_ARMORY";
            }
            break;
            case FUSHI_ARMORY:
            {
                name = "FUSHI_ARMORY";
            }
            break;
            case SHANGREN_ARMORY:
            {
                name = "SHANGREN_ARMORY";
            }
            break;
            case GONGJIANSHOU_ARMORY:
            {
                name = "GONGJIANSHOU_ARMORY";
            }
            break;
            case MOFASHI_ARMORY:
            {
                name = "MOFASHI_ARMORY";
            }
            break;
            case ASSIST_POINT:
            {
                name = "ASSIST_POINT";
            }
            break;
            case QQ_POINT:  //直购测试临时使用
            {
                name = "QQ_POINT";
            }
            break;
            default:
                break;
        }
            
            
        WetestHttpHandler::Instance()->StartAndCommitTransInfo(robot_id_, name+"_SYNC_FAILED", type, WETEST_FAILED);
    }
    virtual_item_type_2_count[type] = count;
}

