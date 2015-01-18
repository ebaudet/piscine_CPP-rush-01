#include <iostream>

#include "MonitorQt.hpp"

#include "MonitorNcurses.hpp"
#include "IMonitorDisplay.hpp"
#include "Module.hpp"
#include "HostModule.hpp"


int main(int argc, char *argv[])
{
    if (argv[1]){
        MonitorNcurses w;
        w.init();
        w.play();
        w.quit();
        return 0;
    }
    else
    {
        MonitorQt qt(argc, argv);
        qt.init();
        qt.play();
        qt.quit();

        return qt.getQA()->exec();
    }
}
