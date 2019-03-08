#include "stdafx.h"
#include "ClassData.h"
#include "FileHandling.h"

#pragma once
class Dist_Cont_Parallel_Coords
{
public:
	/// <summary>	The data. </summary>
	ClassData data;
	/// <summary>	The new file. </summary>
	FileHandling newFile;
	/// <summary>	The xdatatemp. </summary>
	std::vector<float> xdatatemp;
	/// <summary>	The ydatatemp. </summary>
	std::vector<float> ydatatemp;

	Dist_Cont_Parallel_Coords();

	void clearFields();
	void normalizeData();
	void sortDistances();
	void drawData(float x1, float y1, int index);
	void fillGraphLocations();
	void drawGraph(float x, float y);
	void display();
	void sortGraph(ClassData& data);
};

