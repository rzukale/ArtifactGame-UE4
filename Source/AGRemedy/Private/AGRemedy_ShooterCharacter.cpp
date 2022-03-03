// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_ShooterCharacter.h"
#include "AGRemedy_Gun.h"
#include "Components/CapsuleComponent.h"
#include "../AGRemedyGameModeBase.h"
#include "TimerManager.h"

// Sets default values
AAGRemedy_ShooterCharacter::AAGRemedy_ShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAGRemedy_ShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Gun = GetWorld()->SpawnActor<AAGRemedy_Gun>(GunClass);
	if (!ensure(Gun != nullptr)) return;
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	if (Gun != nullptr)
	{
		Gun->AttachToComponent(
			GetMesh(),
			FAttachmentTransformRules::KeepRelativeTransform,
			TEXT("WeaponSocket"));
		Gun->SetOwner(this);
	}
	Health = MaxHealth;
}

// Called every frame
void AAGRemedy_ShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAGRemedy_ShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AAGRemedy_ShooterCharacter::Shoot);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AAGRemedy_ShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &AAGRemedy_ShooterCharacter::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &APawn::AddControllerYawInput);
}

float AAGRemedy_ShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	if (IsDead())
	{
		AAGRemedyGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AAGRemedyGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetWorldTimerManager().SetTimer(ActorDestructionTimer, this, &AAGRemedy_ShooterCharacter::HandleDeath, DestructionDelay);
	}
	return DamageToApply;
}

void AAGRemedy_ShooterCharacter::Shoot()
{
	if (Gun != nullptr)
	{
		Gun->PullTrigger();
	}
}

bool AAGRemedy_ShooterCharacter::IsDead() const
{
	if (Health > 0)
	{
		return false;
	}
	return true;
}

float AAGRemedy_ShooterCharacter::GetHealthPercentage() const
{
	return Health / MaxHealth;
}

void AAGRemedy_ShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AAGRemedy_ShooterCharacter::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AAGRemedy_ShooterCharacter::HandleDeath()
{
	if (Gun != nullptr)
	{
		Gun->Destroy();
	}
	Destroy();
}