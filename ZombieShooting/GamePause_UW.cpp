// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePause_UW.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void UGamePause_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BtResume = Cast<UButton>(GetWidgetFromName(TEXT("BtResume")));
	BtSaveAndOut = Cast<UButton>(GetWidgetFromName(TEXT("BtSaveAndOut")));
}

void UGamePause_UW::NativeConstruct()
{
	Super::NativeConstruct();

	BtResume->OnClicked.AddDynamic(this, &UGamePause_UW::ResumeHandler);
	BtSaveAndOut->OnClicked.AddDynamic(this, &UGamePause_UW::QuitHandler);
}

void UGamePause_UW::SetGamePauseUIVisible()
{
	this->SetVisibility(ESlateVisibility::Visible);
}

void UGamePause_UW::SetGamePauseUIHidden()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UGamePause_UW::ResumeHandler()
{
	GameStatic->SetGamePaused(GetWorld(), false);

	FInputModeGameOnly InputMode;
	UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(false);
	SetGamePauseUIHidden();
}

void UGamePause_UW::QuitHandler()
{

}
