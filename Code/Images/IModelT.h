/// INTERFACE: IModelT provides a public top-level interface to the library,
/// the library thus being viewed by the outside world as a 'Model'.
/// The 'Model' is used as 'smart' storage (ie a 'smart container' or 'collection') for a collection of images.
/// Each item in the container should have a unique identifier, which could be an int, string, or some other type; we use 'KeyType' as a placeholder for that type.
/// For example, if the underlying container is an STL vector, then the unique identifier would probably be an int.
/// You should, however, consider the benefits that other STL container classes have to offer.

/// The 'IMedia' Interface should be provided and implemented by the developer (ie you!).
/// This is an Interface to a media object wrapper, which (at this stage) should wrap an image provided by the FreeImagePlus library.
/// You will have been provided with these when completing the worksheet for Session 4, but you may have amended them during that session.



#pragma once
#include "Images.h"
#include "IMedia.h"


using namespace std;

template<typename KeyType> class IModelT
{

public:

	/// We always have a virtual destructor to prevent any possible memory leaks:
	virtual ~IModelT() {}

	/// Load the media items pointed to by 'pathfilenames' into the 'Model':
	/// @param pathfilenames is a vector of strings; each string containing path/filename for an image file to be loaded
	/// (the vector should contain at least one string)
	/// @return the unique identifiers of the images that have been loaded as a vector<KeyType>
	virtual shared_ptr<vector<KeyType>> load(vector<string> pathfilenames) = 0;

	/// Return a copy of the media item specified by 'key':
	/// @param key is the unique identifier for the image to be returned
	virtual shared_ptr<IMedia> getMediaItem(KeyType key) = 0;

	///virtual MediaManager& getInstance

};