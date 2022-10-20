// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "PlayerDataTableClass.h"
#include "MonsterDataTableClass.h"
#include "StaticMeshDataTableClass.h"
#include "BGMDataTableClass.h"
#include "Sound/SoundCue.h"

UMyGameInstance::UMyGameInstance()
{
	FString PlayerDataPath = TEXT("DataTable'/Game/File/Json/PlayerData.PlayerData'");
	FString MonsterDataPath = TEXT("DataTable'/Game/File/Json/MonsterData.MonsterData'");
	FString SkeletalMeshDataPath = TEXT("DataTable'/Game/File/Json/SkeletalMeshData.SkeletalMeshData'");

	//E:/Unreal/ZombieShooting/Content/File/Json/PlayerData.uasset
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABPLAYER(*PlayerDataPath);
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABMONSTER(*MonsterDataPath);
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABSKELETALMESH(*SkeletalMeshDataPath);

	if (DT_ABPLAYER.Succeeded())
	{
		FPlayerTable = DT_ABPLAYER.Object;
	}

	if (DT_ABMONSTER.Succeeded())
	{
		FMonsterTable = DT_ABMONSTER.Object;
	}

	if (DT_ABSKELETALMESH.Succeeded())
	{
		FSkeletalMeshTable = DT_ABSKELETALMESH.Object;
	}
	
	nMonsterDeath = 0;
	strSkeletalMesh = "GeneralMonster";
}

/*
void UMyGameInstance::JsonSave()
{
	
	FString jsonstr;
	TSharedRef<TJsonWriter<TCHAR>> jsonObj = TJsonWriterFactory<>::Create(&jsonstr);

	jsonObj->WriteObjectStart();
	jsonObj->WriteValue<const char*>("Name", "Player1");
	jsonObj->WriteValue<int>("Hp", 100);
	jsonObj->WriteValue<const char*>("Gun", "Riffle");
	jsonObj->WriteValue<int>("Stage", 1);
	jsonObj->WriteObjectEnd();
	jsonObj->Close();

	FFileHelper::SaveStringToFile(*jsonstr, TEXT("/Game/File/Json/PlayerData.json"));
	
}

// 이건 이어하기에서 사용하자
void UMyGameInstance::JsonLoad()
{
	
	FString result;
	FFileHelper::LoadFileToString(result, *(FPaths::GameDevelopersDir()+"PlayerData.Json"));
	TSharedPtr<FJsonValue> jsonObject;
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(result);
	if (FJsonSerializer::Deserialize(reader, jsonObject))
	{
		const TArray<TSharedPtr<FJsonValue>> arr = jsonObject->AsArray();
		for (auto it = arr.CreateConstIterator(); it; it++)
		{
			FString val = (*it)->AsObject()->GetStringField("Name");
			myPlayerData.Name = val;
			val = (*it)->AsObject()->GetStringField("Hp");
			myPlayerData.Hp = FCString::Atoi(*val);
			val = (*it)->AsObject()->GetStringField("Gun");
			myPlayerData.Gun = val;
			val = (*it)->AsObject()->GetStringField("Stage");
			myPlayerData.Stage = FCString::Atoi(*val);
		}
	}
	
}
*/
FString UMyGameInstance::GetPlayerName()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	FString PlayerName = PlayerData->PlayerName;
	return PlayerName;
}

int UMyGameInstance::GetPlayerHp()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	int PlayerHp = PlayerData->PlayerHp;
	return PlayerHp;
}

FString UMyGameInstance::GetPlayerGun()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	FString PlayerGun = PlayerData->PlayerGun;
	return PlayerGun;
}

int UMyGameInstance::GetPlayerStage()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	int PlayerStage = PlayerData->PlayerStage;
	return PlayerStage;
}

void UMyGameInstance::SetPlayerStage()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	PlayerData->PlayerStage++;
	nMonsterDeath = 0;
}

float UMyGameInstance::GetPlayerBgmPower()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	float PlayerBgmPower = PlayerData->PlayerBgmPower;
	return PlayerBgmPower;
}

void UMyGameInstance::SetPlayerBgmPower(float fBgmPower)
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	PlayerData->PlayerBgmPower = fBgmPower;
}

void UMyGameInstance::SetPlayerGun(FString yourGun)
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	PlayerData->PlayerGun = yourGun;
}

// 몬스터 데이터값 얻어오기

FString UMyGameInstance::GetMonsterName(FString MonsterType)
{
	FMonsterDataTable* MonsterData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	FString MonsterName = MonsterData->MonsterName;
	return MonsterName;
}

float UMyGameInstance::GetMonsterHp(FString MonsterType)
{
	FMonsterDataTable* MonsterData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	float MonsterHp = MonsterData->MonsterHp;
	return MonsterHp;
}

float UMyGameInstance::GetMonsterSpeed(FString MonsterType)
{
	FMonsterDataTable* MonsterData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	float MonsterSpeed = MonsterData->MonsterSpeed;
	return MonsterSpeed;
}

float UMyGameInstance::GetMonsterAttackDamage(FString MonsterType)
{
	FMonsterDataTable* MonsterData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	float MonsterAttackDamage = MonsterData->MonsterAttackDamage;
	return MonsterAttackDamage;
}

float UMyGameInstance::GetMonsterAttackSpeed(FString MonsterType)
{
	FMonsterDataTable* MonsterData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	float MonsterAttackSpeed = MonsterData->MonsterAttackSpeed;
	return MonsterAttackSpeed;
}


USkeletalMesh* UMyGameInstance::GetMonsterSkeletalMesh(FString MonsterType)
{
	FMonsterDataTable* SkeletalMeshData = FMonsterTable->FindRow<FMonsterDataTable>(*MonsterType, TEXT(""));
	USkeletalMesh* MonsterSkeletalMesh = SkeletalMeshData->MonsterSkeletalMesh;
	return MonsterSkeletalMesh;
}

USoundWave* UMyGameInstance::GetSoundWaveBGM(FString Title)
{
	FBGMDataTable* BGMData = FBGMTable->FindRow<FBGMDataTable>(*Title, TEXT(""));
	USoundWave* BGM = BGMData->BGM;
	return BGM;
}


// 여기서는 PlayerInfo말고 Default를 사용하게 해보자!
void UMyGameInstance::SetPlayerDataDefault()
{
	FPlayerDataTable* PlayerData = FPlayerTable->FindRow<FPlayerDataTable>("PlayerInfo", TEXT(""));
	FPlayerDataTable* DefaultData = FPlayerTable->FindRow<FPlayerDataTable>("Default", TEXT(""));
	PlayerData->PlayerName = DefaultData->PlayerName;
	PlayerData->PlayerHp = DefaultData->PlayerHp;
	PlayerData->PlayerGun = DefaultData->PlayerGun;
	PlayerData->PlayerStage = DefaultData->PlayerStage;
}

