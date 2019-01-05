// Fill out your copyright notice in the Description page of Project Settings.

#include "Coin.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "HowToMakeHTML5GameMode.h"
#include <string>

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	pBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Boxcollision"));
	pBoxCollision->SetGenerateOverlapEvents(true);

	pStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	

}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("ACoin::BeginPlay"));

	FScriptDelegate DelegateBegin;
	DelegateBegin.BindUFunction(this, "OnOverlapBegin");
	this->OnActorBeginOverlap.Add(DelegateBegin);

	

	pBoxCollision->SetupAttachment(RootComponent);
	pStaticMesh->SetupAttachment(pBoxCollision);
}

void ACoin::OnOverlapBegin(AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
	//Processing Score
	AHowToMakeHTML5GameMode* temp=(AHowToMakeHTML5GameMode*)GetWorld()->GetAuthGameMode();
	temp->addPlayerScore();

	//for debug=================================================================
	UE_LOG(LogTemp, Warning, TEXT("ACoint::OnOverlapBegin"));
	std::string str= std::to_string(temp->getPlayerScore());

	TCHAR ch[20];
	const char* all = str.c_str();
	int len = 1 + strlen(all);
	wchar_t* t = new wchar_t[len];
	if (NULL == t) throw std::bad_alloc();
	mbstowcs(t, all, len);
	_tcscpy_s(ch,t);

	UE_LOG(LogTemp, Warning, ch);
	//for debug=================================================================

	//Delete this object
	Destroy(this);

}



