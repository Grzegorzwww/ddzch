#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtXlsx>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello Qt!");
    xlsx.saveAs("Test.xlsx");

    graphics = new Graphics(ui,this);




    void on_close_app_from_gui();
}



MainWindow::~MainWindow()
{
    delete ui;
}
