// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "QZBlueprintFunctionLibrary.h"
#include "CameraDirector.h"
#include "CameraDirectorNG.h"
#include "EngineUtils.h"
#include "QZGameInstance.h"
#include "QuzhouProjectCharacter.h"
#include "MyPlayerController.h"

void UQZBlueprintFunctionLibrary::SetBrowseMode()
{
    for (TObjectIterator<ACameraDirector> Itr; Itr; ++Itr)
    {
        Itr->ChangeBrownMode();
    }

    for (TObjectIterator<ACameraDirectorNG> Itr; Itr; ++Itr)
    {
        Itr->ChangeBrownMode();
    }
}


bool UQZBlueprintFunctionLibrary::IfPlayerBackGroud()
{
    return false;
}

bool UQZBlueprintFunctionLibrary::ChangePlayerPerson()
{
	for (TObjectIterator<AQuzhouProjectCharacter> Itr; Itr; ++Itr)
	{
		Itr->ChangePerson();
		return true;
	}

	return true;
}

void UQZBlueprintFunctionLibrary::ShowPlayerGirl()
{
    for (TObjectIterator<AQuzhouProjectCharacter> Itr; Itr; ++Itr)
    {
        Itr->ShowGril();
    }

}

void UQZBlueprintFunctionLibrary::ShowPlayerMan()
{
    for (TObjectIterator<AQuzhouProjectCharacter> Itr; Itr; ++Itr)
    {
        Itr->ShowMan();
    }

}

void UQZBlueprintFunctionLibrary::SetNotShowIma()
{
	for (TObjectIterator<AMyPlayerController> Itr; Itr; ++Itr)
	{
		Itr->SetNotShowIma();
	}

}


