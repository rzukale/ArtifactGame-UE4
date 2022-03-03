// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGRemedy_MenuWidget.h"
#include "AGRemedy_InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_InGameMenu : public UAGRemedy_MenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* ReturnButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* MainMenuButton;

	UFUNCTION()
		void ReturnToGame();

	UFUNCTION()
		void ReturnToMenu();
};
