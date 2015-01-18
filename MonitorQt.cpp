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
MonitorQt::MonitorQt(void)
{
	std::cout << "constructeur MonitorQt" << std::endl;
	
	return ;
}
MonitorQt::MonitorQt(MonitorQt const &instance)
{
	*this = instance;
}
MonitorQt& MonitorQt::operator=(MonitorQt const &rhs)
{
	(void)rhs;
	return *this;
}
MonitorQt::~MonitorQt(void)
{
	std::cout << "desctructeur MonitorQt" << std::endl;
	
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
