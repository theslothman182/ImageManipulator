/// INTERFACE: IMediaManager provides a public interface for any media manager
/// Interface, an example of dynamic polymorphism, and use of programming to the interface

#pragma once
#include "Images.h"
#include "ImageFactory.h"
#include "IMedia.h"
#include "IModelT.h"

using namespace std;

class IMediaManager
{
public:
	/// DESTRUCTOR: virtual destructor to prevent any memory leak
	virtual ~IMediaManager(){}

	/// Load the media items pointed to by 'pathfilenames' into the 'Model':
	/// @param pathfilenames is a vector of strings; each string containing path/filename for an image file to be loaded
	/// (the vector should contain at least one string)
	/// @return the unique identifiers of the images that have been loaded as a vector<string>
	virtual shared_ptr<vector<string>> load(vector<string> pathfilenames) = 0;

	/// Return a copy of the media item specified by 'key':
	/// @param key is the unique identifier for the image to be returned
	virtual shared_ptr<IMedia> getMediaItem(string key) = 0;

	/// Return a media factory
	/// @return return type shared_ptr<ImageFactory>, returning a memory reference to the ImageFactory.
	virtual shared_ptr<ImageFactory> getmediaFactory() = 0;

	/// Return an image list
	/// @return return type shared_ptr<map<string, shared_ptr<IMedia>>>, returning a memory reference to the map storing the image references.
	virtual shared_ptr<map<string, shared_ptr<IMedia>>> getimageList() = 0;

protected:
	/// PROTECTED: so that they are accessible to the MediaManager an other inheritants of IMediaManager, and no-one else, open for extension
	/// DECLARE: a shared pointer to an ImageFactory, holding a reference to an ImageFactory
	shared_ptr<ImageFactory> mediaFactory = 0;
	/// DECLARE: a shared pointer to a map, that uses strings as identifiers to IMedia objects, holding a reference to the map
	shared_ptr<map<string, shared_ptr<IMedia>>> imageList = 0;
};