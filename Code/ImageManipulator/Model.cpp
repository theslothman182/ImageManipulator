#include "stdafx.h"
#include "Model.h"

/// CONSTRUCTOR: creates an instance of
Model::Model()
{
}

/// DESTRUCTOR: to prevent any memory leak
Model::~Model()
{
}

/// subscribes a listener to the model
/// @param eL the listener that wants to subscribe to the event
void Model::subscribe(shared_ptr<IEventListener> eL)
{
	/// SUBSCRIBE: the View to the event
	_eventHandlers.push_back(eL);
}

/// loads the images that have been requested
/// @param files a vector<string> containing the names of the images to be loaded
void Model::doLoad(vector<string> files)
{
	/// INSTANTIATE: the vector of string to load
	resultList = Load(files);
	/// SET: a counter using the size of the vector
	int counter = resultList.size();
	/// SET: the image to be loaded using the first string in the vector
	result = resultList[0];
	/// FIRE: the event, loading the image as an IMedia object
	fireEvent(result, 0);
}

/// Creates a vector of IMedia objects using their filenames
/// @param files a vector<string> containing the names of the images to be loaded
/// @return the vector<shared_ptr<IMedia>> containing the objects to be loaded
vector<shared_ptr<IMedia>> Model::Load(vector<string> files)
{
	/// INSTANTIATE: a vector of string that need to be loaded
	shared_ptr<vector<string>> imageList = mediaMgr->load(files);
	/// DECLARE: a vector of shared pointers to IMedia objects
	vector<shared_ptr<IMedia>> retList;

	/// ITERATE: through the filenames
	for (vector<string>::iterator imgIt = imageList->begin(); imgIt != imageList->end(); imgIt++)
	{
		/// SET: an integer to note the position of the string in the vector
		int imgPos = imgIt - imageList->begin();
		/// ADD: that string as a member of the IMedia vector
		retList.push_back(mediaMgr->getMediaItem(imageList->at(imgPos)));
	}

	/// RETURN: the list of IMedia objects to be loaded
	return retList;

}

/// Changes the current image, to the next image in the vector
/// @param cur an integer to record the current images position in the vector
void Model::getNext(int cur)
{
	/// SET: a counter using the size of the vector
	int counter = resultList.size();
	/// IF: the current item is the last item in the vector
	if (cur + 1 >= resultList.size())
	{
		/// LOOP: back to the first member of the vector
		result = resultList[0];
		/// FIRE: the event, loading this image as an IMedia object
		fireEvent(result, 0);
	}
	else
	{
		/// SET: the image to the next member in the vector
		result = resultList[cur + 1];
		/// FIRE: the event, loading this image as an IMedia object
		fireEvent(result, cur + 1);
	}
}

/// Changes the current image, to the image before it in the vector
/// @param cur an integer to record the current images position in the vector
void Model::getLast(int cur)
{
	/// SET: a counter using the size of the vector
	int counter = resultList.size();
	/// IF: the current item is the first item in the vector
	if (cur - 1 < 0)
	{
		/// LOOP: back to the last member of the vector
		result = resultList[resultList.size() - 1];
		/// FIRE: the event, loading this image as an IMedia object
		fireEvent(result, counter - 1);
	}
	else
	{
		/// SET: the image to the member before in the vector
		result = resultList[cur - 1];
		/// FIRE: the event, loading this image as an IMedia object
		fireEvent(result, cur - 1);
	}
}


/// Flips the current image horizontally
/// @param cur an integer to record the current images position in the vector
void Model::flipHorizontal(int cur)
{
	/// SET: the image using the current image showing
	result = resultList[cur];

	/// DOWNCAST: an IMedia object so that it can be used as an object of type Image
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// FLIP: the image horizontally
	imgRes->image->flipHorizontal();

	/// UPCAST: the Image back to type IMedia
	result = dynamic_pointer_cast<IMedia>(imgRes);
	/// FIRE: the event, loading the changes to the IMedia object
	fireEvent(result, cur);
}

/// Flips the current image vertically
/// @param cur an integer to record the current images position in the vector
void Model::flipVertical(int cur)
{
	/// SET: the image using the current image showing
	result = resultList[cur];

	/// DOWNCAST: an IMedia object so that it can be used as an object of type Image
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// FLIP: the image vertically
	imgRes->image->flipVertical();

	/// UPCAST: the Image back to type IMedia
	result = dynamic_pointer_cast<IMedia>(imgRes);
	/// FIRE: the event, loading the changes to the IMedia object
	fireEvent(result, cur);
}

/// Rotates the current image clockwise by the value given
/// @param cur an integer to record the current images position in the vector
/// @param val the value to rotate the image by
void Model::rotateClockwise(int cur, int val)
{
	/// SET: the image using the current image showing
	result = resultList[cur];

	/// DOWNCAST: an IMedia object so that it can be used as an object of type Imag
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// ROTATE: the image clockwise, using the value given through input
	imgRes->image->rotate(val);

	/// UPCAST: the Image back to type IMedia
	result = dynamic_pointer_cast<IMedia>(imgRes);
	/// FIRE: the event, loading the changes to the IMedia object
	fireEvent(result, cur);
}

/// Rotates the current image anti-clockwise by the value given
/// @param cur an integer to record the current images position in the vector
/// @param val the value to rotate the image by
void Model::rotateAntiClock(int cur, int val) 
{
	/// SET: the image using the current image showing
	result = resultList[cur];

	/// DOWNCAST: an IMedia object so that it can be used as an object of type Imag
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// ROTATE: the image anti- clockwise, using the value given through input
	imgRes->image->rotate(-val);

	/// UPCAST: the Image back to type IMedia
	result = dynamic_pointer_cast<IMedia>(imgRes);
	/// FIRE: the event, loading the changes to the IMedia object
	fireEvent(result, cur);
}

/// Scales the current image by the value given
/// @param cur an integer to record the current images position in the vector
/// @param valW the value to scale the width by
/// @param valH the value to scale the height by
void Model::scale(int cur, int valW, int valH)
{
	/// SET: the image using the current image showing
	result = resultList[cur];

	/// DOWNCAST: an IMedia object so that it can be used as an object of type Imag
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// SCALE: the image, using the value given through input
	imgRes->image->rescale(valW, valH, FILTER_LANCZOS3);

	/// UPCAST: the Image back to type IMedia
	result = dynamic_pointer_cast<IMedia>(imgRes);
	/// FIRE: the event, loading the changes to the IMedia object
	fireEvent(result, cur);
}

/// Fires the event, sending the requested changes back to the View
/// @param img a memory reference to the IMedia object to be shown
/// @param count an integer to record the current images position in the vector
void Model::fireEvent(shared_ptr<IMedia> img, int count)
{
	/// DECLARE: and instantiate an object of type EventArgs
	shared_ptr<IEventArgs> e{ new EventArgs(img, count) };

	/// ITERATE: through the list of listeners
	for (vector<shared_ptr<IEventListener>>::iterator it = _eventHandlers.begin(); it != _eventHandlers.end(); it++)
	{
		/// SET: an integer to note the position of the listener in the vector
		int pos = it - _eventHandlers.begin();
		/// SEND: the image to the View
		_eventHandlers[pos]->whenDataChanged(e);
	}
}

/// saves the requested images, using the file directory and name given to it
/// @param cur an integer to record the current images position in the vector
/// @param name the full file directory to save the image by
void Model::doSave(int cur, string name)
{
	/// DOWNCAST: the IMeda shared pointer, so that it may be accessed as an Image shared pointer
	shared_ptr<Image> imgRes = dynamic_pointer_cast<Image>(result);
	/// FLIP: the image vertically, so that when saved it is the right way up
	imgRes->image->flipVertical();
	/// CAST: the string holding the the save file directory to a list of char's
	const char* charName = name.c_str();
	/// SAVE: the image under the selected directory
	imgRes->image->save(charName);
}