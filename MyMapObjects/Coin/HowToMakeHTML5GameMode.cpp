// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HowToMakeHTML5GameMode.h"
#include "HowToMakeHTML5Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Coin.h"
#include <string>

AHowToMakeHTML5GameMode::AHowToMakeHTML5GameMode()
{

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	
}

void AHowToMakeHTML5GameMode::setPlayerScore(int param)
{
	if(param<0)
	{
		throw param;
	}
	playerScore = param;
}

int AHowToMakeHTML5GameMode::getPlayerScore()
{
	return playerScore;
}

void AHowToMakeHTML5GameMode::addPlayerScore()
{
	playerScore += 1;
}

void AHowToMakeHTML5GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	TActorIterator< ACoin > ActorItr =TActorIterator< ACoin >(GetWorld());
	int currentWorldCoinCount=ActorItr.GetProgressNumerator();
	currentWorldCoinCount -=2;
	if(currentWorldCoinCount <0)
	{
		currentWorldCoinCount = 0;
	}

	//for debug===========================================================
	UE_LOG(LogTemp, Warning, TEXT("AHowToMakeHTML5GameMode::BeginPlay()"));

	std::string str = std::to_string(currentWorldCoinCount);
	TCHAR ch[20];
	
	const char* all = str.c_str();
	int len = 1 + strlen(all);
	wchar_t* t = new wchar_t[len];
	if (NULL == t) throw std::bad_alloc();
	mbstowcs(t, all, len);
	_tcscpy_s(ch, t);

	UE_LOG(LogTemp, Warning, ch);

	//==============================================================
}

