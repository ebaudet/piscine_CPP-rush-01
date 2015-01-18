#include "MonitorNcurses.hpp"

MonitorNcurses::MonitorNcurses(){
    return ;
}

MonitorNcurses::MonitorNcurses(MonitorNcurses const & src)
{
    *this = src;
}



MonitorNcurses::~MonitorNcurses()
{
    return ;
}

MonitorNcurses &    MonitorNcurses::operator=(MonitorNcurses const & rhs){
    (void)rhs;
    return *this;
}

void    MonitorNcurses::init(){
    initscr();
//    getmaxyx(stdscr, this->_heigth, this->_width);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(25);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
    refresh();
    return ;
}
void    MonitorNcurses::quit(){
    endwin();
    std::cout << "this is the end" << std::endl;
    exit(0);
}

int     MonitorNcurses::getX(){
    return this->_x;
}

int     MonitorNcurses::getY(){
    return this->_y;
}

void    MonitorNcurses::setX(int x){
    this->_x = x;
}

void    MonitorNcurses::setY(int y){
    this->_y = y;
}
