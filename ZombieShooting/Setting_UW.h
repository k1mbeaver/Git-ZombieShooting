// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Setting_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API USetting_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UButton* BtBack;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtCheck;

	UPROPERTY(Meta = (BindWidget))
		class USlider* SD_BGM;

public:
	UFUNCTION()
		void BackHandler();

	UFUNCTION()
		void CheckHandler();

	UFUNCTION()
		void SetBgmSlider(float fBgmPower);

	UFUNCTION()
		float GetBgmPower();

	void VisibleSetting();
	void HiddenSetting();

	virtual void NativeConstruct() override;
};
