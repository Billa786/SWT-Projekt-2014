#pragma once
#include <string>
#include <iostream>
using namespace std;

/*Needed to save our weather data*/
struct weather
{
    string location;
    string temp;
};

/*Provides arrays for weather data to be accessable from everywhere in program.
  set methods allow to add structs of weather data easily.
*/
class Weather
{
public:
    Weather();
    void set_weather(weather, int);
    void set_metaData(string, int);
    static weather arrWeather[6];
    static string metaData[2];
};
