// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NPC/EPlusheType.h"
#include "PlusheSettings.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PLUSHETESTASSIGNMENT_API UPlusheSettings : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	float MaxSpeed {200.0f};

	UPROPERTY(EditDefaultsOnly)
	float PerceptionEnterRadius {200.0f};

	UPROPERTY(EditDefaultsOnly)
	float PerceptionLosingSightRadius {300.0f};

	UPROPERTY(EditDefaultsOnly)
	EPlusheTypeD Type = EPlusheTypeD::Aggressive;
};
