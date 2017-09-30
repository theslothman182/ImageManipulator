/// INTERFACE: IMedia provides a public interface for any Media object
/// Implementations should 'wrap' a specific media objects

#pragma once

#include "ImageManipulator.h"

using namespace std;


struct IMedia
{
public:

	virtual ~IMedia() {}

	/// METHOD: Initialise private data:
	virtual void Initialise() = 0;

	/// METHOD: return a RAW pointer to the raw media data:
	virtual unsigned char* rawData() = 0;
};