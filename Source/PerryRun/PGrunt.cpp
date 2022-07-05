// Fill out your copyright notice in the Description page of Project Settings.


#include "PGrunt.h"

// Called every frame
void APGrunt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	float move = FMath::Sin(Runtime + DeltaTime) - FMath::Sin(Runtime);
	Runtime += DeltaTime;
	if (random && (int)Runtime % 10 == 0) {
		speed = FMath::RandRange(100, 5000);
	}
	newLocation.Y += move * speed;

	SetActorLocation(newLocation);


}