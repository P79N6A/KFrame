﻿#include "KFDataConfig.h"

namespace KFrame
{
    const KFClassSetting* KFDataConfig::FindClassSetting( const std::string& classname ) const
    {
        return _class_setting.Find( classname );
    }

    const KFDataSetting* KFDataConfig::FindDataSetting( const std::string& classname, const std::string& propertyname ) const
    {
        auto classsetting = FindClassSetting( classname );
        if ( classsetting == nullptr )
        {
            return nullptr;
        }

        return classsetting->FindDataSetting( propertyname );
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool KFDataConfig::LoadDataConfig( const std::string& file )
    {
        KFXml kfxml( file );
        auto config = kfxml.RootNode();
        auto xmlnode = config.FindNode( "Setting" );
        while ( xmlnode.IsValid() )
        {
            auto classname = xmlnode.GetString( "Class" );
            auto kfclasssetting = _class_setting.Create( classname );
            kfclasssetting->_class = classname;

            auto dataname = xmlnode.GetString( "Name" );
            auto kfdatasetting = kfclasssetting->_static_data.Create( dataname );
            kfdatasetting->_name = dataname;
            kfdatasetting->_type = KFDataDefine::ConvertDataType( xmlnode.GetString( "Type" ) );
            kfdatasetting->_contain_class = xmlnode.GetString( "ContainClass" );
            kfdatasetting->_init_value = xmlnode.GetString( "InitValue" );
            kfdatasetting->_key_name = xmlnode.GetString( "KeyName" );
            kfdatasetting->_config_key_name = xmlnode.GetString( "ConfigKeyName" );
            kfdatasetting->_lua_file = xmlnode.GetString( "LuaFile" );
            kfdatasetting->_add_function = xmlnode.GetString( "AddFunction" );
            kfdatasetting->_update_function = xmlnode.GetString( "UpdateFunction" );
            kfdatasetting->_remove_function = xmlnode.GetString( "RemoveFunction" );

            if ( xmlnode.GetString( "Save" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Save_Database );
            }
            if ( xmlnode.GetString( "Sync" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Sync_Client );
            }
            if ( xmlnode.GetString( "View" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Sync_View );
            }
            if ( xmlnode.GetString( "Log" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_System_Log );
            }
            if ( xmlnode.GetString( "Public" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Public_Data );
            }
            if ( xmlnode.GetString( "Online" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Online_Data );
            }
            if ( xmlnode.GetString( "Relation" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Relation_Data );
            }
            if ( xmlnode.GetString( "Group" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Group_Data );
            }
            if ( xmlnode.GetString( "Guild" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Guild_Data );
            }
            if ( xmlnode.GetString( "Rank" ) == "1" )
            {
                KFUtility::AddBitMask< uint32 >( kfdatasetting->_data_mask, KFDataDefine::Mask_Rank_Data );
            }

            xmlnode.NextNode();
        }
        //////////////////////////////////////////////////////////////////

        return true;
    }
}