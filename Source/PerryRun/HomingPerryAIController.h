// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "HomingPerryAIController.generated.h"


/**
 * 
 */
UCLASS()
class PERRYRUN_API AHomingPerryAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	AHomingPerryAIController(/*const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()*/);
	void BeginPlay() override;
	void OnPossess(APawn* const pawn)override;
	class UBlackboardComponent* getBlackboard()const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UBehaviorTreeComponent* BTree_component;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* BTree;

	class UBlackboardComponent* blackboard;

	class UAISenseConfig_Sight* sight;

	UFUNCTION()
	void detected(AActor* actor, FAIStimulus const stimulus);

	void setupPerception();
};
