// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hostile.h"
#include "HomingPerry.generated.h"

UCLASS()
class PERRYRUN_API AHomingPerry : public AHostile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHomingPerry();
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* head = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
