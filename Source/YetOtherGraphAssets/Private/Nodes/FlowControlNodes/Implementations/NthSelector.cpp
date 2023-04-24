// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/FlowControlNodes/Implementations/NthSelector.h"

#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "NthSelector"

UNthSelector::UNthSelector()
{
    DefaultNodeTitle= LOCTEXT("NthSelector", "'Nth Selector");
}

int32 UNthSelector::IndexEvaluation_Implementation()
{
    int32 Integer = 0;
    bool Result = false;

    Graph->GetIntegerVariable(IndexName, Result);

    if (!Result)
        ELog("%s:Error upon looking for an integer %s", *Graph->GetFullName(), *IndexName.ToString());

   
    return Integer;
}

#undef LOCTEXT_NAMESPACE
