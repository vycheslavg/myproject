#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"


class UTimelineComponent;
class UCurveFloat;


UCLASS()
class MYPROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();


	// запуск платформы из триггера
	UFUNCTION(BlueprintCallable)
	void StartMovement();


protected:

	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY()
	UStaticMeshComponent* PlatformMesh;


	UPROPERTY()
	UTimelineComponent* Timeline;


	UPROPERTY(EditAnywhere, Category="Movement")
	UCurveFloat* MovementCurve;


	UPROPERTY(EditAnywhere, Category="Movement")
	FVector MoveDirection;


	UPROPERTY(EditAnywhere, Category="Movement")
	float MoveDistance;


	FVector StartLocation;


	UFUNCTION()
	void MovePlatform(float Value);

};