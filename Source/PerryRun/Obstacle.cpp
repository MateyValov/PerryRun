// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "PerryRunCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);

	//mesh = CreateDefaultSubobject<USceneComponent>(TEXT("obj"));
	head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	head->SetupAttachment(root);
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	hitbox->SetupAttachment(head);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::objCollide);

	eye1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Eye1"));
	eye1->SetupAttachment(head);
	eye2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Eye2"));
	eye2->SetupAttachment(head);
	mouth = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mouth"));
	mouth->SetupAttachment(head);

	

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	float move = FMath::Sin(Runtime+DeltaTime) - FMath::Sin(Runtime);
	Runtime += DeltaTime;
	if (random && (int)Runtime%10==0) {
		speed =  FMath::RandRange(100, 5000);
	}
	newLocation.Y += move * speed;

	SetActorLocation(newLocation);
	

}

void AObstacle::objCollide(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);
	
	if (actor != nullptr) {
		actor->Respawn();
	}
}

