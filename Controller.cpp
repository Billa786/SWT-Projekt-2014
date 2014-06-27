#include "Controller.h"
#include "ObserverBar.h"
#include "ObserverGraph.h"
#include "ObserverText.h"

Controller::Controller()
{
	subject = new Subject();
}

Controller::~Controller()
{
	delete subject;
}

void Controller::applyChanges()
{
	subject->download();
	subject->parse();
	subject->notify();
}
