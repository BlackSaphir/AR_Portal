// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AR_PortalGameMode.h"
#include "AR_PortalHUD.h"
#include "AR_PortalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAR_PortalGameMode::AAR_PortalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAR_PortalHUD::StaticClass();
}
