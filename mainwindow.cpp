#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , window(new QWidgetGame())
{
    window->setupUiInitialWindow(this);
//    window->setupState(new Ronda());

}

MainWindow::~MainWindow()
{
    delete window;
}

