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

#include <QMainWindow>
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
#include <algorithm>
#include <vector>
#include "Module.hpp"
#include "HostModule.hpp"
#include "OsModule.hpp"
#include "DateModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"

class MonitorQt : public IMonitorDisplay
{
private:
    QApplication            *_qa;
    QMainWindow             *_qwindow;
    QTabWidget              *_onglets;
    std::vector<QWidget *>  _qwidget;
    std::vector<Module *>   _modules;
    int                     addWidget(QWidget *);


    MonitorQt(MonitorQt const &);
    MonitorQt(void);
    MonitorQt& operator=(MonitorQt const &);

public:
    MonitorQt(int, char **);
	~MonitorQt(void);
	
	// member functions
	void	init();
	void	quit();
    void    play();
    int     addModule(Module *);

    // getters & setters
    QApplication    *getQA(void) const;
    QMainWindow     *getQWindow(void) const;
};


#endif // MONITORQT_HPP
