#include <stdio.h>
#include <stdlib.h>
#include "gamePlay.h"
#include <time.h>

float ifEffect(char eleAttack, char eleDefend)
{
    /* ELE: i > f > w > i... */
    float flag = 0;
    if (eleAttack == eleDefend)
    {
        flag = 1;
    }

    else if (eleAttack == 'i')
    {
        if (eleDefend == 'f')
        {
            flag = 2;
        }
        else
        {
            flag = 0.5;
        }

    }
    else if (eleAttack == 'f')
    {
        if (eleDefend == 'w')
        {
            flag = 2;
        }
        else
        {
            flag = 0.5;
        }
    }
    else
    {
        if (eleDefend == 'i')
        {
            flag = 2;
        }
        else
        {
            flag = 0.5;
        }

    }
    return flag;
}

int magicSpell()
{
    /* 3 kinds of spell
     Ice Bolt: 1
     Fire Bolt: 2
     Root Bind: 3
     */

    time_t t;
    srand((unsigned) time(&t));
    return (rand() % 4);
}
