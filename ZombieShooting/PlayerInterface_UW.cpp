// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInterface_UW.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UPlayerInterface_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CurrentBullet = Cast<UTextBlock>(GetWidgetFromName(TEXT("CurrentBullet")));
	DefaultBullet = Cast<UTextBlock>(GetWidgetFromName(TEXT("DefaultBullet")));
	GunName = Cast<UTextBlock>(GetWidgetFromName(TEXT("GunName")));
	TextHP = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextHP")));
	HPBarFill = Cast<UProgressBar>(GetWidgetFromName(TEXT("HPBarFill")));
}

void UPlayerInterface_UW::SetCurrentBullet(int nCurrentBullet, bool bIsSpecial)
{
	// SHOTGUN, HEAVY 老 嫐
	if (bIsSpecial)
	{
		FString fsMissionClear = FString::FromInt(nCurrentBullet);
		FText ftMissionClear = FText::FromString(fsMissionClear);
		CurrentBullet->SetText(ftMissionClear);
	}

	// BASIC 老 锭
	else
	{
		FText ftDefaultBullet = FText::FromString(TEXT("X"));
		CurrentBullet->SetText(ftDefaultBullet);
	}
}

void UPlayerInterface_UW::SetDefaultBullet(bool bIsSpecial)
{
	// SHOTGUN, HEAVY 老 锭
	if (bIsSpecial)
	{
		FText ftDefaultBullet = FText::FromString(TEXT("30"));
		DefaultBullet->SetText(ftDefaultBullet);
	}

	// BASIC 老 锭
	else
	{
		FText ftDefaultBullet = FText::FromString(TEXT("X"));
		DefaultBullet->SetText(ftDefaultBullet);
	}
}

void UPlayerInterface_UW::SetGunName(FString strGunName)
{
	FText ftGunName = FText::FromString(strGunName);
	GunName->SetText(ftGunName);
}

void UPlayerInterface_UW::SetPlayerHP(float fCurrentHP)
{
	HPBarFill->SetPercent(fCurrentHP);
}

