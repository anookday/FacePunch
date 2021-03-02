// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class ATriggerVolume;

UCLASS()
class FACEPUNCH_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
	float MultiplyBackwardForce = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics", meta = (AllowPrivateAccess = "true"))
	float AddUpwardForce = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggers", meta = (AllowPrivateAccess = "true"))
	ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* HitSound;

	bool IsDead = false;

	void CheckPressurePlate();

public:
	ACharacterBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void Launch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called when the actor is hit
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

};
