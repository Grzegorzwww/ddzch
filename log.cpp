#include "log.h"

Log::Log( int x, QString path = LOG_NAME, QObject *parent) : QObject(parent), xlsx(path)
{







    if(x == 1){
        initLog();
    }



    // xlsx(LOG_NAME)
     //= QXlsx::Document(xlsx_write_file_name);
   // QDir::setPath(mediaDir.toString());


}

void Log::initLog() {

    xlsx.write("A1", "Data");
    xlsx.write("B1", "Okres");
    xlsx.write("C1", "Ból Głowy");
    xlsx.write("D1", "Ból Brzucha");
    xlsx.write("E1", "Kupka");
    xlsx.write("F1", "Alkochol");
    xlsx.write("G1", "Woda");
    xlsx.write("H1", "Sen");
    xlsx.write("I1", "Exs");
    xlsx.write("J1", "Nerwy");
    xlsx.write("K1", "Euthyrox");
    xlsx.write("L1", "Czipsy");
    xlsx.write("M1", "Słodyczne");
    xlsx.write("N1", "Twarz 1");
    xlsx.write("O1", "Twarz 2");
    xlsx.write("P1", "Twarz 3");
    xlsx.write("Q1", "Twarz 4");
    xlsx.write("R1", "TREND TWARZY");
    xlsx.write("S1", "Kosmetyki rano");
    xlsx.write("T1", "Kosmetyki wieczorem");
    xlsx.write("U1", "SNIADANIE");
    xlsx.write("V1", "OBIAD");
    xlsx.write("W1", "KOLACJA");
    xlsx.write("X1", "INNE");
    xlsx.write("Y1", "NOTATKI: ");

    xlsx.save();
   // xlsx.saveAs( xlsx_write_file_name);




    qDebug() << "Jestem w initLog()";

}

bool Log::saveLog(Parameters_t param, int last_record) {



    xlsx.write("A"+QString::number(last_record), QDateTime::currentDateTime().date().toString());



    QString temp;
    if(param.period.state){
        temp = "TAK: "+QString::number(param.periodache.value_1)+" : BOL: "+ QString::number(param.periodache.value_2);
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

    temp = param.face_1.place+" - "+param.face_1.what;
    xlsx.write("N"+QString::number(last_record), temp);

    temp = param.face_2.place+" - "+param.face_2.what;
    xlsx.write("O"+QString::number(last_record), temp);

    temp = param.face_3.place+" - "+param.face_3.what;
    xlsx.write("P"+QString::number(last_record), temp);

    temp = param.face_4.place+" - "+param.face_4.what;
    xlsx.write("Q"+QString::number(last_record), temp);

    temp = param.face_trend.trend;
    xlsx.write("R"+QString::number(last_record), temp);

    //TODO:

    temp.clear();
    for(int i = 0; i < param.kosmo.rano.size(); i++){
        if(param.kosmo.rano.at(i) != param.kosmo.rano.last())
            temp += param.kosmo.rano.at(i)+" - ";
        else
            temp += param.kosmo.rano.at(i);
    }
    xlsx.write("S"+QString::number(last_record), temp);


    temp.clear();
    for(int i = 0; i < param.kosmo.wieczor.size(); i++){
        if(param.kosmo.wieczor.at(i) != param.kosmo.wieczor.last())
            temp += param.kosmo.wieczor.at(i)+" - ";
        else
            temp += param.kosmo.wieczor.at(i);
    }
    xlsx.write("T"+QString::number(last_record), temp);


    temp.clear();
    for(int i = 0; i < param.food.sniadanie.size(); i++){
        if(param.food.sniadanie.at(i) != param.food.sniadanie.last())
            temp += param.food.sniadanie.at(i)+" - ";
        else
            temp += param.food.sniadanie.at(i);
    }
    xlsx.write("U"+QString::number(last_record), temp);

    temp.clear();
    for(int i = 0; i < param.food.obiad.size(); i++){
        if(param.food.obiad.at(i) != param.food.obiad.last())
            temp += param.food.obiad.at(i)+" - ";
        else
            temp += param.food.obiad.at(i);
    }
    xlsx.write("V"+QString::number(last_record), temp);

    temp.clear();
    for(int i = 0; i < param.food.kolacja.size(); i++){
        if(param.food.kolacja.at(i) != param.food.kolacja.last())
            temp += param.food.kolacja.at(i)+" - ";
        else
            temp += param.food.kolacja.at(i);
    }
    xlsx.write("W"+QString::number(last_record), temp);

    temp.clear();
    for(int i = 0; i < param.food.inne.size(); i++){
        if(param.food.inne.at(i) != param.food.inne.last())
            temp += param.food.inne.at(i)+" - ";
        else
            temp += param.food.inne.at(i);
    }
    xlsx.write("X"+QString::number(last_record), temp);


    xlsx.write("Y"+QString::number(last_record), param.notice.str_param);







    xlsx.save();
     //xlsx.saveAs( xlsx_write_file_name);
    return true;

}


bool Log::readLog(Parameters_t &param, int last_record){

    QString read_str;

    //   param.read_date_time =  QDateTime(QDateTime::fromString(xlsx.read("A"+QString::number(last_record)).toString()/*"dd.MM.yyyy HH:mm"*/));
    read_str = xlsx.read("A"+QString::number(last_record)).toString();
    if(!read_str.isEmpty()){
        read_str = xlsx.read("B"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.period.state = true;
            param.periodache.value_1 = read_str.split( ": " )[1].toInt();
             param.periodache.value_2 = read_str.split( ": " )[3].toInt(); //TODO:
        }else {
            param.period.state = false;
            param.periodache.value_1 = 1;
            param.periodache.value_2 = 1;
        }


        read_str = xlsx.read("C"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.headache.state = true;
            param.headache.value = read_str.split( ": " )[1].toInt();
        }else {
            param.headache.state = false;
            param.headache.value = 1;
        }


        read_str = xlsx.read("D"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.stomachache.state = true;
            param.stomachache.value = read_str.split( ": " )[1].toInt();
        }else {
            param.stomachache.state = false;
            param.stomachache.value = 1;
        }

        read_str = xlsx.read("E"+QString::number(last_record)).toString();
        QString temp = read_str.split( "/" )[0];
        param.sto.value_1 = temp.split("= ")[1].toInt();

        temp = read_str.split( "/" )[1];
        param.sto.value_2 = temp.split("= ")[1].toInt();



        read_str = xlsx.read("F"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.alco.state = true;
        }else {
            param.alco.state = false;
        }
        read_str = xlsx.read("G"+QString::number(last_record)).toString();
        param.water.value =   read_str.replace(" ml", "").toInt();


        read_str = xlsx.read("H"+QString::number(last_record)).toString();
        if(read_str.contains("DOBRY",  Qt::CaseInsensitive)){
            param.sleep.state = true;
        }else {
            param.sleep.state = false;
        }

        read_str = xlsx.read("I"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.exx.state = true;
        }else {
            param.exx.state = false;
        }

        read_str = xlsx.read("J"+QString::number(last_record)).toString();
        param.scare.value = read_str.toInt();

        read_str = xlsx.read("K"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.pills.state = true;
        }else {
            param.pills.state = false;
        }

        read_str = xlsx.read("L"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.chips.state = true;
        }else {
            param.chips.state = false;
        }

        read_str = xlsx.read("M"+QString::number(last_record)).toString();
        if(read_str.contains("TAK",  Qt::CaseInsensitive)){
            param.sweet.state = true;
        }else {
            param.sweet.state = false;
        }

        read_str = xlsx.read("N"+QString::number(last_record)).toString();
        if(read_str.contains("brak",  Qt::CaseInsensitive)){

        }else {
            param.face_1.place = read_str.split(" - ")[0];
            param.face_1.what = read_str.split(" - ")[1];
        }
        read_str = xlsx.read("O"+QString::number(last_record)).toString();
        if(read_str.contains("brak",  Qt::CaseInsensitive)){

        }else {
            param.face_2.place = read_str.split(" - ")[0];
            param.face_2.what = read_str.split(" - ")[1];
        }
        read_str = xlsx.read("P"+QString::number(last_record)).toString();
        if(read_str.contains("brak",  Qt::CaseInsensitive)){

        }else {
            param.face_3.place = read_str.split(" - ")[0];
            param.face_3.what = read_str.split(" - ")[1];
        }
        read_str = xlsx.read("Q"+QString::number(last_record)).toString();
        if(read_str.contains("brak",  Qt::CaseInsensitive)){

        }else {
            param.face_4.place = read_str.split(" - ")[0];
            param.face_4.what = read_str.split(" - ")[1];
        }

        read_str = xlsx.read("R"+QString::number(last_record)).toString();
        param.face_trend.trend = read_str;



        read_str = xlsx.read("S"+QString::number(last_record)).toString();
        param.kosmo.rano = read_str.split(" - ");
        for(int i = 0; i < param.kosmo.rano.size(); i++ )
            param.kosmo.rano[i].replace("-","");



        read_str = xlsx.read("T"+QString::number(last_record)).toString();
        param.kosmo.wieczor = read_str.split(" -  ");
        for(int i = 0; i < param.kosmo.wieczor.size(); i++ )
            param.kosmo.wieczor[i].replace("-","");


        read_str = xlsx.read("U"+QString::number(last_record)).toString();
        param.food.sniadanie = read_str.split(" -  ");
        for(int i = 0; i < param.food.sniadanie.size(); i++ )
            param.food.sniadanie[i].replace("-","");


        read_str = xlsx.read("V"+QString::number(last_record)).toString();
        param.food.obiad = read_str.split(" -  ");
        for(int i = 0; i < param.food.obiad.size(); i++ )
            param.food.obiad[i].replace("-","");


        read_str = xlsx.read("W"+QString::number(last_record)).toString();
        param.food.kolacja = read_str.split(" -  ");
        for(int i = 0; i < param.food.kolacja.size(); i++ )
            param.food.kolacja[i].replace("-","");


        read_str = xlsx.read("X"+QString::number(last_record)).toString();
        param.food.inne = read_str.split(" -  ");
        for(int i = 0; i < param.food.inne.size(); i++ )
            param.food.inne[i].replace("-","");


        read_str = xlsx.read("Y"+QString::number(last_record)).toString();
        param.notice.str_param = read_str;




        return true;
    }
    else return false;

}
