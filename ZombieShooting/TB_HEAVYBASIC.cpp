// Fill out your copyright notice in the Description page of Project Settings.


#include "TB_HEAVYBASIC.h"
#include "MyCharacter.h"

void ATB_HEAVYBASIC::SettingPlayerGun(AActor* myCharacter, FString yourGun)
{
	AMyCharacter* CastMyCharacter = Cast<AMyCharacter>(myCharacter);

	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("HEAVY!"));

	CastMyCharacter->PlaySettingGun(yourGun);
}

FString ATB_HEAVYBASIC::ReturnGunName()
{
	FString GunName = TEXT("HEAVYBASIC");

	return GunName;
}


