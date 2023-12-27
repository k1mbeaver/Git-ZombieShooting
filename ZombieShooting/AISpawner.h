// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AISpawner.generated.h"

UCLASS()
class ZOMBIESHOOTING_API AAISpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAISpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = AI, Meta = (AllowPrivateAccess = true))
		//int nHowManyAI;

	UFUNCTION(BlueprintCallable)
		int GetPlayerStageAI();

	UFUNCTION(BlueprintCallable)
		int RandomTransform(int min, int max);

	UFUNCTION(BlueprintCallable)
		FVector GiveFVector();

	UFUNCTION(BlueprintCallable)
		void SetMonsterOption(int nIndex);

	UPROPERTY(VisibleAnywhere, Category = Monster)
		int nMonsterDeath;

	//UPROPERTY(VisibleAnywhere, Category = Monster)
		//class AMyAICharacter* DefaultAI;

};
