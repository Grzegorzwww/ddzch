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


    void getParameters(Parameters_t &param);


private:
    Ui::MainWindow *ui;
    QList<int> actual_tab;

    QList<QString> parameters_tags;



    Parameters_t parameters;

    void inicjalizeGraphicsGUI(void);
    void control_tab(int actual);
    void actualice_list(int x);


signals:

public slots:


    void on_menu_wprowadz_wszystko_clicked(bool x);
    void on_menu_modyfikuj_wybrane_clicked(bool x);
    void on_menu_dodaj_parametr_clicked(bool x);
   void on_save_data_button_clicked(bool x);
    void on_wstecz_clicked(bool x);
    void on_next_clicked(bool x);




    void on_period_yes_clicked() {parameters.period.state = true; }
    void on_period_no_clicked() {parameters.period.state = false;}
    void on_period_value_change(int val) {parameters.periodache.value = val; ui->label_7->setText(QString::number(val)); }


    void on_headache_yes_clicked() {parameters.headache.state = true;}
    void on_headache_no_clicked() {parameters.headache.state = false;}
    void on_headache_value_change(int val) {parameters.headache.value = val; ui->label_8->setText(QString::number(val));}


    void on_stomachache_yes_clicked() {parameters.stomachache.state = true;}
    void on_stomachache_no_clicked() {parameters.stomachache.state= false;}
    void on_stomachache_value_change(int val) {parameters.stomachache.value = val; ui->label_9->setText(QString::number(val));}


    void on_slot(){qDebug() << "SLOT";}


signals:


    void on_close_app_from_gui();
};

#endif // GRAPHICS_H
