// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonPingClient.h"


DEFINE_LOG_CATEGORY(LogPingClient)

AThirdPersonPingClient::AThirdPersonPingClient(FObjectInitializer const& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void AThirdPersonPingClient::OnFailure()
{
	Super::OnFailure();
	UE_LOG(LogPingClient, Log, TEXT("APingClient connection failed"))
}

void AThirdPersonPingClient::ClientPingBegin_Implementation()
{
	UE_LOG(LogPingClient, Log, TEXT("APingClient::ClientPingBegin_Implementation"));
	PingBeginTime = FDateTime::Now().GetTicks();
	ServerPong();
}

void AThirdPersonPingClient::ServerPong_Implementation()
{
	UE_LOG(LogPingClient, Log, TEXT("APingClient::ServerPong_Implementation"))
	ClientPingEnd();
}

bool AThirdPersonPingClient::ServerPong_Validate()
{
	return true;
}

void AThirdPersonPingClient::ClientPingEnd_Implementation()
{
	UE_LOG(LogPingClient, Log, TEXT("APingClient::ClientPingEnd_Implementation"));
	int64 const PingTime = FDateTime::Now().GetTicks() - PingBeginTime;
	PingMS = (int32)(PingTime / 10000);
	UE_LOG(LogPingClient, Log, TEXT("Ping Complete: %d ms"), PingMS);
}

bool AThirdPersonPingClient::ConnectToHost(FString Address, int32 const InPort, bool const bPortOverride)
{
	FURL LURL(nullptr, *Address, TRAVEL_Absolute);
	if(bPortOverride)
	{
		LURL.Port = InPort;
	}
	else
	{
		int32 ListenPort = 0;
		if(GConfig->GetInt(TEXT("/Script/OnlineSubsystemUtils.OnlineBeaconHost"), TEXT("ListenPort"),ListenPort, GEngineIni))
		{
			LURL.Port = ListenPort;
		}
		else
		{
			LURL.Port = 8888;
		}
	}
	return InitClient(LURL);
}

void AThirdPersonPingClient::Disconnect()
{
	DestroyBeacon();
}
