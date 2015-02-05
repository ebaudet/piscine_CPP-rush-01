#include <iostream>

#include "MonitorQt.hpp"
#include "MonitorNcurses.hpp"



int main(int argc, char *argv[])
{
    if (argv[1]){
        MonitorNcurses display;

        display.init();
        display.play();
        display.quit();

        return 0;
    }
    else
    {
        MonitorQt display(argc, argv);

        display.init();
        display.play();
        display.quit();

        return display.getQA()->exec();
    }
}
