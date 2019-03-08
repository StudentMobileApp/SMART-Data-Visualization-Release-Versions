///-------------------------------------------------------------------------------------------------
// file:	FileHandling.cpp
//
// summary:	Implements the file handling class
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "FileHandling.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <author>	Allyn Vo </author>	
////////////////////////////////////////////////////////////////////////////////////////////////////

FileHandling::FileHandling() {}

// Input: Contents of input.csv -- Opens the file and reads the values into matrix values

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Opens the file and reads the values into matrix values. </summary>
///
/// <author>	Allyn Vo </author>	
///
/// <param name="data">	[in,out] The data. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void FileHandling::openFile(ClassData &data)
{
	using namespace std;
	ifstream myFile;
	string line;

	myFile.open(data.fileName);											// Open the file

	if (myFile.is_open()) {												/* Valid File: Begin reading data form the file */
		vector<std::string> columns;

		while (getline(myFile, line)) {									/* While the file has more data */
			istringstream cell(line);
			string distance;
			while (getline(cell, distance, ',')) {
				columns.push_back(distance);
			}
			data.values.push_back(columns);								// Store data
			columns.clear();
		}

	}
	myFile.close();
}

// Input: Contents of input.csv -- Splits the values into x and y coords

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sorts graph. Main sorter for standard graphs.</summary>
///
/// <author>	Allyn Vo </author>	
///
/// <param name="data">	[in,out] The data. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void FileHandling::sortGraph(ClassData &data)
{
	std::vector<float> xdatatemp;
	std::vector<float> ydatatemp;
	float xCoord = 0;
	float yCoord = 0;

	for (int i = 1; i < (data.values.size()); i++)					// OLD: for (int i = 1; i < (data.values.size() - 1); i++)
	{																	// Columns
		int nodeClass = 
			stoi(data.values[i][(data.values[0].size() - 1)]);          // Get the class of the node
		if (nodeClass > data.numOfClasses)                              // Get the highest class number
			data.numOfClasses = nodeClass;
		data.classNum.push_back(nodeClass);                             // Add to vector of class numbers

		for (int j = 1; j < (data.values[i].size() - 1); j++)			// Rows
		{                                          
			if (xdatatemp.size() <= ydatatemp.size())					// Get X-coords
			{                                        
				xCoord = stof(data.values[i][j]);
				xdatatemp.push_back(xCoord);
				if (xCoord > data.xmax)
					data.xmax = xCoord;
			}
			else
			{                                                            // Get y coords
				yCoord = stof(data.values[i][j]);
				ydatatemp.push_back(yCoord);
				if (yCoord > data.ymax)
					data.ymax = yCoord;
			}
		}
		if (xdatatemp.size() != ydatatemp.size())						// Duplicate last pair if odd # of columns
		{                                            
			ydatatemp.push_back(xCoord);
			if (yCoord > data.ymax)  // Get y-max
				data.ymax = yCoord;
		}
		data.xdata.push_back(xdatatemp);                                // Add line plot coords
		data.ydata.push_back(ydatatemp);
		xdatatemp.clear();                                              // Clear for the next plot line
		ydatatemp.clear();
	}
}
