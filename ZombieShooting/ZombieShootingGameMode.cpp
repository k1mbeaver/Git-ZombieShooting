// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZombieShootingGameMode.h"
#include "ZombieShootingHUD.h"
#include "ZombieShootingCharacter.h"
#include "ZombieShooting_PC.h"
#include "MyCharacter.h"
#include "MyAICharacter.h"
#include "NavigationSystem.h"
#include "MyGameInstance.h"
#include "PlayerInterface_HUD.h"
#include "UObject/ConstructorHelpers.h"

AZombieShootingGameMode::AZombieShootingGameMode()
	//: Super()
{
	// set default pawn class to our Blueprinted character
	//DefaultPawnClass = AMyCharacter::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/BluePrints/BP_MyCharacter.BP_MyCharacter_C'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// PlayerController
	PlayerControllerClass = AZombieShooting_PC::StaticClass();

	// use our custom HUD class
	HUDClass = APlayerInterface_HUD::StaticClass();
}

void AZombieShootingGameMode::PostLogin(APlayerController* NewPlayer)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("PostLogin End"));

}

void AZombieShootingGameMode::StartPlay()
{
	Super::StartPlay();


}