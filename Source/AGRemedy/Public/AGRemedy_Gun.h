// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGRemedy_Gun.generated.h"

UCLASS()
class AGREMEDY_API AAGRemedy_Gun : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AAGRemedy_Gun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly)
		USoundBase* MuzzleSound = nullptr;
	UPROPERTY(EditDefaultsOnly)
		USceneComponent* Root = nullptr;
	UPROPERTY(EditDefaultsOnly)
		USkeletalMeshComponent* Mesh = nullptr;
	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* MuzzleFlash = nullptr;
	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* HitWorld = nullptr;
	UPROPERTY(EditAnywhere)
		float MaxRange = 10000.f;
	UPROPERTY(EditAnywhere)
		float Damage = 10.f;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
	AController* GetOwnerController() const;
};
