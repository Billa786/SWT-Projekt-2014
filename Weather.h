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
    static weather arrWeather[6];
};
