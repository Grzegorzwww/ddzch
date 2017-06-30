#include "graphics.h"

Graphics::Graphics(Ui::MainWindow *_ui, QWidget *parent) : QWidget(parent),ui(_ui)
{

    inicjalizeGraphicsGUI();

    initParam();


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
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int )), this, SLOT(on_stoo_value_1_change(int)));
    connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int )), this, SLOT(on_stoo_value_2_change(int)));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(on_alco_yes_clicked()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(on_alco_no_clicked()));
    connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), this, SLOT(on_water_value_change(int)));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(on_nes_yes_clicked()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(on_nes_no_clicked()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(on_exx_yes_clicked()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT( on_exx_no_clicked()));
    connect(ui->horizontalSlider_7, SIGNAL(valueChanged(int)), this, SLOT(on_afraid_value_change(int)));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(on_exx_yes_clicked()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT( on_exx_no_clicked()));
    connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(on_eutyrox_yes_clicked()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT( on_eutyrox_no_clicked()));
    connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(on_chips_yes_clicked()));
    connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT( on_chips_no_clicked()));
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(on_sweet_yes_clicked()));
    connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT( on_sweet_no_clicked()));


    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_place_1_change(QString)));
    connect(ui->comboBox_3, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_place_2_change(QString)));
    connect(ui->comboBox_5, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_place_3_change(QString)));
    connect(ui->comboBox_7, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_place_4_change(QString)));
    connect(ui->comboBox_2, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_state_1_change(QString)));
    connect(ui->comboBox_4, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_state_2_change(QString)));
    connect(ui->comboBox_6, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_state_3_change(QString)));
    connect(ui->comboBox_8, SIGNAL(currentTextChanged(QString)), this, SLOT(on_face_state_4_change(QString)));
    connect(ui->horizontalSlider_8, SIGNAL(valueChanged(int)), this, SLOT(on_face_trend_value_change(int)));


    connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(on_dodaj_kosmo_clicked()));
    connect(ui->pushButton_32, SIGNAL(clicked()), this, SLOT(on_usun_kosmo_clicked()));



    connect(ui->comboBox_9, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_1_change(QString)));
    connect(ui->comboBox_10, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_2_change(QString)));
    connect(ui->comboBox_11, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_3_change(QString)));
    connect(ui->comboBox_12, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_4_change(QString)));
    connect(ui->comboBox_13, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_5_change(QString)));
    connect(ui->comboBox_14, SIGNAL(currentTextChanged(QString)), this, SLOT(on_kosmo_6_change(QString)));


    connect(ui->radioButton, SIGNAL(pressed()), this, SLOT(on_posilki_checked()));
    connect(ui->radioButton_2, SIGNAL(pressed()), this, SLOT(on_przekaski_checked()));
    connect(ui->radioButton_3, SIGNAL(pressed()), this, SLOT(on_owoce_checked()));
    connect(ui->radioButton_4, SIGNAL(pressed()), this, SLOT(on_warzywa_checked()));
    connect(ui->radioButton_5, SIGNAL(pressed()), this, SLOT(on_inne_checked()));


    connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(on_dodaj_food_clicked()));
    connect(ui->pushButton_42, SIGNAL(clicked()), this, SLOT(on_usun_food_clicked()));



    connect(ui->groupBox, SIGNAL(clicked()), this, SLOT(on_slot()));



}




void Graphics::inicjalizeGraphicsGUI(void){

    actual_tab.append(0);
     ui->stackedWidget->setCurrentIndex(actual_tab.last());
     ui->horizontalSlider->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_2->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_3->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_4->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_5->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_6->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_7->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->horizontalSlider_8->setStyleSheet("QSlider::handle:horizontal {background-color: white;}");
     ui->pushButton_8->setCheckable(true);
     ui->pushButton_9->setCheckable(true);
     ui->pushButton_10->setCheckable(true);
     ui->pushButton_11->setCheckable(true);
     ui->pushButton_12->setCheckable(true);
     ui->pushButton_13->setCheckable(true);
     ui->pushButton_14->setCheckable(true);
     ui->pushButton_15->setCheckable(true);
     ui->pushButton_16->setCheckable(true);
     ui->pushButton_17->setCheckable(true);
     ui->pushButton_18->setCheckable(true);
     ui->pushButton_19->setCheckable(true);
     ui->pushButton_20->setCheckable(true);
     ui->pushButton_21->setCheckable(true);
     ui->pushButton_22->setCheckable(true);
     ui->pushButton_23->setCheckable(true);
     ui->pushButton_24->setCheckable(true);
     ui->pushButton_25->setCheckable(true);




     QStringList face_init_text = QStringList() <<tr("wybierz")<<tr("broda")<<  tr("czoło") <<tr("policzki") << tr("inne");
     ui->comboBox->addItems(face_init_text);
     ui->comboBox_3->addItems(face_init_text);
     ui->comboBox_5->addItems(face_init_text);
     ui->comboBox_7->addItems(face_init_text);

     QStringList face_state_init_text = QStringList() <<tr("wybierz")<<tr("gule")<<tr("rop")<<  tr("wysyp") <<tr("clasyczne") << tr("niezdefinowane");
     ui->comboBox_2->addItems(face_state_init_text);
     ui->comboBox_4->addItems(face_state_init_text);
     ui->comboBox_6->addItems(face_state_init_text);
     ui->comboBox_8->addItems(face_state_init_text);

     parameters_tags.append("-");
     parameters_tags.append("PERIOD");
     parameters_tags.append("GLOWA");
     parameters_tags.append("BRZUCH");
     parameters_tags.append("STOO");
     parameters_tags.append("ALCO");
     parameters_tags.append("WATER");
     parameters_tags.append("SPEEP");
     parameters_tags.append("EXX");
     parameters_tags.append("SCAREE");
     parameters_tags.append("PILLS");
     parameters_tags.append("CHIPS");
     parameters_tags.append("SWEET");
     parameters_tags.append("FACE");
     parameters_tags.append("KOSMO");
     parameters_tags.append("FOOD");



    actualiceKosmoCombo();










}

void Graphics::actualiceKosmoCombo(){

    kosmo_list.clear();
    readListFromIniFile(kosmo_list, "KosmoList");

    ui->comboBox_9->clear();
    ui->comboBox_10->clear();
    ui->comboBox_11->clear();
    ui->comboBox_12->clear();
    ui->comboBox_13->clear();
    ui->comboBox_14->clear();
     ui->comboBox_15->clear();

    ui->comboBox_9->addItems(kosmo_list);
    ui->comboBox_10->addItems(kosmo_list);
    ui->comboBox_11->addItems(kosmo_list);
    ui->comboBox_12->addItems(kosmo_list);
    ui->comboBox_13->addItems(kosmo_list);
    ui->comboBox_14->addItems(kosmo_list);
    ui->comboBox_15->addItems(kosmo_list);
}



void Graphics::initParam(){

    parameters.period.state = false;
    parameters.periodache.value = 0;
    parameters.headache.state = false;
    parameters.headache.value  = 0;
    parameters.stomachache.state = false;
    parameters.stomachache.value = 0;
    parameters.sto.value_1 = 0;
    parameters.sto.value_2 = 0;
    parameters.alco.state = false;
    parameters.water.value = 0;
    parameters.face_1.place = "brak";
    parameters.face_1.what = "brak";
    parameters.face_2.place = "brak";
    parameters.face_2.what = "brak";
    parameters.face_3.place = "brak";
    parameters.face_3.what = "brak";
    parameters.face_4.place = "brak";
    parameters.face_4.what = "brak";
    parameters.face_trend.trend = "brak";
    parameters.sleep.state = true;
    parameters.scare.value = 1;
    parameters.pills.state = false;
    parameters.chips.state = false;
    parameters.sweet.state = false;


}

void Graphics::actualiceGraphicsGUI(Parameters_t param){
    parameters = param;

    if(parameters.period.state){
        ui->pushButton_8->setChecked(true);
        ui->pushButton_9->setChecked(false);
        ui->horizontalSlider->setValue(param.periodache.value);
        ui->label_7->setText(QString::number(param.periodache.value));
    }
    else {
        ui->pushButton_8->setChecked(false);
        ui->pushButton_9->setChecked(true);
    }

    if(parameters.headache.state){
        ui->pushButton_10->setChecked(true);
        ui->pushButton_11->setChecked(false);
        ui->horizontalSlider_2->setValue(param.headache.value);
        ui->label_8->setText(QString::number(param.headache.value));
    }
    else {
        ui->pushButton_10->setChecked(false);
        ui->pushButton_11->setChecked(true);
    }

    if(parameters.stomachache.state){
        ui->pushButton_12->setChecked(true);
        ui->pushButton_13->setChecked(false);
        ui->horizontalSlider_3->setValue(param.stomachache.value);
        ui->label_8->setText(QString::number(param.stomachache.value));
    }
    else {
        ui->pushButton_12->setChecked(false);
        ui->pushButton_13->setChecked(true);
    }

    ui->horizontalSlider_4->setValue(parameters.sto.value_1);
    ui->label_10->setText(QString::number(parameters.sto.value_1));

    ui->horizontalSlider_5->setValue(parameters.sto.value_2);
    ui->label_13->setText(QString::number(parameters.sto.value_2));

    if(parameters.alco.state){
        ui->pushButton_14->setChecked(true);
        ui->pushButton_15->setChecked(false);
    }
    else {
        ui->pushButton_14->setChecked(false);
        ui->pushButton_15->setChecked(true);
    }

    ui->horizontalSlider_6->setValue(parameters.water.value);
    ui->label_15->setText(QString::number(parameters.water.value));

    if(parameters.sleep.state){
        ui->pushButton_16->setChecked(true);
        ui->pushButton_17->setChecked(false);
    }
    else {
        ui->pushButton_16->setChecked(false);
        ui->pushButton_17->setChecked(true);
    }

    if(parameters.exx.state){
        ui->pushButton_18->setChecked(true);
        ui->pushButton_19->setChecked(false);
    }
    else {
        ui->pushButton_18->setChecked(false);
        ui->pushButton_19->setChecked(true);
    }


    ui->horizontalSlider_7->setValue(parameters.scare.value);
    ui->label_17->setText(QString::number(parameters.scare.value));


    if(parameters.pills.state){
        ui->pushButton_20->setChecked(true);
        ui->pushButton_21->setChecked(false);
    }
    else {
        ui->pushButton_20->setChecked(false);
        ui->pushButton_21->setChecked(true);
    }

    if(parameters.chips.state){
        ui->pushButton_22->setChecked(true);
        ui->pushButton_23->setChecked(false);
    }
    else {
        ui->pushButton_22->setChecked(false);
        ui->pushButton_23->setChecked(true);
    }

    if(parameters.sweet.state){
        ui->pushButton_24->setChecked(true);
        ui->pushButton_25->setChecked(false);
    }
    else {
        ui->pushButton_24->setChecked(false);
        ui->pushButton_25->setChecked(true);
    }

    if(parameters.face_trend.trend.contains("wychodzace")){
        ui->horizontalSlider_8->setValue(1);
        ui->label_21->setText("wychodzace");
    }
    else if(parameters.face_trend.trend.contains("rozwiniete")){
        ui->horizontalSlider_8->setValue(2);
        ui->label_21->setText("rozwiniete");
    }
    else if(parameters.face_trend.trend.contains("zanikajace")){
        ui->horizontalSlider_8->setValue(3);
        ui->label_21->setText("zanikajace");
    }

    ui->comboBox_9->setCurrentIndex(ui->comboBox_9->findText(parameters.kosmo.kosmo_1));
    ui->comboBox_10->setCurrentIndex(ui->comboBox_10->findText(parameters.kosmo.kosmo_2));
    ui->comboBox_11->setCurrentIndex(ui->comboBox_11->findText(parameters.kosmo.kosmo_3));
    ui->comboBox_12->setCurrentIndex(ui->comboBox_12->findText(parameters.kosmo.kosmo_4));
    ui->comboBox_13->setCurrentIndex(ui->comboBox_13->findText(parameters.kosmo.kosmo_5));
    ui->comboBox_14->setCurrentIndex(ui->comboBox_14->findText(parameters.kosmo.kosmo_6));



    //TODO:
//   if(parameters.face_1.place.contains("")){
//        ui->horizontalSlider_8->setValue(3);
//        ui->label_21->setText("zanikajace");
//    }



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
    case WPROWADZ_WSZYSTKO_CZ4_INDEX:
        ui->stackedWidget->setCurrentIndex(WPROWADZ_KOSMO_INDEX);
        control_tab(WPROWADZ_KOSMO_INDEX);

        break;
    case WPROWADZ_KOSMO_INDEX:
        ui->stackedWidget->setCurrentIndex(WPROWADZ_FOOD_INDEX);
        control_tab(WPROWADZ_FOOD_INDEX);
       // actualice_list(15);

        break;


    }
}


void Graphics::on_save_data_button_clicked(bool x){

}

void Graphics::getParameters(Parameters_t &param){
        param = parameters;

  }


 void Graphics::actualice_list(int x){
    if(x > 0 && x <= parameters_tags.size() ){
        ui->label->setText(parameters_tags.at(x-1));ui->label_5->setText(parameters_tags.at(x)); ui->label_6->setText(parameters_tags.at(x+1));
    }
 }

 void Graphics::on_face_trend_value_change(int val) {
     actualice_list(13);
     switch(val){
     case 1:
         ui->label_21->setText("wychodzace");
          parameters.face_trend.trend = "wychodzace";
         break;
     case 2:
         ui->label_21->setText("rozwiniete");
          parameters.face_trend.trend = "rozwiniete";
         break;
     case 3:
         ui->label_21->setText("zanikajace");
          parameters.face_trend.trend = "zanikajace";
         break;
     }
 }

 void Graphics::on_face_place_1_change(QString text){
    parameters.face_1.place = text;
     actualice_list(13);
 }
 void Graphics::on_face_place_2_change(QString text){
    parameters.face_2.place = text;
    actualice_list(13);
 }
 void Graphics::on_face_place_3_change(QString text){
    parameters.face_3.place = text;
    actualice_list(13);
 }
 void Graphics::on_face_place_4_change(QString text){
    parameters.face_4.place = text;
    actualice_list(13);
 }
 void Graphics::on_face_state_1_change(QString text){
    parameters.face_1.what = text;
    actualice_list(13);
 }
 void Graphics::on_face_state_2_change(QString text){
    parameters.face_2.what = text;
    actualice_list(13);
 }
 void Graphics::on_face_state_3_change(QString text){
    parameters.face_3.what = text;
    actualice_list(13);
 }
 void Graphics::on_face_state_4_change(QString text){
    parameters.face_4.what = text;
    actualice_list(13);
 }

 void Graphics:: on_dodaj_kosmo_clicked(){
     kosmo_list.append(ui->textEdit->toPlainText());
     qDebug() << ui->textEdit->toPlainText();

     writeListToIniFile(kosmo_list, "KosmoList");
     actualiceKosmoCombo();
     actualice_list(14);

 }
 void Graphics::on_usun_kosmo_clicked(){
     removeItemFromList(kosmo_list, "KosmoList", ui->comboBox_15->currentText());

     actualice_list(14);
 }




 void Graphics::writeListToIniFile(QStringList &list, QString list_name){
     QSettings settings;
      settings.beginWriteArray(list_name);
      for (int i = 0; i < list.size(); ++i) {
          settings.setArrayIndex(i);
          settings.setValue(list_name+"Item"+QString::number(i), list.at(i));
      }
      settings.endArray();

      settings.setValue(list_name+"size", list.size());
}

 void Graphics::readListFromIniFile(QStringList &list, QString list_name){
     QSettings settings;
     int size =  settings.value(list_name+"size", 0).toInt();
     list.clear();
     settings.beginReadArray(list_name);
     for (int i = 0; i < size ; ++i) {
         settings.setArrayIndex(i);
         kosmo_list.append(settings.value(list_name+"Item"+QString::number(i), "brak").toString());
     }
     settings.endArray();
 }

 void Graphics::removeItemFromList(QStringList &list, QString list_name, QString item_name){

     readListFromIniFile(list, list_name);
     list.removeOne(item_name);
     writeListToIniFile(list, list_name);
     actualiceKosmoCombo();
 }


 void Graphics::on_kosmo_1_change(QString text){
    parameters.kosmo.kosmo_1 = text;
    actualice_list(14);
 }
 void Graphics::on_kosmo_2_change(QString text){
    parameters.kosmo.kosmo_2 = text;\
    actualice_list(14);
 }
 void Graphics::on_kosmo_3_change(QString text){
    parameters.kosmo.kosmo_3 = text;
    actualice_list(14);
 }
 void Graphics::on_kosmo_4_change(QString text){
    parameters.kosmo.kosmo_4 = text;
    actualice_list(14);
 }
 void Graphics::on_kosmo_5_change(QString text){
    parameters.kosmo.kosmo_5 = text;
    actualice_list(14);
 }
 void Graphics::on_kosmo_6_change(QString text){
    parameters.kosmo.kosmo_6 = text;
    actualice_list(14);
 }


 void Graphics::on_posilki_checked(){

     ui->comboBox_17->addItems(posilki_list);
 }
 void Graphics::on_przekaski_checked(){
    ui->comboBox_17->addItems(przekaski_list);
 }

 void Graphics::on_owoce_checked(){
    ui->comboBox_17->addItems(owoce_list);
 }

 void Graphics::on_warzywa_checked(){
    ui->comboBox_17->addItems(warzywa_list);
 }
 void Graphics::on_inne_checked(){
    ui->comboBox_17->addItems(inne_list);
 }

 void Graphics::on_dodaj_food_clicked(){
     if(ui->radioButton->isChecked()){
         posilki_list.append(ui->textEdit_4->toPlainText());
        // writeListToIniFile(posilki_list, "PosilkiLog");
     }else if(ui->radioButton_2->isChecked()){
         przekaski_list.append(ui->textEdit_4->toPlainText());
        // writeListToIniFile(przekaski_list, "PrzekaskiLog");
     }else if(ui->radioButton_3->isChecked()){
         owoce_list.append(ui->textEdit_4->toPlainText());
       //  writeListToIniFile(owoce_list, "OwoceLog");
     }else if(ui->radioButton_4->isChecked()){
         warzywa_list.append(ui->textEdit_4->toPlainText());
         //writeListToIniFile(warzywa_list, "WarzywaLog");
     }else if(ui->radioButton_5->isChecked()){
         inne_list.append(ui->textEdit_4->toPlainText());
         //writeListToIniFile(inne_list, "InneLog");
     }
 }


 void Graphics::on_usun_food_clicked(){

 }









