#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"


class UBoxComponent;
class AMovingPlatform;


UCLASS()
class MYPROJECT_API APlatformTrigger : public AActor
{
	GENERATED_BODY()


public:

	APlatformTrigger();


protected:

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox;


	UPROPERTY(EditAnywhere, Category = "Platform")
	AMovingPlatform* Platform;



	UFUNCTION()
	void OnTriggerBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

};