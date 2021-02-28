/* main program */

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "newSleep.h"
#include "showInfo.h"
#include "linkedList.h"
#include "gamePlay.h"

void split(char *src, const char *separator, char **dest, int *num) {
    char *pNext;
    int count = 0;
    if (src == NULL || strlen(src) == 0)
        return;
    if (separator == NULL || strlen(separator) == 0)
        return;
    pNext = strtok(src, separator);
    while (pNext != NULL) {
        *dest++ = pNext;
        ++count;
        pNext = strtok(NULL, separator);
    }
    *num = count;
}

int main(int argc, char* argv[])
{

	
    Character hero;
    FILE* fHero = fopen(argv[1], "r");

    if (fHero == NULL)
    {
        perror("Error opening file: ");
    }
    else
    {

        char str[100];
        fgets(str, 100, fHero);
        char* newstr[100] = { 0 };
        int num = 0;
        split(str, ",", newstr, &num);

        hero.HP = atoi(newstr[0]);
        hero.MATK = atoi(newstr[1]);
        hero.MRES = atoi(newstr[2]);
        hero.ELE = *newstr[3];
        strcpy(hero.name,newstr[4]);

        fclose(fHero);
    }





    linkedList* enemyList = (linkedList*)malloc(sizeof(linkedList));
    (*enemyList).head = NULL;
    FILE* fEnemy = fopen(argv[2], "r");
    if (fEnemy == NULL)
    {
        perror("Error opening file: ");
    }
    else
    {
        char str[100];
        fgets(str, 100, fEnemy);
        linkedListNode* node = (linkedListNode*)malloc(sizeof(linkedListNode));
        enemyList->head = node;
        do
        {
            char* newstr[100] = { 0 };
            int num = 0;
            split(str, ",", newstr, &num);
            Character *enemy = (Character*)malloc(sizeof(Character));
            enemy->HP = atoi(newstr[0]);
            enemy->MATK = atoi(newstr[1]);
            enemy->MRES = atoi(newstr[2]);
            enemy->ELE = *(newstr[3]);
            memcpy(enemy->name, newstr[4], (int)strlen(newstr[4]));

            node->data = enemy;
            node->next = NULL;
            linkedListNode* pNode = (linkedListNode*)malloc(sizeof(linkedListNode));
            node->next = pNode;
            node = pNode;
            node->next = NULL;
        }while(fgets(str, 100, fEnemy)!=NULL);

        fclose(fEnemy);
    }


    int sleepTime = atoi(argv[3]);


    system("clear");
    printf("Welcome to the auto RPG ! \n");
    newSleep(sleepTime);
    system("clear");
    printf("Hero:\n");
    printf("%s\t\t", hero.name);
    printf("HP: %d", hero.HP);
    printf("\tMATK: %d", hero.MATK);
    printf("\tMRES: %d", hero.MRES);
    printf("\tELE: %c\n\n", hero.ELE);


/*  -----------------------  */
    /* 输出enemy information */

    printf("Enemies:\n");
    linkedListNode* tmp;
    tmp =  enemyList->head;
    while(tmp->next!= NULL)
    {
        Character* tmp_data = (Character *)tmp->data;

        printf("%s\t    ", tmp_data->name);
        printf("HP: %d", tmp_data->HP);
        printf("\tMATK: %d", tmp_data->MATK);
        printf("\tMRES: %d\n", tmp_data->MRES);
        printf("\tELE: %c\n\n", tmp_data->ELE);
        tmp = tmp->next;
    }


    newSleep(sleepTime);
    system("clear");



    Character *newEnemy = (Character*)malloc(sizeof(Character));
    newEnemy = enemyList->head->data;

    while(hero.HP>0)
    {

        if(newEnemy == NULL)
        {
            printf("Arlen defeats all enemies! The world is saved! \n");
            break;
        }

        int spell = magicSpell();
        char eleAttack;

        if (spell == 1)
        {
            eleAttack = 'i';
        }
        else if (spell = 2)
        {
            eleAttack = 'f';
        }
        else
        {
            eleAttack = 'w';

        }


        float flag = ifEffect(eleAttack, newEnemy->ELE);
        int damage = 0;
        damage = (int)((hero.MATK * flag) * (100.0 - newEnemy->MRES) / 100.0);

        newEnemy->HP -= damage;
        if(newEnemy->HP<=0)
        {
            newEnemy->HP = 0;
        }

        showCharacterInfo(&hero);

        /* ------------ printf attck info ------------ */
        char magic[10] = {};
        if (spell == 1)
        {
            strcpy(magic, "ice bolt");
        }
        else if (spell == 2)
        {
            strcpy(magic, "fire bolt");
        }
        else
        {
            strcpy(magic, "root bind");
        }

        char effect[20] = {};
        if (flag == 1)
        {
            strcpy(effect, "");
        }
        else if (flag == 2)
        {
            strcpy(effect, " (very effective)");
        }
        else
        {
            strcpy(effect, " (not effective)");
        }

        printf("\t%s casts %s%s, dealing %d damage!\n\n", hero.name, magic, effect, damage);


        showCharacterInfo(newEnemy);
        newSleep(sleepTime);
        system("clear");


        spell = magicSpell();
        if (spell == 1)
        {
            eleAttack = 'i';
        }
        else if (spell = 2)
        {
            eleAttack = 'f';
        }
        else
        {
            eleAttack = 'w';

        }


        flag = ifEffect(eleAttack, hero.ELE);
        damage = 0;
        damage = (int)((newEnemy->MATK * flag) * (100.0 - hero.MRES) / 100.0);

        hero.HP -= damage;
        if(hero.HP<=0)
        {
            hero.HP = 0;
        }

        showCharacterInfo(&hero);

        /* ------------ printf attck info ------------ */
        if (spell == 1)
        {
            strcpy(magic, "ice bolt");
        }
        else if (spell == 2)
        {
            strcpy(magic, "fire bolt");
        }
        else
        {
            strcpy(magic, "root bind");
        }

        if (flag == 1)
        {
            strcpy(effect, "");
        }
        else if (flag == 2)
        {
            strcpy(effect, " (very effective)");
        }
        else
        {
            strcpy(effect, " (not effective)");
        }

        printf("\t%s casts %s%s, dealing %d damage!\n\n", newEnemy->name, magic, effect, damage);

        showCharacterInfo(newEnemy);
        newSleep(sleepTime);
        system("clear");


        if(newEnemy->HP==0)
        {
            if(newEnemy == NULL)
            {
                printf("Enemies fail\n");
                break;
            }
            else
            {
                enemyList->head = enemyList->head->next;
                newEnemy = enemyList->head->data;
            }


        }

        if(hero.HP == 0)
        {
                printf("Arlen loses the battle! The world is doomed! \n");
            break;
        }

    }
    
    
    
    
    
    /* --- FREE MEMORY --- */
    
    linkedListNode* freeTmp;
    freeTmp = enemyList->head;
    while(freeTmp->next!= NULL)
    {
        linkedListNode* tmpData = freeTmp;
        freeTmp = freeTmp->next;
        free (tmpData);
 
    }
    enemyList->head = NULL;

    return 0;
}


