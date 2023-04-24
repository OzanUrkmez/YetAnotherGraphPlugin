// Copyright (c) 2018 Jhonny Hueller
#pragma once

#include "CoreMinimal.h"
#include "FlowControlNode.h"
#include "MultiNodeSelector.generated.h"

#define LOCTEXT_NAMESPACE "MultiNodeSelector"

/**
 * 
 */
UCLASS(Abstract)
class YETOTHERGRAPHASSETS_API UMultiNodeSelector : public UFlowControlNode
{
	GENERATED_BODY()
	
public:

    UFUNCTION(BlueprintNativeEvent, Category = "Multi Node Selector")
    int32 IndexEvaluation();
    virtual int32 IndexEvaluation_Implementation() { return 0; }

	UYANode* ExecuteNodeGetNode_Implementation() override;
	
	
};

#undef LOCTEXT_NAMESPACE