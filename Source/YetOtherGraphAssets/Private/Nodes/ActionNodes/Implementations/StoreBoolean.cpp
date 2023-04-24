// Copyright (c) 2018 Jhonny Hueller


#include "Nodes/ActionNodes/Implementations/StoreBoolean.h"

#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "StoreBoolean"

UStoreBoolean::UStoreBoolean()
{
    DefaultNodeTitle= LOCTEXT("StoreBoolean", "Store Boolean");
}
void UStoreBoolean::ActionToPerform_Implementation()
{
    if (Name.IsValid())
    {
        Graph->SetBooleanVariable(Name, true);
    }
    else
    {
        ELog("The variable name %s isn't valid. in Node %s child of %s", *Name.ToString(), *GetNodeTitle().ToString(), *Graph->GetFullName());
    }
}

#undef LOCTEXT_NAMESPACE
