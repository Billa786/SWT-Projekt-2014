#pragma once
#include "Observer.h"

ref class ObserverLabel //: public Observer
{
private:
	System::Windows::Forms::Label^ label;
public:
	ObserverLabel(System::Windows::Forms::Label^ labelTemp);
	void update();
};
