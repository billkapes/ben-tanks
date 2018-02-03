// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller not possesing a tank"))

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller possesing: %s"), *(ControlledTank->GetName()))

	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("hitlocation: %s"), *OutHitLocation.ToString())

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
