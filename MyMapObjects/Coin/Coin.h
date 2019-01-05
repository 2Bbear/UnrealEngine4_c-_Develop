// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Coin.generated.h"

UCLASS()
class HOWTOMAKEHTML5_API ACoin : public AActor
{
	GENERATED_BODY()
private:
	//Sets Componetns
	UPROPERTY(VisibleAnywhere, Category = "Config")
	class UBoxComponent * pBoxCollision;
	UPROPERTY(VisibleAnywhere, Category = "Config")
	class UStaticMeshComponent * pStaticMesh;

public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
