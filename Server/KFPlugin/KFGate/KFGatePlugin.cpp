﻿#include "KFGatePlugin.h"
#include "KFGateModule.h"

namespace KFrame
{
    void KFGatePlugin::Install()
    {
        __REGISTER_MODULE__( KFGate );
    }

    void KFGatePlugin::UnInstall()
    {
        __UNREGISTER_MODULE__( KFGate );
    }

    void KFGatePlugin::LoadModule()
    {
        __FIND_MODULE__( _kf_message, KFMessageInterface );
        __FIND_MODULE__( _kf_tcp_client, KFTcpClientInterface );
        __FIND_MODULE__( _kf_tcp_server, KFTcpServerInterface );
    }

}