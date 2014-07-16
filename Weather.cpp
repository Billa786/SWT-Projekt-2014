#include "Weather.h"

Weather::Weather()
{

}

/*A set method to get the data in the array*/
void Weather::set_weather(weather weather_struct, int index)
{
    arrWeather[index]=weather_struct;
}

/*A set method to get the metadata in the array*/
void Weather::set_metaData(string metaDataString, int index)
{
    metaData[index]=metaDataString;
}

weather Weather::arrWeather[6];
string Weather::metaData[2];
