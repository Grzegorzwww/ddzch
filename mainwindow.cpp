#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtXlsx>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAndroidJniObject mediaDir = QAndroidJniObject::callStaticObjectMethod("android/os/Environment", "getExternalStorageDirectory", "()Ljava/io/File;");
    QAndroidJniObject mediaPath = mediaDir.callObjectMethod( "getAbsolutePath", "()Ljava/lang/String;" );
   QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
   QAndroidJniObject package = activity.callObjectMethod("getPackageName", "()Ljava/lang/String;");
   QDir::setCurrent(mediaDir.toString());
    QString  xlsx_write_file_name = LOG_NAME;


    graphics = new Graphics(ui,this);
    setDarkTheme();

    time_date_control = new TimeDateControl();
    time_date_control->load_app_settings();
    log = new Log( time_date_control->getLastRecord(), xlsx_write_file_name );

    int diff;
    if(time_date_control->check_first_turn_on(&diff)){
        qDebug() << "pierwsze wlaczenie";
       ;
    }
    else{
        qDebug() << "kolejne wlaczenie";
        log->readLog(Param,time_date_control->getLastRecord());
        graphics->actualiceGraphicsGUI(Param);
    }

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_save_and_close_app()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_cancel_and_close_app()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graphics;

}


void MainWindow::setDarkTheme(void){

    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);

    ui->radioButton->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_2->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_3->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_4->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_5->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");

    ui->radioButton_6->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_7->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_8->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");
    ui->radioButton_9->setStyleSheet("QRadioButton::indicator:checked { background-color: red;border: 2px solid white;} QRadioButton::indicator:unchecked {  background-color: while; border: 2px solid white;}");



    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

void MainWindow::on_save_and_close_app(){
     graphics->getParameters(Param);
    if(log->saveLog(Param,  time_date_control->getLastRecord())){
        if(ui->stackedWidget->currentIndex() == WPROWADZ_FOOD_INDEX ){
            ui->stackedWidget->setCurrentIndex(LAST_INFO_INDEX);
            vibrator.vibrate(300);
            QTimer::singleShot(1500, this, SLOT(close()));
        }
        else
            this->close();
    }
}

void MainWindow::on_cancel_and_close_app(){
    ui->stackedWidget->setCurrentIndex(LAST_INFO_INDEX);
    QTimer::singleShot(1500, this, SLOT(close()));
}



