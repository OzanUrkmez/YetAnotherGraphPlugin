// Copyright (c) 2018 Jhonny Hueller
#include "YetAnotherAssetFactory.h"
#include "Graphs/YAGraph.h"

UYetAnotherAssetFactory::UYetAnotherAssetFactory()
{
	SupportedClass = UYAGraph::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UYetAnotherAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UYAGraph>(InParent, InClass, InName, Flags);
}