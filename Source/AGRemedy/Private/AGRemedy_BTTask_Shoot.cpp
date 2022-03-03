// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "AGRemedy_ShooterCharacter.h"

UAGRemedy_BTTask_Shoot::UAGRemedy_BTTask_Shoot()
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UAGRemedy_BTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AAIController* AIController = OwnerComp.GetAIOwner();

    if (AIController == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    AAGRemedy_ShooterCharacter* AIPawn = Cast<AAGRemedy_ShooterCharacter>(AIController->GetPawn());
    if (AIPawn == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    AIPawn->Shoot();
    return EBTNodeResult::Succeeded;
}