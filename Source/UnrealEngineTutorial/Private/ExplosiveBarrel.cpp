// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BarrelStaticMeshComponent");
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnExplosiveBarrelHitCallback);
	RadialComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComponent");
	RadialComponent->SetupAttachment(StaticMeshComponent);
	RadialComponent->Radius = 650.0f;
	RadialComponent->ImpulseStrength = 2000.0f;
	RadialComponent->bImpulseVelChange = true;
}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExplosiveBarrel::OnExplosiveBarrelHitCallback(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialComponent->FireImpulse();
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

