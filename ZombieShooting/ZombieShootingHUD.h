// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ZombieShootingHUD.generated.h"

UCLASS()
class AZombieShootingHUD : public AHUD
{
	GENERATED_BODY()

public:
	AZombieShootingHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

