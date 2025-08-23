// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlushe.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABasePlushe::ABasePlushe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePlushe::BeginPlay()
{
	Super::BeginPlay();

	LoadSettings();
	
}

void ABasePlushe::LoadSettings()
{
	if (!PlusheSettingsAsset)
		return;
	
	// UClass* AssetClass = PlusheSettingsAsset.Get();
	// if (!AssetClass)
	// {
	// 	AssetClass = PlusheSettingsAsset.LoadSynchronous();
	// }
	// UE_LOG(LogTemp, Log, TEXT("AssetClass = %s"), *AssetClass->GetName());
	// Settings = NewObject<UPlusheSettings>(this, AssetClass);

	FStreamableDelegate LoadDelegate;
	LoadDelegate.BindLambda([this]()
	{
		// This lambda executes once the asset is loaded
		UClass* AssetClass = PlusheSettingsAsset.Get();
		if (AssetClass)
		{
			UE_LOG(LogTemp, Log, TEXT("AssetClass = %s"), *AssetClass->GetName());
			Settings = NewObject<UPlusheSettings>(this, AssetClass);
			ApplySettings();
			OnSettingsLoaded();
		}
	});
	
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(PlusheSettingsAsset.ToSoftObjectPath(), LoadDelegate);
}

void ABasePlushe::ApplySettings()
{
	if (!Settings)
	{
		UE_LOG(LogTemp, Log, TEXT("Settings is null"));
		return;
	}

	if (auto* CharMoveComp = GetCharacterMovement())
	{
		CharMoveComp->MaxWalkSpeed = Settings->MaxSpeed;
		UE_LOG(LogTemp, Log, TEXT("Applied new MaxWalkSpeed = %f from settings"), Settings->MaxSpeed);
	}

	Type = Settings->Type;
	UE_LOG(LogTemp, Log, TEXT("Applied new Type = %i from settings"), Type);

	PerceptionEnterRadius = Settings->PerceptionEnterRadius;
	UE_LOG(LogTemp, Log, TEXT("Applied new PerceptionEnterRadius = %f from settings"), PerceptionEnterRadius);

	PerceptionLosingSight = Settings->PerceptionLosingSightRadius;
	UE_LOG(LogTemp, Log, TEXT("Applied new PerceptionLosingSight = %f from settings"), PerceptionLosingSight);
}

// Called every frame
void ABasePlushe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlushe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


