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

void    MonitorNcurses::displayAlgo(struct s_mod *host){
    int pos_x, pos_y;

    int max = this->getX() / host->module->getSizeX();
    pos_x = ((this->_mod.size() % max) * host->module->getSizeX() + 2);
    int nb_l = (((this->_mod.size() + 1) * (host->module->getSizeX())) / (this->getX()));
    nb_l = this->_mod.size() == 0 ? 0 : nb_l;
    pos_y = (nb_l > 0 ? (nb_l * (host->module->getSizeY())) : 2);
    host->module->setX(pos_x);
    host->module->setY(pos_y);
}

void    MonitorNcurses::initAttrModules(Module *module){
    struct s_mod *host = new struct s_mod();
    host->module = module;
    host->module->setSizeY(8);
    host->module->setSizeX(42);
    this->displayAlgo(host);

    host->win = subwin(stdscr, host->module->getSizeY(), host->module->getSizeX(), host->module->getY(), host->module->getX());
    mvwprintw(host->win, 1, 3, host->module->getName().c_str());
    mvwprintw(host->win, 3, 3, host->module->getData().c_str());
    this->_mod.push_back(host);
}

void    MonitorNcurses::initModules(){
    this->initAttrModules(new HostModule());
    this->initAttrModules(new DateModule());
    this->initAttrModules(new OsModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
//    this->initAttrModules(new HostModule());
}

void    drawModule(struct s_mod *struc){
    for (int i = 0; i < struc->module->getSizeY(); i++){
        mvwprintw(struc->win, i, 0, "*");
        mvwprintw(struc->win, i, struc->module->getSizeX() - 1, "*");
    }
    for (int i = 0; i < struc->module->getSizeX(); i++){
        mvwprintw(struc->win, 0, i, "*");
        mvwprintw(struc->win, struc->module->getSizeY() - 1, i, "*");
    }
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
    std::cout << "WIDTH = " << this->getX() << std::endl;
    std::cout << "HEIGTH = " << this->getY() << std::endl;
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
    getmaxyx(stdscr, this->_y, this->_x);
    std::vector<struct s_mod *>::iterator it = this->_mod.begin();
    while (it != this->_mod.end()){
        displayAlgo(*it);
        it++;
    }
    refresh();
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
//            this->update();
        }
    }
}
