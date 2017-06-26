#include "time_date_control.h"

TimeDateControl::TimeDateControl()
{






      //actualdatetime = new QDateTime(QDate(1988,9,16), QTime(14,0,0).fromString("dd.MM.yyyy HH:mm"));
      actualdatetime = new QDateTime(QDateTime::currentDateTime()/*.fromString("dd.MM.yyyy HH:mm")*/);
      last_exel_record = 1;

    //prevdatetime = new QDateTime(QDate(1988,9,17), QTime(14,0,0).fromString("dd.MM.yyyy HH:mm"));





}
  TimeDateControl::~TimeDateControl(){
     // delete actualdatetime;
  }

int TimeDateControl::getLastRecord() const {
    return last_exel_record;
}


 void TimeDateControl::load_app_settings(){

        QSettings settings;
        settings.beginGroup( GRUPA_USTAWIEN);
        QDateTime temp = settings.value( OSTATNIE_WYLACZENIE_KOMPUTERA,  QDateTime(QDate(1988,9,17), QTime(14,0,0).fromString("dd.MM.yyyy HH:mm"))).toDateTime();
       prevdatetime = new QDateTime(temp);
        last_exel_record = settings.value( REKORD_XLSX_DO_ZAPISU,  1).toInt();

        qDebug() << "last_exel_record = "<<last_exel_record;


        settings.endGroup();

 }

 bool TimeDateControl::check_first_turn_on(){


     qDebug() << "prevdatetime->date() - "<<prevdatetime->date().toString();
     qDebug() << "actualdatetime->date() - "<<actualdatetime->date().toString();



        if( prevdatetime->date() < actualdatetime->date()){


            qDebug() << "check_first_turn_on()";
            QSettings settings;
            settings.beginGroup( GRUPA_USTAWIEN);
            settings.setValue( OSTATNIE_WYLACZENIE_KOMPUTERA, QDateTime( QDateTime(QDateTime::currentDateTime()/*.fromString("dd.MM.yyyy HH:mm")*/)));
            settings.setValue(REKORD_XLSX_DO_ZAPISU, ++last_exel_record);
            settings.endGroup();

            return true;
        }
        else {
            return false;
        }


 }
