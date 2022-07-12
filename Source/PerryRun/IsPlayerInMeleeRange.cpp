// Fill out your copyright notice in the Description page of Project Settings.


#include "IsPlayerInMeleeRange.h"
#include "HomingPerryAIController.h"
#include "EnemyCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HP_BBKeys.h"

UIsPlayerInMeleeRange::UIsPlayerInMeleeRange() {
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Player In Melee Range");
}

void UIsPlayerInMeleeRange::OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	Super::OnBecomeRelevant(ownerComp, nodeMemory);

	AHomingPerryAIController* const cont = Cast<AHomingPerryAIController>(ownerComp.GetAIOwner());
	AEnemyCharacter* const npc = Cast<AEnemyCharacter>(cont->GetPawn());

	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	cont->getBlackboard()->SetValueAsBool(bb_keys::PlayerIsInMeleeRange, npc->GetDistanceTo(player) <= meleeRange);
}
