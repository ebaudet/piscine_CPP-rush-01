/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorQt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:09:47 by ebaudet           #+#    #+#             */
/*   Updated: 2015/01/18 18:28:23 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorQt.hpp"

/* ************************************************************************** *
	Constructors // Destructors
 * ************************************************************************** */
MonitorQt::MonitorQt(int argc, char *argv[]) {
    this->_qa = new QApplication(argc, argv);
    this->_qwindow = new QtWindow();
}

MonitorQt::MonitorQt(MonitorQt const &instance)
{
	*this = instance;
}
MonitorQt& MonitorQt::operator=(MonitorQt const &rhs)
{
    this->_qa = rhs.getQA();
    this->_qwindow = rhs.getQWindow();
	return *this;
}
MonitorQt::~MonitorQt(void)
{
	std::cout << "desctructeur MonitorQt" << std::endl;
    delete this->_qwindow;
    delete this->_qa;
	return ;
}

/* ************************************************************************** *
	member function
 * ************************************************************************** */

void	MonitorQt::init() {
	std::cout << "appel a MonitorQt::init()" << std::endl;
}
void	MonitorQt::quit() {
	std::cout << "appel a MonitorQt::quit()" << std::endl;
}
int    MonitorQt::addWidget(void) {
    int     position = std::distance(this->_qwidget.begin(), this->_qwidget.end());

    this->_qwidget.insert(this->_qwidget.end(), 1, new QWidget);
    return position;
}

/* ************************************************************************** *
    getters & setters
 * ************************************************************************** */
QApplication    *MonitorQt::getQA(void) const {
    return this->_qa;
}
QtWindow        *MonitorQt::getQWindow(void) const {
    return  this->_qwindow;
}
