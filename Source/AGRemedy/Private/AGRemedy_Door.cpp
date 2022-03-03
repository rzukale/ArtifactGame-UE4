// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_Door.h"
#include "Components/BoxComponent.h"

// Sets default values
AAGRemedy_Door::AAGRemedy_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our Default Components
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	TriggerCapsule = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorProximityVolume"));

	//DoorFrame->SetupAttachment(RootComponent);
	SetRootComponent(DoorFrame);
	Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
	TriggerCapsule->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AAGRemedy_Door::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerCapsule != nullptr)
	{
		TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AAGRemedy_Door::OnOverlapBegin);
		TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AAGRemedy_Door::OnOverlapEnd);
	}
	InitialHeight = Door->GetRelativeLocation().Z;
	CurrentHeight = InitialHeight;
	TargetHeight = InitialHeight + 390.f;
}

// Called every frame
void AAGRemedy_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDoorIsOpening)
	{
		OpenDoor(DeltaTime);
	}
	if (bDoorIsClosing)
	{
		CloseDoor(DeltaTime);
	}
}

void AAGRemedy_Door::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		if (bDoorIsClosed)
		{
			bDoorIsOpening = true;
			bDoorIsClosing = false;
			bDoorIsClosed = false;
		}
	}
}

void AAGRemedy_Door::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAGRemedy_Door::CloseDoor(float DeltaTime)
{
	CurrentHeight -= GetActorLocation().Z * DeltaTime * DoorOpenSpeed;
	if (CurrentHeight <= InitialHeight)
	{
		bDoorIsOpening = false;
		bDoorIsClosing = false;
		bDoorIsClosed = true;
	}
	else if (bDoorIsClosing == true)
	{
		FVector DoorRelativeLocation = Door->GetRelativeLocation();
		FVector NewLocation = FVector(DoorRelativeLocation.X, DoorRelativeLocation.Y, CurrentHeight);
		Door->SetRelativeLocation(NewLocation);
	}
}

void AAGRemedy_Door::OpenDoor(float DeltaTime)
{
	CurrentHeight += GetActorLocation().Z * DeltaTime * DoorOpenSpeed;
	if (CurrentHeight >= TargetHeight)
	{
		bDoorIsOpening = false;
		bDoorIsClosing = true;
	}
	else if (bDoorIsOpening == true)
	{
		FVector DoorRelativeLocation = Door->GetRelativeLocation();
		FVector NewLocation = FVector(DoorRelativeLocation.X, DoorRelativeLocation.Y, CurrentHeight);
		Door->SetRelativeLocation(NewLocation);
	}
}

