// Fill out your copyright notice in the Description page of Project Settings.


#include "MainSetting_UW.h"
#include "Setting_UW.h"

void UMainSetting_UW::VisibleSetting()
{
	Setting_WB->VisibleSetting();
}

void UMainSetting_UW::HiddenSetting()
{
	Setting_WB->HiddenSetting();
}

// Setting창 껏다가 다시 킬 때

void UMainSetting_UW::SetBgmSlider(float fBgmSlider)
{
	Setting_WB->SetBgmSlider(fBgmSlider);
}

float UMainSetting_UW::GetBgmPower()
{
	return Setting_WB->GetBgmPower();
}
