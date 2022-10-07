// Fill out your copyright notice in the Description page of Project Settings.


#include "Porter.h"

// Sets default values
APorter::APorter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = PRootComponent;

	PorterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porter Mesh"));
	PorterMesh->SetupAttachment(RootComponent);

	InteractionUI=CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction UI"));
	InteractionUI->SetupAttachment(RootComponent);

	InteractionUI->SetVisibility(false);
}

// Called when the game starts or when spawned
void APorter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APorter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APorter::InteractWithMe()
{
	UE_LOG(LogTemp,Warning, TEXT("Porter interacted with"));
	Teleport(OtherPorter);
}

void APorter::Teleport(class AActor* OtherActor)
{
	if(OtherPorter)
	{
		AFirstProjectCharacter* character = Cast<AFirstProjectCharacter>(OtherActor);
		if(character)
		{
			character->SetActorLocation(OtherPorter->GetActorLocation());
		}
	}
}

void APorter::ShowInteractionUI()
{
	InteractionUI->SetVisibility(true);
}

void APorter::HideInteractionUI()
{
	InteractionUI->SetVisibility(false);
}

/*void APorter::TeleportBack(class AActor* OtherActor)
{
	if(OtherActor &&)
}*/
