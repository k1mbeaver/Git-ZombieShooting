// Fill out your copyright notice in the Description page of Project Settings.


#include "Setting_UW.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Title_PC.h"

void USetting_UW::NativeConstruct()
{
	Super::NativeConstruct();

	BtBack->OnClicked.AddDynamic(this, &USetting_UW::BackHandler);
	BtCheck->OnClicked.AddDynamic(this, &USetting_UW::CheckHandler);
}

void USetting_UW::BackHandler()
{
	// 여기다가 PC 연결
	ATitle_PC* MyPC = Cast<ATitle_PC>(GetOwningPlayer());
	if (MyPC)
	{
		MyPC->BackSetting();
	}
}

void USetting_UW::CheckHandler()
{
	// 여기다가 PC 연결
	ATitle_PC* MyPC = Cast<ATitle_PC>(GetOwningPlayer());
	if (MyPC)
	{
		MyPC->CheckSetting(); 
	}
}

void USetting_UW::VisibleSetting()
{
	SetVisibility(ESlateVisibility::Visible);
}

void USetting_UW::HiddenSetting()
{
	SetVisibility(ESlateVisibility::Hidden);
}

// Setting창 껏다가 다시 킬 때

void USetting_UW::SetBgmSlider(float fBgmSlider)
{
	SD_BGM->SetValue(fBgmSlider);
}

float USetting_UW::GetBgmPower()
{
	return SD_BGM->GetValue();
}