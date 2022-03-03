// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_BTS_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UAGRemedy_BTS_PlayerLocation::UAGRemedy_BTS_PlayerLocation()
{
	NodeName = TEXT("Update Player Location");
}

void UAGRemedy_BTS_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
}
