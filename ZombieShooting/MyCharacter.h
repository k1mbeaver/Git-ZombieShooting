// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZombieShooting.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UENUM(BlueprintType)
enum class EGunState : uint8
{
	SHOTGUN, // 3발 나감
	BASIC, // 일반
	HEAVYBASIC, // 일반보다 딜이 더 썜
};


UCLASS()
class ZOMBIESHOOTING_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamasgeCauser) override;
	virtual void Jump() override;
	virtual void StopJumping() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		class USpringArmComponent* SpringArm;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		class UCameraComponent* Camera;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AZombieShootingProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HP)
		float fPlayerHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HP)
		float fMaxHp;

	/** AnimMontage to play each time we fire */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//UAnimMontage* FireAnimation;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* MuzzleLocation;

	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ShotgunMuzzleLocationOne;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ShotgunMuzzleLocationTwo;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ShotgunMuzzleLocationThree;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ShotgunMuzzleLocationFour;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ShotgunMuzzleLocationFive;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(VisibleInstanceOnly, Category = Animation)
		class UCharacterAnimInstance* CharacterAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		EGunState myGun;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		int nSpecialGunBullet;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bIsRun;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bPlayerPause;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bCanMove;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bIsPlayerControlled;

	UPROPERTY()
		class UParticleSystem* FireParticle;

	UPROPERTY()
		class UGameplayStatics* GameStatic;

	void StartSettingGun(); // 시작할 때 총 초기화

	void PlaySettingGun(FString yourGun); // 플레이 중 총 초기화
	/*
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, Replicated, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackPower;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	UPROPERTY(VisibleInstanceOnly, Replicated, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, Replicated, Category = Speed)
		float fSprintSpeedMultiPlayer; // 달리기
	*/
	//UPROPERTY(VisibleInstanceOnly, Replicated, Category = Animation)
	//UPROPERTY(VisibleInstanceOnly, Category = Animation)
		//class UABAnimInstance* ABAnim;

public:
	void UpDown(float NewAxisValue);

	void LeftRight(float NewAxisValue);

	void LookUp(float NewAxisValue);

	void Turn(float NewAxisValue);

	void Attack();

	void Run();

	void StopRun();

	void OnFire();

	void ReadyFire();

	void ResetReadyFire();

	void PlayerPause();
};
