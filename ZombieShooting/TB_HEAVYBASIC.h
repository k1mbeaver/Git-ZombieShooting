// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TB_HEAVYBASIC.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API ATB_HEAVYBASIC : public ATriggerBox
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
		void SettingPlayerGun(AActor* myCharacter, FString yourGun);

	UFUNCTION(BlueprintCallable)
		FString ReturnGunName();
};
