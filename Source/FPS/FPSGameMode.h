// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"
#include "Engine/World.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API AFPSGameMode : public AGameMode
{
	GENERATED_BODY()
	
	const float MINIMUM_INTERVAL = 5.5f;
	const float MAXIMUM_INTERVAL = 10.0f;
	const float TIME_TO_MINIMUM_INTERVAL = 30.0f;

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	void IncrementScore();
	void OnGameOver();
	void OnRestart();

	void SpawnEnemy();

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemyController> EnemyBlueprint;

	float EnemyTimer;
	float GameTimer;

protected:

	int Score = 0;

};
