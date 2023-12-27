// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInterface_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UPlayerInterface_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UTextBlock* CurrentBullet;

	UPROPERTY(Meta = (BindWidget))
		class UTextBlock* DefaultBullet;

	UPROPERTY(Meta = (BindWidget))
		class UTextBlock* GunName;

	UPROPERTY(Meta = (BindWidget))
		class UTextBlock* TextHP;

	UPROPERTY(Meta = (BindWidget))
		class UProgressBar* HPBarFill;

protected:
	virtual void NativeOnInitialized() override;
	//virtual void NativeConstruct() override;
public:

	void SetCurrentBullet(int nMissionClear, bool bIsSpecial);
	void SetDefaultBullet(bool bIsSpecial);
	void SetGunName(FString strGunName);
	void SetPlayerHP(float fCurrentHP);
};
