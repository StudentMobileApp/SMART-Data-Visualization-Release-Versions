///-------------------------------------------------------------------------------------------------
// file:	ClassData.h
//
// summary:	Declares the class data class
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
//#include "Color.h"
#include <Windows.h>
#include <GL/glu.h>

#pragma once

//currently setup for EACH INDIVIDUAL CLASS

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The class data. </summary>
///
/// <author>	Paul Collet </author>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ClassData // copy class before changing
{
public: 
	std::vector<std::vector<float> > classColor;

	void setClassColors() {
		for (int i = 0; i < numOfClasses; i++) {
			classColor.push_back({});
			//0, (data.classNum[i] * 50) + 1, 100
			classColor[i].push_back(0);
			classColor[i].push_back((i + 1) * 50 + 1);
			classColor[i].push_back(100);
		}
	}
	void setClassColor(float R, float G, float B, int classnum) {
		if(!classColor[classnum - 1].empty()){
		classColor[classnum-1].clear();
		//for (int i = 0; i < numOfClasses; i++) {
			//0, (data.classNum[i] * 50) + 1, 100
			classColor[classnum - 1].push_back(R);
			classColor[classnum - 1].push_back(G);
			classColor[classnum - 1].push_back(B);
			}
		//}
	}


	/// <summary>	Filename of the file. </summary>
	std::string fileName;

	/// <summary>	The values. </summary>
	std::vector<std::vector<std::string> > values;

	/// <summary>	these are actually in OpenGL.h. </summary>
	double worldWidth;
	/// <summary>	Height of the world. </summary>
	double worldHeight;

	/// <summary>	The class number. </summary>
	std::vector<int> classNum;
	/// <summary>	Number of classes. </summary>
	int numOfClasses = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds class size, it is fixed at 4 for now, but should be changed when reading actual
	/// 	data.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int classsize;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds the x max for all data. Used normalize data to the max for graphing purposes.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double xmax;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds the y max for all data. Used normalize data to the max for graphing purposes.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double ymax;

	/// <summary>	Width size for each graph. </summary>
	double graphwidth;
	/// <summary>	Height size for each graph. </summary>
	double graphheight;

	/// <summary>	Holds different dimensions of x data. </summary>
	std::vector<std::vector<float> > xdata;
	/// <summary>	Holds different dimensions of y data. </summary>
	std::vector<std::vector<float> > ydata;

	//std::vector<ClassData> classes;

	/// <summary>	The initial xclasses. </summary>
	std::vector<std::vector<float> > initialXclasses;
	/// <summary>	The initial yclasses. </summary>
	std::vector<std::vector<float> > initialYclasses;

	/// <summary>	The xclasses. </summary>
	std::vector<std::vector<float> > xclasses;
	/// <summary>	The yclasses. </summary>
	std::vector<std::vector<float> > yclasses;

	// These hold the ORIGINAL x & y coordinates for each graph position.
	// Since we're using ClassData, this might get replaced
	/// <summary>	The originalxgraphcoordinates. </summary>
	std::vector<float> originalxgraphcoordinates;
	/// <summary>	The originalygraphcoordinates. </summary>
	std::vector<float> originalygraphcoordinates;

	/// <summary>	These hold x &amp; y coordinates for each graph position. </summary>
	std::vector<float> xgraphcoordinates;
	/// <summary>	The ygraphcoordinates. </summary>
	std::vector<float> ygraphcoordinates;


	// for zooming and panning ////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The pan x coordinate. </summary>
	double pan_x = 0.0;
	/// <summary>	The pan y coordinate. </summary>
	double pan_y = 0.0;
	/// <summary>	The scale. </summary>
	double scale = 1.2;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	These are starting width and height. The world width and world height is the width after
	/// 	these starting values.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double leftWidth = 0;
	/// <summary>	Height of the bottom. </summary>
	double bottomHeight = 0;
	/// <summary>	starting pan amount because zooming would need a different pan amount. </summary>
	int panamount = 22;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Resets some variables. </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void resetSomeVars() {
		numOfClasses = 0;
		classsize = 0;
		xmax = 0;
		ymax = 0;
		classColor.clear();
	}

	//Color lineColor;
	//double lineThickness;

	//bool shown; // is it visible

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	ClassData() {};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	///
	/// <param name="name">	The name. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	ClassData(std::string name)
	{
		fileName = name;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~ClassData()
	{
		// Delete as necessary.
		values.clear();
		xdata.clear();
		ydata.clear();
		initialXclasses.clear();
		initialYclasses.clear();
		xclasses.clear();
		yclasses.clear();
		originalxgraphcoordinates.clear();
		originalygraphcoordinates.clear();
		xgraphcoordinates.clear();
		ygraphcoordinates.clear();
		classNum.clear();

	}

	/* Input: Position of graph -- Creates a new empty graph */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Draw graph. </summary>
	///
	/// <remarks>	Moved from classes. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void drawGraph(float x, float y) 
	{
		glPushMatrix(); // Makes a new layer
		glTranslatef(x + pan_x, y + pan_y, 0.0f);
		glScalef((graphwidth / 2), (graphheight / 2), 0.0f);
		glBegin(GL_LINE_STRIP);

		glColor3ub(0, 0, 0); // Line color
		glVertex2f(-1, -1);
		glVertex2f(-1, 1);
		glVertex2f(1, 1);
		glEnd();
		glPopMatrix(); // Removes the layer
	}

};







