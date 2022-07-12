// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "IsPlayerInMeleeRange.generated.h"

/**
 * 
 */
UCLASS()
class PERRYRUN_API UIsPlayerInMeleeRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UIsPlayerInMeleeRange();
	void OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float meleeRange = 25.0f;
};
