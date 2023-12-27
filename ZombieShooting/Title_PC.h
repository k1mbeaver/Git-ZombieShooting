// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Title_PC.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API ATitle_PC : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	ATitle_PC();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UMainTitle_UW> TitleUIClass;

	class UMainTitle_UW* TitleUIObject;

	void PlayGame();
	void ReplayGame();
	void SettingGame();
	void BackSetting();
	void CheckSetting();
	void ExitGame();
};
