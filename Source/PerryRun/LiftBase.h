// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiftBase.generated.h"

UCLASS()
class PERRYRUN_API ALiftBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALiftBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float LiftHeight = 0.0f;


private: 
	UPROPERTY(EditAnywhere)
	float stepCount = 100;
	UPROPERTY()
	float move;
	UPROPERTY()
	float destination;
	UPROPERTY()
	float StartingPoint = 0.0f;
	UPROPERTY()
	float EndPoint = 0.0f;
	UPROPERTY()
	bool canMove=true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = ( AllowPrivateAccess = "true"))
	class USceneComponent* RootScene = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* mesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* button = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* box = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	float GetStart() const { return StartingPoint; }

	UFUNCTION(BlueprintPure)
	float GetEnd() const { return EndPoint; }

private:
	UFUNCTION()
	void ButtonTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UFUNCTION()
	void UpdateLift();
};
