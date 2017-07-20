// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "CameraDirector.h"
#include "QuzhouProjectGameMode.h"
#include "QZGameInstance.h"

// Sets default values
ACameraDirector::ACameraDirector()
: m_fMoveDistance(0.0f)
, m_bBrownAuto(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    m_fDeltaTime = 0.0f;
    m_bPlayFirstAnima = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();

    bool bautoBrown = false;
    UQZGameInstance* gameMode = Cast<UQZGameInstance>(GetGameInstance());
    if (gameMode)
    {
        m_bPlayFirstAnima = gameMode->GetPlayCameraAnima();
        bautoBrown = gameMode->GetBrownAuto();
    }

    //m_bPlayFirstAnima = false;

    //代表从室内出来
    if (!m_bPlayFirstAnima)
    {
        CameraFirst->SetActorLocation(FVector(-210 , -160 , 100));
        CameraFirst->SetActorRotation(FVector::ForwardVector.ToOrientationQuat());

        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorLocation(FVector(271, 283, 80));
        }
    }


    if (CameraAnima)
    {
       m_pSplineAnima = Cast<USplineComponent>(CameraAnima->GetRootComponent());
    }

    if (CameraAutoBrown)
    {
        m_pSplineAutoBrown = Cast<USplineComponent>(CameraAutoBrown->GetRootComponent());
    }
	
    
    if (m_bPlayFirstAnima || bautoBrown) //从室内出来 控制权交代
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
    }


}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    m_fDeltaTime += DeltaTime;

    if (m_bPlayFirstAnima && m_pSplineAnima)
    {
        m_fMoveDistance += 150* DeltaTime;

		FVector OldPos = CameraFirst->GetActorLocation();
        FVector moveDis = m_pSplineAnima->GetWorldLocationAtDistanceAlongSpline(m_fMoveDistance);
        CameraFirst->SetActorLocation(moveDis);


		FVector dir = FVector(360, 710, 290)-moveDis;
		dir.Normalize();
		CameraFirst->SetActorRotation(dir.ToOrientationQuat());

        FVector endPos = m_pSplineAnima->GetWorldLocationAtSplinePoint(2);
        if (FVector::DistSquared(moveDis, endPos) <= 100)
        {
            m_bPlayFirstAnima = false;
            m_fMoveDistance = 0.0f;

            SetToPlayerView();

            UQZGameInstance* gameMode = Cast<UQZGameInstance>(GetGameInstance());
            if (gameMode)
            {
                gameMode->SetPlayCameraAnima(m_bPlayFirstAnima);
            }
        }
    }


    //自动浏览
    if (m_bBrownAuto && m_pSplineAutoBrown)
    {
        m_fMoveDistance += 150 * DeltaTime;
        
        FVector OldPos = CameraFirst->GetActorLocation();

        FVector moveDis = m_pSplineAutoBrown->GetWorldLocationAtDistanceAlongSpline(m_fMoveDistance);
        CameraFirst->SetActorLocation(moveDis);

        FVector dir = moveDis - OldPos;
        dir.Normalize();
        CameraFirst->SetActorRotation(dir.ToOrientationQuat());

        APawn* playerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        if (playerPawn)
        {
            playerPawn->SetActorLocation(moveDis);
        }

    }

  
}

void ACameraDirector::SetToPlayerView()
{
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (OurPlayerController)
    {
        CameraThirtPerson = UGameplayStatics::GetPlayerPawn(this , 0);
        if (CameraThirtPerson)
        {
            //Blend smoothly to camera two.
            OurPlayerController->SetViewTarget(CameraThirtPerson);
        }
    }
}

void ACameraDirector::ChangeBrownMode()
{
    m_bBrownAuto = !m_bBrownAuto;

    UQZGameInstance* gameMode = Cast<UQZGameInstance>(GetGameInstance());
    if (gameMode)
    {
        gameMode->SetBrownAuto(m_bBrownAuto);
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

