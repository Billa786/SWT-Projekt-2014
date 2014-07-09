#include "Weather.h"

Weather::Weather()
{

}

void Weather::set_weather(weather weather_struct, int index)
{
    arrWeather[index]=weather_struct;
}

void Weather::set_metaData(string metaDataString, int index)
{
    metaData[index]=metaDataString;
}

weather Weather::arrWeather[6];
string Weather::metaData[2];
