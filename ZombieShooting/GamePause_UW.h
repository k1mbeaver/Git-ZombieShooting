// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePause_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UGamePause_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UButton* BtResume;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtSaveAndOut;

	UPROPERTY()
		class UGameplayStatics* GameStatic;


protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	//virtual void NativeConstruct() override;
public:
	void SetGamePauseUIVisible();
	void SetGamePauseUIHidden();
	UFUNCTION()
		void ResumeHandler();
	UFUNCTION()
		void QuitHandler();
};
