///INTERFACE: The IEventArgs interface stores the methods that any derivation class uses, the IEventArgs is atype of object that will be created
///in the model after manipulating or loading an iamge.
#pragma once
#include "IMedia.h"

class IEventArgs
{
public:
	/// a getter for the memory reference to a object of type IMedia
	/// @return the memory reference to the IMedia object
	virtual shared_ptr<IMedia> image() = 0;

	/// a getter for the current position of an image
	/// @return an integer noting the current position of the image
	virtual int getCount() = 0;
};