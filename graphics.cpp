#include "graphics.h"

Graphics::Graphics(Ui::MainWindow *_ui, QWidget *parent) : QWidget(parent),ui(_ui)
{

    inicjalizeGraphicsGUI();

    // QSlider::setStyleSheet("QSlider::handle:horizontal {background-color: red;}");

    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(on_menu_wprowadz_wszystko_clicked(bool)));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(on_menu_modyfikuj_wybrane_clicked(bool)));
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(on_menu_dodaj_parametr_clicked(bool)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_save_data_button_clicked(bool)));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(on_wstecz_clicked(bool)));



    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(on_next_clicked(bool)));

}

void Graphics::inicjalizeGraphicsGUI(void){

    actual_tab.append(0);
     ui->stackedWidget->setCurrentIndex(actual_tab.last());

     ui->horizontalSlider->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");


     ui->horizontalSlider->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");


     ui->horizontalSlider_2->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_3->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");

     ui->pushButton_8->setCheckable(true);
     ui->pushButton_9->setCheckable(true);


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


void Graphics::on_next_clicked(bool x){


    switch(actual_tab.last()){
    case WPROWADZ_WSZYSTKO_INDEX:
        ui->stackedWidget->setCurrentIndex(WPROWADZ_WSZYSTKO_CZ2_INDEX);
        control_tab(WPROWADZ_WSZYSTKO_CZ2_INDEX);
    break;

    case WPROWADZ_WSZYSTKO_CZ2_INDEX:
        ui->stackedWidget->setCurrentIndex(WPROWADZ_WSZYSTKO_CZ3_INDEX);
        control_tab(WPROWADZ_WSZYSTKO_CZ3_INDEX);

        break;
    case WPROWADZ_WSZYSTKO_CZ3_INDEX:
        ui->stackedWidget->setCurrentIndex(WPROWADZ_WSZYSTKO_CZ4_INDEX);
        control_tab(WPROWADZ_WSZYSTKO_CZ4_INDEX);

        break;



    }

}





void Graphics::on_save_data_button_clicked(bool x){


}


