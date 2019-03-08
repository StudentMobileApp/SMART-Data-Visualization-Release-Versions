///-------------------------------------------------------------------------------------------------
// file:	CombinedSPC.h
//
// summary:	Declares the class for a combined shifted paired coordinate graph.
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "ClassData.h"
#include "FileHandling.h"


#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A combined spc. </summary>
///
/// <author> Phillipe Shin 2/21/2019</author>
/// <editor> Paul Collet </editor>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CombinedSPC
{

public:
	/// <summary>	The class data. </summary>
	ClassData data;
	/// <summary>	The new file. </summary>
	FileHandling newFile;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <author> Phillipe Shin 2/21/2019</author>
	/// <editor> Paul Collet </editor>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	CombinedSPC() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <author> Phillipe Shin 2/21/2019</author>
	/// <editor> Paul Collet </editor>
	///
	/// <param name="parameter1">	[in,out] The first parameter. </param>
	/// <param name="parameter2">	The second parameter. </param>
	/// <param name="parameter3">	The third parameter. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	CombinedSPC(ClassData&, double, double);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Creates starting x and y graph coordinates and example data sets for now. </summary>
	///
	/// <author> Phillipe Shin 2/21/2019</author>
	/// <editor> Paul Collet </editor>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void fillGraphLocations();

	/* Draws data sets. */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Draw data. </summary>
	///
	/// <author> Phillipe Shin 2/21/2019</author>
	/// <editor> Paul Collet </editor>
	///
	/// <param name="x1">	The first x value. </param>
	/// <param name="y1">	The first y value. </param>
	/// <param name="x2">	The second x value. </param>
	/// <param name="y2">	The second y value. </param>
	/// <param name="i"> 	Zero-based index of the. </param>
	/// <param name="j"> 	An int to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void drawData(float x1, float y1, float x2, float y2, int i, int j);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Displays this object. </summary>
	///
	/// <author> Phillipe Shin 2/21/2019</author>
	/// <editor> Paul Collet </editor>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void display();

	// *** STUFF BELOW THIS IS FOR DRAGGING GRAPHS *** //////////////////////////////////////////

	/* DRAGGING GRAPH STUFF */
	/// <summary>	If the mouse is clicked, held and dragging. </summary>
	bool dragging = false;
	/// <summary>	Holds what graphs being clicked. </summary>
	int graphClicked = -1;

	/* This method takes the passed mouse click coordinates and finds the graph clicked on. */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	This method takes the passed mouse click coordinates and finds the graph clicked on. 
	/// 			</summary>
	///
	/// <author> Phillipe Shin and Allyn Vo</author>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///
	/// <returns>	The found clicked graph. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int findClickedGraph(double x, double y);





};

