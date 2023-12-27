// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameClear_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UGameClear_UW : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(Meta = (BindWidget))
		class UButton* BtNext;

	UPROPERTY(Meta = (BindWidget))
		class UButton* BtSaveAndOut;

	UPROPERTY()
		class UGameplayStatics* GameStatic;
protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	//virtual void NativeConstruct() override;
public:
	void SetGameClearUIVisible();
	void SetGameClearUIHidden();
	UFUNCTION()
		void NextHandler();
	UFUNCTION()
		void QuitHandler();
};
