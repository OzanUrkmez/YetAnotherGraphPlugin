// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/FlowControlNodes/Implementations/BooleanSelector.h"

#include "Utility/GraphSupportComponentInterface.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "BooleanSelector"

UBooleanSelector::UBooleanSelector()
{
    DefaultNodeTitle = LOCTEXT("BooleanSelector", "Boolean Selector");
}

bool UBooleanSelector::BooleanEvaluation_Implementation(UObject* GraphOwner)
{
    bool Result = false;
    UObject* Support = nullptr;

    if (GraphOwner->GetClass()->ImplementsInterface(UGraphSupportComponentInterface::StaticClass()))
    {
        IGraphSupportComponentInterface* Interface = Cast<IGraphSupportComponentInterface>(GraphOwner);
        Support = Interface->Execute_GetGraphSupportComponent(GraphOwner);
    }
    else
        if (GraphOwner->GetClass()->ImplementsInterface(UYetAnotherGraphInterface::StaticClass()))
            Support = GraphOwner;

    if (Support != nullptr)
    {
        IYetAnotherGraphInterface* Interface = Cast<IYetAnotherGraphInterface>(Support);
        if (Interface)
            Result = Interface->Execute_GetBooleanVariable(Support, Name);
    }
    else
        ELog("No graph interfaces has been found.");

    
    return Result;
}

#undef LOCTEXT_NAMESPACE
