// Copyright (c) 2018 Jhonny Hueller

#pragma once

#include "CoreMinimal.h"
#include "Nodes/ActionNodes/ActionNode.h"
#include "StoreBoolean.generated.h"

/**
 * 
 */
UCLASS(meta = (Category = "ActionNodes"))
class YETOTHERGRAPHASSETS_API UStoreBoolean : public UActionNode
{
	GENERATED_BODY()

public:
    UStoreBoolean();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Informations")
        FName Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Informations")
        bool Value;
	
    //Inherited from UActionNode
	virtual void ActionToPerform_Implementation() override;
	
};
