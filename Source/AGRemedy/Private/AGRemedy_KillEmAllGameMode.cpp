// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFrameWork/Controller.h"
#include "AGRemedy_AIController.h"

void AAGRemedy_KillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController)
	{
		EndGame(false);
	}
	for (AAGRemedy_AIController* Controller : TActorRange<AAGRemedy_AIController>(GetWorld()))
	{
		if (Controller)
		{
			if (!Controller->IsDead())
			{
				return;
			}
		}
	}
	EndGame(true);
}

void AAGRemedy_KillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}