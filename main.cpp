#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("grzegorz warchol");
    QCoreApplication::setApplicationName("aplikacja");

//    xlsx.write("A1", "Hello Qt!");

    MainWindow w;
    w.show();

    return a.exec();
}
