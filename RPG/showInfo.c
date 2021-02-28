#include <stdio.h>
#include "showInfo.h"

void showCharacterInfo(Character* character)
{
    printf("%s\n", character->name);
    printf("HP: %d\n", character->HP);
    printf("MATK: %d\n", character->MATK);
    printf("MRES: %d\n", character->MRES);

    char ele[4] = {};
    if (character->ELE == 'i')
    {
        strcpy(ele, "ice");
    }
    else if (character->ELE == 'f')
    {
        strcpy(ele, "fire");
    }
    else if (character->ELE == 'w')
    {
        strcpy(ele, "wood");
    }
    else
    {
        printf("Error: No such element!");

    }
    printf("ELE: %s\n", ele);
}



