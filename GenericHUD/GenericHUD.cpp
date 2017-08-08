// Fill out your copyright notice in the Description page of Project Settings.

#include "GenericHUD.h"


AGenericHUD::AGenericHUD()
{
	//Find BlueprintWidget
	//WidgetBlueprint'/Game/GameOverFolder/BP_WG_GameOver.BP_WG_GameOver' 
	static ConstructorHelpers::FClassFinder<UUserWidget> widgetFinder(TEXT("/Game/GameOverFolder/BP_WG_GameOver"));
	pCurrentWidget = widgetFinder.Class;
	
}

void AGenericHUD::BeginPlay()
{
	//For show cursor
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
	//For show widget in UserWindow
	UUserWidget::CreateWidgetOfClass(pCurrentWidget, GetGameInstance(), GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0))->AddToViewport();
	
}
