// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hostile.generated.h"

UCLASS()
class PERRYRUN_API AHostile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHostile();
	

protected:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* hitbox = nullptr;
	UPROPERTY(EditAnywhere)
		class USceneComponent* root = nullptr;

public:

private:
	UFUNCTION()
		void objCollide(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
