// Fill out your copyright notice in the Description page of Project Settings.


#include "Title_GM.h"
#include "Title_PC.h"
#include "MainTitle_HUD.h"

ATitle_GM::ATitle_GM()
{
	PlayerControllerClass = ATitle_PC::StaticClass();
	HUDClass = AMainTitle_HUD::StaticClass();
}

void ATitle_GM::PostLogin(APlayerController* NewPlayer)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("PostLogin End"));

}