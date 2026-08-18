#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.h"


APlatformTrigger::APlatformTrigger()
{

    TriggerBox =
        CreateDefaultSubobject<UBoxComponent>("Trigger");

    RootComponent = TriggerBox;

}



void APlatformTrigger::BeginPlay()
{

    Super::BeginPlay();


    TriggerBox->OnComponentBeginOverlap.AddDynamic(
        this,
        &APlatformTrigger::OnTriggerBegin
    );

}


void APlatformTrigger::OnTriggerBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (Platform)
	{
		Platform->StartMovement();
	}

}