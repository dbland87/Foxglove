// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Runtime/Engine/Classes/Components/SphereComponent.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grippable.generated.h"

class USphereComponent;
class UDecalComponent;

UCLASS()
class FOXGLOVE_API AGrippable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrippable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp;

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public :

	UFUNCTION(BlueprintImplementableEvent, Category = "Grippables");
	void OnGripped();

	UFUNCTION(BlueprintImplementableEvent, Category = "Grippables");
	void OnUnGripped();
};
