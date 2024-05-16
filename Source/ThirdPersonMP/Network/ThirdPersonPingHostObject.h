// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHostObject.h"
#include "ThirdPersonPingHostObject.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONMP_API AThirdPersonPingHostObject : public AOnlineBeaconHostObject
{
	GENERATED_BODY()
public:
	AThirdPersonPingHostObject(const FObjectInitializer& ObjectInitializer);
 
	virtual AOnlineBeaconClient* SpawnBeaconActor(class UNetConnection* ClientConnection) override;
 
	virtual void OnClientConnected(class AOnlineBeaconClient* ClientActor, class UNetConnection* ClientConnection) override;
 
	virtual bool Init();
};