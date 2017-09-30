/// CLASS IMPLEMENTATION: MediaManager implements the IModel interface, which is responsible for loading a list of Images, created in ImageFactory, and returning them
/// Implementing interfaces, an example of polymorphism and programming to the interface.

#include "stdafx.h"
#include "MediaManager.h"

/// Return a media factory
/// @return return type shared_ptr<ImageFactory>, returning a memory reference to the ImageFactory.
shared_ptr<ImageFactory> MediaManager::getmediaFactory()
{
	return mediaFactory;
}

/// Return a image list
/// @return return type shared_ptr<map<string, shared_ptr<IMedia>>>, returning a memory reference to the map storing the image references.
shared_ptr<map<string, shared_ptr<IMedia>>> MediaManager::getimageList()
{
	return imageList;
}

/// Load the media items pointed to by 'pathfilenames' into the 'Model':
/// @param pathfilenames is a vector of strings; each string containing path/filename for an image file to be loaded
/// (the vector should contain at least one string)
/// @return the unique identifiers of the images that have been loaded as a vector<string>
shared_ptr<vector<string>> MediaManager::load(vector<string> pathfilenames)
{
	/// DECLARE: a shared pointer to an instance of IMedia, instantiate as Image
	shared_ptr<IMedia> mediaImg{ new Image() };
	/// DECLARE: a shared pointer to a vecotr of strings, this will contain all the unique identifiers to Images
	shared_ptr<vector<string>> keyList{ new vector<string> };
	/// DECLARE: a string to contain a single key
	string key = "0";
	//cout << pathfilenames.size();
	/// FOR: every item in 'pathfilenames'
	for (int i = 0; i < pathfilenames.size(); i++)
	{
		/// STORE: an IMedia reference, by creating one in the ImageFactory, using the pathfilename
		mediaImg = mediaFactory->Create(pathfilenames[i]);
		/// SET: key to be the 'pathfilename'
		key = pathfilenames[i];
		//cout << key;
		/// ADD: the unique identifier and the Image to the map, 'imageList'
		imageList->insert(pair<string, shared_ptr<IMedia>>(key, mediaImg));
		/// ADD: the unique identifier to a seperate vector, only containing strings, 'keyList'
		keyList->push_back(key);
	}
	/// RETURN: the vector of unique id's
	return keyList;
}

/// Return a copy of the media item specified by 'key':
/// @param key is the unique identifier for the image to be returned
shared_ptr<IMedia> MediaManager::getMediaItem(string key)
{
	/// DECLARE: a shared pointer to an instance of IMedia, instantiate as Image
	shared_ptr<IMedia> img{ new Image() };

	try
	{
		/// TRY: to find the identifier in the map/list
		img = imageList->find(key)->second;
		/// IF: the identifier could not be found
		
		if (imageList->find(key) == imageList->end())
		{
			/// THROW: an exception, we will call this exception 3
			throw 3;
		}
	}
	/// CATCH: any exception thrown
	catch (int e)
	{
		/// IF: the exeption is exception 3
		if (e == 3)
		{
			/// THEN: we know this is due to not finding the identifier, show a message box
			cerr << "An exception occured. Number " << e << " Could not find the image ID.";
			
		}
		/// else/otherwise
		else
		{
			/// It was a seperate error
			cerr << "An Exception has occured.";
		}
	}
	
	/// RETURN: a reference to the image, IMedia
	return img;
}