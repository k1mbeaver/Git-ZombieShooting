// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainSetting_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UMainSetting_UW : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(Meta = (BindWidget))
		class USetting_UW* Setting_WB;

public:
	void VisibleSetting();
	void HiddenSetting();
	void SetBgmSlider(float fBgmPower);
	float GetBgmPower();
};
