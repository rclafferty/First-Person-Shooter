// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"


// Sets default values
AEnemyController::AEnemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true);
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemyController::OnOverlap);

	RootComponent = RootBox;
}

// Called when the game starts or when spawned
void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTowardsPlayer(DeltaTime);
}

void AEnemyController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}

	if (OtherActor->GetName().ToLower().Contains("projectile"))
	{
		OtherActor->Destroy();
		this->Destroy();
	}
}

void AEnemyController::MoveTowardsPlayer(float DeltaTime)
{
	// Get the current player location
	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// Get the current enemy location
	FVector enemyLocation = GetActorLocation();

	// Get the direction TO the player
	Direction = (playerLocation - enemyLocation).GetSafeNormal();

	// Set Rotation
	SetActorRotation(FRotator::MakeFromEuler(Direction));

	// Calculate the new location for the enemy
	enemyLocation.X += Direction.X * SPEED * DeltaTime;
	enemyLocation.Y += Direction.Y * SPEED * DeltaTime;
	// No Z movement for this game

	// Set the new location
	SetActorLocation(enemyLocation);
}