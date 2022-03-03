// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGRemedy_MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class AGREMEDY_API UAGRemedy_MenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void Teardown();
	void Setup();

protected:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

};
