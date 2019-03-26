// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"

AEnemyController::AEnemyController()
{
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true);
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemyController::OnOverlap);

	RootComponent = RootBox;

	UE_LOG(LogTemp, Warning, TEXT("Enemy spawned"));
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	// Set the pointer to the player
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTowardsPlayer(DeltaTime);
}

void AEnemyController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy overlapped with another object"));

	this->Destroy();
}

void AEnemyController::MoveTowardsPlayer(float DeltaTime)
{
	// Get the current player location
	FVector playerLocation = Player->GetActorLocation();

	// Get the current enemy location
	FVector enemyLocation = GetActorLocation();

	// Get the direction TO the player
	Direction = (playerLocation - enemyLocation).GetSafeNormal();

	// Set Rotation
	SetActorRotation(FRotator::MakeFromEuler(Direction));

	// Calculate the new location for the enemy
	enemyLocation.X += Direction.X * Speed * DeltaTime;
	enemyLocation.Y += Direction.Y * Speed * DeltaTime;
	// No Z movement for this game

	// Set the new location
	SetActorLocation(enemyLocation);
}

// Sets default values
/*AEnemyController::AEnemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true);
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemyController::OnOverlap);

	RootComponent = RootBox;

	UE_LOG(LogTemp, Warning, TEXT("Enemy Spawned"));
}

// Called when the game starts or when spawned
void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	
	// Set the pointer to the player
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get the current player location
	FVector playerLocation = Player->GetActorLocation();

	// Get the current enemy location
	FVector enemyLocation = GetActorLocation();

	// Get the direction TO the player
	Direction = (playerLocation - enemyLocation).GetSafeNormal();

	// Set Rotation
	SetActorRotation(FRotator::MakeFromEuler(Direction));

	// Calculate the new location for the enemy
	enemyLocation.X += Direction.X * Speed * DeltaTime;
	enemyLocation.Y += Direction.Y * Speed * DeltaTime;
	// No Z movement for this game

	// Set the new location
	SetActorLocation(enemyLocation);
}

void AEnemyController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString message = "Name of other actor: " + OtherActor->GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *message);

	if (OtherActor->GetName().ToLower().Contains("projectile"))
	{
		((AFPSGameMode*)GetWorld()->GetAuthGameMode())->IncrementScore();
		((AFPSGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(false);

		this->Destroy();
	}
}*/