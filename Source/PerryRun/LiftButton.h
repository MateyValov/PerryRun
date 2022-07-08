// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "LiftBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiftButton.generated.h"

UCLASS()
class PERRYRUN_API ALiftButton : public AActor
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this actor's properties
	ALiftButton();

protected:
	UPROPERTY(EditAnywhere)
		class UBoxComponent* hitbox = nullptr;
	UPROPERTY(EditAnywhere)
		class USceneComponent* root = nullptr;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* body = nullptr;
	UPROPERTY(EditAnywhere)
		class ALiftBase* lift = nullptr;
	UPROPERTY(EditAnywhere)
		float releventPosition = 0;
	//UPROPERTY(EditAnywhere)
	//	class UInputComponent* input = nullptr;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void pressed() {
		lift->UpdateLift(true, releventPosition);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
	UFUNCTION()
		void bindPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void unbindPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
