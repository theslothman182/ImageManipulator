/// CLASS HEADER: Controller implements the IClick and IController interfaces to act as our implementation for the Strategy design pattern
/// The Run method is just to pass control of the running of the program over to FLTK allowing the program to run idly on the Operating System
/// The handleClick method and overloads are to pass data from the View to the Model which are stored as references.
#pragma once
#include "ImageManipulator.h"
#include "IController.h"
#include "IClick.h"
#include "IModel.h"
#include "IView.h"

class Controller : public IClick, public IController
{
public:
	/// CONSTRUCTOR: creates an instance of
	Controller(shared_ptr<IView> pGui, shared_ptr<IModel> pMod);
	/// DESTRUCTOR: to prevent any memory leak
	~Controller();

	/// makes the call to run the program
	void Run();

	/// makes a call to the model to the load the files requested
	/// @param files a vector<string> containing the names of the files to be loaded
	void handleLoadClick(vector<string> files);

	/// makes a call to the model to get the next image in the vector of images
	/// @param cur an integer to record the current images position in the vector
	void handleNextClick(int cur);
	/// makes a call to the model to get the image before in the vector of images
	/// @param cur an integer to record the current images position in the vector
	void handlePreviousClick(int cur);

	/// makes a call to the model to flip the current image being shown, horizontally
	/// @param cur an integer to record the current images position in the vector
	void handleFlipHorizontalClick(int cur);
	/// makes a call to the model to flip the current image being shown, vertically
	/// @param cur an integer to record the current images position in the vector
	void handleFlipVerticalClick(int cur);

	/// makes a call to the model to rotate the current image being shown, clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	void handleRotateClockClick(int cur, int val);
	/// makes a call to the model to rotate the current image being shown, anti-clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	void handleRotateAntiClick(int cur, int val);

	/// makes a call to the model to rotate the current image being shown, anti-clockwise, by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val an integer containing the value the image is to be rotated by
	void handleScaleClick(int cur, int width, int height);

	/// makes a call to the model to save the current image being shown
	/// @param imgCount the amount of images to be saved
	/// @param name the full file directory of the file to be saved
	void handleSaveClick(int imgCount, string name);

	/// DECLARE: a memory reference to the View
	shared_ptr<IView> gui;
	/// DECLARE: a memory reference to the Model
	shared_ptr<IModel> mod;
};

