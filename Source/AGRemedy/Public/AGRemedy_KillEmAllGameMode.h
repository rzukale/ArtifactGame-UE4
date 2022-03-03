// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AGRemedyGameModeBase.h"
#include "AGRemedy_KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API AAGRemedy_KillEmAllGameMode : public AAGRemedyGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
	void EndGame(bool bIsPlayerWinner);
};
