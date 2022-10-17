// Fill out your copyright notice in the Description page of Project Settings.


#include "TB_SHOTGUN.h"
#include "MyCharacter.h"

void ATB_SHOTGUN::SettingPlayerGun(AActor* myCharacter, FString yourGun)
{
	AMyCharacter* CastMyCharacter = Cast<AMyCharacter>(myCharacter);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("SHOTGUN!"));
	CastMyCharacter->PlaySettingGun(yourGun);
}

FString ATB_SHOTGUN::ReturnGunName()
{
	FString GunName = TEXT("SHOTGUN");

	return GunName;
}