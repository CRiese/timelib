/**
 * Author : Catharina Riese
 * Date : 18.12.2018
 * Welcher Tag des Jahres, soll vom eingegebenem Datum ermittelt werden
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    int day, month, year;
    input_date(&day, &month, &year);

    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));

    return 0;
}
