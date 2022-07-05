// Fill out your copyright notice in the Description page of Project Settings.


#include "Hostile.h"
#include "PerryRunCharacter.h"
#include "Components/BoxComponent.h"
// Sets default values
AHostile::AHostile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);

	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	hitbox->SetupAttachment(root);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &AHostile::objCollide);

}


void AHostile ::objCollide(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);

	if (actor != nullptr) {
		actor->Respawn();
	}
}

