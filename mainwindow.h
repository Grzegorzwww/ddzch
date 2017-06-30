#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <graphics.h>
#include <QDir>
#include <QVariant>
#include <QDebug>
#include <QPalette>
#include <QStyleFactory>
#include <QTimer>
#include "time_date_control.h"
#include "log.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

     Graphics *graphics;
     TimeDateControl *time_date_control;
     Log *log;

     Parameters_t Param;

     void setDarkTheme(void);


private slots:


     void on_save_and_close_app();

};

#endif // MAINWINDOW_H
