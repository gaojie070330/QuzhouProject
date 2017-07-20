// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	m_bShowIma = false;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
}


void AMyPlayerController::ShowXianHuaWin()
{
    if (wXianHuaWin) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wXianHuaWin);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowArea1_1()
{
    if (wArea1_1) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wArea1_1);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowArea1_2()
{
    if (wArea1_2) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wArea1_2);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowArea1_3()
{
    if (wArea1_3) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wArea1_3);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowArea2_1()
{
    if (wArea2_1) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wArea2_1);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowArea2_2()
{
    if (wArea2_2) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wArea2_2);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowAreaPingtu()
{
    if (wAreaPingTu) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wAreaPingTu);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowAreaSelectImag()
{
    if (wAreaSelectImag) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wAreaSelectImag);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowLiuYan()
{
    if (wAreaLiuyan) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wAreaLiuyan);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowWenda()
{
    if (wAreaWenda) // Check if the Asset is assigned in the blueprint.
    {
        // Create the widget and store it.
        MyMainMenu = CreateWidget<UUserWidget>(this, wAreaWenda);

        // now you can use the widget directly since you have a referance for it.
        // Extra check to  make sure the pointer holds the widget.
        if (MyMainMenu)
        {
            //let add it to the view port
            MyMainMenu->AddToViewport();
        }

        //Show the Cursor.
        bShowMouseCursor = true;
    }
}

void AMyPlayerController::ShowSelIma2()
{
	if (wAreaSelIma2) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyMainMenu = CreateWidget<UUserWidget>(this, wAreaSelIma2);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyMainMenu)
		{
			//let add it to the view port
			MyMainMenu->AddToViewport();
		}

		//Show the Cursor.
		bShowMouseCursor = true;
	}
}