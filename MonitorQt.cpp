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
    this->_qwindow = new QMainWindow();
    this->_qwindow->setFixedSize(700,500);
    this->_onglets = new QTabWidget(this->_qwindow);
    this->_onglets->setGeometry(30, 20, 650, 400);
}

MonitorQt::~MonitorQt(void)
{
	std::cout << "desctructeur MonitorQt" << std::endl;
    delete this->_onglets;
    delete this->_qwindow;
    delete this->_qa;
	return ;
}

/* ************************************************************************** *
	member function
 * ************************************************************************** */

void	MonitorQt::init() {
	std::cout << "appel a MonitorQt::init()" << std::endl;


    this->addModule(new HostModule());
    this->addModule(new OsModule());
    this->addModule(new DateModule());
    this->addModule(new CpuModule());
    this->addModule(new RamModule());
    this->addModule(new NetworkModule());
 /*   // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QLabel *page3 = new QLabel; // Comme un QLabel est aussi un QWidget (il en hérite), on peut aussi s'en servir de page

    // 3 : Créer le contenu des pages de widgets

    // Page 1

    QLineEdit *lineEdit = new QLineEdit("Entrez votre nom");
    QPushButton *bouton1 = new QPushButton("Cliquez ici");
    QPushButton *bouton2 = new QPushButton("Ou là…");

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(lineEdit);
    vbox1->addWidget(bouton1);
    vbox1->addWidget(bouton2);

    page1->setLayout(vbox1);

    // Page 2

    QProgressBar *progress = new QProgressBar;
    progress->setValue(50);
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton *bouton3 = new QPushButton("Valider");

    QVBoxLayout *vbox2 = new QVBoxLayout;
    vbox2->addWidget(progress);
    vbox2->addWidget(slider);
    vbox2->addWidget(bouton3);

    page2->setLayout(vbox2);

    // Page 3 (je ne vais afficher qu'une image ici, pas besoin de layout)

    page3->setPixmap(QPixmap("icone.png"));
    page3->setAlignment(Qt::AlignCenter);

    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    this->_onglets->addTab(page1, "Coordonnées");
    this->_onglets->addTab(page2, "Progression");
    this->_onglets->addTab(page3, "Image");*/
}
void	MonitorQt::quit() {
	std::cout << "appel a MonitorQt::quit()" << std::endl;
}
void    MonitorQt::play() {
    this->_qwindow->show();
//    while (42)
//    {
//        this->_qwindow->update();
//    }
}

int     MonitorQt::addModule(Module *module) {
    int     position = std::distance(this->_modules.begin(), this->_modules.end());

    this->_modules.push_back(module);


    QWidget *widget = new QWidget();
    this->_onglets->addTab(widget, QString(module->getName().c_str()));


    if (module->typeData() == 1)
    {
        QLabel *label = new QLabel();
        label->setText(QString(module->getData().c_str()));

        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(label);
        widget->setLayout(vbox);
    }
    else if (module->typeData() == 2)
    {
        QLabel *label = new QLabel();
        label->setText(QString(module->getData().c_str()));

        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(label);
        widget->setLayout(vbox);
    }

    this->addWidget(widget);
    return position;
}
int    MonitorQt::addWidget(QWidget *widget) {
    int     position = std::distance(this->_qwidget.begin(), this->_qwidget.end());

    this->_qwidget.push_back(widget);
    return position;
}

/* ************************************************************************** *
    getters & setters
 * ************************************************************************** */
QApplication    *MonitorQt::getQA(void) const {
    return this->_qa;
}
QMainWindow     *MonitorQt::getQWindow(void) const {
    return  this->_qwindow;
}
