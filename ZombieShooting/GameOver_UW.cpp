// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOver_UW.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void UGameOver_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BtReplay = Cast<UButton>(GetWidgetFromName(TEXT("BtReplay")));
	BtSaveAndOut = Cast<UButton>(GetWidgetFromName(TEXT("BtSaveAndOut")));
}

void UGameOver_UW::NativeConstruct()
{
	Super::NativeConstruct();

	BtReplay->OnClicked.AddDynamic(this, &UGameOver_UW::ReplayHandler);
	BtSaveAndOut->OnClicked.AddDynamic(this, &UGameOver_UW::QuitHandler);
}

void UGameOver_UW::SetGameOverUIVisible()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UGameOver_UW::SetGameOverUIHidden()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UGameOver_UW::ReplayHandler()
{
	GameStatic->SetGamePaused(GetWorld(), false);

	FInputModeGameOnly InputMode;
	UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(false);
	SetGameOverUIHidden();

	UGameplayStatics::OpenLevel(GetWorld(), FName("ConceptMap"));
}

void UGameOver_UW::QuitHandler()
{

}
