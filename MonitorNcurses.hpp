#ifndef MONITORNCURSES_H
# define MONITORNCURSES_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ncurses.h>
# include <string.h>
# include <algorithm>

# include "IMonitorDisplay.hpp"
# include "Module.hpp"
# include "HostModule.hpp"
# include "OsModule.hpp"
# include "DateModule.hpp"
# include "CpuModule.hpp"
# include "RamModule.hpp"
# include "NetworkModule.hpp"

class MonitorNcurses : public IMonitorDisplay{
    public:
        MonitorNcurses();
        MonitorNcurses(MonitorNcurses const & src);
        virtual ~MonitorNcurses();
        MonitorNcurses & operator=(MonitorNcurses const & rhs);
        virtual void    init();
        void            initModules();
                void            initAttrModules(Module *module);
        virtual void    quit();
        int             getX();
        int             getY();
        void            setY(int);
        void            setX(int);
        void            play();
        void            update();
        void            displayAlgo(struct s_mod *);
//        std::vector<Module *>     getModules();
//        std::vector<Module *> _modules;
        std::vector<struct s_mod *>    _mod;
    protected:
        int                 _x;
        int                 _y;
};

struct           s_mod
{
    Module      *module;
    WINDOW      *win;
};

void            drawModule(struct s_mod *);

#endif // MONITORNCURSES_HPP
