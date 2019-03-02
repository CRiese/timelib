/**
 * Author : Catharina Riese
 * Date : 26.02.2019
 * Header zur time.c
 **/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED


// erstellen des structs time
struct time
{
    int day;
    int month;
    int year;
};

// deklaration der Prototypen
int isleapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct time date);
int day_of_the_year(struct time date);
struct time input_date(struct time date);

#endif // TIME_H_INCLUDED
