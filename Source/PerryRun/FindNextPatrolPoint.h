// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h" 
#include "BehaviorTree/BehaviorTreeTypes.h"
//#include "UObject/ObjectGlobals.h"
#include "FindNextPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class PERRYRUN_API UFindNextPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UFindNextPatrolPoint();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float searchRadius = 1500.0f;
};
