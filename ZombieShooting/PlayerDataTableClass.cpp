// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDataTableClass.h"

// Sets default values
APlayerDataTableClass::APlayerDataTableClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerDataTableClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerDataTableClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

