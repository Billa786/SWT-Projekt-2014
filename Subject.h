#pragma once
#include <list>
#include <iostream>
using namespace std;
#include "Observer.h"

/* Provides lists to manage observers.
   Allows to add/remove observers and to notify each of them by call notify().
   Provides methods to download and parse the weather data.
*/
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
    bool download();
    bool parse();
};
