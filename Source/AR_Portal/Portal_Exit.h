// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal_Exit.generated.h"

UCLASS()
class AR_PORTAL_API APortal_Exit : public AActor
{
	GENERATED_BODY()
	
		// Functions

public:	
	// Sets default values for this actor's properties
	APortal_Exit();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	// Variable

public:

	UPROPERTY(EditAnywhere)
		FName Portal_Entrance_Tag;

	UPROPERTY(EditAnywhere)
		FName Portal_Exit_Tag;
	
	
};
