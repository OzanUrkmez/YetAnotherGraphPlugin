// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/FlowControlNodes/BinarySelectNode.h"
#include "Graphs/YAGraph.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "BinarySelectNode"

UBinarySelectNode::UBinarySelectNode()
{
    DefaultNodeTitle = LOCTEXT("BinarySelectNode", "Binary Select");
}



UYANode * UBinarySelectNode::GetNodePointer_Implementation()
{
    if (ChildNodes.Num() == 1) return BooleanEvaluation(Graph->Owner) ? ChildNodes[0]->GetNodePointer() : nullptr;
    if (ChildNodes.Num() == 2) return BooleanEvaluation(Graph->Owner) ? ChildNodes[0]->GetNodePointer() : ChildNodes[1]->GetNodePointer();
    ELog("There are %d subnode on a binary select node.", ChildNodes.Num());
    return nullptr;
}


#undef LOCTEXT_NAMESPACE