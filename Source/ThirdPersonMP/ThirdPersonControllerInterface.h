// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ThirdPersonControllerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UThirdPersonControllerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *  Controller interface that implements the following preset logic:
 *  - Respawn functions
 * 
 */
class THIRDPERSONMP_API IThirdPersonControllerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Should respawn currently controlled player in the world
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Gameplay|Controller")
	void RespawnPlayer();
	
};