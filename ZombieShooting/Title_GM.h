// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Title_GM.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API ATitle_GM : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATitle_GM();
	virtual void PostLogin(APlayerController* NewPlayer) override; // 이 과정에서 플레이어 설정이 진행된다.
};
