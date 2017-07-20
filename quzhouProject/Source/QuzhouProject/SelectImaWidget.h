// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Image.h" 
#include "Runtime/UMG/Public/Components/Button.h" 
#include "SelectImaWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API USelectImaWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
    UFUNCTION(BlueprintCallable, Category = "WidgetFunction")
    void OnClickLeftBtn();
	
    UFUNCTION(BlueprintCallable, Category = "WidgetFunction")
    void OnClickRightBtn();

    bool Initialize() override;

    void ShowImageByIndex();

    private:
    TArray<UImage*> m_arrImage;

    UButton* m_LeftBtn;

    UButton* m_RightBtn;

    int m_CurIndex;

};
