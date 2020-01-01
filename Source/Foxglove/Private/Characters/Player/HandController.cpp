// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"
#include "MotionControllerComponent.h"


// Sets default values
AHandController::AHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetupAttachment(GetRootComponent());
	MotionController->SetShowDeviceModel(true);
	MotionController->SetGenerateOverlapEvents(true);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetGenerateOverlapEvents(true);
	SphereCollider->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AHandController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHandController::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AGrippable* Grippable = Cast<AGrippable>(OtherActor);
	if (Grippable != nullptr)
	{
		GripTarget = Grippable;
	}
}

void AHandController::NotifyActorEndOverlap(AActor* OtherActor)
{
	AGrippable* Grippable = Cast<AGrippable>(OtherActor);
	if (Grippable != nullptr && Grippable == GripTarget)
	{
		GripTarget = NULL;
	}
}

void AHandController::BeginGripTarget()
{
	if (GripTarget != nullptr) 
	{
		CurrentGrippable = GripTarget;
		CurrentGrippable->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		CurrentGrippable->OnGripped();
	}
}

void AHandController::EndGripTarget()
{
	if (CurrentGrippable != nullptr)
	{
		CurrentGrippable->OnUnGripped();
		CurrentGrippable->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CurrentGrippable = NULL;
	}
}





