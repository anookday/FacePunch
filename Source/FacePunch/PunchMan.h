// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FacePunchCharacter.h"
#include "PunchMan.generated.h"

class AProjectileBase;

/**
 * 
 */
UCLASS()
class FACEPUNCH_API APunchMan : public AFacePunchCharacter
{
	GENERATED_BODY()

	private:
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* FistSpawnPoint;
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AProjectileBase> ProjectileClass;

		void Punch();
		
	public:
		APunchMan();
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
