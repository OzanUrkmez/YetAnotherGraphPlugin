// Copyright (c) 2018 Jhonny Hueller
#include "Graphs/YAGraph.h"

#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Nodes/YANode.h"
#include "Nodes/EmptyNodes/StartNode.h"
#include "Utility/Logger.h"

#define LOCTEXT_NAMESPACE "UYAGraph"

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

void UYAGraph::InitGraph(UObject * ParentObject)
{
    Owner = ParentObject;
    //it seems that a Rename after the asset has already been assigned in a variable prevents referencing it properly on runtime
    //Rename(nullptr, ParentObject);
}


#if WITH_ENGINE

UWorld * UYAGraph::GetWorld() const
{
    if (Owner->IsA(UActorComponent::StaticClass()) || Owner->IsA(AActor::StaticClass()))
    {
        return Owner->GetWorld();
    }
    
    ELog("It hasn't been possible to retrieve the world context from %s for %s", *Owner->GetFullName(), *GetFullName());
    return nullptr;
    
}

#endif

#if WITH_EDITORONLY_DATA
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
#endif

#undef LOCTEXT_NAMESPACE
