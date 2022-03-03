// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGRemedy_Door.generated.h"

UCLASS()
class AGREMEDY_API AAGRemedy_Door : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAGRemedy_Door();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Door;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent* TriggerCapsule;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	bool bDoorIsClosed = true;
	bool bDoorIsOpening = false;
	bool bDoorIsClosing = false;
	float InitialHeight;
	float CurrentHeight;
	float TargetHeight;
	
	UPROPERTY(EditAnywhere)
	int32 DoorOpenSpeed = 10;

	void CloseDoor(float DeltaTime);
	void OpenDoor(float DeltaTime);
};

