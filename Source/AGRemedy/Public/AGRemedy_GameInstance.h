// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AGRemedy_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UAGRemedy_GameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	void LaunchGame();
	void LaunchMainMenu();

	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();
	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

private:
	TSubclassOf<class UUserWidget> MainMenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	UPROPERTY()
	class UAGRemedy_MainMenu* MainMenu;
	UPROPERTY()
	class UAGRemedy_MenuWidget* InGameMenu;
};
