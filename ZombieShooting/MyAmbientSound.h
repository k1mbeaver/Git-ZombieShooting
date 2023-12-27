// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include "MyAmbientSound.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API AMyAmbientSound : public AAmbientSound
{
	GENERATED_BODY()

		AMyAmbientSound();

private:
	virtual void BeginPlay() override;

	UPROPERTY()
		class USoundCue* TitleBGM;

};
