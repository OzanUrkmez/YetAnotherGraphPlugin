// Copyright (c) 2018 Jhonny Hueller


#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "YetAnotherEdGraphSchema.generated.h"

/**
 * 
 */
UCLASS()
class UYetAnotherEdGraphSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()
	
public:

	/**
	* Get all actions that can be performed when right clicking on a graph or drag-releasing on a graph from a pin
	*
	* @param [in,out]	ContextMenuBuilder	The context (graph, dragged pin, etc...) and output menu builder.
	*/
	void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;

	virtual void GetGraphDisplayInformation(const UEdGraph& Graph, FGraphDisplayInfo& DisplayInfo) const override;
	
	virtual void GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;
	
	/**
	* Determine if a connection can be created between two pins.
	*
	* @param	A	The first pin.
	* @param	B	The second pin.
	*
	* @return	An empty string if the connection is legal, otherwise a message describing why the connection would fail.
	*/
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;

	/* returns new FConnectionDrawingPolicy from this schema */
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;

	/**
	* Populate new graph with any default nodes
	*
	* @param	Graph			Graph to add the default nodes to
	* @param	ContextClass	If specified, the graph terminators will use this class to search for context for signatures (i.e. interface functions)
	*/
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;

};