// Copyright (c) 2018 Jhonny Hueller
#define LOCTEXT_NAMESPACE "MultiNodeSelector"
#include "Nodes/FlowControlNodes/MultiNodeSelector.h"

#include "Graphs/YAGraph.h"
#include "Nodes/YANode.h"
#include "Utility/Logger.h"

UYANode * UMultiNodeSelector::ExecuteNodeGetNode_Implementation()
{
    int32 Index = IndexEvaluation();
    if ((ChildNodes.Num() == 0) || Index >= ChildNodes.Num())
    {
        ELog("There are %d nodes linked to a '%s' node and the index evaluated is &d.", ChildNodes.Num(), *StaticClass()->GetDisplayNameText().ToString(), Index);
        return nullptr;
    }
    return (ChildNodes.IsValidIndex(Index)) ? ChildNodes[Index]->ExecuteNodeGetNode() : nullptr;
}

#undef LOCTEXT_NAMESPACE