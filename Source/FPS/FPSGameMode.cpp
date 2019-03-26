// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameMode.h"

void AFPSGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;

	if (EnemyTimer <= 0.0f)
	{
		float difficultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);
		EnemyTimer = MINIMUM_INTERVAL - ((MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * difficultyPercentage);

		UWorld* World = GetWorld();
		if (World)
		{
			SpawnEnemy();
		}
	}
}

void AFPSGameMode::SpawnEnemy()
{
	float distance = 800.0f;
	float randomAngle = FMath::RandRange(0.0f, 360.0f);

	//FVector playerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();

	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	FVector enemyLocation = playerLocation;

	enemyLocation.X += FMath::Cos(randomAngle * 3.14f / 180.0f) * distance;
	enemyLocation.Y += FMath::Sin(randomAngle * 3.14f / 180.0f) * distance;
	enemyLocation.Z = 220.0f;

	AEnemyController* enemy = GetWorld()->SpawnActor<AEnemyController>(EnemyBlueprint, enemyLocation, FRotator::ZeroRotator);
}

void AFPSGameMode::IncrementScore()
{

}

void AFPSGameMode::OnGameOver()
{

}

void AFPSGameMode::OnRestart()
{

}