// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterHP_UW.h"
#include "Components/ProgressBar.h"

void UMonsterHP_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	HPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("HPBar")));
}

void UMonsterHP_UW::SetMonsterHP(float fCurrentHP)
{
	HPBar->SetPercent(fCurrentHP);
}
