#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HomeworkActor.generated.h"


UENUM(BlueprintType)
enum class EPrintMessage : uint8
{
    Hello UMETA(DisplayName = "Hello"),
    Goodbye UMETA(DisplayName = "Goodbye"),
    Warning UMETA(DisplayName = "Warning")
};


USTRUCT(BlueprintType)
struct FHomeworkData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Homework Data")
    int32 Health = 100;


    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Homework Data")
    float Speed = 600.0f;


    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Homework Data")
    FString PlayerName = TEXT("Player");
};


UCLASS()
class MYPROJECT_API AHomeworkActor : public AActor
{
    GENERATED_BODY()

public:

    AHomeworkActor();


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Homework Data")
    FHomeworkData Data;


    UFUNCTION(BlueprintCallable, Category = "Homework")
    void PrintMessage(EPrintMessage MessageType);
};