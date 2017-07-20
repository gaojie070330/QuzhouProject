// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "SelectImaWidget.h"



bool USelectImaWidget::Initialize()
{

    if (!Super::Initialize())
    {
        return false;
    }

    m_CurIndex = 0;

    UImage* image = Cast<UImage>(GetWidgetFromName("Image1"));
    /*  if(m_Image1)
      m_Image1->SetVisibility(ESlateVisibility::Hidden);*/
    m_arrImage.Add(image);

    image = Cast<UImage>(GetWidgetFromName("Image2"));
    m_arrImage.Add(image);

    image = Cast<UImage>(GetWidgetFromName("Image3"));
    m_arrImage.Add(image);

    image = Cast<UImage>(GetWidgetFromName("Image4"));
    m_arrImage.Add(image);

    image = Cast<UImage>(GetWidgetFromName("Image5"));
    m_arrImage.Add(image);

    m_LeftBtn = Cast<UButton>(GetWidgetFromName("ButtonLeft"));
    m_RightBtn = Cast<UButton>(GetWidgetFromName("ButtonRight"));

    ShowImageByIndex();

    return true;
}

void USelectImaWidget::OnClickLeftBtn()
{
    m_CurIndex--;
    UE_LOG(LogTemp, Warning, TEXT("m_CurIndex %d"), m_CurIndex);
    ShowImageByIndex();
}

void USelectImaWidget::OnClickRightBtn()
{
    m_CurIndex++;
    UE_LOG(LogTemp, Warning, TEXT("m_CurIndex %d") , m_CurIndex);

    ShowImageByIndex();
}

void USelectImaWidget::ShowImageByIndex()
{
    m_LeftBtn->SetVisibility(ESlateVisibility::Visible);
    m_RightBtn->SetVisibility(ESlateVisibility::Visible);

    if (m_CurIndex == 0)
    {
        m_LeftBtn->SetVisibility(ESlateVisibility::Hidden);
    }
    else if (m_CurIndex == 4)
    {
        m_RightBtn->SetVisibility(ESlateVisibility::Hidden);
    }

    for (int i = 0 ; i < m_arrImage.Num(); i++)
    {
        if (i == m_CurIndex)
        {
            m_arrImage[i]->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            m_arrImage[i]->SetVisibility(ESlateVisibility::Hidden);
        }
    }

}