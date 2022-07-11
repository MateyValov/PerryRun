// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "HomingPerryAIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "HP_BBKeys.h"

UFindPlayerLocation::UFindPlayerLocation() {
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) {

	AHomingPerryAIController* cont = Cast<AHomingPerryAIController>(ownerComp.GetAIOwner());
	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	FVector const origin = player->GetActorLocation();
	FNavLocation location;

	UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (navSys->GetRandomPointInNavigableRadius(origin, searchRadius, location, nullptr)) {
		cont->getBlackboard()->SetValueAsVector(bb_keys::targetLocation, location.Location);
	}

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}