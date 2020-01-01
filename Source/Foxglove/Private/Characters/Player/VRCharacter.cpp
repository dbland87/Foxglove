// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Components/CapsuleComponent.h"
#include "HandController.h"


// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetupVROrigin();
	SetupCamera();	
}



// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	//TODO: Should this happen in BeginPlay? What happens if they don't have controllers on yet?
	SpawnControllers();
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
}

void AVRCharacter::PrimaryGripPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("Primary Grip Pressed"));
	RightController->BeginGripTarget();
}

void AVRCharacter::PrimaryGripReleased()
{
	//UE_LOG(LogTemp, Warning, TEXT("Primary Grip Released"));
	RightController->EndGripTarget();
}

void AVRCharacter::PrimaryTriggerPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("Primary Trigger Pressed"));
	
}

void AVRCharacter::PrimaryTriggerReleased()
{
	//UE_LOG(LogTemp, Warning, TEXT("Primary Trigger Released"));
}

void AVRCharacter::SecondaryGripPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("Secondary Grip Pressed"));
	LeftController->BeginGripTarget();
}

void AVRCharacter::SecondaryGripReleased()
{
	//UE_LOG(LogTemp, Warning, TEXT("Secondary Grip Released"));
	LeftController->EndGripTarget();
}

void AVRCharacter::SecondaryTriggerPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("Secondary Trigger Pressed"));
}

void AVRCharacter::SecondaryTriggerReleased()
{
	//UE_LOG(LogTemp, Warning, TEXT("Secondary Trigger Released"));
}

void AVRCharacter::SetupVROrigin()
{
	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());
}

void AVRCharacter::SetupCamera()
{
	CameraBase = CreateDefaultSubobject<USceneComponent>(TEXT("CameraBase"));
	CameraBase->SetupAttachment(GetRootComponent());

	float halfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	FVector Position;
	Position.X = 0.0f;
	Position.Y = 0.0f;
	Position.Z = -halfHeight;

	FTransform Transform;
	Transform.SetLocation(Position);
	CameraBase->SetRelativeTransform(Transform);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBase);
}

void AVRCharacter::SpawnControllers()
{
	LeftController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);

	check(LeftController);
	LeftController->AttachToComponent(CameraBase, FAttachmentTransformRules::KeepRelativeTransform);
	LeftController->SetOwner(this);
	LeftController->SetHand(EControllerHand::Left);
	
	RightController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);

	check(RightController);
	RightController->AttachToComponent(CameraBase, FAttachmentTransformRules::KeepRelativeTransform);
	RightController->SetOwner(this);
	RightController->SetHand(EControllerHand::Right);
	
}
