﻿#include "KFDeployCommandPlugin.h"
#include "KFDeployCommandModule.h"
//////////////////////////////////////////////////////////////////////////

namespace KFrame
{
    void KFDeployCommandPlugin::Install()
    {
        __REGISTER_MODULE__( KFDeployCommand );
    }

    void KFDeployCommandPlugin::UnInstall()
    {
        __UNREGISTER_MODULE__( KFDeployCommand );
    }

    void KFDeployCommandPlugin::LoadModule()
    {
        __FIND_MODULE__( _kf_timer, KFTimerInterface );
        __FIND_MODULE__( _kf_config, KFConfigInterface );
        __FIND_MODULE__( _kf_message, KFMessageInterface );
        __FIND_MODULE_NO_LOG__( _kf_lua, KFLuaInterface );
    }

}