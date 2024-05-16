// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonPingHostObject.h"

#include "ThirdPersonPingClient.h"

AThirdPersonPingHostObject::AThirdPersonPingHostObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ClientBeaconActorClass = AThirdPersonPingClient::StaticClass();
	BeaconTypeName = ClientBeaconActorClass->GetName();

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

AOnlineBeaconClient* AThirdPersonPingHostObject::SpawnBeaconActor(UNetConnection* ClientConnection)
{
	return Super::SpawnBeaconActor(ClientConnection);
}

void AThirdPersonPingHostObject::OnClientConnected(AOnlineBeaconClient* ClientActor, UNetConnection* ClientConnection)
{
	Super::OnClientConnected(ClientActor, ClientConnection);
	auto const PingClient = Cast<AThirdPersonPingClient>(ClientActor);
	if(PingClient)
	{
		PingClient->ClientPingBegin();
	}
}

bool AThirdPersonPingHostObject::Init()
{
	return true;
}
