#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include "IMonitorDisplay.hpp"

class MonitorNcurses : public IMonitorDisplay{
    public:
        MonitorNcurses();
        MonitorNcurses(MonitorNcurses const & src);
        virtual ~MonitorNcurses();
        MonitorNcurses & operator=(MonitorNcurses const & rhs);
        virtual void    init();
};

#endif // MONITORNCURSES_HPP
