// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "StaticMeshDataTableClass.generated.h"

USTRUCT(BlueprintType)
struct FStaticMeshDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// ¸ó½ºÅÍ ½ºÄÌ·¹Å» ¸Þ½Ã
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMesh* MonsterMesh;
};

UCLASS()
class ZOMBIESHOOTING_API AStaticMeshDataTableClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStaticMeshDataTableClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
