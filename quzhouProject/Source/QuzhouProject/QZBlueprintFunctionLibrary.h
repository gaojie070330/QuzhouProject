// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "QZBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API UQZBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
    UFUNCTION(BlueprintCallable, Category = "Quzhou")
    static void SetBrowseMode();

    UFUNCTION(BlueprintCallable, Category = "Quzhou")
    static bool IfPlayerBackGroud();

	UFUNCTION(BlueprintCallable, Category = "Quzhou")
	static bool ChangePlayerPerson();

	UFUNCTION(BlueprintCallable, Category = "Quzhou")
	static void SetNotShowIma();


    UFUNCTION(BlueprintCallable, Category = "Quzhou")
    static void ShowPlayerGirl();

    UFUNCTION(BlueprintCallable, Category = "Quzhou")
    static void ShowPlayerMan();

};
