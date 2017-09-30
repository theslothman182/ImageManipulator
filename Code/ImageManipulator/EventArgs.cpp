#include "stdafx.h"
#include "EventArgs.h"

/// CONSTRUCTOR: creates an instance of
EventArgs::EventArgs(shared_ptr<IMedia> img, int counter)
{
	retVal = img;
	count = counter;
}

/// DESTRUCTOR: to prevent any memory leak
EventArgs::~EventArgs()
{
}

/// a getter for the memory reference to a object of type IMedia
/// @return the memory reference to the IMedia object
shared_ptr<IMedia> EventArgs::image()
{
	/// RETURN: the IMedia object
	return retVal;
}

/// a getter for the current position of an image
/// @return an integer noting the current position of the image
int EventArgs::getCount()
{
	/// RETURN: the current position
	return count;
}
