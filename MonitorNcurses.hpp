#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include "IMonitorDisplay.hpp"
# include <menu.h>
# include "Module.hpp"
# include "HostModule.hpp"

class MonitorNcurses : public IMonitorDisplay{
    public:
        MonitorNcurses();
        MonitorNcurses(MonitorNcurses const & src);
        virtual ~MonitorNcurses();
        MonitorNcurses & operator=(MonitorNcurses const & rhs);
        virtual void    init();
        void            initModules();
        virtual void    quit();
        int             getX();
        int             getY();
        void            setY(int);
        void            setX(int);
        void            play();
        void            update();
//        std::vector<Module *>     getModules();
        std::vector<Module *> _modules;
    protected:
        int                 _x;
        int                 _y;
};

#endif // MONITORNCURSES_HPP
