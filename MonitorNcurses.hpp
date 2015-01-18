#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include "IMonitorDisplay.hpp"

class MonitorNcurses : public IMonitorDisplay{
    public:
        MonitorNcurses();
        MonitorNcurses(MonitorNcurses const & src);
        virtual ~MonitorNcurses();
        MonitorNcurses & operator=(MonitorNcurses const & rhs);
        virtual void    init();
        virtual void quit();
};

#endif // MONITORNCURSES_HPP
