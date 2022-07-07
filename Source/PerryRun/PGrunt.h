// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hostile.h"
#include "PGrunt.generated.h"

/**
 * 
 */
UCLASS()
class PERRYRUN_API APGrunt : public AHostile
{
	GENERATED_BODY()
	public:
		// Sets default values for this actor's properties
		APGrunt();
		//UPROPERTY(EditAnywhere)
		//class USceneComponent* mesh = nullptr;
		//UPROPERTY(EditAnywhere)
		float static static_test;
		UPROPERTY(EditAnywhere)
			class UStaticMeshComponent* head = nullptr;
		virtual void Tick(float DeltaTime) override;


	protected:
		UPROPERTY()
			float Runtime = 0.0f;
		UPROPERTY()
			FVector StartingPoint ;
		UPROPERTY(EditAnywhere)
			float offset = 20.0f;
		UPROPERTY(EditAnywhere)
			float orientation = 0.0f;
		UPROPERTY(EditAnywhere)
			float speed = 0.0f;
		UPROPERTY(EditAnywhere)
			bool random = false;
		UPROPERTY(EditAnywhere)
			bool moveOnX = false;
		UPROPERTY(EditAnywhere)
			bool moveOnZ = false;
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		


	private:
};
