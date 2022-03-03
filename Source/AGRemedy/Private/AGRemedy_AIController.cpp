// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_AIController.h"
#include "Kismet/GameplayStatics.h"
#include "AGRemedy_ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAGRemedy_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		if (PlayerPawn)
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		}
	}
}

void AAGRemedy_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AAGRemedy_AIController::IsDead() const
{
	AAGRemedy_ShooterCharacter* ControlledCharacter = Cast<AAGRemedy_ShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}
	return true;
}
