// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZombieShooting.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "MyAICharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class ZOMBIESHOOTING_API AMyAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyAICharacter();

	UPROPERTY(VisibleInstanceOnly, Category = Animation)
		class UAIAnimInstance* AIAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackPower;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		float fAIHp;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		float fMaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* DeathSound;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		class UWidgetComponent* AIWidget;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		class UStaticMeshComponent* HPStatic;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		class UAIHPBar_UW* MonsterHpBar;

	UPROPERTY(EditDefaultsOnly, Category = HP)
		TSubclassOf<class UUserWidget> MONSTER_HPClass;

	// damage particle
	UPROPERTY()
		class UParticleSystem* DamageParticle;

	UPROPERTY()
		class UGameplayStatics* GameStatic;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* MuzzleLocation;

	int nMonsterCount;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;

	// TakeDamage의 경우에도 다시 해보자
	//float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void Attack();
	void AttackCheck();
	FOnAttackEndDelegate OnAttackEnd; //델리게이트 변수 선언
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void AttackByPlayer(float DamageAmount);
	void StopAIController();
	void InitializeAI(FString MonsterType);

};
