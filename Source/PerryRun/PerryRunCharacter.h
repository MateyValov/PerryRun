// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PerryRunCharacter.generated.h"

UCLASS(config=Game)
class APerryRunCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FVector Spawnpoint;
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	FTimerHandle iframeHandle;
	FTimerHandle messageHandle;

protected:
	UPROPERTY()
		bool isCrouching = false;
	UPROPERTY()
		bool invincible = false;


public:
	APerryRunCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, Category = Stats)
		float currHP;
	UPROPERTY(EditAnywhere, Category = Stats)
		float maxHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
		float percentHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
		FString displayMessage = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;



protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	/*UFUNCTION()
		void beginCrouch();
	UFUNCTION()
		void endCrouch();*/

public:
	virtual void Tick(float DeltaTime) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION()
	void Clear() {displayMessage = "";}

	UFUNCTION()
	void changeMessage(FString message);

	UFUNCTION()
		void setSpawnpoint(FVector newLocation);

	UFUNCTION(BlueprintCallable)
	void Respawn();

	UFUNCTION()
		void iframeCancel() {invincible = false;}

	UFUNCTION()
		void takeDamage(float damage, float recoveryTime);

	UFUNCTION(BlueprintImplementableEvent)
		void die();
};

