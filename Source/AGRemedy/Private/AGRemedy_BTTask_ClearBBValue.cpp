// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_BTTask_ClearBBValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UAGRemedy_BTTask_ClearBBValue::UAGRemedy_BTTask_ClearBBValue()
{
    NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UAGRemedy_BTTask_ClearBBValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    return EBTNodeResult::Succeeded;
}
