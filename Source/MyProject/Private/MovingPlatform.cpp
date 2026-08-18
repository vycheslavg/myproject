#include "MovingPlatform.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"


AMovingPlatform::AMovingPlatform()
{

	PrimaryActorTick.bCanEverTick = true;


	PlatformMesh =
		CreateDefaultSubobject<UStaticMeshComponent>("PlatformMesh");

	RootComponent = PlatformMesh;


	Timeline =
		CreateDefaultSubobject<UTimelineComponent>("Timeline");


	MoveDirection = FVector(0, 0, 1);

	MoveDistance = 300.f;

}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();


	StartLocation = GetActorLocation();


	if (MovementCurve)
	{

		FOnTimelineFloat TimelineProgress;

		TimelineProgress.BindUFunction(
			this,
			FName("MovePlatform")
		);


		Timeline->AddInterpFloat(
			MovementCurve,
			TimelineProgress
		);


		Timeline->SetLooping(true);

		Timeline->PlayFromStart();

	}

}



void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timeline)
	{
		Timeline->TickComponent(
			DeltaTime,
			ELevelTick::LEVELTICK_TimeOnly,
			nullptr
		);
	}

}



void AMovingPlatform::MovePlatform(float Value)
{

	FVector NewLocation =
		StartLocation +
		MoveDirection *
		MoveDistance *
		Value;


	SetActorLocation(NewLocation);

}

void AMovingPlatform::StartMovement()
{
	if (Timeline)
	{
		Timeline->PlayFromStart();
	}
}