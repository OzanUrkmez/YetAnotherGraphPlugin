// Copyright (c) 2018 Jhonny Hueller

#pragma once

#include "CoreMinimal.h"
#include "Nodes/YANode.h"
#include "Nodes/EmptyNodes/SimpleNode.h"
#include "ActionNode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class YETOTHERGRAPHASSETS_API UActionNode : public USimpleNode
{
    GENERATED_BODY()

public:
    UActionNode();

    UFUNCTION(BlueprintNativeEvent, Category = "Action Node")
    void ActionToPerform();
    virtual void ActionToPerform_Implementation() {}

    //Inherited from UYANode
    UYANode* ExecuteNodeGetNode_Implementation() override;
};
