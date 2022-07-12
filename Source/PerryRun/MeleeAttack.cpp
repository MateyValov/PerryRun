// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttack.h"
#include "CombatInterface.h"
#include "AIController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/LatentActionManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Animation/Animinstance.h"


UMeleeAttack::UMeleeAttack() {
	NodeName = TEXT("Melee Attack");

}

EBTNodeResult::Type UMeleeAttack::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) {

	AAIController* const cont = ownerComp.GetAIOwner();
	AEnemyCharacter* npc = Cast<AEnemyCharacter>(cont->GetPawn());

	if (ICombatInterface* const icombat = Cast<ICombatInterface>(npc)){
		if (MontageHasFinished(npc)) {
			icombat->Execute_meleeAttack(npc);
		}
	}


	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}

bool UMeleeAttack::MontageHasFinished(AEnemyCharacter* const npc)
{
	return npc->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(npc->getbasicAttackMontage());
}
