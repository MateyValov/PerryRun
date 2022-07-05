// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "PGrunt.generated.h"

/**
 * 
 */
UCLASS()
class PERRYRUN_API APGrunt : public AObstacle
{
	GENERATED_BODY()
	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;
	
};
