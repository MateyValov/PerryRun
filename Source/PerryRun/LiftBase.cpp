 // Fill out your copyright notice in the Description page of Project Settings.


#include "LiftBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PerryRunCharacter.h"
#include "Engine.h"


// Sets default values
ALiftBase::ALiftBase()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	SetRootComponent(RootScene);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	mesh->SetupAttachment(RootScene);

	button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	button->SetupAttachment(RootScene);

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	box->SetupAttachment(button);
	box->OnComponentBeginOverlap.AddDynamic(this, &ALiftBase::ButtonTriggered);
}

// Called when the game starts or when spawned
void ALiftBase::BeginPlay()
{
	Super::BeginPlay();

	StartingPoint = GetActorLocation().Z;
	EndPoint = StartingPoint + LiftHeight;
	destination = StartingPoint;
}

// Called every frame
void ALiftBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z != destination ) {
		FVector newLocation = GetActorLocation();
		newLocation.Z += LiftHeight/move;
		SetActorLocation(newLocation);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(EndPoint));

	}
	else {
		canMove = true;
	}
	
}

void ALiftBase::ButtonTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);
	//bool moving = false;
	if (actor != nullptr && canMove) {
		UpdateLift();
		canMove = false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "col");
		//moving = true;
	}
}

void ALiftBase::UpdateLift() {

	if(GetActorLocation().Z != StartingPoint && GetActorLocation().Z != EndPoint)return;
	
	if (GetActorLocation().Z == StartingPoint) {
		move = stepCount;
		destination = EndPoint;
	}
	else {
		move = -stepCount;
		destination = StartingPoint;
	}
	

}





