// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "QZGameInstance.h"



UQZGameInstance::UQZGameInstance()
	: m_bBrownAuto(false)
	, m_bPlayCameraAnima(true)
	, m_bPlayBGM(false)
	, m_bThirdPerson(false)
    , m_bShowGirl(true)
{
    static ConstructorHelpers::FObjectFinder<USoundWave> SWBattleBGM(TEXT("/Game/Movies/beijing"));
    m_BGM = SWBattleBGM.Object;
}

bool UQZGameInstance::PlayBGM()
{
    m_bPlayBGM = !m_bPlayBGM;


    return m_bPlayBGM;

    
}
