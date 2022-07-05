// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPBar.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class PERRYRUN_API UHPBar : public UUserWidget
{
	GENERATED_BODY()
	private:
	protected:
		UPROPERTY(EditAnywhere)
			class AObstacle* perry;
		UPROPERTY(meta = (BindWidget))
			class UProgressBar* HPBar;
	public:

};
