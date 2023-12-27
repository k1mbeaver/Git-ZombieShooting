// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MyAICharacter.h"
#include "ZombieShooting_AC.h"

UBTTask_Attack::UBTTask_Attack()
{
    bNotifyTick = true;
    IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

    auto MyAICharacter = Cast<AMyAICharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (MyAICharacter == nullptr)
        return EBTNodeResult::Failed;

    MyAICharacter->Attack();
    IsAttacking = true;
    MyAICharacter->OnAttackEnd.AddLambda([this]() -> void {
        IsAttacking = false;
        });

    return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
    if (!IsAttacking)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}
