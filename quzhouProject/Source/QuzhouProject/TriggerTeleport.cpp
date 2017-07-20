// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "MyPlayerController.h"
#include "TriggerTeleport.h"

void ATriggerTeleport::BeginPlay()
{
    Super::BeginPlay();

    GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &ATriggerTeleport::OnOverlapBegin);
}


void ATriggerTeleport::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OverlappedComp && OtherActor != this)
    {
       
       OtherActor->SetActorLocation(TeleportPos);

       AMyPlayerController* OurPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
       if (OurPlayerController)
       {
           OurPlayerController->StopMovement();
       }
    }
}