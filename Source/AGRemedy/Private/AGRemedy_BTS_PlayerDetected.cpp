// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_BTS_PlayerDetected.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UAGRemedy_BTS_PlayerDetected::UAGRemedy_BTS_PlayerDetected()
{
	NodeName = TEXT("Line of Sight Check");
}

void UAGRemedy_BTS_PlayerDetected::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (AIController && PlayerPawn)
	{
		if (AIController->LineOfSightTo(PlayerPawn))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
		}
		else
		{
			OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		}
	}
}
