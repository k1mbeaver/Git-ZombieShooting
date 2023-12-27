// Fill out your copyright notice in the Description page of Project Settings.


#include "AIAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UAIAnimInstance::UAIAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
	IsDead = false;
	IsAttacking = false;
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/ParagonGrux/Characters/Heroes/Grux/Animations/PrimaryAttack_LA_Fast_Montage.PrimaryAttack_LA_Fast_Montage'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}
}

void UAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner(); // 폰에 접근해서 폰의 속력 값을 얻어온다.
	if (!::IsValid(Pawn)) return;

	if (!IsDead)
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UAIAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
}

void UAIAnimInstance::SetDeadAnim()
{
	IsDead = true;
}

FName UAIAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}

void UAIAnimInstance::AnimNotify_OnAttackStart()
{
	OnOnCollisonStart_Attack.Broadcast();
}

void UAIAnimInstance::AnimNotify_OnAttackEnded()
{
	OnOnCollisonEnd_Attack.Broadcast();
}