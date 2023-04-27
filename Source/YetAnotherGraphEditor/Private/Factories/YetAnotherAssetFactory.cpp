// Copyright (c) 2018 Jhonny Hueller
#include "YetAnotherAssetFactory.h"

#include "ClassViewerFilter.h"
#include "ClassViewerModule.h"

#include "Graphs/YAGraph.h"
#include "Kismet2/SClassPickerDialog.h"

class FClassFilter : public IClassViewerFilter
{
public:

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs ) override
	{
		return InClass->IsChildOf(UYAGraph::StaticClass());
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		return false;
	}
};

UYetAnotherAssetFactory::UYetAnotherAssetFactory()
{
	SupportedClass = UYAGraph::StaticClass();
	ParentClass = UYAGraph::StaticClass();

	FString FormatString = TEXT("uasset");
	Formats.Add(*FormatString);

	bCreateNew = true;
	bEditorImport = true;
	bText = true;
	bEditAfterNew = true;
}

bool UYetAnotherAssetFactory::ConfigureProperties()
{
	// Load the class viewer module to display a class picker
	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");

	// Fill in options
	FClassViewerInitializationOptions Options;
	Options.bShowObjectRootClass = true;
	Options.bShowNoneOption = false;
	Options.bIsBlueprintBaseOnly = false;
	Options.bIsPlaceableOnly = false;
	
	TSharedPtr<FClassFilter> Filter = MakeShareable(new FClassFilter);
	Options.ClassFilters.Add(Filter.ToSharedRef());
	
	const FText TitleText = NSLOCTEXT("EditorFactories", "CreateUYAGraphOptions", "Pick Parent Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UYAGraph::StaticClass());

	if (bPressedOk)
	{
		ParentClass = ChosenClass;
	}

	return bPressedOk;
}

UObject* UYetAnotherAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	return NewObject<UYAGraph>(InParent, ParentClass, InName, Flags);
}