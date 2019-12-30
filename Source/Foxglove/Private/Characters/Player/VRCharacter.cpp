// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	LeftController->SetupAttachment(GetRootComponent());
	LeftController->SetTrackingSource(EControllerHand::Left);
	LeftController->SetShowDeviceModel(true);

	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightController"));
	RightController->SetupAttachment(GetRootComponent());
	RightController->SetTrackingSource(EControllerHand::Right);
	RightController->SetShowDeviceModel(true);
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	InputComponent->BindAction("GripRight", IE_Pressed, this, &AVRCharacter::PrimaryGripPressed);
	InputComponent->BindAction("GripRight", IE_Released, this, &AVRCharacter::PrimaryGripReleased);
	InputComponent->BindAction("TriggerRight", IE_Pressed, this, &AVRCharacter::PrimaryTriggerPressed);
	InputComponent->BindAction("TriggerRight", IE_Released, this, &AVRCharacter::PrimaryTriggerReleased);

	InputComponent->BindAction("GripLeft", IE_Pressed, this, &AVRCharacter::SecondaryGripPressed);
	InputComponent->BindAction("GripLeft", IE_Released, this, &AVRCharacter::SecondaryGripReleased);
	InputComponent->BindAction("TriggerLeft", IE_Pressed, this, &AVRCharacter::SecondaryTriggerPressed);
	InputComponent->BindAction("TriggerLeft", IE_Released, this, &AVRCharacter::SecondaryTriggerReleased);

	InputComponent->BindAction("ButtonPressed", IE_Pressed, this, &AVRCharacter::PrimaryTriggerPressed);
}

void AVRCharacter::PrimaryGripPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Primary Grip Pressed"));
}

void AVRCharacter::PrimaryGripReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Primary Grip Released"));
}

void AVRCharacter::PrimaryTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Primary Trigger Pressed"));
}

void AVRCharacter::PrimaryTriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Primary Trigger Released"));
}

void AVRCharacter::SecondaryGripPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Secondary Grip Pressed"));
}

void AVRCharacter::SecondaryGripReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Secondary Grip Released"));
}

void AVRCharacter::SecondaryTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Secondary Trigger Pressed"));
}

void AVRCharacter::SecondaryTriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Secondary Trigger Released"));
}
