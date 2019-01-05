// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HowToMakeHTML5GameMode.generated.h"

UCLASS(minimalapi)
class AHowToMakeHTML5GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHowToMakeHTML5GameMode();

private:
	int playerScore;
public:
	void setPlayerScore(int param);
	int getPlayerScore();
	void addPlayerScore();

protected:
	virtual void BeginPlay() override;
};



