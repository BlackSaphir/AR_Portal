// Fill out your copyright notice in the Description page of Project Settings.

#include "Portal_Entrance.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneCaptureComponent2D.h"


// Sets default values
APortal_Entrance::APortal_Entrance(/*const FObjectInitializer& ObjectInitializer*/)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	RootComponent = Frame;

	Arrow = CreateOptionalDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Frame);

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetupAttachment(Frame);	

	PortalView = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("PortalView"));
	PortalView->SetupAttachment(Frame);
}

// Called when the game starts or when spawned
void APortal_Entrance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortal_Entrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

