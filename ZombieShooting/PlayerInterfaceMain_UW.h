// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInterfaceMain_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UPlayerInterfaceMain_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UPlayerInterface_UW* PlayerInterface_WB;

	UPROPERTY(Meta = (BindWidget))
		class UGameOver_UW* GameOver_WB;

	UPROPERTY(Meta = (BindWidget))
		class UGamePause_UW* GamePause_WB;

	UPROPERTY(Meta = (BindWidget))
		class UGameClear_UW* GameClear_WB;

public:
	void SetCurrentBullet(int nMissionClear, bool bIsSpecial);
	void SetDefaultBullet(bool bIsSpecial);
	void SetGunName(FString strGunName);
	void SetPlayerHP(float fCurrentHP);
	void SetGameOverUIVisible();
	void SetGameOverUIHidden();
	void SetGameClearUIVisible();
	void SetGameClearUIHidden();
	void SetGamePauseUIVisible();
	void SetGamePauseUIHidden();
};
