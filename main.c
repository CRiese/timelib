/**
 * Author : Catharina Riese
 * Date : 18.12.2018
 * Der Tag des Jahres, vom eingegebenem Datum soll ermittelt werden
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    // Zugriff auf das Struct
    struct time date;
    date = input_date(date);

    // Ausgabe des Tag des Jahres
    printf("Tag des Jahres: %i\n", day_of_the_year(date));

    return 0;
}
