// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZombieShootingGameMode.generated.h"

UCLASS(minimalapi)
class AZombieShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AZombieShootingGameMode();
	virtual void PostLogin(APlayerController* NewPlayer) override; // 이 과정에서 플레이어 설정이 진행된다.
	virtual void StartPlay() override;
};



