// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
UPROPERTY(EditAnywhere)
	FVector MovementSpeed = FVector(100,0,0);
	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0;
	UPROPERTY(EditAnywhere)
	float MoveDistance = 500;
	FVector StartLocation;
	void ToFroMotion(float);
	bool DestinationReached(FVector) const;
	UPROPERTY(EditAnywhere)
	FRotator RotationSpeed = FRotator(0,0,0);
};
