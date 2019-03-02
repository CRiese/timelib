/**
* Author : Catharina Riese
* Date : 26.02.2019
* Bibilothek time.c, alles �ber Zeiten
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"


/**
 * Die Funktion ermittelt f�r ein �bergebenes Jahr des gregorianischen Kalenders,
 * ob es sich um ein Schaltjahr handelt.
 * �bergabeparameter : year:int
 * R�ckgabewert : 1, wenn �bergebenes Jahr ein Schaltjahr ist, 0, wenn �bergebenes Jahr kein
 * Schaltjahr ist, -1, wenn ein ung�ltiges Jahr �bergeben wurde
 **/

int isleapyear(int year)
{
    // ist das Jahr ohne Rest durch 4 teilbar
    if (year % 4 != 0)
    {
        return 0;
    }

    else if(year % 4 == 0)
    {
        // ist das Jahr ohne Rest durch 100 teilbar
        if (year % 100 != 0 )
        {
            return 1;
        }

        else if (year % 100 == 0 && year % 400 == 0)
        {
            // ist das Jahr ohne Rest durch 400 teilbar
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
 * Die Funktion bestimmt f�r einen gegebenen Monat
 * eines gegebenen Jahres, wie viele Tage der Monat hat.
 * Der Wert des Monats muss zwischen 1 und 12 liegen.
 * Schaltjahre werden ber�cksichtigt.
 * �bergabeparameter : month:int, year:int
 * R�ckgabewert : Anzahl von Tagen:int, 28-31, wenn ein g�ltiger Monat eingegeben wurde,
 * -1, wenn ein ung�ltiger Moant oder Jahr �bergeben wurde
 **/
int get_days_for_month(int month, int year)
{
    // ausgabe, wenn es kein Schaltjahr ist
    if (isleapyear(year) == 0)
    {
        const int array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return array[month-1];
    }

    // ausgabe, wenn es ein Schaltjahr ist
    if (isleapyear(year) == 1)
    {
        const int array[] = {31,29,31,30,31,30,31,31,30,31,30,31};
        return array[month-1];
    }
}

/**
* �berpr�ft ob das Datum g�ltig ist.
* Im Zeitraum von 1.1.1582 und 31.12.2400
* �bergabeparameter : day:int, month:int, year:int
* R�ckgabewert : 1, wenn das �bergebene Datum g�ltig ist,
* 0, wenn das �bergebene Datum nicht g�ltig ist
**/
int exists_date(struct time date)
{
    // �berpr�fung des Jahres
    if (date.year >= 1582 && date.year <= 2400)
    {
        // �berpr�fung des Monats
        if (date.month >= 1 && date.month <= 12)
        {
            // �berpr�fung des Tages
            if (date.day >= 1 && date.day <= 31)
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
* berechnet f�r das gegebene Datum die Nummer des Tages, von Jahresbeginn an gez�hlt
* �bergabeparameter : day:int, month:int, year:int
* R�ckgabewert : Nummer des Tages:int
**/
int day_of_the_year(struct time date)
{
    int exists = exists_date(date);
    int i = 1, alldays = 0;
    // �berpr�fung ob das Datum existiert
    if (exists ==1)
    {
        // wenn es existiert, dann geht er durch alle Monate durch und addiert die Tage aufeinander
        while(i<date.month)
        {
            alldays+= get_days_for_month(date.month,date.year);
            date.month--;
        }

        // Ausgabe von allen zusammengefassten Tagen
        alldays+= date.day;
        return alldays;
    }
    else
    {
        return -1;
    }
}

/**
* liest 3 Ganzzahlwerte (Integer) ein, f�r Tag, Monat und Jahr.
* Wenn das gegebene Datum ung�ltig ist, wird erneut eingelesen, bis ein g�ltiges Datum eingegeben wurde.
* �bergabeparameter : day:Zeiger auf int, month:Zeiger auf int, year:Zeiger auf int
* R�ckgabewert : kein R�ckgabewert
**/
struct time input_date(struct time date)
{
    do
    {
        printf("Bitte geben Sie einen Tag ein: \n");
        scanf("%i", &date.day);
        printf("Bitte geben Sie einen Monat ein: \n");
        scanf("%i", &date.month);
        printf("Bitte geben Sie ein Jahr ein: \n");
        scanf("%i", &date.year);

    }
    while(exists_date(date) != 1);

    return date;
}



