// Fill out your copyright notice in the Description page of Project Settings.


#include "GameClear_UW.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void UGameClear_UW::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BtNext = Cast<UButton>(GetWidgetFromName(TEXT("BtNext")));
	BtSaveAndOut = Cast<UButton>(GetWidgetFromName(TEXT("BtSaveAndOut")));
}

void UGameClear_UW::NativeConstruct()
{
	Super::NativeConstruct();

	BtNext->OnClicked.AddDynamic(this, &UGameClear_UW::NextHandler);
	BtSaveAndOut->OnClicked.AddDynamic(this, &UGameClear_UW::QuitHandler);
}

void UGameClear_UW::SetGameClearUIVisible()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UGameClear_UW::SetGameClearUIHidden()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UGameClear_UW::NextHandler()
{
	GameStatic->SetGamePaused(GetWorld(), false);

	FInputModeGameOnly InputMode;
	UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(false);

	UGameplayStatics::OpenLevel(GetWorld(), FName("ConceptMap"));
}

void UGameClear_UW::QuitHandler()
{

}
