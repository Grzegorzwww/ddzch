#ifndef DEFINES_H
#define DEFINES_H

#include <QString>
#include <QDateTimeEdit>
#include <QString>
#include <iostream>




const QString GRUPA_USTAWIEN = "settings_group";
const QString OSTATNIE_WYLACZENIE_KOMPUTERA = "ostatnie_wylaczenie";


typedef struct app_settings_s {
  bool was_run_today;
  QDateTime last_app_turn_off;
  QString last_log_record;

} app_settings_s;



static const int MAIN_MENU_INDEX = 0;

static const int WPROWADZ_WSZYSTKO_INDEX = 1;
static const int WPROWADZ_WSZYSTKO_CZ2_INDEX = 4;
static const int WPROWADZ_WSZYSTKO_CZ3_INDEX= 5;
static const int WPROWADZ_WSZYSTKO_CZ4_INDEX = 6;

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


typedef struct face_state_token_s {
    int no;
    param_type_t param_type;


} face_state_token_t;


typedef struct food_token_s {
    int no;
    param_type_t param_type;
    //TODO: Zaimplementowac typ danych przechowujacy jedzenie
} food_token_t;



typedef struct Parameters_s {
    yesno_token_t period;
    value_token_t periodache;
    yesno_value_token_t headache;
    yesno_value_token_t stomachache;
    double_value_token_t sto;
    yesno_token_t alco;
    value_token_t water;
    face_token_t face;
    yesno_token_s sleep;
    yesno_token_s exx;
    yesno_token_s scare;
    yesno_token_s pills;
    yesno_token_s chips;
    yesno_token_s sweet;
    food_token_t food;

} Parameters_t;


#endif // DEFINES_H


