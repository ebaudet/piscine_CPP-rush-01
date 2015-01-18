#include "MonitorNcurses.hpp"

MonitorNcurses::MonitorNcurses()
{

}

MonitorNcurses::MonitorNcurses(MonitorNcurses const & src)
{
    *this = src;
}



MonitorNcurses::~MonitorNcurses()
{

}

MonitorNcurses &    MonitorNcurses::operator=(MonitorNcurses const & rhs){
    (void)rhs;
    return *this;
}

void    MonitorNcurses::init(){
    return ;
}
