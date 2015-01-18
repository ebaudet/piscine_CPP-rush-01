#include "Module.hpp"

Module::Module(std::string const & name) : _name(name)
{

}

Module::Module(Module const & src, std::string const & name) : _name(name){
    *this = src;
}

Module::~Module()
{

}

Module &    Module::operator=(Module const & rhs){
    (void)rhs;
    return *this;
}

std::string      Module::getName() const{
    return this->_name;
}

void            Module::setSizeX(int x){
    this->_size_x = x;
}

void            Module::setSizeY(int y){
    this->_size_y = y;
}

void            Module::setY(int y){
    this->_y = y;
}

void            Module::setX(int x){
    this->_x = x;
}

int             Module::getSizeX(){
    return this->_size_x;
}

int             Module::getSizeY(){
    return this->_size_y;
}

int             Module::getY(){
    return this->_y;
}

int             Module::getX(){
    return this->_x ;
}
