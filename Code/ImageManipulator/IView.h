///INTERFACE: THe IView interface holds all of the implementation for the View component of our software.
#pragma once
#include "ImageManipulator.h"
#include "IClick.h"
#include "IEventListener.h"
#include "EventArgs.h"

class IView : public IEventListener
{
public:
	/// Sets the controller that will handle all of the events called
	/// @param pctrl is a memory reference to the controller that is being used
	virtual void setClick(shared_ptr <IClick> pctrl) = 0;

	/// Receives the images requested by the user, then sends them to the controller to be loaded 
	virtual void PassValue() = 0;

	/// Sends the value that the image is to be rotated by to the controller
	/// @param dir an integer symbolizing the direction of the rotation, 0 = anti-clockwise, 1 = clockwise
	virtual void SendRotateValues(int dir) = 0;

	/// Sends the value that the image is to be scaled by to the controller
	virtual void PassScaleValue() = 0;

	/// Receives the image with the changes made to it through events
	/// @param e is a memory reference to the EventArgs after the image has been manipulated
	virtual void whenDataChanged(shared_ptr<IEventArgs> e) = 0;

	/// Shows the requested image in the display box
	/// @param pImg is a memory reference to the image that is to be shown
	virtual void displayImage(shared_ptr<IMedia> pImg) = 0;

	/// Sends the request to show the next image in the vector to the controller
	virtual void SendNextCall() = 0;

	/// Sends the request to show the previous image in the vector to the controller
	virtual void SendPreviousCall() = 0;

	/// Sends the request to flip the current image, horizontally, to the controller
	virtual void SendFlipHorizontalCall() = 0;

	/// Sends the request to flip the current image, vertically, to the controller
	virtual void SendFlipVerticalCall() = 0;

	/// Sends the request to rotate the current image, clockwise, to the controller, using the value for rotation given
	/// @param val the value amount to rotate the image by
	virtual void SendRotateClockCall(int val) = 0;
	/// Sends the request to rotate the current image, anti-clockwise, to the controller, using the value for rotation given
	/// @param val the value amount to rotate the image by
	virtual void SendRotateAntiCall(int val) = 0;

	/// Rescales the program window, dependant on the image that is being requested,
	/// and resets the layout of the buttons to match the window size
	/// @param w is the width of the image that is being shown
	/// @param h is the height of the image that is being shown
	virtual void resizeWind(int w, int h) = 0;
};