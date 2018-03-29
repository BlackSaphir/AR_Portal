// Fill out your copyright notice in the Description page of Project Settings.

#include "Portal_Exit.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APortal_Exit::APortal_Exit()
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

	Trigger_Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger_Box->SetupAttachment(Frame);

	Trigger_Box->OnComponentBeginOverlap.AddDynamic(this, &APortal_Exit::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APortal_Exit::BeginPlay()
{
	Super::BeginPlay();

	this->Tags.Add(Portal_Exit_Tag);
	world = GetWorld();
	

}

// Called every frame
void APortal_Exit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (teleported)
	{
		delay_timer += DeltaTime;

		if (delay_timer > 0.5f)
		{
			bCan_teleport = true;
			Portal_1->bCan_teleport = true;
			teleported = false;
			delay_timer = 0.0f;
		}
	}

}

void APortal_Exit::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UGameplayStatics::GetAllActorsWithTag(world, Portal_Entrance_Tag, portal_1_array);
	Portal_1 = Cast<APortal_Entrance>(portal_1_array[0]);

	if (bCan_teleport)
	{
		bCan_teleport = false;
		Portal_1->bCan_teleport = false;

		OtherActor->SetActorLocationAndRotation(FVector(Portal_1->Arrow->GetComponentLocation().X, Portal_1->Arrow->GetComponentLocation().Y, Portal_1->Arrow->GetComponentLocation().Z), FQuat(Portal_1->Arrow->GetComponentRotation()));

		teleported = true;
	}
}

