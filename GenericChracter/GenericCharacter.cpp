// Fill out your copyright notice in the Description page of Project Settings.

#include "GenericCharacter.h"


// Sets default values
AGenericCharacter::AGenericCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
//Component Scale,Location setting;
	//Spring
	pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("pSpringArm"));
	pSpringArm->SetupAttachment(RootComponent);


	//Camera
	pCmaera = CreateDefaultSubobject<UCameraComponent>(TEXT("pCmaera"));
	pCmaera->SetupAttachment(pSpringArm);
	
}

// Called when the game starts or when spawned
void AGenericCharacter::BeginPlay()
{
	Super::BeginPlay();

//Component info setting
	
	//RootComponent

	//Mesh


	//Collistion
	GetCapsuleComponent()->SetSimulatePhysics(true); //set Physics

	//Spring
	pSpringArm->TargetArmLength = 1000; //set Gap of Spring to Camera
	pSpringArm->SetRelativeRotation(FRotator(-30, 0, 0)); // set Spring Rotation

	//Camera
		//pCmaera->ProjectionMode = ECameraProjectionMode::Orthographic ;// set ProjectionMode

//init setting

	//Possessing
		//AutoPossessPlayer = EAutoReceiveInput::Player0; //Auto Possessing

//Useful Function
	//GetGameInstance(); //get current GameInstance
	//GetController();  // get current this actor's Controller
	//GetMovementComponent();// get this actor's movementComponent
	//GetMesh(); //get this actor's mesh
	//GetCapsuleComponent(); // get this actor's CapsuleCollision
}

// Called every frame
void AGenericCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGenericCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//BindAxis
	PlayerInputComponent->BindAxis("BMoveToVertical", this, &AGenericCharacter::moveToVertical);
	PlayerInputComponent->BindAxis("BMoveToHorizontal", this, &AGenericCharacter::moveToHorizontal);

	PlayerInputComponent->BindAxis("BTurnToVertical", this, &AGenericCharacter::TurnToVertical);
	PlayerInputComponent->BindAxis("BTurnToHorizontal", this, &AGenericCharacter::TurnToHorizontal);

	//BindAction
	PlayerInputComponent->BindAction("BJump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("BJump", IE_Released, this, &ACharacter::StopJumping);
}

void AGenericCharacter::moveToHorizontal(float param)
{
	if (param!=0.0f)
	{
		//AddMovementInput(GetActorForwardVector(), param); // add movement in that direction
	}
}

void AGenericCharacter::moveToVertical(float param)
{
	if (param != 0.0f)
	{
		//AddMovementInput(GetActorRightVector(), param); // add movement in that direction
	}
}

void AGenericCharacter::TurnToHorizontal(float param)
{
	if (param != 0.0f)
	{

	}
}

void AGenericCharacter::TurnToVertical(float param)
{
	if (param != 0.0f)
	{

	}
}

