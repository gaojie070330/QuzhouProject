// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "PingtuWidget.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime//UMG/Public/Blueprint/WidgetLayoutLibrary.h"


bool UPingtuWidget::Initialize()
{

    if (!Super::Initialize())
    {
        return false;
    }

    bCanEverTick = true;

	m_PT1 = Cast<UButton>(GetWidgetFromName("Button0"));

    return true;
}


void UPingtuWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

    if (m_CurBtn)
    {
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (OurPlayerController)
        {
            float LocX = 0;
            float LocY = 0;

            UWidgetLayoutLibrary::GetMousePositionScaledByDPI(OurPlayerController , LocX , LocY);

            UCanvasPanelSlot* slot =  Cast<UCanvasPanelSlot>(m_CurBtn->Slot);
            slot->SetPosition(FVector2D(LocX - 200, LocY - 200) );
           // UE_LOG(LogTemp, Warning, TEXT("LocX %f  LocY %f"), LocX, LocY);
        }
    }

}

void UPingtuWidget::OnClickAllBtn()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClickAllBtn"));
	if (m_CurBtn)
	{
        PTReturnBack();
	}
}

void UPingtuWidget::SetClickPTBtn(UButton* btn, int index)
{
	if (m_CurBtn)
	{
        PTReturnBack();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SetClickPTBtn"));
		m_CurBtn = btn;
		m_iCurIndex = index;
		//m_CurBtn->SetVisibility(ESlateVisibility::Hidden);
	}
	
}

bool UPingtuWidget::SetClickSlotBtn(int index)
{
	UE_LOG(LogTemp, Warning, TEXT("SetClickSlotBtn"));
	if (m_CurBtn)
	{
		if (m_iCurIndex == index)
		{
            m_CurBtn->SetVisibility(ESlateVisibility::Hidden);
			m_CurBtn = nullptr;
			return true;
		}

        PTReturnBack();
	}

	return false;
}


void UPingtuWidget::PTReturnBack()
{
    if (m_CurBtn)
    {
        UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(m_CurBtn->Slot);
        if (m_CurBtn->GetName() == "PT0")
        {
            m_CurBtn->SetRenderTranslation(FVector2D(0,0));
            slot->SetPosition(FVector2D(196, 524));
        }
        else if (m_CurBtn->GetName() == "PT1")
        {
            m_CurBtn->SetRenderTranslation(FVector2D(0, 0));
            slot->SetPosition(FVector2D(196, 112));
        }
        else if (m_CurBtn->GetName() == "PT2")
        {
            m_CurBtn->SetRenderTranslation(FVector2D(0, 0));
            slot->SetPosition(FVector2D(1251, 112));
        }
        else if (m_CurBtn->GetName() == "PT3")
        {
            m_CurBtn->SetRenderTranslation(FVector2D(0, 0));
            slot->SetPosition(FVector2D(1251, 524));
        }
       
        UE_LOG(LogTemp, Warning, TEXT("SetClickSlotBtn"));

        m_CurBtn = nullptr;
    }
}
