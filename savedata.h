#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <QWidget>

class SaveData :public QWidget
{
        Q_OBJECT

private:

    void on_save_data_clicked(bool x);


public:
    SaveData();



};

#endif // SAVEDATA_H
