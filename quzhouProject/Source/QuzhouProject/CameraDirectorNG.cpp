// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "CameraDirectorNG.h"
#include "QuzhouProjectGameMode.h"
#include "QZGameInstance.h"


// Sets default values
ACameraDirectorNG::ACameraDirectorNG()
: m_bBrownAuto(false)
, m_bBrownAutoTwo(false)
, m_bBrownAutoThree(false)
, m_bBrownAutoAll(false)
, m_bCurSplineIndex(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirectorNG::BeginPlay()
{
	Super::BeginPlay();
	
    UQZGameInstance* gameMode = Cast<UQZGameInstance>(GetGameInstance());
    if (gameMode)
    {
        m_bBrownAuto = gameMode->GetBrownAuto();
    }

    if (m_bBrownAuto)
    {
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (OurPlayerController)
        {
            if (CameraFirst)
            {
                //Blend smoothly to camera two.
                OurPlayerController->SetViewTarget(CameraFirst);
            }
        }

        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorScale3D(FVector(0.001f, 0.001f, 0.001f));
        }
    }


    if (CameraAutoBrown)
    {
        m_pSplineAutoBrown = Cast<USplineComponent>(CameraAutoBrown->GetRootComponent());
        m_arrSpline.Add(m_pSplineAutoBrown);
    }

    if (CameraAutoBrownTwo)
    {
        m_pSplineAutoBrownTwo = Cast<USplineComponent>(CameraAutoBrownTwo->GetRootComponent());
        m_arrSpline.Add(m_pSplineAutoBrownTwo);
    }

    if (CameraAutoBrownThree)
    {
        m_pSplineAutoBrownThree = Cast<USplineComponent>(CameraAutoBrownThree->GetRootComponent());
        m_arrSpline.Add(m_pSplineAutoBrownThree);
    }

    m_CurSplineAutoBrown = m_arrSpline[0];

    m_arrPointNum.Add(1);
    m_arrPointNum.Add(3);
    m_arrPointNum.Add(3);
}

// Called every frame
void ACameraDirectorNG::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //×Ô¶¯ä¯ÀÀ
    if (m_bBrownAuto && m_CurSplineAutoBrown)
    {
        m_fMoveDistance += 100 * DeltaTime;

        FVector OldPos = CameraFirst->GetActorLocation();

        FVector moveDis = m_CurSplineAutoBrown->GetWorldLocationAtDistanceAlongSpline(m_fMoveDistance);
        CameraFirst->SetActorLocation(moveDis);

        FVector dir = moveDis - OldPos;
        dir.Normalize();
        CameraFirst->SetActorRotation(dir.ToOrientationQuat());

        FVector endPos = m_CurSplineAutoBrown->GetWorldLocationAtSplinePoint(m_arrPointNum[m_bCurSplineIndex]);
        if (FVector::DistSquared(moveDis, endPos) <= 100)
        {
            m_fMoveDistance = 0.0f;
            m_bCurSplineIndex++;

            if (m_bCurSplineIndex <= m_arrSpline.Num())
            {
                m_CurSplineAutoBrown = m_arrSpline[m_bCurSplineIndex];
            }
            else
                m_bBrownAuto = false;

        }

        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorLocation(moveDis);
        }
    }
}

void ACameraDirectorNG::SetToPlayerView()
{
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (OurPlayerController)
    {
        CameraThirtPerson = UGameplayStatics::GetPlayerPawn(this, 0);
        if (CameraThirtPerson)
        {
            //Blend smoothly to camera two.
            OurPlayerController->SetViewTarget(CameraThirtPerson);
        }
    }
}

void ACameraDirectorNG::ChangeBrownMode()
{
    m_bBrownAuto = !m_bBrownAuto;

    if (m_bBrownAuto)
    {
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (OurPlayerController)
        {
            if (CameraFirst)
            {
                //Blend smoothly to camera two.
                OurPlayerController->SetViewTarget(CameraFirst);
            }
        }
        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorScale3D(FVector(0.001f, 0.001f, 0.001f));
        }
    }
    else
    {
        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
        }
        SetToPlayerView();
    }
}

