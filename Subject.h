#pragma once
#include <list>
#include <iostream>
using namespace std;
#include "Observer.h"

class Subject
{
private:
	struct weather
	{
		string location;
		string temp;
	};
	list<weather>::iterator weather_list_iter;
	list<Observer*> observer_list;
	list<Observer*>::iterator observer_list_iter;

public:
	Subject() {};
	list<weather> weather_list;
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify();
	void download();
	void parse();
};
