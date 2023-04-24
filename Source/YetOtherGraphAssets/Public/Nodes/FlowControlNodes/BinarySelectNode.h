// Copyright (c) 2018 Jhonny Hueller
#pragma once

#include "CoreMinimal.h"
#include "FlowControlNode.h"
#include "BinarySelectNode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class YETOTHERGRAPHASSETS_API UBinarySelectNode : public UFlowControlNode
{
	GENERATED_BODY()
	
public:
    UBinarySelectNode();

    UFUNCTION(BlueprintNativeEvent, Category = "Binary Selector")
        bool BooleanEvaluation();
    virtual bool BooleanEvaluation_Implementation() { return false; }
	

    //inherited from YANode
    UYANode* ExecuteNodeGetNode_Implementation() override;

protected:
	//TODO: make this and the check in action node enforced, or at least ensure here. 
    UPROPERTY()
        int32 MaxNumberOfSubNodes = 2;
	
};
