#include <stdlib.h>
#include <stdio.h>
union grade
{
    char us_grade;
    float eu_grade;
};

int main()
{
    union grade g1;
    g1.eu_grade = 5.0;
    g1.us_grade = 'F'; // Wert von 5.0 wurde überschrieben

    printf("%f",g1.eu_grade); // gibt trotzdem keine Compilerwarnung aus
    // Daten in Union werden als float interpretiert ausgegeben -> ungewolltes Ergebnis    

    return 0;
}
