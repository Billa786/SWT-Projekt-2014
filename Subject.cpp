#include "Subject.h"
//#include "../curlpp/curlpp-0.7.3/include/curlpp/cURLpp.hpp"
//#include <curlpp/cURLpp.hpp>
//#include <curlpp/Easy.hpp>
//#include <curlpp/Options.hpp>
//#define CURL_STATICLIB
//#include <curlpp\cURLpp.hpp>
//#include <curlpp\Easy.hpp>
//#include <curlpp\Types.hpp>
#include <windows.h>
#include <string>
#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")
#include <fstream>
#include <iostream>
using namespace std;



void Subject::attach(Observer *observer)
{
	observer_list.insert(observer_list.end(), observer);
}

void Subject::detach(Observer *observer)
{
	observer_list.remove(observer);
}

void Subject::notify()
{
	for(observer_list_iter = observer_list.begin(); observer_list_iter != observer_list.end(); observer_list_iter++)
		(*observer_list_iter)->update();
}

void Subject::download()
{ 
	/* Download data */
	HRESULT hr;

	hr = URLDownloadToFile(NULL,TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"), TEXT("D:\\test.txt"), 0, NULL);

    if(!SUCCEEDED(hr)) {
        string mMessage = "Download failed";
        MessageBox(NULL, TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"), TEXT("D:\\test.txt"), MB_OK | MB_ICONERROR);
    }
}

void Subject::parse()
{
	int i=0;
	string line;
	string parsedLine;
	ifstream dataStream ("D:\\test.txt");
	weather tempData;

	while(!dataStream.eof())
	{
		/* clear structure */
		tempData.location = "";
		tempData.temp = "";

		getline(dataStream, line);

		/* return if eof is reached */
		if(line == "")
			return;

		/* lines with "#" are comments */
		if(line[0] == 35)
			continue;

		/* parse location */
		for( i=0; line[i] != ',' ; i++)
		{
			tempData.location = tempData.location + line[i];
		}

		/* parse temp */
		for( i=i+2; i<line.size() ; i++)
		{
			tempData.temp = tempData.temp + line[i];
		}

		/* insert structure to list */
		weather_list.insert(weather_list.end(), tempData);
	}



}
