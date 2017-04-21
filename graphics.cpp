#include "graphics.h"

Graphics::Graphics(Ui::MainWindow *_ui, QWidget *parent) : QWidget(parent),ui(_ui)
{


    actual_tab.append(0);
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(on_menu_wprowadz_wszystko_clicked(bool)));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(on_menu_modyfikuj_wybrane_clicked(bool)));
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(on_menu_dodaj_parametr_clicked(bool)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_save_data_button_clicked(bool)));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(on_wstecz_clicked(bool)));


}
void Graphics::on_menu_wprowadz_wszystko_clicked(bool x){
    ui->stackedWidget->setCurrentIndex(WPROWADZ_WSZYSTKO_INDEX);
    control_tab(WPROWADZ_WSZYSTKO_INDEX);

}
void Graphics::on_menu_modyfikuj_wybrane_clicked(bool x){
    ui->stackedWidget->setCurrentIndex(MODYFIKUJ_ZAPISY_INDEX);
    control_tab(MODYFIKUJ_ZAPISY_INDEX);
//    QList<int>::iterator i;
//    for (i = actual_tab.begin(); i != actual_tab.end(); ++i)
//        qDebug() << *i << endl;
}

 void Graphics::on_menu_dodaj_parametr_clicked(bool x){
     ui->stackedWidget->setCurrentIndex(DODAJ_PARAMETR_INDEX);
     control_tab(DODAJ_PARAMETR_INDEX);
 }

void Graphics::control_tab(int actual){
            actual_tab.append(actual);
}
void Graphics::on_wstecz_clicked(bool x){
    if(actual_tab.last() != MAIN_MENU_INDEX ){
        if(!actual_tab.isEmpty()){
            actual_tab.removeLast();
        }
    }
      ui->stackedWidget->setCurrentIndex(actual_tab.last());
}


