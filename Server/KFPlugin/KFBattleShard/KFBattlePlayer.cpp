﻿#include "KFBattlePlayer.h"
#include "KFBattleRoom.h"
#include "KFBattleConfig.h"
#include "KFClusterShard/KFClusterShardInterface.h"

namespace KFrame
{
    KFBattlePlayer::KFBattlePlayer()
    {
        _notice_count = 0;
        _status = KFPlayerStatus::StatusPlayerIdle;
    }

    KFBattlePlayer::~KFBattlePlayer()
    {

    }

    KFBattlePlayer* KFBattlePlayer::Create( const KFMsg::PBBattlePlayer& pbplayer )
    {
        auto kfplayer = __KF_CREATE_BATCH__( KFBattlePlayer, 100 );
        kfplayer->LoadFrom( pbplayer );

        return kfplayer;
    }

    void KFBattlePlayer::Release( KFBattlePlayer* kfplayer )
    {
        __KF_DESTROY__( KFBattlePlayer, kfplayer );
    }

    uint32 KFBattlePlayer::GetID()
    {
        return _pb_player.playerid();
    }

    void KFBattlePlayer::LoadFrom( const KFMsg::PBBattlePlayer& pbplayer )
    {
        _pb_player.CopyFrom( pbplayer );

        auto temp = __TO_STRING__( KFUtility::Make64Guid( pbplayer.playerid() ) );
        _token = KFCrypto::Md5Encode( temp.c_str() );

        _status = KFPlayerStatus::StatusEnterRoom;
    }

    void KFBattlePlayer::SaveTo( KFMsg::PBBattlePlayer* pbplayer )
    {
        pbplayer->CopyFrom( _pb_player );
    }

    bool KFBattlePlayer::SendMessageToClient( uint32 msgid, google::protobuf::Message* message )
    {
        return _kf_cluster_shard->SendMessageToClient( _pb_player.serverid(), msgid, message );
    }

    void KFBattlePlayer::RunEnterRoom( KFBattleRoom* kfroom )
    {
        switch ( _status )
        {
        case KFPlayerStatus::StatusEnterRoom:
        {
            // 玩家进去战场
            PlayerEnterBattleRoom( kfroom );
        }
        break;
        case KFPlayerStatus::StatusNoticeRoom:
        {
            // 通知玩家战场信息
            PlayerNoticeBattleRoom( kfroom );
        }
        break;
        default:
            break;
        }
    }

    void KFBattlePlayer::PlayerEnterBattleRoom( KFBattleRoom* kfroom )
    {
        KFMsg::S2SPlayerEnterBattleRoomReq req;
        SaveTo( req.mutable_player() );
        req.set_roomid( kfroom->_battle_room_id );
        req.set_token( _token );
        auto ok = kfroom->SendMessageToBattle( KFMsg::S2S_PLAYER_ENTER_BATTLE_ROOM_REQ, &req );
        if ( ok )
        {
            __LOG_DEBUG__( KFLogEnum::Logic, "player[{}:{}] enter battle room[{}] req!",
                           _pb_player.campid(), _pb_player.playerid(), kfroom->_battle_room_id );
        }
    }

    void KFBattlePlayer::ConfirmEnterBattleRoom()
    {
        _notice_count = 0;
        _status = KFPlayerStatus::StatusNoticeRoom;
    }

    void KFBattlePlayer::PlayerNoticeBattleRoom( KFBattleRoom* kfroom )
    {
        // 发送消息
        KFMsg::S2SNoticeMatchRoomReq req;
        req.set_matchid( kfroom->_match_id );
        req.set_battleshardid( KFGlobal::Instance()->_app_id );
        req.set_campid( _pb_player.campid() );
        req.set_playerid( _pb_player.playerid() );
        req.set_serverid( kfroom->_battle_server._server_id );
        req.set_ip( kfroom->_battle_server._ip );
        req.set_port( kfroom->_battle_server._port );
        req.set_roomid( kfroom->_battle_room_id );
        req.set_token( _token );
        auto ok = SendMessageToClient( KFMsg::S2S_NOTICE_MATCH_ROOM_REQ, &req );
        if ( ok )
        {
            ++_notice_count;
            if ( _notice_count >= 10 )
            {
                _status = KFPlayerStatus::StatusDisconnetRoom;
            }

            __LOG_DEBUG__( KFLogEnum::Logic, "player[{}:{}:{}] notice battle room[{}] req[{}]!",
                           _pb_player.campid(), _pb_player.serverid(), _pb_player.playerid(),
                           kfroom->_battle_room_id, _notice_count );
        }
    }

    void KFBattlePlayer::ConfirmNoticeBattleRoom()
    {
        // 确认客户端已经收到战场信息
        _status = KFPlayerStatus::StatusLoginRoom;
    }

    bool KFBattlePlayer::LoginBattleRoomReq( KFBattleRoom* kfroom )
    {
        _status = KFPlayerStatus::StatusPlayingRoom;

        KFMsg::S2SPlayerLoginBattleRoomAck ack;
        ack.set_roomid( kfroom->_battle_room_id );
        ack.set_campid( _pb_player.campid() );
        ack.set_playerid( _pb_player.playerid() );
        auto ok = kfroom->SendMessageToBattle( KFMsg::S2S_PLAYER_LOGIN_BATTLE_ROOM_ACK, &ack );
        if ( !ok )
        {
            __LOG_ERROR__( KFLogEnum::Logic, "player[{}] login battle room[{}] failed!",
                           _pb_player.playerid(), kfroom->_battle_room_id );
        }

        return ok;
    }

    void KFBattlePlayer::LeaveBattleRoomReq( KFBattleRoom* kfroom )
    {
        if ( kfroom->IsBattleRoomStart() )
        {
            // 已经开始, 设置离开状态
            _status = KFPlayerStatus::StatusLeaveRoom;
        }
        else
        {
            // 发送消息到Match服务器
            KFMsg::S2SPlayerLeaveRoomToMatchShardReq req;
            req.set_matchid( kfroom->_match_id );
            req.set_roomid( kfroom->_battle_room_id );
            req.set_campid( _pb_player.campid() );
            req.set_playerid( _pb_player.playerid() );
            kfroom->SendMessageToMatch( KFMsg::S2S_PLAYER_LEAVE_ROOM_TO_MATCH_SHARD_REQ, &req );
        }

        // 发送到游戏服务器,
        SendLeaveRoomToPlayer();
    }

    bool KFBattlePlayer::QueryBattleRoom( uint32 serverid )
    {
        // 设置游戏服务器id
        _pb_player.set_serverid( serverid );

        // 已经离开了
        if ( _status != KFPlayerStatus::StatusLeaveRoom )
        {
            _notice_count = 0;
            _status = KFPlayerStatus::StatusNoticeRoom;
        }
        else
        {
            __LOG_ERROR__( KFLogEnum::Logic, "player[{}] online status[{}] failed!",
                           _pb_player.playerid(), _status );
        }

        return true;
    }

    void KFBattlePlayer::OnlineBattleRoom( uint32 serverid )
    {
        _pb_player.set_serverid( serverid );
        if ( _status == KFPlayerStatus::StatusDisconnetRoom )
        {
            _notice_count = 0;
            _status = KFPlayerStatus::StatusNoticeRoom;
            __LOG_DEBUG__( KFLogEnum::Logic, "player[{}] online ok!", _pb_player.playerid() );
        }
    }

    void KFBattlePlayer::FinishLeaveRoom()
    {
        if ( _status == KFPlayerStatus::StatusLeaveRoom )
        {
            return;
        }

        _status = KFPlayerStatus::StatusLeaveRoom;
        SendLeaveRoomToPlayer();
    }

    void KFBattlePlayer::SendLeaveRoomToPlayer()
    {
        KFMsg::S2SLeaveBattleRoomToClientAck ack;
        ack.set_playerid( GetID() );
        SendMessageToClient( KFMsg::S2S_LEAVE_BATTLE_ROOM_TO_CLIENT_ACK, &ack );
    }

    bool KFBattlePlayer::BattleScoreBalance( KFBattleRoom* kfroom, KFMsg::PBBattleScore* pbscore )
    {
        // 设置matchid
        pbscore->set_matchid( kfroom->_match_id );

        // 计算评分
        ScoreBalance( pbscore );

        // 计算奖励
        auto reward = _kf_battle_config->FindBattleReward( pbscore->matchid(), pbscore->score() );

        {
            KFMsg::S2SBattleRoomScoreBalanceAck ack;
            ack.set_playerid( pbscore->playerid() );
            ack.set_roomid( kfroom->_battle_room_id );
            ack.set_reward( reward );
            auto ok = kfroom->SendMessageToBattle( KFMsg::S2S_BATTLE_ROOM_SCORE_BALANCE_ACK, &ack );
            if ( !ok )
            {
                __LOG_ERROR__( KFLogEnum::Logic, "player[{}] balance score send failed!", _pb_player.playerid() );
            }
        }

        {
            // 发送到玩家
            KFMsg::S2SPlayerBattleScoreReq req;
            req.set_playerid( _pb_player.playerid() );
            req.set_roomid( kfroom->_battle_room_id );
            req.mutable_pbscore()->CopyFrom( *pbscore );
            SendMessageToClient( KFMsg::S2S_PLAYER_BATTLE_SCORE_REQ, &req );
        }

        return true;
    }

    void KFBattlePlayer::ScoreBalance( KFMsg::PBBattleScore* pbscore )
    {
        // 各项数据
        double battlescore = 0.0f;
        for ( auto i = 0; i < pbscore->pbdata_size(); ++i )
        {
            auto pbdata = &pbscore->pbdata( i );
            auto scoreparam = _kf_battle_config->GetScoreParam( pbdata->name() );
            battlescore += pbdata->value() * scoreparam;
        }

        // 排名分
        auto rankingparam = _kf_battle_config->GetScoreParam( __KF_STRING__( ranking ) );
        battlescore += rankingparam / pbscore->ranking();

        // 吃鸡奖励分
        if ( pbscore->ranking() == 1 )
        {
            auto toponeparam = _kf_battle_config->GetScoreParam( __KF_STRING__( topone ) );
            battlescore += toponeparam;
        }

        if ( battlescore < 0.0f )
        {
            battlescore = 0;
        }
        pbscore->set_score( battlescore );
    }
}