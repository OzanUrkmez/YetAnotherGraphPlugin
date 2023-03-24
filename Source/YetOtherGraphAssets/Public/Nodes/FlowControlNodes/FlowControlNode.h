// Copyright (c) 2018 Jhonny Hueller
#pragma once

#include "CoreMinimal.h"
#include "Nodes/YANode.h"
#include "FlowControlNode.generated.h"

/**
 * Base abstract class for every node that return a different node when called depending on runtime evalutation.
 * Its subnodes are saved in order from left to right.
 */
UCLASS(Abstract)
class YETOTHERGRAPHASSETS_API UFlowControlNode : public UYANode
{
	GENERATED_BODY()

};
