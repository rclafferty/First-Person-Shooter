// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameMode.h"
#include "EnemyController.h"

void AFPSGameMode::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	for (int i = 0; i < 3; i++)
		SpawnEnemy();
}

void AFPSGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//*******************************
	// WORKING CODE -- DO NOT DELETE
	//*******************************

	/*
	// How long the game has been running
	GameTimer += DeltaTime;

	// Countdown to enemy spawn
	EnemyTimer -= DeltaTime;

	if (EnemyTimer <= 0.0f)
	{
		// Determine the interval until the NEXT enemy (not this enemy) is spawned
		float difficultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);
		EnemyTimer = MAXIMUM_INTERVAL - ((MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * difficultyPercentage);

		// If the world pointer is not null
		if (World)
		{
			// Possibly replace the following with SpawnEnemy();

			// Get a random angle (r) between min <= r <= max
			float randomAngle = FMath::RandRange(MIN_ANGLE, MAX_ANGLE);

			// Get the current player location
			FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

			// Base the enemy location on *current* player location
			FVector enemyLocation = playerLocation;

			// Adjust the location of the enemy to be farther away from the player
			enemyLocation.X += FMath::Cos(randomAngle * PI / 180.0f) * DISTANCE_FROM_PLAYER;
			enemyLocation.Y += FMath::Sin(randomAngle * PI / 180.0f) * DISTANCE_FROM_PLAYER;
			enemyLocation.Z = ENEMY_HEIGHT;

			// Spawn the enemy
			AEnemyController* enemy = World->SpawnActor<AEnemyController>(EnemyBlueprint, enemyLocation, FRotator::ZeroRotator);
		}
	}
	*/

	//*******************************
	// WORKING CODE -- DO NOT DELETE
	//*******************************

}

//AEnemyController* AFPSGameMode::SpawnEnemy()
void AFPSGameMode::SpawnEnemy()
{
	// Get a random angle (r) between min <= r <= max
	float randomAngle = FMath::RandRange(MIN_ANGLE, MAX_ANGLE);

	// Get the current player location
	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// Base the enemy location on *current* player location
	FVector enemyLocation = playerLocation;

	// Adjust the location of the enemy to be farther away from the player
	enemyLocation.X += FMath::Cos(randomAngle * PI / 180.0f) * DISTANCE_FROM_PLAYER;
	enemyLocation.Y += FMath::Sin(randomAngle * PI / 180.0f) * DISTANCE_FROM_PLAYER;
	enemyLocation.Z = ENEMY_HEIGHT;

	// Spawn the enemy
	AEnemyController* enemy = World->SpawnActor<AEnemyController>(EnemyBlueprint, enemyLocation, FRotator::ZeroRotator);
}

void AFPSGameMode::IncrementScore()
{
	Score += 100;

	// TODO: Update UI (After UI is created)
}

void AFPSGameMode::OnGameOver(bool win)
{
	// TODO: Update UI (After UI is created)
	
	// Pause the game
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AFPSGameMode::OnRestart()
{
	// TODO: Restart functionality
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}