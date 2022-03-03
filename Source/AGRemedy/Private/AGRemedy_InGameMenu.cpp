// Fill out your copyright notice in the Description page of Project Settings.


#include "AGRemedy_InGameMenu.h"
#include "Components/Button.h"
#include "AGRemedy_GameInstance.h"

bool UAGRemedy_InGameMenu::Initialize()
{
	bool bWasSuccess = Super::Initialize();
	if (!bWasSuccess) return false;

	if (!ensure(ReturnButton != nullptr)) return false;
	ReturnButton->OnClicked.AddDynamic(this, &UAGRemedy_InGameMenu::ReturnToGame);

	if (!ensure(MainMenuButton != nullptr)) return false;
	MainMenuButton->OnClicked.AddDynamic(this, &UAGRemedy_InGameMenu::ReturnToMenu);

	return true;
}
void UAGRemedy_InGameMenu::ReturnToGame()
{
	Teardown();
}

void UAGRemedy_InGameMenu::ReturnToMenu()
{
	UAGRemedy_GameInstance* GameInstance = GetGameInstance<UAGRemedy_GameInstance>();
	if (!ensure(GameInstance != nullptr)) return;

	GameInstance->LaunchMainMenu();
}
