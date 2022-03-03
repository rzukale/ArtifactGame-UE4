// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_MenuWidget.h"

void UAGRemedy_MenuWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = false;

	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}

void UAGRemedy_MenuWidget::Teardown()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	ULevel* Level = World->GetCurrentLevel();
	if (!ensure(Level != nullptr)) return;

	OnLevelRemovedFromWorld(Level, World);
}

void UAGRemedy_MenuWidget::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PC = World->GetFirstPlayerController();
	if (!ensure(PC != nullptr)) return;

	FInputModeUIOnly InputMode;
	this->bIsFocusable = true;
	InputMode.SetWidgetToFocus(this->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}
