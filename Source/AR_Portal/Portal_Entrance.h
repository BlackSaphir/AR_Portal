// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal_Entrance.generated.h"

UCLASS()
class AR_PORTAL_API APortal_Entrance : public AActor
{
	GENERATED_BODY()


		APortal_Entrance();

	// Functions

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	// Variables

private:

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Frame;

	UPROPERTY(EditAnywhere)
		class UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Plane;

	UPROPERTY(EditAnywhere)
		class USceneCaptureComponent2D* PortalView;

	

};
