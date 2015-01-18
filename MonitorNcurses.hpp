#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include <vector>
# include "IMonitorDisplay.hpp"
# include <menu.h>

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
        void            play();
        void            update();
    protected:
        int                 _x;
        int                 _y;
        std::vector<int>  modules;
};

#endif // MONITORNCURSES_HPP