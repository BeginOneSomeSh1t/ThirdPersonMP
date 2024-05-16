// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonPingHost.h"

AThirdPersonPingHost::AThirdPersonPingHost(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BeaconState = EBeaconState::AllowRequests;
}

bool AThirdPersonPingHost::InitializeHost()
{
	bInitSuccess = InitHost();
	return bInitSuccess;
}

void AThirdPersonPingHost::RegisterHostObject(AOnlineBeaconHostObject* HostObject)
{
	if(bInitSuccess)
	{
		RegisterHost(HostObject);
	}
}
