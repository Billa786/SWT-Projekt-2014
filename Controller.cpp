#include "Controller.h"
#include "ObserverBar.h"
#include "ObserverGraph.h"
#include "ObserverText.h"

/*The constructor creates an object of type subject and initializes and starts the timer
  to call function applyChanges() every minute
*/
Controller::Controller()
{
	subject = new Subject();
    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(applyChanges()));
    timer->setInterval(60000);
    timer->start();
}
/*The destructor deletes the created object*/
Controller::~Controller()
{
	delete subject;
}
/*This function is called by timer and refreshs the GUI */
void Controller::applyChanges()
{
    bool successful;
    if(!(successful = subject->download()))
        return;

    if(!(successful = subject->parse()))
        return;
	subject->notify();
}
