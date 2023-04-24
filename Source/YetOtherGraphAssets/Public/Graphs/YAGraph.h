// Copyright (c) 2018 Jhonny Hueller
#pragma once

#include "CoreMinimal.h"
#include "Nodes/YANode.h"
#include "Nodes/EmptyNodes/StartNode.h"
#include "YAGraph.generated.h"

#define LOCTEXT_NAMESPACE "UYAGraph"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class YETOTHERGRAPHASSETS_API UYAGraph : public UObject
{
	GENERATED_BODY()
	
public:
	UYAGraph();

	//fundamental graph functionality ---------------------------------------
	
	UPROPERTY(BlueprintReadOnly, Category = "Graph Data")
		TArray<UYANode*>Nodes;

	UPROPERTY(BlueprintReadOnly, Category = "Graph Data")
		TMap<FString, UYANode*>NamedNodes;

    UPROPERTY(BlueprintReadOnly, Category = "Graph Data")
        TMap<UYANode*, FString>NodesNames;

	UFUNCTION(BlueprintPure, Category = "Graph Data")
		TArray<UStartNode*> GetStartingNodes();
	
	UPROPERTY()
	class UEdGraph* EdGraph;

	template <class T>
	T* SpawnNodeInsideGraph(TSubclassOf<UYANode> InNodeClass)
	{
		T* SpawenNode = NewObject<T>(this, InNodeClass, NAME_None, RF_Transactional);
		AddNode(SpawenNode);
		return SpawenNode;
	}


	virtual void AddNode(UYANode* InNode);
	virtual void RemoveNode(UYANode* NodeToRemove);

	//basic graph operations ---------------------------------------

	bool SetBooleanVariable(FName BooleanName, bool Value);
	bool GetBooleanVariable(FName BooleanName) const;
	bool SetIntegerVariable(FName IntegerName, int32 Value);
	int32 GetIntegerVariable(FName IntegerName, bool& Result) const;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Graph Support")
	TMap<FName, bool>NamedBooleans;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Graph Support")
	TMap<FName, int32>NamedIntegers;

};

#undef LOCTEXT_NAMESPACE