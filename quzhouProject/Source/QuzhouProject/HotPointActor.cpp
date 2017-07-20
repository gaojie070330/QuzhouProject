// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "MyPlayerController.h"
#include "HotPointActor.h"


// Sets default values
AHotPointActor::AHotPointActor()
: m_pTips (nullptr)
, m_ShowObj(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHotPointActor::BeginPlay()
{
	Super::BeginPlay();
	
    TArray<USceneComponent*> arrSceneComp;
    RootComponent->GetChildrenComponents(false , arrSceneComp);

    for (int i = 0; i < arrSceneComp.Num(); i++)
    {
        USceneComponent* curCom = arrSceneComp[i];
        
        if (curCom->GetName() == "Box")
        {
            UBoxComponent* boxCollider = Cast<UBoxComponent>(arrSceneComp[i]);
            {
                boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AHotPointActor::OnOverlapBegin);
                boxCollider->OnComponentEndOverlap.AddDynamic(this, &AHotPointActor::OnOverlapEnd);
            }
        }
        else if (curCom->GetName() == "TipsText")
        {
            m_pTips = curCom;
        }
        else if (curCom->GetName() == "ShowObj")
        {
            m_ShowObj = curCom;
        }
    }
}

// Called every frame
void AHotPointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHotPointActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OverlappedComp && OtherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("AHotPointActor OnOverlapBegin"));
        //m_pTips->SetVisibility(true);
    }
}

void AHotPointActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OverlappedComp && OtherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("AHotPointActor OnOverlapEnd"));

        m_pTips->SetVisibility(false);
    }
}


void AHotPointActor::ShowObj(bool bShow)
{
     ShowMesh(true);
     //m_pTips->SetVisibility(!bShow);
     
     AMyPlayerController* OurPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
     if (OurPlayerController && !OurPlayerController->m_bShowIma)
     {
		 OurPlayerController->m_bShowIma = true;

         switch (Index)
         {
         //ÏÊ»¨
         case 1:
             OurPlayerController->ShowXianHuaWin();
         break;

         //area 1-1
         case 21:
             OurPlayerController->ShowArea1_1();
             break;
        
         case 22:
             OurPlayerController->ShowArea1_2();
             break;

         case 23:
             OurPlayerController->ShowArea1_3();
             break;

             //area 1-1
         case 31:
             OurPlayerController->ShowArea2_1();
             break;

         case 32:
         case 40:
             OurPlayerController->ShowArea2_2();
             break;

         case 33:
             OurPlayerController->ShowAreaPingtu();
             break;

         case 34:
             OurPlayerController->ShowAreaSelectImag();
             break;

        case 50:
        OurPlayerController->ShowLiuYan();
             break;

		case 51:
			OurPlayerController->ShowWenda();
			break;

		case 52:
			OurPlayerController->ShowSelIma2();
			break;
             
         default:
             break;
         }
         
     }
}


void AHotPointActor::ShowMesh(bool bShow)
{
    if (m_ShowObj)
    {
        TArray<USceneComponent*> arrSceneComp;
        m_ShowObj->GetChildrenComponents(true, arrSceneComp);

        for (int i = 0; i < arrSceneComp.Num(); i++)
        {
            USceneComponent* curCom = arrSceneComp[i];
            curCom->SetVisibility(bShow);
        }
    }
}
