// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAmbientSound.h"
#include "Sound/SoundCue.h"
#include "MyGameInstance.h"

AMyAmbientSound::AMyAmbientSound()
{
	
}


void AMyAmbientSound::BeginPlay()
{
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	
	//TitleBGM = MyGI->GetSoundCueBGM("Title");
}