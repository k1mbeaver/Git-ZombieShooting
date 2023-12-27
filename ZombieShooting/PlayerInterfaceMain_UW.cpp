// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInterfaceMain_UW.h"
#include "PlayerInterface_UW.h"
#include "GamePause_UW.h"
#include "GameOver_UW.h"
#include "GameClear_UW.h"

void UPlayerInterfaceMain_UW::SetCurrentBullet(int nCurrentBullet, bool bIsSpecial)
{
	PlayerInterface_WB->SetCurrentBullet(nCurrentBullet, bIsSpecial);
}

void UPlayerInterfaceMain_UW::SetDefaultBullet(bool bIsSpecial)
{
	PlayerInterface_WB->SetDefaultBullet(bIsSpecial);
}

void UPlayerInterfaceMain_UW::SetGunName(FString strGunName)
{
	PlayerInterface_WB->SetGunName(strGunName);
}

void UPlayerInterfaceMain_UW::SetPlayerHP(float fCurrentHP)
{
	PlayerInterface_WB->SetPlayerHP(fCurrentHP);
}

void UPlayerInterfaceMain_UW::SetGameOverUIVisible()
{
	GameOver_WB->SetGameOverUIVisible();
}

void UPlayerInterfaceMain_UW::SetGameOverUIHidden()
{
	GameOver_WB->SetGameOverUIHidden();
}

void UPlayerInterfaceMain_UW::SetGameClearUIVisible()
{
	GameClear_WB->SetGameClearUIVisible();
}

void UPlayerInterfaceMain_UW::SetGameClearUIHidden()
{
	GameClear_WB->SetGameClearUIHidden();
}

void UPlayerInterfaceMain_UW::SetGamePauseUIVisible()
{
	//GamePause_WB->SetGamePauseUIVisible();
	GamePause_WB->SetVisibility(ESlateVisibility::Visible);
}

void UPlayerInterfaceMain_UW::SetGamePauseUIHidden()
{
	//GamePause_WB->SetGamePauseUIHidden();
	GamePause_WB->SetVisibility(ESlateVisibility::Hidden);
}