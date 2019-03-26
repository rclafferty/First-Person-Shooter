// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"
#include "FPSGameMode.generated.h"

#define PI 3.1415926535897

/**
 * 
 */
UCLASS()
class FIRSTPERSONSHOOTER_API AFPSGameMode : public AGameMode
{
	GENERATED_BODY()
	
private:

	const float MINIMUM_INTERVAL = 0.5f;
	const float MAXIMUM_INTERVAL = 2.0f;
	const float TIME_TO_MINIMUM_INTERVAL = 30.0f;

	const float DISTANCE_FROM_PLAYER = 800.0f;
	const float MIN_ANGLE = 0.0f;
	const float MAX_ANGLE = 360.0f;

	const float ENEMY_HEIGHT = 240.0f;

	UWorld* World;
	
protected:

	int Score = 0;

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void IncrementScore();
	void OnGameOver(bool win);
	void OnRestart();

	//AEnemyController* SpawnEnemy();
	void SpawnEnemy();

	// Pointer to blueprint for enemy to be spawned
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemyController> EnemyBlueprint;

	// Countdown to enemy spawn
	float EnemyTimer;

	// How long the game has been running
	float GameTimer;
};
