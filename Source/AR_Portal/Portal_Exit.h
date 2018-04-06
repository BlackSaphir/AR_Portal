// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal_Entrance.h"
#include "Engine/World.h"
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

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// Variable

public:

	UPROPERTY(EditAnywhere)
		FName Portal_Entrance_Tag;

	UPROPERTY(EditAnywhere)
		FName Portal_Exit_Tag;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Frame;

	UPROPERTY(EditAnywhere)
		class UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Plane;

	UPROPERTY(EditAnywhere)
		class USceneCaptureComponent2D* PortalView;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Trigger_Box;

	bool bCan_teleport = true;

private:

	const UWorld* world;
	TArray<AActor*> portal_1_array;
	class APortal_Entrance* Portal_1;
	bool teleported = false;
	float delay_timer;

};
