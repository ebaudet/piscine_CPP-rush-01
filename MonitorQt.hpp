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

#include "Qtwindow.h"
#include "IMonitorDisplay.hpp"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QSlider>
#include <iostream>
#include <vector>

class MonitorQt : public IMonitorDisplay
{
private:
    QApplication        *_qa;
    QtWindow            *_qwindow;
    std::vector<QWidget *>   _qwidget;
    MonitorQt(void);

public:
    MonitorQt(int, char **);
	MonitorQt(MonitorQt const &);
	MonitorQt& operator=(MonitorQt const &);
	~MonitorQt(void);
	
	// member functions
	void	init();
	void	quit();
    void    play();
    int     addWidget(void);

    // getters & setters
    QApplication    *getQA(void) const;
    QtWindow        *getQWindow(void) const;
};


#endif // MONITORQT_HPP
