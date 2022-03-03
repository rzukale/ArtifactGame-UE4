// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AGRemedy_BTTask_ClearBBValue.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_BTTask_ClearBBValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UAGRemedy_BTTask_ClearBBValue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
