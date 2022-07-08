// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftButton.h"
#include "Components/BoxComponent.h"
#include "PerryRunCharacter.h"
#include "Components/InputComponent.h"
//#include "Delegates/DelegateSignatureImpl.inl"
// Sets default values
ALiftButton::ALiftButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	body->SetupAttachment(root);
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	hitbox->SetupAttachment(root);
	//input = CreateDefaultSubobject<UInputComponent>(TEXT("input"));
	//input->BindKey(EKeys::E, IE_Released, this, &ALiftButton::pressed);
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &ALiftButton::bindPlayer);
	hitbox->OnComponentEndOverlap.AddDynamic(this, &ALiftButton::unbindPlayer);
}

// Called when the game starts or when spawned
void ALiftButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALiftButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALiftButton::bindPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);

	if (actor != nullptr) {
		actor->InteractDelegate.BindUFunction(this, FName("pressed"));
	}
}

void ALiftButton::unbindPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	APerryRunCharacter* actor = Cast<APerryRunCharacter>(OtherActor);

	if (actor != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Some debug message!"));
		actor->InteractDelegate.Unbind();
	}
}
