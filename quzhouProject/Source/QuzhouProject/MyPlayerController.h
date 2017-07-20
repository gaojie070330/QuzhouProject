// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class QUZHOUPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
    public:
        AMyPlayerController();
        // Reference UMG Asset in the Editor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
    TSubclassOf<class UUserWidget> wMainMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
    TSubclassOf<class UUserWidget> wXianHuaWin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wArea1_1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wArea1_2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wArea1_3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wArea2_1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wArea2_2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wAreaPingTu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wAreaSelectImag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wAreaLiuyan;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
        TSubclassOf<class UUserWidget> wAreaWenda;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wAreaSelIma2;

    // Variable to hold the widget After Creating it.
    UUserWidget* MyMainMenu;

    void ShowXianHuaWin();

    void ShowArea1_1();
    void ShowArea1_2();
    void ShowArea1_3();

    void ShowArea2_1();
    void ShowArea2_2();

    void ShowAreaPingtu();
    void ShowAreaSelectImag();

    void ShowLiuYan();
    void ShowWenda();

	void ShowSelIma2();

	void SetNotShowIma() { m_bShowIma = false; }

	bool m_bShowIma;

protected:
    virtual void BeginPlay() override;

	
	
};
