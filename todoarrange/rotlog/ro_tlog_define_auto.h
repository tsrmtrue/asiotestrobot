#ifndef __RO_TLOG_DEFINE_AUTO_H__
#define __RO_TLOG_DEFINE_AUTO_H__

#include "rotlog/ro_tlog_define.h"
template<typename T>
std::string ToStringTlog(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

namespace BaseTlogEnumEnum{

    enum class PlatID: uint32_t {
        IOS = 0,//IOS
        ANDROID = 1,//ANDROID 
    };    
    enum class Gender: uint32_t {
        MAN = 0,//男
        WOMAN = 1,//女 
    };    
    enum class JobId: uint32_t {
        Role_None = 0,//无定义
        Role_Novice = 1000,//初心者
        Role_SwordMan = 2000,//剑士
        Role_Knight = 2101,//骑士
        Role_LordKnight = 2102,//骑士领主
        Role_RuneKnight = 2103,//符文骑士
        Role_Crusader = 2201,//十字军
        Role_Paladin = 2202,//圣殿十字军
        Role_RoyalGuard = 2203,//皇家卫士
        Role_Acolyte = 3000,//服事
        Role_Priest = 3101,//牧师
        Role_HighPriest = 3102,//神官
        Role_ArchBishop = 3103,//大主教
        Role_Monk = 3201,//武僧
        Role_Champion = 3202,//武术宗师
        Role_Sura = 3203,//修罗
        Role_Magician = 4000,//法师
        Role_Wizard = 4101,//巫师
        Role_HighWizard = 4102,//超魔导士
        Role_Warlock = 4103,//大法师
        Role_Sage = 4201,//贤者
        Role_Professor = 4202,//智者
        Role_Sorcerer = 4203,//元素使
        Role_Thief = 5000,//盗贼
        Role_Assassin = 5101,//刺客
        Role_AssassinCross = 5102,//十字刺客
        Role_GuillotineCross = 5103,//十字切割者
        Role_Rogue = 5201,//流氓
        Role_Stalker = 5202,//神行太保
        Role_ShadowChaser = 5203,//逐影
        Role_Merchant = 6000,//商人
        Role_Blacksmith = 6101,//铁匠
        Role_WhiteSmith = 6102,//神工匠
        Role_Mechanic = 6103,//机匠
        Role_Alchemist = 6201,//炼金术士
        Role_Creator = 6202,//创造者
        Role_Genetic = 6203,//基因学者
        Role_Archer = 7000,//弓箭手
        Role_Hunter = 7101,//猎人
        Role_Sniper = 7102,//神射手
        Role_Ranger = 7103,//游侠
        Role_Bard_Dancer = 7201,//吟游诗人/舞娘
        Role_Clown_Gypsy = 7202,//搞笑艺人/冷艳舞姬
        Role_Minstrel_Wanderer = 7203,//宫廷乐师/漫游舞者 
    };    
    enum class AddOrReduce: uint32_t {
        ADD = 0,//增加
        REDUCE = 1,//减少 
    };    
    enum class SubReason: uint32_t {
        TO_PLAYER = 0,//流向玩家
        TO_SYSTEM = 1,//流向系统 
    };    
    enum class UnionJudge: uint32_t {
        SAME_GULID = 0,//非同公会
        DIFFERENT_GUILD = 1,//同公会 
    };    
    enum class DutyType: uint32_t {
        COMMON = 0,//成员
        VICECHAIRMAN = 1,//执事
        CHAIRMAN = 2,//会长 
    };    
    enum class FriendJudge: uint32_t {
        NOT_FRIEND = 0,//非好友
        SINGLE_FRIEND = 1,//单向好友
        DOU_FRIEND = 2,//双向好友 
    };    
    enum class DungeonNumberType: uint32_t {
        SINGLE = 0,//单人
        MULTI = 1,//多人 
    };    
};
namespace RoleCommonTlogBaseEnum{

    enum class PlatID: uint32_t {
        IOS = 0,//IOS
        ANDROID = 1,//ANDROID 
    };    
    enum class JobId: uint32_t {
        Role_None = 0,//无定义
        Role_Novice = 1000,//初心者
        Role_SwordMan = 2000,//剑士
        Role_Knight = 2101,//骑士
        Role_LordKnight = 2102,//骑士领主
        Role_RuneKnight = 2103,//符文骑士
        Role_Crusader = 2201,//十字军
        Role_Paladin = 2202,//圣殿十字军
        Role_RoyalGuard = 2203,//皇家卫士
        Role_Acolyte = 3000,//服事
        Role_Priest = 3101,//牧师
        Role_HighPriest = 3102,//神官
        Role_ArchBishop = 3103,//大主教
        Role_Monk = 3201,//武僧
        Role_Champion = 3202,//武术宗师
        Role_Sura = 3203,//修罗
        Role_Magician = 4000,//法师
        Role_Wizard = 4101,//巫师
        Role_HighWizard = 4102,//超魔导士
        Role_Warlock = 4103,//大法师
        Role_Sage = 4201,//贤者
        Role_Professor = 4202,//智者
        Role_Sorcerer = 4203,//元素使
        Role_Thief = 5000,//盗贼
        Role_Assassin = 5101,//刺客
        Role_AssassinCross = 5102,//十字刺客
        Role_GuillotineCross = 5103,//十字切割者
        Role_Rogue = 5201,//流氓
        Role_Stalker = 5202,//神行太保
        Role_ShadowChaser = 5203,//逐影
        Role_Merchant = 6000,//商人
        Role_Blacksmith = 6101,//铁匠
        Role_WhiteSmith = 6102,//神工匠
        Role_Mechanic = 6103,//机匠
        Role_Alchemist = 6201,//炼金术士
        Role_Creator = 6202,//创造者
        Role_Genetic = 6203,//基因学者
        Role_Archer = 7000,//弓箭手
        Role_Hunter = 7101,//猎人
        Role_Sniper = 7102,//神射手
        Role_Ranger = 7103,//游侠
        Role_Bard_Dancer = 7201,//吟游诗人/舞娘
        Role_Clown_Gypsy = 7202,//搞笑艺人/冷艳舞姬
        Role_Minstrel_Wanderer = 7203,//宫廷乐师/漫游舞者 
    };    
    enum class Gender: uint32_t {
        MAN = 0,//男
        WOMAN = 1,//女 
    };    
}

class RoleCommonTlogBase : public ROTlogBase
{
public:
    const char * GetTableName() override
    {
        return "RoleCommonTlogBase"; 
    }
    static const char * TableName() 
    {
        return "RoleCommonTlogBase"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int64_t UnionID {0};
    std::string UnionName {""};
    int32_t RegChannel {0};
    int32_t LoginChannel {0};
    
};
namespace AchieveFlowEnum{

}

class AchieveFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("AchieveTypeID", ToStringTlog(AchieveTypeID)); 
        AddLog("AchieveTypeName", AchieveTypeName); 
        AddLog("AchieveID", ToStringTlog(AchieveID)); 
        AddLog("AchieveName", AchieveName); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("PreProgress", ToStringTlog(PreProgress)); 
        AddLog("AfterProgress", ToStringTlog(AfterProgress)); 
        AddLog("PreAchievePoints", ToStringTlog(PreAchievePoints)); 
        AddLog("AfterAchievePoints", ToStringTlog(AfterAchievePoints)); 
        AddLog("FinishPercent", ToStringTlog(FinishPercent)); 
        AddLog("PreMedalName", PreMedalName); 
        AddLog("AfterMedalName", AfterMedalName); 
        AddLog("PreMedalStar", ToStringTlog(PreMedalStar)); 
        AddLog("AfterMedalStar", ToStringTlog(AfterMedalStar)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"AchieveTypeID\":"+ ToStringTlog(AchieveTypeID)); 
        AddLogJson("\"AchieveTypeName\":\""+AchieveTypeName+"\""); 
        AddLogJson("\"AchieveID\":"+ ToStringTlog(AchieveID)); 
        AddLogJson("\"AchieveName\":\""+AchieveName+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"PreProgress\":"+ ToStringTlog(PreProgress)); 
        AddLogJson("\"AfterProgress\":"+ ToStringTlog(AfterProgress)); 
        AddLogJson("\"PreAchievePoints\":"+ ToStringTlog(PreAchievePoints)); 
        AddLogJson("\"AfterAchievePoints\":"+ ToStringTlog(AfterAchievePoints)); 
        AddLogJson("\"FinishPercent\":"+ ToStringTlog(FinishPercent)); 
        AddLogJson("\"PreMedalName\":\""+PreMedalName+"\""); 
        AddLogJson("\"AfterMedalName\":\""+AfterMedalName+"\""); 
        AddLogJson("\"PreMedalStar\":"+ ToStringTlog(PreMedalStar)); 
        AddLogJson("\"AfterMedalStar\":"+ ToStringTlog(AfterMedalStar)); 

    }
    const char * GetTableName() override
    {
        return "AchieveFlow"; 
    }
    static const char * TableName() 
    {
        return "AchieveFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t AchieveTypeID {0};
    std::string AchieveTypeName {""};
    int32_t AchieveID {0};
    std::string AchieveName {""};
    int32_t OperateType {0};
    int32_t PreProgress {0};
    int32_t AfterProgress {0};
    int32_t PreAchievePoints {0};
    int32_t AfterAchievePoints {0};
    int32_t FinishPercent {0};
    std::string PreMedalName {""};
    std::string AfterMedalName {""};
    int32_t PreMedalStar {0};
    int32_t AfterMedalStar {0};
    
};
namespace ActivityFlowEnum{

}

class ActivityFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ActivityID", ToStringTlog(ActivityID)); 
        AddLog("ActivityCount", ToStringTlog(ActivityCount)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("ItemSequence", ToStringTlog(ItemSequence)); 
        AddLog("MoneySequence", ToStringTlog(MoneySequence)); 
        AddLog("EventResult", ToStringTlog(EventResult)); 
        AddLog("IfHelper", ToStringTlog(IfHelper)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ActivityID\":"+ ToStringTlog(ActivityID)); 
        AddLogJson("\"ActivityCount\":"+ ToStringTlog(ActivityCount)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"ItemSequence\":"+ ToStringTlog(ItemSequence)); 
        AddLogJson("\"MoneySequence\":"+ ToStringTlog(MoneySequence)); 
        AddLogJson("\"EventResult\":"+ ToStringTlog(EventResult)); 
        AddLogJson("\"IfHelper\":"+ ToStringTlog(IfHelper)); 

    }
    const char * GetTableName() override
    {
        return "ActivityFlow"; 
    }
    static const char * TableName() 
    {
        return "ActivityFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t ActivityID {0};
    int32_t ActivityCount {0};
    int32_t Time {0};
    int32_t ItemSequence {0};
    int32_t MoneySequence {0};
    int32_t EventResult {0};
    int32_t IfHelper {0};
    
};
namespace ActivityRankingFlowEnum{

}

class ActivityRankingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("AcitvityID", ToStringTlog(AcitvityID)); 
        AddLog("ActivityName", ActivityName); 
        AddLog("ActivityVolNum", ToStringTlog(ActivityVolNum)); 
        AddLog("ActivityThemeID", ToStringTlog(ActivityThemeID)); 
        AddLog("ActivityThemeName", ActivityThemeName); 
        AddLog("FinalActivityScore", ToStringTlog(FinalActivityScore)); 
        AddLog("ActivityRanking", ToStringTlog(ActivityRanking)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"AcitvityID\":"+ ToStringTlog(AcitvityID)); 
        AddLogJson("\"ActivityName\":\""+ActivityName+"\""); 
        AddLogJson("\"ActivityVolNum\":"+ ToStringTlog(ActivityVolNum)); 
        AddLogJson("\"ActivityThemeID\":"+ ToStringTlog(ActivityThemeID)); 
        AddLogJson("\"ActivityThemeName\":\""+ActivityThemeName+"\""); 
        AddLogJson("\"FinalActivityScore\":"+ ToStringTlog(FinalActivityScore)); 
        AddLogJson("\"ActivityRanking\":"+ ToStringTlog(ActivityRanking)); 

    }
    const char * GetTableName() override
    {
        return "ActivityRankingFlow"; 
    }
    static const char * TableName() 
    {
        return "ActivityRankingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t AcitvityID {0};
    std::string ActivityName {""};
    int32_t ActivityVolNum {0};
    int32_t ActivityThemeID {0};
    std::string ActivityThemeName {""};
    int32_t FinalActivityScore {0};
    int32_t ActivityRanking {0};
    
};
namespace ArrowFlowEnum{

}

class ArrowFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("PreArrowNO", ToStringTlog(PreArrowNO)); 
        AddLog("PreArrowName", PreArrowName); 
        AddLog("PreArrowCount", ToStringTlog(PreArrowCount)); 
        AddLog("AftArrowName", AftArrowName); 
        AddLog("AftArrowCount", ToStringTlog(AftArrowCount)); 
        AddLog("AllArrows", AllArrows); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"PreArrowNO\":"+ ToStringTlog(PreArrowNO)); 
        AddLogJson("\"PreArrowName\":\""+PreArrowName+"\""); 
        AddLogJson("\"PreArrowCount\":"+ ToStringTlog(PreArrowCount)); 
        AddLogJson("\"AftArrowName\":\""+AftArrowName+"\""); 
        AddLogJson("\"AftArrowCount\":"+ ToStringTlog(AftArrowCount)); 
        AddLogJson("\"AllArrows\":\""+AllArrows+"\""); 

    }
    const char * GetTableName() override
    {
        return "ArrowFlow"; 
    }
    static const char * TableName() 
    {
        return "ArrowFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t PreArrowNO {0};
    std::string PreArrowName {""};
    int32_t PreArrowCount {0};
    std::string AftArrowName {""};
    int32_t AftArrowCount {0};
    std::string AllArrows {""};
    
};
namespace ASMIadInfoEnum{

}

class ASMIadInfo : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("attribution", ToStringTlog(attribution)); 
        AddLog("OrgName", OrgName); 
        AddLog("CampaignId", ToStringTlog(CampaignId)); 
        AddLog("CampaignName", CampaignName); 
        AddLog("ConversionDate", ConversionDate); 
        AddLog("ClickDate", ClickDate); 
        AddLog("AdgroupId", ToStringTlog(AdgroupId)); 
        AddLog("AdgroupName", AdgroupName); 
        AddLog("KeyWord", KeyWord); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"attribution\":"+ ToStringTlog(attribution)); 
        AddLogJson("\"OrgName\":\""+OrgName+"\""); 
        AddLogJson("\"CampaignId\":"+ ToStringTlog(CampaignId)); 
        AddLogJson("\"CampaignName\":\""+CampaignName+"\""); 
        AddLogJson("\"ConversionDate\":\""+ConversionDate+"\""); 
        AddLogJson("\"ClickDate\":\""+ClickDate+"\""); 
        AddLogJson("\"AdgroupId\":"+ ToStringTlog(AdgroupId)); 
        AddLogJson("\"AdgroupName\":\""+AdgroupName+"\""); 
        AddLogJson("\"KeyWord\":\""+KeyWord+"\""); 

    }
    const char * GetTableName() override
    {
        return "ASMIadInfo"; 
    }
    static const char * TableName() 
    {
        return "ASMIadInfo"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    int32_t attribution {0};
    std::string OrgName {""};
    int32_t CampaignId {0};
    std::string CampaignName {""};
    std::string ConversionDate {""};
    std::string ClickDate {""};
    int32_t AdgroupId {0};
    std::string AdgroupName {""};
    std::string KeyWord {""};
    
};
namespace AssistantFlowEnum{

}

class AssistantFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("AssistantType", ToStringTlog(AssistantType)); 
        AddLog("AssistantProgress", AssistantProgress); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("RecommendSystemID", ToStringTlog(RecommendSystemID)); 
        AddLog("RecommendType", ToStringTlog(RecommendType)); 
        AddLog("SelectSystemID", ToStringTlog(SelectSystemID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"AssistantType\":"+ ToStringTlog(AssistantType)); 
        AddLogJson("\"AssistantProgress\":\""+AssistantProgress+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"RecommendSystemID\":"+ ToStringTlog(RecommendSystemID)); 
        AddLogJson("\"RecommendType\":"+ ToStringTlog(RecommendType)); 
        AddLogJson("\"SelectSystemID\":"+ ToStringTlog(SelectSystemID)); 

    }
    const char * GetTableName() override
    {
        return "AssistantFlow"; 
    }
    static const char * TableName() 
    {
        return "AssistantFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t AssistantType {0};
    std::string AssistantProgress {""};
    int32_t OperateType {0};
    int32_t RecommendSystemID {0};
    int32_t RecommendType {0};
    int32_t SelectSystemID {0};
    
};
namespace AuctionOperateFlowEnum{

}

class AuctionOperateFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("AuctionID", ToStringTlog(AuctionID)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("ItemUID", ItemUID); 
        AddLog("AuctionState", ToStringTlog(AuctionState)); 
        AddLog("CurrentPrice", ToStringTlog(CurrentPrice)); 
        AddLog("CurrentUpperlimit", ToStringTlog(CurrentUpperlimit)); 
        AddLog("RaisePrice", ToStringTlog(RaisePrice)); 
        AddLog("RealDeduction", ToStringTlog(RealDeduction)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"AuctionID\":"+ ToStringTlog(AuctionID)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"ItemUID\":\""+ItemUID+"\""); 
        AddLogJson("\"AuctionState\":"+ ToStringTlog(AuctionState)); 
        AddLogJson("\"CurrentPrice\":"+ ToStringTlog(CurrentPrice)); 
        AddLogJson("\"CurrentUpperlimit\":"+ ToStringTlog(CurrentUpperlimit)); 
        AddLogJson("\"RaisePrice\":"+ ToStringTlog(RaisePrice)); 
        AddLogJson("\"RealDeduction\":"+ ToStringTlog(RealDeduction)); 

    }
    const char * GetTableName() override
    {
        return "AuctionOperateFlow"; 
    }
    static const char * TableName() 
    {
        return "AuctionOperateFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t AuctionID {0};
    int32_t ItemID {0};
    std::string ItemUID {""};
    int32_t AuctionState {0};
    int32_t CurrentPrice {0};
    int32_t CurrentUpperlimit {0};
    int32_t RaisePrice {0};
    int32_t RealDeduction {0};
    
};
namespace AuctionUpdateFlowEnum{

}

class AuctionUpdateFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("AuctionType", ToStringTlog(AuctionType)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("BeforeValue", ToStringTlog(BeforeValue)); 
        AddLog("ChangeValue", ToStringTlog(ChangeValue)); 
        AddLog("AfterValue", ToStringTlog(AfterValue)); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("CurrentPrice", ToStringTlog(CurrentPrice)); 
        AddLog("DailyAuctionPlayer", ToStringTlog(DailyAuctionPlayer)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"AuctionType\":"+ ToStringTlog(AuctionType)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"BeforeValue\":"+ ToStringTlog(BeforeValue)); 
        AddLogJson("\"ChangeValue\":"+ ToStringTlog(ChangeValue)); 
        AddLogJson("\"AfterValue\":"+ ToStringTlog(AfterValue)); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"CurrentPrice\":"+ ToStringTlog(CurrentPrice)); 
        AddLogJson("\"DailyAuctionPlayer\":"+ ToStringTlog(DailyAuctionPlayer)); 

    }
    const char * GetTableName() override
    {
        return "AuctionUpdateFlow"; 
    }
    static const char * TableName() 
    {
        return "AuctionUpdateFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int32_t OperateType {0};
    int32_t AuctionType {0};
    int32_t ItemID {0};
    int32_t BeforeValue {0};
    int32_t ChangeValue {0};
    int32_t AfterValue {0};
    int32_t MoneyType {0};
    int32_t CurrentPrice {0};
    float DailyAuctionPlayer {0};
    
};
namespace BanquetRankFlowEnum{

}

class BanquetRankFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("GroupID", ToStringTlog(GroupID)); 
        AddLog("GroupGuild", GroupGuild); 
        AddLog("GroupGuildScore", GroupGuildScore); 
        AddLog("GroupGuildRank", GroupGuildRank); 
        AddLog("PlayerRank", PlayerRank); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"GroupID\":"+ ToStringTlog(GroupID)); 
        AddLogJson("\"GroupGuild\":\""+GroupGuild+"\""); 
        AddLogJson("\"GroupGuildScore\":\""+GroupGuildScore+"\""); 
        AddLogJson("\"GroupGuildRank\":\""+GroupGuildRank+"\""); 
        AddLogJson("\"PlayerRank\":\""+PlayerRank+"\""); 

    }
    const char * GetTableName() override
    {
        return "BanquetRankFlow"; 
    }
    static const char * TableName() 
    {
        return "BanquetRankFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int64_t GroupID {0};
    std::string GroupGuild {""};
    std::string GroupGuildScore {""};
    std::string GroupGuildRank {""};
    std::string PlayerRank {""};
    
};
namespace BasePointFlowEnum{

    enum class OperateType: uint32_t {
        RESET = 0,//重置
        RANDOM = 1,//自由分配
        RECOMMEND = 2,//推荐分配
        SWITCH = 3,//天赋切换 
    };    
    enum class PointType: uint32_t {
        STR = 0,//STR
        AGI = 1,//AGI
        VIT = 2,//VIT
        INT = 3,//INT
        DEX = 4,//DEX
        LUCK = 5,//LUCK 
    };    
}

class BasePointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("RecType", ToStringTlog(RecType)); 
        AddLog("PointType", ToStringTlog(PointType)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("BeforeCount", ToStringTlog(BeforeCount)); 
        AddLog("AfterCount", ToStringTlog(AfterCount)); 
        AddLog("vBeforePoint", vBeforePoint); 
        AddLog("vAfterPoint", vAfterPoint); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"RecType\":"+ ToStringTlog(RecType)); 
        AddLogJson("\"PointType\":"+ ToStringTlog(PointType)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"BeforeCount\":"+ ToStringTlog(BeforeCount)); 
        AddLogJson("\"AfterCount\":"+ ToStringTlog(AfterCount)); 
        AddLogJson("\"vBeforePoint\":\""+vBeforePoint+"\""); 
        AddLogJson("\"vAfterPoint\":\""+vAfterPoint+"\""); 

    }
    const char * GetTableName() override
    {
        return "BasePointFlow"; 
    }
    static const char * TableName() 
    {
        return "BasePointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t RecType {0};
    int32_t PointType {0};
    int32_t AddOrReduce {0};
    int32_t BeforeCount {0};
    int32_t AfterCount {0};
    std::string vBeforePoint {""};
    std::string vAfterPoint {""};
    
};
namespace BattleTimeFlowEnum{

}

class BattleTimeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("UsedBlessedTime", ToStringTlog(UsedBlessedTime)); 
        AddLog("RemainBlessedTime", ToStringTlog(RemainBlessedTime)); 
        AddLog("UsedHealthyTime", ToStringTlog(UsedHealthyTime)); 
        AddLog("RemainHealthyTime", ToStringTlog(RemainHealthyTime)); 
        AddLog("UsedVanTime", ToStringTlog(UsedVanTime)); 
        AddLog("BlessedBaseExp", ToStringTlog(BlessedBaseExp)); 
        AddLog("BlessedJobExp", ToStringTlog(BlessedJobExp)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"UsedBlessedTime\":"+ ToStringTlog(UsedBlessedTime)); 
        AddLogJson("\"RemainBlessedTime\":"+ ToStringTlog(RemainBlessedTime)); 
        AddLogJson("\"UsedHealthyTime\":"+ ToStringTlog(UsedHealthyTime)); 
        AddLogJson("\"RemainHealthyTime\":"+ ToStringTlog(RemainHealthyTime)); 
        AddLogJson("\"UsedVanTime\":"+ ToStringTlog(UsedVanTime)); 
        AddLogJson("\"BlessedBaseExp\":"+ ToStringTlog(BlessedBaseExp)); 
        AddLogJson("\"BlessedJobExp\":"+ ToStringTlog(BlessedJobExp)); 

    }
    const char * GetTableName() override
    {
        return "BattleTimeFlow"; 
    }
    static const char * TableName() 
    {
        return "BattleTimeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t UsedBlessedTime {0};
    int32_t RemainBlessedTime {0};
    int32_t UsedHealthyTime {0};
    int32_t RemainHealthyTime {0};
    int32_t UsedVanTime {0};
    int32_t BlessedBaseExp {0};
    int32_t BlessedJobExp {0};
    
};
namespace BGMActFlowEnum{

}

class BGMActFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("NPCName", NPCName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("MoneyCost", ToStringTlog(MoneyCost)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"NPCName\":\""+NPCName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"MoneyCost\":"+ ToStringTlog(MoneyCost)); 

    }
    const char * GetTableName() override
    {
        return "BGMActFlow"; 
    }
    static const char * TableName() 
    {
        return "BGMActFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    std::string NPCName {""};
    int32_t MoneyType {0};
    int32_t MoneyCost {0};
    
};
namespace BlessedExperienceChangeFlowEnum{

}

class BlessedExperienceChangeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("Para", ToStringTlog(Para)); 
        AddLog("ExperienceType", ToStringTlog(ExperienceType)); 
        AddLog("ChangeValue", ToStringTlog(ChangeValue)); 
        AddLog("AfterChangeValue", ToStringTlog(AfterChangeValue)); 
        AddLog("ExpirationDate", ExpirationDate); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"Para\":"+ ToStringTlog(Para)); 
        AddLogJson("\"ExperienceType\":"+ ToStringTlog(ExperienceType)); 
        AddLogJson("\"ChangeValue\":"+ ToStringTlog(ChangeValue)); 
        AddLogJson("\"AfterChangeValue\":"+ ToStringTlog(AfterChangeValue)); 
        AddLogJson("\"ExpirationDate\":\""+ExpirationDate+"\""); 

    }
    const char * GetTableName() override
    {
        return "BlessedExperienceChangeFlow"; 
    }
    static const char * TableName() 
    {
        return "BlessedExperienceChangeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Reason {0};
    int32_t Para {0};
    int32_t ExperienceType {0};
    int32_t ChangeValue {0};
    int32_t AfterChangeValue {0};
    std::string ExpirationDate {""};
    
};
namespace BlessFlowEnum{

}

class BlessFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("BlessID", ToStringTlog(BlessID)); 
        AddLog("Message", Message); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("BuffID", ToStringTlog(BuffID)); 
        AddLog("BuffName", BuffName); 
        AddLog("SuperOne", ToStringTlog(SuperOne)); 
        AddLog("LeaveCount", ToStringTlog(LeaveCount)); 
        AddLog("SendReceiveItems", SendReceiveItems); 
        AddLog("GiftItems", GiftItems); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"BlessID\":"+ ToStringTlog(BlessID)); 
        AddLogJson("\"Message\":\""+Message+"\""); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"BuffID\":"+ ToStringTlog(BuffID)); 
        AddLogJson("\"BuffName\":\""+BuffName+"\""); 
        AddLogJson("\"SuperOne\":"+ ToStringTlog(SuperOne)); 
        AddLogJson("\"LeaveCount\":"+ ToStringTlog(LeaveCount)); 
        AddLogJson("\"SendReceiveItems\":\""+SendReceiveItems+"\""); 
        AddLogJson("\"GiftItems\":\""+GiftItems+"\""); 

    }
    const char * GetTableName() override
    {
        return "BlessFlow"; 
    }
    static const char * TableName() 
    {
        return "BlessFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t BlessID {0};
    std::string Message {""};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t UnionJudge {0};
    int32_t FriendPoints {0};
    int32_t BuffID {0};
    std::string BuffName {""};
    int32_t SuperOne {0};
    int32_t LeaveCount {0};
    std::string SendReceiveItems {""};
    std::string GiftItems {""};
    
};
namespace BossFightFlowEnum{

    enum class DungeonType: uint32_t {
        SINGLE = 0,//单人副本
        MULTI = 1,//多人副本 
    };    
    enum class MemberType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_MATE = 1,//队员 
    };    
    enum class Result: uint32_t {
        VICTORY = 0,//胜利
        FAILED = 1,//失败 
    };    
}

class BossFightFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DungeonType", ToStringTlog(DungeonType)); 
        AddLog("DungeonID", ToStringTlog(DungeonID)); 
        AddLog("DungeonName", DungeonName); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("Roles", ToStringTlog(Roles)); 
        AddLog("Ais", ToStringTlog(Ais)); 
        AddLog("MemberNum", MemberNum); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("BossId", ToStringTlog(BossId)); 
        AddLog("BossHpPer", ToStringTlog(BossHpPer)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DungeonType\":"+ ToStringTlog(DungeonType)); 
        AddLogJson("\"DungeonID\":"+ ToStringTlog(DungeonID)); 
        AddLogJson("\"DungeonName\":\""+DungeonName+"\""); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"Roles\":"+ ToStringTlog(Roles)); 
        AddLogJson("\"Ais\":"+ ToStringTlog(Ais)); 
        AddLogJson("\"MemberNum\":\""+MemberNum+"\""); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"BossId\":"+ ToStringTlog(BossId)); 
        AddLogJson("\"BossHpPer\":"+ ToStringTlog(BossHpPer)); 

    }
    const char * GetTableName() override
    {
        return "BossFightFlow"; 
    }
    static const char * TableName() 
    {
        return "BossFightFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DungeonType {0};
    int32_t DungeonID {0};
    std::string DungeonName {""};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t Roles {0};
    int32_t Ais {0};
    std::string MemberNum {""};
    int32_t DeadTimes {0};
    int32_t Result {0};
    int32_t Time {0};
    int32_t BossId {0};
    int32_t BossHpPer {0};
    
};
namespace CapraFAQFlowEnum{

}

class CapraFAQFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("CapraFAQ", CapraFAQ); 
        AddLog("CapraFAQAnswer", CapraFAQAnswer); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"CapraFAQ\":\""+CapraFAQ+"\""); 
        AddLogJson("\"CapraFAQAnswer\":\""+CapraFAQAnswer+"\""); 

    }
    const char * GetTableName() override
    {
        return "CapraFAQFlow"; 
    }
    static const char * TableName() 
    {
        return "CapraFAQFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string CapraFAQ {""};
    std::string CapraFAQAnswer {""};
    
};
namespace CapraFAQQuestionFlowEnum{

}

class CapraFAQQuestionFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("CapraFAQQuestionNum", ToStringTlog(CapraFAQQuestionNum)); 
        AddLog("CapraFAQQuestionContent", CapraFAQQuestionContent); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"CapraFAQQuestionNum\":"+ ToStringTlog(CapraFAQQuestionNum)); 
        AddLogJson("\"CapraFAQQuestionContent\":\""+CapraFAQQuestionContent+"\""); 

    }
    const char * GetTableName() override
    {
        return "CapraFAQQuestionFlow"; 
    }
    static const char * TableName() 
    {
        return "CapraFAQQuestionFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t CapraFAQQuestionNum {0};
    std::string CapraFAQQuestionContent {""};
    
};
namespace CardSealFlowEnum{

}

class CardSealFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("CardID", ToStringTlog(CardID)); 
        AddLog("UnsealCardID", ToStringTlog(UnsealCardID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"CardID\":"+ ToStringTlog(CardID)); 
        AddLogJson("\"UnsealCardID\":"+ ToStringTlog(UnsealCardID)); 

    }
    const char * GetTableName() override
    {
        return "CardSealFlow"; 
    }
    static const char * TableName() 
    {
        return "CardSealFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t CardID {0};
    int32_t UnsealCardID {0};
    
};
namespace CardSlotFlowEnum{

}

class CardSlotFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 
        AddLog("PartID", ToStringTlog(PartID)); 
        AddLog("Slot", ToStringTlog(Slot)); 
        AddLog("OpenSlots", ToStringTlog(OpenSlots)); 
        AddLog("CardID", ToStringTlog(CardID)); 
        AddLog("CardName", CardName); 
        AddLog("SkillID", ToStringTlog(SkillID)); 
        AddLog("SkillName", SkillName); 
        AddLog("CardsCount", ToStringTlog(CardsCount)); 
        AddLog("CardSameCount", ToStringTlog(CardSameCount)); 
        AddLog("CardAll", CardAll); 
        AddLog("ReforgeTimes", ToStringTlog(ReforgeTimes)); 
        AddLog("PreReforgeAttr", PreReforgeAttr); 
        AddLog("AftReforgeAttr", AftReforgeAttr); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 
        AddLogJson("\"PartID\":"+ ToStringTlog(PartID)); 
        AddLogJson("\"Slot\":"+ ToStringTlog(Slot)); 
        AddLogJson("\"OpenSlots\":"+ ToStringTlog(OpenSlots)); 
        AddLogJson("\"CardID\":"+ ToStringTlog(CardID)); 
        AddLogJson("\"CardName\":\""+CardName+"\""); 
        AddLogJson("\"SkillID\":"+ ToStringTlog(SkillID)); 
        AddLogJson("\"SkillName\":\""+SkillName+"\""); 
        AddLogJson("\"CardsCount\":"+ ToStringTlog(CardsCount)); 
        AddLogJson("\"CardSameCount\":"+ ToStringTlog(CardSameCount)); 
        AddLogJson("\"CardAll\":\""+CardAll+"\""); 
        AddLogJson("\"ReforgeTimes\":"+ ToStringTlog(ReforgeTimes)); 
        AddLogJson("\"PreReforgeAttr\":\""+PreReforgeAttr+"\""); 
        AddLogJson("\"AftReforgeAttr\":\""+AftReforgeAttr+"\""); 

    }
    const char * GetTableName() override
    {
        return "CardSlotFlow"; 
    }
    static const char * TableName() 
    {
        return "CardSlotFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    int32_t PartID {0};
    int32_t Slot {0};
    int32_t OpenSlots {0};
    int32_t CardID {0};
    std::string CardName {""};
    int32_t SkillID {0};
    std::string SkillName {""};
    int32_t CardsCount {0};
    int32_t CardSameCount {0};
    std::string CardAll {""};
    int32_t ReforgeTimes {0};
    std::string PreReforgeAttr {""};
    std::string AftReforgeAttr {""};
    
};
namespace CatBoatFlowEnum{

}

class CatBoatFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ShipOrderID", ToStringTlog(ShipOrderID)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("ItemName", ItemName); 
        AddLog("ItemCount", ToStringTlog(ItemCount)); 
        AddLog("OrderCount", ToStringTlog(OrderCount)); 
        AddLog("BoatCount", ToStringTlog(BoatCount)); 
        AddLog("Fame", ToStringTlog(Fame)); 
        AddLog("RewardItem", RewardItem); 
        AddLog("RewardCount", ToStringTlog(RewardCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ShipOrderID\":"+ ToStringTlog(ShipOrderID)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"ItemName\":\""+ItemName+"\""); 
        AddLogJson("\"ItemCount\":"+ ToStringTlog(ItemCount)); 
        AddLogJson("\"OrderCount\":"+ ToStringTlog(OrderCount)); 
        AddLogJson("\"BoatCount\":"+ ToStringTlog(BoatCount)); 
        AddLogJson("\"Fame\":"+ ToStringTlog(Fame)); 
        AddLogJson("\"RewardItem\":\""+RewardItem+"\""); 
        AddLogJson("\"RewardCount\":"+ ToStringTlog(RewardCount)); 

    }
    const char * GetTableName() override
    {
        return "CatBoatFlow"; 
    }
    static const char * TableName() 
    {
        return "CatBoatFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t ShipOrderID {0};
    int32_t ItemID {0};
    std::string ItemName {""};
    int32_t ItemCount {0};
    int32_t OrderCount {0};
    int32_t BoatCount {0};
    int32_t Fame {0};
    std::string RewardItem {""};
    int32_t RewardCount {0};
    
};
namespace ChatRoomFlowEnum{

}

class ChatRoomFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("RoomID", ToStringTlog(RoomID)); 
        AddLog("RoomName", RoomName); 
        AddLog("Numbers", ToStringTlog(Numbers)); 
        AddLog("NowNumbers", ToStringTlog(NowNumbers)); 
        AddLog("PassNumber", ToStringTlog(PassNumber)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"RoomID\":"+ ToStringTlog(RoomID)); 
        AddLogJson("\"RoomName\":\""+RoomName+"\""); 
        AddLogJson("\"Numbers\":"+ ToStringTlog(Numbers)); 
        AddLogJson("\"NowNumbers\":"+ ToStringTlog(NowNumbers)); 
        AddLogJson("\"PassNumber\":"+ ToStringTlog(PassNumber)); 

    }
    const char * GetTableName() override
    {
        return "ChatRoomFlow"; 
    }
    static const char * TableName() 
    {
        return "ChatRoomFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int64_t RoomID {0};
    std::string RoomName {""};
    int32_t Numbers {0};
    int32_t NowNumbers {0};
    int32_t PassNumber {0};
    
};
namespace ChatRoomMemberFlowEnum{

}

class ChatRoomMemberFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("RoomID", ToStringTlog(RoomID)); 
        AddLog("RoomName", RoomName); 
        AddLog("NowNumbers", ToStringTlog(NowNumbers)); 
        AddLog("PassNumber", ToStringTlog(PassNumber)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"RoomID\":"+ ToStringTlog(RoomID)); 
        AddLogJson("\"RoomName\":\""+RoomName+"\""); 
        AddLogJson("\"NowNumbers\":"+ ToStringTlog(NowNumbers)); 
        AddLogJson("\"PassNumber\":"+ ToStringTlog(PassNumber)); 

    }
    const char * GetTableName() override
    {
        return "ChatRoomMemberFlow"; 
    }
    static const char * TableName() 
    {
        return "ChatRoomMemberFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MemberType {0};
    int64_t RoomID {0};
    std::string RoomName {""};
    int32_t NowNumbers {0};
    int32_t PassNumber {0};
    
};
namespace ClientRechargeEnum{

}

class ClientRecharge : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("vopenid", vopenid); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("IP", ToStringTlog(IP)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("iSourceWay", ToStringTlog(iSourceWay)); 
        AddLog("iGoodID", ToStringTlog(iGoodID)); 
        AddLog("iRechargePrice", ToStringTlog(iRechargePrice)); 
        AddLog("iDelta", ToStringTlog(iDelta)); 
        AddLog("iRechargeAfter", ToStringTlog(iRechargeAfter)); 
        AddLog("iLoginWay", iLoginWay); 
        AddLog("iRegWay", iRegWay); 
        AddLog("CIP", CIP); 
        AddLog("Result", ToStringTlog(Result)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"IP\":"+ ToStringTlog(IP)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"iSourceWay\":"+ ToStringTlog(iSourceWay)); 
        AddLogJson("\"iGoodID\":"+ ToStringTlog(iGoodID)); 
        AddLogJson("\"iRechargePrice\":"+ ToStringTlog(iRechargePrice)); 
        AddLogJson("\"iDelta\":"+ ToStringTlog(iDelta)); 
        AddLogJson("\"iRechargeAfter\":"+ ToStringTlog(iRechargeAfter)); 
        AddLogJson("\"iLoginWay\":\""+iLoginWay+"\""); 
        AddLogJson("\"iRegWay\":\""+iRegWay+"\""); 
        AddLogJson("\"CIP\":\""+CIP+"\""); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 

    }
    const char * GetTableName() override
    {
        return "ClientRecharge"; 
    }
    static const char * TableName() 
    {
        return "ClientRecharge"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    std::string vopenid {""};
    int32_t iZoneAreaID {0};
    int32_t PlatID {0};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t IP {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t iSourceWay {0};
    int32_t iGoodID {0};
    int32_t iRechargePrice {0};
    int32_t iDelta {0};
    int32_t iRechargeAfter {0};
    std::string iLoginWay {""};
    std::string iRegWay {""};
    std::string CIP {""};
    int32_t Result {0};
    
};
namespace CollectionUnlockFlowEnum{

}

class CollectionUnlockFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("CollectionType", ToStringTlog(CollectionType)); 
        AddLog("CollectionName", CollectionName); 
        AddLog("CollectionID", ToStringTlog(CollectionID)); 
        AddLog("UnlockType", ToStringTlog(UnlockType)); 
        AddLog("UnlockQuestID", ToStringTlog(UnlockQuestID)); 
        AddLog("UnlockQuestName", UnlockQuestName); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"CollectionType\":"+ ToStringTlog(CollectionType)); 
        AddLogJson("\"CollectionName\":\""+CollectionName+"\""); 
        AddLogJson("\"CollectionID\":"+ ToStringTlog(CollectionID)); 
        AddLogJson("\"UnlockType\":"+ ToStringTlog(UnlockType)); 
        AddLogJson("\"UnlockQuestID\":"+ ToStringTlog(UnlockQuestID)); 
        AddLogJson("\"UnlockQuestName\":\""+UnlockQuestName+"\""); 

    }
    const char * GetTableName() override
    {
        return "CollectionUnlockFlow"; 
    }
    static const char * TableName() 
    {
        return "CollectionUnlockFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t CollectionType {0};
    std::string CollectionName {""};
    int32_t CollectionID {0};
    int32_t UnlockType {0};
    int32_t UnlockQuestID {0};
    std::string UnlockQuestName {""};
    
};
namespace CommoditAllotFlowEnum{

}

class CommoditAllotFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("BeforeStorge", ToStringTlog(BeforeStorge)); 
        AddLog("BeforePrice", ToStringTlog(BeforePrice)); 
        AddLog("BeforeState", ToStringTlog(BeforeState)); 
        AddLog("PlayerCount", ToStringTlog(PlayerCount)); 
        AddLog("BuyCount", ToStringTlog(BuyCount)); 
        AddLog("AfterStorge", ToStringTlog(AfterStorge)); 
        AddLog("AfterPrice", ToStringTlog(AfterPrice)); 
        AddLog("AfterState", ToStringTlog(AfterState)); 
        AddLog("Tendency", ToStringTlog(Tendency)); 
        AddLog("ContinueDays", ToStringTlog(ContinueDays)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"BeforeStorge\":"+ ToStringTlog(BeforeStorge)); 
        AddLogJson("\"BeforePrice\":"+ ToStringTlog(BeforePrice)); 
        AddLogJson("\"BeforeState\":"+ ToStringTlog(BeforeState)); 
        AddLogJson("\"PlayerCount\":"+ ToStringTlog(PlayerCount)); 
        AddLogJson("\"BuyCount\":"+ ToStringTlog(BuyCount)); 
        AddLogJson("\"AfterStorge\":"+ ToStringTlog(AfterStorge)); 
        AddLogJson("\"AfterPrice\":"+ ToStringTlog(AfterPrice)); 
        AddLogJson("\"AfterState\":"+ ToStringTlog(AfterState)); 
        AddLogJson("\"Tendency\":"+ ToStringTlog(Tendency)); 
        AddLogJson("\"ContinueDays\":"+ ToStringTlog(ContinueDays)); 

    }
    const char * GetTableName() override
    {
        return "CommoditAllotFlow"; 
    }
    static const char * TableName() 
    {
        return "CommoditAllotFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    int32_t GoodsID {0};
    int32_t BeforeStorge {0};
    int32_t BeforePrice {0};
    int32_t BeforeState {0};
    int32_t PlayerCount {0};
    int32_t BuyCount {0};
    int32_t AfterStorge {0};
    int32_t AfterPrice {0};
    int32_t AfterState {0};
    int32_t Tendency {0};
    int32_t ContinueDays {0};
    
};
namespace CommoditSnapshotFlowEnum{

}

class CommoditSnapshotFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("State", ToStringTlog(State)); 
        AddLog("Price1", ToStringTlog(Price1)); 
        AddLog("Price2", ToStringTlog(Price2)); 
        AddLog("Count1", ToStringTlog(Count1)); 
        AddLog("Count2", ToStringTlog(Count2)); 
        AddLog("Count3", ToStringTlog(Count3)); 
        AddLog("Count4", ToStringTlog(Count4)); 
        AddLog("Count5", ToStringTlog(Count5)); 
        AddLog("Count6", ToStringTlog(Count6)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"State\":"+ ToStringTlog(State)); 
        AddLogJson("\"Price1\":"+ ToStringTlog(Price1)); 
        AddLogJson("\"Price2\":"+ ToStringTlog(Price2)); 
        AddLogJson("\"Count1\":"+ ToStringTlog(Count1)); 
        AddLogJson("\"Count2\":"+ ToStringTlog(Count2)); 
        AddLogJson("\"Count3\":"+ ToStringTlog(Count3)); 
        AddLogJson("\"Count4\":"+ ToStringTlog(Count4)); 
        AddLogJson("\"Count5\":"+ ToStringTlog(Count5)); 
        AddLogJson("\"Count6\":"+ ToStringTlog(Count6)); 

    }
    const char * GetTableName() override
    {
        return "CommoditSnapshotFlow"; 
    }
    static const char * TableName() 
    {
        return "CommoditSnapshotFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int32_t ItemID {0};
    float Price {0};
    int32_t State {0};
    float Price1 {0};
    float Price2 {0};
    int32_t Count1 {0};
    int32_t Count2 {0};
    int32_t Count3 {0};
    int32_t Count4 {0};
    int32_t Count5 {0};
    int32_t Count6 {0};
    
};
namespace CosChangeFlowEnum{

    enum class OperateType: uint32_t {
        GET_OFF = 0,//取出
        GET_ON = 1,//应用
        REPLACE = 2,//取消 
    };    
    enum class CosType: uint32_t {
        NORMAL = 0,//原身
        FASHION = 1,//时装 
    };    
    enum class Reason: uint32_t {
        NONE = 0,//无
        END_TIME = 1,//时装到期 
    };    
}

class CosChangeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("CosType", ToStringTlog(CosType)); 
        AddLog("CosSubType", ToStringTlog(CosSubType)); 
        AddLog("BeforeID", ToStringTlog(BeforeID)); 
        AddLog("BeforeName", BeforeName); 
        AddLog("AfterID", ToStringTlog(AfterID)); 
        AddLog("AfterName", AfterName); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("Subreason", ToStringTlog(Subreason)); 
        AddLog("CosScoreDelta", ToStringTlog(CosScoreDelta)); 
        AddLog("BeforeCosScore", ToStringTlog(BeforeCosScore)); 
        AddLog("AfterCosScore", ToStringTlog(AfterCosScore)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"CosType\":"+ ToStringTlog(CosType)); 
        AddLogJson("\"CosSubType\":"+ ToStringTlog(CosSubType)); 
        AddLogJson("\"BeforeID\":"+ ToStringTlog(BeforeID)); 
        AddLogJson("\"BeforeName\":\""+BeforeName+"\""); 
        AddLogJson("\"AfterID\":"+ ToStringTlog(AfterID)); 
        AddLogJson("\"AfterName\":\""+AfterName+"\""); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"Subreason\":"+ ToStringTlog(Subreason)); 
        AddLogJson("\"CosScoreDelta\":"+ ToStringTlog(CosScoreDelta)); 
        AddLogJson("\"BeforeCosScore\":"+ ToStringTlog(BeforeCosScore)); 
        AddLogJson("\"AfterCosScore\":"+ ToStringTlog(AfterCosScore)); 

    }
    const char * GetTableName() override
    {
        return "CosChangeFlow"; 
    }
    static const char * TableName() 
    {
        return "CosChangeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t CosType {0};
    int32_t CosSubType {0};
    int32_t BeforeID {0};
    std::string BeforeName {""};
    int32_t AfterID {0};
    std::string AfterName {""};
    int32_t Reason {0};
    int32_t Subreason {0};
    int32_t CosScoreDelta {0};
    int32_t BeforeCosScore {0};
    int32_t AfterCosScore {0};
    
};
namespace CosScoreFlowEnum{

}

class CosScoreFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("IssueVolNum", ToStringTlog(IssueVolNum)); 
        AddLog("IssueThemeID", ToStringTlog(IssueThemeID)); 
        AddLog("IssueThemeName", IssueThemeName); 
        AddLog("JudgeTimes", ToStringTlog(JudgeTimes)); 
        AddLog("CosScore", ToStringTlog(CosScore)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"IssueVolNum\":"+ ToStringTlog(IssueVolNum)); 
        AddLogJson("\"IssueThemeID\":"+ ToStringTlog(IssueThemeID)); 
        AddLogJson("\"IssueThemeName\":\""+IssueThemeName+"\""); 
        AddLogJson("\"JudgeTimes\":"+ ToStringTlog(JudgeTimes)); 
        AddLogJson("\"CosScore\":"+ ToStringTlog(CosScore)); 

    }
    const char * GetTableName() override
    {
        return "CosScoreFlow"; 
    }
    static const char * TableName() 
    {
        return "CosScoreFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t IssueVolNum {0};
    int32_t IssueThemeID {0};
    std::string IssueThemeName {""};
    int32_t JudgeTimes {0};
    int32_t CosScore {0};
    
};
namespace DungeonFlowEnum{

    enum class OperateType: uint32_t {
        RNTER = 0,//进入副本
        FINISH = 1,//完成副本
        MIDOUT = 2,//中途退出 
    };    
    enum class MemberType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_MATE = 1,//队员 
    };    
    enum class Result: uint32_t {
        VICTORY = 0,//胜利
        FAILED = 1,//失败 
    };    
}

class DungeonFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("DungeonType", ToStringTlog(DungeonType)); 
        AddLog("DungeonNumberType", ToStringTlog(DungeonNumberType)); 
        AddLog("DungeonID", ToStringTlog(DungeonID)); 
        AddLog("DungeonName", DungeonName); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("Roles", ToStringTlog(Roles)); 
        AddLog("Ais", ToStringTlog(Ais)); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("TeamEloBefore", ToStringTlog(TeamEloBefore)); 
        AddLog("PlayerEloBefore", ToStringTlog(PlayerEloBefore)); 
        AddLog("TeamEloAfter", ToStringTlog(TeamEloAfter)); 
        AddLog("PlayerEloAfter", ToStringTlog(PlayerEloAfter)); 
        AddLog("PvpKills", ToStringTlog(PvpKills)); 
        AddLog("IfHelper", ToStringTlog(IfHelper)); 
        AddLog("Stages", ToStringTlog(Stages)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("ElementID", ElementID); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"DungeonType\":"+ ToStringTlog(DungeonType)); 
        AddLogJson("\"DungeonNumberType\":"+ ToStringTlog(DungeonNumberType)); 
        AddLogJson("\"DungeonID\":"+ ToStringTlog(DungeonID)); 
        AddLogJson("\"DungeonName\":\""+DungeonName+"\""); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"Roles\":"+ ToStringTlog(Roles)); 
        AddLogJson("\"Ais\":"+ ToStringTlog(Ais)); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"TeamEloBefore\":"+ ToStringTlog(TeamEloBefore)); 
        AddLogJson("\"PlayerEloBefore\":"+ ToStringTlog(PlayerEloBefore)); 
        AddLogJson("\"TeamEloAfter\":"+ ToStringTlog(TeamEloAfter)); 
        AddLogJson("\"PlayerEloAfter\":"+ ToStringTlog(PlayerEloAfter)); 
        AddLogJson("\"PvpKills\":"+ ToStringTlog(PvpKills)); 
        AddLogJson("\"IfHelper\":"+ ToStringTlog(IfHelper)); 
        AddLogJson("\"Stages\":"+ ToStringTlog(Stages)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"ElementID\":\""+ElementID+"\""); 

    }
    const char * GetTableName() override
    {
        return "DungeonFlow"; 
    }
    static const char * TableName() 
    {
        return "DungeonFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t DungeonType {0};
    int32_t DungeonNumberType {0};
    int32_t DungeonID {0};
    std::string DungeonName {""};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t Roles {0};
    int32_t Ais {0};
    int32_t DeadTimes {0};
    int32_t Count {0};
    int32_t Result {0};
    int32_t Time {0};
    int32_t TeamEloBefore {0};
    int32_t PlayerEloBefore {0};
    int32_t TeamEloAfter {0};
    int32_t PlayerEloAfter {0};
    int32_t PvpKills {0};
    int32_t IfHelper {0};
    int32_t Stages {0};
    int32_t Score {0};
    std::string ElementID {""};
    
};
namespace DungeonStageFlowEnum{

}

class DungeonStageFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DungeonType", ToStringTlog(DungeonType)); 
        AddLog("DungeonID", ToStringTlog(DungeonID)); 
        AddLog("DungeonName", DungeonName); 
        AddLog("StageID", ToStringTlog(StageID)); 
        AddLog("StageTarget", StageTarget); 
        AddLog("StageStatus", ToStringTlog(StageStatus)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("Roles", ToStringTlog(Roles)); 
        AddLog("Ais", ToStringTlog(Ais)); 
        AddLog("StageDeadTimes", ToStringTlog(StageDeadTimes)); 
        AddLog("StageTimeCost", ToStringTlog(StageTimeCost)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DungeonType\":"+ ToStringTlog(DungeonType)); 
        AddLogJson("\"DungeonID\":"+ ToStringTlog(DungeonID)); 
        AddLogJson("\"DungeonName\":\""+DungeonName+"\""); 
        AddLogJson("\"StageID\":"+ ToStringTlog(StageID)); 
        AddLogJson("\"StageTarget\":\""+StageTarget+"\""); 
        AddLogJson("\"StageStatus\":"+ ToStringTlog(StageStatus)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"Roles\":"+ ToStringTlog(Roles)); 
        AddLogJson("\"Ais\":"+ ToStringTlog(Ais)); 
        AddLogJson("\"StageDeadTimes\":"+ ToStringTlog(StageDeadTimes)); 
        AddLogJson("\"StageTimeCost\":"+ ToStringTlog(StageTimeCost)); 

    }
    const char * GetTableName() override
    {
        return "DungeonStageFlow"; 
    }
    static const char * TableName() 
    {
        return "DungeonStageFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DungeonType {0};
    int32_t DungeonID {0};
    std::string DungeonName {""};
    int32_t StageID {0};
    std::string StageTarget {""};
    int32_t StageStatus {0};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t Roles {0};
    int32_t Ais {0};
    int32_t StageDeadTimes {0};
    int32_t StageTimeCost {0};
    
};
namespace ElPointFlowEnum{

    enum class PointType: uint32_t {
        VIGOR = 0,//元气值
        ACHIEVEMENT = 1,//成就点数
        BOLI_POINT = 2,//波利点数
        GUILD_CONTR = 3,//公会贡献
        REPUTAION = 4,//声望值 
    };    
}

class ElPointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PointType", ToStringTlog(PointType)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("Num", ToStringTlog(Num)); 
        AddLog("BeforePoint", ToStringTlog(BeforePoint)); 
        AddLog("AfterPoint", ToStringTlog(AfterPoint)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PointType\":"+ ToStringTlog(PointType)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"Num\":"+ ToStringTlog(Num)); 
        AddLogJson("\"BeforePoint\":"+ ToStringTlog(BeforePoint)); 
        AddLogJson("\"AfterPoint\":"+ ToStringTlog(AfterPoint)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 

    }
    const char * GetTableName() override
    {
        return "ElPointFlow"; 
    }
    static const char * TableName() 
    {
        return "ElPointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PointType {0};
    int32_t AddOrReduce {0};
    int32_t Num {0};
    int32_t BeforePoint {0};
    int32_t AfterPoint {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    
};
namespace EntityHandBookLvFlowEnum{

}

class EntityHandBookLvFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("HandBookLv", ToStringTlog(HandBookLv)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"HandBookLv\":"+ ToStringTlog(HandBookLv)); 

    }
    const char * GetTableName() override
    {
        return "EntityHandBookLvFlow"; 
    }
    static const char * TableName() 
    {
        return "EntityHandBookLvFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t HandBookLv {0};
    
};
namespace EntityResearchFlowEnum{

}

class EntityResearchFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EntityID", ToStringTlog(EntityID)); 
        AddLog("EntityName", EntityName); 
        AddLog("ResearchLevel", ToStringTlog(ResearchLevel)); 
        AddLog("UnitAttrType", UnitAttrType); 
        AddLog("Group", ToStringTlog(Group)); 
        AddLog("HandBookLv", ToStringTlog(HandBookLv)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EntityID\":"+ ToStringTlog(EntityID)); 
        AddLogJson("\"EntityName\":\""+EntityName+"\""); 
        AddLogJson("\"ResearchLevel\":"+ ToStringTlog(ResearchLevel)); 
        AddLogJson("\"UnitAttrType\":\""+UnitAttrType+"\""); 
        AddLogJson("\"Group\":"+ ToStringTlog(Group)); 
        AddLogJson("\"HandBookLv\":"+ ToStringTlog(HandBookLv)); 

    }
    const char * GetTableName() override
    {
        return "EntityResearchFlow"; 
    }
    static const char * TableName() 
    {
        return "EntityResearchFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EntityID {0};
    std::string EntityName {""};
    int32_t ResearchLevel {0};
    std::string UnitAttrType {""};
    int32_t Group {0};
    int32_t HandBookLv {0};
    
};
namespace EntrustFlowEnum{

}

class EntrustFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EntrustType", ToStringTlog(EntrustType)); 
        AddLog("EntrustID", ToStringTlog(EntrustID)); 
        AddLog("EntrustName", EntrustName); 
        AddLog("TaskID", ToStringTlog(TaskID)); 
        AddLog("PaperCost", ToStringTlog(PaperCost)); 
        AddLog("RemainPaper", ToStringTlog(RemainPaper)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("EntrustFinishedTimes", ToStringTlog(EntrustFinishedTimes)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EntrustType\":"+ ToStringTlog(EntrustType)); 
        AddLogJson("\"EntrustID\":"+ ToStringTlog(EntrustID)); 
        AddLogJson("\"EntrustName\":\""+EntrustName+"\""); 
        AddLogJson("\"TaskID\":"+ ToStringTlog(TaskID)); 
        AddLogJson("\"PaperCost\":"+ ToStringTlog(PaperCost)); 
        AddLogJson("\"RemainPaper\":"+ ToStringTlog(RemainPaper)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"EntrustFinishedTimes\":"+ ToStringTlog(EntrustFinishedTimes)); 

    }
    const char * GetTableName() override
    {
        return "EntrustFlow"; 
    }
    static const char * TableName() 
    {
        return "EntrustFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EntrustType {0};
    int32_t EntrustID {0};
    std::string EntrustName {""};
    int32_t TaskID {0};
    int32_t PaperCost {0};
    int32_t RemainPaper {0};
    int32_t Time {0};
    int32_t EntrustFinishedTimes {0};
    
};
namespace EquipEnchantFlowEnum{

    enum class isBlessed: uint32_t {
        NO = 0,//否
        YES = 1,//是 
    };    
    enum class isSaved: uint32_t {
        NO = 0,//否
        YES = 1,//是 
    };    
}

class EquipEnchantFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 
        AddLog("PreResultId", ToStringTlog(PreResultId)); 
        AddLog("ResultId", ToStringTlog(ResultId)); 
        AddLog("PreEntry", ToStringTlog(PreEntry)); 
        AddLog("Entry", ToStringTlog(Entry)); 
        AddLog("PreAll", PreAll); 
        AddLog("AllAfter", AllAfter); 
        AddLog("isBlessed", ToStringTlog(isBlessed)); 
        AddLog("isSaved", ToStringTlog(isSaved)); 
        AddLog("BackPercent", ToStringTlog(BackPercent)); 
        AddLog("SaveTime", ToStringTlog(SaveTime)); 
        AddLog("PrimaryTimes", ToStringTlog(PrimaryTimes)); 
        AddLog("SeniorTimes", ToStringTlog(SeniorTimes)); 
        AddLog("PreEntryScores", ToStringTlog(PreEntryScores)); 
        AddLog("AftEntryScores", ToStringTlog(AftEntryScores)); 
        AddLog("PreEntryType1", ToStringTlog(PreEntryType1)); 
        AddLog("PreEntryAttr1", PreEntryAttr1); 
        AddLog("PreEntryScores1", ToStringTlog(PreEntryScores1)); 
        AddLog("PreEntryType2", ToStringTlog(PreEntryType2)); 
        AddLog("PreEntryAttr2", PreEntryAttr2); 
        AddLog("PreEntryScores2", ToStringTlog(PreEntryScores2)); 
        AddLog("PreEntryType3", ToStringTlog(PreEntryType3)); 
        AddLog("PreEntryAttr3", PreEntryAttr3); 
        AddLog("PreEntryScores3", ToStringTlog(PreEntryScores3)); 
        AddLog("AftEntryType1", ToStringTlog(AftEntryType1)); 
        AddLog("AftEntryAttr1", AftEntryAttr1); 
        AddLog("AftEntryScores1", ToStringTlog(AftEntryScores1)); 
        AddLog("AftEntryType2", ToStringTlog(AftEntryType2)); 
        AddLog("AftEntryAttr2", AftEntryAttr2); 
        AddLog("AftEntryScores2", ToStringTlog(AftEntryScores2)); 
        AddLog("AftEntryType3", ToStringTlog(AftEntryType3)); 
        AddLog("AftEntryAttr3", AftEntryAttr3); 
        AddLog("AftEntryScores3", ToStringTlog(AftEntryScores3)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 
        AddLogJson("\"PreResultId\":"+ ToStringTlog(PreResultId)); 
        AddLogJson("\"ResultId\":"+ ToStringTlog(ResultId)); 
        AddLogJson("\"PreEntry\":"+ ToStringTlog(PreEntry)); 
        AddLogJson("\"Entry\":"+ ToStringTlog(Entry)); 
        AddLogJson("\"PreAll\":\""+PreAll+"\""); 
        AddLogJson("\"AllAfter\":\""+AllAfter+"\""); 
        AddLogJson("\"isBlessed\":"+ ToStringTlog(isBlessed)); 
        AddLogJson("\"isSaved\":"+ ToStringTlog(isSaved)); 
        AddLogJson("\"BackPercent\":"+ ToStringTlog(BackPercent)); 
        AddLogJson("\"SaveTime\":"+ ToStringTlog(SaveTime)); 
        AddLogJson("\"PrimaryTimes\":"+ ToStringTlog(PrimaryTimes)); 
        AddLogJson("\"SeniorTimes\":"+ ToStringTlog(SeniorTimes)); 
        AddLogJson("\"PreEntryScores\":"+ ToStringTlog(PreEntryScores)); 
        AddLogJson("\"AftEntryScores\":"+ ToStringTlog(AftEntryScores)); 
        AddLogJson("\"PreEntryType1\":"+ ToStringTlog(PreEntryType1)); 
        AddLogJson("\"PreEntryAttr1\":\""+PreEntryAttr1+"\""); 
        AddLogJson("\"PreEntryScores1\":"+ ToStringTlog(PreEntryScores1)); 
        AddLogJson("\"PreEntryType2\":"+ ToStringTlog(PreEntryType2)); 
        AddLogJson("\"PreEntryAttr2\":\""+PreEntryAttr2+"\""); 
        AddLogJson("\"PreEntryScores2\":"+ ToStringTlog(PreEntryScores2)); 
        AddLogJson("\"PreEntryType3\":"+ ToStringTlog(PreEntryType3)); 
        AddLogJson("\"PreEntryAttr3\":\""+PreEntryAttr3+"\""); 
        AddLogJson("\"PreEntryScores3\":"+ ToStringTlog(PreEntryScores3)); 
        AddLogJson("\"AftEntryType1\":"+ ToStringTlog(AftEntryType1)); 
        AddLogJson("\"AftEntryAttr1\":\""+AftEntryAttr1+"\""); 
        AddLogJson("\"AftEntryScores1\":"+ ToStringTlog(AftEntryScores1)); 
        AddLogJson("\"AftEntryType2\":"+ ToStringTlog(AftEntryType2)); 
        AddLogJson("\"AftEntryAttr2\":\""+AftEntryAttr2+"\""); 
        AddLogJson("\"AftEntryScores2\":"+ ToStringTlog(AftEntryScores2)); 
        AddLogJson("\"AftEntryType3\":"+ ToStringTlog(AftEntryType3)); 
        AddLogJson("\"AftEntryAttr3\":\""+AftEntryAttr3+"\""); 
        AddLogJson("\"AftEntryScores3\":"+ ToStringTlog(AftEntryScores3)); 

    }
    const char * GetTableName() override
    {
        return "EquipEnchantFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipEnchantFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    int32_t PreResultId {0};
    int32_t ResultId {0};
    int32_t PreEntry {0};
    int32_t Entry {0};
    std::string PreAll {""};
    std::string AllAfter {""};
    int32_t isBlessed {0};
    int32_t isSaved {0};
    int32_t BackPercent {0};
    int32_t SaveTime {0};
    int32_t PrimaryTimes {0};
    int32_t SeniorTimes {0};
    int32_t PreEntryScores {0};
    int32_t AftEntryScores {0};
    int32_t PreEntryType1 {0};
    std::string PreEntryAttr1 {""};
    int32_t PreEntryScores1 {0};
    int32_t PreEntryType2 {0};
    std::string PreEntryAttr2 {""};
    int32_t PreEntryScores2 {0};
    int32_t PreEntryType3 {0};
    std::string PreEntryAttr3 {""};
    int32_t PreEntryScores3 {0};
    int32_t AftEntryType1 {0};
    std::string AftEntryAttr1 {""};
    int32_t AftEntryScores1 {0};
    int32_t AftEntryType2 {0};
    std::string AftEntryAttr2 {""};
    int32_t AftEntryScores2 {0};
    int32_t AftEntryType3 {0};
    std::string AftEntryAttr3 {""};
    int32_t AftEntryScores3 {0};
    
};
namespace EquipFlowEnum{

    enum class OperateType: uint32_t {
        GET_ON = 0,//穿戴
        GET_OFF = 1,//卸下
        GET_BACK = 2,//回收
        GET_SUIT = 3,//套装激活
        GET_MULTI_TELENT_WAAR = 4,//天赋切换穿戴
        GET_MULTI_TELENT_TAKE = 5,//天赋切换卸下 
    };    
}

class EquipFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("BeforePower", ToStringTlog(BeforePower)); 
        AddLog("AfterPower", ToStringTlog(AfterPower)); 
        AddLog("SuitID", ToStringTlog(SuitID)); 
        AddLog("SuitName", SuitName); 
        AddLog("Suit", Suit); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"BeforePower\":"+ ToStringTlog(BeforePower)); 
        AddLogJson("\"AfterPower\":"+ ToStringTlog(AfterPower)); 
        AddLogJson("\"SuitID\":"+ ToStringTlog(SuitID)); 
        AddLogJson("\"SuitName\":\""+SuitName+"\""); 
        AddLogJson("\"Suit\":\""+Suit+"\""); 

    }
    const char * GetTableName() override
    {
        return "EquipFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t BeforePower {0};
    int32_t AfterPower {0};
    int32_t SuitID {0};
    std::string SuitName {""};
    std::string Suit {""};
    
};
namespace EquipForgeFlowEnum{

    enum class Operate: uint32_t {
        FORGING = 0,//锻造
        REPAIR = 1,//修复 
    };    
}

class EquipForgeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Operate", ToStringTlog(Operate)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Operate\":"+ ToStringTlog(Operate)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 

    }
    const char * GetTableName() override
    {
        return "EquipForgeFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipForgeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Operate {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    
};
namespace EquipRefineFlowEnum{

    enum class RefineType: uint32_t {
        BEECHAM = 0,//必成精炼
        ROLLBACK = 1,//祝福精炼
        NONE = 2,//普通精炼 
    };    
    enum class isBroken: uint32_t {
        NONE = 0,//未破损
        DISREPAIR = 1,//破损 
    };    
}

class EquipRefineFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 
        AddLog("RefineType", ToStringTlog(RefineType)); 
        AddLog("PreLevel", ToStringTlog(PreLevel)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 
        AddLog("isBroken", ToStringTlog(isBroken)); 
        AddLog("isPeak", ToStringTlog(isPeak)); 
        AddLog("RefineCostItem", RefineCostItem); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 
        AddLogJson("\"RefineType\":"+ ToStringTlog(RefineType)); 
        AddLogJson("\"PreLevel\":"+ ToStringTlog(PreLevel)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 
        AddLogJson("\"isBroken\":"+ ToStringTlog(isBroken)); 
        AddLogJson("\"isPeak\":"+ ToStringTlog(isPeak)); 
        AddLogJson("\"RefineCostItem\":\""+RefineCostItem+"\""); 

    }
    const char * GetTableName() override
    {
        return "EquipRefineFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipRefineFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    int32_t RefineType {0};
    int32_t PreLevel {0};
    int32_t AfterLevel {0};
    int32_t isBroken {0};
    int32_t isPeak {0};
    std::string RefineCostItem {""};
    
};
namespace EquipRemouldFlowEnum{

}

class EquipRemouldFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Operate", ToStringTlog(Operate)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 
        AddLog("RemouldItem", ToStringTlog(RemouldItem)); 
        AddLog("RemouldNum", ToStringTlog(RemouldNum)); 
        AddLog("AttrBefore1", ToStringTlog(AttrBefore1)); 
        AddLog("AttrAfter1", ToStringTlog(AttrAfter1)); 
        AddLog("AttrBefore2", ToStringTlog(AttrBefore2)); 
        AddLog("AttrAfter2", ToStringTlog(AttrAfter2)); 
        AddLog("AttrBefore3", ToStringTlog(AttrBefore3)); 
        AddLog("AttrAfter3", ToStringTlog(AttrAfter3)); 
        AddLog("AttrBefore4", ToStringTlog(AttrBefore4)); 
        AddLog("AttrAfter4", ToStringTlog(AttrAfter4)); 
        AddLog("AttrLevelBefore", ToStringTlog(AttrLevelBefore)); 
        AddLog("AttrLevelAfter", ToStringTlog(AttrLevelAfter)); 
        AddLog("AttrBefore", ToStringTlog(AttrBefore)); 
        AddLog("AttrAfter", ToStringTlog(AttrAfter)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Operate\":"+ ToStringTlog(Operate)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 
        AddLogJson("\"RemouldItem\":"+ ToStringTlog(RemouldItem)); 
        AddLogJson("\"RemouldNum\":"+ ToStringTlog(RemouldNum)); 
        AddLogJson("\"AttrBefore1\":"+ ToStringTlog(AttrBefore1)); 
        AddLogJson("\"AttrAfter1\":"+ ToStringTlog(AttrAfter1)); 
        AddLogJson("\"AttrBefore2\":"+ ToStringTlog(AttrBefore2)); 
        AddLogJson("\"AttrAfter2\":"+ ToStringTlog(AttrAfter2)); 
        AddLogJson("\"AttrBefore3\":"+ ToStringTlog(AttrBefore3)); 
        AddLogJson("\"AttrAfter3\":"+ ToStringTlog(AttrAfter3)); 
        AddLogJson("\"AttrBefore4\":"+ ToStringTlog(AttrBefore4)); 
        AddLogJson("\"AttrAfter4\":"+ ToStringTlog(AttrAfter4)); 
        AddLogJson("\"AttrLevelBefore\":"+ ToStringTlog(AttrLevelBefore)); 
        AddLogJson("\"AttrLevelAfter\":"+ ToStringTlog(AttrLevelAfter)); 
        AddLogJson("\"AttrBefore\":"+ ToStringTlog(AttrBefore)); 
        AddLogJson("\"AttrAfter\":"+ ToStringTlog(AttrAfter)); 

    }
    const char * GetTableName() override
    {
        return "EquipRemouldFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipRemouldFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Operate {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    int32_t RemouldItem {0};
    int32_t RemouldNum {0};
    int32_t AttrBefore1 {0};
    int32_t AttrAfter1 {0};
    int32_t AttrBefore2 {0};
    int32_t AttrAfter2 {0};
    int32_t AttrBefore3 {0};
    int32_t AttrAfter3 {0};
    int32_t AttrBefore4 {0};
    int32_t AttrAfter4 {0};
    std::string AttrLevelBefore {""};
    std::string AttrLevelAfter {""};
    std::string AttrBefore {""};
    std::string AttrAfter {""};
    
};
namespace EquipSlottingFlowEnum{

}

class EquipSlottingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("EquipID", ToStringTlog(EquipID)); 
        AddLog("EquipName", EquipName); 
        AddLog("EquipLevel", ToStringTlog(EquipLevel)); 
        AddLog("PreSlots", ToStringTlog(PreSlots)); 
        AddLog("AfterSlots", ToStringTlog(AfterSlots)); 
        AddLog("PreEntryQuality1", ToStringTlog(PreEntryQuality1)); 
        AddLog("PreEntryID1", ToStringTlog(PreEntryID1)); 
        AddLog("PreEntryQuality2", ToStringTlog(PreEntryQuality2)); 
        AddLog("PreEntryID2", ToStringTlog(PreEntryID2)); 
        AddLog("PreEntryQuality3", ToStringTlog(PreEntryQuality3)); 
        AddLog("PreEntryID3", ToStringTlog(PreEntryID3)); 
        AddLog("AftEntryQuality1", ToStringTlog(AftEntryQuality1)); 
        AddLog("AftEntryID1", ToStringTlog(AftEntryID1)); 
        AddLog("AftEntryQuality2", ToStringTlog(AftEntryQuality2)); 
        AddLog("AftEntryID2", ToStringTlog(AftEntryID2)); 
        AddLog("AftEntryQuality3", ToStringTlog(AftEntryQuality3)); 
        AddLog("AftEntryID3", ToStringTlog(AftEntryID3)); 
        AddLog("IsSaved", ToStringTlog(IsSaved)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"EquipID\":"+ ToStringTlog(EquipID)); 
        AddLogJson("\"EquipName\":\""+EquipName+"\""); 
        AddLogJson("\"EquipLevel\":"+ ToStringTlog(EquipLevel)); 
        AddLogJson("\"PreSlots\":"+ ToStringTlog(PreSlots)); 
        AddLogJson("\"AfterSlots\":"+ ToStringTlog(AfterSlots)); 
        AddLogJson("\"PreEntryQuality1\":"+ ToStringTlog(PreEntryQuality1)); 
        AddLogJson("\"PreEntryID1\":"+ ToStringTlog(PreEntryID1)); 
        AddLogJson("\"PreEntryQuality2\":"+ ToStringTlog(PreEntryQuality2)); 
        AddLogJson("\"PreEntryID2\":"+ ToStringTlog(PreEntryID2)); 
        AddLogJson("\"PreEntryQuality3\":"+ ToStringTlog(PreEntryQuality3)); 
        AddLogJson("\"PreEntryID3\":"+ ToStringTlog(PreEntryID3)); 
        AddLogJson("\"AftEntryQuality1\":"+ ToStringTlog(AftEntryQuality1)); 
        AddLogJson("\"AftEntryID1\":"+ ToStringTlog(AftEntryID1)); 
        AddLogJson("\"AftEntryQuality2\":"+ ToStringTlog(AftEntryQuality2)); 
        AddLogJson("\"AftEntryID2\":"+ ToStringTlog(AftEntryID2)); 
        AddLogJson("\"AftEntryQuality3\":"+ ToStringTlog(AftEntryQuality3)); 
        AddLogJson("\"AftEntryID3\":"+ ToStringTlog(AftEntryID3)); 
        AddLogJson("\"IsSaved\":"+ ToStringTlog(IsSaved)); 

    }
    const char * GetTableName() override
    {
        return "EquipSlottingFlow"; 
    }
    static const char * TableName() 
    {
        return "EquipSlottingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EquipType {0};
    int32_t EquipID {0};
    std::string EquipName {""};
    int32_t EquipLevel {0};
    int32_t PreSlots {0};
    int32_t AfterSlots {0};
    int32_t PreEntryQuality1 {0};
    int32_t PreEntryID1 {0};
    int32_t PreEntryQuality2 {0};
    int32_t PreEntryID2 {0};
    int32_t PreEntryQuality3 {0};
    int32_t PreEntryID3 {0};
    int32_t AftEntryQuality1 {0};
    int32_t AftEntryID1 {0};
    int32_t AftEntryQuality2 {0};
    int32_t AftEntryID2 {0};
    int32_t AftEntryQuality3 {0};
    int32_t AftEntryID3 {0};
    int32_t IsSaved {0};
    
};
namespace FaceChangeFlowEnum{

}

class FaceChangeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("PreType", ToStringTlog(PreType)); 
        AddLog("PreColor", ToStringTlog(PreColor)); 
        AddLog("AfterType", ToStringTlog(AfterType)); 
        AddLog("AfterColor", ToStringTlog(AfterColor)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"PreType\":"+ ToStringTlog(PreType)); 
        AddLogJson("\"PreColor\":"+ ToStringTlog(PreColor)); 
        AddLogJson("\"AfterType\":"+ ToStringTlog(AfterType)); 
        AddLogJson("\"AfterColor\":"+ ToStringTlog(AfterColor)); 

    }
    const char * GetTableName() override
    {
        return "FaceChangeFlow"; 
    }
    static const char * TableName() 
    {
        return "FaceChangeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t PreType {0};
    int32_t PreColor {0};
    int32_t AfterType {0};
    int32_t AfterColor {0};
    
};
namespace FarmFightFlowEnum{

    enum class MemberType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_MENBER = 1,//队员 
    };    
}

class FarmFightFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("MapName", MapName); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("MemberNum", ToStringTlog(MemberNum)); 
        AddLog("MemberInfo", MemberInfo); 
        AddLog("MemberLv", MemberLv); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("EntityNum", ToStringTlog(EntityNum)); 
        AddLog("AlmaEntityNum", ToStringTlog(AlmaEntityNum)); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("AutoBattleState", ToStringTlog(AutoBattleState)); 
        AddLog("AutoBattleRange", ToStringTlog(AutoBattleRange)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"MapName\":\""+MapName+"\""); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"MemberNum\":"+ ToStringTlog(MemberNum)); 
        AddLogJson("\"MemberInfo\":\""+MemberInfo+"\""); 
        AddLogJson("\"MemberLv\":\""+MemberLv+"\""); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"EntityNum\":"+ ToStringTlog(EntityNum)); 
        AddLogJson("\"AlmaEntityNum\":"+ ToStringTlog(AlmaEntityNum)); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"AutoBattleState\":"+ ToStringTlog(AutoBattleState)); 
        AddLogJson("\"AutoBattleRange\":"+ ToStringTlog(AutoBattleRange)); 

    }
    const char * GetTableName() override
    {
        return "FarmFightFlow"; 
    }
    static const char * TableName() 
    {
        return "FarmFightFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    std::string MapName {""};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t MemberNum {0};
    std::string MemberInfo {""};
    std::string MemberLv {""};
    int32_t DeadTimes {0};
    int32_t Time {0};
    int32_t EntityNum {0};
    int32_t AlmaEntityNum {0};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    int32_t AutoBattleState {0};
    int32_t AutoBattleRange {0};
    
};
namespace FightPointFlowEnum{

}

class FightPointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("BeforePoint", ToStringTlog(BeforePoint)); 
        AddLog("AfterPoint", ToStringTlog(AfterPoint)); 
        AddLog("PointMax", ToStringTlog(PointMax)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"BeforePoint\":"+ ToStringTlog(BeforePoint)); 
        AddLogJson("\"AfterPoint\":"+ ToStringTlog(AfterPoint)); 
        AddLogJson("\"PointMax\":"+ ToStringTlog(PointMax)); 

    }
    const char * GetTableName() override
    {
        return "FightPointFlow"; 
    }
    static const char * TableName() 
    {
        return "FightPointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t BeforePoint {0};
    int32_t AfterPoint {0};
    int32_t PointMax {0};
    
};
namespace FoggyForestFlowEnum{

}

class FoggyForestFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("Roles", ToStringTlog(Roles)); 
        AddLog("Ais", ToStringTlog(Ais)); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("Chambers", ToStringTlog(Chambers)); 
        AddLog("MonsterChambers", ToStringTlog(MonsterChambers)); 
        AddLog("EventChambers", ToStringTlog(EventChambers)); 
        AddLog("BonusChambers", ToStringTlog(BonusChambers)); 
        AddLog("EliteChambers", ToStringTlog(EliteChambers)); 
        AddLog("BossChambers", ToStringTlog(BossChambers)); 
        AddLog("IfKeyFound", ToStringTlog(IfKeyFound)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"Roles\":"+ ToStringTlog(Roles)); 
        AddLogJson("\"Ais\":"+ ToStringTlog(Ais)); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"Chambers\":"+ ToStringTlog(Chambers)); 
        AddLogJson("\"MonsterChambers\":"+ ToStringTlog(MonsterChambers)); 
        AddLogJson("\"EventChambers\":"+ ToStringTlog(EventChambers)); 
        AddLogJson("\"BonusChambers\":"+ ToStringTlog(BonusChambers)); 
        AddLogJson("\"EliteChambers\":"+ ToStringTlog(EliteChambers)); 
        AddLogJson("\"BossChambers\":"+ ToStringTlog(BossChambers)); 
        AddLogJson("\"IfKeyFound\":"+ ToStringTlog(IfKeyFound)); 

    }
    const char * GetTableName() override
    {
        return "FoggyForestFlow"; 
    }
    static const char * TableName() 
    {
        return "FoggyForestFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t Roles {0};
    int32_t Ais {0};
    int32_t DeadTimes {0};
    int32_t Count {0};
    int32_t Result {0};
    int32_t Time {0};
    int32_t Chambers {0};
    int32_t MonsterChambers {0};
    int32_t EventChambers {0};
    int32_t BonusChambers {0};
    int32_t EliteChambers {0};
    int32_t BossChambers {0};
    int32_t IfKeyFound {0};
    
};
namespace FriendFlowEnum{

    enum class OperateType: uint32_t {
        kLogAddFriend = 0,//主动添加
        kLogPassiveAddFriend = 1,//受邀主动添加
        kLogDeleteFriend = 2,//删除好友
        kLogDefriend = 3,//拉黑
        kLogAddEnemy = 4,//加仇人 
    };    
}

class FriendFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 

    }
    const char * GetTableName() override
    {
        return "FriendFlow"; 
    }
    static const char * TableName() 
    {
        return "FriendFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t Reason {0};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendPoints {0};
    int32_t UnionJudge {0};
    
};
namespace FriendPointFlowEnum{

}

class FriendPointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("PrePoints", ToStringTlog(PrePoints)); 
        AddLog("Points", ToStringTlog(Points)); 
        AddLog("AfterPoints", ToStringTlog(AfterPoints)); 
        AddLog("Reason", ToStringTlog(Reason)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"PrePoints\":"+ ToStringTlog(PrePoints)); 
        AddLogJson("\"Points\":"+ ToStringTlog(Points)); 
        AddLogJson("\"AfterPoints\":"+ ToStringTlog(AfterPoints)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 

    }
    const char * GetTableName() override
    {
        return "FriendPointFlow"; 
    }
    static const char * TableName() 
    {
        return "FriendPointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t AddOrReduce {0};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t UnionJudge {0};
    int32_t PrePoints {0};
    int32_t Points {0};
    int32_t AfterPoints {0};
    int32_t Reason {0};
    
};
namespace GameSvrStateEnum{

}

class GameSvrState : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameIP", vGameIP); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameIP\":\""+vGameIP+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 

    }
    const char * GetTableName() override
    {
        return "GameSvrState"; 
    }
    static const char * TableName() 
    {
        return "GameSvrState"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string dtEventTime {""};
    std::string vGameIP {""};
    int32_t iZoneAreaID {0};
    
};
namespace GatchaFlowEnum{

}

class GatchaFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("GatchaType", ToStringTlog(GatchaType)); 
        AddLog("GatchaPoolID", ToStringTlog(GatchaPoolID)); 
        AddLog("iResourceType", ToStringTlog(iResourceType)); 
        AddLog("iResource", ToStringTlog(iResource)); 
        AddLog("AfterResource", ToStringTlog(AfterResource)); 
        AddLog("iGoodsType", ToStringTlog(iGoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("iGoodsID", ToStringTlog(iGoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("Count", ToStringTlog(Count)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"GatchaType\":"+ ToStringTlog(GatchaType)); 
        AddLogJson("\"GatchaPoolID\":"+ ToStringTlog(GatchaPoolID)); 
        AddLogJson("\"iResourceType\":"+ ToStringTlog(iResourceType)); 
        AddLogJson("\"iResource\":"+ ToStringTlog(iResource)); 
        AddLogJson("\"AfterResource\":"+ ToStringTlog(AfterResource)); 
        AddLogJson("\"iGoodsType\":"+ ToStringTlog(iGoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"iGoodsID\":"+ ToStringTlog(iGoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 

    }
    const char * GetTableName() override
    {
        return "GatchaFlow"; 
    }
    static const char * TableName() 
    {
        return "GatchaFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t GatchaType {0};
    int32_t GatchaPoolID {0};
    int32_t iResourceType {0};
    int32_t iResource {0};
    int32_t AfterResource {0};
    int32_t iGoodsType {0};
    int32_t SubGoodsType {0};
    int32_t iGoodsID {0};
    std::string GoodsName {""};
    int32_t Count {0};
    
};
namespace GatgerComFlowEnum{

    enum class ComType: uint32_t {
        COKING = 0,//烹饪
        PHARMACY = 1,//制药
        DESSERT = 2,//甜品
        SMELT = 3,//制药
        OTHER = 4,//其他 
    };    
    enum class Result: uint32_t {
        SUCCESS = 0,//成功
        FAILED = 1,//失败 
    };    
}

class GatgerComFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ComType", ToStringTlog(ComType)); 
        AddLog("ComLevel", ToStringTlog(ComLevel)); 
        AddLog("Materials", Materials); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("ItemName", ItemName); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("MoneyCost", ToStringTlog(MoneyCost)); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ComType\":"+ ToStringTlog(ComType)); 
        AddLogJson("\"ComLevel\":"+ ToStringTlog(ComLevel)); 
        AddLogJson("\"Materials\":\""+Materials+"\""); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"ItemName\":\""+ItemName+"\""); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"MoneyCost\":"+ ToStringTlog(MoneyCost)); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 

    }
    const char * GetTableName() override
    {
        return "GatgerComFlow"; 
    }
    static const char * TableName() 
    {
        return "GatgerComFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ComType {0};
    int32_t ComLevel {0};
    std::string Materials {""};
    int32_t Result {0};
    int32_t ItemID {0};
    std::string ItemName {""};
    int32_t Count {0};
    int32_t MoneyCost {0};
    int32_t MoneyType {0};
    
};
namespace GatgerFlowEnum{

    enum class GatherType: uint32_t {
        PICK = 0,//采摘
        DIG = 1,//挖矿
        FISH = 2,//钓鱼 
    };    
    enum class BuffType: uint32_t {
        BUFF_ON = 0,//有加成
        BUFF_OFF = 1,//无加成 
    };    
}

class GatgerFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("GatherType", ToStringTlog(GatherType)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("BuffType", ToStringTlog(BuffType)); 
        AddLog("BuffID", ToStringTlog(BuffID)); 
        AddLog("BuffName", BuffName); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("IsAuto", ToStringTlog(IsAuto)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"GatherType\":"+ ToStringTlog(GatherType)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"BuffType\":"+ ToStringTlog(BuffType)); 
        AddLogJson("\"BuffID\":"+ ToStringTlog(BuffID)); 
        AddLogJson("\"BuffName\":\""+BuffName+"\""); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"IsAuto\":"+ ToStringTlog(IsAuto)); 

    }
    const char * GetTableName() override
    {
        return "GatgerFlow"; 
    }
    static const char * TableName() 
    {
        return "GatgerFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t GatherType {0};
    int32_t MapID {0};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    int32_t BuffType {0};
    int32_t BuffID {0};
    std::string BuffName {""};
    int32_t Count {0};
    int32_t IsAuto {0};
    
};
namespace GatherFlowEnum{

}

class GatherFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ArchiveType", ToStringTlog(ArchiveType)); 
        AddLog("PartType", ToStringTlog(PartType)); 
        AddLog("CardType", ToStringTlog(CardType)); 
        AddLog("Body", ToStringTlog(Body)); 
        AddLog("Race", ToStringTlog(Race)); 
        AddLog("Elememt", ToStringTlog(Elememt)); 
        AddLog("ArchiveID", ToStringTlog(ArchiveID)); 
        AddLog("ArchiveName", ArchiveName); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("PreProgress", ToStringTlog(PreProgress)); 
        AddLog("AfterProgress", ToStringTlog(AfterProgress)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ArchiveType\":"+ ToStringTlog(ArchiveType)); 
        AddLogJson("\"PartType\":"+ ToStringTlog(PartType)); 
        AddLogJson("\"CardType\":"+ ToStringTlog(CardType)); 
        AddLogJson("\"Body\":"+ ToStringTlog(Body)); 
        AddLogJson("\"Race\":"+ ToStringTlog(Race)); 
        AddLogJson("\"Elememt\":"+ ToStringTlog(Elememt)); 
        AddLogJson("\"ArchiveID\":"+ ToStringTlog(ArchiveID)); 
        AddLogJson("\"ArchiveName\":\""+ArchiveName+"\""); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"PreProgress\":"+ ToStringTlog(PreProgress)); 
        AddLogJson("\"AfterProgress\":"+ ToStringTlog(AfterProgress)); 

    }
    const char * GetTableName() override
    {
        return "GatherFlow"; 
    }
    static const char * TableName() 
    {
        return "GatherFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t ArchiveType {0};
    int32_t PartType {0};
    int32_t CardType {0};
    int32_t Body {0};
    int32_t Race {0};
    int32_t Elememt {0};
    int32_t ArchiveID {0};
    std::string ArchiveName {""};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t PreProgress {0};
    int32_t AfterProgress {0};
    
};
namespace GiftChoiceFlowEnum{

}

class GiftChoiceFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("GiftItemID", ToStringTlog(GiftItemID)); 
        AddLog("GiftItemName", GiftItemName); 
        AddLog("GiftChoiceID", ToStringTlog(GiftChoiceID)); 
        AddLog("GiftChoiceName", GiftChoiceName); 
        AddLog("GiftChoiceNum", ToStringTlog(GiftChoiceNum)); 
        AddLog("GiftChoiceIfALL", GiftChoiceIfALL); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"GiftItemID\":"+ ToStringTlog(GiftItemID)); 
        AddLogJson("\"GiftItemName\":\""+GiftItemName+"\""); 
        AddLogJson("\"GiftChoiceID\":"+ ToStringTlog(GiftChoiceID)); 
        AddLogJson("\"GiftChoiceName\":\""+GiftChoiceName+"\""); 
        AddLogJson("\"GiftChoiceNum\":"+ ToStringTlog(GiftChoiceNum)); 
        AddLogJson("\"GiftChoiceIfALL\":\""+GiftChoiceIfALL+"\""); 

    }
    const char * GetTableName() override
    {
        return "GiftChoiceFlow"; 
    }
    static const char * TableName() 
    {
        return "GiftChoiceFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t GiftItemID {0};
    std::string GiftItemName {""};
    int32_t GiftChoiceID {0};
    std::string GiftChoiceName {""};
    int32_t GiftChoiceNum {0};
    std::string GiftChoiceIfALL {""};
    
};
namespace GoodsTradingFlowEnum{

}

class GoodsTradingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 
        AddLog("EventID", ToStringTlog(EventID)); 
        AddLog("EventName", EventName); 
        AddLog("NPCName", NPCName); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("MapName", MapName); 
        AddLog("QualityType", ToStringTlog(QualityType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("PrePrice", ToStringTlog(PrePrice)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("MoneyCost", ToStringTlog(MoneyCost)); 
        AddLog("MoneyRemain", ToStringTlog(MoneyRemain)); 
        AddLog("TradeCount", ToStringTlog(TradeCount)); 
        AddLog("Times", ToStringTlog(Times)); 
        AddLog("Result", ToStringTlog(Result)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 
        AddLogJson("\"EventID\":"+ ToStringTlog(EventID)); 
        AddLogJson("\"EventName\":\""+EventName+"\""); 
        AddLogJson("\"NPCName\":\""+NPCName+"\""); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"MapName\":\""+MapName+"\""); 
        AddLogJson("\"QualityType\":"+ ToStringTlog(QualityType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"PrePrice\":"+ ToStringTlog(PrePrice)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"MoneyCost\":"+ ToStringTlog(MoneyCost)); 
        AddLogJson("\"MoneyRemain\":"+ ToStringTlog(MoneyRemain)); 
        AddLogJson("\"TradeCount\":"+ ToStringTlog(TradeCount)); 
        AddLogJson("\"Times\":"+ ToStringTlog(Times)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 

    }
    const char * GetTableName() override
    {
        return "GoodsTradingFlow"; 
    }
    static const char * TableName() 
    {
        return "GoodsTradingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int64_t TradeID {0};
    int32_t EventID {0};
    std::string EventName {""};
    std::string NPCName {""};
    int32_t MapID {0};
    std::string MapName {""};
    int32_t QualityType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t PrePrice {0};
    int32_t Price {0};
    int32_t GoodsCount {0};
    int32_t MoneyCost {0};
    int32_t MoneyRemain {0};
    int32_t TradeCount {0};
    int32_t Times {0};
    int32_t Result {0};
    
};
namespace GuildManualFlowEnum{

}

class GuildManualFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("GuildID", ToStringTlog(GuildID)); 
        AddLog("GuildName", GuildName); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("GuildManualScore", ToStringTlog(GuildManualScore)); 
        AddLog("GuildManualStage", ToStringTlog(GuildManualStage)); 
        AddLog("StageTimeSpend", ToStringTlog(StageTimeSpend)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"GuildID\":"+ ToStringTlog(GuildID)); 
        AddLogJson("\"GuildName\":\""+GuildName+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"GuildManualScore\":"+ ToStringTlog(GuildManualScore)); 
        AddLogJson("\"GuildManualStage\":"+ ToStringTlog(GuildManualStage)); 
        AddLogJson("\"StageTimeSpend\":"+ ToStringTlog(StageTimeSpend)); 

    }
    const char * GetTableName() override
    {
        return "GuildManualFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildManualFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int64_t GuildID {0};
    std::string GuildName {""};
    int32_t OperateType {0};
    int32_t GuildManualScore {0};
    int32_t GuildManualStage {0};
    int32_t StageTimeSpend {0};
    
};
namespace GuildManualPersonalFlowEnum{

}

class GuildManualPersonalFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("OperateNumber", ToStringTlog(OperateNumber)); 
        AddLog("ManualScore", ToStringTlog(ManualScore)); 
        AddLog("RewardStage", ToStringTlog(RewardStage)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"OperateNumber\":"+ ToStringTlog(OperateNumber)); 
        AddLogJson("\"ManualScore\":"+ ToStringTlog(ManualScore)); 
        AddLogJson("\"RewardStage\":"+ ToStringTlog(RewardStage)); 

    }
    const char * GetTableName() override
    {
        return "GuildManualPersonalFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildManualPersonalFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t OperateNumber {0};
    int32_t ManualScore {0};
    int32_t RewardStage {0};
    
};
namespace GuildMatchApplyFlowEnum{

}

class GuildMatchApplyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamNum", ToStringTlog(TeamNum)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("TeamJobs", TeamJobs); 
        AddLog("CanceledPlayerId", CanceledPlayerId); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamNum\":"+ ToStringTlog(TeamNum)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"TeamJobs\":\""+TeamJobs+"\""); 
        AddLogJson("\"CanceledPlayerId\":\""+CanceledPlayerId+"\""); 

    }
    const char * GetTableName() override
    {
        return "GuildMatchApplyFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildMatchApplyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamNum {0};
    int32_t InterValue {0};
    std::string TeamJobs {""};
    std::string CanceledPlayerId {""};
    
};
namespace GuildMatchResultFlowEnum{

}

class GuildMatchResultFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MatchID", ToStringTlog(MatchID)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("mTeamType", ToStringTlog(mTeamType)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("TeamInfo", TeamInfo); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("Round", ToStringTlog(Round)); 
        AddLog("DeadCount", ToStringTlog(DeadCount)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("MVP", ToStringTlog(MVP)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("CampPoints", ToStringTlog(CampPoints)); 
        AddLog("FlowerBuffTime", ToStringTlog(FlowerBuffTime)); 
        AddLog("FlowersInRound", ToStringTlog(FlowersInRound)); 
        AddLog("FlowersTotal", ToStringTlog(FlowersTotal)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MatchID\":"+ ToStringTlog(MatchID)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"mTeamType\":"+ ToStringTlog(mTeamType)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"TeamInfo\":\""+TeamInfo+"\""); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"Round\":"+ ToStringTlog(Round)); 
        AddLogJson("\"DeadCount\":"+ ToStringTlog(DeadCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"MVP\":"+ ToStringTlog(MVP)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"CampPoints\":"+ ToStringTlog(CampPoints)); 
        AddLogJson("\"FlowerBuffTime\":"+ ToStringTlog(FlowerBuffTime)); 
        AddLogJson("\"FlowersInRound\":"+ ToStringTlog(FlowersInRound)); 
        AddLogJson("\"FlowersTotal\":"+ ToStringTlog(FlowersTotal)); 

    }
    const char * GetTableName() override
    {
        return "GuildMatchResultFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildMatchResultFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MatchID {0};
    int32_t TeamID {0};
    int32_t mTeamType {0};
    int32_t InterValue {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    std::string TeamInfo {""};
    int32_t Result {0};
    int32_t Round {0};
    int32_t DeadCount {0};
    int32_t Score {0};
    int32_t MVP {0};
    int32_t Time {0};
    int32_t CampPoints {0};
    int32_t FlowerBuffTime {0};
    int32_t FlowersInRound {0};
    int32_t FlowersTotal {0};
    
};
namespace GuildMatchSetTeamFlowEnum{

}

class GuildMatchSetTeamFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Team1", Team1); 
        AddLog("Team2", Team2); 
        AddLog("Team3", Team3); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Team1\":\""+Team1+"\""); 
        AddLogJson("\"Team2\":\""+Team2+"\""); 
        AddLogJson("\"Team3\":\""+Team3+"\""); 

    }
    const char * GetTableName() override
    {
        return "GuildMatchSetTeamFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildMatchSetTeamFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DutyType {0};
    std::string Team1 {""};
    std::string Team2 {""};
    std::string Team3 {""};
    
};
namespace GuildMsgGoodSnapshotFlowEnum{

}

class GuildMsgGoodSnapshotFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("NewsId", ToStringTlog(NewsId)); 
        AddLog("GiveALiketype", ToStringTlog(GiveALiketype)); 
        AddLog("Newstype", ToStringTlog(Newstype)); 
        AddLog("ZDorNot", ToStringTlog(ZDorNot)); 
        AddLog("NewsPlayer", NewsPlayer); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"NewsId\":"+ ToStringTlog(NewsId)); 
        AddLogJson("\"GiveALiketype\":"+ ToStringTlog(GiveALiketype)); 
        AddLogJson("\"Newstype\":"+ ToStringTlog(Newstype)); 
        AddLogJson("\"ZDorNot\":"+ ToStringTlog(ZDorNot)); 
        AddLogJson("\"NewsPlayer\":\""+NewsPlayer+"\""); 

    }
    const char * GetTableName() override
    {
        return "GuildMsgGoodSnapshotFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildMsgGoodSnapshotFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t NewsId {0};
    int32_t GiveALiketype {0};
    int32_t Newstype {0};
    int32_t ZDorNot {0};
    std::string NewsPlayer {""};
    
};
namespace GuildRankFlowEnum{

}

class GuildRankFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("GuildID", ToStringTlog(GuildID)); 
        AddLog("GuildName", GuildName); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("GuildScoreChangeType", ToStringTlog(GuildScoreChangeType)); 
        AddLog("GuildScoreChange", ToStringTlog(GuildScoreChange)); 
        AddLog("GuildRankGroupBefore", ToStringTlog(GuildRankGroupBefore)); 
        AddLog("GuildRankBefore", ToStringTlog(GuildRankBefore)); 
        AddLog("GuildRankGroupAfter", ToStringTlog(GuildRankGroupAfter)); 
        AddLog("GuildRankAfter", ToStringTlog(GuildRankAfter)); 
        AddLog("GuildRankSingleType", ToStringTlog(GuildRankSingleType)); 
        AddLog("GuildRankSingle", ToStringTlog(GuildRankSingle)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"GuildID\":"+ ToStringTlog(GuildID)); 
        AddLogJson("\"GuildName\":\""+GuildName+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"GuildScoreChangeType\":"+ ToStringTlog(GuildScoreChangeType)); 
        AddLogJson("\"GuildScoreChange\":"+ ToStringTlog(GuildScoreChange)); 
        AddLogJson("\"GuildRankGroupBefore\":"+ ToStringTlog(GuildRankGroupBefore)); 
        AddLogJson("\"GuildRankBefore\":"+ ToStringTlog(GuildRankBefore)); 
        AddLogJson("\"GuildRankGroupAfter\":"+ ToStringTlog(GuildRankGroupAfter)); 
        AddLogJson("\"GuildRankAfter\":"+ ToStringTlog(GuildRankAfter)); 
        AddLogJson("\"GuildRankSingleType\":"+ ToStringTlog(GuildRankSingleType)); 
        AddLogJson("\"GuildRankSingle\":"+ ToStringTlog(GuildRankSingle)); 

    }
    const char * GetTableName() override
    {
        return "GuildRankFlow"; 
    }
    static const char * TableName() 
    {
        return "GuildRankFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int64_t GuildID {0};
    std::string GuildName {""};
    int32_t OperateType {0};
    int32_t GuildScoreChangeType {0};
    int32_t GuildScoreChange {0};
    int32_t GuildRankGroupBefore {0};
    int32_t GuildRankBefore {0};
    int32_t GuildRankGroupAfter {0};
    int32_t GuildRankAfter {0};
    int32_t GuildRankSingleType {0};
    int32_t GuildRankSingle {0};
    
};
namespace HymnTrialEnum{

    enum class OperateType: uint32_t {
        TAKE_TASK = 0,//接受任务
        FINISH_TASK = 1,//完成任务
        GIVE_UP_TASK = 2,//放弃任务 
    };    
    enum class TrialType: uint32_t {
        NORMAL = 0,//普通试炼
        SPECIAL = 1,//特殊事件 
    };    
}

class HymnTrial : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TrialType", ToStringTlog(TrialType)); 
        AddLog("TrialFinishRoundNum", ToStringTlog(TrialFinishRoundNum)); 
        AddLog("TrialOneCountTime", ToStringTlog(TrialOneCountTime)); 
        AddLog("TrialEventNum", ToStringTlog(TrialEventNum)); 
        AddLog("TrialEventCostTime", ToStringTlog(TrialEventCostTime)); 
        AddLog("ReceivePraiseCount", ToStringTlog(ReceivePraiseCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TrialType\":"+ ToStringTlog(TrialType)); 
        AddLogJson("\"TrialFinishRoundNum\":"+ ToStringTlog(TrialFinishRoundNum)); 
        AddLogJson("\"TrialOneCountTime\":"+ ToStringTlog(TrialOneCountTime)); 
        AddLogJson("\"TrialEventNum\":"+ ToStringTlog(TrialEventNum)); 
        AddLogJson("\"TrialEventCostTime\":"+ ToStringTlog(TrialEventCostTime)); 
        AddLogJson("\"ReceivePraiseCount\":"+ ToStringTlog(ReceivePraiseCount)); 

    }
    const char * GetTableName() override
    {
        return "HymnTrial"; 
    }
    static const char * TableName() 
    {
        return "HymnTrial"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TrialType {0};
    int32_t TrialFinishRoundNum {0};
    int32_t TrialOneCountTime {0};
    int32_t TrialEventNum {0};
    int32_t TrialEventCostTime {0};
    int32_t ReceivePraiseCount {0};
    
};
namespace InfiniteTowerEnum{

}

class InfiniteTower : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TowerFloor", ToStringTlog(TowerFloor)); 
        AddLog("RoundNum", ToStringTlog(RoundNum)); 
        AddLog("CountTime", ToStringTlog(CountTime)); 
        AddLog("LuckyCount", ToStringTlog(LuckyCount)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("ElementID", ElementID); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TowerFloor\":"+ ToStringTlog(TowerFloor)); 
        AddLogJson("\"RoundNum\":"+ ToStringTlog(RoundNum)); 
        AddLogJson("\"CountTime\":"+ ToStringTlog(CountTime)); 
        AddLogJson("\"LuckyCount\":"+ ToStringTlog(LuckyCount)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"ElementID\":\""+ElementID+"\""); 

    }
    const char * GetTableName() override
    {
        return "InfiniteTower"; 
    }
    static const char * TableName() 
    {
        return "InfiniteTower"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TowerFloor {0};
    int32_t RoundNum {0};
    int32_t CountTime {0};
    int32_t LuckyCount {0};
    int32_t Result {0};
    std::string ElementID {""};
    
};
namespace InteractiveMotionFlowEnum{

}

class InteractiveMotionFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TargetType", ToStringTlog(TargetType)); 
        AddLog("NPCID", ToStringTlog(NPCID)); 
        AddLog("NPCname", NPCname); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("MotionType", ToStringTlog(MotionType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TargetType\":"+ ToStringTlog(TargetType)); 
        AddLogJson("\"NPCID\":"+ ToStringTlog(NPCID)); 
        AddLogJson("\"NPCname\":\""+NPCname+"\""); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"MotionType\":"+ ToStringTlog(MotionType)); 

    }
    const char * GetTableName() override
    {
        return "InteractiveMotionFlow"; 
    }
    static const char * TableName() 
    {
        return "InteractiveMotionFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TargetType {0};
    int32_t NPCID {0};
    std::string NPCname {""};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    int32_t FriendPoints {0};
    int32_t MotionType {0};
    
};
namespace ItemFlowEnum{

    enum class iGoodsType: uint32_t {
        ItemType_Invalid = 0,//无
        ItemType_Equip = 1,//装备
        ItemType_Consumables = 2,//消耗品
        ItemType_Material = 3,//材料
        ItemType_Card = 4,//卡片
        ItemType_BagOther = 5,//背包内不分类道具
        ItemType_Fashion = 6,//时装
        ItemType_Money = 7,//虚拟道具，货币
        ItemType_CookBook = 8,//食谱
        ItemType_Task = 9,//任务道具
        ItemType_LifeEquip = 10,//生活职业道具
        ItemType_HeadwearDrawing = 11,//头饰图纸
        ItemType_Device = 12,//置换器
        ItemType_HeadPortrait = 13,//头像
        ItemType_Carrier = 14,//载具
        ItemType_CarrierExpBook = 15,//载具经验书
        ItemType_CardPatch = 16,//卡牌碎片
        ItemType_Title = 17,//称号
        ItemType_Commodity = 18,//跑商道具
        ItemType_Monster = 19,//魔物
        ItemType_Belluz = 20,//贝鲁兹
        ItemType_EnchantStone = 21,//封魔石 
    };    
}

class ItemFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Sequence", ToStringTlog(Sequence)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("iGoodsType", ToStringTlog(iGoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("iGoodsID", ToStringTlog(iGoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("AfterCount", ToStringTlog(AfterCount)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("iMoneyType", ToStringTlog(iMoneyType)); 
        AddLog("iMoney", ToStringTlog(iMoney)); 
        AddLog("serialnum", serialnum); 
        AddLog("sourceID", ToStringTlog(sourceID)); 
        AddLog("Cmd", Cmd); 
        AddLog("TotalOnlineTime", ToStringTlog(TotalOnlineTime)); 
        AddLog("BindInfo", ToStringTlog(BindInfo)); 
        AddLog("Position", ToStringTlog(Position)); 
        AddLog("SelfDefinedPara1", ToStringTlog(SelfDefinedPara1)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Sequence\":"+ ToStringTlog(Sequence)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"iGoodsType\":"+ ToStringTlog(iGoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"iGoodsID\":"+ ToStringTlog(iGoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"AfterCount\":"+ ToStringTlog(AfterCount)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"iMoneyType\":"+ ToStringTlog(iMoneyType)); 
        AddLogJson("\"iMoney\":"+ ToStringTlog(iMoney)); 
        AddLogJson("\"serialnum\":\""+serialnum+"\""); 
        AddLogJson("\"sourceID\":"+ ToStringTlog(sourceID)); 
        AddLogJson("\"Cmd\":\""+Cmd+"\""); 
        AddLogJson("\"TotalOnlineTime\":"+ ToStringTlog(TotalOnlineTime)); 
        AddLogJson("\"BindInfo\":"+ ToStringTlog(BindInfo)); 
        AddLogJson("\"Position\":"+ ToStringTlog(Position)); 
        AddLogJson("\"SelfDefinedPara1\":"+ ToStringTlog(SelfDefinedPara1)); 

    }
    const char * GetTableName() override
    {
        return "ItemFlow"; 
    }
    static const char * TableName() 
    {
        return "ItemFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Sequence {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t iGoodsType {0};
    int32_t SubGoodsType {0};
    int32_t iGoodsID {0};
    std::string GoodsName {""};
    int32_t Count {0};
    int32_t AfterCount {0};
    int32_t AddOrReduce {0};
    int32_t iMoneyType {0};
    int32_t iMoney {0};
    std::string serialnum {""};
    int32_t sourceID {0};
    std::string Cmd {""};
    int32_t TotalOnlineTime {0};
    int32_t BindInfo {0};
    int32_t Position {0};
    int32_t SelfDefinedPara1 {0};
    
};
namespace LeaderboardFlowEnum{

}

class LeaderboardFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("LbFrameName", LbFrameName); 
        AddLog("LbName", LbName); 
        AddLog("LbComponentName", LbComponentName); 
        AddLog("LbRecordCount", ToStringTlog(LbRecordCount)); 
        AddLog("LbRecordMaxValue", ToStringTlog(LbRecordMaxValue)); 
        AddLog("LbRecordMinValue", ToStringTlog(LbRecordMinValue)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"LbFrameName\":\""+LbFrameName+"\""); 
        AddLogJson("\"LbName\":\""+LbName+"\""); 
        AddLogJson("\"LbComponentName\":\""+LbComponentName+"\""); 
        AddLogJson("\"LbRecordCount\":"+ ToStringTlog(LbRecordCount)); 
        AddLogJson("\"LbRecordMaxValue\":"+ ToStringTlog(LbRecordMaxValue)); 
        AddLogJson("\"LbRecordMinValue\":"+ ToStringTlog(LbRecordMinValue)); 

    }
    const char * GetTableName() override
    {
        return "LeaderboardFlow"; 
    }
    static const char * TableName() 
    {
        return "LeaderboardFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    std::string LbFrameName {""};
    std::string LbName {""};
    std::string LbComponentName {""};
    int32_t LbRecordCount {0};
    int32_t LbRecordMaxValue {0};
    int32_t LbRecordMinValue {0};
    
};
namespace LikeFlowEnum{

    enum class PlayerType: uint32_t {
        LIKE = 0,//点赞
        BE_LIKED = 1,//被点赞 
    };    
    enum class LikeType: uint32_t {
        THEME = 0,//主题副本
        BATTLEFIELD = 1,//战场
        HYMNTRIAL = 2,//圣歌 
    };    
}

class LikeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PlayerType", ToStringTlog(PlayerType)); 
        AddLog("LikeType", ToStringTlog(LikeType)); 
        AddLog("EventID", ToStringTlog(EventID)); 
        AddLog("EventName", EventName); 
        AddLog("LikeCount", ToStringTlog(LikeCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PlayerType\":"+ ToStringTlog(PlayerType)); 
        AddLogJson("\"LikeType\":"+ ToStringTlog(LikeType)); 
        AddLogJson("\"EventID\":"+ ToStringTlog(EventID)); 
        AddLogJson("\"EventName\":\""+EventName+"\""); 
        AddLogJson("\"LikeCount\":"+ ToStringTlog(LikeCount)); 

    }
    const char * GetTableName() override
    {
        return "LikeFlow"; 
    }
    static const char * TableName() 
    {
        return "LikeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PlayerType {0};
    int32_t LikeType {0};
    int32_t EventID {0};
    std::string EventName {""};
    int32_t LikeCount {0};
    
};
namespace LuckyMoneyFlowEnum{

}

class LuckyMoneyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("LMActType", ToStringTlog(LMActType)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("LMType", ToStringTlog(LMType)); 
        AddLog("LMMoneyType", ToStringTlog(LMMoneyType)); 
        AddLog("LMTotalMoney", ToStringTlog(LMTotalMoney)); 
        AddLog("LMTotalAmount", ToStringTlog(LMTotalAmount)); 
        AddLog("LMMyMoney", ToStringTlog(LMMyMoney)); 
        AddLog("LMMyAmount", ToStringTlog(LMMyAmount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"LMActType\":"+ ToStringTlog(LMActType)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"LMType\":"+ ToStringTlog(LMType)); 
        AddLogJson("\"LMMoneyType\":"+ ToStringTlog(LMMoneyType)); 
        AddLogJson("\"LMTotalMoney\":"+ ToStringTlog(LMTotalMoney)); 
        AddLogJson("\"LMTotalAmount\":"+ ToStringTlog(LMTotalAmount)); 
        AddLogJson("\"LMMyMoney\":"+ ToStringTlog(LMMyMoney)); 
        AddLogJson("\"LMMyAmount\":"+ ToStringTlog(LMMyAmount)); 

    }
    const char * GetTableName() override
    {
        return "LuckyMoneyFlow"; 
    }
    static const char * TableName() 
    {
        return "LuckyMoneyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t LMActType {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    int32_t FriendPoints {0};
    int32_t LMType {0};
    int32_t LMMoneyType {0};
    int32_t LMTotalMoney {0};
    int32_t LMTotalAmount {0};
    int32_t LMMyMoney {0};
    int32_t LMMyAmount {0};
    
};
namespace LuckyPointFlowEnum{

}

class LuckyPointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("Awardid", ToStringTlog(Awardid)); 
        AddLog("Packid", ToStringTlog(Packid)); 
        AddLog("ItemList", ItemList); 
        AddLog("CurrentChange", ToStringTlog(CurrentChange)); 
        AddLog("LuckyPoint", ToStringTlog(LuckyPoint)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"Awardid\":"+ ToStringTlog(Awardid)); 
        AddLogJson("\"Packid\":"+ ToStringTlog(Packid)); 
        AddLogJson("\"ItemList\":\""+ItemList+"\""); 
        AddLogJson("\"CurrentChange\":"+ ToStringTlog(CurrentChange)); 
        AddLogJson("\"LuckyPoint\":"+ ToStringTlog(LuckyPoint)); 

    }
    const char * GetTableName() override
    {
        return "LuckyPointFlow"; 
    }
    static const char * TableName() 
    {
        return "LuckyPointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t Reason {0};
    int32_t Awardid {0};
    int32_t Packid {0};
    std::string ItemList {""};
    int32_t CurrentChange {0};
    int32_t LuckyPoint {0};
    
};
namespace MailFlowEnum{

}

class MailFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MailType", ToStringTlog(MailType)); 
        AddLog("ReceiveName", ReceiveName); 
        AddLog("Title", Title); 
        AddLog("Content", Content); 
        AddLog("AttachCount", ToStringTlog(AttachCount)); 
        AddLog("ResourceAttach", ResourceAttach); 
        AddLog("GoodsAttach", GoodsAttach); 
        AddLog("TitlePara", TitlePara); 
        AddLog("ContentPara", ContentPara); 
        AddLog("SelfDefinedPara1", SelfDefinedPara1); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MailType\":"+ ToStringTlog(MailType)); 
        AddLogJson("\"ReceiveName\":\""+ReceiveName+"\""); 
        AddLogJson("\"Title\":\""+Title+"\""); 
        AddLogJson("\"Content\":\""+Content+"\""); 
        AddLogJson("\"AttachCount\":"+ ToStringTlog(AttachCount)); 
        AddLogJson("\"ResourceAttach\":\""+ResourceAttach+"\""); 
        AddLogJson("\"GoodsAttach\":\""+GoodsAttach+"\""); 
        AddLogJson("\"TitlePara\":\""+TitlePara+"\""); 
        AddLogJson("\"ContentPara\":\""+ContentPara+"\""); 
        AddLogJson("\"SelfDefinedPara1\":\""+SelfDefinedPara1+"\""); 

    }
    const char * GetTableName() override
    {
        return "MailFlow"; 
    }
    static const char * TableName() 
    {
        return "MailFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MailType {0};
    std::string ReceiveName {""};
    std::string Title {""};
    std::string Content {""};
    int32_t AttachCount {0};
    std::string ResourceAttach {""};
    std::string GoodsAttach {""};
    std::string TitlePara {""};
    std::string ContentPara {""};
    std::string SelfDefinedPara1 {""};
    
};
namespace MailTakeFlowEnum{

    enum class OperateType: uint32_t {
        RECEIVE = 0,//领取附件
        REMOVE = 1,//删除附件 
    };    
}

class MailTakeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MailType", ToStringTlog(MailType)); 
        AddLog("ReceiveName", ReceiveName); 
        AddLog("Title", Title); 
        AddLog("Content", Content); 
        AddLog("AttachCount", ToStringTlog(AttachCount)); 
        AddLog("ResourceAttach", ResourceAttach); 
        AddLog("GoodsAttach", GoodsAttach); 
        AddLog("TitlePara", TitlePara); 
        AddLog("ContentPara", ContentPara); 
        AddLog("SelfDefinedPara1", SelfDefinedPara1); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MailType\":"+ ToStringTlog(MailType)); 
        AddLogJson("\"ReceiveName\":\""+ReceiveName+"\""); 
        AddLogJson("\"Title\":\""+Title+"\""); 
        AddLogJson("\"Content\":\""+Content+"\""); 
        AddLogJson("\"AttachCount\":"+ ToStringTlog(AttachCount)); 
        AddLogJson("\"ResourceAttach\":\""+ResourceAttach+"\""); 
        AddLogJson("\"GoodsAttach\":\""+GoodsAttach+"\""); 
        AddLogJson("\"TitlePara\":\""+TitlePara+"\""); 
        AddLogJson("\"ContentPara\":\""+ContentPara+"\""); 
        AddLogJson("\"SelfDefinedPara1\":\""+SelfDefinedPara1+"\""); 

    }
    const char * GetTableName() override
    {
        return "MailTakeFlow"; 
    }
    static const char * TableName() 
    {
        return "MailTakeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MailType {0};
    std::string ReceiveName {""};
    std::string Title {""};
    std::string Content {""};
    int32_t AttachCount {0};
    std::string ResourceAttach {""};
    std::string GoodsAttach {""};
    std::string TitlePara {""};
    std::string ContentPara {""};
    std::string SelfDefinedPara1 {""};
    
};
namespace MallTradeFlowEnum{

    enum class ifDiscount: uint32_t {
        NO = 0,//否
        YES = 1,//是 
    };    
}

class MallTradeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MallType", ToStringTlog(MallType)); 
        AddLog("MallSubType", ToStringTlog(MallSubType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("ifDiscount", ToStringTlog(ifDiscount)); 
        AddLog("DiscountRate", ToStringTlog(DiscountRate)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("BeforeMoney", ToStringTlog(BeforeMoney)); 
        AddLog("AfterMoney", ToStringTlog(AfterMoney)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MallType\":"+ ToStringTlog(MallType)); 
        AddLogJson("\"MallSubType\":"+ ToStringTlog(MallSubType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"ifDiscount\":"+ ToStringTlog(ifDiscount)); 
        AddLogJson("\"DiscountRate\":"+ ToStringTlog(DiscountRate)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"BeforeMoney\":"+ ToStringTlog(BeforeMoney)); 
        AddLogJson("\"AfterMoney\":"+ ToStringTlog(AfterMoney)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 

    }
    const char * GetTableName() override
    {
        return "MallTradeFlow"; 
    }
    static const char * TableName() 
    {
        return "MallTradeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MallType {0};
    int32_t MallSubType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t ifDiscount {0};
    int32_t DiscountRate {0};
    int32_t GoodsCount {0};
    int32_t BeforeMoney {0};
    int32_t AfterMoney {0};
    int64_t TradeID {0};
    
};
namespace MercenaryFlowEnum{

    enum class OperateType: uint32_t {
        kOpRecruit = 0,//佣兵解锁
        kTakeOut = 1,//佣兵出战
        kTakeBack = 2,//佣兵停止出战 
    };    
}

class MercenaryFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MercenaryID", ToStringTlog(MercenaryID)); 
        AddLog("MercenaryName", MercenaryName); 
        AddLog("MercenaryLevel", ToStringTlog(MercenaryLevel)); 
        AddLog("MercenaryJob", ToStringTlog(MercenaryJob)); 
        AddLog("MercenaryPower", ToStringTlog(MercenaryPower)); 
        AddLog("Mercenaryposit", ToStringTlog(Mercenaryposit)); 
        AddLog("EquipList", EquipList); 
        AddLog("SkillList", SkillList); 
        AddLog("MerceneryStyleID", ToStringTlog(MerceneryStyleID)); 
        AddLog("MercenaryTalentList", MercenaryTalentList); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MercenaryID\":"+ ToStringTlog(MercenaryID)); 
        AddLogJson("\"MercenaryName\":\""+MercenaryName+"\""); 
        AddLogJson("\"MercenaryLevel\":"+ ToStringTlog(MercenaryLevel)); 
        AddLogJson("\"MercenaryJob\":"+ ToStringTlog(MercenaryJob)); 
        AddLogJson("\"MercenaryPower\":"+ ToStringTlog(MercenaryPower)); 
        AddLogJson("\"Mercenaryposit\":"+ ToStringTlog(Mercenaryposit)); 
        AddLogJson("\"EquipList\":\""+EquipList+"\""); 
        AddLogJson("\"SkillList\":\""+SkillList+"\""); 
        AddLogJson("\"MerceneryStyleID\":"+ ToStringTlog(MerceneryStyleID)); 
        AddLogJson("\"MercenaryTalentList\":\""+MercenaryTalentList+"\""); 

    }
    const char * GetTableName() override
    {
        return "MercenaryFlow"; 
    }
    static const char * TableName() 
    {
        return "MercenaryFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MercenaryID {0};
    std::string MercenaryName {""};
    int32_t MercenaryLevel {0};
    int32_t MercenaryJob {0};
    int32_t MercenaryPower {0};
    int32_t Mercenaryposit {0};
    std::string EquipList {""};
    std::string SkillList {""};
    int32_t MerceneryStyleID {0};
    std::string MercenaryTalentList {""};
    
};
namespace MinigameFlowEnum{

}

class MinigameFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MinigameID", ToStringTlog(MinigameID)); 
        AddLog("MinigameName", MinigameName); 
        AddLog("MaxHP", ToStringTlog(MaxHP)); 
        AddLog("FinalHP", ToStringTlog(FinalHP)); 
        AddLog("Time", ToStringTlog(Time)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MinigameID\":"+ ToStringTlog(MinigameID)); 
        AddLogJson("\"MinigameName\":\""+MinigameName+"\""); 
        AddLogJson("\"MaxHP\":"+ ToStringTlog(MaxHP)); 
        AddLogJson("\"FinalHP\":"+ ToStringTlog(FinalHP)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 

    }
    const char * GetTableName() override
    {
        return "MinigameFlow"; 
    }
    static const char * TableName() 
    {
        return "MinigameFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MinigameID {0};
    std::string MinigameName {""};
    int32_t MaxHP {0};
    int32_t FinalHP {0};
    int32_t Time {0};
    
};
namespace MoneyFlowEnum{

    enum class iMoneyType: uint32_t {
        ZENY = 1,//铜币
        ROMONRY = 2,//zeny
        DIAMOND = 3,//金币 
    };    
}

class MoneyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Sequence", ToStringTlog(Sequence)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("iMoneyType", ToStringTlog(iMoneyType)); 
        AddLog("iMoney", ToStringTlog(iMoney)); 
        AddLog("AfterMoney", ToStringTlog(AfterMoney)); 
        AddLog("AfterBoundMoney", ToStringTlog(AfterBoundMoney)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("serialnum", serialnum); 
        AddLog("sourceID", ToStringTlog(sourceID)); 
        AddLog("Cmd", Cmd); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Sequence\":"+ ToStringTlog(Sequence)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"iMoneyType\":"+ ToStringTlog(iMoneyType)); 
        AddLogJson("\"iMoney\":"+ ToStringTlog(iMoney)); 
        AddLogJson("\"AfterMoney\":"+ ToStringTlog(AfterMoney)); 
        AddLogJson("\"AfterBoundMoney\":"+ ToStringTlog(AfterBoundMoney)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"serialnum\":\""+serialnum+"\""); 
        AddLogJson("\"sourceID\":"+ ToStringTlog(sourceID)); 
        AddLogJson("\"Cmd\":\""+Cmd+"\""); 

    }
    const char * GetTableName() override
    {
        return "MoneyFlow"; 
    }
    static const char * TableName() 
    {
        return "MoneyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Sequence {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t iMoneyType {0};
    int32_t iMoney {0};
    int32_t AfterMoney {0};
    int32_t AfterBoundMoney {0};
    int32_t AddOrReduce {0};
    std::string serialnum {""};
    int32_t sourceID {0};
    std::string Cmd {""};
    
};
namespace MonthlyCardFlowEnum{

}

class MonthlyCardFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("BuyMonthlyCardBase", ToStringTlog(BuyMonthlyCardBase)); 
        AddLog("BuyMonthlyCardServerLv", ToStringTlog(BuyMonthlyCardServerLv)); 
        AddLog("BuyMonthlyCardTotalNum", ToStringTlog(BuyMonthlyCardTotalNum)); 
        AddLog("BuyMonthlyGiftPackageTotalNum", BuyMonthlyGiftPackageTotalNum); 
        AddLog("ReceiveFreeGiftPackageTotalNum", ToStringTlog(ReceiveFreeGiftPackageTotalNum)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"BuyMonthlyCardBase\":"+ ToStringTlog(BuyMonthlyCardBase)); 
        AddLogJson("\"BuyMonthlyCardServerLv\":"+ ToStringTlog(BuyMonthlyCardServerLv)); 
        AddLogJson("\"BuyMonthlyCardTotalNum\":"+ ToStringTlog(BuyMonthlyCardTotalNum)); 
        AddLogJson("\"BuyMonthlyGiftPackageTotalNum\":\""+BuyMonthlyGiftPackageTotalNum+"\""); 
        AddLogJson("\"ReceiveFreeGiftPackageTotalNum\":"+ ToStringTlog(ReceiveFreeGiftPackageTotalNum)); 

    }
    const char * GetTableName() override
    {
        return "MonthlyCardFlow"; 
    }
    static const char * TableName() 
    {
        return "MonthlyCardFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t BuyMonthlyCardBase {0};
    int32_t BuyMonthlyCardServerLv {0};
    int32_t BuyMonthlyCardTotalNum {0};
    std::string BuyMonthlyGiftPackageTotalNum {""};
    int32_t ReceiveFreeGiftPackageTotalNum {0};
    
};
namespace MVPFlowEnum{

}

class MVPFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MosterID", ToStringTlog(MosterID)); 
        AddLog("MonsterName", MonsterName); 
        AddLog("BeKillTimes", ToStringTlog(BeKillTimes)); 
        AddLog("DeadOrNot", ToStringTlog(DeadOrNot)); 
        AddLog("TeamNum", ToStringTlog(TeamNum)); 
        AddLog("MemberNum", ToStringTlog(MemberNum)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("MaxLv", ToStringTlog(MaxLv)); 
        AddLog("MinLv", ToStringTlog(MinLv)); 
        AddLog("MaxInjury", ToStringTlog(MaxInjury)); 
        AddLog("MaxCure", ToStringTlog(MaxCure)); 
        AddLog("MaxDPS", ToStringTlog(MaxDPS)); 
        AddLog("MinDPS", ToStringTlog(MinDPS)); 
        AddLog("MVPPoint", ToStringTlog(MVPPoint)); 
        AddLog("LastHit", LastHit); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MosterID\":"+ ToStringTlog(MosterID)); 
        AddLogJson("\"MonsterName\":\""+MonsterName+"\""); 
        AddLogJson("\"BeKillTimes\":"+ ToStringTlog(BeKillTimes)); 
        AddLogJson("\"DeadOrNot\":"+ ToStringTlog(DeadOrNot)); 
        AddLogJson("\"TeamNum\":"+ ToStringTlog(TeamNum)); 
        AddLogJson("\"MemberNum\":"+ ToStringTlog(MemberNum)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"MaxLv\":"+ ToStringTlog(MaxLv)); 
        AddLogJson("\"MinLv\":"+ ToStringTlog(MinLv)); 
        AddLogJson("\"MaxInjury\":"+ ToStringTlog(MaxInjury)); 
        AddLogJson("\"MaxCure\":"+ ToStringTlog(MaxCure)); 
        AddLogJson("\"MaxDPS\":"+ ToStringTlog(MaxDPS)); 
        AddLogJson("\"MinDPS\":"+ ToStringTlog(MinDPS)); 
        AddLogJson("\"MVPPoint\":"+ ToStringTlog(MVPPoint)); 
        AddLogJson("\"LastHit\":\""+LastHit+"\""); 

    }
    const char * GetTableName() override
    {
        return "MVPFlow"; 
    }
    static const char * TableName() 
    {
        return "MVPFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MosterID {0};
    std::string MonsterName {""};
    int32_t BeKillTimes {0};
    int32_t DeadOrNot {0};
    int32_t TeamNum {0};
    int32_t MemberNum {0};
    int32_t Time {0};
    int32_t DeadTimes {0};
    int32_t MaxLv {0};
    int32_t MinLv {0};
    int32_t MaxInjury {0};
    int32_t MaxCure {0};
    int32_t MaxDPS {0};
    int32_t MinDPS {0};
    int32_t MVPPoint {0};
    std::string LastHit {""};
    
};
namespace NPCTradeFlowEnum{

    enum class OperateType: uint32_t {
        FORM_NPC = 0,//从NPC购买
        TO_NPC = 1,//卖给NPC 
    };    
}

class NPCTradeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("NPCName", NPCName); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 
        AddLog("GoodsType", ToStringTlog(GoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("SkillDiscountPrice", ToStringTlog(SkillDiscountPrice)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("MoneyCount", ToStringTlog(MoneyCount)); 
        AddLog("GoodsLeave", ToStringTlog(GoodsLeave)); 
        AddLog("ShopID", ToStringTlog(ShopID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"NPCName\":\""+NPCName+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 
        AddLogJson("\"GoodsType\":"+ ToStringTlog(GoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"SkillDiscountPrice\":"+ ToStringTlog(SkillDiscountPrice)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"MoneyCount\":"+ ToStringTlog(MoneyCount)); 
        AddLogJson("\"GoodsLeave\":"+ ToStringTlog(GoodsLeave)); 
        AddLogJson("\"ShopID\":"+ ToStringTlog(ShopID)); 

    }
    const char * GetTableName() override
    {
        return "NPCTradeFlow"; 
    }
    static const char * TableName() 
    {
        return "NPCTradeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string NPCName {""};
    int32_t OperateType {0};
    int64_t TradeID {0};
    int32_t GoodsType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t SkillDiscountPrice {0};
    int32_t GoodsCount {0};
    int32_t MoneyCount {0};
    int32_t GoodsLeave {0};
    int32_t ShopID {0};
    
};
namespace onlinecntEnum{

}

class onlinecnt : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("gameappid", gameappid); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("timekey", timekey); 
        AddLog("gsid", gsid); 
        AddLog("zoneareaid", ToStringTlog(zoneareaid)); 
        AddLog("onlinecntios", ToStringTlog(onlinecntios)); 
        AddLog("onlinecntandroid", ToStringTlog(onlinecntandroid)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"gameappid\":\""+gameappid+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"timekey\":\""+timekey+"\""); 
        AddLogJson("\"gsid\":\""+gsid+"\""); 
        AddLogJson("\"zoneareaid\":"+ ToStringTlog(zoneareaid)); 
        AddLogJson("\"onlinecntios\":"+ ToStringTlog(onlinecntios)); 
        AddLogJson("\"onlinecntandroid\":"+ ToStringTlog(onlinecntandroid)); 

    }
    const char * GetTableName() override
    {
        return "onlinecnt"; 
    }
    static const char * TableName() 
    {
        return "onlinecnt"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string gameappid {""};
    std::string dtEventTime {""};
    std::string timekey {""};
    std::string gsid {""};
    int32_t zoneareaid {0};
    int32_t onlinecntios {0};
    int32_t onlinecntandroid {0};
    
};
namespace OperatingActivityFlowEnum{

}

class OperatingActivityFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ActivityType", ToStringTlog(ActivityType)); 
        AddLog("ActivityID", ToStringTlog(ActivityID)); 
        AddLog("ActivityName", ActivityName); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ActivityType\":"+ ToStringTlog(ActivityType)); 
        AddLogJson("\"ActivityID\":"+ ToStringTlog(ActivityID)); 
        AddLogJson("\"ActivityName\":\""+ActivityName+"\""); 

    }
    const char * GetTableName() override
    {
        return "OperatingActivityFlow"; 
    }
    static const char * TableName() 
    {
        return "OperatingActivityFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ActivityType {0};
    int32_t ActivityID {0};
    std::string ActivityName {""};
    
};
namespace OperatingGiftFlowEnum{

    enum class OperateType: uint32_t {
        PRIZE = 0,//活动赠送
        BUY = 1,//活动购买 
    };    
}

class OperatingGiftFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ActivityType", ToStringTlog(ActivityType)); 
        AddLog("ActivityID", ToStringTlog(ActivityID)); 
        AddLog("ActivityName", ActivityName); 
        AddLog("GiftID", ToStringTlog(GiftID)); 
        AddLog("GiftName", GiftName); 
        AddLog("OperateType", ToStringTlog(OperateType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ActivityType\":"+ ToStringTlog(ActivityType)); 
        AddLogJson("\"ActivityID\":"+ ToStringTlog(ActivityID)); 
        AddLogJson("\"ActivityName\":\""+ActivityName+"\""); 
        AddLogJson("\"GiftID\":"+ ToStringTlog(GiftID)); 
        AddLogJson("\"GiftName\":\""+GiftName+"\""); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 

    }
    const char * GetTableName() override
    {
        return "OperatingGiftFlow"; 
    }
    static const char * TableName() 
    {
        return "OperatingGiftFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ActivityType {0};
    int32_t ActivityID {0};
    std::string ActivityName {""};
    int32_t GiftID {0};
    std::string GiftName {""};
    int32_t OperateType {0};
    
};
namespace OptionsChoiceFlowEnum{

    enum class OptionType: uint32_t {
        DOUBLE = 0,//双操作模式
        WHEEL = 1,//轮盘模式
        P2_5D = 2,//2.5D视角
        P3D = 3,//3D视角 
    };    
}

class OptionsChoiceFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OptionType", ToStringTlog(OptionType)); 
        AddLog("PreChoice", ToStringTlog(PreChoice)); 
        AddLog("AfterChoice", ToStringTlog(AfterChoice)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OptionType\":"+ ToStringTlog(OptionType)); 
        AddLogJson("\"PreChoice\":"+ ToStringTlog(PreChoice)); 
        AddLogJson("\"AfterChoice\":"+ ToStringTlog(AfterChoice)); 

    }
    const char * GetTableName() override
    {
        return "OptionsChoiceFlow"; 
    }
    static const char * TableName() 
    {
        return "OptionsChoiceFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OptionType {0};
    int32_t PreChoice {0};
    int32_t AfterChoice {0};
    
};
namespace PhotoFlowEnum{

    enum class OperateType: uint32_t {
        KNORMAL = 0,//普通
        KFREEDOM = 1,//自由
        KSELFIESTICK = 2,//自拍
        KAR = 3,//AR 
    };    
    enum class Result: uint32_t {
        KNONE = 0,//未保存
        KLOCAL = 1,//保存本地
        KGAME = 2,//保存游戏
        KALL = 3,//双向保存 
    };    
}

class PhotoFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("MapName", MapName); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("StickerID", StickerID); 
        AddLog("FrameID", ToStringTlog(FrameID)); 
        AddLog("EmojiID", ToStringTlog(EmojiID)); 
        AddLog("Message", Message); 
        AddLog("ActionID", ToStringTlog(ActionID)); 
        AddLog("Result", ToStringTlog(Result)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"MapName\":\""+MapName+"\""); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"StickerID\":\""+StickerID+"\""); 
        AddLogJson("\"FrameID\":"+ ToStringTlog(FrameID)); 
        AddLogJson("\"EmojiID\":"+ ToStringTlog(EmojiID)); 
        AddLogJson("\"Message\":\""+Message+"\""); 
        AddLogJson("\"ActionID\":"+ ToStringTlog(ActionID)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 

    }
    const char * GetTableName() override
    {
        return "PhotoFlow"; 
    }
    static const char * TableName() 
    {
        return "PhotoFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MapID {0};
    std::string MapName {""};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    std::string StickerID {""};
    int32_t FrameID {0};
    int32_t EmojiID {0};
    std::string Message {""};
    int32_t ActionID {0};
    int32_t Result {0};
    
};
namespace PitchFlowEnum{

    enum class Operate: uint32_t {
        UP = 0,//上架
        DOWM = 1,//下架
        RAPID_UP = 2,//快速上架
        RAPID_DOWN = 3,//快速下架 
    };    
}

class PitchFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Operate", ToStringTlog(Operate)); 
        AddLog("GoodsType", ToStringTlog(GoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("ProPrice", ToStringTlog(ProPrice)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("GoodsLeave", ToStringTlog(GoodsLeave)); 
        AddLog("Fee", ToStringTlog(Fee)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Operate\":"+ ToStringTlog(Operate)); 
        AddLogJson("\"GoodsType\":"+ ToStringTlog(GoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"ProPrice\":"+ ToStringTlog(ProPrice)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"GoodsLeave\":"+ ToStringTlog(GoodsLeave)); 
        AddLogJson("\"Fee\":"+ ToStringTlog(Fee)); 

    }
    const char * GetTableName() override
    {
        return "PitchFlow"; 
    }
    static const char * TableName() 
    {
        return "PitchFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Operate {0};
    int32_t GoodsType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t ProPrice {0};
    int32_t GoodsCount {0};
    int32_t GoodsLeave {0};
    int32_t Fee {0};
    
};
namespace PitchTakeFlowEnum{

    enum class OperateType: uint32_t {
        BUYER = 0,//买家
        SELLER = 1,//卖家 
    };    
}

class PitchTakeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("GoodsType", ToStringTlog(GoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("ProPrice", ToStringTlog(ProPrice)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("SellTime", ToStringTlog(SellTime)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TradeID", TradeID); 
        AddLog("iopenidID", iopenidID); 
        AddLog("iRoleId", iRoleId); 
        AddLog("iRoleName", iRoleName); 
        AddLog("iLevel", ToStringTlog(iLevel)); 
        AddLog("vJobLevel", ToStringTlog(vJobLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"GoodsType\":"+ ToStringTlog(GoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"ProPrice\":"+ ToStringTlog(ProPrice)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"SellTime\":"+ ToStringTlog(SellTime)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TradeID\":\""+TradeID+"\""); 
        AddLogJson("\"iopenidID\":\""+iopenidID+"\""); 
        AddLogJson("\"iRoleId\":\""+iRoleId+"\""); 
        AddLogJson("\"iRoleName\":\""+iRoleName+"\""); 
        AddLogJson("\"iLevel\":"+ ToStringTlog(iLevel)); 
        AddLogJson("\"vJobLevel\":"+ ToStringTlog(vJobLevel)); 

    }
    const char * GetTableName() override
    {
        return "PitchTakeFlow"; 
    }
    static const char * TableName() 
    {
        return "PitchTakeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t GoodsType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t ProPrice {0};
    int32_t GoodsCount {0};
    int32_t SellTime {0};
    int32_t OperateType {0};
    std::string TradeID {""};
    std::string iopenidID {""};
    std::string iRoleId {""};
    std::string iRoleName {""};
    int32_t iLevel {0};
    int32_t vJobLevel {0};
    
};
namespace PlayerDeadFlowEnum{

    enum class DeadType: uint32_t {
        BY_PALYER = 0,//玩家击杀
        BY_MONSTER = 1,//怪物击杀 
    };    
}

class PlayerDeadFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("DeadType", ToStringTlog(DeadType)); 
        AddLog("BossID", ToStringTlog(BossID)); 
        AddLog("BossLevel", ToStringTlog(BossLevel)); 
        AddLog("kRoleid", ToStringTlog(kRoleid)); 
        AddLog("ActivityType", ToStringTlog(ActivityType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"DeadType\":"+ ToStringTlog(DeadType)); 
        AddLogJson("\"BossID\":"+ ToStringTlog(BossID)); 
        AddLogJson("\"BossLevel\":"+ ToStringTlog(BossLevel)); 
        AddLogJson("\"kRoleid\":"+ ToStringTlog(kRoleid)); 
        AddLogJson("\"ActivityType\":"+ ToStringTlog(ActivityType)); 

    }
    const char * GetTableName() override
    {
        return "PlayerDeadFlow"; 
    }
    static const char * TableName() 
    {
        return "PlayerDeadFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    int32_t DeadType {0};
    int32_t BossID {0};
    int32_t BossLevel {0};
    int32_t kRoleid {0};
    int32_t ActivityType {0};
    
};
namespace PlayerFriendsListEnum{

}

class PlayerFriendsList : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vroleid", vroleid); 
        AddLog("vRoleName", vRoleName); 
        AddLog("iJobId", ToStringTlog(iJobId)); 
        AddLog("iHeadId", ToStringTlog(iHeadId)); 
        AddLog("vFriendsList", vFriendsList); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vroleid\":\""+vroleid+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"iJobId\":"+ ToStringTlog(iJobId)); 
        AddLogJson("\"iHeadId\":"+ ToStringTlog(iHeadId)); 
        AddLogJson("\"vFriendsList\":\""+vFriendsList+"\""); 

    }
    const char * GetTableName() override
    {
        return "PlayerFriendsList"; 
    }
    static const char * TableName() 
    {
        return "PlayerFriendsList"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vroleid {""};
    std::string vRoleName {""};
    int32_t iJobId {0};
    int32_t iHeadId {0};
    std::string vFriendsList {""};
    
};
namespace PlayerLoginEnum{

    enum class LoginType: uint32_t {
        NORMAL = 0,//正常登录
        RECONECT = 1,//断线重连 
    };    
}

class PlayerLogin : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("LoginType", ToStringTlog(LoginType)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("SystemSoftware", SystemSoftware); 
        AddLog("SystemHardware", SystemHardware); 
        AddLog("TelecomOper", TelecomOper); 
        AddLog("Network", Network); 
        AddLog("ScreenWidth", ToStringTlog(ScreenWidth)); 
        AddLog("ScreenHight", ToStringTlog(ScreenHight)); 
        AddLog("Density", ToStringTlog(Density)); 
        AddLog("CpuHardware", CpuHardware); 
        AddLog("Memory", ToStringTlog(Memory)); 
        AddLog("GLRender", GLRender); 
        AddLog("GLVersion", GLVersion); 
        AddLog("DeviceId", DeviceId); 
        AddLog("vClientIp", vClientIp); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"LoginType\":"+ ToStringTlog(LoginType)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"SystemSoftware\":\""+SystemSoftware+"\""); 
        AddLogJson("\"SystemHardware\":\""+SystemHardware+"\""); 
        AddLogJson("\"TelecomOper\":\""+TelecomOper+"\""); 
        AddLogJson("\"Network\":\""+Network+"\""); 
        AddLogJson("\"ScreenWidth\":"+ ToStringTlog(ScreenWidth)); 
        AddLogJson("\"ScreenHight\":"+ ToStringTlog(ScreenHight)); 
        AddLogJson("\"Density\":"+ ToStringTlog(Density)); 
        AddLogJson("\"CpuHardware\":\""+CpuHardware+"\""); 
        AddLogJson("\"Memory\":"+ ToStringTlog(Memory)); 
        AddLogJson("\"GLRender\":\""+GLRender+"\""); 
        AddLogJson("\"GLVersion\":\""+GLVersion+"\""); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"vClientIp\":\""+vClientIp+"\""); 

    }
    const char * GetTableName() override
    {
        return "PlayerLogin"; 
    }
    static const char * TableName() 
    {
        return "PlayerLogin"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t LoginType {0};
    std::string ClientVersion {""};
    std::string SystemSoftware {""};
    std::string SystemHardware {""};
    std::string TelecomOper {""};
    std::string Network {""};
    int32_t ScreenWidth {0};
    int32_t ScreenHight {0};
    float Density {0};
    std::string CpuHardware {""};
    int32_t Memory {0};
    std::string GLRender {""};
    std::string GLVersion {""};
    std::string DeviceId {""};
    std::string vClientIp {""};
    
};
namespace PlayerLogoutEnum{

    enum class LogoutType: uint32_t {
        NORMAL = 0,//正常登出
        KICKOUT = 1,//被踢下线 
    };    
}

class PlayerLogout : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("LogoutType", ToStringTlog(LogoutType)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("SystemSoftware", SystemSoftware); 
        AddLog("SystemHardware", SystemHardware); 
        AddLog("TelecomOper", TelecomOper); 
        AddLog("Network", Network); 
        AddLog("ScreenWidth", ToStringTlog(ScreenWidth)); 
        AddLog("ScreenHight", ToStringTlog(ScreenHight)); 
        AddLog("Density", ToStringTlog(Density)); 
        AddLog("CpuHardware", CpuHardware); 
        AddLog("Memory", ToStringTlog(Memory)); 
        AddLog("GLRender", GLRender); 
        AddLog("GLVersion", GLVersion); 
        AddLog("DeviceId", DeviceId); 
        AddLog("vClientIp", vClientIp); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"LogoutType\":"+ ToStringTlog(LogoutType)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"SystemSoftware\":\""+SystemSoftware+"\""); 
        AddLogJson("\"SystemHardware\":\""+SystemHardware+"\""); 
        AddLogJson("\"TelecomOper\":\""+TelecomOper+"\""); 
        AddLogJson("\"Network\":\""+Network+"\""); 
        AddLogJson("\"ScreenWidth\":"+ ToStringTlog(ScreenWidth)); 
        AddLogJson("\"ScreenHight\":"+ ToStringTlog(ScreenHight)); 
        AddLogJson("\"Density\":"+ ToStringTlog(Density)); 
        AddLogJson("\"CpuHardware\":\""+CpuHardware+"\""); 
        AddLogJson("\"Memory\":"+ ToStringTlog(Memory)); 
        AddLogJson("\"GLRender\":\""+GLRender+"\""); 
        AddLogJson("\"GLVersion\":\""+GLVersion+"\""); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"vClientIp\":\""+vClientIp+"\""); 

    }
    const char * GetTableName() override
    {
        return "PlayerLogout"; 
    }
    static const char * TableName() 
    {
        return "PlayerLogout"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t LogoutType {0};
    std::string ClientVersion {""};
    std::string SystemSoftware {""};
    std::string SystemHardware {""};
    std::string TelecomOper {""};
    std::string Network {""};
    int32_t ScreenWidth {0};
    int32_t ScreenHight {0};
    float Density {0};
    std::string CpuHardware {""};
    int32_t Memory {0};
    std::string GLRender {""};
    std::string GLVersion {""};
    std::string DeviceId {""};
    std::string vClientIp {""};
    
};
namespace PlayerMedalFlowEnum{

}

class PlayerMedalFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MedalType", ToStringTlog(MedalType)); 
        AddLog("MedalID", ToStringTlog(MedalID)); 
        AddLog("MedalName", MedalName); 
        AddLog("PreLevel", ToStringTlog(PreLevel)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 
        AddLog("PreStage", ToStringTlog(PreStage)); 
        AddLog("AfterStage", ToStringTlog(AfterStage)); 
        AddLog("CostFame", ToStringTlog(CostFame)); 
        AddLog("CostItem", CostItem); 
        AddLog("CostItemName", CostItemName); 
        AddLog("CostCount", ToStringTlog(CostCount)); 
        AddLog("PrestigeNum", ToStringTlog(PrestigeNum)); 
        AddLog("AllMedalLv", AllMedalLv); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MedalType\":"+ ToStringTlog(MedalType)); 
        AddLogJson("\"MedalID\":"+ ToStringTlog(MedalID)); 
        AddLogJson("\"MedalName\":\""+MedalName+"\""); 
        AddLogJson("\"PreLevel\":"+ ToStringTlog(PreLevel)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 
        AddLogJson("\"PreStage\":"+ ToStringTlog(PreStage)); 
        AddLogJson("\"AfterStage\":"+ ToStringTlog(AfterStage)); 
        AddLogJson("\"CostFame\":"+ ToStringTlog(CostFame)); 
        AddLogJson("\"CostItem\":\""+CostItem+"\""); 
        AddLogJson("\"CostItemName\":\""+CostItemName+"\""); 
        AddLogJson("\"CostCount\":"+ ToStringTlog(CostCount)); 
        AddLogJson("\"PrestigeNum\":"+ ToStringTlog(PrestigeNum)); 
        AddLogJson("\"AllMedalLv\":\""+AllMedalLv+"\""); 

    }
    const char * GetTableName() override
    {
        return "PlayerMedalFlow"; 
    }
    static const char * TableName() 
    {
        return "PlayerMedalFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t MedalType {0};
    int32_t MedalID {0};
    std::string MedalName {""};
    int32_t PreLevel {0};
    int32_t AfterLevel {0};
    int32_t PreStage {0};
    int32_t AfterStage {0};
    int32_t CostFame {0};
    std::string CostItem {""};
    std::string CostItemName {""};
    int32_t CostCount {0};
    int32_t PrestigeNum {0};
    std::string AllMedalLv {""};
    
};
namespace PlayerRegisterEnum{

    enum class Result: uint32_t {
        SUCCESS = 0,//成功
        FAILED = 1,//失败 
    };    
}

class PlayerRegister : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("iLevel", ToStringTlog(iLevel)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("SystemSoftware", SystemSoftware); 
        AddLog("SystemHardware", SystemHardware); 
        AddLog("TelecomOper", TelecomOper); 
        AddLog("Network", Network); 
        AddLog("ScreenWidth", ToStringTlog(ScreenWidth)); 
        AddLog("ScreenHight", ToStringTlog(ScreenHight)); 
        AddLog("Density", ToStringTlog(Density)); 
        AddLog("CpuHardware", CpuHardware); 
        AddLog("Memory", ToStringTlog(Memory)); 
        AddLog("GLRender", GLRender); 
        AddLog("GLVersion", GLVersion); 
        AddLog("DeviceId", DeviceId); 
        AddLog("vClientIp", vClientIp); 
        AddLog("Result", ToStringTlog(Result)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"iLevel\":"+ ToStringTlog(iLevel)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"SystemSoftware\":\""+SystemSoftware+"\""); 
        AddLogJson("\"SystemHardware\":\""+SystemHardware+"\""); 
        AddLogJson("\"TelecomOper\":\""+TelecomOper+"\""); 
        AddLogJson("\"Network\":\""+Network+"\""); 
        AddLogJson("\"ScreenWidth\":"+ ToStringTlog(ScreenWidth)); 
        AddLogJson("\"ScreenHight\":"+ ToStringTlog(ScreenHight)); 
        AddLogJson("\"Density\":"+ ToStringTlog(Density)); 
        AddLogJson("\"CpuHardware\":\""+CpuHardware+"\""); 
        AddLogJson("\"Memory\":"+ ToStringTlog(Memory)); 
        AddLogJson("\"GLRender\":\""+GLRender+"\""); 
        AddLogJson("\"GLVersion\":\""+GLVersion+"\""); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"vClientIp\":\""+vClientIp+"\""); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 

    }
    const char * GetTableName() override
    {
        return "PlayerRegister"; 
    }
    static const char * TableName() 
    {
        return "PlayerRegister"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t iLevel {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    int32_t RegChannel {0};
    int32_t LoginChannel {0};
    std::string ClientVersion {""};
    std::string SystemSoftware {""};
    std::string SystemHardware {""};
    std::string TelecomOper {""};
    std::string Network {""};
    int32_t ScreenWidth {0};
    int32_t ScreenHight {0};
    float Density {0};
    std::string CpuHardware {""};
    int32_t Memory {0};
    std::string GLRender {""};
    std::string GLVersion {""};
    std::string DeviceId {""};
    std::string vClientIp {""};
    int32_t Result {0};
    
};
namespace PlayerReviveFlowEnum{

}

class PlayerReviveFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("ReviveType", ToStringTlog(ReviveType)); 
        AddLog("rRoleid", ToStringTlog(rRoleid)); 
        AddLog("ActivityType", ToStringTlog(ActivityType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"ReviveType\":"+ ToStringTlog(ReviveType)); 
        AddLogJson("\"rRoleid\":"+ ToStringTlog(rRoleid)); 
        AddLogJson("\"ActivityType\":"+ ToStringTlog(ActivityType)); 

    }
    const char * GetTableName() override
    {
        return "PlayerReviveFlow"; 
    }
    static const char * TableName() 
    {
        return "PlayerReviveFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    int32_t ReviveType {0};
    int32_t rRoleid {0};
    int32_t ActivityType {0};
    
};
namespace PlayerTrueLoginoutEnum{

    enum class LoginType: uint32_t {
        NORMAL = 0,//正常登录
        RECONECT = 1,//断线重连 
    };    
    enum class LogoutType: uint32_t {
        NORMAL = 0,//正常登出
        KICKOUT = 1,//被踢下线 
    };    
}

class PlayerTrueLoginout : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("CreateTime", CreateTime); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("LoginType", ToStringTlog(LoginType)); 
        AddLog("LogoutType", ToStringTlog(LogoutType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("SystemSoftware", SystemSoftware); 
        AddLog("SystemHardware", SystemHardware); 
        AddLog("TelecomOper", TelecomOper); 
        AddLog("Network", Network); 
        AddLog("ScreenWidth", ToStringTlog(ScreenWidth)); 
        AddLog("ScreenHight", ToStringTlog(ScreenHight)); 
        AddLog("Density", ToStringTlog(Density)); 
        AddLog("CpuHardware", CpuHardware); 
        AddLog("Memory", ToStringTlog(Memory)); 
        AddLog("GLRender", GLRender); 
        AddLog("GLVersion", GLVersion); 
        AddLog("DeviceId", DeviceId); 
        AddLog("vClientIp", vClientIp); 
        AddLog("TotalTime", ToStringTlog(TotalTime)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"LoginType\":"+ ToStringTlog(LoginType)); 
        AddLogJson("\"LogoutType\":"+ ToStringTlog(LogoutType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"SystemSoftware\":\""+SystemSoftware+"\""); 
        AddLogJson("\"SystemHardware\":\""+SystemHardware+"\""); 
        AddLogJson("\"TelecomOper\":\""+TelecomOper+"\""); 
        AddLogJson("\"Network\":\""+Network+"\""); 
        AddLogJson("\"ScreenWidth\":"+ ToStringTlog(ScreenWidth)); 
        AddLogJson("\"ScreenHight\":"+ ToStringTlog(ScreenHight)); 
        AddLogJson("\"Density\":"+ ToStringTlog(Density)); 
        AddLogJson("\"CpuHardware\":\""+CpuHardware+"\""); 
        AddLogJson("\"Memory\":"+ ToStringTlog(Memory)); 
        AddLogJson("\"GLRender\":\""+GLRender+"\""); 
        AddLogJson("\"GLVersion\":\""+GLVersion+"\""); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"vClientIp\":\""+vClientIp+"\""); 
        AddLogJson("\"TotalTime\":"+ ToStringTlog(TotalTime)); 

    }
    const char * GetTableName() override
    {
        return "PlayerTrueLoginout"; 
    }
    static const char * TableName() 
    {
        return "PlayerTrueLoginout"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string CreateTime {""};
    int32_t RegChannel {0};
    int32_t LoginChannel {0};
    int32_t LoginType {0};
    int32_t LogoutType {0};
    int32_t OperateType {0};
    std::string ClientVersion {""};
    std::string SystemSoftware {""};
    std::string SystemHardware {""};
    std::string TelecomOper {""};
    std::string Network {""};
    int32_t ScreenWidth {0};
    int32_t ScreenHight {0};
    float Density {0};
    std::string CpuHardware {""};
    int32_t Memory {0};
    std::string GLRender {""};
    std::string GLVersion {""};
    std::string DeviceId {""};
    std::string vClientIp {""};
    int32_t TotalTime {0};
    
};
namespace PlayerWeightFlowEnum{

}

class PlayerWeightFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("WeightType", ToStringTlog(WeightType)); 
        AddLog("PreWeight", ToStringTlog(PreWeight)); 
        AddLog("AfterWeight", ToStringTlog(AfterWeight)); 
        AddLog("PreAllWeight", ToStringTlog(PreAllWeight)); 
        AddLog("AfterAllWeight", ToStringTlog(AfterAllWeight)); 
        AddLog("PreWeightMax", ToStringTlog(PreWeightMax)); 
        AddLog("AfterWeightMax", ToStringTlog(AfterWeightMax)); 
        AddLog("IsOverLoad", ToStringTlog(IsOverLoad)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("PreGymStamp", ToStringTlog(PreGymStamp)); 
        AddLog("AfterGymStamp", ToStringTlog(AfterGymStamp)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"WeightType\":"+ ToStringTlog(WeightType)); 
        AddLogJson("\"PreWeight\":"+ ToStringTlog(PreWeight)); 
        AddLogJson("\"AfterWeight\":"+ ToStringTlog(AfterWeight)); 
        AddLogJson("\"PreAllWeight\":"+ ToStringTlog(PreAllWeight)); 
        AddLogJson("\"AfterAllWeight\":"+ ToStringTlog(AfterAllWeight)); 
        AddLogJson("\"PreWeightMax\":"+ ToStringTlog(PreWeightMax)); 
        AddLogJson("\"AfterWeightMax\":"+ ToStringTlog(AfterWeightMax)); 
        AddLogJson("\"IsOverLoad\":"+ ToStringTlog(IsOverLoad)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"PreGymStamp\":"+ ToStringTlog(PreGymStamp)); 
        AddLogJson("\"AfterGymStamp\":"+ ToStringTlog(AfterGymStamp)); 

    }
    const char * GetTableName() override
    {
        return "PlayerWeightFlow"; 
    }
    static const char * TableName() 
    {
        return "PlayerWeightFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t AddOrReduce {0};
    int32_t WeightType {0};
    int32_t PreWeight {0};
    int32_t AfterWeight {0};
    int32_t PreAllWeight {0};
    int32_t AfterAllWeight {0};
    int32_t PreWeightMax {0};
    int32_t AfterWeightMax {0};
    int32_t IsOverLoad {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t PreGymStamp {0};
    int32_t AfterGymStamp {0};
    
};
namespace PoringClubFlowEnum{

}

class PoringClubFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PoringID", ToStringTlog(PoringID)); 
        AddLog("PoringName", PoringName); 
        AddLog("FindType", ToStringTlog(FindType)); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("MoneyAmount", ToStringTlog(MoneyAmount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PoringID\":"+ ToStringTlog(PoringID)); 
        AddLogJson("\"PoringName\":\""+PoringName+"\""); 
        AddLogJson("\"FindType\":"+ ToStringTlog(FindType)); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"MoneyAmount\":"+ ToStringTlog(MoneyAmount)); 

    }
    const char * GetTableName() override
    {
        return "PoringClubFlow"; 
    }
    static const char * TableName() 
    {
        return "PoringClubFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PoringID {0};
    std::string PoringName {""};
    int32_t FindType {0};
    int32_t MoneyType {0};
    int32_t MoneyAmount {0};
    
};
namespace PowerSavingFlowEnum{

    enum class PowerSavingType: uint32_t {
        ENTER_SAVEPOWER = 0,//进入节电模式
        LEAVE_SAVEPOWER = 1,//退出节电模式 
    };    
}

class PowerSavingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PowerSavingType", ToStringTlog(PowerSavingType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PowerSavingType\":"+ ToStringTlog(PowerSavingType)); 

    }
    const char * GetTableName() override
    {
        return "PowerSavingFlow"; 
    }
    static const char * TableName() 
    {
        return "PowerSavingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PowerSavingType {0};
    
};
namespace PresentedFlowEnum{

}

class PresentedFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("rRoleId", rRoleId); 
        AddLog("rRoleName", rRoleName); 
        AddLog("rJobId", ToStringTlog(rJobId)); 
        AddLog("rGender", ToStringTlog(rGender)); 
        AddLog("rLevel", ToStringTlog(rLevel)); 
        AddLog("rJobLevel", ToStringTlog(rJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("Items", Items); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"rRoleId\":\""+rRoleId+"\""); 
        AddLogJson("\"rRoleName\":\""+rRoleName+"\""); 
        AddLogJson("\"rJobId\":"+ ToStringTlog(rJobId)); 
        AddLogJson("\"rGender\":"+ ToStringTlog(rGender)); 
        AddLogJson("\"rLevel\":"+ ToStringTlog(rLevel)); 
        AddLogJson("\"rJobLevel\":"+ ToStringTlog(rJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"Items\":\""+Items+"\""); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 

    }
    const char * GetTableName() override
    {
        return "PresentedFlow"; 
    }
    static const char * TableName() 
    {
        return "PresentedFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string rRoleId {""};
    std::string rRoleName {""};
    int32_t rJobId {0};
    int32_t rGender {0};
    int32_t rLevel {0};
    int32_t rJobLevel {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    std::string Items {""};
    int32_t FriendPoints {0};
    
};
namespace PVEChallengeFlowEnum{

}

class PVEChallengeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("LeveID", ToStringTlog(LeveID)); 
        AddLog("LevelName", LevelName); 
        AddLog("LevelStar", ToStringTlog(LevelStar)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("DeadCount", ToStringTlog(DeadCount)); 
        AddLog("bReviveCount", ToStringTlog(bReviveCount)); 
        AddLog("ReviveCount", ToStringTlog(ReviveCount)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("Rank", ToStringTlog(Rank)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"LeveID\":"+ ToStringTlog(LeveID)); 
        AddLogJson("\"LevelName\":\""+LevelName+"\""); 
        AddLogJson("\"LevelStar\":"+ ToStringTlog(LevelStar)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"DeadCount\":"+ ToStringTlog(DeadCount)); 
        AddLogJson("\"bReviveCount\":"+ ToStringTlog(bReviveCount)); 
        AddLogJson("\"ReviveCount\":"+ ToStringTlog(ReviveCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"Rank\":"+ ToStringTlog(Rank)); 

    }
    const char * GetTableName() override
    {
        return "PVEChallengeFlow"; 
    }
    static const char * TableName() 
    {
        return "PVEChallengeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamID {0};
    int32_t LeveID {0};
    std::string LevelName {""};
    int32_t LevelStar {0};
    int32_t Result {0};
    int32_t DeadCount {0};
    int32_t bReviveCount {0};
    int32_t ReviveCount {0};
    int32_t Score {0};
    int32_t Rank {0};
    
};
namespace PVPApplyFlowEnum{

    enum class ApplyType: uint32_t {
        APPLY_SINGLE = 0,//单人报名
        APPLY_DOUBLE = 1,//双人队报名
        APPLY_TRIPLE = 2,//三人队报名 
    };    
}

class PVPApplyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ApplyType", ToStringTlog(ApplyType)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ApplyType\":"+ ToStringTlog(ApplyType)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 

    }
    const char * GetTableName() override
    {
        return "PVPApplyFlow"; 
    }
    static const char * TableName() 
    {
        return "PVPApplyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ApplyType {0};
    int32_t InterValue {0};
    
};
namespace PVPDetailFlowEnum{

}

class PVPDetailFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("PVPType", ToStringTlog(PVPType)); 
        AddLog("KillTimes", ToStringTlog(KillTimes)); 
        AddLog("KillMaxCombo", ToStringTlog(KillMaxCombo)); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("HelpTimes", ToStringTlog(HelpTimes)); 
        AddLog("EndCombo", ToStringTlog(EndCombo)); 
        AddLog("EndMaxCombo", ToStringTlog(EndMaxCombo)); 
        AddLog("ReviveTimes", ToStringTlog(ReviveTimes)); 
        AddLog("RevivedTimes", ToStringTlog(RevivedTimes)); 
        AddLog("ItemReviedTimes", ToStringTlog(ItemReviedTimes)); 
        AddLog("PVPDamage", ToStringTlog(PVPDamage)); 
        AddLog("PVEDamage", ToStringTlog(PVEDamage)); 
        AddLog("PVPDamaged", ToStringTlog(PVPDamaged)); 
        AddLog("PVEDamaged", ToStringTlog(PVEDamaged)); 
        AddLog("PVPHeal", ToStringTlog(PVPHeal)); 
        AddLog("PVPHealed", ToStringTlog(PVPHealed)); 
        AddLog("ItemHeal", ToStringTlog(ItemHeal)); 
        AddLog("OccupyCount", ToStringTlog(OccupyCount)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("MVP", ToStringTlog(MVP)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"PVPType\":"+ ToStringTlog(PVPType)); 
        AddLogJson("\"KillTimes\":"+ ToStringTlog(KillTimes)); 
        AddLogJson("\"KillMaxCombo\":"+ ToStringTlog(KillMaxCombo)); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"HelpTimes\":"+ ToStringTlog(HelpTimes)); 
        AddLogJson("\"EndCombo\":"+ ToStringTlog(EndCombo)); 
        AddLogJson("\"EndMaxCombo\":"+ ToStringTlog(EndMaxCombo)); 
        AddLogJson("\"ReviveTimes\":"+ ToStringTlog(ReviveTimes)); 
        AddLogJson("\"RevivedTimes\":"+ ToStringTlog(RevivedTimes)); 
        AddLogJson("\"ItemReviedTimes\":"+ ToStringTlog(ItemReviedTimes)); 
        AddLogJson("\"PVPDamage\":"+ ToStringTlog(PVPDamage)); 
        AddLogJson("\"PVEDamage\":"+ ToStringTlog(PVEDamage)); 
        AddLogJson("\"PVPDamaged\":"+ ToStringTlog(PVPDamaged)); 
        AddLogJson("\"PVEDamaged\":"+ ToStringTlog(PVEDamaged)); 
        AddLogJson("\"PVPHeal\":"+ ToStringTlog(PVPHeal)); 
        AddLogJson("\"PVPHealed\":"+ ToStringTlog(PVPHealed)); 
        AddLogJson("\"ItemHeal\":"+ ToStringTlog(ItemHeal)); 
        AddLogJson("\"OccupyCount\":"+ ToStringTlog(OccupyCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"MVP\":"+ ToStringTlog(MVP)); 

    }
    const char * GetTableName() override
    {
        return "PVPDetailFlow"; 
    }
    static const char * TableName() 
    {
        return "PVPDetailFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamID {0};
    int32_t PVPType {0};
    int32_t KillTimes {0};
    int32_t KillMaxCombo {0};
    int32_t DeadTimes {0};
    int32_t HelpTimes {0};
    int32_t EndCombo {0};
    int32_t EndMaxCombo {0};
    int32_t ReviveTimes {0};
    int32_t RevivedTimes {0};
    int32_t ItemReviedTimes {0};
    int32_t PVPDamage {0};
    int32_t PVEDamage {0};
    int32_t PVPDamaged {0};
    int32_t PVEDamaged {0};
    int32_t PVPHeal {0};
    int32_t PVPHealed {0};
    int32_t ItemHeal {0};
    int32_t OccupyCount {0};
    int32_t Score {0};
    int32_t MVP {0};
    
};
namespace PVPResultFlowEnum{

    enum class mTeamType: uint32_t {
        TEAM_LOCAL = 0,//本服玩家
        TEAM_CROSS = 1,//跨服玩家
        TEAM_BOT = 2,//机器人 
    };    
    enum class Result: uint32_t {
        WIN = 0,//胜
        DRAW = 1,//平
        FAIL = 2,//负 
    };    
}

class PVPResultFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MatchID", ToStringTlog(MatchID)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("mTeamType", ToStringTlog(mTeamType)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("TeamInfo", TeamInfo); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("PreFloor", ToStringTlog(PreFloor)); 
        AddLog("AfterFloor", ToStringTlog(AfterFloor)); 
        AddLog("DeadCount", ToStringTlog(DeadCount)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("MVP", ToStringTlog(MVP)); 
        AddLog("Time", ToStringTlog(Time)); 
        AddLog("CampPoints", ToStringTlog(CampPoints)); 
        AddLog("Round", ToStringTlog(Round)); 
        AddLog("PVPMedal", ToStringTlog(PVPMedal)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MatchID\":"+ ToStringTlog(MatchID)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"mTeamType\":"+ ToStringTlog(mTeamType)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"TeamInfo\":\""+TeamInfo+"\""); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"PreFloor\":"+ ToStringTlog(PreFloor)); 
        AddLogJson("\"AfterFloor\":"+ ToStringTlog(AfterFloor)); 
        AddLogJson("\"DeadCount\":"+ ToStringTlog(DeadCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"MVP\":"+ ToStringTlog(MVP)); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 
        AddLogJson("\"CampPoints\":"+ ToStringTlog(CampPoints)); 
        AddLogJson("\"Round\":"+ ToStringTlog(Round)); 
        AddLogJson("\"PVPMedal\":"+ ToStringTlog(PVPMedal)); 

    }
    const char * GetTableName() override
    {
        return "PVPResultFlow"; 
    }
    static const char * TableName() 
    {
        return "PVPResultFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MatchID {0};
    int32_t TeamID {0};
    int32_t mTeamType {0};
    int32_t InterValue {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    std::string TeamInfo {""};
    int32_t Result {0};
    int32_t PreFloor {0};
    int32_t AfterFloor {0};
    int32_t DeadCount {0};
    int32_t Score {0};
    int32_t MVP {0};
    int32_t Time {0};
    int32_t CampPoints {0};
    int32_t Round {0};
    int32_t PVPMedal {0};
    
};
namespace RealProfitFlowEnum{

}

class RealProfitFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("Awardid", ToStringTlog(Awardid)); 
        AddLog("Packid", ToStringTlog(Packid)); 
        AddLog("ItemList", ItemList); 
        AddLog("CurrentChange", ToStringTlog(CurrentChange)); 
        AddLog("DailyProfit", ToStringTlog(DailyProfit)); 
        AddLog("HistoryProfit", ToStringTlog(HistoryProfit)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"Awardid\":"+ ToStringTlog(Awardid)); 
        AddLogJson("\"Packid\":"+ ToStringTlog(Packid)); 
        AddLogJson("\"ItemList\":\""+ItemList+"\""); 
        AddLogJson("\"CurrentChange\":"+ ToStringTlog(CurrentChange)); 
        AddLogJson("\"DailyProfit\":"+ ToStringTlog(DailyProfit)); 
        AddLogJson("\"HistoryProfit\":"+ ToStringTlog(HistoryProfit)); 

    }
    const char * GetTableName() override
    {
        return "RealProfitFlow"; 
    }
    static const char * TableName() 
    {
        return "RealProfitFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Reason {0};
    int32_t Awardid {0};
    int32_t Packid {0};
    std::string ItemList {""};
    float CurrentChange {0};
    int32_t DailyProfit {0};
    int32_t HistoryProfit {0};
    
};
namespace RechargeEnum{

}

class Recharge : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("vopenid", vopenid); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("IP", ToStringTlog(IP)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("iSourceWay", ToStringTlog(iSourceWay)); 
        AddLog("iDelta", ToStringTlog(iDelta)); 
        AddLog("iRechargeAfter", ToStringTlog(iRechargeAfter)); 
        AddLog("iRechargeTotal", ToStringTlog(iRechargeTotal)); 
        AddLog("iLoginWay", iLoginWay); 
        AddLog("iRegWay", iRegWay); 
        AddLog("CIP", CIP); 
        AddLog("iRechargeType", ToStringTlog(iRechargeType)); 
        AddLog("TradeID", TradeID); 
        AddLog("GiftID", ToStringTlog(GiftID)); 
        AddLog("ItemList", ItemList); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"IP\":"+ ToStringTlog(IP)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"iSourceWay\":"+ ToStringTlog(iSourceWay)); 
        AddLogJson("\"iDelta\":"+ ToStringTlog(iDelta)); 
        AddLogJson("\"iRechargeAfter\":"+ ToStringTlog(iRechargeAfter)); 
        AddLogJson("\"iRechargeTotal\":"+ ToStringTlog(iRechargeTotal)); 
        AddLogJson("\"iLoginWay\":\""+iLoginWay+"\""); 
        AddLogJson("\"iRegWay\":\""+iRegWay+"\""); 
        AddLogJson("\"CIP\":\""+CIP+"\""); 
        AddLogJson("\"iRechargeType\":"+ ToStringTlog(iRechargeType)); 
        AddLogJson("\"TradeID\":\""+TradeID+"\""); 
        AddLogJson("\"GiftID\":"+ ToStringTlog(GiftID)); 
        AddLogJson("\"ItemList\":\""+ItemList+"\""); 

    }
    const char * GetTableName() override
    {
        return "Recharge"; 
    }
    static const char * TableName() 
    {
        return "Recharge"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    std::string vopenid {""};
    int32_t iZoneAreaID {0};
    int32_t PlatID {0};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t IP {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t iSourceWay {0};
    int32_t iDelta {0};
    int32_t iRechargeAfter {0};
    float iRechargeTotal {0};
    std::string iLoginWay {""};
    std::string iRegWay {""};
    std::string CIP {""};
    int32_t iRechargeType {0};
    std::string TradeID {""};
    int32_t GiftID {0};
    std::string ItemList {""};
    
};
namespace RefineTransferFlowEnum{

    enum class MoneyType: uint32_t {
        ZENY = 1,//铜币
        ROMONRY = 2,//zeny
        DIAMOND = 3,//金币 
    };    
}

class RefineTransferFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("EquipType", ToStringTlog(EquipType)); 
        AddLog("PreEquipID", ToStringTlog(PreEquipID)); 
        AddLog("PreEquipName", PreEquipName); 
        AddLog("PreEquipLevel", ToStringTlog(PreEquipLevel)); 
        AddLog("PreRefineLevel", ToStringTlog(PreRefineLevel)); 
        AddLog("AfterEquipID", ToStringTlog(AfterEquipID)); 
        AddLog("AfterEquipName", AfterEquipName); 
        AddLog("AfterEquipLevel", ToStringTlog(AfterEquipLevel)); 
        AddLog("AfterRefineLevel", ToStringTlog(AfterRefineLevel)); 
        AddLog("TransferType", ToStringTlog(TransferType)); 
        AddLog("CostItemId", ToStringTlog(CostItemId)); 
        AddLog("CostItemName", CostItemName); 
        AddLog("CostCount", ToStringTlog(CostCount)); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("MoneyCount", ToStringTlog(MoneyCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"EquipType\":"+ ToStringTlog(EquipType)); 
        AddLogJson("\"PreEquipID\":"+ ToStringTlog(PreEquipID)); 
        AddLogJson("\"PreEquipName\":\""+PreEquipName+"\""); 
        AddLogJson("\"PreEquipLevel\":"+ ToStringTlog(PreEquipLevel)); 
        AddLogJson("\"PreRefineLevel\":"+ ToStringTlog(PreRefineLevel)); 
        AddLogJson("\"AfterEquipID\":"+ ToStringTlog(AfterEquipID)); 
        AddLogJson("\"AfterEquipName\":\""+AfterEquipName+"\""); 
        AddLogJson("\"AfterEquipLevel\":"+ ToStringTlog(AfterEquipLevel)); 
        AddLogJson("\"AfterRefineLevel\":"+ ToStringTlog(AfterRefineLevel)); 
        AddLogJson("\"TransferType\":"+ ToStringTlog(TransferType)); 
        AddLogJson("\"CostItemId\":"+ ToStringTlog(CostItemId)); 
        AddLogJson("\"CostItemName\":\""+CostItemName+"\""); 
        AddLogJson("\"CostCount\":"+ ToStringTlog(CostCount)); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"MoneyCount\":"+ ToStringTlog(MoneyCount)); 

    }
    const char * GetTableName() override
    {
        return "RefineTransferFlow"; 
    }
    static const char * TableName() 
    {
        return "RefineTransferFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t EquipType {0};
    int32_t PreEquipID {0};
    std::string PreEquipName {""};
    int32_t PreEquipLevel {0};
    int32_t PreRefineLevel {0};
    int32_t AfterEquipID {0};
    std::string AfterEquipName {""};
    int32_t AfterEquipLevel {0};
    int32_t AfterRefineLevel {0};
    int32_t TransferType {0};
    int32_t CostItemId {0};
    std::string CostItemName {""};
    int32_t CostCount {0};
    int32_t MoneyType {0};
    int32_t MoneyCount {0};
    
};
namespace ResourceFlowEnum{

}

class ResourceFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("iResourceType", ToStringTlog(iResourceType)); 
        AddLog("iResource", ToStringTlog(iResource)); 
        AddLog("AfterResource", ToStringTlog(AfterResource)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"iResourceType\":"+ ToStringTlog(iResourceType)); 
        AddLogJson("\"iResource\":"+ ToStringTlog(iResource)); 
        AddLogJson("\"AfterResource\":"+ ToStringTlog(AfterResource)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 

    }
    const char * GetTableName() override
    {
        return "ResourceFlow"; 
    }
    static const char * TableName() 
    {
        return "ResourceFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t iResourceType {0};
    int32_t iResource {0};
    int32_t AfterResource {0};
    int32_t AddOrReduce {0};
    
};
namespace RidingExteriorFlowEnum{

}

class RidingExteriorFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("ExteriorType", ToStringTlog(ExteriorType)); 
        AddLog("ExteriorId", ToStringTlog(ExteriorId)); 
        AddLog("ExteriorRidingId", ToStringTlog(ExteriorRidingId)); 
        AddLog("CostItem", CostItem); 
        AddLog("RidingExteriorNum", ToStringTlog(RidingExteriorNum)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"ExteriorType\":"+ ToStringTlog(ExteriorType)); 
        AddLogJson("\"ExteriorId\":"+ ToStringTlog(ExteriorId)); 
        AddLogJson("\"ExteriorRidingId\":"+ ToStringTlog(ExteriorRidingId)); 
        AddLogJson("\"CostItem\":\""+CostItem+"\""); 
        AddLogJson("\"RidingExteriorNum\":"+ ToStringTlog(RidingExteriorNum)); 

    }
    const char * GetTableName() override
    {
        return "RidingExteriorFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingExteriorFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t ExteriorType {0};
    int32_t ExteriorId {0};
    int32_t ExteriorRidingId {0};
    std::string CostItem {""};
    int32_t RidingExteriorNum {0};
    
};
namespace RidingFlowEnum{

}

class RidingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RidingID", ToStringTlog(RidingID)); 
        AddLog("RidingName", ToStringTlog(RidingName)); 
        AddLog("RidingLevel", ToStringTlog(RidingLevel)); 
        AddLog("RidingPower", ToStringTlog(RidingPower)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RidingID\":"+ ToStringTlog(RidingID)); 
        AddLogJson("\"RidingName\":"+ ToStringTlog(RidingName)); 
        AddLogJson("\"RidingLevel\":"+ ToStringTlog(RidingLevel)); 
        AddLogJson("\"RidingPower\":"+ ToStringTlog(RidingPower)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 

    }
    const char * GetTableName() override
    {
        return "RidingFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t RidingID {0};
    int32_t RidingName {0};
    int32_t RidingLevel {0};
    int32_t RidingPower {0};
    int32_t OperateType {0};
    
};
namespace RidingLevelFlowEnum{

}

class RidingLevelFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("BeforeLevel", ToStringTlog(BeforeLevel)); 
        AddLog("count", ToStringTlog(count)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 
        AddLog("RemainingNum", ToStringTlog(RemainingNum)); 
        AddLog("VehicleExpBefore", ToStringTlog(VehicleExpBefore)); 
        AddLog("VehicleExpAfter", ToStringTlog(VehicleExpAfter)); 
        AddLog("AdvancedLevel", ToStringTlog(AdvancedLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"BeforeLevel\":"+ ToStringTlog(BeforeLevel)); 
        AddLogJson("\"count\":"+ ToStringTlog(count)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 
        AddLogJson("\"RemainingNum\":"+ ToStringTlog(RemainingNum)); 
        AddLogJson("\"VehicleExpBefore\":"+ ToStringTlog(VehicleExpBefore)); 
        AddLogJson("\"VehicleExpAfter\":"+ ToStringTlog(VehicleExpAfter)); 
        AddLogJson("\"AdvancedLevel\":"+ ToStringTlog(AdvancedLevel)); 

    }
    const char * GetTableName() override
    {
        return "RidingLevelFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingLevelFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t OperateType {0};
    int32_t BeforeLevel {0};
    int32_t count {0};
    int32_t AfterLevel {0};
    int32_t RemainingNum {0};
    int64_t VehicleExpBefore {0};
    int64_t VehicleExpAfter {0};
    int32_t AdvancedLevel {0};
    
};
namespace RidingQualityBreakFlowEnum{

}

class RidingQualityBreakFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("BreakType", ToStringTlog(BreakType)); 
        AddLog("BeforeBreakPoint", BeforeBreakPoint); 
        AddLog("AftBreakPoint", AftBreakPoint); 
        AddLog("RemainingTimes", ToStringTlog(RemainingTimes)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"BreakType\":"+ ToStringTlog(BreakType)); 
        AddLogJson("\"BeforeBreakPoint\":\""+BeforeBreakPoint+"\""); 
        AddLogJson("\"AftBreakPoint\":\""+AftBreakPoint+"\""); 
        AddLogJson("\"RemainingTimes\":"+ ToStringTlog(RemainingTimes)); 

    }
    const char * GetTableName() override
    {
        return "RidingQualityBreakFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingQualityBreakFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t BreakType {0};
    std::string BeforeBreakPoint {""};
    std::string AftBreakPoint {""};
    int32_t RemainingTimes {0};
    
};
namespace RidingQualityFlowEnum{

}

class RidingQualityFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("PreTrainPoint", PreTrainPoint); 
        AddLog("ResultPoint", ResultPoint); 
        AddLog("AftTrainPoint", AftTrainPoint); 
        AddLog("IsSaved", ToStringTlog(IsSaved)); 
        AddLog("OperateScores", ToStringTlog(OperateScores)); 
        AddLog("PreTrainTimes", ToStringTlog(PreTrainTimes)); 
        AddLog("SeniorTrainTimes", ToStringTlog(SeniorTrainTimes)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"PreTrainPoint\":\""+PreTrainPoint+"\""); 
        AddLogJson("\"ResultPoint\":\""+ResultPoint+"\""); 
        AddLogJson("\"AftTrainPoint\":\""+AftTrainPoint+"\""); 
        AddLogJson("\"IsSaved\":"+ ToStringTlog(IsSaved)); 
        AddLogJson("\"OperateScores\":"+ ToStringTlog(OperateScores)); 
        AddLogJson("\"PreTrainTimes\":"+ ToStringTlog(PreTrainTimes)); 
        AddLogJson("\"SeniorTrainTimes\":"+ ToStringTlog(SeniorTrainTimes)); 

    }
    const char * GetTableName() override
    {
        return "RidingQualityFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingQualityFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t OperateType {0};
    std::string PreTrainPoint {""};
    std::string ResultPoint {""};
    std::string AftTrainPoint {""};
    int32_t IsSaved {0};
    int32_t OperateScores {0};
    int32_t PreTrainTimes {0};
    int32_t SeniorTrainTimes {0};
    
};
namespace RidingUpgradeFlowEnum{

}

class RidingUpgradeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RidingID", ToStringTlog(RidingID)); 
        AddLog("RidingName", ToStringTlog(RidingName)); 
        AddLog("RidingLevel", ToStringTlog(RidingLevel)); 
        AddLog("RidingPower", ToStringTlog(RidingPower)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("RidingEXP", ToStringTlog(RidingEXP)); 
        AddLog("RidingStageID", ToStringTlog(RidingStageID)); 
        AddLog("RidingBaseStatus", RidingBaseStatus); 
        AddLog("RidingSkillNum", ToStringTlog(RidingSkillNum)); 
        AddLog("RidingSkill", RidingSkill); 
        AddLog("RidingColorID", ToStringTlog(RidingColorID)); 
        AddLog("RidingAccessoriesID", ToStringTlog(RidingAccessoriesID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RidingID\":"+ ToStringTlog(RidingID)); 
        AddLogJson("\"RidingName\":"+ ToStringTlog(RidingName)); 
        AddLogJson("\"RidingLevel\":"+ ToStringTlog(RidingLevel)); 
        AddLogJson("\"RidingPower\":"+ ToStringTlog(RidingPower)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"RidingEXP\":"+ ToStringTlog(RidingEXP)); 
        AddLogJson("\"RidingStageID\":"+ ToStringTlog(RidingStageID)); 
        AddLogJson("\"RidingBaseStatus\":\""+RidingBaseStatus+"\""); 
        AddLogJson("\"RidingSkillNum\":"+ ToStringTlog(RidingSkillNum)); 
        AddLogJson("\"RidingSkill\":\""+RidingSkill+"\""); 
        AddLogJson("\"RidingColorID\":"+ ToStringTlog(RidingColorID)); 
        AddLogJson("\"RidingAccessoriesID\":"+ ToStringTlog(RidingAccessoriesID)); 

    }
    const char * GetTableName() override
    {
        return "RidingUpgradeFlow"; 
    }
    static const char * TableName() 
    {
        return "RidingUpgradeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t RidingID {0};
    int32_t RidingName {0};
    int32_t RidingLevel {0};
    int32_t RidingPower {0};
    int32_t OperateType {0};
    int32_t RidingEXP {0};
    int32_t RidingStageID {0};
    std::string RidingBaseStatus {""};
    int32_t RidingSkillNum {0};
    std::string RidingSkill {""};
    int32_t RidingColorID {0};
    int32_t RidingAccessoriesID {0};
    
};
namespace RoleCreateEnum{

}

class RoleCreate : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("EyeType", ToStringTlog(EyeType)); 
        AddLog("EyeColor", ToStringTlog(EyeColor)); 
        AddLog("HairType", ToStringTlog(HairType)); 
        AddLog("HairColor", ToStringTlog(HairColor)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"EyeType\":"+ ToStringTlog(EyeType)); 
        AddLogJson("\"EyeColor\":"+ ToStringTlog(EyeColor)); 
        AddLogJson("\"HairType\":"+ ToStringTlog(HairType)); 
        AddLogJson("\"HairColor\":"+ ToStringTlog(HairColor)); 

    }
    const char * GetTableName() override
    {
        return "RoleCreate"; 
    }
    static const char * TableName() 
    {
        return "RoleCreate"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string vopenid {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    int32_t LoginChannel {0};
    int32_t RegChannel {0};
    int32_t EyeType {0};
    int32_t EyeColor {0};
    int32_t HairType {0};
    int32_t HairColor {0};
    
};
namespace RoleDeleteFlowEnum{

}

class RoleDeleteFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("vopenid", vopenid); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("IP", ToStringTlog(IP)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("Gold", ToStringTlog(Gold)); 
        AddLog("Zeny", ToStringTlog(Zeny)); 
        AddLog("Copper", ToStringTlog(Copper)); 
        AddLog("DeviceId", DeviceId); 
        AddLog("vClientIp", vClientIp); 
        AddLog("TotalTime", ToStringTlog(TotalTime)); 
        AddLog("DeleteTime", ToStringTlog(DeleteTime)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"IP\":"+ ToStringTlog(IP)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"Gold\":"+ ToStringTlog(Gold)); 
        AddLogJson("\"Zeny\":"+ ToStringTlog(Zeny)); 
        AddLogJson("\"Copper\":"+ ToStringTlog(Copper)); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"vClientIp\":\""+vClientIp+"\""); 
        AddLogJson("\"TotalTime\":"+ ToStringTlog(TotalTime)); 
        AddLogJson("\"DeleteTime\":"+ ToStringTlog(DeleteTime)); 

    }
    const char * GetTableName() override
    {
        return "RoleDeleteFlow"; 
    }
    static const char * TableName() 
    {
        return "RoleDeleteFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    std::string vopenid {""};
    int32_t iZoneAreaID {0};
    int32_t PlatID {0};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t IP {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t OperateType {0};
    int32_t Gold {0};
    int32_t Zeny {0};
    int32_t Copper {0};
    std::string DeviceId {""};
    std::string vClientIp {""};
    int32_t TotalTime {0};
    int32_t DeleteTime {0};
    
};
namespace RoleEnterEnum{

}

class RoleEnter : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("RoleExp", ToStringTlog(RoleExp)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("Stone", ToStringTlog(Stone)); 
        AddLog("Rmoney", ToStringTlog(Rmoney)); 
        AddLog("Zeny", ToStringTlog(Zeny)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("UnionSumCont", ToStringTlog(UnionSumCont)); 
        AddLog("UnionCurCont", ToStringTlog(UnionCurCont)); 
        AddLog("Line", ToStringTlog(Line)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("LoginType", ToStringTlog(LoginType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"RoleExp\":"+ ToStringTlog(RoleExp)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"Stone\":"+ ToStringTlog(Stone)); 
        AddLogJson("\"Rmoney\":"+ ToStringTlog(Rmoney)); 
        AddLogJson("\"Zeny\":"+ ToStringTlog(Zeny)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"UnionSumCont\":"+ ToStringTlog(UnionSumCont)); 
        AddLogJson("\"UnionCurCont\":"+ ToStringTlog(UnionCurCont)); 
        AddLogJson("\"Line\":"+ ToStringTlog(Line)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"LoginType\":"+ ToStringTlog(LoginType)); 

    }
    const char * GetTableName() override
    {
        return "RoleEnter"; 
    }
    static const char * TableName() 
    {
        return "RoleEnter"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int64_t RoleExp {0};
    int32_t Stone {0};
    int32_t Rmoney {0};
    int32_t Zeny {0};
    int32_t UnionSumCont {0};
    int32_t UnionCurCont {0};
    int32_t Line {0};
    int32_t MapID {0};
    int32_t Result {0};
    int32_t LoginType {0};
    
};
namespace RoleEnterMapEnum{

    enum class EnterType: uint32_t {
        NORMAL = 0,//正常进入
        SWITCH = 1,//传送
        RECONECT = 2,//断线重连
        GMOPERATE = 3,//gm操作
        ESCAPESTUCK = 4,//脱离卡死 
    };    
}

class RoleEnterMap : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Line", ToStringTlog(Line)); 
        AddLog("EnterType", ToStringTlog(EnterType)); 
        AddLog("pos_x", ToStringTlog(pos_x)); 
        AddLog("pos_y", ToStringTlog(pos_y)); 
        AddLog("pos_z", ToStringTlog(pos_z)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Line\":"+ ToStringTlog(Line)); 
        AddLogJson("\"EnterType\":"+ ToStringTlog(EnterType)); 
        AddLogJson("\"pos_x\":"+ ToStringTlog(pos_x)); 
        AddLogJson("\"pos_y\":"+ ToStringTlog(pos_y)); 
        AddLogJson("\"pos_z\":"+ ToStringTlog(pos_z)); 

    }
    const char * GetTableName() override
    {
        return "RoleEnterMap"; 
    }
    static const char * TableName() 
    {
        return "RoleEnterMap"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    int32_t Line {0};
    int32_t EnterType {0};
    int32_t pos_x {0};
    int32_t pos_y {0};
    int32_t pos_z {0};
    
};
namespace RoleExpFlowEnum{

    enum class ExpType: uint32_t {
        BASE_LEVEL = 0,//Base经验
        JOB_LEVEL = 1,//Job经验 
    };    
}

class RoleExpFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ExpType", ToStringTlog(ExpType)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("RoleExpBefore", ToStringTlog(RoleExpBefore)); 
        AddLog("ExpCount", ToStringTlog(ExpCount)); 
        AddLog("RoleExpAfter", ToStringTlog(RoleExpAfter)); 
        AddLog("PowerBefore", ToStringTlog(PowerBefore)); 
        AddLog("PowerAfter", ToStringTlog(PowerAfter)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("TotalOnlineTime", ToStringTlog(TotalOnlineTime)); 
        AddLog("RealBaseLevel", ToStringTlog(RealBaseLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ExpType\":"+ ToStringTlog(ExpType)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"RoleExpBefore\":"+ ToStringTlog(RoleExpBefore)); 
        AddLogJson("\"ExpCount\":"+ ToStringTlog(ExpCount)); 
        AddLogJson("\"RoleExpAfter\":"+ ToStringTlog(RoleExpAfter)); 
        AddLogJson("\"PowerBefore\":"+ ToStringTlog(PowerBefore)); 
        AddLogJson("\"PowerAfter\":"+ ToStringTlog(PowerAfter)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"TotalOnlineTime\":"+ ToStringTlog(TotalOnlineTime)); 
        AddLogJson("\"RealBaseLevel\":"+ ToStringTlog(RealBaseLevel)); 

    }
    const char * GetTableName() override
    {
        return "RoleExpFlow"; 
    }
    static const char * TableName() 
    {
        return "RoleExpFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ExpType {0};
    int32_t AddOrReduce {0};
    int64_t RoleExpBefore {0};
    int64_t ExpCount {0};
    int64_t RoleExpAfter {0};
    int32_t PowerBefore {0};
    int32_t PowerAfter {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t TotalOnlineTime {0};
    int32_t RealBaseLevel {0};
    
};
namespace RoleLeaveEnum{

}

class RoleLeave : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("Stone", ToStringTlog(Stone)); 
        AddLog("Rmoney", ToStringTlog(Rmoney)); 
        AddLog("Zeny", ToStringTlog(Zeny)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("UnionSumCont", ToStringTlog(UnionSumCont)); 
        AddLog("UnionCurCont", ToStringTlog(UnionCurCont)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Line", ToStringTlog(Line)); 
        AddLog("OnlineTime", ToStringTlog(OnlineTime)); 
        AddLog("LogoutType", ToStringTlog(LogoutType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"Stone\":"+ ToStringTlog(Stone)); 
        AddLogJson("\"Rmoney\":"+ ToStringTlog(Rmoney)); 
        AddLogJson("\"Zeny\":"+ ToStringTlog(Zeny)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"UnionSumCont\":"+ ToStringTlog(UnionSumCont)); 
        AddLogJson("\"UnionCurCont\":"+ ToStringTlog(UnionCurCont)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Line\":"+ ToStringTlog(Line)); 
        AddLogJson("\"OnlineTime\":"+ ToStringTlog(OnlineTime)); 
        AddLogJson("\"LogoutType\":"+ ToStringTlog(LogoutType)); 

    }
    const char * GetTableName() override
    {
        return "RoleLeave"; 
    }
    static const char * TableName() 
    {
        return "RoleLeave"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t Stone {0};
    int32_t Rmoney {0};
    int32_t Zeny {0};
    int32_t UnionSumCont {0};
    int32_t UnionCurCont {0};
    int32_t MapID {0};
    int32_t Line {0};
    int32_t OnlineTime {0};
    int32_t LogoutType {0};
    
};
namespace RoleLeaveMapEnum{

    enum class LeaveType: uint32_t {
        NORMAL = 0,//登出
        SWITCH = 1,//传送出
        KICKOUT = 2,//其他设备登录踢人
        GMOPERATE = 3,//gm操作
        ESCAPESTUCK = 4,//脱离卡死 
    };    
}

class RoleLeaveMap : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("Line", ToStringTlog(Line)); 
        AddLog("LeaveType", ToStringTlog(LeaveType)); 
        AddLog("pos_x", ToStringTlog(pos_x)); 
        AddLog("pos_y", ToStringTlog(pos_y)); 
        AddLog("pos_z", ToStringTlog(pos_z)); 
        AddLog("CostTime", ToStringTlog(CostTime)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"Line\":"+ ToStringTlog(Line)); 
        AddLogJson("\"LeaveType\":"+ ToStringTlog(LeaveType)); 
        AddLogJson("\"pos_x\":"+ ToStringTlog(pos_x)); 
        AddLogJson("\"pos_y\":"+ ToStringTlog(pos_y)); 
        AddLogJson("\"pos_z\":"+ ToStringTlog(pos_z)); 
        AddLogJson("\"CostTime\":"+ ToStringTlog(CostTime)); 

    }
    const char * GetTableName() override
    {
        return "RoleLeaveMap"; 
    }
    static const char * TableName() 
    {
        return "RoleLeaveMap"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    int32_t Line {0};
    int32_t LeaveType {0};
    int32_t pos_x {0};
    int32_t pos_y {0};
    int32_t pos_z {0};
    int32_t CostTime {0};
    
};
namespace RoleLevelUpEnum{

    enum class LevelType: uint32_t {
        BASE = 0,//Base等级
        JOB = 1,//Job等级 
    };    
}

class RoleLevelUp : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("LevelType", ToStringTlog(LevelType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("BeforeLevel", ToStringTlog(BeforeLevel)); 
        AddLog("count", ToStringTlog(count)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 
        AddLog("RoleExpBefore", ToStringTlog(RoleExpBefore)); 
        AddLog("RoleExpAfter", ToStringTlog(RoleExpAfter)); 
        AddLog("PowerBefore", ToStringTlog(PowerBefore)); 
        AddLog("PowerAfter", ToStringTlog(PowerAfter)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 
        AddLog("TotalOnlineTime", ToStringTlog(TotalOnlineTime)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"LevelType\":"+ ToStringTlog(LevelType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"BeforeLevel\":"+ ToStringTlog(BeforeLevel)); 
        AddLogJson("\"count\":"+ ToStringTlog(count)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 
        AddLogJson("\"RoleExpBefore\":"+ ToStringTlog(RoleExpBefore)); 
        AddLogJson("\"RoleExpAfter\":"+ ToStringTlog(RoleExpAfter)); 
        AddLogJson("\"PowerBefore\":"+ ToStringTlog(PowerBefore)); 
        AddLogJson("\"PowerAfter\":"+ ToStringTlog(PowerAfter)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 
        AddLogJson("\"TotalOnlineTime\":"+ ToStringTlog(TotalOnlineTime)); 

    }
    const char * GetTableName() override
    {
        return "RoleLevelUp"; 
    }
    static const char * TableName() 
    {
        return "RoleLevelUp"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t LevelType {0};
    int32_t OperateType {0};
    int32_t BeforeLevel {0};
    int32_t count {0};
    int32_t AfterLevel {0};
    int64_t RoleExpBefore {0};
    int64_t RoleExpAfter {0};
    int32_t PowerBefore {0};
    int32_t PowerAfter {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    int32_t TotalOnlineTime {0};
    
};
namespace RORoleSnapshotEnum{

}

class RORoleSnapshot : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("registerTime", registerTime); 
        AddLog("ActiveTime", ActiveTime); 
        AddLog("TwoWayPlayerFriendsNum", ToStringTlog(TwoWayPlayerFriendsNum)); 
        AddLog("Stone", ToStringTlog(Stone)); 
        AddLog("Rmoney", ToStringTlog(Rmoney)); 
        AddLog("Zeny", ToStringTlog(Zeny)); 
        AddLog("TaskID_Main", TaskID_Main); 
        AddLog("TaskID_Side", TaskID_Side); 
        AddLog("MedalLevel", MedalLevel); 
        AddLog("RidingLevel", ToStringTlog(RidingLevel)); 
        AddLog("Mercenary1Id", ToStringTlog(Mercenary1Id)); 
        AddLog("Mercenary2Id", ToStringTlog(Mercenary2Id)); 
        AddLog("MainWeaponId", ToStringTlog(MainWeaponId)); 
        AddLog("MainWeaponLevel", ToStringTlog(MainWeaponLevel)); 
        AddLog("MainWeaponRefine", ToStringTlog(MainWeaponRefine)); 
        AddLog("MainWeaponHole", ToStringTlog(MainWeaponHole)); 
        AddLog("MainWeaponCard", ToStringTlog(MainWeaponCard)); 
        AddLog("MainWeaponHoleAttr", MainWeaponHoleAttr); 
        AddLog("MainWeaponCardList", MainWeaponCardList); 
        AddLog("MainWeaponEnchantAttr", MainWeaponEnchantAttr); 
        AddLog("MainWeaponEnchantLevel", MainWeaponEnchantLevel); 
        AddLog("MainWeaponRemouldAttr", MainWeaponRemouldAttr); 
        AddLog("MainWeaponRemouldLevel", MainWeaponRemouldLevel); 
        AddLog("SecondWeaponId", ToStringTlog(SecondWeaponId)); 
        AddLog("SecondWeaponLevel", ToStringTlog(SecondWeaponLevel)); 
        AddLog("SecondWeaponRefine", ToStringTlog(SecondWeaponRefine)); 
        AddLog("SecondWeaponHole", ToStringTlog(SecondWeaponHole)); 
        AddLog("SecondWeaponCard", ToStringTlog(SecondWeaponCard)); 
        AddLog("SecondWeaponHoleAttr", SecondWeaponHoleAttr); 
        AddLog("SecondWeaponCardList", SecondWeaponCardList); 
        AddLog("SecondWeaponEnchantAttr", SecondWeaponEnchantAttr); 
        AddLog("SecondWeaponEnchantLevel", SecondWeaponEnchantLevel); 
        AddLog("SecondWeaponRemouldAttr", SecondWeaponRemouldAttr); 
        AddLog("SecondWeaponRemouldLevel", SecondWeaponRemouldLevel); 
        AddLog("EquipHeadId", ToStringTlog(EquipHeadId)); 
        AddLog("EquipHeadLevel", ToStringTlog(EquipHeadLevel)); 
        AddLog("EquipHeadRefine", ToStringTlog(EquipHeadRefine)); 
        AddLog("EquipHeadHole", ToStringTlog(EquipHeadHole)); 
        AddLog("EquipHeadCard", ToStringTlog(EquipHeadCard)); 
        AddLog("EquipHeadHoleAttr", EquipHeadHoleAttr); 
        AddLog("EquipHeadCardList", EquipHeadCardList); 
        AddLog("EquipHeadEnchantAttr", EquipHeadEnchantAttr); 
        AddLog("EquipHeadEnchantLevel", EquipHeadEnchantLevel); 
        AddLog("EquipHeadRemouldAttr", EquipHeadRemouldAttr); 
        AddLog("EquipHeadRemouldLevel", EquipHeadRemouldLevel); 
        AddLog("EquipFaceId", ToStringTlog(EquipFaceId)); 
        AddLog("EquipMouthId", ToStringTlog(EquipMouthId)); 
        AddLog("EquipCloakId", ToStringTlog(EquipCloakId)); 
        AddLog("EquipCloakLevel", ToStringTlog(EquipCloakLevel)); 
        AddLog("EquipCloakRefine", ToStringTlog(EquipCloakRefine)); 
        AddLog("EquipCloakHole", ToStringTlog(EquipCloakHole)); 
        AddLog("EquipCloakCard", ToStringTlog(EquipCloakCard)); 
        AddLog("EquipCloakHoleAttr", EquipCloakHoleAttr); 
        AddLog("EquipCloakCardList", EquipCloakCardList); 
        AddLog("EquipCloakEnchantAttr", EquipCloakEnchantAttr); 
        AddLog("EquipCloakEnchantLevel", EquipCloakEnchantLevel); 
        AddLog("EquipCloakRemouldAttr", EquipCloakRemouldAttr); 
        AddLog("EquipCloakRemouldLevel", EquipCloakRemouldLevel); 
        AddLog("EquipArmorId", ToStringTlog(EquipArmorId)); 
        AddLog("EquipArmorLevel", ToStringTlog(EquipArmorLevel)); 
        AddLog("EquipArmorRefine", ToStringTlog(EquipArmorRefine)); 
        AddLog("EquipArmorHole", ToStringTlog(EquipArmorHole)); 
        AddLog("EquipArmorCard", ToStringTlog(EquipArmorCard)); 
        AddLog("EquipArmorHoleAttr", EquipArmorHoleAttr); 
        AddLog("EquipArmorCardList", EquipArmorCardList); 
        AddLog("EquipArmorEnchantAttr", EquipArmorEnchantAttr); 
        AddLog("EquipArmorEnchantLevel", EquipArmorEnchantLevel); 
        AddLog("EquipArmorRemouldAttr", EquipArmorRemouldAttr); 
        AddLog("EquipArmorRemouldLevel", EquipArmorRemouldLevel); 
        AddLog("EquipBootsId", ToStringTlog(EquipBootsId)); 
        AddLog("EquipBootsLevel", ToStringTlog(EquipBootsLevel)); 
        AddLog("EquipBootsRefine", ToStringTlog(EquipBootsRefine)); 
        AddLog("EquipBootsHole", ToStringTlog(EquipBootsHole)); 
        AddLog("EquipBootsCard", ToStringTlog(EquipBootsCard)); 
        AddLog("EquipBootsHoleAttr", EquipBootsHoleAttr); 
        AddLog("EquipBootsCardList", EquipBootsCardList); 
        AddLog("EquipBootsEnchantAttr", EquipBootsEnchantAttr); 
        AddLog("EquipBootsEnchantLevel", EquipBootsEnchantLevel); 
        AddLog("EquipBootsRemouldAttr", EquipBootsRemouldAttr); 
        AddLog("EquipBootsRemouldLevel", EquipBootsRemouldLevel); 
        AddLog("EquipOrnament1Id", ToStringTlog(EquipOrnament1Id)); 
        AddLog("EquipOrnament1Level", ToStringTlog(EquipOrnament1Level)); 
        AddLog("EquipOrnament1Refine", ToStringTlog(EquipOrnament1Refine)); 
        AddLog("EquipOrnament1Hole", ToStringTlog(EquipOrnament1Hole)); 
        AddLog("EquipOrnament1Card", ToStringTlog(EquipOrnament1Card)); 
        AddLog("EquipOrnament1HoleAttr", EquipOrnament1HoleAttr); 
        AddLog("EquipOrnament1CardList", EquipOrnament1CardList); 
        AddLog("EquipOrnament1EnchantAttr", EquipOrnament1EnchantAttr); 
        AddLog("EquipOrnament1EnchantLevel", EquipOrnament1EnchantLevel); 
        AddLog("EquipOrnament1RemouldAttr", EquipOrnament1RemouldAttr); 
        AddLog("EquipOrnament1RemouldLevel", EquipOrnament1RemouldLevel); 
        AddLog("EquipOrnament2Id", ToStringTlog(EquipOrnament2Id)); 
        AddLog("EquipOrnament2Level", ToStringTlog(EquipOrnament2Level)); 
        AddLog("EquipOrnament2Refine", ToStringTlog(EquipOrnament2Refine)); 
        AddLog("EquipOrnament2Hole", ToStringTlog(EquipOrnament2Hole)); 
        AddLog("EquipOrnament2Card", ToStringTlog(EquipOrnament2Card)); 
        AddLog("EquipOrnament2HoleAttr", EquipOrnament2HoleAttr); 
        AddLog("EquipOrnament2CardList", EquipOrnament2CardList); 
        AddLog("EquipOrnament2EnchantAttr", EquipOrnament2EnchantAttr); 
        AddLog("EquipOrnament2EnchantLevel", EquipOrnament2EnchantLevel); 
        AddLog("EquipOrnament2RemouldAttr", EquipOrnament2RemouldAttr); 
        AddLog("EquipOrnament2RemouldLevel", EquipOrnament2RemouldLevel); 
        AddLog("EquipBackId", ToStringTlog(EquipBackId)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"registerTime\":\""+registerTime+"\""); 
        AddLogJson("\"ActiveTime\":\""+ActiveTime+"\""); 
        AddLogJson("\"TwoWayPlayerFriendsNum\":"+ ToStringTlog(TwoWayPlayerFriendsNum)); 
        AddLogJson("\"Stone\":"+ ToStringTlog(Stone)); 
        AddLogJson("\"Rmoney\":"+ ToStringTlog(Rmoney)); 
        AddLogJson("\"Zeny\":"+ ToStringTlog(Zeny)); 
        AddLogJson("\"TaskID_Main\":\""+TaskID_Main+"\""); 
        AddLogJson("\"TaskID_Side\":\""+TaskID_Side+"\""); 
        AddLogJson("\"MedalLevel\":\""+MedalLevel+"\""); 
        AddLogJson("\"RidingLevel\":"+ ToStringTlog(RidingLevel)); 
        AddLogJson("\"Mercenary1Id\":"+ ToStringTlog(Mercenary1Id)); 
        AddLogJson("\"Mercenary2Id\":"+ ToStringTlog(Mercenary2Id)); 
        AddLogJson("\"MainWeaponId\":"+ ToStringTlog(MainWeaponId)); 
        AddLogJson("\"MainWeaponLevel\":"+ ToStringTlog(MainWeaponLevel)); 
        AddLogJson("\"MainWeaponRefine\":"+ ToStringTlog(MainWeaponRefine)); 
        AddLogJson("\"MainWeaponHole\":"+ ToStringTlog(MainWeaponHole)); 
        AddLogJson("\"MainWeaponCard\":"+ ToStringTlog(MainWeaponCard)); 
        AddLogJson("\"MainWeaponHoleAttr\":\""+MainWeaponHoleAttr+"\""); 
        AddLogJson("\"MainWeaponCardList\":\""+MainWeaponCardList+"\""); 
        AddLogJson("\"MainWeaponEnchantAttr\":\""+MainWeaponEnchantAttr+"\""); 
        AddLogJson("\"MainWeaponEnchantLevel\":\""+MainWeaponEnchantLevel+"\""); 
        AddLogJson("\"MainWeaponRemouldAttr\":\""+MainWeaponRemouldAttr+"\""); 
        AddLogJson("\"MainWeaponRemouldLevel\":\""+MainWeaponRemouldLevel+"\""); 
        AddLogJson("\"SecondWeaponId\":"+ ToStringTlog(SecondWeaponId)); 
        AddLogJson("\"SecondWeaponLevel\":"+ ToStringTlog(SecondWeaponLevel)); 
        AddLogJson("\"SecondWeaponRefine\":"+ ToStringTlog(SecondWeaponRefine)); 
        AddLogJson("\"SecondWeaponHole\":"+ ToStringTlog(SecondWeaponHole)); 
        AddLogJson("\"SecondWeaponCard\":"+ ToStringTlog(SecondWeaponCard)); 
        AddLogJson("\"SecondWeaponHoleAttr\":\""+SecondWeaponHoleAttr+"\""); 
        AddLogJson("\"SecondWeaponCardList\":\""+SecondWeaponCardList+"\""); 
        AddLogJson("\"SecondWeaponEnchantAttr\":\""+SecondWeaponEnchantAttr+"\""); 
        AddLogJson("\"SecondWeaponEnchantLevel\":\""+SecondWeaponEnchantLevel+"\""); 
        AddLogJson("\"SecondWeaponRemouldAttr\":\""+SecondWeaponRemouldAttr+"\""); 
        AddLogJson("\"SecondWeaponRemouldLevel\":\""+SecondWeaponRemouldLevel+"\""); 
        AddLogJson("\"EquipHeadId\":"+ ToStringTlog(EquipHeadId)); 
        AddLogJson("\"EquipHeadLevel\":"+ ToStringTlog(EquipHeadLevel)); 
        AddLogJson("\"EquipHeadRefine\":"+ ToStringTlog(EquipHeadRefine)); 
        AddLogJson("\"EquipHeadHole\":"+ ToStringTlog(EquipHeadHole)); 
        AddLogJson("\"EquipHeadCard\":"+ ToStringTlog(EquipHeadCard)); 
        AddLogJson("\"EquipHeadHoleAttr\":\""+EquipHeadHoleAttr+"\""); 
        AddLogJson("\"EquipHeadCardList\":\""+EquipHeadCardList+"\""); 
        AddLogJson("\"EquipHeadEnchantAttr\":\""+EquipHeadEnchantAttr+"\""); 
        AddLogJson("\"EquipHeadEnchantLevel\":\""+EquipHeadEnchantLevel+"\""); 
        AddLogJson("\"EquipHeadRemouldAttr\":\""+EquipHeadRemouldAttr+"\""); 
        AddLogJson("\"EquipHeadRemouldLevel\":\""+EquipHeadRemouldLevel+"\""); 
        AddLogJson("\"EquipFaceId\":"+ ToStringTlog(EquipFaceId)); 
        AddLogJson("\"EquipMouthId\":"+ ToStringTlog(EquipMouthId)); 
        AddLogJson("\"EquipCloakId\":"+ ToStringTlog(EquipCloakId)); 
        AddLogJson("\"EquipCloakLevel\":"+ ToStringTlog(EquipCloakLevel)); 
        AddLogJson("\"EquipCloakRefine\":"+ ToStringTlog(EquipCloakRefine)); 
        AddLogJson("\"EquipCloakHole\":"+ ToStringTlog(EquipCloakHole)); 
        AddLogJson("\"EquipCloakCard\":"+ ToStringTlog(EquipCloakCard)); 
        AddLogJson("\"EquipCloakHoleAttr\":\""+EquipCloakHoleAttr+"\""); 
        AddLogJson("\"EquipCloakCardList\":\""+EquipCloakCardList+"\""); 
        AddLogJson("\"EquipCloakEnchantAttr\":\""+EquipCloakEnchantAttr+"\""); 
        AddLogJson("\"EquipCloakEnchantLevel\":\""+EquipCloakEnchantLevel+"\""); 
        AddLogJson("\"EquipCloakRemouldAttr\":\""+EquipCloakRemouldAttr+"\""); 
        AddLogJson("\"EquipCloakRemouldLevel\":\""+EquipCloakRemouldLevel+"\""); 
        AddLogJson("\"EquipArmorId\":"+ ToStringTlog(EquipArmorId)); 
        AddLogJson("\"EquipArmorLevel\":"+ ToStringTlog(EquipArmorLevel)); 
        AddLogJson("\"EquipArmorRefine\":"+ ToStringTlog(EquipArmorRefine)); 
        AddLogJson("\"EquipArmorHole\":"+ ToStringTlog(EquipArmorHole)); 
        AddLogJson("\"EquipArmorCard\":"+ ToStringTlog(EquipArmorCard)); 
        AddLogJson("\"EquipArmorHoleAttr\":\""+EquipArmorHoleAttr+"\""); 
        AddLogJson("\"EquipArmorCardList\":\""+EquipArmorCardList+"\""); 
        AddLogJson("\"EquipArmorEnchantAttr\":\""+EquipArmorEnchantAttr+"\""); 
        AddLogJson("\"EquipArmorEnchantLevel\":\""+EquipArmorEnchantLevel+"\""); 
        AddLogJson("\"EquipArmorRemouldAttr\":\""+EquipArmorRemouldAttr+"\""); 
        AddLogJson("\"EquipArmorRemouldLevel\":\""+EquipArmorRemouldLevel+"\""); 
        AddLogJson("\"EquipBootsId\":"+ ToStringTlog(EquipBootsId)); 
        AddLogJson("\"EquipBootsLevel\":"+ ToStringTlog(EquipBootsLevel)); 
        AddLogJson("\"EquipBootsRefine\":"+ ToStringTlog(EquipBootsRefine)); 
        AddLogJson("\"EquipBootsHole\":"+ ToStringTlog(EquipBootsHole)); 
        AddLogJson("\"EquipBootsCard\":"+ ToStringTlog(EquipBootsCard)); 
        AddLogJson("\"EquipBootsHoleAttr\":\""+EquipBootsHoleAttr+"\""); 
        AddLogJson("\"EquipBootsCardList\":\""+EquipBootsCardList+"\""); 
        AddLogJson("\"EquipBootsEnchantAttr\":\""+EquipBootsEnchantAttr+"\""); 
        AddLogJson("\"EquipBootsEnchantLevel\":\""+EquipBootsEnchantLevel+"\""); 
        AddLogJson("\"EquipBootsRemouldAttr\":\""+EquipBootsRemouldAttr+"\""); 
        AddLogJson("\"EquipBootsRemouldLevel\":\""+EquipBootsRemouldLevel+"\""); 
        AddLogJson("\"EquipOrnament1Id\":"+ ToStringTlog(EquipOrnament1Id)); 
        AddLogJson("\"EquipOrnament1Level\":"+ ToStringTlog(EquipOrnament1Level)); 
        AddLogJson("\"EquipOrnament1Refine\":"+ ToStringTlog(EquipOrnament1Refine)); 
        AddLogJson("\"EquipOrnament1Hole\":"+ ToStringTlog(EquipOrnament1Hole)); 
        AddLogJson("\"EquipOrnament1Card\":"+ ToStringTlog(EquipOrnament1Card)); 
        AddLogJson("\"EquipOrnament1HoleAttr\":\""+EquipOrnament1HoleAttr+"\""); 
        AddLogJson("\"EquipOrnament1CardList\":\""+EquipOrnament1CardList+"\""); 
        AddLogJson("\"EquipOrnament1EnchantAttr\":\""+EquipOrnament1EnchantAttr+"\""); 
        AddLogJson("\"EquipOrnament1EnchantLevel\":\""+EquipOrnament1EnchantLevel+"\""); 
        AddLogJson("\"EquipOrnament1RemouldAttr\":\""+EquipOrnament1RemouldAttr+"\""); 
        AddLogJson("\"EquipOrnament1RemouldLevel\":\""+EquipOrnament1RemouldLevel+"\""); 
        AddLogJson("\"EquipOrnament2Id\":"+ ToStringTlog(EquipOrnament2Id)); 
        AddLogJson("\"EquipOrnament2Level\":"+ ToStringTlog(EquipOrnament2Level)); 
        AddLogJson("\"EquipOrnament2Refine\":"+ ToStringTlog(EquipOrnament2Refine)); 
        AddLogJson("\"EquipOrnament2Hole\":"+ ToStringTlog(EquipOrnament2Hole)); 
        AddLogJson("\"EquipOrnament2Card\":"+ ToStringTlog(EquipOrnament2Card)); 
        AddLogJson("\"EquipOrnament2HoleAttr\":\""+EquipOrnament2HoleAttr+"\""); 
        AddLogJson("\"EquipOrnament2CardList\":\""+EquipOrnament2CardList+"\""); 
        AddLogJson("\"EquipOrnament2EnchantAttr\":\""+EquipOrnament2EnchantAttr+"\""); 
        AddLogJson("\"EquipOrnament2EnchantLevel\":\""+EquipOrnament2EnchantLevel+"\""); 
        AddLogJson("\"EquipOrnament2RemouldAttr\":\""+EquipOrnament2RemouldAttr+"\""); 
        AddLogJson("\"EquipOrnament2RemouldLevel\":\""+EquipOrnament2RemouldLevel+"\""); 
        AddLogJson("\"EquipBackId\":"+ ToStringTlog(EquipBackId)); 

    }
    const char * GetTableName() override
    {
        return "RORoleSnapshot"; 
    }
    static const char * TableName() 
    {
        return "RORoleSnapshot"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string registerTime {""};
    std::string ActiveTime {""};
    int32_t TwoWayPlayerFriendsNum {0};
    int64_t Stone {0};
    int64_t Rmoney {0};
    int64_t Zeny {0};
    std::string TaskID_Main {""};
    std::string TaskID_Side {""};
    std::string MedalLevel {""};
    int32_t RidingLevel {0};
    int32_t Mercenary1Id {0};
    int32_t Mercenary2Id {0};
    int32_t MainWeaponId {0};
    int32_t MainWeaponLevel {0};
    int32_t MainWeaponRefine {0};
    int32_t MainWeaponHole {0};
    int32_t MainWeaponCard {0};
    std::string MainWeaponHoleAttr {""};
    std::string MainWeaponCardList {""};
    std::string MainWeaponEnchantAttr {""};
    std::string MainWeaponEnchantLevel {""};
    std::string MainWeaponRemouldAttr {""};
    std::string MainWeaponRemouldLevel {""};
    int32_t SecondWeaponId {0};
    int32_t SecondWeaponLevel {0};
    int32_t SecondWeaponRefine {0};
    int32_t SecondWeaponHole {0};
    int32_t SecondWeaponCard {0};
    std::string SecondWeaponHoleAttr {""};
    std::string SecondWeaponCardList {""};
    std::string SecondWeaponEnchantAttr {""};
    std::string SecondWeaponEnchantLevel {""};
    std::string SecondWeaponRemouldAttr {""};
    std::string SecondWeaponRemouldLevel {""};
    int32_t EquipHeadId {0};
    int32_t EquipHeadLevel {0};
    int32_t EquipHeadRefine {0};
    int32_t EquipHeadHole {0};
    int32_t EquipHeadCard {0};
    std::string EquipHeadHoleAttr {""};
    std::string EquipHeadCardList {""};
    std::string EquipHeadEnchantAttr {""};
    std::string EquipHeadEnchantLevel {""};
    std::string EquipHeadRemouldAttr {""};
    std::string EquipHeadRemouldLevel {""};
    int32_t EquipFaceId {0};
    int32_t EquipMouthId {0};
    int32_t EquipCloakId {0};
    int32_t EquipCloakLevel {0};
    int32_t EquipCloakRefine {0};
    int32_t EquipCloakHole {0};
    int32_t EquipCloakCard {0};
    std::string EquipCloakHoleAttr {""};
    std::string EquipCloakCardList {""};
    std::string EquipCloakEnchantAttr {""};
    std::string EquipCloakEnchantLevel {""};
    std::string EquipCloakRemouldAttr {""};
    std::string EquipCloakRemouldLevel {""};
    int32_t EquipArmorId {0};
    int32_t EquipArmorLevel {0};
    int32_t EquipArmorRefine {0};
    int32_t EquipArmorHole {0};
    int32_t EquipArmorCard {0};
    std::string EquipArmorHoleAttr {""};
    std::string EquipArmorCardList {""};
    std::string EquipArmorEnchantAttr {""};
    std::string EquipArmorEnchantLevel {""};
    std::string EquipArmorRemouldAttr {""};
    std::string EquipArmorRemouldLevel {""};
    int32_t EquipBootsId {0};
    int32_t EquipBootsLevel {0};
    int32_t EquipBootsRefine {0};
    int32_t EquipBootsHole {0};
    int32_t EquipBootsCard {0};
    std::string EquipBootsHoleAttr {""};
    std::string EquipBootsCardList {""};
    std::string EquipBootsEnchantAttr {""};
    std::string EquipBootsEnchantLevel {""};
    std::string EquipBootsRemouldAttr {""};
    std::string EquipBootsRemouldLevel {""};
    int32_t EquipOrnament1Id {0};
    int32_t EquipOrnament1Level {0};
    int32_t EquipOrnament1Refine {0};
    int32_t EquipOrnament1Hole {0};
    int32_t EquipOrnament1Card {0};
    std::string EquipOrnament1HoleAttr {""};
    std::string EquipOrnament1CardList {""};
    std::string EquipOrnament1EnchantAttr {""};
    std::string EquipOrnament1EnchantLevel {""};
    std::string EquipOrnament1RemouldAttr {""};
    std::string EquipOrnament1RemouldLevel {""};
    int32_t EquipOrnament2Id {0};
    int32_t EquipOrnament2Level {0};
    int32_t EquipOrnament2Refine {0};
    int32_t EquipOrnament2Hole {0};
    int32_t EquipOrnament2Card {0};
    std::string EquipOrnament2HoleAttr {""};
    std::string EquipOrnament2CardList {""};
    std::string EquipOrnament2EnchantAttr {""};
    std::string EquipOrnament2EnchantLevel {""};
    std::string EquipOrnament2RemouldAttr {""};
    std::string EquipOrnament2RemouldLevel {""};
    int32_t EquipBackId {0};
    
};
namespace RoundFlowEnum{

}

class RoundFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("vopenid", vopenid); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("vIP", vIP); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("BattleID", ToStringTlog(BattleID)); 
        AddLog("BattleType", ToStringTlog(BattleType)); 
        AddLog("RoundScore", ToStringTlog(RoundScore)); 
        AddLog("RoundTime", ToStringTlog(RoundTime)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("Rank", ToStringTlog(Rank)); 
        AddLog("Items", Items); 
        AddLog("Moneys", Moneys); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"vIP\":\""+vIP+"\""); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"BattleID\":"+ ToStringTlog(BattleID)); 
        AddLogJson("\"BattleType\":"+ ToStringTlog(BattleType)); 
        AddLogJson("\"RoundScore\":"+ ToStringTlog(RoundScore)); 
        AddLogJson("\"RoundTime\":"+ ToStringTlog(RoundTime)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"Rank\":"+ ToStringTlog(Rank)); 
        AddLogJson("\"Items\":\""+Items+"\""); 
        AddLogJson("\"Moneys\":\""+Moneys+"\""); 

    }
    const char * GetTableName() override
    {
        return "RoundFlow"; 
    }
    static const char * TableName() 
    {
        return "RoundFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    std::string vopenid {""};
    int32_t iZoneAreaID {0};
    int32_t PlatID {0};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    std::string vIP {""};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int32_t BattleID {0};
    int32_t BattleType {0};
    int32_t RoundScore {0};
    int32_t RoundTime {0};
    int32_t Result {0};
    int32_t Rank {0};
    std::string Items {""};
    std::string Moneys {""};
    
};
namespace SceneUIFlowEnum{

}

class SceneUIFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("MapID", ToStringTlog(MapID)); 
        AddLog("UIType", ToStringTlog(UIType)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("Pox", ToStringTlog(Pox)); 
        AddLog("Poy", ToStringTlog(Poy)); 
        AddLog("Poz", ToStringTlog(Poz)); 
        AddLog("ActType", ToStringTlog(ActType)); 
        AddLog("PrizeType", ToStringTlog(PrizeType)); 
        AddLog("PrizeID", ToStringTlog(PrizeID)); 
        AddLog("RefreshTime", RefreshTime); 
        AddLog("DestroyTime", DestroyTime); 
        AddLog("ActAffiliation", ToStringTlog(ActAffiliation)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 
        AddLogJson("\"UIType\":"+ ToStringTlog(UIType)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"Pox\":"+ ToStringTlog(Pox)); 
        AddLogJson("\"Poy\":"+ ToStringTlog(Poy)); 
        AddLogJson("\"Poz\":"+ ToStringTlog(Poz)); 
        AddLogJson("\"ActType\":"+ ToStringTlog(ActType)); 
        AddLogJson("\"PrizeType\":"+ ToStringTlog(PrizeType)); 
        AddLogJson("\"PrizeID\":"+ ToStringTlog(PrizeID)); 
        AddLogJson("\"RefreshTime\":\""+RefreshTime+"\""); 
        AddLogJson("\"DestroyTime\":\""+DestroyTime+"\""); 
        AddLogJson("\"ActAffiliation\":"+ ToStringTlog(ActAffiliation)); 

    }
    const char * GetTableName() override
    {
        return "SceneUIFlow"; 
    }
    static const char * TableName() 
    {
        return "SceneUIFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t MapID {0};
    int32_t UIType {0};
    int32_t ItemID {0};
    int32_t Pox {0};
    int32_t Poy {0};
    int32_t Poz {0};
    int32_t ActType {0};
    int32_t PrizeType {0};
    int32_t PrizeID {0};
    std::string RefreshTime {""};
    std::string DestroyTime {""};
    int32_t ActAffiliation {0};
    
};
namespace SecAddFriendFlowEnum{

}

class SecAddFriendFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("OpenID", OpenID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleId", ToStringTlog(RoleId)); 
        AddLog("RoleType", ToStringTlog(RoleType)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("RoleBattlePoint", ToStringTlog(RoleBattlePoint)); 
        AddLog("UserIP", UserIP); 
        AddLog("GroupID", GroupID); 
        AddLog("DeviceInfo", DeviceInfo); 
        AddLog("ReceiverOpenID", ReceiverOpenID); 
        AddLog("ReceiverRoleID", ToStringTlog(ReceiverRoleID)); 
        AddLog("ReceiverRoleName", ReceiverRoleName); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleId\":"+ ToStringTlog(RoleId)); 
        AddLogJson("\"RoleType\":"+ ToStringTlog(RoleType)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"RoleBattlePoint\":"+ ToStringTlog(RoleBattlePoint)); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"GroupID\":\""+GroupID+"\""); 
        AddLogJson("\"DeviceInfo\":\""+DeviceInfo+"\""); 
        AddLogJson("\"ReceiverOpenID\":\""+ReceiverOpenID+"\""); 
        AddLogJson("\"ReceiverRoleID\":"+ ToStringTlog(ReceiverRoleID)); 
        AddLogJson("\"ReceiverRoleName\":\""+ReceiverRoleName+"\""); 

    }
    const char * GetTableName() override
    {
        return "SecAddFriendFlow"; 
    }
    static const char * TableName() 
    {
        return "SecAddFriendFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    std::string OpenID {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string ClientVersion {""};
    std::string RoleName {""};
    uint64_t RoleId {0};
    int32_t RoleType {0};
    int32_t RoleLevel {0};
    int32_t RoleBattlePoint {0};
    std::string UserIP {""};
    std::string GroupID {""};
    std::string DeviceInfo {""};
    std::string ReceiverOpenID {""};
    uint64_t ReceiverRoleID {0};
    std::string ReceiverRoleName {""};
    
};
namespace SecAuctionCompleteFlowEnum{

}

class SecAuctionCompleteFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("OpenID", OpenID); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("RoleID", ToStringTlog(RoleID)); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleProf", ToStringTlog(RoleProf)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("BuyerRoleBattlePoint", ToStringTlog(BuyerRoleBattlePoint)); 
        AddLog("BuyerUserIP", BuyerUserIP); 
        AddLog("BuyerFamilyID", ToStringTlog(BuyerFamilyID)); 
        AddLog("BuyerMoney1Count", ToStringTlog(BuyerMoney1Count)); 
        AddLog("BuyerMoney2Count", ToStringTlog(BuyerMoney2Count)); 
        AddLog("BuyerMoney3Count", ToStringTlog(BuyerMoney3Count)); 
        AddLog("DealAuctionID", DealAuctionID); 
        AddLog("DealMainType", ToStringTlog(DealMainType)); 
        AddLog("DealPriceType", ToStringTlog(DealPriceType)); 
        AddLog("DealPrice", ToStringTlog(DealPrice)); 
        AddLog("DealCount", ToStringTlog(DealCount)); 
        AddLog("DealUnitPrice", ToStringTlog(DealUnitPrice)); 
        AddLog("DealItemID", ToStringTlog(DealItemID)); 
        AddLog("DealUUID", DealUUID); 
        AddLog("DealLevel", ToStringTlog(DealLevel)); 
        AddLog("DealQlty", ToStringTlog(DealQlty)); 
        AddLog("DealGuadanCount", ToStringTlog(DealGuadanCount)); 
        AddLog("NowPriceMin", ToStringTlog(NowPriceMin)); 
        AddLog("NowPriceMax", ToStringTlog(NowPriceMax)); 
        AddLog("NowLastCount", ToStringTlog(NowLastCount)); 
        AddLog("LevelLimit", ToStringTlog(LevelLimit)); 
        AddLog("SellerOpenID", SellerOpenID); 
        AddLog("SellerRoleUid", ToStringTlog(SellerRoleUid)); 
        AddLog("SellerRoleJobID", ToStringTlog(SellerRoleJobID)); 
        AddLog("SellerRoleLevel", ToStringTlog(SellerRoleLevel)); 
        AddLog("SellerUserIP", SellerUserIP); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"RoleID\":"+ ToStringTlog(RoleID)); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleProf\":"+ ToStringTlog(RoleProf)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"BuyerRoleBattlePoint\":"+ ToStringTlog(BuyerRoleBattlePoint)); 
        AddLogJson("\"BuyerUserIP\":\""+BuyerUserIP+"\""); 
        AddLogJson("\"BuyerFamilyID\":"+ ToStringTlog(BuyerFamilyID)); 
        AddLogJson("\"BuyerMoney1Count\":"+ ToStringTlog(BuyerMoney1Count)); 
        AddLogJson("\"BuyerMoney2Count\":"+ ToStringTlog(BuyerMoney2Count)); 
        AddLogJson("\"BuyerMoney3Count\":"+ ToStringTlog(BuyerMoney3Count)); 
        AddLogJson("\"DealAuctionID\":\""+DealAuctionID+"\""); 
        AddLogJson("\"DealMainType\":"+ ToStringTlog(DealMainType)); 
        AddLogJson("\"DealPriceType\":"+ ToStringTlog(DealPriceType)); 
        AddLogJson("\"DealPrice\":"+ ToStringTlog(DealPrice)); 
        AddLogJson("\"DealCount\":"+ ToStringTlog(DealCount)); 
        AddLogJson("\"DealUnitPrice\":"+ ToStringTlog(DealUnitPrice)); 
        AddLogJson("\"DealItemID\":"+ ToStringTlog(DealItemID)); 
        AddLogJson("\"DealUUID\":\""+DealUUID+"\""); 
        AddLogJson("\"DealLevel\":"+ ToStringTlog(DealLevel)); 
        AddLogJson("\"DealQlty\":"+ ToStringTlog(DealQlty)); 
        AddLogJson("\"DealGuadanCount\":"+ ToStringTlog(DealGuadanCount)); 
        AddLogJson("\"NowPriceMin\":"+ ToStringTlog(NowPriceMin)); 
        AddLogJson("\"NowPriceMax\":"+ ToStringTlog(NowPriceMax)); 
        AddLogJson("\"NowLastCount\":"+ ToStringTlog(NowLastCount)); 
        AddLogJson("\"LevelLimit\":"+ ToStringTlog(LevelLimit)); 
        AddLogJson("\"SellerOpenID\":\""+SellerOpenID+"\""); 
        AddLogJson("\"SellerRoleUid\":"+ ToStringTlog(SellerRoleUid)); 
        AddLogJson("\"SellerRoleJobID\":"+ ToStringTlog(SellerRoleJobID)); 
        AddLogJson("\"SellerRoleLevel\":"+ ToStringTlog(SellerRoleLevel)); 
        AddLogJson("\"SellerUserIP\":\""+SellerUserIP+"\""); 

    }
    const char * GetTableName() override
    {
        return "SecAuctionCompleteFlow"; 
    }
    static const char * TableName() 
    {
        return "SecAuctionCompleteFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    int32_t PlatID {0};
    int32_t ZoneID {0};
    std::string OpenID {""};
    int32_t AreaID {0};
    uint64_t RoleID {0};
    std::string RoleName {""};
    int32_t RoleProf {0};
    int32_t RoleLevel {0};
    int32_t BuyerRoleBattlePoint {0};
    std::string BuyerUserIP {""};
    int32_t BuyerFamilyID {0};
    int32_t BuyerMoney1Count {0};
    int32_t BuyerMoney2Count {0};
    int32_t BuyerMoney3Count {0};
    std::string DealAuctionID {""};
    int32_t DealMainType {0};
    int32_t DealPriceType {0};
    int32_t DealPrice {0};
    int32_t DealCount {0};
    int32_t DealUnitPrice {0};
    int32_t DealItemID {0};
    std::string DealUUID {""};
    int32_t DealLevel {0};
    int32_t DealQlty {0};
    int32_t DealGuadanCount {0};
    int32_t NowPriceMin {0};
    int32_t NowPriceMax {0};
    int32_t NowLastCount {0};
    int32_t LevelLimit {0};
    std::string SellerOpenID {""};
    uint64_t SellerRoleUid {0};
    int32_t SellerRoleJobID {0};
    int32_t SellerRoleLevel {0};
    std::string SellerUserIP {""};
    
};
namespace SecAuctionFlowEnum{

}

class SecAuctionFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("OpenID", OpenID); 
        AddLog("RoleID", ToStringTlog(RoleID)); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleProf", ToStringTlog(RoleProf)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("UserIP", UserIP); 
        AddLog("GroupID", GroupID); 
        AddLog("AuctionID", AuctionID); 
        AddLog("AuctionPriceType", ToStringTlog(AuctionPriceType)); 
        AddLog("AuctionPrice", ToStringTlog(AuctionPrice)); 
        AddLog("AuctionUnitPrice", ToStringTlog(AuctionUnitPrice)); 
        AddLog("AuctionCount", ToStringTlog(AuctionCount)); 
        AddLog("AuctionItemID", ToStringTlog(AuctionItemID)); 
        AddLog("AuctionUUID", AuctionUUID); 
        AddLog("AuctionLevel", ToStringTlog(AuctionLevel)); 
        AddLog("AuctionQlty", ToStringTlog(AuctionQlty)); 
        AddLog("DealMainType", ToStringTlog(DealMainType)); 
        AddLog("AuctionTime", AuctionTime); 
        AddLog("SellerMoney1Count", ToStringTlog(SellerMoney1Count)); 
        AddLog("SellerMoney2Count", ToStringTlog(SellerMoney2Count)); 
        AddLog("SellerMoney3Count", ToStringTlog(SellerMoney3Count)); 
        AddLog("ServiceCharge", ToStringTlog(ServiceCharge)); 
        AddLog("LevelLimit", ToStringTlog(LevelLimit)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"RoleID\":"+ ToStringTlog(RoleID)); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleProf\":"+ ToStringTlog(RoleProf)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"GroupID\":\""+GroupID+"\""); 
        AddLogJson("\"AuctionID\":\""+AuctionID+"\""); 
        AddLogJson("\"AuctionPriceType\":"+ ToStringTlog(AuctionPriceType)); 
        AddLogJson("\"AuctionPrice\":"+ ToStringTlog(AuctionPrice)); 
        AddLogJson("\"AuctionUnitPrice\":"+ ToStringTlog(AuctionUnitPrice)); 
        AddLogJson("\"AuctionCount\":"+ ToStringTlog(AuctionCount)); 
        AddLogJson("\"AuctionItemID\":"+ ToStringTlog(AuctionItemID)); 
        AddLogJson("\"AuctionUUID\":\""+AuctionUUID+"\""); 
        AddLogJson("\"AuctionLevel\":"+ ToStringTlog(AuctionLevel)); 
        AddLogJson("\"AuctionQlty\":"+ ToStringTlog(AuctionQlty)); 
        AddLogJson("\"DealMainType\":"+ ToStringTlog(DealMainType)); 
        AddLogJson("\"AuctionTime\":\""+AuctionTime+"\""); 
        AddLogJson("\"SellerMoney1Count\":"+ ToStringTlog(SellerMoney1Count)); 
        AddLogJson("\"SellerMoney2Count\":"+ ToStringTlog(SellerMoney2Count)); 
        AddLogJson("\"SellerMoney3Count\":"+ ToStringTlog(SellerMoney3Count)); 
        AddLogJson("\"ServiceCharge\":"+ ToStringTlog(ServiceCharge)); 
        AddLogJson("\"LevelLimit\":"+ ToStringTlog(LevelLimit)); 

    }
    const char * GetTableName() override
    {
        return "SecAuctionFlow"; 
    }
    static const char * TableName() 
    {
        return "SecAuctionFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string OpenID {""};
    uint64_t RoleID {0};
    std::string RoleName {""};
    int32_t RoleProf {0};
    int32_t RoleLevel {0};
    std::string UserIP {""};
    std::string GroupID {""};
    std::string AuctionID {""};
    int32_t AuctionPriceType {0};
    int32_t AuctionPrice {0};
    int32_t AuctionUnitPrice {0};
    int32_t AuctionCount {0};
    int32_t AuctionItemID {0};
    std::string AuctionUUID {""};
    int32_t AuctionLevel {0};
    int32_t AuctionQlty {0};
    int32_t DealMainType {0};
    std::string AuctionTime {""};
    int64_t SellerMoney1Count {0};
    int64_t SellerMoney2Count {0};
    int64_t SellerMoney3Count {0};
    int32_t ServiceCharge {0};
    int32_t LevelLimit {0};
    
};
namespace SecEditFlowEnum{

}

class SecEditFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("OpenID", OpenID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleId", ToStringTlog(RoleId)); 
        AddLog("RoleType", ToStringTlog(RoleType)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("RoleBattlePoint", ToStringTlog(RoleBattlePoint)); 
        AddLog("UserIP", UserIP); 
        AddLog("GroupID", GroupID); 
        AddLog("GroupName", GroupName); 
        AddLog("PicUrl", PicUrl); 
        AddLog("EditType", ToStringTlog(EditType)); 
        AddLog("EditContents", EditContents); 
        AddLog("MsgType", ToStringTlog(MsgType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleId\":"+ ToStringTlog(RoleId)); 
        AddLogJson("\"RoleType\":"+ ToStringTlog(RoleType)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"RoleBattlePoint\":"+ ToStringTlog(RoleBattlePoint)); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"GroupID\":\""+GroupID+"\""); 
        AddLogJson("\"GroupName\":\""+GroupName+"\""); 
        AddLogJson("\"PicUrl\":\""+PicUrl+"\""); 
        AddLogJson("\"EditType\":"+ ToStringTlog(EditType)); 
        AddLogJson("\"EditContents\":\""+EditContents+"\""); 
        AddLogJson("\"MsgType\":"+ ToStringTlog(MsgType)); 

    }
    const char * GetTableName() override
    {
        return "SecEditFlow"; 
    }
    static const char * TableName() 
    {
        return "SecEditFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    std::string OpenID {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string ClientVersion {""};
    std::string RoleName {""};
    uint64_t RoleId {0};
    int32_t RoleType {0};
    int32_t RoleLevel {0};
    int32_t RoleBattlePoint {0};
    std::string UserIP {""};
    std::string GroupID {""};
    std::string GroupName {""};
    std::string PicUrl {""};
    int32_t EditType {0};
    std::string EditContents {""};
    int32_t MsgType {0};
    
};
namespace SecLoginEnum{

}

class SecLogin : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppid", GameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("openid", openid); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("SystemSoftware", SystemSoftware); 
        AddLog("SystemHardware", SystemHardware); 
        AddLog("TelecomOper", TelecomOper); 
        AddLog("Network", Network); 
        AddLog("DeviceId", DeviceId); 
        AddLog("RealIMEI", RealIMEI); 
        AddLog("UserIP", UserIP); 
        AddLog("RegisterTime", RegisterTime); 
        AddLog("TotalGameTime", TotalGameTime); 
        AddLog("RoleID", RoleID); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleJob", RoleJob); 
        AddLog("FightPower", ToStringTlog(FightPower)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("PicUrl", PicUrl); 
        AddLog("VipLevel", ToStringTlog(VipLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("RPNum", ToStringTlog(RPNum)); 
        AddLog("MoneyNum", ToStringTlog(MoneyNum)); 
        AddLog("Money2Num", ToStringTlog(Money2Num)); 
        AddLog("RoleJobGender", RoleJobGender); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppid\":\""+GameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"openid\":\""+openid+"\""); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"SystemSoftware\":\""+SystemSoftware+"\""); 
        AddLogJson("\"SystemHardware\":\""+SystemHardware+"\""); 
        AddLogJson("\"TelecomOper\":\""+TelecomOper+"\""); 
        AddLogJson("\"Network\":\""+Network+"\""); 
        AddLogJson("\"DeviceId\":\""+DeviceId+"\""); 
        AddLogJson("\"RealIMEI\":\""+RealIMEI+"\""); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"RegisterTime\":\""+RegisterTime+"\""); 
        AddLogJson("\"TotalGameTime\":\""+TotalGameTime+"\""); 
        AddLogJson("\"RoleID\":\""+RoleID+"\""); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleJob\":\""+RoleJob+"\""); 
        AddLogJson("\"FightPower\":"+ ToStringTlog(FightPower)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"PicUrl\":\""+PicUrl+"\""); 
        AddLogJson("\"VipLevel\":"+ ToStringTlog(VipLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"RPNum\":"+ ToStringTlog(RPNum)); 
        AddLogJson("\"MoneyNum\":"+ ToStringTlog(MoneyNum)); 
        AddLogJson("\"Money2Num\":"+ ToStringTlog(Money2Num)); 
        AddLogJson("\"RoleJobGender\":\""+RoleJobGender+"\""); 

    }
    const char * GetTableName() override
    {
        return "SecLogin"; 
    }
    static const char * TableName() 
    {
        return "SecLogin"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppid {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string openid {""};
    std::string ClientVersion {""};
    std::string SystemSoftware {""};
    std::string SystemHardware {""};
    std::string TelecomOper {""};
    std::string Network {""};
    std::string DeviceId {""};
    std::string RealIMEI {""};
    std::string UserIP {""};
    std::string RegisterTime {""};
    std::string TotalGameTime {""};
    std::string RoleID {""};
    std::string RoleName {""};
    std::string RoleJob {""};
    int32_t FightPower {0};
    int32_t Level {0};
    std::string PicUrl {""};
    int32_t VipLevel {0};
    int32_t PlayerFriendsNum {0};
    int64_t RPNum {0};
    int64_t MoneyNum {0};
    int64_t Money2Num {0};
    std::string RoleJobGender {""};
    
};
namespace SecRepaymentFlowEnum{

}

class SecRepaymentFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("OpenID", OpenID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleId", ToStringTlog(RoleId)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("RoleBattlePoint", ToStringTlog(RoleBattlePoint)); 
        AddLog("UserIP", UserIP); 
        AddLog("GroupID", GroupID); 
        AddLog("EquipmentType", EquipmentType); 
        AddLog("PlayerMoney1", ToStringTlog(PlayerMoney1)); 
        AddLog("PlayerMoney2", ToStringTlog(PlayerMoney2)); 
        AddLog("PlayerMoney3", ToStringTlog(PlayerMoney3)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleId\":"+ ToStringTlog(RoleId)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"RoleBattlePoint\":"+ ToStringTlog(RoleBattlePoint)); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"GroupID\":\""+GroupID+"\""); 
        AddLogJson("\"EquipmentType\":\""+EquipmentType+"\""); 
        AddLogJson("\"PlayerMoney1\":"+ ToStringTlog(PlayerMoney1)); 
        AddLogJson("\"PlayerMoney2\":"+ ToStringTlog(PlayerMoney2)); 
        AddLogJson("\"PlayerMoney3\":"+ ToStringTlog(PlayerMoney3)); 

    }
    const char * GetTableName() override
    {
        return "SecRepaymentFlow"; 
    }
    static const char * TableName() 
    {
        return "SecRepaymentFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    std::string OpenID {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string RoleName {""};
    int32_t RoleId {0};
    int32_t RoleLevel {0};
    int32_t RoleBattlePoint {0};
    std::string UserIP {""};
    std::string GroupID {""};
    std::string EquipmentType {""};
    int64_t PlayerMoney1 {0};
    int64_t PlayerMoney2 {0};
    int64_t PlayerMoney3 {0};
    
};
namespace SecTalkFlowEnum{

}

class SecTalkFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("GameSvrId", GameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("GameAppID", GameAppID); 
        AddLog("OpenID", OpenID); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("AreaID", ToStringTlog(AreaID)); 
        AddLog("ZoneID", ToStringTlog(ZoneID)); 
        AddLog("ClientVersion", ClientVersion); 
        AddLog("RoleName", RoleName); 
        AddLog("RoleId", ToStringTlog(RoleId)); 
        AddLog("RoleType", ToStringTlog(RoleType)); 
        AddLog("RoleLevel", ToStringTlog(RoleLevel)); 
        AddLog("RoleBattlePoint", ToStringTlog(RoleBattlePoint)); 
        AddLog("UserIP", UserIP); 
        AddLog("GroupID", GroupID); 
        AddLog("GroupName", GroupName); 
        AddLog("PicUrl", PicUrl); 
        AddLog("ReceiverOpenID", ReceiverOpenID); 
        AddLog("ReceiverRoleID", ToStringTlog(ReceiverRoleID)); 
        AddLog("ReceiverRoleName", ReceiverRoleName); 
        AddLog("ReceiverRoleType", ToStringTlog(ReceiverRoleType)); 
        AddLog("ReceiverRoleLevel", ToStringTlog(ReceiverRoleLevel)); 
        AddLog("ChatType", ToStringTlog(ChatType)); 
        AddLog("ChatContents", ChatContents); 
        AddLog("MsgType", ToStringTlog(MsgType)); 
        AddLog("MsgCharType", ToStringTlog(MsgCharType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"GameSvrId\":\""+GameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"GameAppID\":\""+GameAppID+"\""); 
        AddLogJson("\"OpenID\":\""+OpenID+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"AreaID\":"+ ToStringTlog(AreaID)); 
        AddLogJson("\"ZoneID\":"+ ToStringTlog(ZoneID)); 
        AddLogJson("\"ClientVersion\":\""+ClientVersion+"\""); 
        AddLogJson("\"RoleName\":\""+RoleName+"\""); 
        AddLogJson("\"RoleId\":"+ ToStringTlog(RoleId)); 
        AddLogJson("\"RoleType\":"+ ToStringTlog(RoleType)); 
        AddLogJson("\"RoleLevel\":"+ ToStringTlog(RoleLevel)); 
        AddLogJson("\"RoleBattlePoint\":"+ ToStringTlog(RoleBattlePoint)); 
        AddLogJson("\"UserIP\":\""+UserIP+"\""); 
        AddLogJson("\"GroupID\":\""+GroupID+"\""); 
        AddLogJson("\"GroupName\":\""+GroupName+"\""); 
        AddLogJson("\"PicUrl\":\""+PicUrl+"\""); 
        AddLogJson("\"ReceiverOpenID\":\""+ReceiverOpenID+"\""); 
        AddLogJson("\"ReceiverRoleID\":"+ ToStringTlog(ReceiverRoleID)); 
        AddLogJson("\"ReceiverRoleName\":\""+ReceiverRoleName+"\""); 
        AddLogJson("\"ReceiverRoleType\":"+ ToStringTlog(ReceiverRoleType)); 
        AddLogJson("\"ReceiverRoleLevel\":"+ ToStringTlog(ReceiverRoleLevel)); 
        AddLogJson("\"ChatType\":"+ ToStringTlog(ChatType)); 
        AddLogJson("\"ChatContents\":\""+ChatContents+"\""); 
        AddLogJson("\"MsgType\":"+ ToStringTlog(MsgType)); 
        AddLogJson("\"MsgCharType\":"+ ToStringTlog(MsgCharType)); 

    }
    const char * GetTableName() override
    {
        return "SecTalkFlow"; 
    }
    static const char * TableName() 
    {
        return "SecTalkFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string GameSvrId {""};
    std::string dtEventTime {""};
    std::string GameAppID {""};
    std::string OpenID {""};
    int32_t PlatID {0};
    int32_t AreaID {0};
    int32_t ZoneID {0};
    std::string ClientVersion {""};
    std::string RoleName {""};
    uint64_t RoleId {0};
    int32_t RoleType {0};
    int32_t RoleLevel {0};
    int32_t RoleBattlePoint {0};
    std::string UserIP {""};
    std::string GroupID {""};
    std::string GroupName {""};
    std::string PicUrl {""};
    std::string ReceiverOpenID {""};
    uint64_t ReceiverRoleID {0};
    std::string ReceiverRoleName {""};
    int32_t ReceiverRoleType {0};
    int32_t ReceiverRoleLevel {0};
    int32_t ChatType {0};
    std::string ChatContents {""};
    int32_t MsgType {0};
    int32_t MsgCharType {0};
    
};
namespace ShopFollowFlowEnum{

    enum class FollowType: uint32_t {
        SET_ATTENTION = 0,//关注
        CANCLE_ATTENTION = 1,//取消关注 
    };    
}

class ShopFollowFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 
        AddLog("FollowType", ToStringTlog(FollowType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("GoodsLevel", ToStringTlog(GoodsLevel)); 
        AddLog("GoodsMoneyType", ToStringTlog(GoodsMoneyType)); 
        AddLog("GoodsPrice", ToStringTlog(GoodsPrice)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("FollowCount", ToStringTlog(FollowCount)); 
        AddLog("MaxPrice", ToStringTlog(MaxPrice)); 
        AddLog("MinPrice", ToStringTlog(MinPrice)); 
        AddLog("GoodsQuantum", ToStringTlog(GoodsQuantum)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 
        AddLogJson("\"FollowType\":"+ ToStringTlog(FollowType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"GoodsLevel\":"+ ToStringTlog(GoodsLevel)); 
        AddLogJson("\"GoodsMoneyType\":"+ ToStringTlog(GoodsMoneyType)); 
        AddLogJson("\"GoodsPrice\":"+ ToStringTlog(GoodsPrice)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"FollowCount\":"+ ToStringTlog(FollowCount)); 
        AddLogJson("\"MaxPrice\":"+ ToStringTlog(MaxPrice)); 
        AddLogJson("\"MinPrice\":"+ ToStringTlog(MinPrice)); 
        AddLogJson("\"GoodsQuantum\":"+ ToStringTlog(GoodsQuantum)); 

    }
    const char * GetTableName() override
    {
        return "ShopFollowFlow"; 
    }
    static const char * TableName() 
    {
        return "ShopFollowFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int64_t TradeID {0};
    int32_t FollowType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t GoodsLevel {0};
    int32_t GoodsMoneyType {0};
    int32_t GoodsPrice {0};
    int32_t GoodsCount {0};
    int32_t FollowCount {0};
    int32_t MaxPrice {0};
    int32_t MinPrice {0};
    int32_t GoodsQuantum {0};
    
};
namespace ShopSellFlowEnum{

}

class ShopSellFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("GoodsType", ToStringTlog(GoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 
        AddLog("Cost", ToStringTlog(Cost)); 
        AddLog("GoodsLeave", ToStringTlog(GoodsLeave)); 
        AddLog("GoodsSellLimitLeave", ToStringTlog(GoodsSellLimitLeave)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"GoodsType\":"+ ToStringTlog(GoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 
        AddLogJson("\"Cost\":"+ ToStringTlog(Cost)); 
        AddLogJson("\"GoodsLeave\":"+ ToStringTlog(GoodsLeave)); 
        AddLogJson("\"GoodsSellLimitLeave\":"+ ToStringTlog(GoodsSellLimitLeave)); 

    }
    const char * GetTableName() override
    {
        return "ShopSellFlow"; 
    }
    static const char * TableName() 
    {
        return "ShopSellFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t GoodsType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t GoodsCount {0};
    int64_t TradeID {0};
    int32_t Cost {0};
    int32_t GoodsLeave {0};
    int32_t GoodsSellLimitLeave {0};
    
};
namespace ShopTradeFlowEnum{

    enum class OperateType: uint32_t {
        BUY = 0,//直接购买
        ORDER = 1,//预购 
    };    
}

class ShopTradeFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("GoodsType", ToStringTlog(GoodsType)); 
        AddLog("SubGoodsType", ToStringTlog(SubGoodsType)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("GoodsName", GoodsName); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("GoodsCount", ToStringTlog(GoodsCount)); 
        AddLog("TradeID", ToStringTlog(TradeID)); 
        AddLog("Cost", ToStringTlog(Cost)); 
        AddLog("GoodsLeave", ToStringTlog(GoodsLeave)); 
        AddLog("GoodsBuyLimitLeave", ToStringTlog(GoodsBuyLimitLeave)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"GoodsType\":"+ ToStringTlog(GoodsType)); 
        AddLogJson("\"SubGoodsType\":"+ ToStringTlog(SubGoodsType)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"GoodsName\":\""+GoodsName+"\""); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"GoodsCount\":"+ ToStringTlog(GoodsCount)); 
        AddLogJson("\"TradeID\":"+ ToStringTlog(TradeID)); 
        AddLogJson("\"Cost\":"+ ToStringTlog(Cost)); 
        AddLogJson("\"GoodsLeave\":"+ ToStringTlog(GoodsLeave)); 
        AddLogJson("\"GoodsBuyLimitLeave\":"+ ToStringTlog(GoodsBuyLimitLeave)); 

    }
    const char * GetTableName() override
    {
        return "ShopTradeFlow"; 
    }
    static const char * TableName() 
    {
        return "ShopTradeFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t GoodsType {0};
    int32_t SubGoodsType {0};
    int32_t GoodsID {0};
    std::string GoodsName {""};
    int32_t MoneyType {0};
    int32_t Price {0};
    int32_t GoodsCount {0};
    int64_t TradeID {0};
    int32_t Cost {0};
    int32_t GoodsLeave {0};
    int32_t GoodsBuyLimitLeave {0};
    
};
namespace SkillPointFlowEnum{

    enum class OperateType: uint32_t {
        RESET = 0,//重置
        RANDOM = 1,//自由分配
        RECOMMEND = 2,//推荐分配
        SWITCH = 3,//天赋切换 
    };    
    enum class SkillType: uint32_t {
        NORMAL = 0,//基础技能
        FIRST = 1,//一转职业
        SECOND = 2,//二转职业
        SECOND_UP = 3,//二转进阶 
    };    
}

class SkillPointFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("RecType", ToStringTlog(RecType)); 
        AddLog("SkillType", ToStringTlog(SkillType)); 
        AddLog("AddOrReduce", ToStringTlog(AddOrReduce)); 
        AddLog("SkillID", ToStringTlog(SkillID)); 
        AddLog("SkillName", SkillName); 
        AddLog("BeforeCount", ToStringTlog(BeforeCount)); 
        AddLog("AfterCount", ToStringTlog(AfterCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"RecType\":"+ ToStringTlog(RecType)); 
        AddLogJson("\"SkillType\":"+ ToStringTlog(SkillType)); 
        AddLogJson("\"AddOrReduce\":"+ ToStringTlog(AddOrReduce)); 
        AddLogJson("\"SkillID\":"+ ToStringTlog(SkillID)); 
        AddLogJson("\"SkillName\":\""+SkillName+"\""); 
        AddLogJson("\"BeforeCount\":"+ ToStringTlog(BeforeCount)); 
        AddLogJson("\"AfterCount\":"+ ToStringTlog(AfterCount)); 

    }
    const char * GetTableName() override
    {
        return "SkillPointFlow"; 
    }
    static const char * TableName() 
    {
        return "SkillPointFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t RecType {0};
    int32_t SkillType {0};
    int32_t AddOrReduce {0};
    int32_t SkillID {0};
    std::string SkillName {""};
    int32_t BeforeCount {0};
    int32_t AfterCount {0};
    
};
namespace SnsFlowEnum{

    enum class SnsType: uint32_t {
        NONE = 0,//无定义
        INVITE = 1,//邀请
        APPLY = 2,//接受
        LIKE = 3,//点赞
        BE_LIKED = 4,//被点赞
        GIVE_GIFTS = 5,//赠送
        RECEIVE_MAIL = 6,//收到邮件
        SHARE = 7,//分享
        OTHER = 8,//其他 
    };    
    enum class SNSSenType: uint32_t {
        NONE = 0,//NONE
        INVITE_TO_TEAM = 1,//INVITE_TO_TEAM
        INVITE_TO_FOLLOW = 2,//INVITE_TO_FOLLOW
        INVITE_TO_GUILD = 3,//INVITE_TO_GUILD
        INVITE_TO_FRIEND = 4,//INVITE_TO_FRIEND
        APPLY_TO_JOIN_TEAM = 5,//APPLY_TO_JOIN_TEAM
        SHARE_ACHIEVEMENT = 6,//SHARE_ACHIEVEMENT
        SHARE_PROP = 7,//SHARE_PROP
        SHARE_OTHER = 8,//SHARE_OTHER 
    };    
}

class SnsFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("ActorOpenID", ActorOpenID); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("RecNum", ToStringTlog(RecNum)); 
        AddLog("Count", ToStringTlog(Count)); 
        AddLog("SnsType", ToStringTlog(SnsType)); 
        AddLog("SNSSenType", ToStringTlog(SNSSenType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"ActorOpenID\":\""+ActorOpenID+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"RecNum\":"+ ToStringTlog(RecNum)); 
        AddLogJson("\"Count\":"+ ToStringTlog(Count)); 
        AddLogJson("\"SnsType\":"+ ToStringTlog(SnsType)); 
        AddLogJson("\"SNSSenType\":"+ ToStringTlog(SNSSenType)); 

    }
    const char * GetTableName() override
    {
        return "SnsFlow"; 
    }
    static const char * TableName() 
    {
        return "SnsFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t PlatID {0};
    int32_t iZoneAreaID {0};
    std::string ActorOpenID {""};
    std::string vRoleId {""};
    std::string vRoleName {""};
    int32_t JobId {0};
    int32_t Gender {0};
    int32_t Level {0};
    int32_t iJobLevel {0};
    int32_t PlayerFriendsNum {0};
    int32_t ChargeGold {0};
    int32_t RoleVip {0};
    std::string CreateTime {""};
    int32_t Power {0};
    int64_t UnionID {0};
    int32_t RecNum {0};
    int32_t Count {0};
    int32_t SnsType {0};
    int32_t SNSSenType {0};
    
};
namespace SpaceTaskFlowEnum{

}

class SpaceTaskFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("SpaceTimeQueryNum", ToStringTlog(SpaceTimeQueryNum)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"SpaceTimeQueryNum\":"+ ToStringTlog(SpaceTimeQueryNum)); 

    }
    const char * GetTableName() override
    {
        return "SpaceTaskFlow"; 
    }
    static const char * TableName() 
    {
        return "SpaceTaskFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t SpaceTimeQueryNum {0};
    
};
namespace SpaceTaskNumFlowEnum{

}

class SpaceTaskNumFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("SpaceTaskNum", ToStringTlog(SpaceTaskNum)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"SpaceTaskNum\":"+ ToStringTlog(SpaceTaskNum)); 

    }
    const char * GetTableName() override
    {
        return "SpaceTaskNumFlow"; 
    }
    static const char * TableName() 
    {
        return "SpaceTaskNumFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int32_t SpaceTaskNum {0};
    
};
namespace StallSnapshotFlowEnum{

}

class StallSnapshotFlow : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("GoodsID", ToStringTlog(GoodsID)); 
        AddLog("CurrentStorge", ToStringTlog(CurrentStorge)); 
        AddLog("CurrentPrice", ToStringTlog(CurrentPrice)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"GoodsID\":"+ ToStringTlog(GoodsID)); 
        AddLogJson("\"CurrentStorge\":"+ ToStringTlog(CurrentStorge)); 
        AddLogJson("\"CurrentPrice\":"+ ToStringTlog(CurrentPrice)); 

    }
    const char * GetTableName() override
    {
        return "StallSnapshotFlow"; 
    }
    static const char * TableName() 
    {
        return "StallSnapshotFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string vGameSvrId {""};
    std::string dtEventTime {""};
    int32_t iZoneAreaID {0};
    int32_t GoodsID {0};
    int32_t CurrentStorge {0};
    float CurrentPrice {0};
    
};
namespace TalentFlowEnum{

    enum class OperateType: uint32_t {
        TALENT_OPEN = 0,//天赋开启
        TALENT_EDIT = 1,//天赋编辑
        TALENT_SWITCH = 2,//天赋编辑 
    };    
    enum class TalentType: uint32_t {
        BASE_POINT = 0,//素质点
        SKILL_PONIT = 1,//技能点
        EQUIP = 2,//装备 
    };    
}

class TalentFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TalentType", ToStringTlog(TalentType)); 
        AddLog("TalentName", TalentName); 
        AddLog("TalentTaskID", ToStringTlog(TalentTaskID)); 
        AddLog("BeforePower", ToStringTlog(BeforePower)); 
        AddLog("AfterPower", ToStringTlog(AfterPower)); 
        AddLog("BeforeBasePoint", BeforeBasePoint); 
        AddLog("AfterBasePoint", AfterBasePoint); 
        AddLog("BeforeSkillPoint", BeforeSkillPoint); 
        AddLog("AfterSkillPoint", AfterSkillPoint); 
        AddLog("BeforeEquipStatus", BeforeEquipStatus); 
        AddLog("AfterEquipStatus", AfterEquipStatus); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TalentType\":"+ ToStringTlog(TalentType)); 
        AddLogJson("\"TalentName\":\""+TalentName+"\""); 
        AddLogJson("\"TalentTaskID\":"+ ToStringTlog(TalentTaskID)); 
        AddLogJson("\"BeforePower\":"+ ToStringTlog(BeforePower)); 
        AddLogJson("\"AfterPower\":"+ ToStringTlog(AfterPower)); 
        AddLogJson("\"BeforeBasePoint\":\""+BeforeBasePoint+"\""); 
        AddLogJson("\"AfterBasePoint\":\""+AfterBasePoint+"\""); 
        AddLogJson("\"BeforeSkillPoint\":\""+BeforeSkillPoint+"\""); 
        AddLogJson("\"AfterSkillPoint\":\""+AfterSkillPoint+"\""); 
        AddLogJson("\"BeforeEquipStatus\":\""+BeforeEquipStatus+"\""); 
        AddLogJson("\"AfterEquipStatus\":\""+AfterEquipStatus+"\""); 

    }
    const char * GetTableName() override
    {
        return "TalentFlow"; 
    }
    static const char * TableName() 
    {
        return "TalentFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TalentType {0};
    std::string TalentName {""};
    int32_t TalentTaskID {0};
    int32_t BeforePower {0};
    int32_t AfterPower {0};
    std::string BeforeBasePoint {""};
    std::string AfterBasePoint {""};
    std::string BeforeSkillPoint {""};
    std::string AfterSkillPoint {""};
    std::string BeforeEquipStatus {""};
    std::string AfterEquipStatus {""};
    
};
namespace TalkFlowEnum{

    enum class ChatType: uint32_t {
        WORLD = 0,//世界
        SCENE = 1,//场景
        GUILD = 2,//公会
        PRIVATE = 3,//私聊
        FRIEND = 4,//好友
        TEAM = 5,//组队 
    };    
    enum class ClicheOperateType: uint32_t {
        CLICHE_NONE = 0,//CLICHE_NONE
        CLICHE_SAVE = 1,//CLICHE_SAVE
        CLICHE_SEND = 2,//CLICHE_SEND
        CLICHE_ADDSTAR = 3,//CLICHE_ADDSTAR
        CLICHE_REMOVESTAR = 4,//CLICHE_REMOVESTAR 
    };    
}

class TalkFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("rRoleId", rRoleId); 
        AddLog("rRoleName", rRoleName); 
        AddLog("rJobId", ToStringTlog(rJobId)); 
        AddLog("rGender", ToStringTlog(rGender)); 
        AddLog("rLevel", ToStringTlog(rLevel)); 
        AddLog("rJobLevel", ToStringTlog(rJobLevel)); 
        AddLog("ChatType", ToStringTlog(ChatType)); 
        AddLog("Content", Content); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("ClicheOperateType", ToStringTlog(ClicheOperateType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"rRoleId\":\""+rRoleId+"\""); 
        AddLogJson("\"rRoleName\":\""+rRoleName+"\""); 
        AddLogJson("\"rJobId\":"+ ToStringTlog(rJobId)); 
        AddLogJson("\"rGender\":"+ ToStringTlog(rGender)); 
        AddLogJson("\"rLevel\":"+ ToStringTlog(rLevel)); 
        AddLogJson("\"rJobLevel\":"+ ToStringTlog(rJobLevel)); 
        AddLogJson("\"ChatType\":"+ ToStringTlog(ChatType)); 
        AddLogJson("\"Content\":\""+Content+"\""); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"ClicheOperateType\":"+ ToStringTlog(ClicheOperateType)); 

    }
    const char * GetTableName() override
    {
        return "TalkFlow"; 
    }
    static const char * TableName() 
    {
        return "TalkFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string rRoleId {""};
    std::string rRoleName {""};
    int32_t rJobId {0};
    int32_t rGender {0};
    int32_t rLevel {0};
    int32_t rJobLevel {0};
    int32_t ChatType {0};
    std::string Content {""};
    int32_t FriendPoints {0};
    int32_t ClicheOperateType {0};
    
};
namespace TaskFlowEnum{

    enum class OperateType: uint32_t {
        TAKE_TASK = 0,//接取任务
        FINISH_TASK = 1,//交付任务
        GIVEUP_TASK = 2,//放弃任务 
    };    
    enum class TaskType: uint32_t {
        kTaskTypeNone = 0,//无
        kTaskTypeMainStory = 1,//主线
        kTaskTypeBranch = 2,//支线
        kTaskTypeProfession = 3,//职业
        kTaskTypeDaily = 4,//日常
        kTaskTypeWeekly = 5,//周常
        kTaskTypeGuide = 6,//引导
        kTaskTypeSurprise = 7,//奇遇
        kTaskTypeGuild = 8,//公会
        kTaskTypeEden = 9,//伊甸园任务
        kTaskTypeAishen = 10,//爱神任务
        kTaskTypeEdenUrgent = 11,//伊甸园特殊任务
        kTaskTypeAdventure = 12,//冒险任务
        kTaskTypeDungeon = 13,//副本任务
        kTaskTypeLife = 14,//生活支线任务
        kTaskTypeWorldPve = 15,//世界pve
        kTaskTypePostcard = 16,//萌新任务
        kTaskTypeDelegate = 17,//日常委托任务
        kTaskTypeFake = 18,//前端假任务服务器不用管
        kTaskTypeExplore = 19,//探索任务
        kTaskTypeMercenary = 20,//佣兵
        kTaskTypeChallenge = 21,//挑战任务
        kTaskTypeActivity = 22,//活动任务 
    };    
}

class TaskFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TaskType", ToStringTlog(TaskType)); 
        AddLog("TaskID", ToStringTlog(TaskID)); 
        AddLog("TaskName", TaskName); 
        AddLog("Time", ToStringTlog(Time)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TaskType\":"+ ToStringTlog(TaskType)); 
        AddLogJson("\"TaskID\":"+ ToStringTlog(TaskID)); 
        AddLogJson("\"TaskName\":\""+TaskName+"\""); 
        AddLogJson("\"Time\":"+ ToStringTlog(Time)); 

    }
    const char * GetTableName() override
    {
        return "TaskFlow"; 
    }
    static const char * TableName() 
    {
        return "TaskFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TaskType {0};
    int32_t TaskID {0};
    std::string TaskName {""};
    int32_t Time {0};
    
};
namespace tbRealOnlineEnum{

}

class tbRealOnline : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("itimekey", ToStringTlog(itimekey)); 
        AddLog("zoneId", ToStringTlog(zoneId)); 
        AddLog("vGameSvrId", ToStringTlog(vGameSvrId)); 
        AddLog("iUserNum", ToStringTlog(iUserNum)); 
        AddLog("iMaxCapacity", ToStringTlog(iMaxCapacity)); 
        AddLog("MapID", ToStringTlog(MapID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"itimekey\":"+ ToStringTlog(itimekey)); 
        AddLogJson("\"zoneId\":"+ ToStringTlog(zoneId)); 
        AddLogJson("\"vGameSvrId\":"+ ToStringTlog(vGameSvrId)); 
        AddLogJson("\"iUserNum\":"+ ToStringTlog(iUserNum)); 
        AddLogJson("\"iMaxCapacity\":"+ ToStringTlog(iMaxCapacity)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 

    }
    const char * GetTableName() override
    {
        return "tbRealOnline"; 
    }
    static const char * TableName() 
    {
        return "tbRealOnline"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t itimekey {0};
    int32_t zoneId {0};
    int32_t vGameSvrId {0};
    int32_t iUserNum {0};
    int32_t iMaxCapacity {0};
    int32_t MapID {0};
    
};
namespace tbRealSceneOnlineEnum{

}

class tbRealSceneOnline : public ROTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("itimekey", ToStringTlog(itimekey)); 
        AddLog("zoneId", ToStringTlog(zoneId)); 
        AddLog("vGameSvrId", ToStringTlog(vGameSvrId)); 
        AddLog("iUserNum", ToStringTlog(iUserNum)); 
        AddLog("iMaxCapacity", ToStringTlog(iMaxCapacity)); 
        AddLog("MapID", ToStringTlog(MapID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"itimekey\":"+ ToStringTlog(itimekey)); 
        AddLogJson("\"zoneId\":"+ ToStringTlog(zoneId)); 
        AddLogJson("\"vGameSvrId\":"+ ToStringTlog(vGameSvrId)); 
        AddLogJson("\"iUserNum\":"+ ToStringTlog(iUserNum)); 
        AddLogJson("\"iMaxCapacity\":"+ ToStringTlog(iMaxCapacity)); 
        AddLogJson("\"MapID\":"+ ToStringTlog(MapID)); 

    }
    const char * GetTableName() override
    {
        return "tbRealSceneOnline"; 
    }
    static const char * TableName() 
    {
        return "tbRealSceneOnline"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string dtEventTime {""};
    std::string vGameAppid {""};
    int32_t itimekey {0};
    int32_t zoneId {0};
    int32_t vGameSvrId {0};
    int32_t iUserNum {0};
    int32_t iMaxCapacity {0};
    int32_t MapID {0};
    
};
namespace TeamActFlowEnum{

}

class TeamActFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PlayerType", ToStringTlog(PlayerType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("tPlayerType", ToStringTlog(tPlayerType)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PlayerType\":"+ ToStringTlog(PlayerType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"tPlayerType\":"+ ToStringTlog(tPlayerType)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 

    }
    const char * GetTableName() override
    {
        return "TeamActFlow"; 
    }
    static const char * TableName() 
    {
        return "TeamActFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PlayerType {0};
    int32_t OperateType {0};
    int32_t TeamType {0};
    int32_t TeamID {0};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t tPlayerType {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t FriendPoints {0};
    
};
namespace TeamApplyFlowEnum{

    enum class PlayerType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_NONE = 1,//无队伍 
    };    
    enum class OperateType: uint32_t {
        INVITE = 0,//发起申请
        ACCPTE = 1,//接受申请
        REFUSE = 2,//拒绝申请 
    };    
    enum class InviteType: uint32_t {
        FRIEND = 0,//好友
        GUILD = 1,//公会 
    };    
    enum class tPlayerType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_MEMBER = 1,//队员 
    };    
}

class TeamApplyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PlayerType", ToStringTlog(PlayerType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("InviteType", ToStringTlog(InviteType)); 
        AddLog("tPlayerType", ToStringTlog(tPlayerType)); 
        AddLog("WaitTime", ToStringTlog(WaitTime)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PlayerType\":"+ ToStringTlog(PlayerType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"InviteType\":"+ ToStringTlog(InviteType)); 
        AddLogJson("\"tPlayerType\":"+ ToStringTlog(tPlayerType)); 
        AddLogJson("\"WaitTime\":"+ ToStringTlog(WaitTime)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 

    }
    const char * GetTableName() override
    {
        return "TeamApplyFlow"; 
    }
    static const char * TableName() 
    {
        return "TeamApplyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PlayerType {0};
    int32_t OperateType {0};
    int32_t TeamType {0};
    int32_t TeamID {0};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t InviteType {0};
    int32_t tPlayerType {0};
    int32_t WaitTime {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t FriendPoints {0};
    
};
namespace TeamJoinFlowEnum{

    enum class PlayerType: uint32_t {
        TEAM_LEADER = 0,//队长
        TEAM_MENBER = 1,//队员 
    };    
    enum class OperateType: uint32_t {
        INVITE = 0,//邀请加入
        ACCPTE = 1,//申请加入
        REFUSE = 2,//匹配加入
        NONE = 3,//无 
    };    
    enum class InviteType: uint32_t {
        FRIEND = 0,//好友
        GUILD = 1,//公会 
    };    
}

class TeamJoinFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PlayerType", ToStringTlog(PlayerType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("InviteType", ToStringTlog(InviteType)); 
        AddLog("WaitTime", ToStringTlog(WaitTime)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PlayerType\":"+ ToStringTlog(PlayerType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"InviteType\":"+ ToStringTlog(InviteType)); 
        AddLogJson("\"WaitTime\":"+ ToStringTlog(WaitTime)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 

    }
    const char * GetTableName() override
    {
        return "TeamJoinFlow"; 
    }
    static const char * TableName() 
    {
        return "TeamJoinFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PlayerType {0};
    int32_t OperateType {0};
    int32_t TeamType {0};
    int32_t TeamID {0};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t InviteType {0};
    int32_t WaitTime {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t InterValue {0};
    int32_t FriendPoints {0};
    
};
namespace TeamMatchEndEnum{

    enum class OperateType: uint32_t {
        SELF = 0,//个人发起匹配
        TEAM = 1,//组队发起匹配 
    };    
    enum class TeamType: uint32_t {
        AMUSEMENT = 0,//娱乐
        ANTHEM_TRIAL = 1,//圣歌
        BATTLE = 2,//战场
        DIG_TREASURE = 3,//挖宝
        INFINITY_TOWER = 4,//无限塔
        TRAIN = 5,//开火车
        MVP = 6,//MVP
        MINI = 7,//MINI 
    };    
    enum class Result: uint32_t {
        SUCCESS = 0,//成功
        FAILED = 1,//失败 
    };    
}

class TeamMatchEnd : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("MatchID", ToStringTlog(MatchID)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("Result", ToStringTlog(Result)); 
        AddLog("WaitTime", ToStringTlog(WaitTime)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("mTeamType", ToStringTlog(mTeamType)); 
        AddLog("MatchSuccessType", ToStringTlog(MatchSuccessType)); 
        AddLog("MatchType", ToStringTlog(MatchType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"MatchID\":"+ ToStringTlog(MatchID)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"Result\":"+ ToStringTlog(Result)); 
        AddLogJson("\"WaitTime\":"+ ToStringTlog(WaitTime)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"mTeamType\":"+ ToStringTlog(mTeamType)); 
        AddLogJson("\"MatchSuccessType\":"+ ToStringTlog(MatchSuccessType)); 
        AddLogJson("\"MatchType\":"+ ToStringTlog(MatchType)); 

    }
    const char * GetTableName() override
    {
        return "TeamMatchEnd"; 
    }
    static const char * TableName() 
    {
        return "TeamMatchEnd"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TeamType {0};
    int32_t MatchID {0};
    int32_t TeamID {0};
    int32_t Result {0};
    int32_t WaitTime {0};
    int32_t InterValue {0};
    int32_t mTeamType {0};
    int32_t MatchSuccessType {0};
    int32_t MatchType {0};
    
};
namespace TeamMatchStartEnum{

    enum class OperateType: uint32_t {
        SELF = 0,//个人发起匹配
        TEAM = 1,//组队发起匹配 
    };    
}

class TeamMatchStart : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("MatchID", ToStringTlog(MatchID)); 
        AddLog("InterValue", ToStringTlog(InterValue)); 
        AddLog("MatchType", ToStringTlog(MatchType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"MatchID\":"+ ToStringTlog(MatchID)); 
        AddLogJson("\"InterValue\":"+ ToStringTlog(InterValue)); 
        AddLogJson("\"MatchType\":"+ ToStringTlog(MatchType)); 

    }
    const char * GetTableName() override
    {
        return "TeamMatchStart"; 
    }
    static const char * TableName() 
    {
        return "TeamMatchStart"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TeamType {0};
    int32_t MatchID {0};
    int32_t InterValue {0};
    int32_t MatchType {0};
    
};
namespace ThemePartyFlowEnum{

}

class ThemePartyFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PhraseID", ToStringTlog(PhraseID)); 
        AddLog("PhraseName", PhraseName); 
        AddLog("PhraseStatus", ToStringTlog(PhraseStatus)); 
        AddLog("PhraseTimeCost", ToStringTlog(PhraseTimeCost)); 
        AddLog("MagicCosThemeID", ToStringTlog(MagicCosThemeID)); 
        AddLog("MagicCosThemeName", MagicCosThemeName); 
        AddLog("MagicCosScore", ToStringTlog(MagicCosScore)); 
        AddLog("CockTailID", ToStringTlog(CockTailID)); 
        AddLog("CockTailName", CockTailName); 
        AddLog("CocktailBuffID", ToStringTlog(CocktailBuffID)); 
        AddLog("CocktailBuffEffect", CocktailBuffEffect); 
        AddLog("ifDrunk", ToStringTlog(ifDrunk)); 
        AddLog("ifCockTailInvite", ToStringTlog(ifCockTailInvite)); 
        AddLog("DancePhrase", ToStringTlog(DancePhrase)); 
        AddLog("ifDanceSuccess", ToStringTlog(ifDanceSuccess)); 
        AddLog("ifDanceLeader", ToStringTlog(ifDanceLeader)); 
        AddLog("myLikes", ToStringTlog(myLikes)); 
        AddLog("PrizeID", ToStringTlog(PrizeID)); 
        AddLog("PhraseReward", PhraseReward); 
        AddLog("PhraseCost", PhraseCost); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("tLikes", ToStringTlog(tLikes)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PhraseID\":"+ ToStringTlog(PhraseID)); 
        AddLogJson("\"PhraseName\":\""+PhraseName+"\""); 
        AddLogJson("\"PhraseStatus\":"+ ToStringTlog(PhraseStatus)); 
        AddLogJson("\"PhraseTimeCost\":"+ ToStringTlog(PhraseTimeCost)); 
        AddLogJson("\"MagicCosThemeID\":"+ ToStringTlog(MagicCosThemeID)); 
        AddLogJson("\"MagicCosThemeName\":\""+MagicCosThemeName+"\""); 
        AddLogJson("\"MagicCosScore\":"+ ToStringTlog(MagicCosScore)); 
        AddLogJson("\"CockTailID\":"+ ToStringTlog(CockTailID)); 
        AddLogJson("\"CockTailName\":\""+CockTailName+"\""); 
        AddLogJson("\"CocktailBuffID\":"+ ToStringTlog(CocktailBuffID)); 
        AddLogJson("\"CocktailBuffEffect\":\""+CocktailBuffEffect+"\""); 
        AddLogJson("\"ifDrunk\":"+ ToStringTlog(ifDrunk)); 
        AddLogJson("\"ifCockTailInvite\":"+ ToStringTlog(ifCockTailInvite)); 
        AddLogJson("\"DancePhrase\":"+ ToStringTlog(DancePhrase)); 
        AddLogJson("\"ifDanceSuccess\":"+ ToStringTlog(ifDanceSuccess)); 
        AddLogJson("\"ifDanceLeader\":"+ ToStringTlog(ifDanceLeader)); 
        AddLogJson("\"myLikes\":"+ ToStringTlog(myLikes)); 
        AddLogJson("\"PrizeID\":"+ ToStringTlog(PrizeID)); 
        AddLogJson("\"PhraseReward\":\""+PhraseReward+"\""); 
        AddLogJson("\"PhraseCost\":\""+PhraseCost+"\""); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"tLikes\":"+ ToStringTlog(tLikes)); 

    }
    const char * GetTableName() override
    {
        return "ThemePartyFlow"; 
    }
    static const char * TableName() 
    {
        return "ThemePartyFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PhraseID {0};
    std::string PhraseName {""};
    int32_t PhraseStatus {0};
    int32_t PhraseTimeCost {0};
    int32_t MagicCosThemeID {0};
    std::string MagicCosThemeName {""};
    int32_t MagicCosScore {0};
    int32_t CockTailID {0};
    std::string CockTailName {""};
    int32_t CocktailBuffID {0};
    std::string CocktailBuffEffect {""};
    int32_t ifDrunk {0};
    int32_t ifCockTailInvite {0};
    int32_t DancePhrase {0};
    int32_t ifDanceSuccess {0};
    int32_t ifDanceLeader {0};
    int32_t myLikes {0};
    int32_t PrizeID {0};
    std::string PhraseReward {""};
    std::string PhraseCost {""};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t tLikes {0};
    
};
namespace TitleFlowEnum{

}

class TitleFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("PreTitleName", PreTitleName); 
        AddLog("AftTitleName", AftTitleName); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"PreTitleName\":\""+PreTitleName+"\""); 
        AddLogJson("\"AftTitleName\":\""+AftTitleName+"\""); 

    }
    const char * GetTableName() override
    {
        return "TitleFlow"; 
    }
    static const char * TableName() 
    {
        return "TitleFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    std::string PreTitleName {""};
    std::string AftTitleName {""};
    
};
namespace TreasureHunterFlowEnum{

}

class TreasureHunterFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PlayerType", ToStringTlog(PlayerType)); 
        AddLog("THF_OperateType", ToStringTlog(THF_OperateType)); 
        AddLog("OperateObjectType", ToStringTlog(OperateObjectType)); 
        AddLog("OperateObjectUId", OperateObjectUId); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("TreasureType", ToStringTlog(TreasureType)); 
        AddLog("TreasureItem", TreasureItem); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PlayerType\":"+ ToStringTlog(PlayerType)); 
        AddLogJson("\"THF_OperateType\":"+ ToStringTlog(THF_OperateType)); 
        AddLogJson("\"OperateObjectType\":"+ ToStringTlog(OperateObjectType)); 
        AddLogJson("\"OperateObjectUId\":\""+OperateObjectUId+"\""); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"TreasureType\":"+ ToStringTlog(TreasureType)); 
        AddLogJson("\"TreasureItem\":\""+TreasureItem+"\""); 

    }
    const char * GetTableName() override
    {
        return "TreasureHunterFlow"; 
    }
    static const char * TableName() 
    {
        return "TreasureHunterFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PlayerType {0};
    int32_t THF_OperateType {0};
    int32_t OperateObjectType {0};
    std::string OperateObjectUId {""};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t FriendPoints {0};
    int32_t TreasureType {0};
    std::string TreasureItem {""};
    
};
namespace TreasureOpenFlowEnum{

}

class TreasureOpenFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamType", ToStringTlog(TeamType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("TreasureID", ToStringTlog(TreasureID)); 
        AddLog("TreasureName", TreasureName); 
        AddLog("Resason", ToStringTlog(Resason)); 
        AddLog("Subreason", ToStringTlog(Subreason)); 
        AddLog("Fake", ToStringTlog(Fake)); 
        AddLog("Items", Items); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamType\":"+ ToStringTlog(TeamType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"TreasureID\":"+ ToStringTlog(TreasureID)); 
        AddLogJson("\"TreasureName\":\""+TreasureName+"\""); 
        AddLogJson("\"Resason\":"+ ToStringTlog(Resason)); 
        AddLogJson("\"Subreason\":"+ ToStringTlog(Subreason)); 
        AddLogJson("\"Fake\":"+ ToStringTlog(Fake)); 
        AddLogJson("\"Items\":\""+Items+"\""); 

    }
    const char * GetTableName() override
    {
        return "TreasureOpenFlow"; 
    }
    static const char * TableName() 
    {
        return "TreasureOpenFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamType {0};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    int32_t TreasureID {0};
    std::string TreasureName {""};
    int32_t Resason {0};
    int32_t Subreason {0};
    int32_t Fake {0};
    std::string Items {""};
    
};
namespace UnionAuctionFlowEnum{

}

class UnionAuctionFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("UnionDonate", ToStringTlog(UnionDonate)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("ItemName", ItemName); 
        AddLog("iMoneyType", ToStringTlog(iMoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 
        AddLog("AuctionType", ToStringTlog(AuctionType)); 
        AddLog("Reason", ToStringTlog(Reason)); 
        AddLog("SubReason", ToStringTlog(SubReason)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"UnionDonate\":"+ ToStringTlog(UnionDonate)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"ItemName\":\""+ItemName+"\""); 
        AddLogJson("\"iMoneyType\":"+ ToStringTlog(iMoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 
        AddLogJson("\"AuctionType\":"+ ToStringTlog(AuctionType)); 
        AddLogJson("\"Reason\":"+ ToStringTlog(Reason)); 
        AddLogJson("\"SubReason\":"+ ToStringTlog(SubReason)); 

    }
    const char * GetTableName() override
    {
        return "UnionAuctionFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionAuctionFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DutyType {0};
    int32_t UnionDonate {0};
    int32_t OperateType {0};
    int32_t ItemID {0};
    std::string ItemName {""};
    int32_t iMoneyType {0};
    int32_t Price {0};
    int32_t AuctionType {0};
    int32_t Reason {0};
    int32_t SubReason {0};
    
};
namespace UnionBagFlowEnum{

}

class UnionBagFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("ItemID", ToStringTlog(ItemID)); 
        AddLog("ItemName", ItemName); 
        AddLog("AuctionType", ToStringTlog(AuctionType)); 
        AddLog("iMoneyType", ToStringTlog(iMoneyType)); 
        AddLog("Price", ToStringTlog(Price)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"ItemID\":"+ ToStringTlog(ItemID)); 
        AddLogJson("\"ItemName\":\""+ItemName+"\""); 
        AddLogJson("\"AuctionType\":"+ ToStringTlog(AuctionType)); 
        AddLogJson("\"iMoneyType\":"+ ToStringTlog(iMoneyType)); 
        AddLogJson("\"Price\":"+ ToStringTlog(Price)); 

    }
    const char * GetTableName() override
    {
        return "UnionBagFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionBagFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DutyType {0};
    int32_t OperateType {0};
    int32_t ItemID {0};
    std::string ItemName {""};
    int32_t AuctionType {0};
    int32_t iMoneyType {0};
    int32_t Price {0};
    
};
namespace UnionBanquetFlowEnum{

}

class UnionBanquetFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("PhraseID", ToStringTlog(PhraseID)); 
        AddLog("PhraseName", PhraseName); 
        AddLog("PhraseStatus", ToStringTlog(PhraseStatus)); 
        AddLog("PhraseTimeCost", ToStringTlog(PhraseTimeCost)); 
        AddLog("PhraseScore", ToStringTlog(PhraseScore)); 
        AddLog("PhraseReward", PhraseReward); 
        AddLog("tRoleId", ToStringTlog(tRoleId)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"PhraseID\":"+ ToStringTlog(PhraseID)); 
        AddLogJson("\"PhraseName\":\""+PhraseName+"\""); 
        AddLogJson("\"PhraseStatus\":"+ ToStringTlog(PhraseStatus)); 
        AddLogJson("\"PhraseTimeCost\":"+ ToStringTlog(PhraseTimeCost)); 
        AddLogJson("\"PhraseScore\":"+ ToStringTlog(PhraseScore)); 
        AddLogJson("\"PhraseReward\":\""+PhraseReward+"\""); 
        AddLogJson("\"tRoleId\":"+ ToStringTlog(tRoleId)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 

    }
    const char * GetTableName() override
    {
        return "UnionBanquetFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionBanquetFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t PhraseID {0};
    std::string PhraseName {""};
    int32_t PhraseStatus {0};
    int32_t PhraseTimeCost {0};
    int32_t PhraseScore {0};
    std::string PhraseReward {""};
    int32_t tRoleId {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    
};
namespace UnionBuildFlowEnum{

}

class UnionBuildFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("BuildType", ToStringTlog(BuildType)); 
        AddLog("CrystalType", ToStringTlog(CrystalType)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("MoneyCost", ToStringTlog(MoneyCost)); 
        AddLog("Diamonds", ToStringTlog(Diamonds)); 
        AddLog("DonateItems", DonateItems); 
        AddLog("UpTime", ToStringTlog(UpTime)); 
        AddLog("RemainTime", ToStringTlog(RemainTime)); 
        AddLog("PreLevel", ToStringTlog(PreLevel)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"BuildType\":"+ ToStringTlog(BuildType)); 
        AddLogJson("\"CrystalType\":"+ ToStringTlog(CrystalType)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"MoneyCost\":"+ ToStringTlog(MoneyCost)); 
        AddLogJson("\"Diamonds\":"+ ToStringTlog(Diamonds)); 
        AddLogJson("\"DonateItems\":\""+DonateItems+"\""); 
        AddLogJson("\"UpTime\":"+ ToStringTlog(UpTime)); 
        AddLogJson("\"RemainTime\":"+ ToStringTlog(RemainTime)); 
        AddLogJson("\"PreLevel\":"+ ToStringTlog(PreLevel)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 

    }
    const char * GetTableName() override
    {
        return "UnionBuildFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionBuildFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DutyType {0};
    int32_t BuildType {0};
    int32_t CrystalType {0};
    int32_t OperateType {0};
    int32_t MoneyCost {0};
    int32_t Diamonds {0};
    std::string DonateItems {""};
    int32_t UpTime {0};
    int32_t RemainTime {0};
    int32_t PreLevel {0};
    int32_t AfterLevel {0};
    
};
namespace UnionCarveFlowEnum{

}

class UnionCarveFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("CarvePointGet", ToStringTlog(CarvePointGet)); 
        AddLog("BeforeCarvePoint", ToStringTlog(BeforeCarvePoint)); 
        AddLog("AfterCarvePoint", ToStringTlog(AfterCarvePoint)); 
        AddLog("OptType", ToStringTlog(OptType)); 
        AddLog("OptPeople", ToStringTlog(OptPeople)); 
        AddLog("CoatofArmsID", ToStringTlog(CoatofArmsID)); 
        AddLog("BeforeGivePoint", ToStringTlog(BeforeGivePoint)); 
        AddLog("AfterGivePoint", ToStringTlog(AfterGivePoint)); 
        AddLog("GivePeople", GivePeople); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"CarvePointGet\":"+ ToStringTlog(CarvePointGet)); 
        AddLogJson("\"BeforeCarvePoint\":"+ ToStringTlog(BeforeCarvePoint)); 
        AddLogJson("\"AfterCarvePoint\":"+ ToStringTlog(AfterCarvePoint)); 
        AddLogJson("\"OptType\":"+ ToStringTlog(OptType)); 
        AddLogJson("\"OptPeople\":"+ ToStringTlog(OptPeople)); 
        AddLogJson("\"CoatofArmsID\":"+ ToStringTlog(CoatofArmsID)); 
        AddLogJson("\"BeforeGivePoint\":"+ ToStringTlog(BeforeGivePoint)); 
        AddLogJson("\"AfterGivePoint\":"+ ToStringTlog(AfterGivePoint)); 
        AddLogJson("\"GivePeople\":\""+GivePeople+"\""); 

    }
    const char * GetTableName() override
    {
        return "UnionCarveFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionCarveFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    int32_t FriendPoints {0};
    int32_t CarvePointGet {0};
    int32_t BeforeCarvePoint {0};
    int32_t AfterCarvePoint {0};
    int32_t OptType {0};
    int32_t OptPeople {0};
    int32_t CoatofArmsID {0};
    int32_t BeforeGivePoint {0};
    int32_t AfterGivePoint {0};
    std::string GivePeople {""};
    
};
namespace UnionCookFlowEnum{

}

class UnionCookFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("CookName", CookName); 
        AddLog("PreCount", ToStringTlog(PreCount)); 
        AddLog("AfterCount", ToStringTlog(AfterCount)); 
        AddLog("Rank", ToStringTlog(Rank)); 
        AddLog("TimeBuffCount", ToStringTlog(TimeBuffCount)); 
        AddLog("OutPotCount", ToStringTlog(OutPotCount)); 
        AddLog("UrgentMenuCount", ToStringTlog(UrgentMenuCount)); 
        AddLog("UrgentMenuFinishCount", ToStringTlog(UrgentMenuFinishCount)); 
        AddLog("PerfectTimeCount", ToStringTlog(PerfectTimeCount)); 
        AddLog("Score", ToStringTlog(Score)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"CookName\":\""+CookName+"\""); 
        AddLogJson("\"PreCount\":"+ ToStringTlog(PreCount)); 
        AddLogJson("\"AfterCount\":"+ ToStringTlog(AfterCount)); 
        AddLogJson("\"Rank\":"+ ToStringTlog(Rank)); 
        AddLogJson("\"TimeBuffCount\":"+ ToStringTlog(TimeBuffCount)); 
        AddLogJson("\"OutPotCount\":"+ ToStringTlog(OutPotCount)); 
        AddLogJson("\"UrgentMenuCount\":"+ ToStringTlog(UrgentMenuCount)); 
        AddLogJson("\"UrgentMenuFinishCount\":"+ ToStringTlog(UrgentMenuFinishCount)); 
        AddLogJson("\"PerfectTimeCount\":"+ ToStringTlog(PerfectTimeCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 

    }
    const char * GetTableName() override
    {
        return "UnionCookFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionCookFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    std::string CookName {""};
    int32_t PreCount {0};
    int32_t AfterCount {0};
    int32_t Rank {0};
    int32_t TimeBuffCount {0};
    int32_t OutPotCount {0};
    int32_t UrgentMenuCount {0};
    int32_t UrgentMenuFinishCount {0};
    int32_t PerfectTimeCount {0};
    int32_t Score {0};
    
};
namespace UnionCrystalFlowEnum{

}

class UnionCrystalFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("ActionType", ToStringTlog(ActionType)); 
        AddLog("CrystalType1", ToStringTlog(CrystalType1)); 
        AddLog("CrystalType2", ToStringTlog(CrystalType2)); 
        AddLog("CrystalType3", ToStringTlog(CrystalType3)); 
        AddLog("BlessType", ToStringTlog(BlessType)); 
        AddLog("BlessBuff", BlessBuff); 
        AddLog("ResearchType", ToStringTlog(ResearchType)); 
        AddLog("BeforeProgress", ToStringTlog(BeforeProgress)); 
        AddLog("ProgressDelta", ToStringTlog(ProgressDelta)); 
        AddLog("AfterProgress", ToStringTlog(AfterProgress)); 
        AddLog("BeforeLevel", ToStringTlog(BeforeLevel)); 
        AddLog("LevelDelta", ToStringTlog(LevelDelta)); 
        AddLog("AfterLevel", ToStringTlog(AfterLevel)); 
        AddLog("MoneyType", ToStringTlog(MoneyType)); 
        AddLog("MoneyCost", ToStringTlog(MoneyCost)); 
        AddLog("AfterMoney", ToStringTlog(AfterMoney)); 
        AddLog("IfContriUse", ToStringTlog(IfContriUse)); 
        AddLog("ContriCost", ToStringTlog(ContriCost)); 
        AddLog("AfterContri", ToStringTlog(AfterContri)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"ActionType\":"+ ToStringTlog(ActionType)); 
        AddLogJson("\"CrystalType1\":"+ ToStringTlog(CrystalType1)); 
        AddLogJson("\"CrystalType2\":"+ ToStringTlog(CrystalType2)); 
        AddLogJson("\"CrystalType3\":"+ ToStringTlog(CrystalType3)); 
        AddLogJson("\"BlessType\":"+ ToStringTlog(BlessType)); 
        AddLogJson("\"BlessBuff\":\""+BlessBuff+"\""); 
        AddLogJson("\"ResearchType\":"+ ToStringTlog(ResearchType)); 
        AddLogJson("\"BeforeProgress\":"+ ToStringTlog(BeforeProgress)); 
        AddLogJson("\"ProgressDelta\":"+ ToStringTlog(ProgressDelta)); 
        AddLogJson("\"AfterProgress\":"+ ToStringTlog(AfterProgress)); 
        AddLogJson("\"BeforeLevel\":"+ ToStringTlog(BeforeLevel)); 
        AddLogJson("\"LevelDelta\":"+ ToStringTlog(LevelDelta)); 
        AddLogJson("\"AfterLevel\":"+ ToStringTlog(AfterLevel)); 
        AddLogJson("\"MoneyType\":"+ ToStringTlog(MoneyType)); 
        AddLogJson("\"MoneyCost\":"+ ToStringTlog(MoneyCost)); 
        AddLogJson("\"AfterMoney\":"+ ToStringTlog(AfterMoney)); 
        AddLogJson("\"IfContriUse\":"+ ToStringTlog(IfContriUse)); 
        AddLogJson("\"ContriCost\":"+ ToStringTlog(ContriCost)); 
        AddLogJson("\"AfterContri\":"+ ToStringTlog(AfterContri)); 

    }
    const char * GetTableName() override
    {
        return "UnionCrystalFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionCrystalFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t ActionType {0};
    int32_t CrystalType1 {0};
    int32_t CrystalType2 {0};
    int32_t CrystalType3 {0};
    int32_t BlessType {0};
    std::string BlessBuff {""};
    int32_t ResearchType {0};
    int32_t BeforeProgress {0};
    int32_t ProgressDelta {0};
    int32_t AfterProgress {0};
    int32_t BeforeLevel {0};
    int32_t LevelDelta {0};
    int32_t AfterLevel {0};
    int32_t MoneyType {0};
    int32_t MoneyCost {0};
    int32_t AfterMoney {0};
    int32_t IfContriUse {0};
    int32_t ContriCost {0};
    int32_t AfterContri {0};
    
};
namespace UnionFlowEnum{

    enum class OperateType: uint32_t {
        CREATE = 0,//创建
        DISSOLVED = 1,//解散 
    };    
}

class UnionFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("UnionLevel", ToStringTlog(UnionLevel)); 
        AddLog("UnionMessage", UnionMessage); 
        AddLog("UnionMembers", ToStringTlog(UnionMembers)); 
        AddLog("UnionMoney", ToStringTlog(UnionMoney)); 
        AddLog("UnionActive", ToStringTlog(UnionActive)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"UnionLevel\":"+ ToStringTlog(UnionLevel)); 
        AddLogJson("\"UnionMessage\":\""+UnionMessage+"\""); 
        AddLogJson("\"UnionMembers\":"+ ToStringTlog(UnionMembers)); 
        AddLogJson("\"UnionMoney\":"+ ToStringTlog(UnionMoney)); 
        AddLogJson("\"UnionActive\":"+ ToStringTlog(UnionActive)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 

    }
    const char * GetTableName() override
    {
        return "UnionFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t UnionLevel {0};
    std::string UnionMessage {""};
    int32_t UnionMembers {0};
    int32_t UnionMoney {0};
    int32_t UnionActive {0};
    int32_t OperateType {0};
    
};
namespace UnionGiftFlowEnum{

}

class UnionGiftFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("GiftID", ToStringTlog(GiftID)); 
        AddLog("GiftName", GiftName); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("tRoleName", tRoleName); 
        AddLog("tJobId", ToStringTlog(tJobId)); 
        AddLog("tGender", ToStringTlog(tGender)); 
        AddLog("tLevel", ToStringTlog(tLevel)); 
        AddLog("tJobLevel", ToStringTlog(tJobLevel)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("GiftCount", ToStringTlog(GiftCount)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"GiftID\":"+ ToStringTlog(GiftID)); 
        AddLogJson("\"GiftName\":\""+GiftName+"\""); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"tRoleName\":\""+tRoleName+"\""); 
        AddLogJson("\"tJobId\":"+ ToStringTlog(tJobId)); 
        AddLogJson("\"tGender\":"+ ToStringTlog(tGender)); 
        AddLogJson("\"tLevel\":"+ ToStringTlog(tLevel)); 
        AddLogJson("\"tJobLevel\":"+ ToStringTlog(tJobLevel)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"GiftCount\":"+ ToStringTlog(GiftCount)); 

    }
    const char * GetTableName() override
    {
        return "UnionGiftFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionGiftFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t GiftID {0};
    std::string GiftName {""};
    int32_t DutyType {0};
    std::string tRoleName {""};
    int32_t tJobId {0};
    int32_t tGender {0};
    int32_t tLevel {0};
    int32_t tJobLevel {0};
    int32_t FriendJudge {0};
    int32_t FriendPoints {0};
    int32_t GiftCount {0};
    
};
namespace UnionHuntingFlowEnum{

}

class UnionHuntingFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("RewardTimes", ToStringTlog(RewardTimes)); 
        AddLog("KillCount", ToStringTlog(KillCount)); 
        AddLog("LeaveCount", ToStringTlog(LeaveCount)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("Rank", ToStringTlog(Rank)); 
        AddLog("Times", ToStringTlog(Times)); 
        AddLog("HuntingLevel", ToStringTlog(HuntingLevel)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"RewardTimes\":"+ ToStringTlog(RewardTimes)); 
        AddLogJson("\"KillCount\":"+ ToStringTlog(KillCount)); 
        AddLogJson("\"LeaveCount\":"+ ToStringTlog(LeaveCount)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"Rank\":"+ ToStringTlog(Rank)); 
        AddLogJson("\"Times\":"+ ToStringTlog(Times)); 
        AddLogJson("\"HuntingLevel\":"+ ToStringTlog(HuntingLevel)); 

    }
    const char * GetTableName() override
    {
        return "UnionHuntingFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionHuntingFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t TeamID {0};
    int32_t DutyType {0};
    int32_t RewardTimes {0};
    int32_t KillCount {0};
    int32_t LeaveCount {0};
    int32_t Score {0};
    int32_t Rank {0};
    int32_t Times {0};
    int32_t HuntingLevel {0};
    
};
namespace UnionMemberFlowEnum{

    enum class OperateType: uint32_t {
        ADD = 0,//加入
        KICK = 1,//逐出
        APPOINT = 2,//任命
        DISAPPOINT = 3,//卸任 
    };    
    enum class OperaterType: uint32_t {
        CHAIRMAN = 0,//会长
        VICECHAIRMAN = 1,//执事
        COMMON = 2,//会员 
    };    
}

class UnionMemberFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("UnionLevel", ToStringTlog(UnionLevel)); 
        AddLog("UnionMessage", UnionMessage); 
        AddLog("UnionMembers", ToStringTlog(UnionMembers)); 
        AddLog("UnionMoney", ToStringTlog(UnionMoney)); 
        AddLog("UnionActive", ToStringTlog(UnionActive)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("JoinType", ToStringTlog(JoinType)); 
        AddLog("DutyType", ToStringTlog(DutyType)); 
        AddLog("UnionDonate", ToStringTlog(UnionDonate)); 
        AddLog("OperaterType", ToStringTlog(OperaterType)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("FriendPoints", ToStringTlog(FriendPoints)); 
        AddLog("tRoleActive", ToStringTlog(tRoleActive)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"UnionLevel\":"+ ToStringTlog(UnionLevel)); 
        AddLogJson("\"UnionMessage\":\""+UnionMessage+"\""); 
        AddLogJson("\"UnionMembers\":"+ ToStringTlog(UnionMembers)); 
        AddLogJson("\"UnionMoney\":"+ ToStringTlog(UnionMoney)); 
        AddLogJson("\"UnionActive\":"+ ToStringTlog(UnionActive)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"JoinType\":"+ ToStringTlog(JoinType)); 
        AddLogJson("\"DutyType\":"+ ToStringTlog(DutyType)); 
        AddLogJson("\"UnionDonate\":"+ ToStringTlog(UnionDonate)); 
        AddLogJson("\"OperaterType\":"+ ToStringTlog(OperaterType)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"FriendPoints\":"+ ToStringTlog(FriendPoints)); 
        AddLogJson("\"tRoleActive\":"+ ToStringTlog(tRoleActive)); 

    }
    const char * GetTableName() override
    {
        return "UnionMemberFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionMemberFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t UnionLevel {0};
    std::string UnionMessage {""};
    int32_t UnionMembers {0};
    int32_t UnionMoney {0};
    int32_t UnionActive {0};
    int32_t OperateType {0};
    int32_t JoinType {0};
    int32_t DutyType {0};
    int32_t UnionDonate {0};
    int32_t OperaterType {0};
    int32_t FriendJudge {0};
    int32_t FriendPoints {0};
    int32_t tRoleActive {0};
    
};
namespace UnionTasteFlowEnum{

}

class UnionTasteFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 
        AddLog("CookName", CookName); 
        AddLog("PreCount", ToStringTlog(PreCount)); 
        AddLog("AfterCount", ToStringTlog(AfterCount)); 
        AddLog("RandomEventID", ToStringTlog(RandomEventID)); 
        AddLog("RandomEventName", RandomEventName); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 
        AddLogJson("\"CookName\":\""+CookName+"\""); 
        AddLogJson("\"PreCount\":"+ ToStringTlog(PreCount)); 
        AddLogJson("\"AfterCount\":"+ ToStringTlog(AfterCount)); 
        AddLogJson("\"RandomEventID\":"+ ToStringTlog(RandomEventID)); 
        AddLogJson("\"RandomEventName\":\""+RandomEventName+"\""); 

    }
    const char * GetTableName() override
    {
        return "UnionTasteFlow"; 
    }
    static const char * TableName() 
    {
        return "UnionTasteFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    std::string CookName {""};
    int32_t PreCount {0};
    int32_t AfterCount {0};
    int32_t RandomEventID {0};
    std::string RandomEventName {""};
    
};
namespace WatchPlayFlowEnum{

}

class WatchPlayFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("WatchPlayAct", ToStringTlog(WatchPlayAct)); 
        AddLog("RoomID", ToStringTlog(RoomID)); 
        AddLog("RoomCreateTime", RoomCreateTime); 
        AddLog("RoomLifeTime", ToStringTlog(RoomLifeTime)); 
        AddLog("RoomTimeLeft", ToStringTlog(RoomTimeLeft)); 
        AddLog("WatchPlayType", ToStringTlog(WatchPlayType)); 
        AddLog("WatchPlayID", ToStringTlog(WatchPlayID)); 
        AddLog("WatchPlayName", WatchPlayName); 
        AddLog("StageID", ToStringTlog(StageID)); 
        AddLog("AudienceNum", ToStringTlog(AudienceNum)); 
        AddLog("LikesNum", ToStringTlog(LikesNum)); 
        AddLog("PlayTimesNum", ToStringTlog(PlayTimesNum)); 
        AddLog("RecommendIndex", ToStringTlog(RecommendIndex)); 
        AddLog("FriendJudge", ToStringTlog(FriendJudge)); 
        AddLog("UnionJudge", ToStringTlog(UnionJudge)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"WatchPlayAct\":"+ ToStringTlog(WatchPlayAct)); 
        AddLogJson("\"RoomID\":"+ ToStringTlog(RoomID)); 
        AddLogJson("\"RoomCreateTime\":\""+RoomCreateTime+"\""); 
        AddLogJson("\"RoomLifeTime\":"+ ToStringTlog(RoomLifeTime)); 
        AddLogJson("\"RoomTimeLeft\":"+ ToStringTlog(RoomTimeLeft)); 
        AddLogJson("\"WatchPlayType\":"+ ToStringTlog(WatchPlayType)); 
        AddLogJson("\"WatchPlayID\":"+ ToStringTlog(WatchPlayID)); 
        AddLogJson("\"WatchPlayName\":\""+WatchPlayName+"\""); 
        AddLogJson("\"StageID\":"+ ToStringTlog(StageID)); 
        AddLogJson("\"AudienceNum\":"+ ToStringTlog(AudienceNum)); 
        AddLogJson("\"LikesNum\":"+ ToStringTlog(LikesNum)); 
        AddLogJson("\"PlayTimesNum\":"+ ToStringTlog(PlayTimesNum)); 
        AddLogJson("\"RecommendIndex\":"+ ToStringTlog(RecommendIndex)); 
        AddLogJson("\"FriendJudge\":"+ ToStringTlog(FriendJudge)); 
        AddLogJson("\"UnionJudge\":"+ ToStringTlog(UnionJudge)); 

    }
    const char * GetTableName() override
    {
        return "WatchPlayFlow"; 
    }
    static const char * TableName() 
    {
        return "WatchPlayFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t WatchPlayAct {0};
    int64_t RoomID {0};
    std::string RoomCreateTime {""};
    int32_t RoomLifeTime {0};
    int32_t RoomTimeLeft {0};
    int32_t WatchPlayType {0};
    int32_t WatchPlayID {0};
    std::string WatchPlayName {""};
    int32_t StageID {0};
    int32_t AudienceNum {0};
    int32_t LikesNum {0};
    int32_t PlayTimesNum {0};
    int32_t RecommendIndex {0};
    int32_t FriendJudge {0};
    int32_t UnionJudge {0};
    
};
namespace WheelFlowEnum{

}

class WheelFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("OperateType", ToStringTlog(OperateType)); 
        AddLog("WheelID", ToStringTlog(WheelID)); 
        AddLog("WheelName", WheelName); 
        AddLog("WheelType", ToStringTlog(WheelType)); 
        AddLog("WheelLevel", ToStringTlog(WheelLevel)); 
        AddLog("AttrLevel", ToStringTlog(AttrLevel)); 
        AddLog("WheelSkill1", ToStringTlog(WheelSkill1)); 
        AddLog("WheelSkill2", ToStringTlog(WheelSkill2)); 
        AddLog("WheelWeight", ToStringTlog(WheelWeight)); 
        AddLog("ComposeType", ToStringTlog(ComposeType)); 
        AddLog("ComposeAttr1", ComposeAttr1); 
        AddLog("ComposeAttr2", ComposeAttr2); 
        AddLog("ComposeAttr3", ComposeAttr3); 
        AddLog("ComposeAttr4", ComposeAttr4); 
        AddLog("ComposeAttrAfter", ComposeAttrAfter); 
        AddLog("AttrResetBefore", AttrResetBefore); 
        AddLog("AttrResetAfter", AttrResetAfter); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"OperateType\":"+ ToStringTlog(OperateType)); 
        AddLogJson("\"WheelID\":"+ ToStringTlog(WheelID)); 
        AddLogJson("\"WheelName\":\""+WheelName+"\""); 
        AddLogJson("\"WheelType\":"+ ToStringTlog(WheelType)); 
        AddLogJson("\"WheelLevel\":"+ ToStringTlog(WheelLevel)); 
        AddLogJson("\"AttrLevel\":"+ ToStringTlog(AttrLevel)); 
        AddLogJson("\"WheelSkill1\":"+ ToStringTlog(WheelSkill1)); 
        AddLogJson("\"WheelSkill2\":"+ ToStringTlog(WheelSkill2)); 
        AddLogJson("\"WheelWeight\":"+ ToStringTlog(WheelWeight)); 
        AddLogJson("\"ComposeType\":"+ ToStringTlog(ComposeType)); 
        AddLogJson("\"ComposeAttr1\":\""+ComposeAttr1+"\""); 
        AddLogJson("\"ComposeAttr2\":\""+ComposeAttr2+"\""); 
        AddLogJson("\"ComposeAttr3\":\""+ComposeAttr3+"\""); 
        AddLogJson("\"ComposeAttr4\":\""+ComposeAttr4+"\""); 
        AddLogJson("\"ComposeAttrAfter\":\""+ComposeAttrAfter+"\""); 
        AddLogJson("\"AttrResetBefore\":\""+AttrResetBefore+"\""); 
        AddLogJson("\"AttrResetAfter\":\""+AttrResetAfter+"\""); 

    }
    const char * GetTableName() override
    {
        return "WheelFlow"; 
    }
    static const char * TableName() 
    {
        return "WheelFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t OperateType {0};
    int32_t WheelID {0};
    std::string WheelName {""};
    int32_t WheelType {0};
    int32_t WheelLevel {0};
    int32_t AttrLevel {0};
    int32_t WheelSkill1 {0};
    int32_t WheelSkill2 {0};
    int32_t WheelWeight {0};
    int32_t ComposeType {0};
    std::string ComposeAttr1 {""};
    std::string ComposeAttr2 {""};
    std::string ComposeAttr3 {""};
    std::string ComposeAttr4 {""};
    std::string ComposeAttrAfter {""};
    std::string AttrResetBefore {""};
    std::string AttrResetAfter {""};
    
};
namespace YggdrasillDefActFlowEnum{

}

class YggdrasillDefActFlow : public RoleCommonTlogBase
{
public:
    virtual void DoAdd() override
    {
        AddLog("vGameSvrId", vGameSvrId); 
        AddLog("dtEventTime", dtEventTime); 
        AddLog("vGameAppid", vGameAppid); 
        AddLog("PlatID", ToStringTlog(PlatID)); 
        AddLog("iZoneAreaID", ToStringTlog(iZoneAreaID)); 
        AddLog("vopenid", vopenid); 
        AddLog("vRoleId", vRoleId); 
        AddLog("vRoleName", vRoleName); 
        AddLog("JobId", ToStringTlog(JobId)); 
        AddLog("Gender", ToStringTlog(Gender)); 
        AddLog("Level", ToStringTlog(Level)); 
        AddLog("iJobLevel", ToStringTlog(iJobLevel)); 
        AddLog("PlayerFriendsNum", ToStringTlog(PlayerFriendsNum)); 
        AddLog("ChargeGold", ToStringTlog(ChargeGold)); 
        AddLog("RoleVip", ToStringTlog(RoleVip)); 
        AddLog("CreateTime", CreateTime); 
        AddLog("Power", ToStringTlog(Power)); 
        AddLog("UnionID", ToStringTlog(UnionID)); 
        AddLog("UnionName", UnionName); 
        AddLog("RegChannel", ToStringTlog(RegChannel)); 
        AddLog("LoginChannel", ToStringTlog(LoginChannel)); 
        AddLog("DungeonType", ToStringTlog(DungeonType)); 
        AddLog("DungeonStatusID", ToStringTlog(DungeonStatusID)); 
        AddLog("TeamID", ToStringTlog(TeamID)); 
        AddLog("MemberType", ToStringTlog(MemberType)); 
        AddLog("Roles", ToStringTlog(Roles)); 
        AddLog("Ais", ToStringTlog(Ais)); 
        AddLog("DeadTimes", ToStringTlog(DeadTimes)); 
        AddLog("ActType", ToStringTlog(ActType)); 
        AddLog("ServantType", ToStringTlog(ServantType)); 
        AddLog("ServantID", ToStringTlog(ServantID)); 
        AddLog("OrderID", ToStringTlog(OrderID)); 
        AddLog("MPBefore", ToStringTlog(MPBefore)); 
        AddLog("MPAfter", ToStringTlog(MPAfter)); 
        AddLog("TreeLife", ToStringTlog(TreeLife)); 
        AddLog("Waves", ToStringTlog(Waves)); 
        AddLog("DefTime", ToStringTlog(DefTime)); 
        AddLog("Score", ToStringTlog(Score)); 
        AddLog("BlessingDefenseID", ToStringTlog(BlessingDefenseID)); 
        AddLog("BlessingAttackID", ToStringTlog(BlessingAttackID)); 
        AddLog("TalentID", ToStringTlog(TalentID)); 

    }
    virtual void DoAddJson() override
    {
        AddLogJson("\"vGameSvrId\":\""+vGameSvrId+"\""); 
        AddLogJson("\"dtEventTime\":\""+dtEventTime+"\""); 
        AddLogJson("\"vGameAppid\":\""+vGameAppid+"\""); 
        AddLogJson("\"PlatID\":"+ ToStringTlog(PlatID)); 
        AddLogJson("\"iZoneAreaID\":"+ ToStringTlog(iZoneAreaID)); 
        AddLogJson("\"vopenid\":\""+vopenid+"\""); 
        AddLogJson("\"vRoleId\":\""+vRoleId+"\""); 
        AddLogJson("\"vRoleName\":\""+vRoleName+"\""); 
        AddLogJson("\"JobId\":"+ ToStringTlog(JobId)); 
        AddLogJson("\"Gender\":"+ ToStringTlog(Gender)); 
        AddLogJson("\"Level\":"+ ToStringTlog(Level)); 
        AddLogJson("\"iJobLevel\":"+ ToStringTlog(iJobLevel)); 
        AddLogJson("\"PlayerFriendsNum\":"+ ToStringTlog(PlayerFriendsNum)); 
        AddLogJson("\"ChargeGold\":"+ ToStringTlog(ChargeGold)); 
        AddLogJson("\"RoleVip\":"+ ToStringTlog(RoleVip)); 
        AddLogJson("\"CreateTime\":\""+CreateTime+"\""); 
        AddLogJson("\"Power\":"+ ToStringTlog(Power)); 
        AddLogJson("\"UnionID\":"+ ToStringTlog(UnionID)); 
        AddLogJson("\"UnionName\":\""+UnionName+"\""); 
        AddLogJson("\"RegChannel\":"+ ToStringTlog(RegChannel)); 
        AddLogJson("\"LoginChannel\":"+ ToStringTlog(LoginChannel)); 
        AddLogJson("\"DungeonType\":"+ ToStringTlog(DungeonType)); 
        AddLogJson("\"DungeonStatusID\":"+ ToStringTlog(DungeonStatusID)); 
        AddLogJson("\"TeamID\":"+ ToStringTlog(TeamID)); 
        AddLogJson("\"MemberType\":"+ ToStringTlog(MemberType)); 
        AddLogJson("\"Roles\":"+ ToStringTlog(Roles)); 
        AddLogJson("\"Ais\":"+ ToStringTlog(Ais)); 
        AddLogJson("\"DeadTimes\":"+ ToStringTlog(DeadTimes)); 
        AddLogJson("\"ActType\":"+ ToStringTlog(ActType)); 
        AddLogJson("\"ServantType\":"+ ToStringTlog(ServantType)); 
        AddLogJson("\"ServantID\":"+ ToStringTlog(ServantID)); 
        AddLogJson("\"OrderID\":"+ ToStringTlog(OrderID)); 
        AddLogJson("\"MPBefore\":"+ ToStringTlog(MPBefore)); 
        AddLogJson("\"MPAfter\":"+ ToStringTlog(MPAfter)); 
        AddLogJson("\"TreeLife\":"+ ToStringTlog(TreeLife)); 
        AddLogJson("\"Waves\":"+ ToStringTlog(Waves)); 
        AddLogJson("\"DefTime\":"+ ToStringTlog(DefTime)); 
        AddLogJson("\"Score\":"+ ToStringTlog(Score)); 
        AddLogJson("\"BlessingDefenseID\":"+ ToStringTlog(BlessingDefenseID)); 
        AddLogJson("\"BlessingAttackID\":"+ ToStringTlog(BlessingAttackID)); 
        AddLogJson("\"TalentID\":"+ ToStringTlog(TalentID)); 

    }
    const char * GetTableName() override
    {
        return "YggdrasillDefActFlow"; 
    }
    static const char * TableName() 
    {
        return "YggdrasillDefActFlow"; 
    }
    const std::string GetVersion()
    {
        return "1.0"; 
    }
public:
    int32_t DungeonType {0};
    int32_t DungeonStatusID {0};
    int32_t TeamID {0};
    int32_t MemberType {0};
    int32_t Roles {0};
    int32_t Ais {0};
    int32_t DeadTimes {0};
    int32_t ActType {0};
    int32_t ServantType {0};
    int32_t ServantID {0};
    int32_t OrderID {0};
    int32_t MPBefore {0};
    int32_t MPAfter {0};
    int32_t TreeLife {0};
    int32_t Waves {0};
    int32_t DefTime {0};
    int32_t Score {0};
    int32_t BlessingDefenseID {0};
    int32_t BlessingAttackID {0};
    int32_t TalentID {0};
    
};

#endif
