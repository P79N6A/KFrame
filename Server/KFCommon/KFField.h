﻿#ifndef __KF_FIELD_H__
#define __KF_FIELD_H__

namespace KFrame
{
#define __STRING_DEFINE__( name )  static std::string _##name = #name;
#define __KF_STRING__( name )  KFField::_##name

    namespace KFField
    {
        __STRING_DEFINE__( daemon );
        __STRING_DEFINE__( win64 );
        __STRING_DEFINE__( linux );
        __STRING_DEFINE__( shard );
        __STRING_DEFINE__( gate );
        __STRING_DEFINE__( game );
        __STRING_DEFINE__( master );
        __STRING_DEFINE__( proxy );
        __STRING_DEFINE__( client );
        __STRING_DEFINE__( world );
        __STRING_DEFINE__( login );
        __STRING_DEFINE__( retcode );
        __STRING_DEFINE__( sign );
        __STRING_DEFINE__( password );
        __STRING_DEFINE__( account );
        __STRING_DEFINE__( accountflag );
        __STRING_DEFINE__( accountid );
        __STRING_DEFINE__( playerid );
        __STRING_DEFINE__( playeridcreate );
        __STRING_DEFINE__( accountlist );
        __STRING_DEFINE__( accountmake );
        __STRING_DEFINE__( address );
        __STRING_DEFINE__( appid );
        __STRING_DEFINE__( appname );
        __STRING_DEFINE__( apptype );
        __STRING_DEFINE__( apppath );
        __STRING_DEFINE__( appfile );
        __STRING_DEFINE__( appconfig );
        __STRING_DEFINE__( appkey );
        __STRING_DEFINE__( localip );
        __STRING_DEFINE__( interanetip );
        __STRING_DEFINE__( agentid );
        __STRING_DEFINE__( auth );
        __STRING_DEFINE__( activation );
        __STRING_DEFINE__( activationcode );
        __STRING_DEFINE__( channel );
        __STRING_DEFINE__( flag );
        __STRING_DEFINE__( id );
        __STRING_DEFINE__( zone );
        __STRING_DEFINE__( updatezone );
        __STRING_DEFINE__( lostzone );
        __STRING_DEFINE__( zonelist );
        __STRING_DEFINE__( zonehttp );
        __STRING_DEFINE__( zonelistversion );
        __STRING_DEFINE__( zonestatus );
        __STRING_DEFINE__( name );
        __STRING_DEFINE__( sex );
        __STRING_DEFINE__( serverlist );
        __STRING_DEFINE__( serverlisttype );
        __STRING_DEFINE__( token );
        __STRING_DEFINE__( type );
        __STRING_DEFINE__( ip );
        __STRING_DEFINE__( port );
        __STRING_DEFINE__( url );
        __STRING_DEFINE__( launch );
        __STRING_DEFINE__( time );
        __STRING_DEFINE__( process );
        __STRING_DEFINE__( command );
        __STRING_DEFINE__( shutdown );
        __STRING_DEFINE__( launchservice );
        __STRING_DEFINE__( startup );
        __STRING_DEFINE__( restart );
        __STRING_DEFINE__( download );
        __STRING_DEFINE__( upload );
        __STRING_DEFINE__( transmit );
        __STRING_DEFINE__( launchlist );
        __STRING_DEFINE__( status );
        __STRING_DEFINE__( statustime );
        __STRING_DEFINE__( describe );
        __STRING_DEFINE__( code );
        __STRING_DEFINE__( machine );
        __STRING_DEFINE__( errcode );
        __STRING_DEFINE__( accesstoken );
        __STRING_DEFINE__( refreshtoken );
        __STRING_DEFINE__( openid );
        __STRING_DEFINE__( scope );
        __STRING_DEFINE__( expiresin );
        __STRING_DEFINE__( weixindata );
        __STRING_DEFINE__( unionid );
        __STRING_DEFINE__( nickname );
        __STRING_DEFINE__( headimgurl );
        __STRING_DEFINE__( icon );
        __STRING_DEFINE__( iconbox );
        __STRING_DEFINE__( count );
        __STRING_DEFINE__( index );
        __STRING_DEFINE__( order );
        __STRING_DEFINE__( orderid );
        __STRING_DEFINE__( user );
        __STRING_DEFINE__( player );
        __STRING_DEFINE__( playerlist );
        __STRING_DEFINE__( task );
        __STRING_DEFINE__( value );
        __STRING_DEFINE__( received );
        __STRING_DEFINE__( item );
        __STRING_DEFINE__( achieve );
        __STRING_DEFINE__( level );
        __STRING_DEFINE__( activity );
        __STRING_DEFINE__( birthday );
        __STRING_DEFINE__( serverid );
        __STRING_DEFINE__( server );
        __STRING_DEFINE__( zoneid );
        __STRING_DEFINE__( zonebalance );
        __STRING_DEFINE__( gateid );
        __STRING_DEFINE__( var );
        __STRING_DEFINE__( note );
        __STRING_DEFINE__( gift );
        __STRING_DEFINE__( giftkey );
        __STRING_DEFINE__( reward );
        __STRING_DEFINE__( result );
        __STRING_DEFINE__( data );
        __STRING_DEFINE__( route );
        __STRING_DEFINE__( match );
        __STRING_DEFINE__( matchid );
        __STRING_DEFINE__( source );
        __STRING_DEFINE__( wholemail );
        __STRING_DEFINE__( wholemailtime );
        __STRING_DEFINE__( personmail );
        __STRING_DEFINE__( personmailtime );
        __STRING_DEFINE__( mail );
        __STRING_DEFINE__( mailidcreater );
        __STRING_DEFINE__( maillist );
        __STRING_DEFINE__( battle );
        __STRING_DEFINE__( battlelist );
        __STRING_DEFINE__( handleid );
        __STRING_DEFINE__( clientid );
        __STRING_DEFINE__( proxyid );
        __STRING_DEFINE__( matchplayer );
        __STRING_DEFINE__( teamid );
        __STRING_DEFINE__( roomid );
        __STRING_DEFINE__( grading );
        __STRING_DEFINE__( public );
        __STRING_DEFINE__( friend );
        __STRING_DEFINE__( friendliness );
        __STRING_DEFINE__( friendinvite );
        __STRING_DEFINE__( friendlinesslimit );
        __STRING_DEFINE__( refuseinvite );
        __STRING_DEFINE__( friendlist );
        __STRING_DEFINE__( invitelist );
        __STRING_DEFINE__( invite );
        __STRING_DEFINE__( newadd );
        __STRING_DEFINE__( senderid );
        __STRING_DEFINE__( sendername );
        __STRING_DEFINE__( validtime );
        __STRING_DEFINE__( sendtime );
        __STRING_DEFINE__( title );
        __STRING_DEFINE__( content );
        __STRING_DEFINE__( basic );
        __STRING_DEFINE__( message );
        __STRING_DEFINE__( store );
        __STRING_DEFINE__( model );
        __STRING_DEFINE__( modelid );
        __STRING_DEFINE__( clothesid );
        __STRING_DEFINE__( clothes );
        __STRING_DEFINE__( mailsendinfo );
        __STRING_DEFINE__( gmemaillastid );
        __STRING_DEFINE__( gmemailnum );
        __STRING_DEFINE__( friendemailnum );
        __STRING_DEFINE__( giftemailnum );
        __STRING_DEFINE__( personmailgm );
        __STRING_DEFINE__( personmailfriend );
        __STRING_DEFINE__( personmailgift );
        __STRING_DEFINE__( motto );
        __STRING_DEFINE__( toast );
        __STRING_DEFINE__( toastcount );
        __STRING_DEFINE__( file );
        __STRING_DEFINE__( groupid );
        __STRING_DEFINE__( maxgroupcount );
        __STRING_DEFINE__( nowgroupcount );
        __STRING_DEFINE__( group );
        __STRING_DEFINE__( groupmember );
        __STRING_DEFINE__( refusegroupinvite );
        __STRING_DEFINE__( groupapply );
        __STRING_DEFINE__( groupinvite );
        __STRING_DEFINE__( captainid );
        __STRING_DEFINE__( prepare );
        __STRING_DEFINE__( guest );
        __STRING_DEFINE__( configid );
        __STRING_DEFINE__( record );
        __STRING_DEFINE__( score );
        __STRING_DEFINE__( victory );
        __STRING_DEFINE__( topfive );
        __STRING_DEFINE__( topten );
        __STRING_DEFINE__( totalscore );
        __STRING_DEFINE__( topone );
        __STRING_DEFINE__( ranking );
        __STRING_DEFINE__( maxcount );
        __STRING_DEFINE__( campid );
        __STRING_DEFINE__( hero );
        __STRING_DEFINE__( heroid );
        __STRING_DEFINE__( elovalue );
        __STRING_DEFINE__( guild );
        __STRING_DEFINE__( rank );
        __STRING_DEFINE__( ranklist );
        __STRING_DEFINE__( ranksort );
        __STRING_DEFINE__( ranksortlist );
        __STRING_DEFINE__( rankdata );
        __STRING_DEFINE__( wishorder );
        __STRING_DEFINE__( robot );
        __STRING_DEFINE__( singlescore );
        __STRING_DEFINE__( doublescore );
        __STRING_DEFINE__( fourscore );
        __STRING_DEFINE__( usecount );
        __STRING_DEFINE__( onlinezone );
        __STRING_DEFINE__( online );
        __STRING_DEFINE__( kick );
        __STRING_DEFINE__( kickonline );
        __STRING_DEFINE__( extend );
        __STRING_DEFINE__( setting );
        __STRING_DEFINE__( relation );
        __STRING_DEFINE__( kill );
        __STRING_DEFINE__( die );
        __STRING_DEFINE__( evalscore );
        __STRING_DEFINE__( winscore );
        __STRING_DEFINE__( killscore );
        __STRING_DEFINE__( single );
        __STRING_DEFINE__( double );
        __STRING_DEFINE__( four );
        __STRING_DEFINE__( total );
        __STRING_DEFINE__( evalrank );
        __STRING_DEFINE__( winrank );
        __STRING_DEFINE__( killrank );
        __STRING_DEFINE__( winrate );
        __STRING_DEFINE__( evagekill );
        __STRING_DEFINE__( kda );
        __STRING_DEFINE__( averagekill );
        __STRING_DEFINE__( operatetime );
        __STRING_DEFINE__( stranger );
        __STRING_DEFINE__( deploy );
        __STRING_DEFINE__( delaytime );
        __STRING_DEFINE__( scheduletime );
        __STRING_DEFINE__( platform );
        __STRING_DEFINE__( minrankscore );
        __STRING_DEFINE__( log );
        __STRING_DEFINE__( battleroom );
        __STRING_DEFINE__( ftpid );
        __STRING_DEFINE__( recentlist );
        __STRING_DEFINE__( recenthash );
        __STRING_DEFINE__( recentplayer );
        __STRING_DEFINE__( totalplayer );
        __STRING_DEFINE__( bekilled );
        __STRING_DEFINE__( relationtype );
        __STRING_DEFINE__( skill );
        __STRING_DEFINE__( skillid );
        __STRING_DEFINE__( signin );
        __STRING_DEFINE__( sevenday );
        __STRING_DEFINE__( sevenreward );
        __STRING_DEFINE__( deploypath );
        __STRING_DEFINE__( minid );
        __STRING_DEFINE__( maxid );
        __STRING_DEFINE__( logtype );
        __STRING_DEFINE__( service );

    }
}

#endif
