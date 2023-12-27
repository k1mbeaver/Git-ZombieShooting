// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainTitle_UW.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UMainTitle_UW : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Meta = (BindWidget))
		class UTitle_UW* WBTitle;
};
