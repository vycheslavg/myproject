#include "HomeworkActor.h"
#include "Engine/Engine.h"


AHomeworkActor::AHomeworkActor()
{
    PrimaryActorTick.bCanEverTick = false;
}


void AHomeworkActor::PrintMessage(EPrintMessage MessageType)
{
    FString Message;


    switch (MessageType)
    {
    case EPrintMessage::Hello:
    {
        Message = TEXT("Hello!");
        break;
    }


    case EPrintMessage::Goodbye:
    {
        Message = TEXT("Goodbye!");
        break;
    }


    case EPrintMessage::Warning:
    {
        Message = TEXT("Warning!");
        break;
    }


    default:
    {
        Message = TEXT("Unknown message");
        break;
    }
    }


    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Green,
            Message
        );
    }
}