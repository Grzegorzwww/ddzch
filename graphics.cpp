#include "graphics.h"

Graphics::Graphics(Ui::MainWindow *_ui, QWidget *parent) : QWidget(parent),ui(_ui)
{




    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(on_menu_wprowadz_wszystko_clicked(bool)));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(on_menu_modyfikuj_wybrane_clicked(bool)));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(on_wstecz_clicked(bool)));


}
void Graphics::on_menu_wprowadz_wszystko_clicked(bool x){
    qDebug() << "on_menu_wprowadz_wszystko_clicked";
    ui->stackedWidget->setCurrentIndex(WPROWADZ_WSZYSTKO_INDEX);
    control_tab(WPROWADZ_WSZYSTKO_INDEX);

}
void Graphics::on_menu_modyfikuj_wybrane_clicked(bool x){
    qDebug() << "on_menu_modyfikuj_wybrane_clicked";
    ui->stackedWidget->setCurrentIndex(MODYFIKUJ_ZAPISY_INDEX);
    control_tab(MODYFIKUJ_ZAPISY_INDEX);

}
void Graphics::control_tab(int actual){
            actual_tab.push_back(actual);
}
void Graphics::on_wstecz_clicked(bool x){
    if(!actual_tab.isEmpty()){
        ui->stackedWidget->setCurrentIndex(actual_tab.last());
        actual_tab.removeLast();
    }
}