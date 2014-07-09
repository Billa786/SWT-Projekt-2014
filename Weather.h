#pragma once
#include <string>
#include <iostream>
using namespace std;

struct weather
{
    string location;
    string temp;
};


class Weather
{
public:
    Weather();
    void set_weather(weather, int);
    void set_metaData(string, int);
    static weather arrWeather[6];
    static string metaData[2];
};
