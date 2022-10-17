// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieShooting_PC.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AZombieShooting_PC::AZombieShooting_PC()
{

}

void AZombieShooting_PC::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	if (aPawn)
	{
		myCharacter = Cast<AMyCharacter>(aPawn);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Success!"));
		SetInputMode(FInputModeGameOnly());
	}
}

void AZombieShooting_PC::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Possess!"));
}

void AZombieShooting_PC::SetupInputComponent()
{
	Super::SetupInputComponent();

	//AABCharacter* myCharacter = Cast<AABCharacter>(myPawn);

	// 캐릭터 이동 함수
	//InputComponent->BindAxis(TEXT("MoveForward"), this, &AZombieShooting_PC::UpDown);
	//InputComponent->BindAxis(TEXT("MoveRight"), this, &AZombieShooting_PC::LeftRight);
	//InputComponent->BindAxis(TEXT("LookUp"), this, &AZombieShooting_PC::LookUp);
	//InputComponent->BindAxis(TEXT("Turn"), this, &AZombieShooting_PC::Turn);

	// 캐릭터 점프 함수
	InputComponent->BindAction("Jump", IE_Pressed, this, &AZombieShooting_PC::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AZombieShooting_PC::StopJumping);

	// 캐릭터 공격 함수
	InputComponent->BindAction("Fire", IE_Pressed, this, &AZombieShooting_PC::OnFire);

	// 캐릭터 달리기 함수
	InputComponent->BindAction("Run", IE_Pressed, this, &AZombieShooting_PC::Run);
	InputComponent->BindAction("Run", IE_Released, this, &AZombieShooting_PC::StopRun);

	// 캐릭터 견착 함수
	InputComponent->BindAction("ReadyFire", IE_Pressed, this, &AZombieShooting_PC::ReadyFire);
	InputComponent->BindAction("ReadyFire", IE_Released, this, &AZombieShooting_PC::ResetReadyFire);

	// 플레이어 일시정지 함수
	InputComponent->BindAction("Pause", IE_Pressed, this, &AZombieShooting_PC::PlayerPause);
}

/*
void AZombieShooting_PC::UpDown(float NewAxisValue)
{
	if (myCharacter)
	{
		myCharacter->UpDown(NewAxisValue);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("UpDown!"));
	}
}

void AZombieShooting_PC::LeftRight(float NewAxisValue)
{
	if (myCharacter)
	{
		myCharacter->LeftRight(NewAxisValue);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("LeftRight!"));
	}
}

void AZombieShooting_PC::LookUp(float NewAxisValue)
{
	if (myCharacter)
	{
		myCharacter->LookUp(NewAxisValue);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("LookUp!"));
	}
}

void AZombieShooting_PC::Turn(float NewAxisValue)
{
	if (myCharacter)
	{
		myCharacter->Turn(NewAxisValue);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Turn!"));
	}
}
*/

void AZombieShooting_PC::Jump()
{
	if (myCharacter != nullptr)
	{
		myCharacter->Jump();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Jump!"));
	}
}

void AZombieShooting_PC::StopJumping()
{
	if (myCharacter != nullptr)
	{
		myCharacter->StopJumping();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("StopJumping!"));
	}
}

void AZombieShooting_PC::ReadyFire()
{
	if (myCharacter != nullptr)
	{
		myCharacter->ReadyFire();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ReadyFire!"));
	}
}

void AZombieShooting_PC::ResetReadyFire()
{
	if (myCharacter != nullptr)
	{
		myCharacter->ResetReadyFire();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ResetReadyFire!"));
	}
}

void AZombieShooting_PC::OnFire()
{
	if (myCharacter != nullptr)
	{
		myCharacter->OnFire();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("OnFire!"));
	}
}

void AZombieShooting_PC::Run()
{
	if (myCharacter != nullptr)
	{
		myCharacter->Run();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Run!"));
	}
}

void AZombieShooting_PC::StopRun()
{
	if (myCharacter != nullptr)
	{
		myCharacter->StopRun();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("StopRun!"));
	}
}

void AZombieShooting_PC::PlayerPause()
{
	if (myCharacter != nullptr)
	{
		myCharacter->PlayerPause();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("PlayerPause!"));
	}
}