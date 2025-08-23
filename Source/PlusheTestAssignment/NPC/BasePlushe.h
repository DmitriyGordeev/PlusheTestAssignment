// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../PlusheSettings.h"
#include "BasePlushe.generated.h"





UCLASS()
class PLUSHETESTASSIGNMENT_API ABasePlushe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasePlushe();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Здесь происходит загрузка параметров из uasset
	virtual void LoadSettings();
	
	virtual void ApplySettings();

	UPROPERTY(EditDefaultsOnly)
	TSoftClassPtr<UPlusheSettings> PlusheSettingsAsset;

	UPROPERTY()
	UPlusheSettings* Settings = nullptr;

	UPROPERTY()
	EPlusheTypeD Type = EPlusheTypeD::Aggressive;

	UPROPERTY(BlueprintReadWrite)
	float PerceptionEnterRadius {200.0f};

	UPROPERTY(BlueprintReadWrite)
	float PerceptionLosingSight {300.0f};
};
