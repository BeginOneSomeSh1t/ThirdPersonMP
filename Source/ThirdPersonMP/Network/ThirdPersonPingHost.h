// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHost.h"
#include "ThirdPersonPingHost.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONMP_API AThirdPersonPingHost : public AOnlineBeaconHost
{
	GENERATED_BODY()
public:
	AThirdPersonPingHost(const FObjectInitializer& ObjectInitializer);
 
	UFUNCTION(BlueprintCallable, Category=Ping)
	bool InitializeHost();
 
	UFUNCTION(BlueprintCallable, Category=Ping)
	void RegisterHostObject(AOnlineBeaconHostObject* HostObject);
 
protected:
	bool bInitSuccess;
};
