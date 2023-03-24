// Copyright (c) 2018 Jhonny Hueller


#pragma once

#include "CoreMinimal.h"
#include "Nodes/YANode.h"
#include "SimpleNode.generated.h"

/**
 * Base node, used for storing information or change the topography of the graph
 */
UCLASS(meta = (Category = "EmptyNodes"))
class YETOTHERGRAPHASSETS_API USimpleNode : public UYANode
{
	GENERATED_BODY()
	
public:
	USimpleNode();
	
	
	
};
