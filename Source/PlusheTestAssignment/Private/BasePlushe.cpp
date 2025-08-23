// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlushe.h"

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

