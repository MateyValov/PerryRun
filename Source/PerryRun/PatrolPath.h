// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

UCLASS()
class PERRYRUN_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolPath();
	FVector getPatrolPoint(int index);
	int size();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RootScene = nullptr;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
		TArray<FVector> points;

};
