/*
 * File: linkedList.c
 * File Created: Wednesday,  11st October
 * Author: Evan Jun Yu Ong
 * -----
 * Last Modified: Wednesday, 26th October
 * Modified By: Evan Jun Yu Ong
 * Student ID:19632191
 * -----
 * Purpose: C program to run the output structure
 * linkedliststruct - 2D Array will be abstract ,no struct pointer, only struct itself because this way to access it
 * get inside the struct 2D array field inside var, inside each indexs(array) struct of field, get field c
 * the values to be store in the list are structs
 * the size of the list must be instantly accessable
 * the last element of the list must be instantly accessible
 * to design a set of struct to hold linkedlist
 * no fix size anymore essienally, normal list, have pointer each elements will point to next elements to the list
 * the last node not pointing another node, know end of lists.
 * when well spend the linkedlist last node pointing another node then increase the size
 * Struct LinkedListNode will contain a pointer in the integer, reference linkedlist node inside itself
 * displayed as standard or in bold for highlighting
 * use an escape sequence followed by the correct color code, the print the text and finally reset the colors.
 * /033 is escape code*/

#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/*Allocate Memory to Linked List Struct and Returns its address*/
struct LinkedList* createLinkedList()
{
        struct LinkedList* newList = malloc(sizeof(struct LinkedList));

        if (newList == NULL)/*Memory allocation check*/
        {
                fprintf(stderr, "malloc error");
                exit(EXIT_FAILURE);
        }

        newList->head = NULL;

        return newList;
}

/*Allocate memory to Linked List Node struct and width bytes to Node data and returns address of the Node*/
struct LLNode* createNewNode(void* src, unsigned int width)
{
        struct LLNode* newNode = malloc(sizeof(struct LLNode));

        if (newNode == NULL)/*Memory allocation check*/
        {
                fprintf(stderr, "malloc error");
                exit(EXIT_FAILURE);
        }

        newNode->data = malloc(width);

        if (newNode->data == NULL)/*Memory allocation check*/
        {
                fprintf(stderr, "malloc error");
                exit(EXIT_FAILURE);
        }

        memcpy(newNode->data, src, width);/* must include <string.h>*/

        newNode->next = NULL;

        return newNode;
}

/*This function creates a new Node with width bytes of src as node data and insert the node at the head
of the linked list*/
void insertAtHead(struct LinkedList* linkedlist, void* src, unsigned int width)
{
        struct LLNode* newNode = createNewNode(src, width);
        if (linkedlist->head == NULL)/*empty linked list check*/
        {
                linkedlist->head = newNode;

                return;
        }
        newNode->next = linkedlist->head;

        linkedlist->head = newNode;
}

/* remove node from the head of the linked list and free the allocated memory using freeNode()*/
void removeFromHead(struct LinkedList* linkedlist)
{
        struct LLNode* temp;
        if (linkedlist->head == NULL)/*Empty linked list check*/
        {
                return;
        }

        temp = linkedlist->head;
        linkedlist->head = linkedlist->head->next;

        freeNode(temp);
}

/*Copies width bytes of data from head node data into the dest*/
void getHeadData(struct LinkedList* linkedlist, void* dest, unsigned int width)
{
        if (linkedlist->head == NULL)/*Empty linked list check*/
        {
                fprintf(stderr, "empty list error");
                exit(EXIT_FAILURE);
        }

        memcpy(dest, linkedlist->head->data, width);/* must include <string.h>*/
}

/*print the linked list using the function display*/
void printList(struct LinkedList* linkedlist, void(*display)(void*))
{
        struct LLNode* p = linkedlist->head;
        while (p != NULL)/*loop until end of the list*/
        {
                display(p->data);
                p = p->next;
        }
}

/*Free the memory allocated to the linked list Nodes using freeNode and the Linked List*/
void freeLinkedList(struct LinkedList* linkedlist)
{
        while (linkedlist->head)/*Loop until the end of list*/
        {
                struct LLNode* temp = linkedlist->head->next;
                free(linkedlist->head);

                linkedlist->head = temp;
        }

        free(linkedlist);
}

/*Free the memory allocated to the node data and the node*/
void freeNode(struct LLNode* node)
{
        if (node == NULL)
        {
                return;
        }

        if (node->data)
        {
                free(node->data);/*Free the memory allocated to data*/
        }
        free(node);
}

/*Returs 1 if the linked list is empty else returns false*/
int isEmpty(struct LinkedList* linkedlist)
{
        if (linkedlist->head == NULL)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}
