	// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "ZombieShootingProjectile.h"
#include "CharacterAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "MyGameInstance.h"
#include "Particles/ParticleSystem.h"
#include "PlayerInterface_HUD.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyCharacter::AMyCharacter()
{

	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));


	SpringArm->bUsePawnControlRotation = true; // LookUp을 위함
	//Camera->bUsePawnControlRotation = true;

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->SetupAttachment(GetCapsuleComponent());
	MuzzleLocation->SetRelativeLocation(FVector(100.0f, 15.0f, 40.0f));

	
	ShotgunMuzzleLocationOne = CreateDefaultSubobject<USceneComponent>(TEXT("ShotgunMuzzleLocationOne"));
	ShotgunMuzzleLocationOne->SetupAttachment(GetCapsuleComponent());
	ShotgunMuzzleLocationOne->SetRelativeLocationAndRotation(FVector(100.0f, -45.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

	ShotgunMuzzleLocationTwo = CreateDefaultSubobject<USceneComponent>(TEXT("ShotgunMuzzleLocationTwo"));
	ShotgunMuzzleLocationTwo->SetupAttachment(GetCapsuleComponent());
	ShotgunMuzzleLocationTwo->SetRelativeLocationAndRotation(FVector(100.0f, -15.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

	ShotgunMuzzleLocationThree = CreateDefaultSubobject<USceneComponent>(TEXT("ShotgunMuzzleLocationThree"));
	ShotgunMuzzleLocationThree->SetupAttachment(GetCapsuleComponent());
	ShotgunMuzzleLocationThree->SetRelativeLocationAndRotation(FVector(100.0f, 15.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

	ShotgunMuzzleLocationFour = CreateDefaultSubobject<USceneComponent>(TEXT("ShotgunMuzzleLocationFour"));
	ShotgunMuzzleLocationFour->SetupAttachment(GetCapsuleComponent());
	ShotgunMuzzleLocationFour->SetRelativeLocationAndRotation(FVector(100.0f, 45.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

	ShotgunMuzzleLocationFive = CreateDefaultSubobject<USceneComponent>(TEXT("ShotgunMuzzleLocationFive"));
	ShotgunMuzzleLocationFive->SetupAttachment(GetCapsuleComponent());
	ShotgunMuzzleLocationFive->SetRelativeLocationAndRotation(FVector(100.0f, 75.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_EASYMODEL(TEXT("/Game/File/Mesh/Murdock.Murdock"));
	if (SK_EASYMODEL.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_EASYMODEL.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	//static ConstructorHelpers::FClassFinder<UAnimInstance> PLAYER_ANIM(TEXT("/Game/BluePrints/Murdock_AnimBlueprint.Murdock_AnimBlueprint_C"));
	static ConstructorHelpers::FClassFinder<UAnimInstance> PLAYER_ANIM(TEXT("/Game/BluePrints/Character_AnimBlueprint.Character_AnimBlueprint_C"));
	if (PLAYER_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(PLAYER_ANIM.Class);
	}

	// bullet effect
	static ConstructorHelpers::FObjectFinder<UParticleSystem> FIRE(TEXT("ParticleSystem'/Game/ParagonMurdock/FX/Particles/Abilities/SpreadShot/FX/P_SpreadShotImpact_Radial.P_SpreadShotImpact_Radial'"));
	if (FIRE.Succeeded())
	{
		FireParticle = FIRE.Object;
	}

	GetCharacterMovement()->JumpZVelocity = 400.0f;
	GetCharacterMovement()->MaxWalkSpeed = 200.0f;

	// 캐릭터가 자연스럽게 회전하게 
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("MyCharacter"));

	IsAttacking = false;

	fMaxHp = 100.0f;
	fPlayerHp = 100.0f;

	nSpecialGunBullet = 30;

	bIsRun = false;
	bPlayerPause = false;
	bCanMove = true;
	bIsPlayerControlled = false;

	//myGun = EGunState::BASIC;
}

void AMyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	CharacterAnim = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());
}


// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	StartSettingGun();
	bIsRun = false;// 시작할 때 달리기 느려지는 오류 대처
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 캐릭터 이동 함수
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyCharacter::Turn);
	/*
	// 캐릭터 점프 함수
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// 캐릭터 공격 함수
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnFire);

	// 캐릭터 달리기 함수
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacter::Run);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AMyCharacter::StopRun);

	// 캐릭터 견착 함수
	PlayerInputComponent->BindAction("ReadyFire", IE_Pressed, this, &AMyCharacter::ReadyFire);
	PlayerInputComponent->BindAction("ReadyFire", IE_Released, this, &AMyCharacter::ResetReadyFire);

	// 플레이어 일시정지 함수
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AMyCharacter::PlayerPause);
	*/
}

void AMyCharacter::UpDown(float NewAxisValue)
{
	if (bCanMove)
	{
		FVector Direction = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X);
		Direction.Z = 0.0f;
		Direction.Normalize();
		AddMovementInput(Direction, NewAxisValue);
	}
}

void AMyCharacter::LeftRight(float NewAxisValue)
{
	if (bCanMove)
	{
		FVector Direction = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y);
		Direction.Z = 0.0f;
		Direction.Normalize();
		AddMovementInput(Direction, NewAxisValue);
	}
}

void AMyCharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}

void AMyCharacter::Turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void AMyCharacter::ReadyFire()
{
	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD == nullptr) return;
	HUD->bPlayerCross = true;

	Camera->SetRelativeLocation(FVector(450.0f, 0.0f, 30.0f));
}

void AMyCharacter::ResetReadyFire()
{
	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD == nullptr) return;
	HUD->bPlayerCross = false;

	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

void AMyCharacter::Jump()
{
	Super::Jump();
}

void AMyCharacter::StopJumping()
{
	Super::StopJumping();
}

void AMyCharacter::OnFire()
{
	auto AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (nullptr == AnimInstance) return;

	GameStatic->SpawnEmitterAttached(FireParticle, MuzzleLocation, FName("MuzzleLocation"));

	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD == nullptr) return;

	AnimInstance->PlayAttackMontage();

	if (myGun == EGunState::SHOTGUN)
	{
		nSpecialGunBullet -= 1; // 탄알 감소

		HUD->SetCurrentBullet(nSpecialGunBullet, true);

		// try and fire a projectile
		if (ProjectileClass != nullptr)
		{
			UWorld* const World = GetWorld();

			if (World != nullptr)
			{
				const FRotator SpawnRotationOne = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocationOne = ((ShotgunMuzzleLocationOne != nullptr) ? ShotgunMuzzleLocationOne->GetComponentLocation() : GetActorLocation());

				const FRotator SpawnRotationTwo = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocationTwo = ((ShotgunMuzzleLocationTwo != nullptr) ? ShotgunMuzzleLocationTwo->GetComponentLocation() : GetActorLocation());

				const FRotator SpawnRotationThree = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocationThree = ((ShotgunMuzzleLocationThree != nullptr) ? ShotgunMuzzleLocationThree->GetComponentLocation() : GetActorLocation());

				const FRotator SpawnRotationFour = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocationFour = ((ShotgunMuzzleLocationFour != nullptr) ? ShotgunMuzzleLocationFour->GetComponentLocation() : GetActorLocation());

				const FRotator SpawnRotationFive = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocationFive = ((ShotgunMuzzleLocationFive != nullptr) ? ShotgunMuzzleLocationFive->GetComponentLocation() : GetActorLocation());

				// + SpawnRotation.RotateVector(GunOffset)
				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocationOne, SpawnRotationOne, ActorSpawnParams);
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocationTwo, SpawnRotationTwo, ActorSpawnParams);
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocationThree, SpawnRotationThree, ActorSpawnParams);
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocationFour, SpawnRotationFour, ActorSpawnParams);
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocationFive, SpawnRotationFive, ActorSpawnParams);
			}
		}

		// try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		if (nSpecialGunBullet == 0)
		{
			// 여기서 총을 BASIC으로 바꾼다.
			PlaySettingGun("BASIC");
		}
	}
	
	// 일반 = 변경점 X
	else
	{
		if (myGun == EGunState::HEAVYBASIC)
		{
			nSpecialGunBullet -= 1; // 탄알 감소
			HUD->SetCurrentBullet(nSpecialGunBullet, true);
		}
		// try and fire a projectile
		if (ProjectileClass != nullptr)
		{
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((MuzzleLocation != nullptr) ? MuzzleLocation->GetComponentLocation() : GetActorLocation());


				// + SpawnRotation.RotateVector(GunOffset)
				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AZombieShootingProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}

		// try and play the sound if specified
		if (FireSound != nullptr && nSpecialGunBullet != 0)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		if (myGun == EGunState::HEAVYBASIC && nSpecialGunBullet == 0)
		{
			// 여기서 총을 BASIC으로 바꾼다.
			PlaySettingGun("BASIC");
		}
	}

	

	// try and play a firing animation if specified
	/*
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
	*/
}

void AMyCharacter::Attack()
{
	// 공격 애니메이션 실행
	//CharacterAnim->PlayAttackMontage();

	auto AnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (nullptr == AnimInstance) return;

	AnimInstance->PlayAttackMontage();
	OnFire();
}

void AMyCharacter::Run()
{
	GetCharacterMovement()->MaxWalkSpeed *= 2.5f;
	bIsRun = true;
}

void AMyCharacter::StopRun()
{
	if (bIsRun)
	{
		GetCharacterMovement()->MaxWalkSpeed /= 2.5f;
	}
}

void AMyCharacter::PlayerPause()
{
	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	GameStatic->SetGamePaused(GetWorld(), true);

	FInputModeUIOnly InputMode;
	UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(InputMode);
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);
	HUD->SetGamePauseUIVisible();
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	fPlayerHp -= FinalDamage;
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Attack!"));

	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	float fCurrentHP = fPlayerHp / fMaxHp;

	HUD->SetPlayerHP(fCurrentHP);

	if (fPlayerHp == 0) // 피가 다 까이면
	{
		CharacterAnim->SetDeadAnim();
		
		bCanMove = false;

		FInputModeUIOnly InputMode;
		UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(InputMode);
		UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(true);

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

		HUD->SetGameOverUIVisible();
	}

	//MyTakeDamage.Broadcast();
	return FinalDamage;

}

// 총 세팅
void AMyCharacter::StartSettingGun()
{
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	FString GunName = MyGI->GetPlayerGun();

	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD == nullptr) return;	

	if (GunName == TEXT("HEAVYBASIC"))
	{
		myGun = EGunState::HEAVYBASIC;
		nSpecialGunBullet = 30;
		HUD->SetGunName(GunName);
		HUD->SetDefaultBullet(true);
		HUD->SetCurrentBullet(nSpecialGunBullet, true);
	}

	else if (GunName == TEXT("SHOTGUN"))
	{
		myGun = EGunState::SHOTGUN;
		nSpecialGunBullet = 30;
		HUD->SetGunName(GunName);
		HUD->SetDefaultBullet(true);
		HUD->SetCurrentBullet(nSpecialGunBullet, true);
	}

	else
	{
		myGun = EGunState::BASIC;
		HUD->SetGunName(GunName);
		HUD->SetDefaultBullet(false);
		HUD->SetCurrentBullet(nSpecialGunBullet, false);
	}
}

void AMyCharacter::PlaySettingGun(FString yourGun)
{
	UMyGameInstance* MyGI = GetGameInstance<UMyGameInstance>();
	
	MyGI->SetPlayerGun(yourGun);

	APlayerInterface_HUD* HUD = Cast<APlayerInterface_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD == nullptr) return;

	if (yourGun == TEXT("HEAVYBASIC"))
	{
		myGun = EGunState::HEAVYBASIC;
		nSpecialGunBullet = 30;
		HUD->SetGunName(yourGun);
		HUD->SetDefaultBullet(true);
		HUD->SetCurrentBullet(nSpecialGunBullet, true);
	}

	else if (yourGun == TEXT("SHOTGUN"))
	{
		myGun = EGunState::SHOTGUN;
		nSpecialGunBullet = 30;
		HUD->SetGunName(yourGun);
		HUD->SetDefaultBullet(true);
		HUD->SetCurrentBullet(nSpecialGunBullet, true);
	}

	else
	{
		myGun = EGunState::BASIC;
		nSpecialGunBullet = 1;
		HUD->SetGunName(yourGun);
		HUD->SetDefaultBullet(false);
		HUD->SetCurrentBullet(nSpecialGunBullet, false);
	}
}