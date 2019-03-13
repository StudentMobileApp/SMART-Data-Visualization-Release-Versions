///-------------------------------------------------------------------------------------------------
// file:	OpenGL3.h
//
// summary:	Declares the OpenGL class
///-------------------------------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "stdafx.h"
#include "ClassData.h"
#include "FileHandling.h"

#include "SeparatedCPC.h"
#include "CombinedCPC.h"

#include "SeparatedSPC.h"
#include "CombinedSPC.h"

#include "StandardTS.h"
#include "SeparatedTS_SPC.h"
#include "TimeSeries_Dist.h"

#include "Cont_Parallel_Coordinates.h"
#include "Dist_Cont_Parallel_Coords.h"



///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

using namespace System::Windows::Forms;


///-------------------------------------------------------------------------------------------------
// namespace: OpenGLForm
//
// summary:	.
///-------------------------------------------------------------------------------------------------

namespace OpenGLForm
{
	/// <summary>	THE MAGIC. </summary>
	ClassData data;
	/// <summary>	The new file. </summary>
	FileHandling newFile;

	/// <summary>	The first graph. </summary>
	SeparatedCPC graph1;
	/// <summary>	The second graph. </summary>
	CombinedCPC graph2;
	/// <summary>	The third graph. </summary>
	SeparatedSPC graph3;
	/// <summary>	The fourth graph. </summary>
	CombinedSPC graph4;

	/// <summary>	The fifth graph. </summary>
	SeparatedTS_SPC graph5;

	/// <summary>	The graph 6. </summary>
	StandardTS graph6;

	/// <summary>	The graph 7. </summary>
	TimeSeries_Dist graph7;

	/// <summary>	The graph 8. </summary>
	Cont_Parallel_Coordinates graph8;

	/// <summary>	The graph 9. </summary>
	Dist_Cont_Parallel_Coords graph9;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	An open gl 3. </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	public ref class COpenGL3 : public System::Windows::Forms::NativeWindow
	{
	public:

		/// <summary>	Height of the world. </summary>
		double worldHeight;
		/// <summary>	Width of the world. </summary>
		double worldWidth;
		/// <summary>	Holds the clicked dimension. </summary>
		int clickedDimension;

		/// <summary>	Holds mouse X coord when mapped to world. </summary>
		double worldMouseX;
		/// <summary>	Holds mouse Y coord when mapped to world. </summary>
		double worldMouseY;

		/// <summary>	Is made true via mouselistener when dragging the mouse. </summary>
		bool drawingDragged;

		/// <summary>	holds which graph to display, -1 for none right now. </summary>
		int graphType = -1;

		

		/// <summary>	The original wh. </summary>
		int originalWH;
		/// <summary>	The original ww. </summary>
		int originalWW;

		int cpPosx;
		int cpPosy;


		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Constructor. </summary>
		///
		/// <remarks>	Modified by Allyn Vo </remarks>
		///
		/// <param name="parentForm">	The parent form. </param>
		/// <param name="iWidth">	 	Zero-based index of the width. </param>
		/// <param name="iHeight">   	Zero-based index of the height. </param>
		/// <param name="igraphType">	Type of the igraph. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		COpenGL3(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, int igraphType)
		{
			graphType = igraphType;

			CreateParams^ cp = gcnew CreateParams;

			worldWidth = iWidth;
			worldHeight = iHeight;
			drawingDragged = false;
			clickedDimension = -1;

			originalWW = iWidth;
			originalWH = iHeight;

			// Set the position on the form
			cp->X = 201;
			cpPosx = 201;
			cp->Y = 33;
			cpPosy = 33;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;
			
			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_BORDER;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				//InitGL();
			}
		}

		void resizeDrawingArea1(int xdifference) {
				this->worldWidth -= xdifference;
				if (xdifference < 0) {
					SetWindowPos((HWND)this->Handle.ToPointer(), NULL, 10, 33, this->worldWidth -10, this->worldHeight, SWP_NOZORDER | SWP_NOACTIVATE);
					cpPosx = 10;
				}
				else {
					SetWindowPos((HWND)this->Handle.ToPointer(), NULL, 201, 33, this->worldWidth , this->worldHeight, SWP_NOZORDER | SWP_NOACTIVATE);
					cpPosx = 201;
				}
		}
		void resizeDrawingArea2(int xdifference) {
			this->worldWidth -= xdifference;
			if (xdifference < 0) {
				SetWindowPos((HWND)this->Handle.ToPointer(), NULL, cpPosx, 33, this->worldWidth, this->worldHeight, SWP_NOZORDER | SWP_NOACTIVATE);
			}
			else {
				SetWindowPos((HWND)this->Handle.ToPointer(), NULL, cpPosx, 33, this->worldWidth, this->worldHeight, SWP_NOZORDER | SWP_NOACTIVATE);
			}
		}
		void resetDrawingArea() {
			SetWindowPos((HWND)this->Handle.ToPointer(), NULL, 201, 33, originalWW, originalWH, SWP_NOZORDER | SWP_NOACTIVATE);
			cpPosx = 201;
		}

		// CHANGE BACKGROUND COLOR
		void setClassColor(float R, float G, float B, int classnumber) {
			if (classnumber > 0 && classnumber <= data.numOfClasses) {
				graph1.data.setClassColor(R, G, B, classnumber);
				graph2.data.setClassColor(R, G, B, classnumber);
				graph3.data.setClassColor(R, G, B, classnumber);
				graph4.data.setClassColor(R, G, B, classnumber);
				graph5.data.setClassColor(R, G, B, classnumber);
				graph6.data.setClassColor(R, G, B, classnumber);
				graph7.data.setClassColor(R, G, B, classnumber);
				graph8.data.setClassColor(R, G, B, classnumber);
				graph9.data.setClassColor(R, G, B, classnumber);
			}

		}

		int getClassSize() {
			return graph1.data.numOfClasses;
		}

		void setGraph5ColumnSize(int newColumnSize) {
			graph5.columns = newColumnSize;

			graph5.data.xgraphcoordinates.clear();
			graph5.data.ygraphcoordinates.clear();

			graph5.data.xclasses.clear();
			graph5.data.yclasses.clear();

			if (graph5.columns < 10) { // After 10, no more resizing of graph width because the graphs will become too small, so after 10, add to the end only
				graph5.data.graphwidth = worldWidth / (graph5.columns + 1);
			}
			graph5.fillGraphLocations();

		}

		void setGraph5ConnectedLineColor(float R, float G, float B) {
			graph5.setLineColor(R, G, B);
		}

		/* RENDERING FOR DIFFERENT GRAPHS *//////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders SCPC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render(System::Void)
		{
			graph1.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders CCPC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render2(System::Void)
		{
			graph2.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders SSPC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render3(System::Void)
		{
			graph3.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders CSPC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render4(System::Void)
		{
			graph4.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders StdTS. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render5(System::Void)
		{
			graph5.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders DistTS. </summary>
		///
		/// <remarks>	Modified by Allyn Vo </remarks>
		///
		/// <param name="parameter1">	The first parameter. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render6(System::Void)
		{
			graph6.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders SepTS-SPC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render7(System::Void)
		{
			graph7.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders ConParC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render8(System::Void)
		{
			graph8.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Renders DistConParC. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void Render9(System::Void)
		{
			graph9.display();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Swap open gl buffers. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Clears all graph data. </summary>
		///
		/// <author>	Allyn Vo </author>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void clearAllGraphData() 
		{
			data.~ClassData();
			graph1.data.~ClassData();
			graph2.data.~ClassData();
			graph3.data.~ClassData();
			graph4.data.~ClassData();
			graph5.data.~ClassData();
			graph6.data.~ClassData();
			graph7.data.~ClassData();

			graph5.xdatatemp.clear();
			graph5.ydatatemp.clear();
			graph5.distanceX.clear();
			graph5.distanceY.clear();
			graph5.convertedValues.clear();

			graph6.convertedValues.clear();

			graph7.convertedValues.clear();

			data.resetSomeVars();
			graph1.data.resetSomeVars();
			graph2.data.resetSomeVars();
			graph3.data.resetSomeVars();
			graph4.data.resetSomeVars();
			graph5.data.resetSomeVars();
			graph6.data.resetSomeVars();
			graph7.data.resetSomeVars();

			graph8.data.~ClassData();
			graph8.data.resetSomeVars();
			graph8.clearFields();

			graph9.data.~ClassData();
			graph9.data.resetSomeVars();
			graph9.clearFields();

		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Sets file name. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <param name="file">	The file. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void setFileName(ClassData file) {
			clearAllGraphData();


			/* Opens the file and process the data */
			//data.fileName = "input.csv";
			data.fileName = file.fileName;
			data.worldWidth = worldWidth;
			data.worldHeight = worldHeight;
			data.xmax = 0;
			data.ymax = 0;
			newFile.openFile(data);
			newFile.sortGraph(data);

			// S-CPC
			graph1.data = data;
			graph1.data.classsize = int(data.xdata[0].size());
			graph1.data.graphwidth = worldWidth * 0.4; // Width size for each graph
			graph1.data.graphheight = worldHeight / (graph1.data.numOfClasses + 1); // Height size for each graph
			graph1.fillGraphLocations(); // Creates starting graph positions, and fills example data for now.
			graph1.data.setClassColors();

			// C-CPC
			graph2.data = data;
			graph2.data.classsize = int(data.xdata[0].size());
			graph2.data.graphwidth = worldWidth / 2; // Width size for each graph
			graph2.data.graphheight = worldHeight / 2; // Height size for each graph
			graph2.fillGraphLocations(); // Creates starting graph positions, and fills example data for now.
			graph2.data.setClassColors();

			// S-SPC
			graph3.data = data;
			graph3.data.classsize = int(data.xdata[0].size());
			graph3.data.graphwidth = worldWidth / (data.xdata[0].size() + 1); // Width size for each graph
			graph3.data.graphheight = worldHeight / (graph3.data.numOfClasses + 1); // Height size for each graph
			graph3.fillGraphLocations(); // Creates starting graph positions, and fills example data for now.
			graph3.data.setClassColors();

			// C-SPC
			graph4.data = data;
			graph4.data.classsize = int(data.xdata[0].size());
			graph4.data.graphwidth = worldWidth / (graph4.data.classsize + 1); // Width size for each graph
			graph4.data.graphheight = worldHeight / (2); // Height size for each graph
			graph4.fillGraphLocations(); // Creates starting graph positions, and fills example data for now.
			graph4.data.setClassColors();

			// Separated TS-SPC
			graph5.data.fileName = file.fileName;
			graph5.data.worldWidth = worldWidth;
			graph5.data.worldHeight = worldHeight;
			graph5.data.xmax = 0;
			graph5.data.ymax = 0;
			newFile.openFile(graph5.data);
			graph5.sortGraph2(graph5.data);
			graph5.normalizeData();
			graph5.graphByPairs();
			graph5.data.classsize = int(graph5.data.xdata[0].size());
			graph5.data.graphwidth = worldWidth /(graph5.columns + 1); // Width size for each graph
			graph5.data.graphheight = worldHeight / (graph5.data.numOfClasses + 1); // Height size for each graph
			graph5.fillGraphLocations();  // Creates starting graph positions, and fills example data for now.
			graph5.data.setClassColors();

			// Standard TS
			graph6.data.fileName = file.fileName;
			graph6.data.worldWidth = worldWidth;
			graph6.data.worldHeight = worldHeight;
			graph6.data.xmax = 0;
			graph6.data.ymax = 0;
			newFile.openFile(graph6.data);
			graph6.sortGraph2();
			graph6.normalizeData();
			graph6.data.classsize = int(data.xdata[0].size());
			graph6.data.graphwidth = worldWidth * 0.35; // Width size for each graph
			graph6.data.graphheight = worldHeight / (data.numOfClasses + 1); // Height size for each graph
			graph6.fillGraphLocations();  // Creates starting graph positions, and fills example data for now.
			graph6.data.setClassColors();

			// Distance TS
			graph7.data.fileName = file.fileName;
			graph7.data.worldWidth = worldWidth;
			graph7.data.worldHeight = worldHeight;
			graph7.data.xmax = 0;
			graph7.data.ymax = 0;
			newFile.openFile(graph7.data);
			graph7.sortGraph2();
			graph7.sortDistances(); //THE DIFFERENCE
			graph7.normalizeData();
			graph7.data.classsize = int(graph7.data.xdata[0].size());
			graph7.data.graphwidth = worldWidth * 0.35; // Width size for each graph
			graph7.data.graphheight = worldHeight / (graph7.data.numOfClasses + 1); // Height size for each graph
			graph7.fillGraphLocations();  // Creates starting graph positions, and fills example data for now.
			graph7.data.setClassColors();

			// Standard Continuous Parallel Coordinates
			graph8.data.fileName = file.fileName;
			graph8.data.worldWidth = worldWidth;
			graph8.data.worldHeight = worldHeight;
			graph8.data.xmax = 0;
			graph8.data.ymax = 0;
			newFile.openFile(graph8.data);
			graph8.sortGraph(graph8.data);
			graph8.normalizeData();
			graph8.data.classsize = int(graph8.data.xdata[0].size());
			graph8.data.graphwidth = worldWidth * 0.8;
			graph8.data.graphheight = worldHeight * 0.5;
			graph8.fillGraphLocations();
			graph8.data.setClassColors();

			// Distance Continuous Parallel Coordinates
			graph9.data.fileName = file.fileName;
			graph9.data.worldWidth = worldWidth;
			graph9.data.worldHeight = worldHeight;
			graph9.data.xmax = 0;
			graph9.data.ymax = 0;
			newFile.openFile(graph9.data);
			graph9.sortGraph(graph9.data);
			graph9.sortDistances();
			graph9.normalizeData();
			//graph9.data.classsize = int(graph9.data.xdata[0].size());
			graph9.data.graphwidth = worldWidth * 0.8;
			graph9.data.graphheight = worldHeight * 0.5;
			graph9.fillGraphLocations();
			graph9.data.setClassColors();

			originalWH = worldHeight; // Saves orginals to use for increments like for zooming.
			originalWW = worldWidth;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Zooms. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <param name="scaler">	The scaler. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void zoom(int scaler) {
			int width = originalWW;
			int height = originalWH;

			if (graphType == 1) { // S-CPC

				graph1.data.worldWidth -= width / 20 * scaler; // increments of 20 is the limit for now as the zoom variable is from 1-10.
				graph1.data.worldHeight -= height / 20 * scaler;
				graph1.data.leftWidth += width / 20 * scaler;
				graph1.data.bottomHeight += height / 20 * scaler;

				graph1.data.panamount -= scaler * 2;
			}
			else if (graphType == 2) { // C-CPC

				graph2.data.worldWidth -= width / 20 * scaler;
				graph2.data.worldHeight -= height / 20 * scaler;
				graph2.data.leftWidth += width / 20 * scaler;
				graph2.data.bottomHeight += height / 20 * scaler;

				graph2.data.panamount -= scaler * 2;
			}
			else if (graphType == 3) { // S-SPC

				graph3.data.worldWidth -= width / 20 * scaler;
				graph3.data.worldHeight -= height / 20 * scaler;
				graph3.data.leftWidth += width / 20 * scaler;
				graph3.data.bottomHeight += height / 20 * scaler;

				graph3.data.panamount -= scaler * 2;
			}
			else if (graphType == 4) { // C-SPC

				graph4.data.worldWidth -= width / 20 * scaler;
				graph4.data.worldHeight -= height / 20 * scaler;
				graph4.data.leftWidth += width / 20 * scaler;
				graph4.data.bottomHeight += height / 20 * scaler;

				graph4.data.panamount -= scaler * 2;
			}
			else if (graphType == 5) { // Separated TS-SPC

				graph5.data.worldWidth -= width / 20 * scaler;
				graph5.data.worldHeight -= height / 20 * scaler;
				graph5.data.leftWidth += width / 20 * scaler;
				graph5.data.bottomHeight += height / 20 * scaler;

				graph5.data.panamount -= scaler * 2;
			}
			else if (graphType == 6) { // Standard TS

				graph6.data.worldWidth -= width / 20 * scaler;
				graph6.data.worldHeight -= height / 20 * scaler;
				graph6.data.leftWidth += width / 20 * scaler;
				graph6.data.bottomHeight += height / 20 * scaler;

				graph6.data.panamount -= scaler * 2;
			}
			else if (graphType == 7) { // Distance TS

				graph7.data.worldWidth -= width / 20 * scaler;
				graph7.data.worldHeight -= height / 20 * scaler;
				graph7.data.leftWidth += width / 20 * scaler;
				graph7.data.bottomHeight += height / 20 * scaler;

				graph7.data.panamount -= scaler * 2;
			}
			else if (graphType == 8) { // Continuous Parallel Coordinates

				graph8.data.worldWidth -= width / 20 * scaler;
				graph8.data.worldHeight -= height / 20 * scaler;
				graph8.data.leftWidth += width / 20 * scaler;
				graph8.data.bottomHeight += height / 20 * scaler;

				graph8.data.panamount -= scaler * 2;
			}
			else if (graphType == 9) { // Distance Continuous Parallel Coordinates

				graph9.data.worldWidth -= width / 20 * scaler;
				graph9.data.worldHeight -= height / 20 * scaler;
				graph9.data.leftWidth += width / 20 * scaler;
				graph9.data.bottomHeight += height / 20 * scaler;

				graph9.data.panamount -= scaler * 2;
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Pan horizontal. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <param name="right">	True to right. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void panHorizontal(bool right) {
			if (graphType == 1) { // S-CPC
				if (right) {
					graph1.data.pan_x -= graph1.data.panamount;
				}
				else {
					graph1.data.pan_x += graph1.data.panamount;
				}
				
			}
			else if (graphType == 2) { // C-CPC
				if (right) {
					graph2.data.pan_x -= graph2.data.panamount;
				}
				else {
					graph2.data.pan_x += graph2.data.panamount;
				}
			}
			else if (graphType == 3) { // S-SPC
				if (right) {
					graph3.data.pan_x -= graph3.data.panamount;
				}
				else {
					graph3.data.pan_x += graph3.data.panamount;
				}
			}
			else if (graphType == 4) { // C-SPC
				if (right) {
					graph4.data.pan_x -= graph4.data.panamount;
				}
				else {
					graph4.data.pan_x += graph4.data.panamount;
				}
			}
			else if (graphType == 5) { // Separated TS-SPC
				if (right) {
					graph5.data.pan_x -= graph5.data.panamount;
				}
				else {
					graph5.data.pan_x += graph5.data.panamount;
				}
			}
			else if (graphType == 6) { // Standard TS
				if (right) {
					graph6.data.pan_x -= graph6.data.panamount;
				}
				else {
					graph6.data.pan_x += graph6.data.panamount;
				}
			}
			else if (graphType == 7) { // Distance TS
				if (right) {
					graph7.data.pan_x -= graph7.data.panamount;
				}
				else {
					graph7.data.pan_x += graph7.data.panamount;
				}
			}
			else if (graphType == 8) { // Continuous Parallel Coordinates
				if (right) {
					graph8.data.pan_x -= graph8.data.panamount;
				}
				else {
					graph8.data.pan_x += graph8.data.panamount;
				}
			}
			else if (graphType == 9) { // Distance Continuous Parallel Coordinates
				if (right) {
					graph9.data.pan_x -= graph9.data.panamount;
				}
				else {
					graph9.data.pan_x += graph9.data.panamount;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Pan vertical. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <param name="up">	True to up. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void panVertical(bool up) {
			if (graphType == 1) { // S-CPC
				if (up) {
					graph1.data.pan_y -= graph1.data.panamount;
				}
				else {
					graph1.data.pan_y += graph1.data.panamount;
				}

			}
			else if (graphType == 2) { // C-CPC
				if (up) {
					graph2.data.pan_y -= graph2.data.panamount;
				}
				else {
					graph2.data.pan_y += graph2.data.panamount;
				}
			}
			else if (graphType == 3) { // S-SPC
				if (up) {
					graph3.data.pan_y -= graph3.data.panamount;
				}
				else {
					graph3.data.pan_y += graph3.data.panamount;
				}
			}
			else if (graphType == 4) { // C-SPC
				if (up) {
					graph4.data.pan_y -= graph4.data.panamount;
				}
				else {
					graph4.data.pan_y += graph4.data.panamount;
				}
			}
			else if (graphType == 5) { // Separated TS-SPC
				if (up) {
					graph5.data.pan_y -= graph5.data.panamount;
				}
				else {
					graph5.data.pan_y += graph5.data.panamount;
				}
			}
			else if (graphType == 6) { // Standard TS
				if (up) {
					graph6.data.pan_y -= graph6.data.panamount;
				}
				else {
					graph6.data.pan_y += graph6.data.panamount;
				}
			}
			else if (graphType == 7) { // Distance TS
				if (up) {
					graph7.data.pan_y -= graph7.data.panamount;
				}
				else {
					graph7.data.pan_y += graph7.data.panamount;
				}
			}
			else if (graphType == 8) { // Continuous Parallel Coordinates
				if (up) {
					graph8.data.pan_y -= graph8.data.panamount;
				}
				else {
					graph8.data.pan_y += graph8.data.panamount;
				}
			}
			else if (graphType == 9) { // Distance Continuous Parallel Coordinates
				if (up) {
					graph9.data.pan_y -= graph9.data.panamount;
				}
				else {
					graph9.data.pan_y += graph9.data.panamount;
				}
			}
		}


	private:
		/// <summary>	The device-context. </summary>
		/// <summary>	The device-context. </summary>
		HDC m_hDC;
		/// <summary>	The hglrc. </summary>
		HGLRC m_hglrc;


	protected:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Destructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		~COpenGL3(System::Void)
		{
			this->DestroyHandle();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	My set pixel format. </summary>
		///
		/// <param name="hdc">	The hdc. </param>
		///
		/// <returns>	A GLint. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Initializes the gl. </summary>
		///
		/// <param name="parameter1">	The first parameter. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{

			return TRUE;										// Initialisation went ok
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Re size gl scene. </summary>
		///
		/// <param name="width"> 	The width. </param>
		/// <param name="height">	The height. </param>
		///
		/// <returns>	A GLvoid. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets world mouse x coordinate. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <returns>	The world mouse x coordinate. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		double getWorldMouseX() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // gets the mouse coordinate relative to the OpenGL view

			double xWorld = pts->x;
			delete pts;
			return xWorld;
		} // Converts raw mouse X coordinates to world coordinates

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets world mouse y coordinate. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <returns>	The world mouse y coordinate. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		double getWorldMouseY() {

			// this will get the mouse position relative to the child window
			LPPOINT pts = new POINT;
			GetCursorPos(pts);

			::ScreenToClient((HWND)this->Handle.ToPointer(), pts); // Gets the mouse position relative to the OpenGL view

			double yWorld = pts->y;
			delete pts;
			return yWorld;
		} // Converts raw mouse Y coordinates to world coordinates



		// THIS IS WHERE ANY BUTTON CLICKS GO ///////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Window procedure. </summary>
		///
		/// <author>	Allyn Vo </author>
		///
		/// <param name="msg">	[in,out] The message. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual void WndProc(Message %msg) override
		{
			// get the X and Y coordinates of the mouse position
			this->worldMouseX = this->getWorldMouseX();
			this->worldMouseY = this->getWorldMouseY();

			switch (msg.Msg)
			{

			case WM_LBUTTONDOWN:
			{

				if (graphType == 1) { // S-CPC
					//No graph dragging
				}
				else if (graphType == 2) { // C-CPC
					graph2.zoom_at(worldMouseX, worldMouseY, 1.2); // 1.2 is scaling factor
				}
				else if (graphType == 3) { // S-SPC
					// FOR DRAGGING
					graph3.findClickedGraph(worldMouseX, worldMouseY);
					bool colliding = (graph3.graphClickedi != -1 && graph3.graphClickedj != -1);
					if (colliding)
					{
						graph3.dragging = true;
						graph3.data.xclasses[graph3.graphClickedi][graph3.graphClickedj] = worldMouseX - graph3.data.pan_x;
						graph3.data.yclasses[graph3.graphClickedi][graph3.graphClickedj] = worldMouseY - graph3.data.pan_y;

					}
				}
				else if (graphType == 4) { // C-SPC
					// FOR DRAGGING
					graph4.graphClicked = graph4.findClickedGraph(worldMouseX, worldMouseY);
					bool colliding = (graph4.graphClicked != -1);
					if (colliding)
					{
						graph4.dragging = true;
						graph4.data.xgraphcoordinates[graph4.graphClicked] = worldMouseX - graph4.data.pan_x;
						graph4.data.ygraphcoordinates[graph4.graphClicked] = worldMouseY - graph4.data.pan_y;
					}
				}
				else if (graphType == 5) { // S-TS-SPC
					// FOR DRAGGING
					graph5.findClickedGraph(worldMouseX, worldMouseY);
					bool colliding = (graph5.graphClickedi != -1 && graph5.graphClickedj != -1);
					if (colliding)
					{
						graph5.dragging = true;
						graph5.data.xclasses[graph5.graphClickedi][graph5.graphClickedj] = worldMouseX - graph5.data.pan_x;
						graph5.data.yclasses[graph5.graphClickedi][graph5.graphClickedj] = worldMouseY - graph4.data.pan_y;

					}
				}


			}
			break;
			case WM_RBUTTONDOWN:
			{

				if (graphType == 1) { // S-CPC
					// NOTHING YET
				}
				else if (graphType == 2) { // C-CPC
					graph2.zoom_at(worldMouseX, worldMouseY, 1/1.2); // 1.2 is scaling factor
				}
				else if (graphType == 3) { // S-SPC
					// NOTHING YET
				}
				else if (graphType == 4) { // C-SPC
					// NOTHING YET
				}
			}
			break;
			case WM_MOUSEMOVE:
			{

				//if (drawingDragged)
				//{
					if (graphType == 1) { // S-CPC
						//graph1.data.ygraphcoordinates[lineClicked] = worldMouseY;
					}
					else if (graphType == 2) { // C-CPC
						// NOTHING YET
					}
					else if (graphType == 3) { // S-SPC
						// DRAGGING
						if (graph3.dragging) {
							graph3.data.xclasses[graph3.graphClickedi][graph3.graphClickedj] = worldMouseX - graph3.data.pan_x;
							graph3.data.yclasses[graph3.graphClickedi][graph3.graphClickedj] = worldMouseY - graph3.data.pan_y;
						}
					}
					else if (graphType == 4) { // C-SPC
						// DRAGGING
						if (graph4.dragging) {
							graph4.data.xgraphcoordinates[graph4.graphClicked] = worldMouseX - graph4.data.pan_x;
							graph4.data.ygraphcoordinates[graph4.graphClicked] = worldMouseY - graph4.data.pan_y;
						}
					}
					else if (graphType == 5) { // S-TS-SPC
						// DRAGGING
						if (graph5.dragging) {
							graph5.data.xclasses[graph5.graphClickedi][graph5.graphClickedj] = worldMouseX - graph5.data.pan_x;
							graph5.data.yclasses[graph5.graphClickedi][graph5.graphClickedj] = worldMouseY - graph5.data.pan_y;
						}
					}


				//}
			}
			break;
			case WM_LBUTTONUP:
			{
				if (graph3.dragging) {
					graph3.dragging = false;
					graph3.graphClickedi = -1;
					graph3.graphClickedj = -1;
				}

				if (graph4.dragging) {
					graph4.dragging = false;
					graph4.graphClicked = -1;
				}

				if (graph5.dragging) {
					graph5.dragging = false;
					graph5.graphClickedi = -1;
					graph5.graphClickedj = -1;
				}

				if (this->drawingDragged) {

					this->drawingDragged = false;
					
				}

			}
			break;
			}

			NativeWindow::WndProc(msg);
		}

		
	};
}
