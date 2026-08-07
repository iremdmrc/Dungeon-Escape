// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...	
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if(MoverActor) //(MoverActor != nullptr
	{
		Mover = MoverActor->FindComponentByClass<UMover>();

		if (Mover) //Mover != nullptr
		{
			UE_LOG(LogTemp, Display, TEXT("Successfully found the Mover component."));
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("Failed to find Mover component."));
		}
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("MoverActor is nullptr."));
	}

	if(IsPressurePlate) {
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, 
	ELevelTick TickType, 
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
		if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
		{
			ActivatorCount++; //increase it 1

			if (!IsTriggered)
			{
				Trigger(true);
			}
		}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex)
{

		if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
		{
			ActivatorCount--; //decrease it 1

			if (IsTriggered && (ActivatorCount == 0))
			{
				Trigger(false);
			}
		}
 }

//refactor the code with NewTriggerValue parameter to avoid code duplication
void UTriggerComponent::Trigger(bool NewTriggerValue)
{
	IsTriggered = NewTriggerValue;

	if (Mover) {
		Mover->SetShouldMove(IsTriggered);
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("%s does not have a mover to trigger"), *GetOwner()->GetActorNameOrLabel());
	}
}



