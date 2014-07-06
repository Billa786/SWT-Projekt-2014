#include "Controller.h"
#include "ObserverBar.h"
#include "ObserverGraph.h"
#include "ObserverText.h"

Controller::Controller()
{
	subject = new Subject();
    	timer = new QTimer(this);
	connect (timer, SIGNAL(timeout()), this, SLOT(applyChanges()));
	timer->setInterval(60000);
    	timer->start();
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
