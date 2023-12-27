// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnOnCollisonStart_AttackDelegate); // 공격 시작
DECLARE_MULTICAST_DELEGATE(FOnOnCollisonEnded_AttackDelegate); // 공격 끝


/**
 * 
 */
UCLASS()
class ZOMBIESHOOTING_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UAIAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayAttackMontage();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;

	FOnOnCollisonStart_AttackDelegate OnOnCollisonStart_Attack;
	FOnOnCollisonEnded_AttackDelegate OnOnCollisonEnd_Attack;

	FName GetAttackMontageSectionName(int32 Section);
	void SetDeadAnim();

private:
	UFUNCTION()
		void AnimNotify_OnAttackStart();
	UFUNCTION()
		void AnimNotify_OnAttackEnded();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed; // AnimInstance를 사용해서 C++ 스크립팅 한 것을 블루프린트에서 사용이 가능하다.

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsDead;

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;
};
