// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %f"), RelativeSpeed)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	SetRelativeRotation(FRotator(0, Rotation, 0));
}


