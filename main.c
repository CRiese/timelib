/**
 * Author : Catharina Riese
 * Date : 18.12.2018
 * Vom eingegebenem Datum soll ermittelt werden welcher Tag, dass im Jahr ist
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 * Die Funktion ermittelt für ein übergebenes Jahr des gregorianischen Kalenders,
 * ob es sich um ein Schaltjahr handelt.
 **/

 int isLeapyear(int year)
{
    if ( year % 4 != 0)
    {
        return 0;
    }

    else if( year % 4 == 0)
    {
    if ( year % 100 != 0 )
    {
        return 1;
    }

    else if (year % 100 == 0 && year % 400 == 0)
    {
    if(year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
    }

    else
    {
        return -1;
    }
}

/**
 * Einlesen von 3 Ganzzahlenwerte für Tag, Monat, Jahr
 *
 **/
 int input_date(int day, int month, int year)
 {

 }

 /**
 * Bestimmung für den gegebenen Monat eines gegebenen Jahres,
 * wie viele Tage der Moant hat
 **/
 int get_days_for_month(int month, int year)
 {
    int array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
 }

 /**
 * überprüft ob das Datum gültig ist.
 * Zeitraum von 1.1.1582 und 31.12.2400
 **/
 int exists_date(int day, int month, int year)
 {
    if (year >= 1582 && year <= 2400)
    {
        if (month >= 1 && month <= 12)
        {
            if (day >= 1 && day <= 31)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
            {
                return 0;
            }
    }
    else
            {
                return 0;
            }
 }

/**
 * berechent für das gegebene Datum die Nummer des Tages,
 * von Jahresbeginn an gezählt
 **/
int day_of_the_year(int day, int month, int year)
{


    return 0;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));

    printf("Tag ist korrekt: %i\n", exists_date(31, 12, 2018));
    return 0;
}
