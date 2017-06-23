#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtXlsx>
#include "xlsxdocument.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    graphics = new Graphics(ui,this);
    setDarkTheme();




        QXlsx::Document xlsx;
        QXlsx::Document xlsx_2("Test.xlsx");

//        xlsx.write("A1", "Hello Qt!");
//        xlsx.saveAs("Test.xlsx");
        QVariant var;
        var = xlsx_2.read("A1");

//        qDebug() << QDir::currentPath();
//        std::cout << QDir::currentPath().toStdString();

        ui->label_4->setText(var.toString());



    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graphics;


}


void MainWindow::setDarkTheme(void){

    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);




    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}
