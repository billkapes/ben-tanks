// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, 1);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();

		
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
