#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("grzegorz warchol");
    QCoreApplication::setApplicationName("aplikacja");



    MainWindow w;
    w.show();

    return a.exec();
}
