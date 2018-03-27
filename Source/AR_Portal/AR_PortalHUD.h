// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AR_PortalHUD.generated.h"

UCLASS()
class AAR_PortalHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAR_PortalHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

