// Fill out your copyright notice in the Description page of Project Settings.


#include "MainTitle_HUD.h"
#include "MainTitle_UW.h"
#include "MainSetting_UW.h"

AMainTitle_HUD::AMainTitle_HUD()
{
	static ConstructorHelpers::FClassFinder<UMainTitle_UW> WB_Main(TEXT("WidgetBlueprint'/Game/Widget/MainTitle_WB.MainTitle_WB_C'"));
	if (WB_Main.Succeeded())
	{
		MainUIClass = WB_Main.Class;
	}

	static ConstructorHelpers::FClassFinder<UMainSetting_UW> WB_Setting(TEXT("WidgetBlueprint'/Game/Widget/MainSetting_WB.MainSetting_WB_C'"));
	if (WB_Setting.Succeeded())
	{
		SettingUIClass = WB_Setting.Class;
	}
}

void AMainTitle_HUD::BeginPlay()
{
	Super::BeginPlay();

	CheckUIObject(); // 시작하면 UI를 생성한다.
}

void AMainTitle_HUD::VisibleSetting()
{
	SettingUIObject->VisibleSetting();
}

void AMainTitle_HUD::HiddenSetting()
{
	SettingUIObject->HiddenSetting();
}

float AMainTitle_HUD::GetBgmPower()
{
	return SettingUIObject->GetBgmPower();
}

void AMainTitle_HUD::SetBgmSlider(float fBgmPower)
{
	SettingUIObject->SetBgmSlider(fBgmPower);
}

bool AMainTitle_HUD::CheckUIObject()
{
	if (MainUIObject == nullptr && SettingUIObject == nullptr) // UI가 없다면 생성.
	{
		return CreateUIObject();
	}

	return true; // 있다면 True.
}

bool AMainTitle_HUD::CreateUIObject()
{
	if (MainUIClass && SettingUIClass)
	{
		MainUIObject = CreateWidget<UMainTitle_UW>(GetOwningPlayerController(), MainUIClass);
		SettingUIObject = CreateWidget<UMainSetting_UW>(GetOwningPlayerController(), SettingUIClass);
		if (MainUIObject && SettingUIObject)
		{
			MainUIObject->AddToViewport();
			SettingUIObject->AddToViewport();
			return true; // 만들었다면 true.
		}
	}

	return false; // 못 만들었다면 false.
}