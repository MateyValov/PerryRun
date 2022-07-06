// Fill out your copyright notice in the Description page of Project Settings.


#include "PGrunt.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

APGrunt::APGrunt() {
	PrimaryActorTick.bCanEverTick = true;
	head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	head->SetupAttachment(root);
}

// Called every frame
void APGrunt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	float move =  FMath::Sin(Runtime);
	Runtime += speed;//0.01;// DeltaTime;
	
	newLocation.Y = StartingPoint +  offset * move;
	SetActorRotation(FQuat(FRotator(0, orientation, 0)), ETeleportType::None);
	SetActorLocation(newLocation);
	if (newLocation.Y == StartingPoint || newLocation.Y == EndPoint) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "col");
		orientation += 180;
	}
}

void APGrunt::BeginPlay()
{
	Super::BeginPlay();
	StartingPoint = GetActorLocation().Y - offset;
	EndPoint = GetActorLocation().Y + offset;
	if (random) {
		offset = FMath::RandRange(100, 1000);
		speed = FMath::FRandRange(0.01f, 0.07f);
	}
	

}