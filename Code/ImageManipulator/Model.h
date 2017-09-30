///CLASS HEADER: THe Model class is responsible for all of the backend logic of the program such as loading and manipulating
///images
#pragma once
#include "ImageManipulator.h"
#include "IModel.h"
#include "IEventPublisher.h"
#include "MediaManager.h"
#include "IMedia.h"
#include "EventArgs.h"

class Model : public IEventPublisher, public IModel
{
public:
	/// CONSTRUCTOR: creates an instance of
	Model();
	/// DESTRUCTOR: to prevent any memory leak
	~Model();

	/// saves the requested images, using the file directory and name given to it
	/// @param cur an integer to record the current images position in the vector
	/// @param name the full file directory to save the image by
	void doSave(int cur, string name);

	/// loads the images that have been requested
	/// @param files a vector<string> containing the names of the images to be loaded
	void doLoad(vector<string> files);

	/// loads the images that have been requested
	/// @param files a vector<string> containing the names of the images to be loaded
	vector<shared_ptr<IMedia>> Load(vector<string> files);

	/// subscribes a listener to the model
	/// @param eL the listener that wants to subscribe to the event
	void subscribe(shared_ptr<IEventListener> eL);

	/// Fires the event, sending the requested changes back to the View
	/// @param img a memory reference to the IMedia object to be shown
	/// @param count an integer to record the current images position in the vector
	void fireEvent(shared_ptr<IMedia> img, int count);

	/// Changes the current image, to the next image in the vector
	/// @param cur an integer to record the current images position in the vector
	void getNext(int cur);

	/// Changes the current image, to the image before it in the vector
	/// @param cur an integer to record the current images position in the vector
	void getLast(int cur);

	/// Flips the current image horizontally
	/// @param cur an integer to record the current images position in the vector
	void flipHorizontal(int cur);

	/// Flips the current image vertically
	/// @param cur an integer to record the current images position in the vector
	void flipVertical(int cur);

	/// Rotates the current image clockwise by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val the value to rotate the image by
	void rotateClockwise(int cur, int val);

	/// Rotates the current image anti-clockwise by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val the value to rotate the image by
	void rotateAntiClock(int cur, int val);

	/// Scales the current image by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param valW the value to scale the width by
	/// @param valH the value to scale the height by
	void scale(int cur, int valW, int valH);

private:
	/// DECLARE: a vector to store references to IMedia objects
	vector<shared_ptr<IMedia>> resultList;
	/// DECLARE: a memory reference to an IMedia object, to be stored in the vector
	shared_ptr<IMedia> result;
	/// DECLARE: a vector to store references to event listeners
	vector<shared_ptr<IEventListener>> _eventHandlers;
	/// DECLARE: and instantiate an object of type MediaManager
	shared_ptr<IMediaManager> mediaMgr{ new MediaManager() };
};

