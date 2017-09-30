///IEventPublisher is the interface that is responsible for storing a list of IEventListeners and also for crreating the
///IEventArgs object that will be sent to each of the listeners through this publisher
#pragma once
#include "ImageManipulator.h"
#include "IEventListener.h"

class IEventPublisher
{
public:
	/// subscribes a listener to the model
	/// @param eL the listener that wants to subscribe to the event
	virtual void subscribe(shared_ptr<IEventListener> eL) = 0;

	/// Fires the event, sending the requested changes back to the View
	/// @param img a memory reference to the IMedia object to be shown
	/// @param count an integer to record the current images position in the vector
	virtual void fireEvent(shared_ptr<IMedia> img, int count) = 0;
};
