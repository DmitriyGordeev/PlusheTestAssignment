// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PLUSHETESTASSIGNMENT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Input handlers --------------------------------------------  */
	virtual void MoveInputTriggered(const FInputActionValue& Value);
	virtual void MoveInputCompleted(const FInputActionValue& Value);
	
	virtual void LookInputTriggered(const FInputActionValue& Value);
	virtual void LookInputCompleted(const FInputActionValue& Value);
	
	
	/* Input ------------------------- */
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput", meta = (AllowPrivateAccess = "true"))
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
};
