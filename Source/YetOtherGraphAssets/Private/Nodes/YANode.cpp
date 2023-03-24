// Copyright (c) 2018 Jhonny Hueller

#include "Nodes/YANode.h"

#include "Graphs/YAGraph.h"

#define LOCTEXT_NAMESPACE "YANode" 

UYANode::UYANode()
{
	DefaultNodeTitle = LOCTEXT("Node Title", "Node");
}

UYANode * UYANode::GetNodePointer_Implementation()
{
	return this;
}

void UYANode::SetGraph(UYAGraph * InGraph)
{
	Graph = InGraph;
}

UYAGraph * UYANode::GetGraph()
{
	return Graph;
}

FText UYANode::GetNodeTitle_Implementation()
{
	return DefaultNodeTitle.IsEmpty() ? LOCTEXT("Node Title", "Node") : DefaultNodeTitle;
}

TArray<UYANode*> UYANode::GetChildren()
{
	TArray<UYANode*>ReturnArray;
	for (UYANode* Node : ChildNodes)
	{
        auto* object = Node->GetNodePointer();
		if(object)ReturnArray.Add(object);
	}
	return ReturnArray;
}

TArray<UYANode*> UYANode::GetParents()
{
	return ParentNodes;
}

bool UYANode::HasInputPins_Implementation()
{
	return bHasInputPins;
}

bool UYANode::HasOutputPins_Implementation()
{
	return bHasOutputPins;
}

void UYANode::AddToChildren(UYANode * NewSubNode)
{
	ChildNodes.Add(NewSubNode);
}

void UYANode::AddToParent(UYANode * NewParentNode)
{
	ParentNodes.Add(NewParentNode);
}

bool UYANode::HasParentNodes()
{
	return ParentNodes.Num() > 0;
}

void UYANode::LinkArgumentNodeAsChild(UYANode * Child)
{
	AddToChildren(Child);
	Child->AddToParent(this);
}

void UYANode::ClearLinks()
{
	ParentNodes.Empty();
	ChildNodes.Empty();
}

bool UYANode::RemoveLinkedNode(UYANode * NodeToRemove)
{
	return RemoveNodeFromParents(NodeToRemove) || RemoveNodeFromChilds(NodeToRemove);
}

bool UYANode::RemoveNodeFromParents(UYANode * NodeToRemove)
{
	return ParentNodes.Remove(NodeToRemove) > 0;
}

bool UYANode::RemoveNodeFromChilds(UYANode * NodeToRemove)
{
	return ChildNodes.Remove(NodeToRemove) > 0;
}

#if WITH_ENGINE

UWorld * UYANode::GetWorld() const
{
    return (Graph) ? Graph->GetWorld() : nullptr;
}

#endif

#undef LOCTEXT_NAMESPACE