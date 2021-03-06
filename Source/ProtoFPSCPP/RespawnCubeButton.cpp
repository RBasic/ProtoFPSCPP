// Fill out your copyright notice in the Description page of Project Settings.

#include "RespawnCubeButton.h"
#include "Components/StaticMeshComponent.h"
#include "Cube.h"
#include "Kismet/GameplayStatics.h"
#include "ProtoFPSCPPCharacter.h"
#include "ConstructorHelpers.h"


// Sets default values
ARespawnCubeButton::ARespawnCubeButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>meshRef(TEXT("/Game/Meshes/Pillar_50x500"));
	SetRootComponent(mesh);
	mesh->SetStaticMesh(meshRef.Object);
	mesh->SetNotifyRigidBodyCollision(true);
	mesh->SetCollisionObjectType(ECC_GameTraceChannel3);
}

// Called when the game starts or when spawned
void ARespawnCubeButton::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACube::StaticClass(),cubeRef);
}

// Called every frame
void ARespawnCubeButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARespawnCubeButton::Interact() {
	for (AActor* cube : cubeRef) {
		 ACube *temp = Cast<ACube>(cube);
		 temp->Player->release();
		 temp->respawn = true;
		

	}
}
