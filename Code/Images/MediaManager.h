/// CLASS HEADER: MediaManager implements the IModel interface, which is responsible for loading a list of Images, created in ImageFactory, and returning them
/// Implementing interfaces, an example of polymorphism and programming to the interface.

#pragma once

#include "Images.h"
#include "IFactory.h"
#include "IMedia.h"
#include "Image.h"
#include "ImageFactory.h"
#include "IMediaManager.h"

#pragma comment (lib, "Libs/FreeImagePlusd.lib")
#pragma comment (lib, "Libs/FreeImaged.lib")

class MediaManager : public IModelT <string>, public IMediaManager
{
public:
	/// CONSTRUCTOR: to create a instances of 
	MediaManager() {};

	/// DESTRUCTOR: virtual destructor to prevent any memory leak
	virtual ~MediaManager() {};

	/// Load the media items pointed to by 'pathfilenames' into the 'Model':
	/// @param pathfilenames is a vector of strings; each string containing path/filename for an image file to be loaded
	/// (the vector should contain at least one string)
	/// @return the unique identifiers of the images that have been loaded as a vector<string>
	shared_ptr<vector<string>> load(vector<string> pathfilenames);

	/// Return a copy of the media item specified by 'key':
	/// @param key is the unique identifier for the image to be returned
	shared_ptr<IMedia> getMediaItem(string key);

	/// Return a media factory
	/// @return return type shared_ptr<ImageFactory>, returning a memory reference to the ImageFactory.
	virtual shared_ptr<ImageFactory> getmediaFactory();

	/// Return a image list
	/// @return return type shared_ptr<map<string, shared_ptr<IMedia>>>, returning a memory reference to the map storing the image references.
	virtual shared_ptr<map<string, shared_ptr<IMedia>>> getimageList();

private:
	/// ACCESS: changed to private, so no-one else has access, staying closed to mutation
	/// DECLARE: a shared pointer to an instance of an ImageFactory, holding a reference to an ImageFactory
	shared_ptr<ImageFactory>mediaFactory{ new ImageFactory() };
	/// DECLARE: a shared pointer to an instance of a map, that uses strings as identifiers to IMedia objects, holding a reference to the map
	shared_ptr<map<string, shared_ptr<IMedia>>> imageList{ new map<string, shared_ptr<IMedia>> };
};

