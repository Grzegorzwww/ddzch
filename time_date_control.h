#ifndef TIME_DATE_CONTROL_H
#define TIME_DATE_CONTROL_H

#include <QObject>
#include <QSettings>
#include <QTime>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include "defines.h"

class TimeDateControl
{
public:
    TimeDateControl();
    ~TimeDateControl();


    void load_app_settings();
    bool check_first_turn_on(int *days_diff);




    int getLastRecord() const;

private:

    QDateTime *actualdatetime;
    QDateTime *prevdatetime;
    int last_exel_record;




};

#endif // TIME_DATE_CONTROL_H
