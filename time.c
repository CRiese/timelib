/**
* Author : Catharina Riese
* Date : 26.02.2019
* Bibilothek time.c, alles über Zeiten
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"


/**
 * Die Funktion ermittelt für ein übergebenes Jahr des gregorianischen Kalenders,
 * ob es sich um ein Schaltjahr handelt.
 * Übergabeparameter : year:int
 * Rückgabewert : 1, wenn übergebenes Jahr ein Schaltjahr ist, 0, wenn übergebenes Jahr kein
 * Schaltjahr ist, -1, wenn ein ungültiges Jahr übergeben wurde
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
 * Die Funktion bestimmt für einen gegebenen Monat
 * eines gegebenen Jahres, wie viele Tage der Monat hat.
 * Der Wert des Monats muss zwischen 1 und 12 liegen.
 * Schaltjahre werden berücksichtigt.
 * Übergabeparameter : month:int, year:int
 * Rückgabewert : Anzahl von Tagen:int, 28-31, wenn ein gültiger Monat eingegeben wurde,
 * -1, wenn ein ungültiger Moant oder Jahr übergeben wurde
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
* überprüft ob das Datum gültig ist.
* Im Zeitraum von 1.1.1582 und 31.12.2400
* Übergabeparameter : day:int, month:int, year:int
* Rückgabewert : 1, wenn das übergebene Datum gültig ist,
* 0, wenn das übergebene Datum nicht gültig ist
**/
int exists_date(struct time date)
{
    // Überprüfung des Jahres
    if (date.year >= 1582 && date.year <= 2400)
    {
        // Überprüfung des Monats
        if (date.month >= 1 && date.month <= 12)
        {
            // Überprüfung des Tages
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
* berechnet für das gegebene Datum die Nummer des Tages, von Jahresbeginn an gezählt
* Übergabeparameter : day:int, month:int, year:int
* Rückgabewert : Nummer des Tages:int
**/
int day_of_the_year(struct time date)
{
    int exists = exists_date(date);
    int i = 1, alldays = 0;
    // überprüfung ob das Datum existiert
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
* liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr.
* Wenn das gegebene Datum ungültig ist, wird erneut eingelesen, bis ein gültiges Datum eingegeben wurde.
* Übergabeparameter : day:Zeiger auf int, month:Zeiger auf int, year:Zeiger auf int
* Rückgabewert : kein Rückgabewert
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



