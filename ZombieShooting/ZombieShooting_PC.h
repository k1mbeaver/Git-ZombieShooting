// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZombieShooting_PC.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API AZombieShooting_PC : public APlayerController
{
	GENERATED_BODY()
		AZombieShooting_PC();
public:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void PostInitializeComponents() override; // 여기서 빙의되는지 알 수 있음
	virtual void SetupInputComponent() override;
 
private:
	UPROPERTY()
	class AMyCharacter* myCharacter;

private:
	void UpDown(float NewAxisValue);

	void LeftRight(float NewAxisValue);

	void LookUp(float NewAxisValue);

	void Turn(float NewAxisValue);

	void OnFire();

	void Run();

	void StopRun();

	void Jump();

	void StopJumping();

	void ReadyFire();

	void ResetReadyFire();

	void PlayerPause();
};
