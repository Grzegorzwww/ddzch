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



    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_period_yes_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_period_no_clicked()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(on_period_value_change(int)));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(on_headache_yes_clicked()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_headache_no_clicked()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(on_headache_value_change(int)));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_stomachache_yes_clicked()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_stomachache_no_clicked()));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), this, SLOT(on_stomachache_value_change(int)));


    connect(ui->groupBox, SIGNAL(clicked()), this, SLOT(on_slot()));



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

     ui->pushButton_10->setCheckable(true);
     ui->pushButton_11->setCheckable(true);



     ui->pushButton_12->setCheckable(true);
     ui->pushButton_13->setCheckable(true);

     parameters_tags.append("PERIOD");
     parameters_tags.append("GLOWA");
     parameters_tags.append("BRZUCH");
     parameters_tags.append("STOO");
     parameters_tags.append("ALCO");
     parameters_tags.append("WATER");
     parameters_tags.append("SPEEP");
     parameters_tags.append("SCAREE");
     parameters_tags.append("PILLS");
     parameters_tags.append("CHIPS");
     parameters_tags.append("SWEET");

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

void Graphics::getParameters(Parameters_t &param){
        param = parameters;

  }


 void Graphics::actualice_list(int x){

     switch(x) {
     case 1:
         ui->label;




     }



 }


