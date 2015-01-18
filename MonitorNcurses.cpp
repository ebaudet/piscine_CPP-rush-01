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
    host->module->setSizeY(8);
    host->module->setSizeX(42);
    host->module->setX((this->_x / 2) - 21);
    host->module->setY(10);
    host->win = subwin(stdscr, host->module->getSizeY(), host->module->getSizeX(), host->module->getY(), host->module->getX());

    this->_mod.push_back(host);
    struct s_mod *host2 = new struct s_mod();
    host2->module = new HostModule();
    host2->module->setSizeY(8);
    host2->module->setSizeX(42);
    host2->module->setX((this->_x / 2) - 21);
    host2->module->setY(30);
    host2->win = subwin(stdscr, host2->module->getSizeY(), host2->module->getSizeX(), host2->module->getY(), host2->module->getX());
    this->_mod.push_back(host);

    struct s_mod *host3 = new struct s_mod();
    host3->module = new HostModule();
    host3->module->setSizeY(8);
    host3->module->setSizeX(42);
    host3->module->setX((this->_x / 2) - 21);
    host3->module->setY(60);
    host3->win = subwin(stdscr, host3->module->getSizeY(), host3->module->getSizeX(), host3->module->getY(), host3->module->getX());
    this->_mod.push_back(host);
}

void    drawModule(struct s_mod *struc){
//    for (int i = 0; i < struc->module->getSizeY(); i++){
//        mvwprintw(struc->win, i, 0, "*");
//        mvwprintw(struc->win, i, 41, "*");
//    }
//    for (int i = 0; i < struc->module->getSizeX(); i++){
//        mvwprintw(struc->win, 0, i, "*");
//        mvwprintw(struc->win, 7, i, "*");
//    }

    int x;
    int y;
    getmaxyx(stdscr, y, x);

    for (int i = struc->module->getY(); i < struc->module->getY() + struc->module->getSizeY(); i++){
        mvwprintw(stdscr, i, (x / 2) - 21, "*");
        mvwprintw(stdscr, i, ((x / 2) - 21) + 41, "*");
    }
    for (int i = ((x / 2) - 21); i < ((x / 2) - 21) + struc->module->getSizeX(); i++){
        mvwprintw(stdscr, struc->module->getY(), i, "*");
        mvwprintw(stdscr, struc->module->getY() + 8, i, "*");
    }
    std::string test = struc->module->getData();
    mvprintw(12, ((x / 2) - 18), test.c_str());
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
    refresh();
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
