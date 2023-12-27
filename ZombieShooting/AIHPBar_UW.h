// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AIHPBar_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UAIHPBar_UW : public UUserWidget
{
	GENERATED_BODY()
	

	UPROPERTY(Meta = (BindWidget))
		class UProgressBar* AIHPBar;

protected:
	virtual void NativeOnInitialized() override;

public:
	void SetMonsterHP(float fCurrentHP);
};
