﻿#ifndef __KF_DATE_H__
#define __KF_DATE_H__
/************************************************************************

					现实时间  单位 : 秒


************************************************************************/
#include "KFInclude.h"
typedef struct tm _tm;

namespace KFrame
{
    namespace KFTimeEnum
    {
        enum EConstDefine
        {
            SinceYear = 1900,

            OneSecondMicSecond = 1000,
            OneMinuteSecond = 60,
            OneMinuteMicSecond = 60 * OneSecondMicSecond,
            OneHourMinute = 60,
            OneHourSecond = OneHourMinute * OneMinuteSecond,
            OneHourMicSecond = OneHourSecond * OneSecondMicSecond,
            OneDayHour = 24,
            OneDayMinute = OneDayHour * OneHourMinute,
            OneDaySecond = OneDayMinute * OneMinuteSecond,
            OneDayMicSecond = OneDaySecond * OneSecondMicSecond,
            OneWeekDay = 7,
            OneWeekHour = OneWeekDay * OneDayHour,
            OneWeekMinute = OneWeekHour * OneHourMinute,
            OneWeekSecond = OneWeekMinute * OneMinuteSecond,

            OneMonthDay = 30,
            ////////////////////////////////////////////////////////////////////////
            None = 0,
            Hour = 1,
            Day = 2,
            Week = 3,
            Month = 4,
            Year = 5,
            Max,
        };
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 系统时间
    class KFDate
    {
    public:
        KFDate();
        KFDate( uint64 time );
        KFDate( uint32 year, uint32 month, uint32 day, uint32 hour, uint32 min, uint32 second = 0 );

        // 获得时间
        uint64 GetTime() const;
        void SetTime( uint64 time );
        void AddTime( uint64 time );

        // 获得具体年月日时间
        uint32 GetYear() const;
        uint32 GetMonth() const;
        uint32 GetDay() const;
        uint32 GetHour() const;
        uint32 GetMinute() const;
        uint32 GetSecond() const;
        uint32 GetDayOfWeek() const;
        uint32 GetDayOfYear() const;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static std::string GetTimeString();
        static std::string GetTimeString( uint64 time );
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // 获得当前时间
        static KFDate GetDate();
        static uint64 GetTimeEx();

        // 判断在时间内
        static bool CheckInTime( uint64 start, uint64 end, uint64 now );

        // 判断时间是否已经过了
        static bool CheckPassTime( uint64 starttime, uint64 keeptime );
        static bool CheckPassTime( uint64 nowtime, uint64 starttime, uint64 keeptime );

        // 获得剩余时间
        static uint64 GetLeftTime( uint64 nowtime, uint64 starttime, uint32 keeptime );

        // 判断是否过了一年
        static bool CheckPassYear( uint64 lasttime, uint64 nowtime );

        // 判断是否过了某一天
        static bool CheckPassMonth( uint64 lasttime, uint64 nowtime, uint32 day, uint32 hour );

        // 判断是否过了一小时
        static bool CheckPassHour( uint64 lasttime, uint64 nowtime );

        // 判断同一天
        static bool CheckSameDay( uint64 lasttime, uint64 nowtime );

        // 判断是否过了某一天
        static bool CheckPassDay( uint64 lasttime, uint64 nowtime, uint32 hour );

        // 判断是否过了一周
        static bool CheckPassWeek( uint64 lasttime, uint64 nowtime, uint32 dayofweek, uint32 hour );

        // 判断时间
        static bool CheckTime( uint32 type, uint32 value, uint32 hour, uint64 lasttime, uint64 nowtime );

        // 判断是否过了时间
        static bool CheckPassTime( uint32 year, uint32 month, uint32 day, uint32 hour, uint32 minute );

        // 转换时间戳
        static uint64 TimeFormate( const std::string& ymd, const std::string& split = "-" );

    protected:
        // 转换时间
        void ConvertTimeDate();

    private:
        time_t _time;
        _tm _tm_date;
    };
}




#endif