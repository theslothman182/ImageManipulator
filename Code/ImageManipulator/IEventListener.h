///INTERFACE: The IeventListener interface implements the observer pattern and will be used when an event is fired from the model. Any object subscribing to this
/// interface will need a whenDataChanged method and will subscribe to the IEventPublisher
#pragma once
#include "ImageManipulator.h"
#include "IEventArgs.h"

class IEventListener
{
public:
	/// Receives the image with the changes made to it through events
	/// @param e is a memory reference to the EventArgs after the image has been manipulated
	virtual void whenDataChanged(shared_ptr<IEventArgs> e) = 0;
};