#include "log.h"

Log::Log( int x, QObject *parent) : QObject(parent),  xlsx(LOG_NAME)
{

    if(x == 1){
        initLog();
    }


}

void Log::initLog() {

    xlsx.write("A1", "Data");
    xlsx.write("B1", "Period");
    xlsx.write("C1", "HeadAche");
    xlsx.write("D1", "Stomachache");
    xlsx.write("E1", "STOOO");
    xlsx.write("F1", "ALCO");
    xlsx.write("G1", "water");
    xlsx.write("H1", "sleep");
    xlsx.write("I1", "exx");
    xlsx.write("J1", "scare");
    xlsx.write("K1", "pills");
    xlsx.write("L1", "chip");
    xlsx.write("M1", "sweet");

    xlsx.save();
    qDebug() << "Jestem w initLog()";

}

bool Log::saveLog(Parameters_t param, int last_record) {



    xlsx.write("A"+QString::number(last_record), QDateTime::currentDateTime().date().toString());

    QString temp;
    if(param.period.state){
        temp = "TAK: "+QString::number(param.periodache.value);
    }else {
        temp = "NIE";
    }
    xlsx.write("B"+QString::number(last_record), temp);


    if(param.headache.state){
        temp = "TAK: "+QString::number(param.headache.value);
    }else {
        temp = "NIE";
    }
    xlsx.write("C"+QString::number(last_record), temp);


    if(param.stomachache.state){
        temp = "TAK: "+QString::number(param.stomachache.value);
    }else {
        temp = "NIE";
    }
    xlsx.write("D"+QString::number(last_record), temp);

    temp = "ILE = "+QString::number(param.sto.value_1)+" / JAKI = "+QString::number(param.sto.value_2);
    xlsx.write("E"+QString::number(last_record), temp);

    if(param.alco.state){
        temp = "TAK: ";
    }else {
        temp = "NIE";
    }
    xlsx.write("F"+QString::number(last_record), temp);

    temp = QString::number(param.water.value)+" ml";
    xlsx.write("G"+QString::number(last_record), temp);

    if(param.sleep.state){
        temp = "DOBRY ";
    }else {
        temp = "ZŁY";
    }
    xlsx.write("H"+QString::number(last_record), temp);


    if(param.exx.state){
        temp = "TAK :) ";
    }else {
        temp = "NIE :(";
    }
    xlsx.write("I"+QString::number(last_record), temp);


    temp = QString::number(param.scare.value);
    xlsx.write("J"+QString::number(last_record), temp);

    if(param.pills.state){
        temp = "TAK";
    }else {
        temp = "NIE";
    }
    xlsx.write("K"+QString::number(last_record), temp);

    if(param.chips.state){
        temp = "TAK";
    }else {
        temp = "NIE";
    }
    xlsx.write("L"+QString::number(last_record), temp);


    if(param.sweet.state){
        temp = "TAK";
    }else {
        temp = "NIE";
    }
    xlsx.write("M"+QString::number(last_record), temp);



    xlsx.save();
    return true;




}
