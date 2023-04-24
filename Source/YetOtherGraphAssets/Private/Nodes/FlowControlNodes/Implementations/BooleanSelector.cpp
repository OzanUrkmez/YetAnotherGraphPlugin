// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/FlowControlNodes/Implementations/BooleanSelector.h"

#include "Graphs/YAGraph.h"

#define LOCTEXT_NAMESPACE "BooleanSelector"

UBooleanSelector::UBooleanSelector()
{
    DefaultNodeTitle = LOCTEXT("BooleanSelector", "Boolean Selector");
}

bool UBooleanSelector::BooleanEvaluation_Implementation()
{
    return Graph->GetBooleanVariable(Name);
}

#undef LOCTEXT_NAMESPACE
