// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AGRemedy_BTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_BTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UAGRemedy_BTTask_Shoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
