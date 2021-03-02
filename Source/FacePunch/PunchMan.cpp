// Fill out your copyright notice in the Description page of Project Settings.


#include "PunchMan.h"
#include "ProjectileBase.h"

APunchMan::APunchMan()
{
  FistSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	FistSpawnPoint->SetupAttachment(RootComponent);
}

void APunchMan::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) 
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);
  PlayerInputComponent->BindAction("Punch", IE_Pressed, this, &APunchMan::Punch);
}

void APunchMan::Punch() 
{
  if (ProjectileClass)
	{
    FVector SpawnLocation = FistSpawnPoint->GetComponentLocation();
    FRotator SpawnRotation = FistSpawnPoint->GetComponentRotation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(
			ProjectileClass, 
      SpawnLocation,
      SpawnRotation
		);
		TempProjectile->SetOwner(this);
	}	  
}
