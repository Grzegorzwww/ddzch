#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "ui_mainwindow.h"
#include <QWidget>
#include <QDebug>
#include <QList>
#include "defines.h"


class Graphics : public QWidget
{
    Q_OBJECT
public:
    Graphics(Ui::MainWindow *_ui, QWidget *parent = 0);


private:
    Ui::MainWindow *ui;
    QList<int> actual_tab;


    void inicjalizeGraphicsGUI(void);
    void control_tab(int actual);

signals:

public slots:


    void on_menu_wprowadz_wszystko_clicked(bool x);
    void on_menu_modyfikuj_wybrane_clicked(bool x);
    void on_menu_dodaj_parametr_clicked(bool x);
   void on_save_data_button_clicked(bool x);
    void on_wstecz_clicked(bool x);
    void on_next_clicked(bool x);


signals:


    void on_close_app_from_gui();
};

#endif // GRAPHICS_H
