// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
///
//fill out your HeaderFile
#include "CodeFactory.h" // this header is have project header and LogCode
///
#include "GameFramework/Character.h"
#include "GenericCharacter.generated.h"

UCLASS()
class CODEFACTORY_API AGenericCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGenericCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


//Ingerit Value
public:
	//GameIstance
	//GameInstance = GetGameInstance();
	//Controller
	//AIControllerClass = TSubclassOf<AController> pAIController; //Default class to use when pawn is controlled by AI.

	//AutoPossessAI = EAutoPossessAI::Something //	Determines when the Pawn creates and is possessed by an AI Controller (on level start, when spawned, etc).
	//AutoPossessPlayer = EAutoReceiveInput::Somthing //Determines which PlayerController, if any, should automatically possess the pawn when the level starts or when the pawn is spawned.

	//Controller = AController pController; //Controller currently possessing this Actor

	//PlayerState
	//PlayerState = APlayerState pPlayerState; //	If Pawn is possessed by a player, points to his playerstate.


//Component
public:
	//Mesh
		//already have that , GetMesh()
	//Collision
		//already have that , GetCapsulComponent();
	//Spring
	UPROPERTY(VisibleAnywhere, Category = "Config")
		class USpringArmComponent *pSpringArm;
	//Camera
	UPROPERTY(VisibleAnywhere, Category = "Config")
		class UCameraComponent *pCmaera;
	


//CustomFunction
public:

//CustomValue
private:
	//ActiveSwitch
	bool ActiveSwitch;

	//moveToHorizontal
	void moveToHorizontal(float param); ////need to binding PlayerInputComponent->BindAxis
	//moveToVertical
	void moveToVertical(float param); ////need to binding PlayerInputComponent->BindAxis
	 //moveToTurnHorizontalFunction
	void TurnToHorizontal(float param); //need to binding PlayerInputComponent->BindAxis
	//moceToTurnVerticalFunction
	void TurnToVertical(float param); //need to binding PlayerInputComponent->BindAxis

	//jump and someThing diffrent Button Action Functions, for Bind
	

	
	
};
