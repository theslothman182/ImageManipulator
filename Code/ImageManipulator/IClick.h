///INTERFACE: The IClick interface is the interface that is responsible for our Strategy pattern
#pragma once
#include "ImageManipulator.h"

class IClick
{
public:
	/// makes a call to the model to the load the files requested
	/// @param files a vector<string> containing the names of the files to be loaded
	virtual void handleLoadClick(vector<string> files) = 0;

	/// makes a call to the model to get the next image in the vector of images
	/// @param cur an integer to record the current images position in the vector
	virtual void handleNextClick(int cur) = 0;

	/// makes a call to the model to get the image before in the vector of images
	/// @param cur an integer to record the current images position in the vector
	virtual void handlePreviousClick(int cur) = 0;

	/// makes a call to the model to flip the current image being shown, vertically
	/// @param cur an integer to record the current images position in the vector
	virtual void handleFlipVerticalClick(int cur) = 0;

	/// makes a call to the model to flip the current image being shown, horizontally
	/// @param cur an integer to record the current images position in the vector
	virtual void handleFlipHorizontalClick(int cur) = 0;

	/// makes a call to the model to rotate the current image being shown, clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	virtual void handleRotateClockClick(int cur, int val) = 0;

	/// makes a call to the model to rotate the current image being shown, anti-clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	virtual void handleRotateAntiClick(int cur, int val) = 0;

	/// makes a call to the model to rotate the current image being shown, anti-clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	virtual void handleScaleClick(int cur, int width, int height) = 0;

	/// makes a call to the model to save the current image being shown
	/// @param imgCount the amount of images to be saved
	/// @param name the full file directory of the file to be saved
	virtual void handleSaveClick(int imgCount, string name) = 0;
};
