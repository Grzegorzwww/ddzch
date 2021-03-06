#ifndef DEFINES_H
#define DEFINES_H

#include <QString>
#include <QDateTimeEdit>
#include <QString>
#include <iostream>




const QString GRUPA_USTAWIEN = "settings_group";
const QString GRUPA_KOSMO = "kosmo_group";


const QString OSTATNIE_WYLACZENIE_KOMPUTERA = "ostatnie_wylaczenie";
const QString REKORD_XLSX_DO_ZAPISU = "ostatni_record_xlsx";
const QString LISTA_KOSMO = "kosmo_list";


typedef struct app_settings_s {
  bool was_run_today;
  QDateTime last_app_turn_off;
  QString last_log_record;

} app_settings_t;



static const int MAIN_MENU_INDEX = 0;

static const int WPROWADZ_WSZYSTKO_INDEX = 1;
static const int WPROWADZ_WSZYSTKO_CZ2_INDEX = 4;
static const int WPROWADZ_WSZYSTKO_CZ3_INDEX= 5;
static const int WPROWADZ_WSZYSTKO_CZ4_INDEX = 6;
static const int WPROWADZ_KOSMO_INDEX = 7;
static const int WPROWADZ_FOOD_INDEX = 8;
static const int LAST_INFO_INDEX = 9;

static const int MODYFIKUJ_ZAPISY_INDEX = 2;
static const int DODAJ_PARAMETR_INDEX = 3;


typedef enum {YES_NO = 0, YES_NO_VALUE, VALUE_INT_ONLY, DOUBLE_VALUE_INT_ONLY, VALUE_STR_ONLY, GOOD_BAD_TYPE, FACE_STATE, FOOD } param_type_t ;


typedef struct yesno_token_s {
    int no;
    param_type_t param_type;
    bool state;
} yesno_token_t;

typedef struct yesno_value_token_s {
    int no;
    param_type_t param_type;
    bool state;
    int value;
} yesno_value_token_t;

typedef struct value_token_s {
    int no;
    param_type_t param_type;
    int value;
} value_token_t;

typedef struct double_value_token_s {
    int no;
    param_type_t param_type;
    int value_1;
    int value_2;
} double_value_token_t;



typedef struct value_str_token_s {
    int no;
    param_type_t param_type;
    QString str_param;
} value_str_token_t;

typedef struct good_bad_token_s {
    int no;
    param_type_t param_type;
    bool good_bad_state;
} good_bad_token_t;




typedef struct face_token_s {
    QString place;
    QString what;
    QString trend;

}face_token_t;


typedef struct used_kosmo_token_s {
    int no;
    param_type_t param_type;
    QStringList rano;
    QStringList wieczor;



} used_kosmo_token_t;


typedef struct food_token_s {
    int no;
    param_type_t param_type;
    QStringList sniadanie;
    QStringList obiad;
    QStringList kolacja;
    QStringList inne;
} food_token_t;



typedef struct Parameters_s {
    yesno_token_t period;
    double_value_token_t periodache;
    yesno_value_token_t headache;
    yesno_value_token_t stomachache;
    double_value_token_t sto;
    yesno_token_t alco;
    value_token_t water;
    face_token_t face_1;
    face_token_t face_2;
    face_token_t face_3;
    face_token_t face_4;
    face_token_t face_trend;
    yesno_token_t sleep;
    yesno_token_t exx;
    value_token_t scare;
    yesno_token_t pills;
    yesno_token_t chips;
    yesno_token_t sweet;
    used_kosmo_token_t kosmo;
    food_token_t food;
    value_str_token_t notice;

    QDateTime read_date_time;

} Parameters_t;


#endif // DEFINES_H


