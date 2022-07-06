// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "PerryRunCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);*/

	//mesh = CreateDefaultSubobject<USceneComponent>(TEXT("obj"));
	

	

	

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}



