// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AGRemedy_AIController.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API AAGRemedy_AIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior = nullptr;
};
