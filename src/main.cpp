#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"



int main()
{
    std::cout << "Hellow World" << std::endl;

    Button button1(27); //27번 핀이 power버튼이라고 의미를 부여함
    Led led1(25);
    Listener listener(&button1, &led1);

    while (1)
    {
        listener.checkEvent();
        delay(50);
    }
    return 0;
}
