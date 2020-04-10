#ifndef __RO_TLOG_DEFINE_H__
#define __RO_TLOG_DEFINE_H__
#include <string>
#include <vector>
#include <list>
#include "singleton.h"
#include "util/gametime.h"


class ROTlogBase
{
public:
    ROTlogBase(){};
    virtual ~ROTlogBase() {};

    inline void AddLog(const std::string& key, const std::string& value)
    {
        keys_.emplace_back(key);
        values_.emplace_back(value);
    }
    inline void AddLogJson(const std::string& value)
    {
        //keys_.emplace_back(key);
        json_values_.emplace_back(value);
    }
    inline void SetSpecialUserTable(bool b)
    {
        is_user_table_ = b;
    }
    inline bool IsSpecialUserTable()
    {
        return is_user_table_;
    }
private:
    std::vector<std::string> keys_;
    std::vector<std::string> values_;
    std::vector<std::string> json_values_;
    //���������ر�Ҫ���ӡ�������ļ�
    bool is_user_table_{ false };
public:
    virtual const char* GetTableName() = 0;
    virtual void DoAdd() = 0;
    virtual void DoAddJson() = 0;
    virtual bool Parse(uint64_t role_id)
    {
        day_time = GameTime::GetTimeStringShortNow();
        return true;
    }
    bool BuildTlogTxt(std::string * str)//�������Txt��ʽ
    {
        if (!str)
        {
            return false;
        }
		keys_.clear();
		values_.clear();
        DoAdd();
        str->clear();
        str->append(GetTableName());
        for (auto & log : values_)
        {
            CheckTlogString(&log);
            str->append("|").append(log);
        }
        str->append("\n");
        return true;
    }
    bool BuildJson(std::string * str)//�������json
    {
        if (!str)
        {
            return false;
        }
        DoAddJson();
        str->clear();
        str->append("{\"_app\":\"ro_tlog\",");

		str->append("\"_accountid\":\"");
		//str->append(std::to_string(GameTime::GetTime()));//Ӧ��д�û�id��û�о���ʱ��
		str->append("");//�˻�id�ڸ����¼������ı����У�����Ͳ�Ҫ����ȥ��д��
		str->append("\",");

		str->append("\"_distinctid\":\"");
		str->append("");
		str->append("\",");

		str->append("\"_eventname\":\"");
		str->append(GetTableName());
		str->append("\",");

		str->append("\"_ip\":\"");
		str->append("");//ip�ڸ����¼������ı����У�����Ͳ���Ҫ������д�ˡ�
		str->append("\",");

		str->append("\"value\":{");

		size_t i = 1;
        for (auto & log : json_values_)
        {
            CheckTlogString(&log);
			str->append(log);
			if (i<json_values_.size())
			{
				str->append(",");
			}
			i++;

        }
        str->append("}}");
        return true;
    }

public:
    //������ yyyy-mm-dd �����γɱ����ļ�����
    std::string day_time{ "" };

public :
    static std::string RemoveVerticalLine(const std::string& origin_str)
    {
        std::string x;
        x.reserve(origin_str.size());
        for (const char c : origin_str)
        {
            if (c != '|' && c != '\t'
                && c != '\r' && c != '\n'
                && c != ' ')
            {
                x += c;
            }
        }
        return x;
    }

    static void CheckTlogString(std::string* tlog_string)
    {
        if (tlog_string)
        {
            for (auto &s : *tlog_string)
            {
                if (s == '\0' || s == '\r' || s == '\n' || s == '|')
                {
                    s = ' ';
                }
            }
        }
    }
};




#endif