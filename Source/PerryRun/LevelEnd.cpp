// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEnd.h"
#include "PerryRunCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALevelEnd::ALevelEnd()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);
	pole = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pole"));
	pole->SetupAttachment(root);
	flag = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flag"));
	flag->SetupAttachment(pole);
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	hitbox->SetupAttachment(pole);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ALevelEnd::Trigger);
	
}

// Called when the game starts or when spawned
void ALevelEnd::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelEnd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelEnd::Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);

	if (actor != nullptr) {
		//UE_LOG(LogTemp, Warning, TEXT("neshto"));
		UGameplayStatics::OpenLevel(GetWorld(), leadsTo);
		actor->changeMessage("Advanced to next level!");
	}
}

