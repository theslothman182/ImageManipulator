/// CLASS HEADER: ImageFactory implements the IFactory(subject to change) template, and contains a factory method to create and return an object of type IMedia.
/// Implementing a Template and it's methods, an example of polymorphism, and programming to the interface/template
/// Create(...), an example of the factory pattern

#pragma once
#include "ImageManipulator.h"
#include "IFactory.h"
#include "IMedia.h"
#include "Image.h"

using namespace std;

class ImageFactory : public IFactory<shared_ptr<IMedia>>
{
public:
	/// CONSTRUCTOR: to create a instances of ImageFactory
	ImageFactory() {}

	/// DESTRUCTOR: virtual destructor to prevent any memory leak
	virtual ~ImageFactory() {}

	/// Create an object of type IMedia that is pointed to using a 'pathfilename', and return the pointer:
	/// @param pathFileName is a string containing the path/filename for an image file that is to be loaded.
	/// @return the reference that is pointing to an IMedia object that has been loaded as a list of type char, using the string
	shared_ptr<IMedia> Create(string pathFileName);
};




