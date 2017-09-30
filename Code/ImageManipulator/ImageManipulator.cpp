// ImageManipulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImageManipulator.h"
#include "View.h"
#include "Model.h"
#include "Controller.h"

int main()
{
	/// DECLARE: and instantiate a new View object
	shared_ptr<IView> gui{ new View() };
	/// DECLARE: and instantiate a new Model object
	shared_ptr<IModel> mod{ new Model() };
	/// DECLARE: and instantiate a new Controller object
	shared_ptr<IController> ctrl{ new Controller(gui, mod) };
	/// CAST: the Controller so it may be used as an object of IClick
	shared_ptr<IClick> cCtrl = dynamic_pointer_cast<IClick>(ctrl);
	/// SET: the Controller in the View
	gui->setClick(cCtrl);
	/// RUN: the program
	ctrl->Run();
}

