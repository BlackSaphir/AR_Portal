// Fill out your copyright notice in the Description page of Project Settings.

#include "AR_Pawn.h"


// Sets default values
AAR_Pawn::AAR_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAR_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAR_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAR_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

