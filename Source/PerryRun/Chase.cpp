// Fill out your copyright notice in the Description page of Project Settings.


#include "Chase.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "HomingPerryAIController.h"
//#include "GameFramework/Character.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
//#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "HP_BBKeys.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UChase::UChase() {
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChase::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) {

	AHomingPerryAIController* cont = Cast<AHomingPerryAIController>(ownerComp.GetAIOwner());

	FVector const targetLocation = cont->getBlackboard()->GetValueAsVector(bb_keys::targetLocation);
	
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, targetLocation);

	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}