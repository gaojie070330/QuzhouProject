// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "CameraDirectorNG.generated.h"

UCLASS()
class QUZHOUPROJECT_API ACameraDirectorNG : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirectorNG();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void SetToPlayerView();

public:
    void ChangeBrownMode();


    UPROPERTY(EditAnywhere)
        AActor* CameraFirst;

    UPROPERTY(EditAnywhere)
        AActor* CameraThirtPerson;

    UPROPERTY(EditAnywhere)
        AActor* CameraAutoBrown;

    UPROPERTY(EditAnywhere)
        AActor* CameraAutoBrownTwo;

    UPROPERTY(EditAnywhere)
        AActor* CameraAutoBrownThree;

    //spline
    float m_fMoveDistance;

    int                 m_bCurSplineIndex;
    USplineComponent*   m_CurSplineAutoBrown;

    USplineComponent*   m_pSplineAutoBrown;

    USplineComponent*   m_pSplineAutoBrownTwo;

    USplineComponent*   m_pSplineAutoBrownThree;

    TArray<USplineComponent*>  m_arrSpline;
    TArray<int>                 m_arrPointNum;

    float m_fDeltaTime;

    bool m_bBrownAutoAll;

    bool m_bBrownAuto;
    bool m_bBrownAutoTwo;
    bool m_bBrownAutoThree;
	
};
