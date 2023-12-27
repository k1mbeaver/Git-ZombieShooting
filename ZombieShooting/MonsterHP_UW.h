// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MonsterHP_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UMonsterHP_UW : public UUserWidget
{
	GENERATED_BODY()
	
		UPROPERTY(Meta = (BindWidget))
		class UProgressBar* HPBar;

protected:
	virtual void NativeOnInitialized() override;

public:
	void SetMonsterHP(float fCurrentHP);
};
