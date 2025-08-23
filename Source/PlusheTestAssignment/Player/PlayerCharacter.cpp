// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Setup MappingContext
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (InputMappingContext)
				Subsystem->AddMappingContext(InputMappingContext, 0); // 0 is priority
		}
	}
	
}

void APlayerCharacter::MoveInputTriggered(const FInputActionValue& Value)
{
}

void APlayerCharacter::MoveInputCompleted(const FInputActionValue& Value)
{
}

void APlayerCharacter::LookInputTriggered(const FInputActionValue& Value)
{
}

void APlayerCharacter::LookInputCompleted(const FInputActionValue& Value)
{
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

