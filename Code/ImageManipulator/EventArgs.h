///CLASS HEADER: The EventArgs are the concrete implementation for the IEventArgs interface that will be created in the model
///after loading or manipulating an iamge.
#pragma once
#include "ImageManipulator.h"
#include "IEventArgs.h"

class EventArgs : public IEventArgs
{
public:
	/// CONSTRUCTOR: creates an instance of
	EventArgs(shared_ptr<IMedia> img, int counter);
	/// DESTRUCTOR: to prevent any memory leak
	~EventArgs();

	/// a getter for the memory reference to a object of type IMedia
	/// @return the memory reference to the IMedia object
	shared_ptr<IMedia> image();

	/// a getter for the current position of an image
	/// @return an integer noting the current position of the image
	int getCount();

private:
	/// DECLARE: a memory reference to an IMedia object
	shared_ptr<IMedia> retVal;
	/// DECLARE: an integer, to note the position of an item in a vector
	int count;
};

