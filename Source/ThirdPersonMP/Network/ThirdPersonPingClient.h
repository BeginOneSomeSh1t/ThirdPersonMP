// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconClient.h"
#include "ThirdPersonPingClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPingClient, Log, All);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Transient, NotPlaceable, Config=Engine)
class THIRDPERSONMP_API AThirdPersonPingClient : public AOnlineBeaconClient
{
	GENERATED_BODY()
public:
	AThirdPersonPingClient(FObjectInitializer const& ObjectInitializer);

	virtual void OnFailure() override;

	UFUNCTION(Client, Reliable)
	void ClientPingBegin();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPong();

	UFUNCTION(Client, Reliable)
	void ClientPingEnd();

	UFUNCTION(BlueprintCallable, Category=Ping)
	bool ConnectToHost(FString Address, int32 const InPort, bool const bPortOverride);

	UFUNCTION(BlueprintCallable, Category=Ping)
	void Disconnect();

protected:
	int64 PingBeginTime;
	int32 PingMS;
};
