// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Title_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UTitle_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UButton* BtReplay;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtSetting;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtExit;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtPlay;

public:
	UFUNCTION()
		void PlayHandler();

	UFUNCTION()
		void ReplayHandler();

	UFUNCTION()
		void SettingHandler();

	UFUNCTION()
		void ExitHandler();

	virtual void NativeConstruct() override;
};
