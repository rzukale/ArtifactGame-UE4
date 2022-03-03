// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_MainMenu.h"
#include "Components/Button.h"
#include "AGRemedy_GameInstance.h"

bool UAGRemedy_MainMenu::Initialize()
{
	bool bWasSuccess = Super::Initialize();
	if (!bWasSuccess) return false;

	if (!ensure(StartButton != nullptr)) return false;
	StartButton->OnClicked.AddDynamic(this, &UAGRemedy_MainMenu::StartGame);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UAGRemedy_MainMenu::QuitGame);

	return true;
}

void UAGRemedy_MainMenu::StartGame()
{
	UAGRemedy_GameInstance* GameInstance = GetGameInstance<UAGRemedy_GameInstance>();
	if (!ensure(GameInstance != nullptr)) return;

	GameInstance->LaunchGame();
}

void UAGRemedy_MainMenu::QuitGame()
{
	FGenericPlatformMisc::RequestExit(false);
}

