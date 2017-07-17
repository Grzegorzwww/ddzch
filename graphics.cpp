#include "graphics.h"

Graphics::Graphics(Ui::MainWindow *_ui, QWidget *parent) : QWidget(parent),ui(_ui)
{
    
    inicjalizeGraphicsGUI();
    
    initParam();


    //ui->label_22->setText(QCoreApplication::applicationDirPath());


    

    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(on_menu_wprowadz_wszystko_clicked(bool)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_save_data_button_clicked(bool)));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(on_wstecz_clicked(bool)));
    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(on_next_clicked(bool)));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_period_yes_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_period_no_clicked()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(on_period_value_change(int)));
    connect(ui->horizontalSlider_9, SIGNAL(valueChanged(int)), this, SLOT(on_period_value_pain_change(int)));


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
    //connect(ui->pushButton_32, SIGNAL(clicked()), this, SLOT(on_usun_kosmo_clicked()));
    
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tableView_rano_customContextMenuRequested(QPoint)));
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_clicked(QModelIndex)));
    
    connect(ui->tableView_2, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_2_clicked(QModelIndex)));
    connect(ui->tableView_3, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_3_clicked(QModelIndex)));
    
    
    
    connect(ui->radioButton, SIGNAL(pressed()), this, SLOT(on_posilki_checked()));
    connect(ui->radioButton_2, SIGNAL(pressed()), this, SLOT(on_przekaski_checked()));
    connect(ui->radioButton_3, SIGNAL(pressed()), this, SLOT(on_owoce_checked()));
    connect(ui->radioButton_4, SIGNAL(pressed()), this, SLOT(on_warzywa_checked()));
    connect(ui->radioButton_5, SIGNAL(pressed()), this, SLOT(on_inne_checked()));
    
    
    connect(ui->radioButton_6, SIGNAL(pressed()), this, SLOT(on_sniadanie_checked()));
    connect(ui->radioButton_7, SIGNAL(pressed()), this, SLOT(on_obiad_checked()));
    connect(ui->radioButton_8, SIGNAL(pressed()), this, SLOT(on_kolacja_checked()));
    connect(ui->radioButton_9, SIGNAL(pressed()), this, SLOT(on_inne_posilki_checked()));
    
    
    connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(on_dodaj_food_clicked()));
    //connect(ui->pushButton_42, SIGNAL(clicked()), this, SLOT(on_usun_food_clicked()));
    
    connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(on_set_rano_tab()));
    connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(on_set_wieczor_tab()));
    
    
    connect(ui->textEdit_2, SIGNAL(textChanged()),this, SLOT(on_notice_changed()));
    connect(ui->groupBox, SIGNAL(clicked()), this, SLOT(on_slot()));
    
    
    
}




void Graphics::inicjalizeGraphicsGUI(void){
    
    actual_tab.append(0);
    ui->stackedWidget->setCurrentIndex(actual_tab.last());

    ui->label->setText( QDir::currentPath());

    QString horizontal_slider_style = "QSlider::groove:horizontal { "" border:none; " "margin-top: 10px;""margin-bottom: 10px;" "  height: 10px;"  "} "
                                      "QSlider::handle:horizontal { ""background: white;" "border: 1px solid white;" "height: 40px;""width: 40px;""margin: -30px 0;" "border-radius: 20px"   "} "
                                      "QSlider::sub-page {" "background: rgb(70, 120, 200);" "}" "QSlider::add-page  {" "background: rgb(70, 70, 70);" "}";

    ui->horizontalSlider->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_2->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_3->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_4->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_5->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_6->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_7->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_8->setStyleSheet(horizontal_slider_style);
    ui->horizontalSlider_9->setStyleSheet(horizontal_slider_style);




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
    ui->pushButton_26->setCheckable(true);
    ui->pushButton_27->setCheckable(true);
    
    
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
    parameters_tags.append("OKRES");
    parameters_tags.append("BOL GŁOWY");
    parameters_tags.append("BOL BRZUCHA");
    parameters_tags.append("KUPKA");
    parameters_tags.append("ALKOCHOL");
    parameters_tags.append("WYPITA WODA");
    parameters_tags.append("SEN ");
    parameters_tags.append("EXS");
    parameters_tags.append("NERWY");
    parameters_tags.append("EUTHYROX ");
    parameters_tags.append("CHIPSY");
    parameters_tags.append("SŁODYCZE");
    parameters_tags.append("STAN BUZI");
    parameters_tags.append("LUŹNE NOTATKI");
    parameters_tags.append("UŻYTE KOSMEYKI");
    parameters_tags.append("JEDZENIE");
    parameters_tags.append("JEDZENIE");
    
    
    kosmo_list.clear();
    readListFromIniFile(kosmo_list, "KosmoList");
    
    //ui->comboBox_15->clear();
    //ui->comboBox_15->addItems(kosmo_list);
    
    createTabWidgets();
    actualiceKosmo();
    
    ui->radioButton->setChecked(true);
    ui->radioButton_6->setChecked(true);
    on_posilki_checked();
    on_face_trend_value_change(1);
    
    
}

void Graphics::createTabWidgets(){
    
    kosmo_table_model = new QStandardItemModel(0,1,this);
    QStringList _model_items;
    QStringList _model_items_2;
    QStringList _model_items_3;
    _model_items.append("KOSMO");
    kosmo_table_model->setHorizontalHeaderLabels(_model_items);
    ui->tableView->setModel(kosmo_table_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    kosmo_wieczor_table_model = new QStandardItemModel(0,1,this);
    _model_items_2.clear();
    _model_items_2.append("KOSMO WIECZOR");
    kosmo_wieczor_table_model->setHorizontalHeaderLabels(_model_items_2);
    ui->tableView_2->setModel(kosmo_wieczor_table_model);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    _model_items_3.clear();
    _model_items_3.append("NAZWA");
    _model_items_3.append("TYP");
    food_table_model = new QStandardItemModel();
    food_table_model->setHorizontalHeaderLabels( _model_items_3);
    ui->tableView_3->setModel(food_table_model);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    
}

void Graphics::actualiceKosmo(){
    
    
    kosmo_table_model->clear();
    QStringList _model_items;
    QStringList _model_items_2;
    _model_items.append("KOSMETYKI RANO");
    kosmo_table_model->setHorizontalHeaderLabels(_model_items);
    ui->tableView->setModel(kosmo_table_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    QList<QStandardItem *> newRow;
    for(int i = 0; i < kosmo_list.size(); i++){
        newRow.clear();
        newRow.append(new QStandardItem(kosmo_list.at(i)));
        kosmo_table_model->appendRow(newRow);
    }
    
    kosmo_wieczor_table_model->clear();
    _model_items_2.append("KOSMETYKI WIECZOR");
    kosmo_wieczor_table_model->setHorizontalHeaderLabels(_model_items_2);
    ui->tableView_2->setModel(kosmo_wieczor_table_model);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    for(int i = 0; i < kosmo_list.size(); i++){
        newRow.clear();
        newRow.append(new QStandardItem(kosmo_list.at(i)));
        kosmo_wieczor_table_model->appendRow(newRow);
    }
}

void Graphics::addListToTable(QStandardItemModel &model,  QStringList  &list){
    
    
    
}


void Graphics::initParam(){
    
    parameters.period.state = false;
    parameters.periodache.value_1 = 0;
    parameters.periodache.value_2 = 0;

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
        ui->horizontalSlider->setValue(param.periodache.value_1);
        ui->horizontalSlider_9->setValue(param.periodache.value_2);

        ui->label_7->setText(QString::number(param.periodache.value_1));
        ui->label_23->setText(QString::number(param.periodache.value_2));
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
    
    ui->horizontalSlider_6->setValue(parameters.water.value / 10 );
    ui->label_15->setText(QString::number(parameters.water.value  ));

    
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
    
    QColor rowColor = Qt::red; //or some other color definition
    
    for(int i = 0; i < parameters.kosmo.rano.size(); i++){
        for(int j = 0; j < kosmo_list.size(); j++){
            if(parameters.kosmo.rano.at(i).contains(kosmo_list.at(j))){
                qDebug() << "zawieram " << kosmo_list.at(j) << "numer = "<<j;
                ui->tableView->model()->setData(ui->tableView->model()->index(j, 0),rowColor, Qt::ForegroundRole );
            }
        }
    }
    for(int i = 0; i < parameters.kosmo.wieczor.size(); i++){
        for(int j = 0; j < kosmo_list.size(); j++){
            if(parameters.kosmo.wieczor.at(i).contains(kosmo_list.at(j))){
                qDebug() << "zawieram " << kosmo_list.at(j) << "numer = "<<j;
                ui->tableView_2->model()->setData(ui->tableView_2->model()->index(j, 0),rowColor, Qt::ForegroundRole );
            }
        }
    }
    
    ui->comboBox->setCurrentText( parameters.face_1.place);
    ui->comboBox_2->setCurrentText( parameters.face_1.what);
    ui->comboBox_3->setCurrentText( parameters.face_2.place);
    ui->comboBox_4->setCurrentText( parameters.face_2.what);
    ui->comboBox_5->setCurrentText( parameters.face_3.place);
    ui->comboBox_6->setCurrentText( parameters.face_3.what);
    ui->comboBox_7->setCurrentText( parameters.face_4.place);
    ui->comboBox_8->setCurrentText( parameters.face_4.what);
    
    
    ui->textEdit_2->setText(parameters.notice.str_param);
    
    
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

    case WPROWADZ_FOOD_INDEX:
         QMessageBox::information(this, "Koniec listy parametrow", "Koniec wpisywania parametrow, nacisnij zakończ, aby zapisac dane");
        break;
    }
}


void Graphics::on_save_data_button_clicked(bool x){
    
}

void Graphics::getParameters(Parameters_t &param){
    param = parameters;
    
}


void Graphics::actualice_list(int x){
    //    if(x > 0 && x <= parameters_tags.size() ){
    //        ui->label->setText(parameters_tags.at(x-1));ui->label_5->setText(parameters_tags.at(x)); ui->label_6->setText(parameters_tags.at(x+1));
    //    }
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
    ui->textEdit->clear();
    
    
    writeListToIniFile(kosmo_list, "KosmoList");
    actualiceKosmo();
    actualice_list(15);
    
}
void Graphics::on_usun_kosmo_clicked(){


    //removeItemFromList(kosmo_list, "KosmoList", ui->comboBox_15->currentText());
    
    actualice_list(15);
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
        list.append(settings.value(list_name+"Item"+QString::number(i), "brak").toString());
    }
    settings.endArray();
}

void Graphics::removeItemFromList(QStringList &list, QString list_name, QString item_name){
    
    readListFromIniFile(list, list_name);
    list.removeOne(item_name);
    writeListToIniFile(list, list_name);
    actualiceKosmo();
}


void Graphics::on_kosmo_rano_change(QString text){
    parameters.kosmo.rano.append(text);
    actualice_list(15);
}


void Graphics::on_posilki_checked(){
    actualice_list(15);
    readListFromIniFile(posilki_list, "PosilkiLog");
    fillFoodTable(food_table_model, posilki_list, false);
    
    // ui->comboBox_17->clear();
    // ui->comboBox_17->addItems(posilki_list);
    
}
void Graphics::on_przekaski_checked(){
    actualice_list(15);
    readListFromIniFile(przekaski_list, "PrzekaskiLog");
    fillFoodTable(food_table_model, przekaski_list, false);
    // ui->comboBox_17->clear();
    // ui->comboBox_17->addItems(przekaski_list);
    
}

void Graphics::on_owoce_checked(){
    actualice_list(15);
    readListFromIniFile(owoce_list, "OwoceLog");
    fillFoodTable(food_table_model, owoce_list, false);
    //  ui->comboBox_17->clear();
    //  ui->comboBox_17->addItems(owoce_list);
    
}

void Graphics::on_warzywa_checked(){
    actualice_list(15);
    readListFromIniFile(warzywa_list, "WarzywaLog");
    fillFoodTable(food_table_model, warzywa_list, false);
    // ui->comboBox_17->clear();
    //ui->comboBox_17->addItems(warzywa_list);
    
}
void Graphics::on_inne_checked(){
    actualice_list(15);
    readListFromIniFile(inne_list, "InneLog");
    fillFoodTable(food_table_model, inne_list, false);
    //ui->comboBox_17->clear();
    //ui->comboBox_17->addItems(inne_list);
    
}

void Graphics::on_set_rano_tab(){
    actualice_list(15);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->pushButton_26->setChecked(true);
    ui->pushButton_27->setChecked(false);
    
}
void Graphics::on_set_wieczor_tab(){
    actualice_list(15);
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->pushButton_27->setChecked(true);
    ui->pushButton_26->setChecked(false);
}

void Graphics::fillFoodTable(QStandardItemModel *model, QStringList list, bool clear){
    QStringList _model_items;
    _model_items.append("NAZWA");
    _model_items.append("TYP");
    food_table_model = new QStandardItemModel();
    food_table_model->setHorizontalHeaderLabels( _model_items);
    fillTable(model, list, clear);
}


void Graphics::fillTable(QStandardItemModel *model, QStringList list, bool clear){
    
    
    if(clear){
        model->clear();
    }
    
    ui->tableView_3->setModel(model);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch);
    
    QList<QStandardItem *> newRow;
    for(int i = 0; i < list.size(); i++){
        newRow.clear();
        newRow.append(new QStandardItem(list.at(i)));
        model->appendRow(newRow);
        
    }
    
}

void Graphics::on_sniadanie_checked(){
    actualice_list(16);
}

void Graphics::on_obiad_checked(){
    actualice_list(16);
}

void Graphics::on_kolacja_checked(){
    actualice_list(16);
}

void Graphics::on_inne_posilki_checked(){
    actualice_list(16);
}


void Graphics::on_dodaj_food_clicked(){
    actualice_list(16);
    if(ui->radioButton->isChecked()){
        qDebug() << "PosilkiLog";
        posilki_list.append(ui->textEdit_4->toPlainText());
        qDebug() << "ui->textEdit_4->toPlainText() = " << ui->textEdit_4->toPlainText();
        writeListToIniFile(posilki_list, "PosilkiLog");
        readListFromIniFile(posilki_list, "PosilkiLog");
        fillFoodTable(food_table_model, posilki_list, false);
        
        // ui->comboBox_17->clear();
        // ui->comboBox_17->addItems( posilki_list);
        
        
    }else if(ui->radioButton_2->isChecked()){
        qDebug() << "PrzekaskiLog";
        przekaski_list.append(ui->textEdit_4->toPlainText());
        writeListToIniFile(przekaski_list, "PrzekaskiLog");
        readListFromIniFile(przekaski_list, "PrzekaskiLog");
        fillFoodTable(food_table_model, przekaski_list, false);
        //ui->comboBox_17->clear();
        //ui->comboBox_17->addItems( przekaski_list);
        
    }else if(ui->radioButton_3->isChecked()){
        qDebug() << "OwoceLog";
        owoce_list.append(ui->textEdit_4->toPlainText());
        writeListToIniFile(owoce_list, "OwoceLog");
        readListFromIniFile(owoce_list, "OwoceLog");
        fillFoodTable(food_table_model, owoce_list, false);
        // ui->comboBox_17->clear();
        // ui->comboBox_17->addItems( owoce_list);
        
    }else if(ui->radioButton_4->isChecked()){
        qDebug() << "WarzywaLog";
        warzywa_list.append(ui->textEdit_4->toPlainText());
        writeListToIniFile(warzywa_list, "WarzywaLog");
        readListFromIniFile(warzywa_list, "WarzywaLog");
        fillFoodTable(food_table_model, warzywa_list, false);
        // ui->comboBox_17->clear();
        // ui->comboBox_17->addItems( warzywa_list);
        
    }else if(ui->radioButton_5->isChecked()){
        qDebug() << "InneLog";
        inne_list.append(ui->textEdit_4->toPlainText());
        writeListToIniFile(inne_list, "InneLog");
        readListFromIniFile(inne_list, "InneLog");
        fillFoodTable(food_table_model, inne_list, false);
        // ui->comboBox_17->clear();
        //  ui->comboBox_17->addItems( inne_list);
    }
    
    ui->textEdit_4->clear();
}




void Graphics::on_tableView_rano_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << ui->tableView->viewport()->mapToGlobal(pos);
}

void Graphics::on_tableView_wieczor_customContextMenuRequested(const QPoint &pos){
    qDebug() << ui->tableView_2->viewport()->mapToGlobal(pos);
}




void Graphics::on_tableView_clicked(QModelIndex index)
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if(selection.count() > 0){
        QModelIndex index = selection.at(0);
    }


    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setText("Co zrobić z:  "+kosmo_list.at(index.row())+" ?");
    int ret = msgBox.exec();


    if(ret == QMessageBox::Save){
        parameters.kosmo.rano.append(kosmo_list.at(index.row()));
        QColor rowColor = Qt::red;
        ui->tableView->model()->setData(ui->tableView->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
    }else if(ret == QMessageBox::Discard){
        removeItemFromList(kosmo_list, "KosmoList", kosmo_list.at(index.row()));
    }

}

void Graphics::on_tableView_2_clicked(QModelIndex index){
    
    QModelIndexList selection = ui->tableView_2->selectionModel()->selectedRows();
    if(selection.count() > 0){
        QModelIndex index = selection.at(0);
    }



    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setText("Czy Dodac \""+kosmo_list.at(index.row())+"\" ?");
    int ret = msgBox.exec();

    QColor rowColor = Qt::red;

    if(ret  == QMessageBox::Save){
        parameters.kosmo.wieczor.append(kosmo_list.at(index.row()));
        QColor rowColor = Qt::red;
        ui->tableView_2->model()->setData(ui->tableView_2->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
    } else if(ret == QMessageBox::Discard){
        removeItemFromList(kosmo_list, "KosmoList", kosmo_list.at(index.row()));
    }
}


QStringList Graphics::getActualFoodList(){
    if(ui->radioButton->isChecked()){
        return posilki_list;
    }
    else if(ui->radioButton_2->isChecked()){
        return przekaski_list;
    }
    else if(ui->radioButton_3->isChecked()){
        return owoce_list;
    }
    else if(ui->radioButton_4->isChecked()){
        return warzywa_list;
    }
    else if(ui->radioButton_5->isChecked()){
        return inne_list;
    }
}

void Graphics::on_tableView_3_clicked(QModelIndex index){
    
    actualice_list(16);
    QColor rowColor = Qt::red;

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setText("Co zrobić : \""+getActualFoodList().at(index.row())+"\" ?");
    int ret = msgBox.exec();



    if (ret == QMessageBox::Save) {
        if(ui->radioButton_6->isChecked() ){
            parameters.food.sniadanie.append(getActualFoodList().at(index.row()));
            ui->tableView_3->model()->setData(ui->tableView_3->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
            qDebug() << parameters.food.sniadanie;
        }
        if(ui->radioButton_7->isChecked() ){
            parameters.food.obiad.append(getActualFoodList().at(index.row()));
            ui->tableView_3->model()->setData(ui->tableView_3->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
            qDebug() << parameters.food.obiad;
        }
        if(ui->radioButton_8->isChecked() ){
            parameters.food.kolacja.append(getActualFoodList().at(index.row()));
            ui->tableView_3->model()->setData(ui->tableView_3->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
            qDebug() << parameters.food.kolacja;
        }
        if(ui->radioButton_9->isChecked() ){
            parameters.food.inne.append(getActualFoodList().at(index.row()));
            ui->tableView_3->model()->setData(ui->tableView_3->model()->index(index.row(), 0),rowColor, Qt::ForegroundRole );
            qDebug() << parameters.food.inne;
        }
    }
    else if(ret ==  QMessageBox::Discard) {
        if(ui->radioButton->isChecked() ){
            removeItemFromList(posilki_list, "PosilkiLog", posilki_list.at(index.row()));
            readListFromIniFile(posilki_list, "PosilkiLog");
            fillFoodTable(food_table_model, posilki_list, false);
        }
        if(ui->radioButton_2->isChecked() ){
            removeItemFromList(przekaski_list, "PrzekaskiLog", przekaski_list.at(index.row()));
            readListFromIniFile(przekaski_list, "PrzekaskiLog");
            fillFoodTable(food_table_model, przekaski_list, false);
        }
        if(ui->radioButton_3->isChecked() ){
            removeItemFromList(owoce_list, "OwoceLog", owoce_list.at(index.row()));
            readListFromIniFile(owoce_list, "OwoceLog");
            fillFoodTable(food_table_model, owoce_list, false);
        }
        if(ui->radioButton_4->isChecked() ){
            removeItemFromList(warzywa_list, "WarzywaLog", warzywa_list.at(index.row()));
            readListFromIniFile(warzywa_list, "WarzywaLog");
            fillFoodTable(food_table_model, warzywa_list, false);
        }
        if(ui->radioButton_5->isChecked() ){
            removeItemFromList(inne_list, "InneLog", inne_list.at(index.row()));
            readListFromIniFile(inne_list, "InneLog");
            fillFoodTable(food_table_model, inne_list, false);
        }

    }
}

void  Graphics::on_notice_changed(){
    
    actualice_list(14);
    qDebug() << ui->textEdit_2->toPlainText();
    parameters.notice.str_param = ui->textEdit_2->toPlainText();
}














