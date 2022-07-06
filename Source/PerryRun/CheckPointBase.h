// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckPointBase.generated.h"

UCLASS()
class PERRYRUN_API ACheckPointBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPointBase();

	UPROPERTY(EditAnywhere)
	class USceneComponent* root = nullptr;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* pole = nullptr;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* flag = nullptr;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* hitbox = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		bool isReached = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void setRespawnPoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
