// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AGRemedy_ShooterCharacter.generated.h"

class AAGRemedy_Gun;

UCLASS()
class AGREMEDY_API AAGRemedy_ShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAGRemedy_ShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void Shoot();

	UFUNCTION(BlueprintPure)
		bool IsDead() const;
	UFUNCTION(BlueprintPure)
		float GetHealthPercentage() const;

private:
	void MoveForward(float AxisValue);
	void MoveSide(float AxisValue);
	void HandleDeath();

	float DestructionDelay = 2.5f;

	FTimerHandle ActorDestructionTimer;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AAGRemedy_Gun> GunClass;
	UPROPERTY()
		AAGRemedy_Gun* Gun = nullptr;
	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere)
		float Health;
};
