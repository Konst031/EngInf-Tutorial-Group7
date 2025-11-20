#include <stdlib.h>
#include <stdio.h>

enum week{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    enum week day = THURSDAY; 

    switch (day)
    {
    case THURSDAY:
        printf("Heute Info-Tutorium. Yay :)");
        break;
    case SATURDAY:
    case SUNDAY:
        printf("Wochenende :D");
        break;
           
    default:
        printf("Normaler Wochentag...");
        break;
    }
    return 0;
}
