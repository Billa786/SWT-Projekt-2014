#pragma once
#include <list>
#include <iostream>
using namespace std;
#include "Observer.h"
//#include "Weather.h"


class Subject
{
private:
	list<Observer*> observer_list;
	list<Observer*>::iterator observer_list_iter;

public:
    Subject() {}
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify();
	void download();
	void parse();
};
