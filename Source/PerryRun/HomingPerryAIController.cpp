// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingPerryAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h" 
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "PerryRunCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "HP_BBKeys.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/Character.h"
#include "Perception\AIPerceptionComponent.h"

AHomingPerryAIController::AHomingPerryAIController(/*const FObjectInitializer& ObjectInitializer*/) {
	static ConstructorHelpers::FObjectFinder<UBehaviorTree>obj(TEXT("BehaviorTree'/Game/ThirdPersonCPP/Blueprints/Enemies/HomingPerry/HomingPerryBT.HomingPerryBT'"));
	if (obj.Succeeded()) {
		BTree = obj.Object;
	}
	BTree_component = /*ObjectInitializer.*/CreateDefaultSubobject<UBehaviorTreeComponent>(/*this,*/ TEXT("BTComp"));
	blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	setupPerception();
	
}	

void AHomingPerryAIController::BeginPlay() {
	Super::BeginPlay();
	RunBehaviorTree(BTree);
	BTree_component->StartTree(*BTree);
}

void AHomingPerryAIController::OnPossess(APawn* const pawn) {
	Super::OnPossess( pawn);
	if (blackboard) {
		blackboard->InitializeBlackboard(*BTree->BlackboardAsset);
	}
}

UBlackboardComponent* AHomingPerryAIController::getBlackboard()const {
	return blackboard;
}

void AHomingPerryAIController::detected(AActor* actor, FAIStimulus const stimulus){
	if (APerryRunCharacter* const character = Cast<APerryRunCharacter>(actor)) {
		getBlackboard()->SetValueAsBool(bb_keys::CanSeePlayer, stimulus.WasSuccessfullySensed());
	}
}

void AHomingPerryAIController::setupPerception(){
	sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
	sight->SightRadius = 500.0f;
	sight->LoseSightRadius = sight->SightRadius + 50.0f;
	sight->PeripheralVisionAngleDegrees = 135.0f;
	sight->SetMaxAge(5.0f);
	sight->AutoSuccessRangeFromLastSeenLocation = 10.0f;
	sight->DetectionByAffiliation.bDetectEnemies = true;
	sight->DetectionByAffiliation.bDetectFriendlies = true;
	sight->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*sight->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AHomingPerryAIController::detected);
	GetPerceptionComponent()->ConfigureSense(*sight);
}
