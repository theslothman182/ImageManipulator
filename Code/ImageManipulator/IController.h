///INTERFACE: The IController interface hold implementation for the controller that is not in the IClick interface
#pragma once

class IController

{
public:
	/// makes the call to run the program
	virtual void Run() = 0;
};