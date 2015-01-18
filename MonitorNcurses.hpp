#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include <vector>
# include "IMonitorDisplay.hpp"

template <typename T>
class MonitorNcurses : public IMonitorDisplay{
    public:
        MonitorNcurses();
        MonitorNcurses(MonitorNcurses const & src);
        virtual ~MonitorNcurses();
        MonitorNcurses & operator=(MonitorNcurses const & rhs);
        virtual void    init();
        virtual void    quit();
        int             getX();
        int             getY();
        void            setY(int);
        void            setX(int);
    protected:
        int                 _x;
        int                 _y;
        std::vector<T>  modules;
};

#endif // MONITORNCURSES_HPP
