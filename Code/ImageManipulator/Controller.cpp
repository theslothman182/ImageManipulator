#include "stdafx.h"
#include "Controller.h"

/// CONSTRUCTOR: creates an instance of
Controller::Controller(shared_ptr<IView> pGui, shared_ptr<IModel> pMod)
{
	/// INSTANTIATE: the View
	gui = pGui;
	/// INSTANTIATE: the Model
	mod = pMod;
	/// UPCAST: the Model, so that it can be used as an IEventPublisher
	shared_ptr<IEventPublisher> modPub = dynamic_pointer_cast<IEventPublisher>(mod);
	/// SUBSCRIBE: the View to the Model
	modPub->subscribe(dynamic_pointer_cast<IEventListener>(gui));
	/// CAST: the IEventListener, so it can be used as an IModel
	mod = dynamic_pointer_cast<IModel>(modPub);
}

/// DESTRUCTOR: to prevent any memory leak
Controller::~Controller()
{
}

/// makes the call to run the program
void Controller::Run()
{
	/// RUN: the program
	Fl::run();
}

/// makes a call to the model to the load the files requested
/// @param files a vector<string> containing the names of the files to be loaded
void Controller::handleLoadClick(vector<string> files)
{
	/// CALL: the method to load the images requested
	mod->doLoad(files);
	
}

/// makes a call to the model to get the next image in the vector of images
/// @param cur an integer to record the current images position in the vector
void Controller::handleNextClick(int cur)
{
	/// CALL: the method to get the next image in the vector
	mod->getNext(cur);
}

/// makes a call to the model to get the image before in the vector of images
/// @param cur an integer to record the current images position in the vector
void Controller::handlePreviousClick(int cur)
{
	/// CALL: the method to get the previous image in the vector
	mod->getLast(cur);
}

/// makes a call to the model to flip the current image being shown, horizontally
/// @param cur an integer to record the current images position in the vector
void Controller::handleFlipHorizontalClick(int cur)
{
	/// CALL: the method to flip the image horizontally
	mod->flipHorizontal(cur);
}

/// makes a call to the model to flip the current image being shown, vertically
/// @param cur an integer to record the current images position in the vector
void Controller::handleFlipVerticalClick(int cur)
{
	/// CALL: the method to flip the image vertically
	mod->flipVertical(cur);
}

/// makes a call to the model to rotate the current image being shown, clockwise, by the value given
/// @param cur an integer to record the current images position in the vector
/// @param val an integer containing the value the image is to be rotated by
void Controller::handleRotateClockClick(int cur, int val)
{
	/// CALL: the method to rotate the image clockwise
	mod->rotateClockwise(cur, val);
}

/// makes a call to the model to rotate the current image being shown, anti-clockwise, by the value given
/// @param cur an integer to record the current images position in the vector
/// @param val an integer containing the value the image is to be rotated by
void Controller::handleRotateAntiClick(int cur, int val)
{
	/// CALL: the method to rotate the image anti-clockwise
	mod->rotateAntiClock(cur, val);
}

/// makes a call to the model to scale the current image being shown, by the value given
/// @param an integer to record the current images position in the vector
/// @param width the value the width of the image is to be scaled by
/// @param height the value the height of the image is to be scaled by
void Controller::handleScaleClick(int cur, int width, int height)
{
	/// CALL: the method to set the scale of the image
	mod->scale(cur, width, height);
}

/// makes a call to the model to save the current image being shown
/// @param imgCount the amount of images to be saved
/// @param name the full file directory of the file to be saved
void Controller::handleSaveClick(int imgCount, string name)
{
	/// CALL: the method to save the image
	mod->doSave(imgCount, name);
}
