// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	UE_LOG(LogTemp, Display, TEXT("Log Printing"));
	UE_LOG(LogTemp, Warning, TEXT("Log Printing"));
	UE_LOG(LogTemp, Error, TEXT("Log Printing"));
	Super::BeginPlay();
	StartLocation = GetActorLocation() ;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	ToFroMotion(DeltaTime);
	FRotator CurrentRotation;
	CurrentRotation = GetActorRotation();
	CurrentRotation += RotationSpeed * DeltaTime;
	SetActorRotation(CurrentRotation);	
}


void AMyActor::ToFroMotion(float DeltaTime) {
	FVector CurrentLocation;
	Super::Tick(DeltaTime);
	CurrentLocation = GetActorLocation();
	CurrentLocation += MovementSpeed * DeltaTime;
	SetActorLocation(CurrentLocation);
	DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
	if(DistanceMoved >= MoveDistance )
	{
		FVector MoveDirection = MovementSpeed.GetSafeNormal();
		MovementSpeed *= -1;
		StartLocation += MoveDirection * MoveDistance;
		float offset = FVector::Distance(StartLocation, GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("Log Printing %f"), offset);
		SetActorLocation(StartLocation);
		FString s = "Hello";
		UE_LOG(LogTemp, Warning, TEXT("Log Printing %s"), *s);
		
	}

}

bool AMyActor::DestinationReached(FVector CurrentLocation) const 
{
	return FVector::Distance(StartLocation, CurrentLocation) >= MoveDistance ;
}

