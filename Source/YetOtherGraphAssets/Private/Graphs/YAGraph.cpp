// Copyright (c) 2018 Jhonny Hueller
#include "Graphs/YAGraph.h"

#include "Nodes/YANode.h"
#include "Nodes/EmptyNodes/StartNode.h"
#include "Utility/Logger.h"

UYAGraph::UYAGraph()
{
    
#if WITH_EDITORONLY_DATA
	EdGraph = nullptr;
#endif

}

TArray<UStartNode*> UYAGraph::GetStartingNodes()
{
	TArray<UStartNode*>NodesArray;
	for (UYANode* Node:Nodes)
	{
		if (UStartNode* StartNode = Cast<UStartNode>(Node))
			NodesArray.Add(StartNode);
	}
	return NodesArray;
}

void UYAGraph::AddNode(UYANode * InNode)
{
	InNode->SetGraph(this);
	InNode->Rename(nullptr, this);
	int32 Index = Nodes.Add(InNode);
	LLog("Spawned node at index %d", Index);
}

void UYAGraph::RemoveNode(UYANode * NodeToRemove)
{
	for (UYANode* Node : Nodes)
	{
		Node->RemoveLinkedNode(NodeToRemove);
	}

	int32 Removed=Nodes.Remove(NodeToRemove);

	if (Removed > 0)
	{
		LLog("Node Removed.");
	}
	else
	{
		ELog("The node is not present inside the graph.");
	}
}

bool UYAGraph::SetBooleanVariable(FName BooleanName, bool Value) {
	NamedBooleans.Add(BooleanName, Value);
	return false;
}

bool UYAGraph::GetBooleanVariable(FName BooleanName) const {
	return NamedBooleans.Find(BooleanName) ? *NamedBooleans.Find(BooleanName) : false;
}

bool UYAGraph::SetIntegerVariable(FName IntegerName, int32 Value) {
	NamedIntegers.Add(IntegerName, Value);
	return false;
}

int32 UYAGraph::GetIntegerVariable(FName IntegerName, bool& Result) const {
	Result = NamedIntegers.Contains(IntegerName);
	return NamedIntegers.Contains(IntegerName)? *NamedIntegers.Find(IntegerName) : 0;
}
