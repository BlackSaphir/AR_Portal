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

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	RootComponent = DefaultRoot;

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Frame->SetupAttachment(DefaultRoot);

	Arrow = CreateOptionalDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(DefaultRoot);

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetupAttachment(DefaultRoot);

	PortalView = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("PortalView"));
	PortalView->SetupAttachment(DefaultRoot);

	Trigger_Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger_Box"));
	Trigger_Box->SetupAttachment(DefaultRoot);

	Trigger_Box->OnComponentBeginOverlap.AddDynamic(this, &APortal_Entrance::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APortal_Entrance::BeginPlay()
{
	Super::BeginPlay();

	this->Tags.Add(Portal_Entrance_Tag);

}

// Called every frame
void APortal_Entrance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (teleported)
	{
		delay_timer += DeltaTime;
		if (delay_timer > 0.5f)
		{
			bCan_teleport = true;
			Portal_2->bCan_teleport = true;
			teleported = false;
			delay_timer = 0.0f;
		}
	}

}

void APortal_Entrance::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    world = GetWorld();
    
    if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
    {
    
    if (world != nullptr)
    {
        UGameplayStatics::GetAllActorsWithTag(world, Portal_Exit_Tag, portal_2_array);
        Portal_2 = Cast<APortal_Exit>(portal_2_array[0]);
        
        if (bCan_teleport)
        {
            bCan_teleport = false;
            Portal_2->bCan_teleport = false;
            
            OtherActor->SetActorLocationAndRotation(FVector(Portal_2->Arrow->GetComponentLocation().X, Portal_2->Arrow->GetComponentLocation().Y, Portal_2->Arrow->GetComponentLocation().Z), FQuat(Portal_2->Arrow->GetComponentRotation()));
            
            teleported = true;
            
        }
    }
    }
	
}

