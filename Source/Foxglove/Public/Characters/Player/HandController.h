// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "Grippable.h"
#include "HandController.generated.h"

UCLASS()
class FOXGLOVE_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();

	void SetHand(EControllerHand Hand);
	
	//K{ MotionController->SetTrackingSource(Hand); }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereCollider;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

private:


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMotionControllerComponent* MotionController;

	UPROPERTY(VisibleAnywhere)
	AGrippable* GripTarget;

	UPROPERTY(VisibleAnywhere)
	AGrippable* CurrentGrippable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool NeedsFlipped;

	void BeginGripTarget();
	void EndGripTarget();
};
