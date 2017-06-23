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

     void setDarkTheme(void);

};

#endif // MAINWINDOW_H
