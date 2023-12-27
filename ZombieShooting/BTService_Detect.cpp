// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "ZombieShooting_AC.h"
#include "MyAICharacter.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect()
{
    NodeName = TEXT("Detect");
    Interval = 0.3f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (nullptr == ControllingPawn)
        return;

    UWorld* World = ControllingPawn->GetWorld();
    FVector Center = ControllingPawn->GetActorLocation();
    float DetectRadius = 1000.0f;

    if (nullptr == World)
        return;

    TArray<FOverlapResult> OverlapResults;
    FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
    bool bResult = World->OverlapMultiByChannel(OverlapResults, Center, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel2, FCollisionShape::MakeSphere(DetectRadius), CollisionQueryParam);

    if (bResult)
    {
        for (auto const& OverlapResult : OverlapResults)
        {
            AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
           //AMyAICharacter* MyAICharacter = Cast<AMyAICharacter>(OverlapResult.GetActor());

            //  && MyCharacter->GetController()->IsPlayerController()
            if (MyCharacter)
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsObject(AZombieShooting_AC::TargetKey, MyCharacter);
               // DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);

               // DrawDebugPoint(World, MyCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
               // DrawDebugLine(World, ControllingPawn->GetActorLocation(), MyCharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
                return;
            }

            else
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsObject(AZombieShooting_AC::TargetKey, nullptr);
            }
        }
    }
   // DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
}
