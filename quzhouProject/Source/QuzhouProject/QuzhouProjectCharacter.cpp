// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "QuzhouProject.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "QuzhouProjectCharacter.h"
#include "HotPointActor.h"
#include "QZGameInstance.h"

//////////////////////////////////////////////////////////////////////////
// AQuzhouProjectCharacter

AQuzhouProjectCharacter::AQuzhouProjectCharacter()
: m_pHotPointActor(nullptr)
, m_CamThirdPersonPos(FVector(150 , 0 , 80))
, m_CamFirstPersonPos(FVector(320, 0, 70))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(30.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AQuzhouProjectCharacter::BeginPlay()
{
    Super::BeginPlay();

    //SetActorLocation(FVector(750,1791,98));

    TArray<USceneComponent*> arrSceneComp;
    RootComponent->GetChildrenComponents(false, arrSceneComp);

    for (int i = 0; i < arrSceneComp.Num(); i++)
    {
        USceneComponent* curCom = arrSceneComp[i];

        if (curCom->GetName() == "Box")
        {
            UBoxComponent* boxCollider = Cast<UBoxComponent>(arrSceneComp[i]);
            {
                boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AQuzhouProjectCharacter::OnOverlapBegin);
                boxCollider->OnComponentEndOverlap.AddDynamic(this, &AQuzhouProjectCharacter::OnOverlapEnd);
            }
        }
		else if (curCom->GetName() == "nvsheng_dongzuo")
		{
			m_GirlMesh = Cast<USkeletalMeshComponent>(curCom);
		}
    }

    bool bShowGirl = true;
    UQZGameInstance* gameInstance = Cast<UQZGameInstance>(GetGameInstance());
    if (gameInstance)
    {
        bShowGirl = gameInstance->GetShowPlayerType();
    }
    if (true)
    {
        ShowGril();
    }
    else
    {
        ShowMan();
    }
}

//////////////////////////////////////////////////////////////////////////
// Input

void AQuzhouProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AQuzhouProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AQuzhouProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AQuzhouProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AQuzhouProjectCharacter::LookUpAtRate);
    PlayerInputComponent->BindAction("PressE", IE_Pressed, this, &AQuzhouProjectCharacter::OnPressE);

    PlayerInputComponent->BindAction("ClickLeftMouse", IE_Pressed, this, &AQuzhouProjectCharacter::OnPressMouseLeft);

	// handle touch devices
	//PlayerInputComponent->BindTouch(IE_Pressed, this, &AQuzhouProjectCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &AQuzhouProjectCharacter::TouchStopped);

	// VR headset functionality
	//PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AQuzhouProjectCharacter::OnResetVR);
}


void AQuzhouProjectCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AQuzhouProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AQuzhouProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AQuzhouProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AQuzhouProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AQuzhouProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AQuzhouProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


void AQuzhouProjectCharacter::OnPressE()
{
    /* UE_LOG(LogTemp, Error, TEXT("Your message"));
     if (m_pHotPointActor)
     {
         m_pHotPointActor->ShowObj(true);
     }*/
}

void AQuzhouProjectCharacter::OnPressMouseLeft()
{
    UE_LOG(LogTemp, Error, TEXT("OnPressMouseLeft"));

    FVector startPos = FVector::ZeroVector;
    FVector startDir = FVector::ZeroVector;
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (OurPlayerController)
    {
        OurPlayerController->DeprojectMousePositionToWorld(startPos , startDir);
    }

	/*FHitResult RV_Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(RV_Hit , startPos , startPos + startDir*100 , ECC_GameTraceChannel1);
	GetWord()->DrawLine();*/

	FCollisionObjectQueryParams traceParams;
	traceParams.AddObjectTypesToQuery(ECC_GameTraceChannel2);
	FHitResult hitInfo(ForceInit);
	if (GetWorld()->LineTraceSingleByObjectType(hitInfo, startPos, startPos + startDir * 1000, traceParams))
	{
		if (hitInfo.Actor != nullptr)
		{
			AHotPointActor* hotActor = Cast<AHotPointActor>(hitInfo.GetActor());
			if (hotActor)
			{
				hotActor->ShowObj(true);

			}
		}
	}

}

void AQuzhouProjectCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OverlappedComp && OtherActor != this)
    {
        m_pHotPointActor = Cast<AHotPointActor>(OtherActor);
    }
}

void AQuzhouProjectCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OverlappedComp && OtherActor != this)
    {
        m_pHotPointActor = nullptr;
    }
}

bool AQuzhouProjectCharacter::ChangePerson()
{
	bool bThirdPerson = true;

	UQZGameInstance* gameInstance = Cast<UQZGameInstance>(GetGameInstance());
	if (gameInstance)
	{
		bThirdPerson = !gameInstance->GetThirdPerson();
		gameInstance->SetThirdPerson(bThirdPerson);
	}

	GetMesh()->SetOwnerNoSee(bThirdPerson);
	if (m_GirlMesh)
	{
		m_GirlMesh->SetOwnerNoSee(bThirdPerson);
	}

	//if (bThirdPerson)
	//{
	//	FollowCamera->SetWorldLocation(m_CamThirdPersonPos);
	//}
	//else
	//{
	//	FollowCamera->SetWorldLocation(m_CamFirstPersonPos);
	//}


	return bThirdPerson;
}

void AQuzhouProjectCharacter::ShowGril()
{
    UQZGameInstance* gameInstance = Cast<UQZGameInstance>(GetGameInstance());
    if (gameInstance)
    {
        gameInstance->SetShowPlayerType(true);
    }

    GetMesh()->SetVisibility(false);
    if (m_GirlMesh)
    {
        m_GirlMesh->SetVisibility(true);
    }
}

void AQuzhouProjectCharacter::ShowMan()
{
    UQZGameInstance* gameInstance = Cast<UQZGameInstance>(GetGameInstance());
    if (gameInstance)
    {
        gameInstance->SetShowPlayerType(false);
    }

    GetMesh()->SetVisibility(true);
    if (m_GirlMesh)
    {
        m_GirlMesh->SetVisibility(false);
    }
}

