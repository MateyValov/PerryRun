// Fill out your copyright notice in the Description page of Project Settings.


#include "FindNextPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "HomingPerryAIController.h"
#include "EnemyCharacter.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "HP_BBKeys.h"
#include "cmath"

UFindNextPatrolPoint::UFindNextPatrolPoint() {
	NodeName = TEXT("Find Next Patrol Point");

}

EBTNodeResult::Type UFindNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) {

	AHomingPerryAIController* cont = Cast<AHomingPerryAIController>(ownerComp.GetAIOwner());
	AEnemyCharacter* npc = Cast<AEnemyCharacter>(cont->GetPawn());
	maxIndex = npc->getPath()->size()-1;

	int index = cont->getBlackboard()->GetValueAsInt(bb_keys::PatrolPathIndex);
	
	if(!looped){
		if(index >= maxIndex && direction == EDirectionType::Forward) {
			direction = EDirectionType::Reverse;
		}
		
		else if (index == minIndex && direction == EDirectionType::Reverse) {
			direction = EDirectionType::Forward;
		}
	}
	
	cont->getBlackboard()->SetValueAsInt(bb_keys::PatrolPathIndex, (direction == EDirectionType::Forward ? std::abs(index+1) : std::abs(index-1)) % (maxIndex+1));
	
	FVector const point = npc->getPath()->getPatrolPoint(index);
	FVector const location = npc->getPath()->GetActorTransform().TransformPosition(point);

	//FNavLocation location;

	//UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(GetWorld());
	//if (navSys->GetRandomPointInNavigableRadius(origin, searchRadius, location, nullptr)) {
		cont->getBlackboard()->SetValueAsVector(bb_keys::targetLocation, location);
	//}

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}