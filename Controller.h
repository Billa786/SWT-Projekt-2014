//using namespace System::Windows::Forms;
#pragma once
#include "Subject.h"
#include <windows.h>

ref class Controller
{
private:
	Subject *subject;

public:
	Controller(System::Windows::Forms::DataVisualization::Charting::Chart^, System::Windows::Forms::DataVisualization::Charting::Chart^, System::Windows::Forms::Label^);
	~Controller();
	void applyChanges(System::Windows::Forms::Label ^ labelLocations);

};
