#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    //w.setWindowState(Qt::WindowFullScreen);
    //w.setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowTitleHint |Qt::WindowSystemMenuHint);
    w.showFullScreen();
   // w.show();
    return a.exec();
}
