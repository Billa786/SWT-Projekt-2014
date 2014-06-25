#include "ObserverLabel.h"

ObserverLabel::ObserverLabel(System::Windows::Forms::Label^ labelTemp)
{
	label = labelTemp;
}


void ObserverLabel::update()
{
	// update label
	//label->Text = "test";
}
