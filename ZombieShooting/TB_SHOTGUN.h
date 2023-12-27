// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TB_SHOTGUN.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API ATB_SHOTGUN : public ATriggerBox
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable)
		void SettingPlayerGun(AActor* myCharacter, FString yourGun);

	UFUNCTION(BlueprintCallable)
		FString ReturnGunName();
};
