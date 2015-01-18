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

//std::vector<Module *> MonitorNcurses::getModules(){
//    return this->_modules;
//}

void    MonitorNcurses::initModules(){
    this->_modules.push_back(new HostModule());
}

void    MonitorNcurses::init(){
    initModules();
    initscr();
    getmaxyx(stdscr, this->_y, this->_x);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(25);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
    mvprintw(0, 0, "Nb module = %d ", this->_modules[0]->getName().c_str());
    refresh();
    return ;
}
void    MonitorNcurses::quit(){
    endwin();
    std::cout << "Size = " << this->_modules.size() << std::endl;
    std::cout << "Size = " << this->_modules.front()->getName() << std::endl;
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

void    MonitorNcurses::update(){

}

void    MonitorNcurses::play(){
    int key;
    while (42){
        while ((key = getch()) != ERR){
             if (key == KEY_UP){

                }
            else if (key == KEY_DOWN){

            }
            else if (key == ' '){

            }
        }
    }
}
