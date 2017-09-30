///CLASS HEADER: The View is responsible for the display of all data and also the user interface in the program. The buttons in the
///user interface initiate a callback when they are clicked which sends data to the controller to be passed on to view.
#pragma once
#include "ImageManipulator.h"
#include "IView.h"
#include "IClick.h"
#include "IEventListener.h"
#include "IEventArgs.h"
#include "Image.h"

class View : public IView, public Fl_Double_Window
{
public:
	/// CONSTRUCTOR: creates an instance of
	View();
	/// DESTRUCTOR: to prevent any memory leak
	~View();

	/// DECLARE: a button to load images from
	shared_ptr<Fl_Button> loadButton;
	/// DECLARE: a button to show the next image in a vector
	shared_ptr<Fl_Button> nextButton;
	/// DECLARE: a button to show the image before in a vector
	shared_ptr<Fl_Button> backButton;
	/// DECLARE: a button to flip the current image vertically
	shared_ptr<Fl_Button> flipVerticalButton;
	/// DECLARE: a button to flip the current image horizontally
	shared_ptr<Fl_Button> flipHorizontalButton;
	/// DECLARE: a button to rotate the current image clockwise
	shared_ptr<Fl_Button> rotateClockButton;
	/// DECLARE: a button to rotate the current image anti-clockwise
	shared_ptr<Fl_Button> rotateAntiButton;
	/// DECLARE: an input for the user to set the value they want to rotate an image by
	shared_ptr<Fl_Value_Input> Rotation;
	/// DECLARE: an input for the user to set the value they want to scale the width by
	shared_ptr<Fl_Value_Input> Width;
	/// DECLARE: an input for the user to set the value they want to scale the height by
	shared_ptr<Fl_Value_Input> Height;
	/// DECLARE: a button to scale the current image
	shared_ptr<Fl_Button> scaleButton;
	/// DECLARE: a display box to show the current image in
	shared_ptr<Fl_Box> displayBox;
	/// DECLARE: a button to save the current image in the state it is in
	shared_ptr<Fl_Button> saveButton;
	/// DECLARE: a controller to handle requested events
	shared_ptr<IClick> ctrl;

	/// Makes a call for the current image to be saved
	/// @param *w
	/// @param *data
	static void DoSave(Fl_Widget *w, void *data);
	/// Makes a call to load an image
	/// @param *w
	/// @param *data
	static void DoLoad(Fl_Widget *w, void *data);

	/// Makes a call to show the next image in the vector
	/// @param *w
	/// @param *data
	static void DoNext(Fl_Widget *w, void *data);
	/// Makes a call to show the previous image in the vector
	/// @param *w
	/// @param *data
	static void DoPrevious(Fl_Widget *w, void *data);

	/// Makes a call to flip the current image horizontally
	/// @param *w
	/// @param *data
	static void DoFlipHorizontal(Fl_Widget *w, void *data);
	/// Makes a call to flip the current image vertically
	/// @param *w
	/// @param *data
	static void DoFlipVertical(Fl_Widget *w, void *data);

	/// Makes a call to rotate the current image clockwise
	/// @param *w
	/// @param *data
	static void DoRotateClock(Fl_Widget *w, void *data);
	/// Makes a call to rotate the current image anti-clockwise
	/// @param *w
	/// @param *data
	static void DoRotateAnti(Fl_Widget *w, void *data);

	/// Makes a call to scale the current image
	/// @param *w
	/// @param *data
	static void DoScale(Fl_Widget *w, void *data);

	/// Opens a file chooser window, where the user can select the images they want to load
	/// @param prompt the message header to the file chooser
	/// @return the vecotr<string> containing the names of the images to be loaded
	vector<string> getInput(string prompt);
	/// Sets the controller that will handle all of the events called
	/// @param pctrl is a memory reference to the controller that is being used
	void setClick(shared_ptr <IClick> pctrl);

	/// Receives the images requested by the user, then sends them to the controller to be loaded 
	void PassValue();
	/// Sends the value that the image is to be rotated by to the controller
	/// @param dir an integer symbolizing the direction of the rotation, 0 = anti-clockwise, 1 = clockwise
	void SendRotateValues(int dir);

	/// Sends the request to show the next image in the vector to the controller
	void SendNextCall();
	/// Sends the request to show the previous image in the vector to the controller
	void SendPreviousCall();

	/// Sends the request to flip the current image, horizontally, to the controller
	void SendFlipHorizontalCall();
	/// Sends the request to flip the current image, vertically, to the controller
	void SendFlipVerticalCall();

	/// Sends the request to rotate the current image, clockwise, to the controller, using the value for rotation given
	/// @param val the value amount to rotate the image by
	void SendRotateClockCall(int val);
	/// Sends the request to rotate the current image, anti-clockwise, to the controller, using the value for rotation given
	/// @param val the value amount to rotate the image by
	void SendRotateAntiCall(int val);

	/// Sends the value that the image is to be scaled by to the controller
	void PassScaleValue();
	/// Sends the request to scale the current image to the controller, using the values for height and width given
	/// @param width the value amount to scale the width of the image by
	/// @param width the value amount to scale the height of the image by
	void SendScale(int width, int height);

	/// Receives the image with the changes made to it through events
	/// @param e is a memory reference to the EventArgs after the image has been manipulated
	void whenDataChanged(shared_ptr<IEventArgs> e);
	/// Shows the requested image in the display box
	/// @param pImg is a memory reference to the image that is to be shown
	void displayImage(shared_ptr<IMedia> pImg);

	/// Opens a native file chooser where the user can slect the location and the name of the file they want to save,
	/// and sends its file directory and name to the controller
	void SaveImageData();

	/// Rescales the program window, dependant on the image that is being requested,
	/// and resets the layout of the buttons to match the window size
	/// @param w is the width of the image that is being shown
	/// @param h is the height of the image that is being shown
	void resizeWind(int w, int h);
	
private:
	/// DECLARE: an integer to note the amount of images in a vector 
	int imgCount;
	/// DECLARE: an integer to note the position of the current image in a vector
	int currentImg;
	/// DECLARE: an integer for the minimum width of the window
	int minWidth;
	/// DECLARE: an integer for the minimum height of the window
	int minHeight;
};

