#include "Subject.h"
#include <windows.h>
#include <string>
#include <urlmon.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <WinInet.h>
#include "Weather.h"


/*Adds a new observer to observerlist*/
void Subject::attach(Observer *observer)
{
	observer_list.insert(observer_list.end(), observer);
}

/*Removes an observer of the observerlist*/
void Subject::detach(Observer *observer)
{
	observer_list.remove(observer);
}

/*Calls update function of every observer in the observerlist*/
void Subject::notify()
{
	for(observer_list_iter = observer_list.begin(); observer_list_iter != observer_list.end(); observer_list_iter++)
        (*observer_list_iter)->update();
    cout << "called notify()" << endl;
}

/*Downloads the data from the internet to a file using the WinInet library*/
bool Subject::download()
{ 
	/* Download data */
	HRESULT hr;
	DeleteUrlCacheEntry(TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
    hr = URLDownloadToFile(NULL,TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"), TEXT("C:\\Users\\Qazi\\Desktop\\Temperaturdaten.txt"), 0, NULL);

    if(!SUCCEEDED(hr))
    {
        MessageBox(NULL, TEXT("Fehler beim Download der Daten. Internetverbindung pruefen."), TEXT("Fehlermeldung"), MB_OK | MB_ICONERROR);
        return false;
    }
    cout << "download finished" << endl;
    return true;
}

/*Function for parsing the downloaded data
  and saves them into the arrWeather and metaData arrays
*/
bool Subject::parse()
{
    /*Loop variables*/
    unsigned int i=0, j=0, k=0;
    Weather weatherData;
	string line;
    ifstream dataStream ("C:\\Users\\Qazi\\Desktop\\Temperaturdaten.txt");
    if(!dataStream.is_open())
    {
        MessageBox(NULL, TEXT("Fehler beim Oeffnen der Datei."), TEXT("Fehlermeldung"), MB_OK | MB_ICONERROR);
        return false;
    }
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
            return true;
        }

        /* lines with "#" are comments/metadata */
		if(line[0] == 35)
        {
            if(k>1)
            {
                MessageBox(NULL, TEXT("Mehr als zwei Zeilen mit Metadaten vorhanden."), TEXT("Fehlermeldung"), MB_OK | MB_ICONERROR);
                return false;
            }
            weatherData.set_metaData(line, k);
            k++;
			continue;
        }

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
        if(j>5)
        {
            MessageBox(NULL, TEXT("Mehr als 6 Orte mit Temperaturdaten vorhanden."), TEXT("Fehlermeldung"), MB_OK | MB_ICONERROR);
            return false;
        }
        weatherData.set_weather(tempData, j);
		j++;
	}
    return true;
}
