// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "MonsterDataTableClass.generated.h"

USTRUCT(BlueprintType)
struct FMonsterDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MonsterName;

	// HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MonsterHp;

	// 몬스터 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MonsterType;

	// 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MonsterSpeed;

	// 공격 데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MonsterAttackDamage;

	// 공격속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MonsterAttackSpeed;

};

UCLASS()
class ZOMBIESHOOTING_API AMonsterDataTableClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterDataTableClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
