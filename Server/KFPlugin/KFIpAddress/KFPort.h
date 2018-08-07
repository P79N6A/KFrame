#ifndef __KF_NET_PORT_H__
#define __KF_NET_PORT_H__

#include "KFrame.h"

namespace KFrame
{
    class KFPort
    {
    public:
        KFPort()
        {
            _id = 0;
            _port = 0;
        }

    public:
        uint32 _id;
        uint32 _port;
    };

#define __MAX_PORT_COUNT__ 200
    class KFramePort
    {
    public:
        KFramePort()
        {
            _is_inited = 0;
        }

        // 查找端口
        KFPort* FindPort( uint32 id );

    public:
        // 是否初始化
        uint32 _is_inited;

        // 互斥量
        KFMutex _kf_mutex;

        // 端口列表
        KFPort _kf_port[ __MAX_PORT_COUNT__ ];
    };

#define __FIX_PORT__ 0	// 固定计算端口
#define __ID_PORT__ 1	// id计算端口
#define __SH_PORT__ 2	// 共享内存计算端口
#define __ZONE_PORT__ 3 // 按照分区计算端口

    ///////////////////////////////////////////////////////////////////////
    class KFNetProt
    {
    public:
        KFNetProt();
        ~KFNetProt();

        // 设置类型
        void InitMemoryType( const std::string& type );

        // 计算一个监听端口
        uint32 CalcListenPort( uint32 type, uint32 baseport, uint32 appid );

    private:
        // 内存类型
        std::string _memory_type;

        // 共享内存
        KFShareMemory _kf_share_memory;
    };
}
#endif

