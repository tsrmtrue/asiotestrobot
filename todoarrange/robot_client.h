#ifndef __ROBOT_CLIENT_H__
#define __ROBOT_CLIENT_H__
#include <deque>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <random>
#include "asio.hpp"
#include "pb/pbc_unclassified.pb.h"
#include "pb/pbc_battle.pb.h"
#include "pb/pbc_team.pb.h"
#include "robot_component/robot_team_component.h"
#include "rogamelibs/utility/math/vector3.h"
#include "http_handler.h"
#include "protocol_wrap.h"
#include "table/template/task_table.h"
#include <list>
#include <array>
#include "robot_define.h"
#include "robot_component/robot_task_com.h"
#include "robot_component/robot_io_com.h"
#include "robot_component/robot_move_com.h"
#include "robot_component/robot_sync_com.h"
#include "robot_component/robot_role_com.h"
#include "robot_component/robot_singing_com.h"
//#include "utility/math/vector3.h"

using asio::ip::tcp;
using TaskRowData = TableLib::TaskTable::RowData;
class CWorkFrame;
class RoRobot;
class CTask;
class CIO;
class CMove;
class CSync;
class CRole;
class CSinging;

class CRobotClient
{
	//采用行为树做机器人行为
public:
	CRobotClient(uint32_t id, asio::io_service& io_service, std::string accountname,int sleep)
		: timer_(io_service),
		account_name_(accountname), 
        robot_id_(id)
	{

        start_next_bt_timepoint_ = std::chrono::system_clock::now();;
        team_com.SetRobot(this);
		//TryConnect(endpoint_iterator);
		//启动定时器
		timer_.expires_from_now(std::chrono::milliseconds(sleep));
		timer_.async_wait([this](const asio::error_code& error) {this->OnTimer(error); });
#ifdef WIN32
#else
        WetestHttpHandler::Instance()->statistic_robot.robot_total_num++;
#endif
        module_list_.resize(RobotModuleBase::GetModuleCount());
        Add<CTask>(*this);
        Add<CIO>(*this, io_service);
        Add<CMove>(*this);
        Add<CSync>(*this);
        Add<CRole>(*this);
        Add<CSinging>(*this);
	}
    ~CRobotClient() 
    {
        for (auto &module : module_list_)
        {
            delete module;
        }
        module_list_.clear();
    }

	bool ParseBTFromXml(std::string xmlFile);


    // 模块组

    template <typename T, typename ...Args>
    T * Add(Args && ...args)
    {
        auto module = new T(std::forward<Args>(args)...);
        module_list_[T::kModuleType] = module;
        return module;
    }
    template <typename T>
    T * Get()
    {
        return static_cast<T *>(module_list_[T::kModuleType]);
    }
    template <typename T>
    const T * Get() const
    {
        return static_cast<T *>(module_list_[T::kModuleType]);
    }

private:
    CRobotClient &robot_client_ = *this;
    std::vector<RobotModuleBase *> module_list_;

public:
    

    static std::map<uint32_t, std::vector<uint32_t>> all_skill_id;
    static std::vector<uint32_t> all_scene_id;
    static std::map<uint32_t, std::vector<float>> all_skill_sing_time;
    static std::map<uint32_t, uint32_t> all_skill_target;
    static std::map<uint32_t, std::vector<uint32_t>> all_barber;
    static std::map<uint32_t, std::vector<uint32_t>> all_eye;
    static std::map<uint32_t, KKSG::Vec3> all_field_map;
    static std::vector<uint32_t> all_field_id;
    static std::map<uint32_t, std::vector<std::pair<uint32_t, uint32_t>>> patrol_way;
    static std::map<uint32_t, std::vector<std::pair<uint32_t, uint32_t>>> patrol_gate;
    static std::vector<uint32_t> patrol_scene;
    static int profession_tree[10000];
    static uint32_t eye_style;


    void CreateRandomName();
    void SetAccountName(std::string name)
    {
        account_name_ = name;
    }

    static uint32_t added_account_count_;//本次新创建的账户数量

    static uint32_t added_role_count_;//本次新创建的角色数量
public:
    void IncreaseAccountCount() { added_account_count_++; }
    uint32_t GetAccountCount() { return added_account_count_; }
    void IncreaseRoleCount() { added_role_count_++; }
    uint32_t GetRoleCount() { return added_role_count_; }
public:
    KKSG::RoleType GetRoleType()
    {
        return (KKSG::RoleType)(select_role_ntf_data_.roledata().brief().type());
    }
    void StartRpc();
    bool IsRpcLate(uint32_t cd);//true  rpc调用超时
    uint32_t GetRobotId() { return  robot_id_;    }
	//给行为树调用的函数
	void Connect2Server(std::string ip, int16_t port);
	void SendClientLoginRequest(int serverid);
	// bool WaitClientLoginRequest();
	// bool WaitQueryGateIP();
	// bool WaitSelectRole();
	bool WaitSelectRoleNtf();
	void SendMoveRandom();
	void SendCreateRole();
	bool WaitCreateRole();
	void SendLocalGMCmd(std::string gmcmd);
    void SendGMCmdGotoMonsterPos();
    void SendGMCmdAddBuff();
	void TestRandom();
	void BuildRandomTarget();
	void SendMove2Target();
	bool WaitShowMessage();
	void SetMoveTarget(int x, int y);
    void ChooseTargetMonsterRandomly();
    bool ChooseTargetMonsterByHurt();
    void ChooseNearestMonster();
    void ChooseTargetRoleRandomly();
    void UpdateTargetHurt(uint64_t target_id, int32_t hurt);
	bool CheckMove2Target();
    // void ClearLastNetMessage();
    bool SendSingingArg(int skilleffectid, SUnitSimple monster);
    bool SendSinging(int skilleffectid);
    bool SendSingingNoTarget(int skilleffectid);
    void SendSingingArgNormal();
    void SendSingingArgRandom();
    bool SendSingingArgNonRandom();
	bool WaitSingingRes();
	void UpdateTargetPostion();
	bool CheckTargetMonsterDead();
	void SendRoleReviveArg();
	bool WaitRoleReviveRes();
    int CheckSkillTargetType();
    void TakeAndFinishTasks();
    void InitGetAllTaskId();
    bool TakeAndFinishOneTaskFromTable();
    bool HasCurrentTask();
    bool HasTaskAcceptable();
    bool HasTaskFinished();
    bool GmFinishCurrentTask();
    bool GmContinueCurrentTask();
    bool GmAddItem();
    bool GmTakeFirstAcceptableTask();
    bool CheckTask();
    void PrintListStatus();


    void SendEasyNavigateToTarget();
    int WaitSingTimePVP();
    void CreateArenaPvpCustom();
    // bool WaitCreateArenaPvpCustom();

    bool WaitSyncArenaRoomBriefInfoNtf();
    void SendAutoPairOperateWithArgs();

    void SetMonsterInPvP(const KKSG::ArenaRoomInfo & m_Data, int group_id);
    void AddMonster();
    void EnterDungeons();
//==scene=================================
    void BuildTeamFull();
    
//========================================

    static int RandomBetween0And100();

//==scene=================================
    bool WaitEnterSceneNtf();
    // bool WaitDoEnterScene();
    void SendEnterSceneRequest(int sceneid);
    void JumpToScene();
    void SwitchSceneRandom();
    void ChangScene(uint32_t scene_id);
    void GetNextPatrol();
    void SendCaptainRequestEnter();
    void SendMemberReplyEnter();

    uint32_t WaitRobotInBattleField();
    void BeginMatchForBattleField();
    void QueryRobotTeamBattle();
    uint32_t WaitBeginMatchForBattleField();
    bool WaitAskMemberEnterFBNtf();

    ROGameLibs::Vector3 RandomPostion(uint32_t scene_id, float x, float z);
    std::string RobotSceneTypeRandom();
    std::string RobotSceneTypeBattle(uint32_t type);
    std::string RobotSceneTypePatrol();
    std::string RobotSceneTypeBattleField();
    int GetCurrentSceneId();
    int GetCurrentDungeonId();
    //发送当前触发器触发

//========================================

    const TeamComponent& GetTeamCom() const { return team_com; }

//==role==================================
    bool CheckRoleCreated();
    bool CheckRoleDead();
    bool CheckRoleType();
    bool CheckRoleIsPvP();
    bool CheckRoleBattleField();
    void RoleTransprofessionOneTurn();
    bool CheckRoleMoveChangeScene();
    bool CheckROleLogin();
    bool CheckRoleSelect();
    bool CheckRolePosition();
    bool CheckRoleHasTarget();
    void UpdateRoleFace();
    void PrepareRoleForSecondTurn();
    void AddRoleQuality(int attr,int max_attr);
    void PrepareRoleQualityRandomly();
    void PrepareRoleEquip();
    void PrepareRoleEquipRandom();
    void PrepareRoleEquipNotRandom();
    void AddItemForSkill();
    void ChangeRoleName();
    void MakeRobotType();
//========================================

//==move==================================
    void GetRoad();
    void GoNextRoad(Road& current_road, int dir);
    Road CheckNextRoad(Road& current_road, int dir);
    float GetDirToTarget(Road& current_road);
    float CheckValidRoad(Road& current_road);
    void GMJump2Target();
    void SetLocalPos(float x, float y, float z);

//========================================

//==auto==================================
    bool SendStepOneByOne(uint32_t now_index);
//===================================

    void SendSyncTime();

    void SendQueryGateIP();

    void SendGetVersion();

    void SendRpcC2V_GetVersionTest();

    void SendClientLoginRequest();

    void SendCreateRoleNew();

    void SendSelectRole();

    void SendDoEnterScene();

    void SendCreateTeam();

    void SendAcceptTeamInvatation();

    void SendInviteJoinTeam();

    void SendBegJoinTeam();

    void SendLeaveTeam();

    void SendGetApplicationList();

    void SendKickTeamMember();

    void SendTeamSetting();

    void SendGetTeamInfo();

    bool SendEquipItem();

    bool SendTakeOffEquip();

    void SendUnlockBlank();

    void SendJunkItem();

    void SendMoveItem();

    void SendClearTempBag();

    void SendFetchTempBag();

    void SendTransferProfession();

    void SendSkillPoint();

    void SendSkillSlot();

    void SendAttrAdd();

    void SendAttrClear();

    void SendAttrModule();

    void SendSetLevel();

    void SendAddExp();

    void SendSingingRequest();

    void SendUseItem();

    void SendRoleRevive();

    void SendTaskAccept();

    void SendTaskFinish();

    void SendChangeWarehouseName();

    void SendWearFashion();

    void SendPickUpItem();

    void SendCreateArenaPvpCustom();

    void SendActiveJoinArenaRoom();

    void SendShowArenaRoomList();

    void SendChangeArenaRoomCondition();

    void SendGetMVPInfo();

    void SendGetMVPRankInfo();

    void SendWearOrnament();

    void SendAppraiseEquip();

    void SendChatSenderInfo();

    void SendChangeHair();

    void SendTaskReport();

    void SendSendHorn();

    void SendReconnect();

    void SendTaskSceneTriggerEventModify();

    void SendChangeEye();

    void SendExchangeMoney();

    void SendOpenSystemReward();

    void SendTakeVehicle();

    void SendGetOnVehicleAgree();

    void SendAskTakeVehicle();

    void SendQueryIsInTeam();

    void SendFollowOthers();

    void SendAcceptBegJoinTeam();

    void SendTaskGiveup();

    void SendTaskOpenEden();

    void SendNearbyMap();

    void SendEasyNavigate();

    void SendTaskTrackGotoDungeon();

    void SendRequestShopItem();

    void SendRequestBuyShopItem();

    void SendRequestSellShopItem();

    void SendAccelerateVehicle();

    void SendEnterSceneWall();

    void SendSingleCookingStart();

    void SendSingleCookingFinish();

    void SendSkillReset();

    void SendForgeEquip();

    void SendDailyActivityShow();

    void SendRideCommonVehicle();

    void SendGetInvitationList();

    void SendRequestTransfigure();

    void SendQueryRoleBriefInfo();

    void SendAutoPairOperate(int a);

    void SendGetTeamList();

    void SendTeamShout();

    void SendToBeFollowed();

    void SendReplyToBeFollowed();

    void SendQueryAutoPairStatus();

    void SendGetCountInfo();

    void SendGetTradeInfo();

    void SendTradeBuyItem();

    void SendTradeSellItem();

    void SendEquipRefineUpgrade();

    void SendEquipRefineRepair();

    void SendCollectRequest();

    void SendStopState();

    void SendBattlefieldApply();

    void SendGetValidName();

    void SendAddFriend();

    void SendDeleteFriend();

    void SendReadPrivateMessage();

    void SendPullChatMsg();

    void SendGetFriendInfo();

    void SendGuildCreate();

    void SendGuildGetInfo();

    void SendGuildGetList();

    void SendGuildSearch();

    void SendGuildApply();

    void SendGuildDeclarationChange();

    void SendGuildAnnounceChange();

    void SendGuildQueryMemberList();

    void SendGuildMemberSearch();

    void SendGuildChangePermission();

    void SendGuildKickOutMember();

    void SendGuildGetApplicationList();

    void SendGuildApplyReplay();

    void SendGuildAutoApprovalApply();

    void SendGuildQuit();

    void SendGuildIconChange();

    void SendGetStaticSceneLine();

    void SendChangeSceneLine();

    void SendEquipEnchant();

    void SendEquipEnchantConfirm();

    void SendGetServerLevelBonusInfo();

    void SendAwardPreview();

    void SendExchangeHeadGear();

    void SendGetMailList();

    void SendMailOp();

    void SendGetOneMail();

    void SendStallGetMarkInfo();

    void SendStallGetItemInfo();

    bool IsStallBuyHaveItem();

    void SendStallItemBuy();

    void SendStallRefresh();

    void SendStallGetSellInfo();

    void SendStallGetPreSellItemInfo();

    void SendStallSellItem();

    bool IsStallSellItemNeedCancel();

    void SendStallSellItemCancel();

    void SendStallDrawMoney();

    void SendStallBuyStallCount();

    void SendStallReSellItem();

    void SendHSUsedAwardTimesDungeon();

    void SendHSQueryRoundInfo();

    void SendGuildGetNewsInfo();

    void SendEquipCardInsert();

    void SendEquipCardRemove();

    void SendEquipMakeHole();

    void SendEquipReformMake();

    void SendDrawBoLiPointAward();

    void SendQueryRandomAwardStart();

    void SendGiveGifts();

    void SendGetGiftLimitInfo();

    void SendSevenLoginActivityGetReward();

    void SendSevenLoginActivityGetInfo();

    void SendYuanQiRequest();

    void SendLifeSkillFishing();

    void SendSaveReviveRecord();

    void SendTrialDungeonChooseProfession();

    void SendDailyActivityShowToMS();

    void SendLifeEquipChange();

    void SendBlessOperation();

    void SendGetBlessInfo();

    void SendSortBag();

    void SendChatMsg(unsigned int channel);

    void SendRoleSearch();

    void SendRecommandMember();

    void SendDirTeleport();

    void SendDoubleActiveApply();

    void SendDoubleActiveAgree();

    void SendGuildPermissionNameChange();

    void SendEquipCompound();

    void SendGetItemByUid();

    void SendJudgeTextForbid();

    void SendGsChangeRoleName();

    void SendUnLockRoleIllutration();

    void SendBeginMatchForBattleField();

    void SendGuildGetBuildingInfo();

    void SendGuildUpBuildingLevel();

    void SendGuildDonateMaterials();

    void SendGuildDonateMoney();

    void SendDoubleActiveEnd();

    void SendMaterialsMechant();

    void SendKeepAlivePingAck();

    void SendDelayNotify();

    void SendMoveOperationReq();

    void SendHandoverCaptainReq();

    void SendClearApplicationListReq();

    void SendEnterSceneReq();

    void SendLocalGMCmd();

    void SendPushIntoArenaPvpCustom();

    void SendLeaveFromArenaPvpRoom();

    void SendSendChattingMsg();

    void SendEnterDungeons();

    void SendBroadcastTakePhotoStatus();

    void SendSetRoleSelfyStatus();

    void SendTeleportItem();

    void SendEasyPathDestinationNtf();

    void SendEasyPathForgiveNtf();

    void SendMemberReplyEnterFBPtc();

    void SendCaptainRequestEnterFBPtc(uint32_t dungeon_id);

    void SendLeaveSceneReq();

    void SendDungeonsEncourage();

    void SendCookFoodOperationPtc();

    void SendTradeKeepAliveNotify();

    void SendReqLeaveSceneWall();

    void SendSendPrivateChatMsg();

    void SendStopFollow();

    void SendClientLogout();

    void SendPhotoFlowNewTlog();

    void SendApplyForCaptainNtf();

    void SendTeamAfkNtf();

    void SendSendDebugLog();

    void SendDoubleActiveRefuse();

    void SendDoubleActiveRevoke();

    void SendEnterGuildScene();

    void SendTssSdkAntiDataUpload();

    void SendSetAchievementFocus();


//===================================


    bool WaitSyncTime();

    bool WaitQueryGateIP();

    bool WaitGetVersion();

    bool WaitRpcC2V_GetVersionTest();

    bool WaitClientLoginRequest();

    bool WaitCreateRoleNew();

    bool WaitSelectRole();

    bool WaitDoEnterScene();

    bool WaitCreateTeam();

    bool WaitAcceptTeamInvatation();

    bool WaitInviteJoinTeam();

    bool WaitBegJoinTeam();

    bool WaitLeaveTeam();

    bool WaitGetApplicationList();

    bool WaitKickTeamMember();

    bool WaitTeamSetting();

    bool WaitGetTeamInfo();

    bool WaitEquipItem();

    bool WaitTakeOffEquip();

    bool WaitUnlockBlank();

    bool WaitJunkItem();

    bool WaitMoveItem();

    bool WaitClearTempBag();

    bool WaitFetchTempBag();

    bool WaitTransferProfession();

    bool WaitSkillPoint();

    bool WaitSkillSlot();

    bool WaitAttrAdd();

    bool WaitAttrClear();

    bool WaitAttrModule();

    bool WaitSingingRequest();

    bool WaitUseItem();

    bool WaitRoleRevive();

    bool WaitTaskCheck();

    bool WaitTargetFinish();

    bool WaitTaskAccept();

    bool WaitTaskFinish();

    bool WaitChangeWarehouseName();

    bool WaitWearFashion();

    bool WaitPickUpItem();

    bool WaitCreateArenaPvpCustom();

    bool WaitActiveJoinArenaRoom();

    bool WaitShowArenaRoomList();

    bool WaitChangeArenaRoomCondition();

    bool WaitGetMVPInfo();

    bool WaitGetMVPRankInfo();

    bool WaitWearOrnament();

    bool WaitChatSenderInfo();

    bool WaitChangeHair();

    bool WaitTaskReport();

    bool WaitSendHorn();

    bool WaitReconnect();

    bool WaitTaskSceneTriggerEventModify();

    bool WaitChangeEye();

    bool WaitExchangeMoney();

    bool WaitOpenSystemReward();

    bool WaitTakeVehicle();

    bool WaitGetOnVehicleAgree();

    bool WaitAskTakeVehicle();

    bool WaitQueryIsInTeam();

    bool WaitFollowOthers();

    bool WaitAcceptBegJoinTeam();

    bool WaitTaskGiveup();

    bool WaitTaskOpenEden();

    bool WaitNearbyMap();

    bool WaitEasyNavigate();

    bool WaitTaskTrackGotoDungeon();

    bool WaitRequestShopItem();

    bool WaitRequestBuyShopItem();

    bool WaitRequestSellShopItem();

    bool WaitAccelerateVehicle();

    bool WaitEnterSceneWall();

    bool WaitSingleCookingStart();

    bool WaitSingleCookingFinish();

    bool WaitSkillReset();

    bool WaitForgeEquip();

    bool WaitDailyActivityShow();

    bool WaitRideCommonVehicle();

    bool WaitGetInvitationList();

    bool WaitQueryRoleBriefInfo();

    bool WaitAutoPairOperate();

    bool WaitGetTeamList();

    bool WaitTeamShout();

    bool WaitToBeFollowed();

    bool WaitReplyToBeFollowed();

    bool WaitQueryAutoPairStatus();

    bool WaitGetCountInfo();

    bool WaitGetTradeInfo();

    bool WaitTradeBuyItem();

    bool WaitTradeSellItem();

    bool WaitEquipRefineUpgrade();

    bool WaitEquipRefineRepair();

    bool WaitCollectRequest();

    bool WaitStopState();

    bool WaitBattlefieldApply();

    bool WaitGetValidName();

    bool WaitAddFriend();

    bool WaitDeleteFriend();

    bool WaitReadPrivateMessage();

    bool WaitPullChatMsg();

    bool WaitGetFriendInfo();

    bool WaitGuildCreate();

    bool WaitGuildGetInfo();

    bool WaitGuildGetList();

    bool WaitGuildSearch();

    bool WaitGuildApply();

    bool WaitGuildDeclarationChange();

    bool WaitGuildAnnounceChange();

    bool WaitGuildQueryMemberList();

    bool WaitGuildMemberSearch();

    bool WaitGuildChangePermission();

    bool WaitGuildKickOutMember();

    bool WaitGuildGetApplicationList();

    bool WaitGuildApplyReplay();

    bool WaitGuildAutoApprovalApply();

    bool WaitGuildQuit();

    bool WaitGuildIconChange();

    bool WaitGetStaticSceneLine();

    bool WaitChangeSceneLine();

    bool WaitEquipEnchant();

    bool WaitEquipEnchantConfirm();

    bool WaitClearEnchatCache();

    bool WaitGetServerLevelBonusInfo();

    bool WaitAwardPreview();

    bool WaitExchangeHeadGear();

    bool WaitGetMailList();

    bool WaitMailOp();

    bool WaitGetOneMail();

    bool WaitStallGetMarkInfo();

    bool WaitStallGetItemInfo();

    bool WaitStallItemBuy();

    bool WaitStallRefresh();

    bool WaitStallGetSellInfo();

    bool WaitStallGetPreSellItemInfo();

    bool WaitStallSellItem();

    bool WaitStallSellItemCancel();

    bool WaitStallDrawMoney();

    bool WaitStallBuyStallCount();

    bool WaitStallReSellItem();

    bool WaitHSUsedAwardTimesDungeon();

    bool WaitHSQueryRoundInfo();

    bool WaitGuildGetNewsInfo();

    bool WaitEquipCardInsert();

    bool WaitEquipCardRemove();

    bool WaitEquipMakeHole();

    bool WaitEquipReformMake();

    bool WaitQueryRandomAwardStart();

    bool WaitGiveGifts();

    bool WaitGetGiftLimitInfo();

    bool WaitSevenLoginActivityGetReward();

    bool WaitSevenLoginActivityGetInfo();

    bool WaitYuanQiRequest();

    bool WaitLifeSkillFishing();

    bool WaitSaveReviveRecord();

    bool WaitTrialDungeonChooseProfession();

    bool WaitDailyActivityShowToMS();

    bool WaitLifeEquipChange();

    bool WaitBlessOperation();

    bool WaitGetBlessInfo();

    bool WaitSortBag();

    bool WaitSendChatMsg();

    bool WaitRoleSearch();

    bool WaitRecommandMember();

    bool WaitDirTeleport();

    bool WaitDoubleActiveApply();

    bool WaitDoubleActiveAgree();

    bool WaitGuildPermissionNameChange();

    bool WaitGuildDinnerViewMenu();

    bool WaitGuildDinnerTaskAccept();

    bool WaitEquipCompound();

    bool WaitGetItemByUid();

    bool WaitJudgeTextForbid();

    bool WaitGsChangeRoleName();

    bool WaitUnLockRoleIllutration();

    // bool WaitBeginMatchForBattleField();

    bool WaitGuildGetBuildingInfo();

    bool WaitGuildUpBuildingLevel();

    bool WaitGuildDonateMaterials();

    bool WaitGuildDonateMoney();

    bool WaitDoubleActiveEnd();

    bool WaitMaterialsMechant();

    bool WaitEquipEnchantReborn();

    bool WaitEquipEnchantRebornPreview();

    bool WaitRecoveCard();

    bool WaitGuildGiveItem();

    bool WaitGuildGetWelfare();

    bool WaitGuildWelfareAward();

    bool WaitExtractCard();

    bool WaitRecycleCardPreview();

    bool WaitChangeTrolley();

    bool WaitGuildDinnerGetDishNPCState();

    bool WaitGuildDinnerEatDish();

    bool WaitGuildDinnerGetCookingNPCState();

    bool WaitPreviewOrnament();

    bool WaitExtractOrnament();

    bool WaitRecoveOrnament();

    bool WaitMakeDevice();

    bool WaitUseDevice();

    bool WaitEquipRefineUnblock();

    bool WaitEquipRefineTransfer();

    bool WaitCatTradeActivityGetInfo();

    bool WaitCatTradeActivityGetReward();

    bool WaitCatTradeActivitySellGoods();

    bool WaitCancelTransfigureRequest();

    bool WaitMedalOp();

    bool WaitGetPrestigeAddition();

    bool WaitExchangeAwardPack();

    bool WaitGetTutorialMark();

    bool WaitUpdateTutorialMark();

    bool WaitQueryRobotTeamBattle();

    bool WaitDoubleActiveEnter();

    bool WaitGuildEmailSend();

    bool WaitGuildInviteJoin();

    bool WaitPayNotify();

    bool WaitAutoFishPush();

    bool WaitGuildCrystalGetInfo();

    bool WaitGuildCrystalLearn();

    bool WaitGuildCrystalQuickUpgrade();

    bool WaitGuildCrystalPray();

    bool WaitGuildCrystalGiveEnergy();

    bool WaitSwitchRole();

    bool WaitGetPostcardDisplay();

    bool WaitUpdatePostcardDisplay();

    bool WaitEnterSceneTriggerObject();

    bool WaitCancelBuff();

    bool WaitPickUpDropBuff();

    bool WaitCreateChatRoom();

    bool WaitChangeRoomSetting();

    bool WaitKickRoomMember();

    bool WaitLeaveRoom();

    bool WaitDissolveRoom();

    bool WaitApplyJoinRoom();

    bool WaitRoomChangeCaptain();

    bool WaitGetChatRoomInfo();

    bool WaitRoomAfk();

    bool WaitPayFine();

    bool WaitRequestEquipForgedList();

    bool WaitAchievementGetInfo();

    bool WaitAchievementGetFinishRateInfo();

    bool WaitAchievementGetBadgeRateInfo();

    bool WaitAchievementGetItemReward();

    bool WaitAchievementGetPointReward();

    bool WaitDelegationAward();

    bool WaitSetArrow();

    bool WaitOnSceneTrigger();

    bool WaitIsAssist();

    bool WaitDeleteRole();

    bool WaitResumeRole();

    bool WaitGetAccountRoleData();

    bool WaitThirtySignActivityGetReward();

    bool WaitThirtySignActivityGetInfo();

    bool WaitBatchAwardPreview();

    bool WaitSceneTriggerSummonMonster();

    bool WaitEnterTriggerFishpond();



//==================================


    //==================================

    //int CRobotClient::GetActionNameCount();
	//
	inline void SetState(int s)
	{
        PushActionName(__func__);
        PushActionName(std::to_string(s));
	    state_ = s;
	};
	inline int GetState()
	{
        //PushActionName(__func__);;
        return state_;
	}
    inline TeamStatus GetTeamStatus()
	{
        return team_com.GetTeamStatus();
	}
    void SetTeamStatus(int s)
	{
        team_com.SetTeamStatus(s);
	}

    uint32_t GetRandomSkillID();

public:
    //void OnResetWorkFrame();//重置工作帧
    void OnRunWorkFrame();//处理工作帧
    void OnTimer(const asio::error_code& error);

    
    //void SetResetNetwork() { need_reset_bt_ = true; }
    bool HandleBasicNtf(SReadMessage & _t);

    // tool
    bool FillSpaceBetweenFrame(uint32_t line_num);
private:
    void OnStepSyncInfo(const KKSG::StepSyncList & sync);//移动信息 
    void OnUnitAppear(const KKSG::UnitAppearList & appearlist); //对象出现
    void OnUnitAppear(const KKSG::UnitAppearance & appear); //对象出现
    void OnUnitDisappear(const KKSG::UnitDisappearData & appear);//  对象消失
    void OnUnitPostionSync(const KKSG::StepSyncList & postionsyninfo);//对象同步
    void ShowBroadCast(const KKSG::BroadCastDataM2T & broad_data);
    void GetCurrentFightGroup(const KKSG::UnitAppearList & m_oArg);
    void UpdataArenaRoomInfo(const KKSG::ArenaRoomInfo & m_Data);

public:
    void SendRankPos(float x, float y, float z);
public:
    uint32_t GetFightGroup() { return fight_group_; }

private:

    asio::steady_timer timer_;
    uint32_t timer_elapse_milliseconds_{ MESSAGE_HANDLER_TIMER_MILLISECOND };
	//bool is_post_read_{ false };
	//bool is_post_write_{ false };
	//std::list<CWorkFrame*> work_todo_;

	RoRobot* p_robot_bt_;//行为树
	int state_{ 0 };//行为树中需要的状态机

    TeamComponent team_com;
    
private:
	//逻辑
    std::string account_name_{ "robot" };
    KKSG::QueryGateRes query_gate_res_;//网关回包
    KKSG::LoginRes login_res_;//登陆回包
    KKSG::SelectRoleNtfData select_role_ntf_data_;//角色信息
    KKSG::SceneCfg scene_cfg_;//当前场景
    KKSG::ShowListArenaPvpRes room_info_;
    KKSG::CreateBattleSceneRes battle_scene_;
    KKSG::ArenaRoomInfo arena_room_info_;
    KKSG::BeginMatchForBattleFieldRes match_res_;
    KKSG::QueryRobotTeamBattleRes robot_team_;
    std::chrono::steady_clock::time_point move_start_timepoint_;
    uint64_t current_target_role_id_{ 0 };
    float current_target_des_x_{ 0.0f };//目标前进方向
    float current_target_des_z_{ 0.0f };
    float current_target_des_y_{ 0.0f };
    int current_target_dir_scene_{ 0 };
    int current_fight_group_{ -1 };
    float current_target_dir_face_{ 0.0f };
    //std::vector<ROGameLibs::Vector3> path;

    uint64_t current_target_monster_uid_{ 0 };
	float current_pos_x_{ 0 };//当前坐标
    float current_pos_y_{ 0 };
    float current_pos_z_{ 0 };
    float current_pos_face_{ 0 };
    int current_scene_id_{ 0 };

    std::unordered_map<uint64_t, SUnitSimple> all_monster_;
    std::unordered_map<uint64_t, SUnitSimple> all_player_;

    const float move_pace_{ 0.7f };//每一次行走的步长

    int skill_uuid_ = 0;
    int current_skill_ = 0;
    int count_skill_ = 0;
    int max_move_count_ = 0;
    int max_check_count_ = 0;
    int skill_flag = 0;
    int tot_item_count_ = 0;


//==move===============================
    const float my_pi_{ 3.1415926f };
    std::deque<Road> open_road_;
    std::set<Road> close_road_;
    std::deque<Road> left_road_;
    std::deque<Road> right_road_;
    Road target_road_;
    Road start_road_;
    std::deque<Road> result_road_;
//=====================================
//心跳包
    bool login_2_gate_{ false };
    std::chrono::system_clock::time_point send_sync_timepoint_;
    //rpc检查时间
    std::chrono::system_clock::time_point start_rpc_timepoint_;
    //bt更新时间点
    bool CheckBTRunTimeLate();
    //下一帧等待时间点
    std::chrono::system_clock::time_point start_next_bt_timepoint_;

    
    //监视用
public:
    void ResetBtStatus(bool need_delay);
    bool GetIsArenaIsFinished()
    {
        return is_arena_finished_;
    }
private:
    int all_actions_count_{ 0 };
    bool is_dead_{ false };
    bool is_login_{ false };
    bool is_role_select_{ false };
    bool isPvP = { false };
    bool is_create_{ false };
    bool is_target_position_{ false };
    bool is_has_target_{ false };
    bool is_patrol_{ false };
    bool is_change_scene_{ false };
    bool is_battle_field{ true };
    bool is_enterscene_ntf_{ false };//跨场景通知
    bool is_selectrole_ntf_{ false };//选择角色通知.
    bool is_arena_finished_{ false };//竞技场是否结束了
    bool is_need_reconnect_{ false };//需要重复等待

    uint32_t dungeons_id_{ 0 };

    uint32_t dir_of_patrol_{ 0 };
    uint32_t index_of_scene_{ 0 };
    uint32_t index_of_pos_{ 0 };
    std::pair<uint32_t, uint32_t> start_patrol_{ std::make_pair(86, 134) };
    std::pair<uint32_t, uint32_t> end_patrol_{ std::make_pair(147, 120) };

    //std::list<SClientProfile > all_actions_;
public:
    void PushActionName(const std::string & action_name);

    //inline const std::list<SClientProfile > & GetHistoryActive()
    //{
    //    return all_actions_;
    //};
    inline const std::string & GetRoleName()          { return select_role_ntf_data_.roledata().brief().name(); }
    inline const KKSG::RoleAllInfo & GetRoleAllInfo() { return select_role_ntf_data_.roledata(); }
    inline const uint64_t GetRoleId()    const     { return select_role_ntf_data_.roledata().brief().roleid(); }
private:
    //任务相关
    std::vector<int32_t> all_task_ids_temp;
    KKSG::TaskRecord all_task_data;
    std::vector<int32_t> all_acceptable_ids;


private:
    uint32_t robot_id_{0};
    uint32_t login_count_{ 0 };
private:
    KKSG::StallGetItemInfoRes stall_get_item_info_res_;
    KKSG::StallGetPreSellItemInfoRes stall_presell_item_info_res_;
    KKSG::StallGetSellInfoRes stall_get_sell_info_res_;

public:
    uint64_t GetUidByItemID(uint32_t item_id) const;
    void OnItemChangeNtf(const KKSG::ItemChange & data);
    void InitBagWhenSelectRole();
private:

    std::map<uint32_t, std::list<KKSG::Item>> bag_;
    std::array<KKSG::Item, kEquipCount> equips_;
    int32_t wear_index_{ 0 };
    int32_t take_off_index_{ 0 };
    std::array<uint32_t, kEquipCount> equips_id_;

    int32_t check_monster_dead_count_{ 0 };
    //重置处理 
    //bool need_reset_bt_{ false };
    //std::string xml_name;

    KKSG::WallData current_wall_data_;//当前墙的id
    KKSG::EnterWallSyncInfo current_enterwall_;//圣歌转盘

private:




    //pvp相关
    enum ArenaState
    {
        kArenaStateNone = 0, //啥都没干的状态
        kArenaStateInRoom = 1, //在匹配房间的状态
        kkArenaStateInBattle = 2, //在角斗场中
    };
public:
    void SetArenaState(int x)
    {
        PushActionName(__func__);
        arena_state_ = static_cast<ArenaState>(x);
    }
    int32_t GetArenaState()
    {
        PushActionName(__func__);
        return arena_state_;
    }
    bool CanAreanaStart(uint32_t count);
    bool FindAnyArenaRoom();
    void SetArenaFinished() { is_arena_finished_ = false; };
    inline bool GetArenaOperateResult()
    {
        PushActionName(__func__);
        return arena_operate_result_;
    }
private:
    ArenaState arena_state_{ kArenaStateNone };
    uint32_t find_any_pvp_room_id_{ 0 };
    uint32_t fight_group_{ 0 };
    bool arena_operate_result_{ false };

private:
    //虚拟物品相关
    std::map<int32_t, int32_t> virtual_item_type_2_count;
    //普通更新   
    void UpdateVirtualItem(int32_t type, int32_t count);

    //检查数量
    void InitVirtualItem(int32_t type, int32_t count);

private:
    bool need_sync_{ true };
public:
    inline void SetNoSync() { need_sync_ = false; };


    //组队进入副本
    uint32_t enter_dungeon_member_ask_dungeon_id_{ 0 };
    uint32_t enter_dungeon_member_ask_chapter_id_{ 0 };

public:
    bool change_role_name_failed_{ false };
    bool IsLoginTokenOK();
    void ReportEnterDungeon();

public:
    bool GetRecommenedGate(std::string & ip, uint32_t & port);
    bool GetRandomGate(std::string & ip, uint32_t & port);
};

#endif