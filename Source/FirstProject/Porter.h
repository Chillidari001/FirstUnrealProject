// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstProjectCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "InteractionInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Porter.generated.h"

UCLASS()
class FIRSTPROJECT_API APorter : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APorter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void InteractWithMe();

	UPROPERTY(EditAnywhere, Category = "Porter");
	APorter* OtherPorter;

	UFUNCTION()
	void Teleport(class AActor* OtherActor);

	virtual void ShowInteractionUI() override;
	virtual void HideInteractionUI() override;

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* PRootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PorterMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* InteractionUI;
};
