// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MotionControllerComponent.h"
#include "Components/SceneComponent.h"
#include "VRCharacter.generated.h"

UCLASS()
class FOXGLOVE_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetupVROrigin();

	void SetupCamera();

	void SpawnControllers();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* CameraBase;

	/*UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CapsuleComponent;*/

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly)
	class AHandController* LeftController;

	UPROPERTY(EditDefaultsOnly)
	class AHandController* RightController;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandController> HandControllerClass;

public :

	// Input functions
	void PrimaryGripPressed(); 
	void PrimaryGripReleased();
	void PrimaryTriggerPressed();
	void PrimaryTriggerReleased();

	void SecondaryGripPressed();
	void SecondaryGripReleased();
	void SecondaryTriggerPressed();
	void SecondaryTriggerReleased();

};
