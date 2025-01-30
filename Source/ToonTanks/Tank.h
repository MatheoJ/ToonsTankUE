// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, CAtegory= "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, CAtegory = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	float speed = 200.0f;

	UPROPERTY(EditAnywhere)
	float TurnRate = 45.0f;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* PlayerControllerRef;
	
};
