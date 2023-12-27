// Fill out your copyright notice in the Description page of Project Settings.


#include "AIHPBar_UW.h"
#include "Components/ProgressBar.h"

void UAIHPBar_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	AIHPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("AIHPBar")));
}

void UAIHPBar_UW::SetMonsterHP(float fCurrentHP)
{
	AIHPBar->SetPercent(fCurrentHP);
}

