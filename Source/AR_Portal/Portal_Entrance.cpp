// Fill out your copyright notice in the Description page of Project Settings.

#include "Portal_Entrance.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Portal_Exit.h"


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

	Trigger_Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger_Box"));
	Trigger_Box->SetupAttachment(Frame);

	Trigger_Box->OnComponentBeginOverlap.AddDynamic(this, &APortal_Entrance::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APortal_Entrance::BeginPlay()
{
	Super::BeginPlay();

	world = GetWorld();

	this->Tags.Add(Portal_Entrance_Tag);

	UGameplayStatics::GetAllActorsWithTag(world, FName ("Portal_Exit"), portal_2_Array);
	APortal_Exit* Portal_2 = Cast<APortal_Exit>(portal_2_Array[0]);
}

// Called every frame
void APortal_Entrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortal_Entrance::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bCan_teleport)
	{
		bCan_teleport = false;
	}
}

