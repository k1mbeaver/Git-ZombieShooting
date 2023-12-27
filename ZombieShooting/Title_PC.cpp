// Fill out your copyright notice in the Description page of Project Settings.


#include "Title_PC.h"
#include "MainTitle_UW.h"
#include "Setting_UW.h"
#include "MainTitle_HUD.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "AudioDevice.h"

ATitle_PC::ATitle_PC()
{
	static ConstructorHelpers::FClassFinder<UMainTitle_UW> WBTitle(TEXT("WidgetBlueprint'/Game/Widget/MainTitle_WB.MainTitle_WB_C'"));
	if (WBTitle.Succeeded())
	{
		TitleUIClass = WBTitle.Class;
	}
}

void ATitle_PC::BeginPlay()
{
	Super::BeginPlay();

	TitleUIObject = CreateWidget<UMainTitle_UW>(this, TitleUIClass);
	TitleUIObject->AddToViewport();
	TitleUIObject->SetVisibility(ESlateVisibility::Hidden);

	SetShowMouseCursor(true);
	SetInputMode(FInputModeUIOnly());

	FTimerHandle StartAnimDelayTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(StartAnimDelayTimerHandle, FTimerDelegate::CreateLambda([&]()
		{
			TitleUIObject->SetVisibility(ESlateVisibility::Visible);
		}), 1.0f, false);
}

void ATitle_PC::PlayGame()
{
	// 여기서 GameInstance를 사용해서 Json 파일을 디폴트 값으로 설정하고
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	MyGI->SetPlayerDataDefault();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, MyGI->GetPlayerGun());
	// 그거에 맞는 레벨을 실행한다. (이거도 GameInstance 값 따라서 OpenLevel 하도록 설정하자)
	//UGameplayStatics::OpenLevel(GetWorld(), FName("FirstPersonExampleMap"));
	UGameplayStatics::OpenLevel(GetWorld(), FName("ConceptMap"));
}

void ATitle_PC::ReplayGame()
{
	// 여기서 GameInstance를 사용해서 원래 있던 Json 파일을 읽어와서 그 값대로 
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, MyGI->GetPlayerGun());
	// 그거에 맞는 레벨을 실행한다. (이거도 GameInstance 값 따라서 OpenLevel 하도록 설정하자)
	//UGameplayStatics::OpenLevel(GetWorld(), FName("FirstPersonExampleMap"));
	UGameplayStatics::OpenLevel(GetWorld(), FName("ConceptMap"));
}

void ATitle_PC::SettingGame()
{
	AMainTitle_HUD* HUD = GetHUD<AMainTitle_HUD>();
	if (HUD == nullptr) return;
	// 현재 GameInstance의 볼륨 값에 따라서 Slider 값이 달라진다.

	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();

	HUD->SetBgmSlider(MyGI->GetPlayerBgmPower()); // 여기서 gameinstance값을 가져온다.
	// 그 후에 Setting 창을 띄운다.

	HUD->VisibleSetting();
}

void ATitle_PC::BackSetting()
{
	AMainTitle_HUD* HUD = GetHUD<AMainTitle_HUD>();
	if (HUD == nullptr) return;

	HUD->HiddenSetting();
}

void ATitle_PC::CheckSetting()
{
	AMainTitle_HUD* HUD = GetHUD<AMainTitle_HUD>();
	if (HUD == nullptr) return;
	// 입력한 값에 따라서 GameInstance값이 달라진다.
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	MyGI->SetPlayerBgmPower(HUD->GetBgmPower()); // 여기서 값을 GameInstance에 넣는다.
	// 그 후에 setting 창을 숨긴다.

	HUD->HiddenSetting();
}

void ATitle_PC::ExitGame()
{
	// 종료
}