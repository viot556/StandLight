#include "View.h"
#include <wiringPi.h>

View::View(Led *led)
{
    light = led;
    lightState = LIGHT_OFF;
}

View::~View()
{  

}

void View::updateState(std::string strBtn)
{
    switch (lightState)
    {
    case LIGHT_OFF:
    if(strBtn == "StateOn"){
        lightState = LIGHT_ON;
    }
    break;
    case LIGHT_ON:
    if(strBtn == "StateOff"){
        lightState = LIGHT_OFF;
    }    
    break;
    }
}

void View::lightView()
{
    switch (lightState)
    {
    case LIGHT_OFF:
        lightOff();
        break;

    case LIGHT_ON:
        lightOn();
        break;
    }
}

void View::lightOn()
{
    static int prevTime = 0;

    if (millis() - prevTime < 300)    // millis = 1 msec 씩 계속 증가하는 함수
    return;
    prevTime = millis();   
    light->Toggle();
}

void View::lightOff()
{
    light->Off();
}

