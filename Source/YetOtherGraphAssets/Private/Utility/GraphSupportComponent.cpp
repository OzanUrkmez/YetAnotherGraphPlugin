// Copyright (c) 2018 Jhonny Hueller


#include "Utility/GraphSupportComponent.h"
// Sets default values for this component's properties
UGraphSupportComponent::UGraphSupportComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
    Owner = Cast<AActor>(GetOuter());
    
	// ...
}



// Called when the game starts
void UGraphSupportComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGraphSupportComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGraphSupportComponent::SetBooleanVariable_Implementation(FName BooleanName, bool Value)
{
    NamedBooleans.Add(BooleanName, Value);
    return false;
}

bool UGraphSupportComponent::GetBooleanVariable_Implementation(FName BooleanName) const
{
    return NamedBooleans.Find(BooleanName) ? *NamedBooleans.Find(BooleanName) : false;
}

bool UGraphSupportComponent::SetIntegerVariable_Implementation(FName IntegerName, int32 Value)
{
    NamedIntegers.Add(IntegerName, Value);
    return false;
}

int32 UGraphSupportComponent::GetIntegerVariable_Implementation(FName IntegerName, bool& Result) const
{
    Result = NamedIntegers.Contains(IntegerName);
    return NamedIntegers.Contains(IntegerName)?*NamedIntegers.Find(IntegerName):0;
}