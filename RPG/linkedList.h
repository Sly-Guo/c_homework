#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*composite data type inside one container*/
/*Generic Linked List Node Struct*/
typedef struct LLNode
{
        void* data;
        struct LLNode* next;
}linkedListNode;

/*Linked List Struct*/
typedef struct LinkedList
{
        struct LLNode* head;
}linkedList;

struct LinkedList* createLinkedList();
struct LLNode* createNewNode(void* src, unsigned int width);
void insertAtHead(struct LinkedList* linkedlist, void* src, unsigned int width);
int isEmpty(struct LinkedList* linkedlist);
void removeFromHead(struct LinkedList* linkedlist);
void getHeadData(struct LinkedList* linkedlist, void* dest, unsigned int width);
void printList(struct LinkedList* linkedlist, void(*display)(void*));
void freeLinkedList(struct LinkedList* linkedlist);
void freeNode(struct LLNode* node);

#endif
