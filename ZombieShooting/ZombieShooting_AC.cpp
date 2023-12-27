// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieShooting_AC.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAICharacter.h"

const FName AZombieShooting_AC::HomePosKey(TEXT("HomePos"));
const FName AZombieShooting_AC::PatrolPosKey(TEXT("PatrolPos"));
const FName AZombieShooting_AC::TargetKey(TEXT("Target"));

AZombieShooting_AC::AZombieShooting_AC(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/Game/BluePrints/AI/BT_ZombieAI.BT_ZombieAI'"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}

	BTAsset_Component = object_initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BBAsset = object_initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void AZombieShooting_AC::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BTAsset);
	BTAsset_Component->StartTree(*BTAsset);
}

void AZombieShooting_AC::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}

UBlackboardComponent* AZombieShooting_AC::get_blackboard() const
{
	return BBAsset;
}

void AZombieShooting_AC::RunAI()
{
	if (BBAsset)
	{
		BBAsset->InitializeBlackboard(*BTAsset->BlackboardAsset);
	}
}

void AZombieShooting_AC::StopAI()
{
	if (this == nullptr) // 서버, 클라이언트 할때는 이거 해줘야하나?
	{
		return;
	}

	BTAsset_Component->StopTree(EBTStopMode::Safe);
}
