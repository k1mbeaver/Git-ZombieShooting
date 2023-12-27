// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
struct FPlayerDataTable;
class UDataTable;

UCLASS()
class ZOMBIESHOOTING_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

	// 데이터 값 얻어오기(이어하기에서 사용?)
	FString GetPlayerName();
	int GetPlayerHp();
	FString GetPlayerGun();
	int GetPlayerStage();
	float GetPlayerBgmPower();
	void SetPlayerBgmPower(float fBgmPower);
	void SetPlayerDataDefault();
	void SetPlayerStage();
	void SetPlayerGun(FString yourGun);

	// 몬스터 데이터값 얻어오기

	FString GetMonsterName(FString MonsterType);
	float GetMonsterHp(FString MonsterType);
	float GetMonsterSpeed(FString MonsterType);
	float GetMonsterAttackDamage(FString MonsterType);
	float GetMonsterAttackSpeed(FString MonsterType);
	USkeletalMesh* GetMonsterSkeletalMesh(FString MonsterType);

	// 브금 데이터 값 얻어오기
	USoundWave* GetSoundWaveBGM(FString Title);

	UPROPERTY()
		int nMonsterDeath;

	UPROPERTY()
		FString strSkeletalMesh;

	// Json 관련 (현재는 미사용)
	//void JsonSave();
	//void JsonLoad();

private:
	UPROPERTY()
		UDataTable* FPlayerTable;

	UPROPERTY()
		UDataTable* FMonsterTable;

	UPROPERTY()
		UDataTable* FSkeletalMeshTable;

	UPROPERTY()
		UDataTable* FBGMTable;
};
