#include "MonitorNcurses.hpp"

typedef struct s_mod t_mod;

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
    struct s_mod *host = new struct s_mod();
    host->module = new HostModule();
    host->module->setSizeY(4);
    host->module->setSizeX(8);
    host->module->setX((this->_x / 2) - 4);
    host->module->setY(0);
//    host->win = subwin(stdscr, host->module->getSizeY(), host->module->getSizeX(), host->module->getY(), host->module->getY());
    host->win = subwin(stdscr, 4, 8, 42, 42);
    this->_mod.push_back(host);
}

void    drawModule(struct s_mod *struc){
    for (int i = 0; i < 8; i++){
        mvwprintw(struc->win, i, 21, "*");
        mvwprintw(struc->win, i, 42, "*");
    }
    wrefresh(struc->win);
}

void    MonitorNcurses::init(){
    initscr();
    getmaxyx(stdscr, this->_y, this->_x);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(25);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
    initModules();
    for_each(this->_mod.begin(), this->_mod.end(), drawModule);

//    mvprintw(0, 0, "Nb module = %d, Module name = %s ", this->_modules.size() ,this->_modules[0]->getName().c_str());
//    refresh();
    return ;
}
void    MonitorNcurses::quit(){
    endwin();
//    std::cout << "Size = " << this->_modules.size() << std::endl;
    std::cout << "STRUCT Size = " << this->_mod.size() << " , size y = " << this->_mod.front()->module->getSizeY() << std::endl;
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
