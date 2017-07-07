#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "ui_mainwindow.h"
#include <QWidget>
#include <QDebug>
#include <QList>
#include <QSettings>
#include <QStandardItem>
#include "defines.h"
 #include <QMessageBox>


class Graphics : public QWidget
{
    Q_OBJECT
public:
    Graphics(Ui::MainWindow *_ui, QWidget *parent = 0);


    void getParameters(Parameters_t &param);
    void actualiceGraphicsGUI(Parameters_t param);

private:
    Ui::MainWindow *ui;
    QList<int> actual_tab;

    QList<QString> parameters_tags;



    Parameters_t parameters;
    QStringList kosmo_list;




    QStringList posilki_list;
    QStringList przekaski_list;
    QStringList owoce_list;
    QStringList warzywa_list;
    QStringList inne_list;

    QStandardItemModel *kosmo_table_model;
    QStandardItemModel *kosmo_wieczor_table_model;

     QStandardItemModel *food_table_model;





    void inicjalizeGraphicsGUI(void);

    void initParam();
    void control_tab(int actual);
    void actualice_list(int x);
    void actualiceKosmo();
    void createTabWidgets();


    void writeListToIniFile(QStringList &list, QString list_name);
    void readListFromIniFile(QStringList &list, QString list_name);
    void removeItemFromList(QStringList &list, QString list_name, QString item_name);
    void addListToTable(QStandardItemModel &model,  QStringList &list);
    void fillFoodTable(QStandardItemModel *model, QStringList list, bool clear);
    void fillTable(QStandardItemModel *model, QStringList list, bool clear);
    QStringList getActualFoodList();
    void actualiceCheckedFood();




signals:

public slots:


    void on_menu_wprowadz_wszystko_clicked(bool x);
    void on_menu_modyfikuj_wybrane_clicked(bool x);
    void on_menu_dodaj_parametr_clicked(bool x);
   void on_save_data_button_clicked(bool x);
    void on_wstecz_clicked(bool x);
    void on_next_clicked(bool x);



    void on_period_yes_clicked() {parameters.period.state = true; ui->pushButton_9->setChecked(false); actualice_list(1);}
    void on_period_no_clicked() {parameters.period.state = false; ui->pushButton_8->setChecked(false); actualice_list(1);}
    void on_period_value_change(int val) {parameters.periodache.value = val; ui->label_7->setText(QString::number(val)); actualice_list(1);}
    void on_headache_yes_clicked() {parameters.headache.state = true; ui->pushButton_11->setChecked(false);  actualice_list(2);}
    void on_headache_no_clicked() {parameters.headache.state = false; ui->pushButton_10->setChecked(false);  actualice_list(2);}
    void on_headache_value_change(int val) {parameters.headache.value = val; ui->label_8->setText(QString::number(val)); actualice_list(2);}
    void on_stomachache_yes_clicked() {parameters.stomachache.state = true; ui->pushButton_13->setChecked(false);  actualice_list(3);}
    void on_stomachache_no_clicked() {parameters.stomachache.state= false;ui->pushButton_12->setChecked(false);  actualice_list(3);}
    void on_stomachache_value_change(int val) {parameters.stomachache.value = val; ui->label_9->setText(QString::number(val));actualice_list(3);}
    void on_stoo_value_1_change(int val) {parameters.sto.value_1 = val; ui->label_10->setText(QString::number(val));actualice_list(4);}
    void on_stoo_value_2_change(int val) {parameters.sto.value_2 = val; ui->label_13->setText(QString::number(val));actualice_list(4);}
    void on_alco_yes_clicked() {parameters.alco.state = true;  ui->pushButton_15->setChecked(false);  actualice_list(5);}
    void on_alco_no_clicked() {parameters.alco.state= false;ui->pushButton_14->setChecked(false); actualice_list(5);}
    void on_water_value_change(int val) {parameters.water.value = val; ui->label_15->setText(QString::number(val)+" ml");actualice_list(6);}
    void on_nes_yes_clicked() {parameters.sleep.state = true; ui->pushButton_17->setChecked(false); actualice_list(7);}
    void on_nes_no_clicked() {parameters.sleep.state = false; ui->pushButton_16->setChecked(false); actualice_list(7);}
    void on_exx_yes_clicked() {parameters.exx.state = true;ui->pushButton_19->setChecked(false); actualice_list(8);}
    void on_exx_no_clicked() {parameters.exx.state = false;ui->pushButton_18->setChecked(false); actualice_list(8);}
    void on_afraid_value_change(int val) {parameters.scare.value = val;  ui->label_17->setText(QString::number(val)); actualice_list(9);}
    void on_eutyrox_yes_clicked() {parameters.pills.state = true; ui->pushButton_21->setChecked(false);actualice_list(10);}
    void on_eutyrox_no_clicked() {parameters.pills.state= false; ui->pushButton_20->setChecked(false); actualice_list(10);}
    void on_chips_yes_clicked() {parameters.chips.state = true;ui->pushButton_23->setChecked(false);actualice_list(11);}
    void on_chips_no_clicked() {parameters.chips.state = false;ui->pushButton_22->setChecked(false);actualice_list(11);}
    void on_sweet_yes_clicked() {parameters.sweet.state = true;ui->pushButton_25->setChecked(false);actualice_list(12);}
    void on_sweet_no_clicked() {parameters.sweet.state= false;ui->pushButton_24->setChecked(false);actualice_list(12);}



     void on_face_trend_value_change(int val) ;


    void on_face_place_1_change(QString text) ;
    void on_face_place_2_change(QString text) ;
    void on_face_place_3_change(QString text) ;
    void on_face_place_4_change(QString text) ;



    void on_face_state_1_change(QString text) ;
    void on_face_state_2_change(QString text) ;
    void on_face_state_3_change(QString text) ;
    void on_face_state_4_change(QString text) ;


    void on_dodaj_kosmo_clicked();
    void on_usun_kosmo_clicked();

    void on_dodaj_food_clicked();
    void on_usun_food_clicked();

    void on_set_rano_tab();
    void on_set_wieczor_tab();




    void on_kosmo_rano_change(QString text);


    void on_posilki_checked();
    void on_przekaski_checked();
    void on_owoce_checked();
    void on_warzywa_checked();
    void on_inne_checked();

    void on_sniadanie_checked();
    void on_obiad_checked();
    void on_kolacja_checked();
    void on_inne_posilki_checked();





    void on_tableView_rano_customContextMenuRequested(const QPoint &pos);
     void on_tableView_wieczor_customContextMenuRequested(const QPoint &pos);

    void on_tableView_clicked(QModelIndex index);
    void on_tableView_2_clicked(QModelIndex index);
    void on_tableView_3_clicked(QModelIndex index);





    void on_slot(){qDebug() << "SLOT";}


signals:


    void on_close_app_from_gui();
};

#endif // GRAPHICS_H
