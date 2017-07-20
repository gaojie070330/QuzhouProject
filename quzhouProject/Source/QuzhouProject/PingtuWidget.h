// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h" 


#include "PingtuWidget.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API UPingtuWidget : public UUserWidget
{
	GENERATED_BODY()
	
    bool Initialize() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "WidgetFunction")
	void SetClickPTBtn(UButton* btn , int index);

	UFUNCTION(BlueprintCallable, Category = "WidgetFunction")
	bool SetClickSlotBtn(int index);

	UFUNCTION(BlueprintCallable, Category = "WidgetFunction")
	void OnClickAllBtn();


	UButton* m_PT1;
	UButton* m_PT2;
	UButton* m_PT3;
	UButton* m_PT4;

protected:
    void PTReturnBack();



	int m_iCurIndex;
	UButton* m_CurBtn;
};
