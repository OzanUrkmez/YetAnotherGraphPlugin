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
    void ActionToPerform(UObject* GraphOwner);
    virtual void ActionToPerform_Implementation(UObject* GraphOwner) {}

    //Inherited from UYANode
    UYANode* GetNodePointer_Implementation() override;
};
