// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
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

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// Variables

public:

	UPROPERTY(EditAnywhere)
		class USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Frame;

	UPROPERTY(EditAnywhere)
		class UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Plane;

	UPROPERTY(EditAnywhere)
		class USceneCaptureComponent2D* PortalView;

	UPROPERTY(EditAnywhere)
		FName Portal_Entrance_Tag;

	UPROPERTY(EditAnywhere)
		FName Portal_Exit_Tag;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Trigger_Box;

	bool bCan_teleport = true;

private:

	TArray<AActor*> portal_2_array;
    const UWorld* world;
    UObject* world_Object;
	bool teleported = false;
	float delay_timer;
	class APortal_Exit* Portal_2;
	

};
