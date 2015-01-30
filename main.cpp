#include <iostream>

#include "MonitorQt.hpp"
#include "MonitorNcurses.hpp"
#include "Module.hpp"
#include "HostModule.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"


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

        display.addModule(new HostModule());
        display.addModule(new OsModule());
        display.addModule(new DateModule());
        display.init();
        display.play();
        display.quit();

        return display.getQA()->exec();
    }
}
