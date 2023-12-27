// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainTitle_HUD.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API AMainTitle_HUD : public AHUD
{
	GENERATED_BODY()
public:
	AMainTitle_HUD();
	virtual void BeginPlay() override;

private:

	TSubclassOf<class UMainTitle_UW> MainUIClass;
	class UMainTitle_UW* MainUIObject;

	TSubclassOf<class UMainSetting_UW> SettingUIClass;
	class UMainSetting_UW* SettingUIObject;

public:
	UFUNCTION()
		void VisibleSetting();

	UFUNCTION()
		void HiddenSetting();

	UFUNCTION()
		float GetBgmPower();

	UFUNCTION()
		void SetBgmSlider(float fBgmPower);

private:
	bool CheckUIObject();
	bool CreateUIObject();
};
