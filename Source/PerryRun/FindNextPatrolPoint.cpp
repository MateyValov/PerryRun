// Fill out your copyright notice in the Description page of Project Settings.


#include "FindNextPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "HomingPerryAIController.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "HP_BBKeys.h"

UFindNextPatrolPoint::UFindNextPatrolPoint() {
	NodeName = TEXT("Find Next Patrol Point");
}

EBTNodeResult::Type UFindNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) {

	AHomingPerryAIController* cont = Cast<AHomingPerryAIController>(ownerComp.GetAIOwner());
	auto const npc = cont->GetPawn();

	FVector const origin = npc->GetActorLocation();
	FNavLocation location;

	UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (navSys->GetRandomPointInNavigableRadius(origin, searchRadius, location, nullptr)) {
		cont->getBlackboard()->SetValueAsVector(bb_keys::targetLocation, location.Location);
	}

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}