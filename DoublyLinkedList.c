/**
 * 
 * @file DoublyLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Doubly Linked List (DLL) implementation in C language
 * @version 0.1
 * @date 2022-12-19
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

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
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/**
 * @brief Create a new doubly linked list
 * 
 * @return DoublyLinkedList* 
 */
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList *newList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtEnd(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);
    if(list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtBeginning(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);
    if(list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->head->prev = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the given index
 * 
 * @param list 
 * @param data 
 * @param index 
 */
void insertAtIndex(DoublyLinkedList *list, int data, int index) {
    if(index < 0 || index > list->size) {
        printf("Invalid index!\n");
        return;
    }
    if(index == 0) {
        insertAtBeginning(list, data);
        return;
    }
    else if(index == list->size) {
        insertAtEnd(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = list->head;
    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    list->size++;
}

/**
 * @brief Delete the first node of the list
 * 
 * @param list 
 */
void deleteFirst(DoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
}

/**
 * @brief Delete the last node of the list
 * 
 * @param list 
 */
void deleteLast(DoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
    list->size--;
}
