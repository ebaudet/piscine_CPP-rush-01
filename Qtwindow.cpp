#include "Qtwindow.h"
#include "ui_qtwindow.h"

QtWindow::QtWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtWindow)
{
    ui->setupUi(this);
}

QtWindow::~QtWindow()
{
    delete ui;
}
