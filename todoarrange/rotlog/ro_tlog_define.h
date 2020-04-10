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
    //技术中心特别要求打印到独立文件
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
    bool BuildTlogTxt(std::string * str)//返回组成Txt格式
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
    bool BuildJson(std::string * str)//返回组成json
    {
        if (!str)
        {
            return false;
        }
        DoAddJson();
        str->clear();
        str->append("{\"_app\":\"ro_tlog\",");

		str->append("\"_accountid\":\"");
		//str->append(std::to_string(GameTime::GetTime()));//应该写用户id，没有就填时间
		str->append("");//账户id在各个事件独立的表里有，这里就不要另外去填写了
		str->append("\",");

		str->append("\"_distinctid\":\"");
		str->append("");
		str->append("\",");

		str->append("\"_eventname\":\"");
		str->append(GetTableName());
		str->append("\",");

		str->append("\"_ip\":\"");
		str->append("");//ip在各个事件独立的表里有，这里就不需要另外填写了。
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
    //短日期 yyyy-mm-dd 用来形成本地文件名字
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