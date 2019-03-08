///-------------------------------------------------------------------------------------------------
// file:	CombinedSPC.cpp
//
// summary:	Implements the class for a combined shifted paired coordinate graph.
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "CombinedSPC.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <author> Phillipe Shin 2/21/2019</author>
/// <editor> Paul Collet </editor>
///
/// <param name="given"> 	[in,out] The given. </param>
/// <param name="worldW">	The world w. </param>
/// <param name="worldH">	The world h. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CombinedSPC::CombinedSPC(ClassData &given, double worldW, double worldH)
{
	this->data = given;

	data.worldWidth = worldW;
	data.worldHeight = worldH;

	data.xmax = 0;
	data.ymax = 0;

	newFile.openFile(data);
	newFile.sortGraph(data);

	data.classsize = int(data.xdata[0].size());

	data.graphwidth = worldW / (data.classsize * 2.5);						// Width size for each graph
	data.graphheight = worldH / 2.0;										// Height size for each graph


	fillGraphLocations(); // Creates starting graph positions, and fills example data for now.

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	display();
}



////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates starting x and y graph coordinates and example data sets for now. </summary>
///
/// <author> Phillipe Shin 2/21/2019</author>
/// <editor> Paul Collet </editor>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CombinedSPC::fillGraphLocations()
{
	for (int k = 1; k <= data.xdata.size(); k++)
	{
		for (int i = 1; i <= data.classsize; i++)
		{
			data.xgraphcoordinates.push_back(data.graphwidth * i + i * 5);
			data.ygraphcoordinates.push_back(data.graphheight);
		}
		data.xclasses.push_back(data.xgraphcoordinates);
		data.yclasses.push_back(data.ygraphcoordinates);
	}
}

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

void CombinedSPC::drawData(float x1, float y1, float x2, float y2, int i, int j)
{
	float xratio = data.graphwidth / data.xmax; // Normalize data to the graph size
	float yratio = data.graphheight / data.ymax;

	x1 -= (data.graphwidth / 2);
	x2 -= (data.graphwidth / 2);
	y1 += (data.graphheight / 2);
	y2 += (data.graphheight / 2);

	glPushMatrix();															// Makes a new layer
	glTranslatef(x1 + data.pan_x, y1 + data.pan_y, 0);                      // Translates starting position to draw
	glBegin(GL_LINE_STRIP);

	//glColor3ub(0, (index * 50), 100);
	//glColor3ub(0, (data.classNum[i] * 50) + 1, 100);

	int classnum = data.classNum[i] - 1;
	glColor3ub(data.classColor[classnum][0], data.classColor[classnum][1], data.classColor[classnum][2]);

	glVertex2f(0 + xratio * data.xdata[i][j], 0 - yratio * data.ydata[i][j]);                                     // starting vertex
	glVertex2f((x2 - x1) + xratio * data.xdata[i][j + 1], (y2 - y1) - yratio * data.ydata[i][j + 1]);                         // ending vertex
	glEnd();

	
	glColor3ub(0, 0, 0);    
	if (j == 0) {
		glPointSize(4);
	}
	else {
		glPointSize(2);
	}
	glBegin(GL_POINTS);
	glVertex2f(0 + xratio * data.xdata[i][j], 0 - yratio * data.ydata[i][j]);                                     // starting vertex
	glEnd();

	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2f((x2 - x1) + xratio * data.xdata[i][j + 1], (y2 - y1) - yratio * data.ydata[i][j + 1]);                         // ending vertex
	glEnd();
	
	glPopMatrix();
}

/* DISPLAY */

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays this object. </summary>
///
/// <author> Phillipe Shin 2/21/2019</author>
/// <editor> Paul Collet </editor>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CombinedSPC::display() {

	glClearColor(194 / 255.0f, 206 / 255.0f, 218 / 255.0f, 0.0f);			//194, 206, 218. VisCanvas background color.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/* Adjust the windows aspect ratio? */
	glOrtho(data.leftWidth, data.worldWidth, data.worldHeight, data.bottomHeight, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();														// Reset the model-view matrix

	/* Draws a graph for each dimension */
	for (int i = 0; i < data.classsize; i++)
	{
		data.drawGraph(data.xgraphcoordinates[i], data.ygraphcoordinates[i]);
	}

	glLoadIdentity();														// Reset the model-view matrix
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);

	/* Plots the data. Outer loop for each dimension. Inner loop for data across each graph.  */
	for (int i = 0; i < data.xdata.size(); i++) {

		for (int j = 0; j < data.classsize - 1; j++)
		{
			drawData(	data.xgraphcoordinates[j],		data.ygraphcoordinates[j],
						data.xgraphcoordinates[j + 1],	data.ygraphcoordinates[j + 1], i, j);
		}
	}

}

// *** STUFF BELOW THIS IS FOR DRAGGING GRAPHS *** //////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	This method takes the passed mouse click coordinates and finds the dimension/graph clicked on. 
/// 			</summary>
///
/// <author> Phillipe Shin and Allyn Vo</author>
///
/// <param name="x">	The x coordinate. </param>
/// <param name="y">	The y coordinate. </param>
///
/// <returns>	The found clicked graph. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int CombinedSPC::findClickedGraph(double x, double y) 
{
	for (int i = 0; i < data.classsize; i++) 
	{
		if (data.xgraphcoordinates[i] + data.pan_x - (data.graphwidth / 2) <= x && 
			data.xgraphcoordinates[i] + data.pan_x + (data.graphwidth / 2) >= x &&
			data.ygraphcoordinates[i] + data.pan_y - (data.graphheight / 2) <= y &&
			data.ygraphcoordinates[i] + data.pan_y + (data.graphheight / 2) >= y)
		{
			return i;
		}

	} return -1;
}