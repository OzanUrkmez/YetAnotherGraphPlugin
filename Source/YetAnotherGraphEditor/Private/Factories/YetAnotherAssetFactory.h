// Copyright (c) 2018 Jhonny Hueller
#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "YetAnotherAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class UYetAnotherAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UYetAnotherAssetFactory();
	
	UPROPERTY(EditAnywhere, Category = YetAnotherAssetFactory, meta = (AllowAbstract = "", BlueprintBaseOnly = ""))
	TSubclassOf<class UYAGraph> ParentClass;
	
	virtual bool ConfigureProperties() override;

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
