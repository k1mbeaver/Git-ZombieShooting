// Fill out your copyright notice in the Description page of Project Settings.


#include "AISpawner.h"
#include "NavigationSystem.h"
#include "MyAICharacter.h"
#include "MyGameInstance.h"
#include <random>

// Sets default values
AAISpawner::AAISpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*
	static ConstructorHelpers::FObjectFinder<AMyAICharacter> AI_CHARACTER(TEXT("Blueprint'/Game/BluePrints/BP_MyAICharacter.BP_MyAICharacter'"));
	if (AI_CHARACTER.Succeeded())
	{
		DefaultAI = AI_CHARACTER.Object;
	}
	*/
}

void AAISpawner::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	//nHowManyAI = MyGI->GetPlayerStage();
}

// Called when the game starts or when spawned
void AAISpawner::BeginPlay()
{
	Super::BeginPlay();


	/*
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	
	for (int i = 0; i < 3; i++)
	{
		FNavLocation SpawnLocation;
		NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 4000.0f, SpawnLocation);

		(AMyAICharacter*)GetWorld()->SpawnActor(DefaultAI, SpawnLocation.Location, FName("Monster"));
	}
	*/
}

// Called every frame
void AAISpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AAISpawner::GetPlayerStageAI()
{
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	int nHowManyAI = MyGI->GetPlayerStage();

	return nHowManyAI;
}

int AAISpawner::RandomTransform(int min, int max)
{
	std::random_device rd;
	std::mt19937_64 rEngine(rd());
	std::uniform_int_distribution<>dist(min, max);
	return static_cast<int>(dist(rEngine));
}

FVector AAISpawner::GiveFVector()
{
	int nDestinationX, nDestinationY;
	nDestinationX = RandomTransform(-110, 550); // -110 ~ 550 (x) // 700 ~ -2100 (y)
	nDestinationY = RandomTransform(-2100, 700);

	return FVector(nDestinationX, nDestinationY, 250);
}

void AAISpawner::SetMonsterOption(int nIndex)
{
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();

	if (nIndex % 20 == 0)
	{
		MyGI->strSkeletalMesh = "Tank";
	}

	else if (nIndex % 10 == 0)
	{
		MyGI->strSkeletalMesh = "Speed";
	}

	else if (nIndex % 5 == 0)
	{
		MyGI->strSkeletalMesh = "Damage";
	}

	else
	{
		MyGI->strSkeletalMesh = "GeneralMonster";
	}
}
