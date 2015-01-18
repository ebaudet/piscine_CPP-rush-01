/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorQt.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:09:47 by ebaudet           #+#    #+#             */
/*   Updated: 2015/01/18 18:27:16 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORQT_HPP
# define MONITORQT_HPP

#include "IMonitorDisplay.hpp"
#include <iostream>

class MonitorQt : public IMonitorDisplay
{
public:
	MonitorQt(void);
	MonitorQt(MonitorQt const &);
	MonitorQt& operator=(MonitorQt const &);
	~MonitorQt(void);
	
	// member functions
	void	init();
	void	quit();
};


#endif // MONITORQT_HPP
