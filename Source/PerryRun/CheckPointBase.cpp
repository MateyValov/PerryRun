// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPointBase.h"
#include "PerryRunCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ACheckPointBase::ACheckPointBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);

	pole = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pole"));
	pole->SetupAttachment(root);

	flag = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flag"));
	flag->SetupAttachment(root);

	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("hitbox"));
	hitbox->SetupAttachment(root);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ACheckPointBase::setRespawnPoint);
}

// Called when the game starts or when spawned
void ACheckPointBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckPointBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPointBase::setRespawnPoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);

	if (actor != nullptr && !isReached) {
		FVector newLocation = GetActorLocation();
		//newLocation.Z 
		actor->setSpawnpoint(GetActorLocation());
		actor->changeMessage("Checkpoint Reached");
		isReached = true;
	}
}

