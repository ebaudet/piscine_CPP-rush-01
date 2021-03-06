/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:54:30 by ebaudet           #+#    #+#             */
/*   Updated: 2015/01/18 21:00:57 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Module.hpp"
#include <iostream>

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
std::string     Module::getData(void) {
    std::string     result;

    result.append("EMPTY MODULE\n");

    return result;
}

int         Module::typeData(void) {
    return 1;
}
