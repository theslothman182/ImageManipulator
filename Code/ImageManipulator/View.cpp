#include "stdafx.h"
#include "View.h"
#include <FL/Fl_Native_File_Chooser.H>

/// CONSTRUCTOR: creates an instance of
View::View() : Fl_Double_Window(700, 450, "ImageTest") 
{
	/// SET: the minimum width and height for the window
	minWidth = 700;
	minHeight = 320;
	
	{
		/// INSTANTIATE: the display box using the minimum height and width
		displayBox = shared_ptr<Fl_Box>(new Fl_Box(0, 0, minWidth, minHeight));
	}

	/// DELCARE: 2 integers to store the displacement of the display box on the x and y axis
	int dispX = displayBox->x() + displayBox->w();
	int dispY = displayBox->y() + displayBox->h();

	{
		/// INSTANTIATE: the back button
		backButton = shared_ptr<Fl_Button>(new Fl_Button(30, dispY, 120, 35, "Back"));
		/// SET: its callback method
		backButton->callback((Fl_Callback*)DoPrevious, this);
	}
	{
		/// INSTANTIATE: the load button
		loadButton = shared_ptr<Fl_Button>(new Fl_Button(205, dispY, 120, 35, "Load"));
		loadButton->callback((Fl_Callback*)DoLoad, this);
	}
	{
		/// INSTANTIATE: the save button
		saveButton = shared_ptr<Fl_Button>(new Fl_Button(380, dispY, 120, 35, "Save"));
		saveButton->callback((Fl_Callback*)DoSave, this);
	}
	{
		/// INSTANTIATE: the next button
		nextButton = shared_ptr<Fl_Button>(new Fl_Button(555, dispY, 120, 35, "Next"));
		nextButton->callback((Fl_Callback*)DoNext, this);
	}
	{
		/// INSTANTIATE: the flip verically button
		flipVerticalButton = shared_ptr<Fl_Button>(new Fl_Button(0, dispY + loadButton->h(), 140, 35, "Flip Vertical"));
		flipVerticalButton->callback((Fl_Callback*)DoFlipVertical, this);
	}
	{
		/// INSTANTIATE: the rotate clockwise button
		rotateClockButton = shared_ptr<Fl_Button>(new Fl_Button(140, dispY + loadButton->h(), 140, 35, "Rotate Clockwise"));
		rotateClockButton->callback((Fl_Callback*)DoRotateClock, this);
	}
	{
		/// INSTANTIATE: the rotate anti-clockwise button
		rotateAntiButton = shared_ptr<Fl_Button>(new Fl_Button(280, dispY + loadButton->h(), 140, 35, "Rotate Anti-Clockwise"));
		rotateAntiButton->callback((Fl_Callback*)DoRotateAnti, this);
	}
	{
		/// INSTANTIATE: the scale button
		scaleButton = shared_ptr<Fl_Button>(new Fl_Button(420, dispY + loadButton->h(), 140, 35, "Scale"));
		scaleButton->callback((Fl_Callback*)DoScale, this);
	}
	{
		/// INSTANTIATE: the flip horizontally button
		flipHorizontalButton = shared_ptr<Fl_Button>(new Fl_Button(560, dispY + loadButton->h(), 140, 35, "Flip Horizontal"));
		flipHorizontalButton->callback((Fl_Callback*)DoFlipHorizontal, this);
	}
	{
		/// INSTANTIATE: the ratation value input
		Rotation = shared_ptr<Fl_Value_Input>(new Fl_Value_Input(220, dispY + loadButton->h() + scaleButton->h(), 120, 40, "Rotation: "));
	}
	{
		/// INSTANTIATE: the width value input
		Width = shared_ptr<Fl_Value_Input>(new Fl_Value_Input(400, dispY + loadButton->h() + scaleButton->h(), 120, 40, "Width: "));
	}
	{
		/// INSTANTIATE: the height value input
		Height = shared_ptr<Fl_Value_Input>(new Fl_Value_Input(575, dispY + loadButton->h() + scaleButton->h(), 120, 40, "Height: "));
	}

	/// DECLARE: the end to the window construction
	end();
	/// SHOW: the window
	show();

	/// SET: the image count to -1, below the minimum vector length
	imgCount = -1;
}

/// DESTRUCTOR: to prevent any memory leak
View::~View()
{
}

/// Receives the image with the changes made to it through events
/// @param e is a memory reference to the EventArgs after the image has been manipulated
void View::whenDataChanged(shared_ptr<IEventArgs> e)
{
	/// SET: the current image to match the index in model
	imgCount = e->getCount();
	/// CALL: the method to display the image received from eventArgs
	displayImage(e->image());
}

/// Sets the controller that will handle all of the events called
/// @param pctrl is a memory reference to the controller that is being used
void View::setClick(shared_ptr<IClick> pctrl)
{
	/// INSTANTIATE: the controller
	ctrl = pctrl;
}

/// Makes a call for the current image to be saved
/// @param *w
/// @param *data
void View::DoSave(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// CALL: the mthod to save the image
	obj->SaveImageData();
}

/// Makes a call to load an image
/// @param *w
/// @param *data
void View::DoLoad(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// CALL: the method to load the image
	obj->PassValue();
}

/// Makes a call to show the next image in the vector
/// @param *w
/// @param *data
void View::DoNext(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request for the method to move to the next image in the vector
	obj->SendNextCall();

}

/// Makes a call to show the previous image in the vector
/// @param *w
/// @param *data
void View::DoPrevious(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to move to the previous image in the vector
	obj->SendPreviousCall();

}

/// Makes a call to flip the current image horizontally
/// @param *w
/// @param *data
void View::DoFlipHorizontal(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to flip the image horizontally
	obj->SendFlipHorizontalCall();
}

/// Makes a call to flip the current image vertically
/// @param *w
/// @param *data
void View::DoFlipVertical(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to flip the image vertically
	obj->SendFlipVerticalCall();
}

/// Makes a call to rotate the current image clockwise
/// @param *w
/// @param *data
void View::DoRotateClock(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to make the image rotate clockwise by the set amount
	obj->SendRotateValues(1);
}

/// Makes a call to rotate the current image anti-clockwise
/// @param *w
/// @param *data
void View::DoRotateAnti(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to make the image rotate anti-clockwise by the set amount
	obj->SendRotateValues(0);
}

/// Makes a call to scale the current image
/// @param *w
/// @param *data
void View::DoScale(Fl_Widget *w, void *data)
{
	/// CREATE: a view object
	View *obj = (View*)data;
	/// SEND: a request the method to scale the images height and width by the set amount
	obj->PassScaleValue();
}

/// Sends the request to show the next image in the vector to the controller
void View::SendNextCall()
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to move to the next image in the vector through the controller
		ctrl->handleNextClick(imgCount);
}

/// Sends the request to show the previous image in the vector to the controller
void View::SendPreviousCall()
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to move to the previous image in the vector through the controller
		ctrl->handlePreviousClick(imgCount);
}

/// Sends the request to flip the current image, horizontally, to the controller
void View::SendFlipHorizontalCall()
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to flip the image horizontally through the controller
		ctrl->handleFlipHorizontalClick(imgCount);
}

/// Sends the request to flip the current image, vertically, to the controller
void View::SendFlipVerticalCall()
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to flip the image horizontally through the controller
		ctrl->handleFlipVerticalClick(imgCount);
}

/// Sends the request to rotate the current image, clockwise, to the controller, using the value for rotation given
/// @param val the value amount to rotate the image by
void View::SendRotateClockCall(int val)
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to rotate the image clockwise through the controller
		ctrl->handleRotateClockClick(imgCount, val);
}

/// Sends the request to rotate the current image, anti-clockwise, to the controller, using the value for rotation given
/// @param val the value amount to rotate the image by
void View::SendRotateAntiCall(int val)
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to rotate the image anti-clockwise through the controller
		ctrl->handleRotateAntiClick(imgCount, val);
}

/// Sends the request to scale the current image to the controller, using the values for height and width given
/// @param width the value amount to scale the width of the image by
/// @param width the value amount to scale the height of the image by
void View::SendScale(int width, int height)
{
	/// IF: there is at least 1 image
	if (imgCount != -1)
		/// HANDLE: the request to scale the image through the controller
		ctrl->handleScaleClick(imgCount, width, height);
}

/// Shows the requested image in the display box
/// @param pImg is a memory reference to the image that is to be shown
void View::displayImage(shared_ptr<IMedia> pImg)
{
	/// DOWNCAST: a shared pointer of type IMedia, so it may be accessed as an object of type Image
	shared_ptr<Image> img = dynamic_pointer_cast<Image>(pImg);
	/// DECLARE: a an integer to store the width of the image
	int width = 0;
	/// DECLARE: a an integer to store the height of the image
	int height = 0;

	/// IF: the width of the image is more than the set minimum width
	if (img->image->getWidth() > minWidth)
	{
		/// STORE: the width of the image
		width = img->image->getWidth();
	}
	else
	{
		/// STORE: the minimum width
		width = minWidth;
	}
	/// IF: the height of the image is more than the set minimum height
	if (img->image->getHeight() > minHeight)
	{
		/// STORE: the height of the image
		height = img->image->getHeight();
	}

	else
	{
		/// STORE: the minimum height
		height = minHeight;
	}

	/// RESIZE: the window using image width and height
	resizeWind(width, height);

	/// SET: the image to be shown
	displayBox->image(new Fl_RGB_Image(img->image->accessPixels(), img->image->getWidth(), img->image->getHeight(), img->numberOfChannels()));
	/// HIDE: the display box, whilst the changes are being made
	displayBox->hide();
	/// SHOW: the display box
	displayBox->show();
}

/// Rescales the program window, dependant on the image that is being requested,
/// and resets the layout of the buttons to match the window size
/// @param w is the width of the image that is being shown
/// @param h is the height of the image that is being shown
void View::resizeWind(int w, int h)
{
	/// RESIZE: the display box for the image, using the width and height of the image
	displayBox->resize(0, 0, w, h);
	/// RESIZE: the window of the program, using the image width and height, leaving room for the button layout
	resize(x(), y(), w, h + 140);

	/// DELCARE: 2 integers to store the displacement of the display box on the x and y axis
	int dispX = displayBox->x() + displayBox->w();
	int dispY = displayBox->y() + displayBox->h();

	/// RESET: the positions of each button, and input, on the y axis
	backButton->resize(30, dispY, 120, 35);
	loadButton->resize(205, dispY, 120, 35);
	saveButton->resize(380, dispY, 120, 35);
	nextButton->resize(555, dispY, 120, 35);
	flipVerticalButton->resize(0, dispY + loadButton->h(), 140, 35);
	rotateClockButton->resize(140, dispY + loadButton->h(), 140, 35);
	rotateAntiButton->resize(280, dispY + loadButton->h(), 140, 35);
	scaleButton->resize(420, dispY + loadButton->h(), 140, 35);
	flipHorizontalButton->resize(560, dispY + loadButton->h(), 140, 35);
	Rotation->resize(220, dispY + loadButton->h() + scaleButton->h(), 120, 40);
	Width->resize(400, dispY + loadButton->h() + scaleButton->h(), 120, 40);
	Height->resize(575, dispY + loadButton->h() + scaleButton->h(), 120, 40);
}

/// Receives the images requested by the user, then sends them to the controller to be loaded 
void View::PassValue()
{
	/// DECLARE: a vector of strings for the images wanted to load
	vector<string> imageFiles = getInput("Please choose images to load");
	/// SEND: the request to load an image to the controller
	ctrl->handleLoadClick(imageFiles);
}

/// Sends the value that the image is to be rotated by to the controller
/// @param dir an integer symbolizing the direction of the rotation, 0 = anti-clockwise, 1 = clockwise
void View::SendRotateValues(int dir)
{
	/// IF: dir is set to 0
	if (dir == 0)
	{
		/// SEND: the value to move the image anti-clockwise
		SendRotateAntiCall(Rotation->value());
	}
	else
	{
		/// SEND: the value to move the image clockwise
		SendRotateClockCall(Rotation->value());
	}
}

/// Sends the value that the image is to be scaled by to the controller
void View::PassScaleValue()
{
	/// SEND: the values for the width and height to scale the image
	SendScale(Width->value(), Height->value());
}

/// Opens a file chooser window, where the user can select the images they want to load
/// @param prompt the message header to the file chooser
/// @return the vecotr<string> containing the names of the images to be loaded
vector<string> View::getInput(string prompt)
{
	/// CREATE: a vector<string> to hold the return value, call it rtnVal:
	vector<string> rtnVal;

	/// INSTANTIATE: file chooser window, call it fileInput:
	Fl_File_Chooser fileInput = Fl_File_Chooser(".", "*", Fl_File_Chooser::MULTI, prompt.c_str());

	/// SHOW: fileInput:
	fileInput.show();

	/// WAIT: for user input:
	while (fileInput.shown())
	{
		Fl::wait();
	}

	/// RETURN: the entered text as a single string:
	if (fileInput.count() > 0)
	{
		/// RETURN: the entered text as a single string:
		if ((NULL != fileInput.value()) && (0 < fileInput.count()))
		{
			/// ITERATE: through filenames collected:
			for (int i = 0; i < fileInput.count(); i++)
			{
				/// CONVERT: each filename to a string and push onto rtnVal:
				string rtn;
				rtn.assign(fileInput.value(i + 1));
				rtnVal.push_back(rtn);
			}
		}
	}
	else
	{
		/// PUSH BACK: a blank string
		rtnVal.push_back(" ");
	}

	/// RETURN: the vector of stings
	return rtnVal;
}

/// Opens a native file chooser where the user can slect the location and the name of the file they want to save,
/// and sends its file directory and name to the controller
void View::SaveImageData()
{
	/// DECLARE: a shared pointer to a native file chooser
	shared_ptr<Fl_Native_File_Chooser> chsr{ new Fl_Native_File_Chooser(4) };
	/// SHOW: the native file chooser
	chsr->show();

	/// DECLARE: a string to store the file directory and file name chosen by the user
	string chosenName = chsr->filename();
	/// DECLARE: a string to add the png filetype extension
	string png = ".png";
	/// DECLARE: a string to concatenate the file directory and the extension
	string saveName = chosenName + png;

	/// SEND: the controller the string containing the save file details
	ctrl->handleSaveClick(1,saveName);
}
