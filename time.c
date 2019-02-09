/** Bibilothek time.c, alles über Zeiten
**/

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
 * Die Funktion bestimmt für einen gegebenen Monat
 * eines gegebenen Jahres, wie viele Tage der Monat hat.
 * Der Wert des Monats muss zwischen 1 und 12 liegen.
 * Schaltjahre werden berücksichtigt.
 **/
 int get_days_for_month(int month, int year)
 {
    if (isLeapyear(year) == 0)
    {
        int array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return array[month-1];
    }

    if (isLeapyear(year) == 1)
    {
        int array[] = {31,29,31,30,31,30,31,31,30,31,30,31};
        return array[month-1];
    }


 }

 /**
 * überprüft ob das Datum gültig ist.
 * Im Zeitraum von 1.1.1582 und 31.12.2400
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
 * berechnet für das gegebene Datum die Nummer des Tages,
 * von Jahresbeginn an gezählt
 **/
int day_of_the_year(int day, int month, int year)
{
    int exists = exists_date(day,month,year);
    int i = 1, alldays = 0;
    if (exists ==1)
    {
        while(i<month)
        {
            alldays+= get_days_for_month(month,year);
            month--;
        }

        alldays+= day;
        return alldays;
    }
    else
    {
        return -1;
    }
}

 /**
 * liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr.
 * Wenn das gegebene Datum ungültig ist, wird erneut eingelesen,
 * bis ein gültiges Datum eingegeben wurde.
 **/
int input_date(int *day, int *month, int *year)
{
    do
        {
            printf("Bitte geben Sie einen Tag ein: \n");
            scanf("%i", day);
            printf("Bitte geben Sie einen Monat ein: \n");
            scanf("%i", month);
            printf("Bitte geben Sie ein Jahr ein: \n");
            scanf("%i", year);

        } while(exists_date(*day,*month,*year) != 1);

    return 0;

}



