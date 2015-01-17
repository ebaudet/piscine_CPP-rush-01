#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>

namespace Ui {
class QtWindow;
}

class QtWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtWindow(QWidget *parent = 0);
    ~QtWindow();

private:
    Ui::QtWindow *ui;
};

#endif // QTWINDOW_H
