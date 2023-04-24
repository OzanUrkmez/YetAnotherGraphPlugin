// Copyright (c) 2018 Jhonny Hueller



#include "Nodes/ActionNodes/Implementations/StoreInteger.h"

#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "StoreInteger"

UStoreInteger::UStoreInteger()
{
    DefaultNodeTitle= LOCTEXT("StoreInteger", "Store Integer");
}

void UStoreInteger::ActionToPerform_Implementation()
{
    if (Name.IsValid())
    {
        Graph->SetIntegerVariable(Name, Value);
    }
    else
    {
        ELog("The variable name %s isn't valid. in Node %s child of %s", *Name.ToString(), *GetNodeTitle().ToString(), *Graph->GetFullName());
    }
}

#undef LOCTEXT_NAMESPACE