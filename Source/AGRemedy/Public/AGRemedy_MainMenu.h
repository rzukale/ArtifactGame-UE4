// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGRemedy_MenuWidget.h"
#include "AGRemedy_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_MainMenu : public UAGRemedy_MenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;
	//virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* StartButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void StartGame();
	UFUNCTION()
	void QuitGame();
};
