// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAGRemedy_Gun::AAGRemedy_Gun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	if (Root)
	{
		SetRootComponent(Root);
	}
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	if (Mesh && Root)
	{
		Mesh->SetupAttachment(Root);
	}
}

// Called when the game starts or when spawned
void AAGRemedy_Gun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAGRemedy_Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGRemedy_Gun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleSoundSocket"));
	FHitResult Hit;
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitWorld, Hit.Location, ShotDirection.Rotation());
		AActor* ImpactedActor = Hit.GetActor();
		if (!ImpactedActor)
		{
			return;
		}
		AController* OwnerController = GetOwnerController();
		if (OwnerController == nullptr)
		{
			return;
		}
		FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
		ImpactedActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
	}
}


bool AAGRemedy_Gun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
	{
		return false;
	}
	FVector Location = FVector::ZeroVector;
	FRotator Rotation = FRotator::ZeroRotator;

	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AAGRemedy_Gun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
	{
		return nullptr;
	}
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr)
	{
		return nullptr;
	}
	return OwnerController;
}

