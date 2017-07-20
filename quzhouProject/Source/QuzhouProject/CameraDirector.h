// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "CameraDirector.generated.h"

class ASplineMeshActor;
class USplineMeshComponent;

UCLASS()
class QUZHOUPROJECT_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void SetToPlayerView();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void ChangeBrownMode();


    UPROPERTY(EditAnywhere)
    AActor* CameraFirst;

    UPROPERTY(EditAnywhere)
    AActor* CameraThirtPerson;

    UPROPERTY(EditAnywhere)
    AActor* CameraAnima;

    UPROPERTY(EditAnywhere)
    AActor* CameraAutoBrown;

    //spline
    USplineComponent* m_pSplineAnima;
    float m_fMoveDistance;

    USplineComponent* m_pSplineAutoBrown;

    float m_fDeltaTime;
    bool  m_bPlayFirstAnima;

    bool m_bBrownAuto;
	
	
};
