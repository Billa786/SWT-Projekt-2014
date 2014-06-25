#include "Controller.h"
#include "ObserverBar.h"
#include "ObserverGraph.h"
#include "ObserverLabel.h"

Controller::Controller(System::Windows::Forms::DataVisualization::Charting::Chart^ chartBar, System::Windows::Forms::DataVisualization::Charting::Chart^ chartGraph, System::Windows::Forms::Label^ labelTemp)
{
	subject = new Subject();
	ObserverLabel^ observerlabel = gcnew ObserverLabel(labelTemp);
	//subject->attach(*observerlabel);
	//ObserverBar *observerbar = new ObserverBar(labelTemp);
	//ObserverGraph *observergraph = new ObserverGraph();
	//subject->attach(observerbar);
	//subject->attach(observergraph);
}

Controller::~Controller()
{
	delete subject;
}

void Controller::applyChanges(System::Windows::Forms::Label ^ labelLocation)
{
	subject->download();
	subject->parse();
	subject->notify();
	//string str = subject->arrWeather[0].location;
	//System::String^ str2 = gcnew System::String(str.c_str());
	//labelLocation->Text = gcnew System::String(str.c_str());


	//labelLocation->Text = subject->arrWeather[0].location;
}
