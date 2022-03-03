// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "AGRemedy_BTS_PlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_BTS_PlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UAGRemedy_BTS_PlayerLocation();

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
