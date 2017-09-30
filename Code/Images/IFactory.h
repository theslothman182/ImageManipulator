/// INTERFACE: IFactory is an template, containing the template factory method, Create(...), that will be implemented by all factory classes
/// Template, an example of static polymorphism
/// Create(), an example of the factory pattern

#pragma once
#include "Images.h"

using namespace std;

template<class T> class IFactory /// should change to FactoryT for c++ standard naming
{
public:
	/// DESTRUCTOR: virtual destructor to prevent any memory leak
	virtual ~IFactory() {}

	/// Create a generic object using a 'pathfilename', and return it:
	/// @param pathFileName is a string containing the path/filename for an image file that is to be loaded.
	/// @return return type T is generic, and will be declared upon implementation.
	virtual T Create(string pathFileName) = 0;
};