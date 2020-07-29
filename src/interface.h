#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>

#include <d1_mainwindow.h>
#include <d2_mainwindow.h>

namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private:
    Ui::Interface *ui;
    void initToolBar();

    MainWindow* mainWindow;

private slots:
    void start(DisplayResolution resolution);
};

#endif // INTERFACE_H
