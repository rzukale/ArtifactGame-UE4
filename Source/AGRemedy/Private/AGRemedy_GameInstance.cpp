// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_GameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "AGRemedy_MainMenu.h"
#include "AGRemedy_InGameMenu.h"
#include "Kismet/GameplayStatics.h"

UAGRemedy_GameInstance::UAGRemedy_GameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/Blueprints/Menu/WBP_MainMenu"));
	if (!ensure(MainMenuBPClass.Class != nullptr)) return;

	MainMenuClass = MainMenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/Blueprints/Menu/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

void UAGRemedy_GameInstance::Init()
{
	Super::Init();
}

void UAGRemedy_GameInstance::LaunchGame()
{
	if (MainMenu != nullptr)
	{
		MainMenu->Teardown();
	}
	UGameplayStatics::OpenLevel(this, "Showcase");
}

void UAGRemedy_GameInstance::LaunchMainMenu()
{
	if (InGameMenu != nullptr)
	{
		InGameMenu->Teardown();
	}
	UGameplayStatics::OpenLevel(this, "MainMenuLevel");
}

void UAGRemedy_GameInstance::LoadMainMenu()
{
	if (!ensure(MainMenuClass != nullptr)) return;

	MainMenu = CreateWidget<UAGRemedy_MainMenu>(this, MainMenuClass);
	if (!ensure(MainMenu != nullptr)) return;

	MainMenu->Setup();
}

void UAGRemedy_GameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;

	InGameMenu = CreateWidget<UAGRemedy_MenuWidget>(this, InGameMenuClass);
	if (!ensure(InGameMenu != nullptr)) return;

	InGameMenu->Setup();
}

