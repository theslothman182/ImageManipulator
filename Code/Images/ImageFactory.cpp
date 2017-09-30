/// CLASS IMPLEMENTATION: ImageFactory implements the IFactory(subject to change) template, and contains a factory method to create and return an object of type IMedia.
/// Implementing a Template and it's methods, an example of polymorphism, and programming to the interface/template
/// Create(...), an example of the factory pattern

#include "stdafx.h"
#include "ImageFactory.h"

/// Create an object of type IMedia that is pointed to using a 'pathfilename', and return the pointer:
/// @param pathFileName is a string containing the path/filename for an image file that is to be loaded.
/// @return the reference that is pointing to an IMedia object that has been loaded as a list of type char, using the string
shared_ptr<IMedia> ImageFactory::Create(string pathFileName)
{
	/// DECLARE: a shared pointer to an instance of Image, that will store a fipImage
	shared_ptr<Image> myImage{ new Image() };
	/// DECLARE: a shared pointer to an fipImage, which will hold a reference to a fipImage
	shared_ptr<fipImage> img{ new fipImage() };

	/// DECLARE: a list of char's that will store a string, holding the 'pathFileName'
	const char* imgFile = pathFileName.c_str();
	//cout << pathFileName;

	try
	{
		/// TRY: to load a fipImage using the converted 'pathFileName'
		img->load(imgFile);
		//cout << img->load(imgFile);
		/// IF: the 'pathFileName' does NOT match an item filepath
		if (img->load(imgFile) == FALSE)
		{
			/// THEN: throw an exception, we will call this exception 1
			throw 1;
		}

		/// POINT: image, a shared pointer declared within the Image class, at the memory refrece to the fipImage
		myImage->image = img;
		//cout << "Image loaded!";

	}
	/// CATCH: any exception thrown
	catch (int e)
	{
		/// IF: the exception is exception 1
		if (e == 1)
		{
			/// THEN: we know this is due to the filepath not existing, show a message box
			//cerr << "An exception has occured. Number " + e;
			MessageBox(NULL, L" An exception occurred. Exception Nr.1 \nFilepath does not exist", NULL, NULL);
			///RESET: Path Name
			pathFileName = "DefaultImage.jpg";
			imgFile = pathFileName.c_str();
			/// TRY: to load a fipImage using the converted 'pathFileName'
			img->load(imgFile);

			/// POINT: image, a shared pointer declared within the Image class, at the memory refrece to the fipImage
			myImage->image = img;
		}
		/// else/otherwise
		else
		{
			/// It was a seperate error
			MessageBox(NULL, L" An unknown error has occured ", NULL, NULL);
			//cerr << "An unknown error has occured.";
		}
	}
	///FLIP: image. Remove incompatibilities between FLTK and FreeImagePlus
	myImage->image->flipVertical();
	/// UPCAST: the Image shared pointer, so it may be accessed by an IMedia shared pointer
	shared_ptr<IMedia> mediaImg = dynamic_pointer_cast<IMedia>(myImage);

	/// RETURN: a reference to an IMedia object.
	return mediaImg;
}