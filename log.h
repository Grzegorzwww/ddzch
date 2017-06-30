#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QString>
#include <defines.h>
#include <QDebug>
#include "xlsxdocument.h"


static const QString LOG_NAME = "zapisane_dane.xlsx";

class Log : public QObject
{
    Q_OBJECT
public:
    explicit Log(int x, QObject *parent = 0);
    bool saveLog(Parameters_t param, int last_record);
    bool readLog(Parameters_t &param, int last_record);

private:
    QXlsx::Document xlsx;
    int last_record;

    void initLog();



signals:

public slots:
};

#endif // LOG_H
