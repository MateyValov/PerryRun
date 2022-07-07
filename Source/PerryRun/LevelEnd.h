// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelEnd.generated.h"

UCLASS()
class PERRYRUN_API ALevelEnd : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelEnd();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		class ULevel* level = nullptr;
	UPROPERTY(EditAnywhere)
		class USceneComponent* root = nullptr;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* flag = nullptr;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* pole = nullptr;
	UPROPERTY(EditAnywhere)
		class UBoxComponent* hitbox = nullptr;

	UPROPERTY(EditAnywhere)
		FName leadsTo;

	UFUNCTION()
		void Trigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	/*UFUNCTION(BlueprintImplementableEvent)
		void load();*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
};
