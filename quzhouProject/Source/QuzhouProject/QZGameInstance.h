// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "QZGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API UQZGameInstance : public UGameInstance
{
	GENERATED_BODY()
        UQZGameInstance();

public:
    bool GetBrownAuto() { return m_bBrownAuto; }
    void SetBrownAuto(bool bFlag) { m_bBrownAuto = bFlag; }

    bool GetPlayCameraAnima() { return m_bPlayCameraAnima; }
    void SetPlayCameraAnima(bool bFlag) { m_bPlayCameraAnima = bFlag; }

	bool GetThirdPerson() { return m_bThirdPerson; }
	void SetThirdPerson(bool bFlag) { m_bThirdPerson = bFlag; }

    bool GetShowPlayerType() {return m_bShowGirl;}
    void SetShowPlayerType(bool bFlag) { m_bShowGirl = bFlag;}


    bool PlayBGM();

private:
    bool m_bBrownAuto;

    bool m_bPlayCameraAnima;

    bool m_bPlayBGM;

	bool m_bThirdPerson;

    USoundWave* m_BGM;

	bool m_bShowGirl;
	
};
