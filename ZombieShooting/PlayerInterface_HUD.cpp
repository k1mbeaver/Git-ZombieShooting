// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInterface_HUD.h"
#include "PlayerInterfaceMain_UW.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

APlayerInterface_HUD::APlayerInterface_HUD()
{
	static ConstructorHelpers::FClassFinder<UPlayerInterfaceMain_UW> WB_Main(TEXT("WidgetBlueprint'/Game/Widget/PlayerInterfaceMain_WB'"));
	if (WB_Main.Succeeded())
	{
		MainUIClass = WB_Main.Class;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}

void APlayerInterface_HUD::BeginPlay()
{
	Super::BeginPlay();

	CheckUIObject(); // 시작하면 UI를 생성한다.
	bPlayerCross = false;
}

bool APlayerInterface_HUD::CheckUIObject()
{
	if (MainUIObject == nullptr) // UI가 없다면 생성.
	{
		return CreateUIObject();
	}
	return true; // 있다면 True.
}

bool APlayerInterface_HUD::CreateUIObject()
{
	if (MainUIClass)
	{
		MainUIObject = CreateWidget<UPlayerInterfaceMain_UW>(GetOwningPlayerController(), MainUIClass);
		if (MainUIObject)
		{
			MainUIObject->AddToViewport();
			return true; // 만들었다면 true.
		}
	}
	return false; // 못 만들었다면 false.
}

void APlayerInterface_HUD::SetCurrentBullet(int nCurrentBullet, bool bIsSpecial)
{
	MainUIObject->SetCurrentBullet(nCurrentBullet, bIsSpecial);
}

void APlayerInterface_HUD::SetDefaultBullet(bool bIsSpecial)
{
	MainUIObject->SetDefaultBullet(bIsSpecial);
}

void APlayerInterface_HUD::SetGunName(FString strGunName)
{
	MainUIObject->SetGunName(strGunName);
}

void APlayerInterface_HUD::SetPlayerHP(float fCurrentHP)
{
	MainUIObject->SetPlayerHP(fCurrentHP);
}

void APlayerInterface_HUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	if (bPlayerCross)
	{
		// find center of the Canvas
		const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
		const FVector2D CrosshairDrawPosition((Center.X),
			(Center.Y + 20.0f));

		// draw the crosshair
		FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}

void APlayerInterface_HUD::SetGameOverUIVisible()
{
	MainUIObject->SetGameOverUIVisible();
}

void APlayerInterface_HUD::SetGameOverUIHidden()
{
	MainUIObject->SetGameOverUIHidden();
}

void APlayerInterface_HUD::SetGameClearUIVisible()
{
	MainUIObject->SetGameClearUIVisible();
}

void APlayerInterface_HUD::SetGameClearUIHidden()
{
	MainUIObject->SetGameClearUIHidden();
}

void APlayerInterface_HUD::SetGamePauseUIVisible()
{
	MainUIObject->SetGamePauseUIVisible();
}

void APlayerInterface_HUD::SetGamePauseUIHidden()
{
	MainUIObject->SetGamePauseUIHidden();
}
