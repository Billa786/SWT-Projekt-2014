#include <iostream>
using namespace std;
#include <WinInet.h>
//#pragma comment(lib, "Wininet.lib")
#include "Weather.h"



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
    cout << "called notify()" << endl;
}

void Subject::download()
{ 
	/* Download data */
	HRESULT hr;
	DeleteUrlCacheEntry(TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
    hr = URLDownloadToFile(NULL,TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"), TEXT("C:\\Users\\Qazi\\Desktop\\Temperaturdaten.txt"), 0, NULL);

    if(!SUCCEEDED(hr)) {
        string mMessage = "Download failed";
        MessageBox(NULL, TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"), TEXT("C:\\Users\\Qazi\\Desktop\\Temperaturdaten.txt"), MB_OK | MB_ICONERROR);
    }
    cout << "download finished" << endl;
}

void Subject::parse()
{
    unsigned int i=0, j=0;
    Weather weatherData;
	string line;
	string parsedLine;
    ifstream dataStream ("C:\\Users\\Qazi\\Desktop\\Temperaturdaten.txt");
	weather tempData;

	while(!dataStream.eof())
	{
		/* clear structure */
		tempData.location = "";
		tempData.temp = "";

		getline(dataStream, line);

		/* return if eof is reached */
		if(line == "")
        {
            cout << "parsing finished" << endl;
			return;
        }

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
		//weather_list.insert(weather_list.end(), tempData);
        //Weather::arrWeather[j]=tempData;

        weatherData.set_weather(tempData, j);
        //weatherData.arrWeather[j]=tempData;
		j++;
	}


}
