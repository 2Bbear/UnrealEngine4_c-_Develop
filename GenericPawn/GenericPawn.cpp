// Fill out your copyright notice in the Description page of Project Settings.
/**
 
*/
#include "GenericPawn.h"
#include "Engine.h"


// Sets default values
AGenericPawn::AGenericPawn()
{
	CLog_LOG(Warning, TEXT("Constructor Call Start"));
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

//set Value
	ActiveSwitch = false;

//Component creating setting Scale, Location
	//RootComponent
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//Mesh
	pStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("pStaticMesh"));
	pStaticMesh->SetupAttachment(RootComponent);
	pStaticMesh->SetRelativeScale3D(FVector(2, 2, 2)); //set Scale
	
	//Collistion
	pColiistion = CreateDefaultSubobject<UBoxComponent>(TEXT("pColiistion"));
	pColiistion->SetupAttachment(RootComponent);
	pColiistion->SetBoxExtent(FVector(32, 32, 32)); //set Scale
	//pColiistion->SetRelativeRotation(FRotator(-30, 0, 0)); // set Spring Rotation

	//Spring
	pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("pSpringArm"));
	pSpringArm->SetupAttachment(RootComponent);
	
	
	//Camera
	pCmaera = CreateDefaultSubobject<UCameraComponent>(TEXT("pCmaera"));
	pCmaera->SetupAttachment(pSpringArm);

	CLog_LOG(Warning, TEXT("Constructor Call End"));
}

// Called when the game starts or when spawned
void AGenericPawn::BeginPlay()
{
	Super::BeginPlay();

	
//Component info setting
	//RootComponent
	
	//Mesh
	

	//Collistion
	pColiistion->SetSimulatePhysics(true); //set Physics

	//Spring
	pSpringArm->TargetArmLength = 1000; //set Gap of Spring to Camera
	pSpringArm->SetRelativeRotation(FRotator(-30, 0, 0)); // set Spring Rotation
	
	//Camera
		//pCmaera->ProjectionMode = ECameraProjectionMode::Orthographic ;// set ProjectionMode

//init setting

	//Possessing
		//AutoPossessPlayer = EAutoReceiveInput::Player0; //Auto Possessing
	
}

// Called every frame
void AGenericPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveSwitch)
	{
		
	}

}

// Called to bind functionality to input
void AGenericPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	CLog_LOG_CALLONLY(Warning);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//BindAxis
	PlayerInputComponent->BindAxis("BMoveToVertical", this, &AGenericPawn::moveToVertical);
	PlayerInputComponent->BindAxis("BMoveToHorizontal", this, &AGenericPawn::moveToHorizontal);

	PlayerInputComponent->BindAxis("BTurnToVertical", this, &AGenericPawn::TurnToVertical);
	PlayerInputComponent->BindAxis("BTurnToHorizontal", this, &AGenericPawn::TurnToHorizontal);

	//BindAction
	PlayerInputComponent->BindAction("BJump", IE_Pressed, this, &AGenericPawn::Jump);
	PlayerInputComponent->BindAction("BJump", IE_Released, this, &AGenericPawn::StopJumping);
}

void AGenericPawn::moveToHorizontal(float param)
{
	if (param != 0.0f)
	{
		CLog_LOG_CALLONLY(Warning);
		this->AddActorWorldTransform(FTransform(FVector(param*10, 0, 0))); // move
	}
	

}

void AGenericPawn::moveToVertical(float param)
{
	if (param != 0.0f)
	{
		CLog_LOG_CALLONLY(Warning);
	}
}

void AGenericPawn::TurnToHorizontal(float param)
{
	if (param != 0.0f)
	{

	}
}



void AGenericPawn::TurnToVertical(float param)
{
	if (param != 0.0f)
	{

	}
}

void AGenericPawn::Jump()
{
	CLog_LOG_CALLONLY(Warning);
}

void AGenericPawn::StopJumping()
{
	CLog_LOG_CALLONLY(Warning);
}



