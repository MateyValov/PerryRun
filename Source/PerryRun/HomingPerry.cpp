// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingPerry.h"

// Sets default values
AHomingPerry::AHomingPerry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	head->SetupAttachment(root);
}

// Called when the game starts or when spawned
void AHomingPerry::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHomingPerry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

