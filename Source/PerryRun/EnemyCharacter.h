// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolPath.h"
#include "CombatInterface.h"
#include "Animation/AnimMontage.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class PERRYRUN_API AEnemyCharacter : public ACharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APatrolPath* getPath();
	int meleeAttack_Implementation() override;

	UAnimMontage* getbasicAttackMontage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	APatrolPath* patrolPath;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* basicAttackMontage;
};
