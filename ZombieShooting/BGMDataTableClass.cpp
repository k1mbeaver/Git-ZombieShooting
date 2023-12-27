// Fill out your copyright notice in the Description page of Project Settings.


#include "BGMDataTableClass.h"
#include "Sound/AmbientSound.h"
#include "Sound/SoundCue.h"

// Sets default values
ABGMDataTableClass::ABGMDataTableClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABGMDataTableClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABGMDataTableClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

