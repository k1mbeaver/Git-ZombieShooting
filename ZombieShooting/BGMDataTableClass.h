// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "BGMDataTableClass.generated.h"

USTRUCT(BlueprintType)
struct FBGMDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 타이틀 브금
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USoundWave* BGM;
};

UCLASS()
class ZOMBIESHOOTING_API ABGMDataTableClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABGMDataTableClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
