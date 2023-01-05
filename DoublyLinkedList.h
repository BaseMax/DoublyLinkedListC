#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free
#include <stdbool.h> // bool, true, false

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

/**
 * @brief Create a new node
 * 
 * @param data
 * @return Node* 
 */
Node* createNode(int data);

/**
 * @brief Create a new doubly linked list
 * 
 * @return DoublyLinkedList* 
 */
DoublyLinkedList* createDoublyLinkedList();

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtEnd(DoublyLinkedList *list, int data);

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtBeginning(DoublyLinkedList *list, int data);

/**
 * @brief Insert a new node at the given index
 * 
 * @param list 
 * @param data 
 * @param index 
 */
void insertAtIndex(DoublyLinkedList *list, int data, int index);

/**
 * @brief Delete the first node of the list
 * 
 * @param list 
 */
void deleteFirst(DoublyLinkedList *list);

/**
 * @brief Delete the last node of the list
 * 
 * @param list 
 */
void deleteLast(DoublyLinkedList *list);

/**
 * @brief Delete the node at the given index
 * 
 * @param list 
 * @param index 
 */
void deleteAtIndex(DoublyLinkedList *list, int index);

/**
 * @brief Print the list
 * 
 * @param list 
 */
void printList(DoublyLinkedList *list);

/**
 * @brief Reverse the list
 * 
 * @param list 
 */
void reverseList(DoublyLinkedList *list);

/**
 * @brief Print the list in reverse order
 * 
 * @param list 
 */
void printListReverse(DoublyLinkedList *list);

/**
 * @brief Get the size of the list
 * 
 * @param list 
 * @return int 
 */
int getSize(DoublyLinkedList *list);

/**
 * @brief Get the data at the given index
 * 
 * @param list 
 * @param index 
 * @return int 
 */
int getDataAtIndex(DoublyLinkedList *list, int index);

/**
 * @brief Get the index of the given data
 * 
 * @param list 
 * @param data 
 * @return int 
 */
int getIndex(DoublyLinkedList *list, int data);

/**
 * @brief Check if the list is empty
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool isEmpty(DoublyLinkedList *list);

/**
 * @brief Clear the list
 * 
 * @param list 
 */
void clear(DoublyLinkedList *list);

/**
 * @brief Free the list
 * 
 * @param list 
 */
void freeList(DoublyLinkedList *list);

#endif
