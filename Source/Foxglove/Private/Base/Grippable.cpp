// Fill out your copyright notice in the Description page of Project Settings.


#include "Grippable.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"

// Sets default values
AGrippable::AGrippable()
{

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(75.0f);
	RootComponent = SphereComp;

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	DecalComp->DecalSize = FVector(64, 75, 75);
	DecalComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGrippable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrippable::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
}

