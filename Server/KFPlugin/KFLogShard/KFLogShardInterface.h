﻿/*------------------------------------
// Module:
// Author: NickYang
// Mail: NickYang1988@qq.com
// Date: 2018/06/28
------------------------------------*/
#ifndef __KF_LOG_SHARD_INTERFACE__
#define __KF_LOG_SHARD_INTERFACE__

#include "KFrame.h"

namespace KFrame
{

    class KFLogShardInterface : public KFModule
    {
    public:
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    __KF_INTERFACE__( _kf_log_shard, KFLogShardInterface );
    ///////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif //!__KF_LOG_SHARD_INTERFACE__