// Copyright (c) 2018 Jhonny Hueller



#include "Nodes/ActionNodes/ActionNode.h"

#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "ActionNode"

UActionNode::UActionNode()
{
    DefaultNodeTitle= LOCTEXT("ActionNode", "Action Node");
}

UYANode * UActionNode::ExecuteNodeGetNode_Implementation()
{
    if (ChildNodes.Num() <= 1)
    {
        ActionToPerform();
        return (ChildNodes.IsValidIndex(0)) ? ChildNodes[0]->ExecuteNodeGetNode() : nullptr;
    }
    else
    {
        //TODO: is there things in place to ensure this?
        ELog("There should be at most one subnode on an ActionNode"); 
        return nullptr;
    }
}

#undef LOCTEXT_NAMESPACE
