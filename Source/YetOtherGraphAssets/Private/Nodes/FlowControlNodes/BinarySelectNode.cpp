// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/FlowControlNodes/BinarySelectNode.h"
#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "BinarySelectNode"

UBinarySelectNode::UBinarySelectNode()
{
    DefaultNodeTitle = LOCTEXT("BinarySelectNode", "Binary Select");
}



UYANode * UBinarySelectNode::ExecuteNodeGetNode_Implementation()
{
    if (ChildNodes.Num() == 1) return BooleanEvaluation() ? ChildNodes[0]->ExecuteNodeGetNode() : nullptr;
    if (ChildNodes.Num() == 2) return BooleanEvaluation() ? ChildNodes[0]->ExecuteNodeGetNode() : ChildNodes[1]->ExecuteNodeGetNode();
    ELog("There are %d subnode on a binary select node.", ChildNodes.Num());
    return nullptr;
}


#undef LOCTEXT_NAMESPACE