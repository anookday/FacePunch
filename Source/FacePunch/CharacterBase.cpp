// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "ProjectileBase.h"
#include "PunchMan.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"

#define OUT

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacterBase::BeginPlay() 
{
	Super::BeginPlay();	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckPressurePlate();
}

void ACharacterBase::Launch() 
{
	// don't launch again if Launch() has been triggered
	if (IsDead) return;
	IsDead = true;
	// enable ragdoll mode
	USkeletalMeshComponent* MeshToLaunch = GetMesh();
	GetCharacterMovement()->DisableMovement();
	MeshToLaunch->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshToLaunch->SetAllBodiesSimulatePhysics(true);
	// launch in direction
	FRotator MeshRotationOffset = GetBaseRotationOffsetRotator();
	FVector LaunchDirection = MeshRotationOffset.GetInverse().RotateVector(MeshToLaunch->GetForwardVector());
	LaunchDirection = LaunchDirection * -1.f * MultiplyBackwardForce;
	LaunchDirection.Z += AddUpwardForce;
	MeshToLaunch->AddImpulse(LaunchDirection * MeshToLaunch->GetMass());
}

void ACharacterBase::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if(Other->IsA(AProjectileBase::StaticClass())) 
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, HitParticle, HitLocation);
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, HitLocation);
		Launch();
	}
}

void ACharacterBase::CheckPressurePlate() 
{
	if (!PressurePlate) return;

	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (AActor* Actor : OverlappingActors)
	{
		if (Actor->IsA(APunchMan::StaticClass()))
		{
			Launch();
		}
	}
}
