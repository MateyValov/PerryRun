// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class PERRYRUN_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();
	UPROPERTY(EditAnywhere)
	class USceneComponent* root = nullptr;
	//UPROPERTY(EditAnywhere)
	//class USceneComponent* mesh = nullptr;
	//UPROPERTY(EditAnywhere)
	float static static_test;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* head = nullptr;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* eye1 = nullptr;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* eye2 = nullptr;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* mouth = nullptr;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* hitbox = nullptr;

protected:
	UPROPERTY()
		float Runtime = 0.0f;
	UPROPERTY(EditAnywhere)
		float speed = 20.0f;
	UPROPERTY(EditAnywhere)
		bool random = false;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void objCollide(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
