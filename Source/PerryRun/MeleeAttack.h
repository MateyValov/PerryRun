// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h" 
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EnemyCharacter.h"
#include "MeleeAttack.generated.h"

/**
 *
 */
UCLASS()
class PERRYRUN_API UMeleeAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UMeleeAttack();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory);

private:
	bool MontageHasFinished(AEnemyCharacter* const npc);
};

