#pragma once
#include "Subject.h"
#include <windows.h>
#include "ObserverBar.h"

class Controller
{
private:


public:
    Subject *subject;

    Controller();
	~Controller();
	void applyChanges();

};
