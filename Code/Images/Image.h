/// CLASS: Image implements the IMedia interface, and is a wrapper for a 'fipImage' instance

#pragma once

#include "Images.h"
#include "IMedia.h"

using namespace std;

class Image : public IMedia
{
private:
	/// DECLARE a reference to the raw data, call it _rawData:
	unsigned char* _rawData;

public:
	/// DECLARE a reference to the fipImage object, call it image:
	shared_ptr<fipImage> image;

	/// METHOD: Initialise private data:
	void Initialise()
	{
		_rawData = image->accessPixels();
	}

	/// METHOD: return a RAW pointer to the raw media data (ie pixels):
	unsigned char* rawData()
	{
		return _rawData;
	};


	/// METHOD: return the number of channels in the contained image:
	int numberOfChannels()
	{
		/// DECLARE an unsigned short to hold the return value (either 1, 3, or 4), call it rtnVal:
		int rtnVal = 1;

		/// SET rtnVal = 4 if (and only if) the 'FREE_IMAGE_COLOR_TYPE' of image = 4:
		unsigned int bpp = image->getBitsPerPixel();
		FREE_IMAGE_COLOR_TYPE colorType = image->getColorType();
		if (bpp ==24)		
		{
			rtnVal = 3;
		}
		else if (bpp == 32 && colorType == 4)
		{
			rtnVal = 4;
		}

		return rtnVal;
	};
};