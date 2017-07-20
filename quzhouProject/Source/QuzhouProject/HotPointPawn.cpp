// Fill out your copyright notice in the Description page of Project Settings.

#include "QuzhouProject.h"
#include "HotPointPawn.h"


// Sets default values
AHotPointPawn::AHotPointPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHotPointPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHotPointPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHotPointPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("PressE", IE_Pressed, this, &AHotPointPawn::OnPressE);
}

void AHotPointPawn::OnPressE()
{
    UE_LOG(LogTemp, Error, TEXT("Your message"));
}

