#!/bin/sh

function copyfile()
{
	file1=$path1/$2
	file2=$path2/$2
	
	needcopyfile=0
	if [ ! -f "$file1" ];then
		needcopyfile=0
	elif [ ! -f "$file2" ];then
		needcopyfile=1	
	elif [ $1 == "1" ];then
		filetime1=`stat -c %Y $file1`
        	filetime2=`stat -c %Y $file2`

        	if [ $filetime1 -gt $filetime2 ];then
                	needcopyfile=1
        	fi
	fi
	
	if [ $needcopyfile == 1 ];then
		echo "copy $file1 $file2"
		cp -f $file1 $file2
	fi
}

respath=../../../Bin
deploypath=/data/mail

mkdir -p $deploypath
mkdir -p $deploypath/setting
mkdir -p $deploypath/plugin
mkdir -p $deploypath/config
mkdir -p $deploypath/startup

#setting
path1=$respath/setting
path2=$deploypath/setting
copyfile 1 ip.address
copyfile 1 bus.relation
copyfile 1 server.network
copyfile 1 redis.address
copyfile 1 cluster.setting
copyfile 1 option.setting

path1=$respath/startup
path2=$deploypath/startup
copyfile 1 common.startup
copyfile 1 mail.master.startup
copyfile 1 mail.proxy.startup
copyfile 1 mail.shard.startup

#config
path1=$respath/config
path2=$deploypath/config

#plugin
path1=$respath/bin
path2=$deploypath
copyfile 1 KFStartup
copyfile 1 KFStartupd

cp -f $deploypath/KFStartup $deploypath/mailserver
cp -f $deploypath/KFStartupd $deploypath/mailserverd

path2=$deploypath/plugin
copyfile 1 KFBus.so
copyfile 1 KFBusd.so
copyfile 1 KFIpAddress.so
copyfile 1 KFIpAddressd.so
copyfile 1 KFHttpClient.so
copyfile 1 KFHttpClientd.so
copyfile 1 KFTcpServer.so
copyfile 1 KFTcpServerd.so
copyfile 1 KFTcpClient.so
copyfile 1 KFTcpClientd.so
copyfile 1 KFMessage.so
copyfile 1 KFMessaged.so
copyfile 1 KFConfig.so
copyfile 1 KFConfigd.so
copyfile 1 KFClusterMaster.so
copyfile 1 KFClusterMasterd.so
copyfile 1 KFClusterProxy.so
copyfile 1 KFClusterProxyd.so
copyfile 1 KFTimer.so
copyfile 1 KFTimerd.so
copyfile 1 KFClusterShard.so
copyfile 1 KFClusterShardd.so
copyfile 1 KFWorker.so
copyfile 1 KFWorkerd.so
copyfile 1 KFMailProxy.so
copyfile 1 KFMailProxyd.so
copyfile 1 KFMailShard.so
copyfile 1 KFMailShardd.so
copyfile 1 KFRedis.so
copyfile 1 KFRedisd.so
copyfile 1 KFOptiond.so
copyfile 1 KFOption.so
copyfile 1 KFScheduled.so
copyfile 1 KFSchedule.so
copyfile 1 KFDeployClient.so
copyfile 1 KFDeployClientd.so
copyfile 1 KFDeployCommand.so
copyfile 1 KFDeployCommandd.so
copyfile 1 KFClusterClientd.so
copyfile 1 KFClusterClient.so
copyfile 1 KFLogClientd.so
copyfile 1 KFLogClient.so
copyfile 1 KFHttpServerd.so
copyfile 1 KFHttpServer.so
copyfile 1 KFMailMasterd.so
copyfile 1 KFMailMaster.so
