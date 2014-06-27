#include "Weather.h"

Weather::Weather()
{

}

void Weather::set_weather(weather weather_struct, int index)
{
    arrWeather[index]=weather_struct;
}

weather Weather::arrWeather[6];
