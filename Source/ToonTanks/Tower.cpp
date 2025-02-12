// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"


void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

	float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	if (Distance <= fireRange)
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (!Tank)
	{
		return;
	}

	float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	if (Distance <= fireRange)
	{
		Fire();
	}
}
