// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AGRemedyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API AAGRemedyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);
};
