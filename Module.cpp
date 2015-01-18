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

