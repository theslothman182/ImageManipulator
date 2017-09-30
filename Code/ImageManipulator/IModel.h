///INTERFACE: This interface is responsible for all of the logic handling done in the program since the Model implements this 
///interface.
#pragma once
#include "IEventPublisher.h"
#include "ImageManipulator.h"
class IModel
{
public:
	/// loads the images that have been requested
	/// @param files a vector<string> containing the names of the images to be loaded
	virtual vector<shared_ptr<IMedia>> Load(vector<string> files) = 0;

	/// saves the requested images, using the file directory and name given to it
	/// @param cur an integer to record the current images position in the vector
	/// @param name the full file directory to save the image by
	virtual void doSave(int cur, string name) = 0;

	/// loads the images that have been requested
	/// @param files a vector<string> containing the names of the images to be loaded
	virtual void doLoad(vector<string> files) = 0;

	/// Changes the current image, to the next image in the vector
	/// @param cur an integer to record the current images position in the vector
	virtual void getNext(int cur) = 0;

	/// Changes the current image, to the image before it in the vector
	/// @param cur an integer to record the current images position in the vector
	virtual void getLast(int cur) = 0;

	/// Flips the current image horizontally
	/// @param cur an integer to record the current images position in the vector
	virtual void flipHorizontal(int cur) = 0;

	/// Flips the current image vertically
	/// @param cur an integer to record the current images position in the vector
	virtual void flipVertical(int cur) = 0;

	/// Rotates the current image clockwise by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val the value to rotate the image by
	virtual void rotateClockwise(int cur, int val) = 0;

	/// Rotates the current image anti-clockwise by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param val the value to rotate the image by
	virtual void rotateAntiClock(int cur, int val) = 0;

	/// Scales the current image by the value given
	/// @param cur an integer to record the current images position in the vector
	/// @param valW the value to scale the width by
	/// @param valH the value to scale the height by
	virtual void scale(int cur, int valW, int valH) = 0;
};
