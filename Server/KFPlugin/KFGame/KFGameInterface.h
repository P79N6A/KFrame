﻿#ifndef __KF_GAME_INTERFACE_H__
#define __KF_GAME_INTERFACE_H__

#include "KFrame.h"

namespace KFrame
{
    class KFData;
    class KFEntity;
    /////////////////////////////////////////////////////////////////////////////////////////////
    class KFGameInterface : public KFModule
    {
    public:
        // 发送消息到世界服务器
        virtual bool SendToWorld( uint32 msgid, ::google::protobuf::Message* message ) = 0;

        // 发送消息到Gate服务器
        virtual void SendToGate( uint32 msgid, ::google::protobuf::Message* message ) = 0;
        virtual bool SendToGate( uint64 gateid, uint32 msgid, ::google::protobuf::Message* message ) = 0;

        // 发送消息到客户端
        virtual bool SendToClient( uint64 gateid, uint64 playerid, uint32 msgid, ::google::protobuf::Message* message ) = 0;
        virtual bool SendToClient( KFEntity* player, uint32 msgid, ::google::protobuf::Message* message ) = 0;

        // 发送到玩家
        virtual bool SendToPlayer( KFData* kfbasic, uint32 msgid, ::google::protobuf::Message* message ) = 0;
        virtual bool SendToPlayer( uint64 serverid, uint64 playerid, uint32 msgid, ::google::protobuf::Message* message ) = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        // 广播消息到客户端
        virtual bool BroadcastToGate( uint32 msgid, ::google::protobuf::Message* message ) = 0;
        virtual bool BroadcastToWorld( uint32 msgid, ::google::protobuf::Message* message ) = 0;

        // 转发服务器
        virtual bool TransmitToServer( uint32 msgid, ::google::protobuf::Message* message ) = 0;

        // 转发给玩家
        virtual bool TransmitToPlayer( uint64 playerid, uint32 msgid, ::google::protobuf::Message* message ) = 0;

        /////////////////////////////////////////////////////////////////////////////////////////////
        // 踢掉角色
        virtual void KickPlayer( uint64 playerid, uint32 type, const char* function, uint32 line ) = 0;
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    __KF_INTERFACE__( _kf_game, KFGameInterface );
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}



#endif