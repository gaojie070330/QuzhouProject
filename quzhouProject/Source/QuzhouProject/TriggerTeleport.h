// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerBox.h"
#include "TriggerTeleport.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API ATriggerTeleport : public ATriggerBox
{
	GENERATED_BODY()
	
	public:
    UPROPERTY(Category = TriggerBase , EditAnyWhere)
    FVector TeleportPos;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};
