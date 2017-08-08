// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Engine.h"
///
#include "CoreMinimal.h"

#include "GameFramework/HUD.h"
#include "GenericHUD.generated.h"

/**
 * 
 */
UCLASS()
class STD_SAVEGAME_API AGenericHUD : public AHUD
{
	GENERATED_BODY()
	
	AGenericHUD();
public:
	virtual void BeginPlay()override;

public:
	UClass * pCurrentWidget;
	
};
