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

#include "DoublyLinkedList.h"

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

/**
 * @brief Delete the node at the given index
 * 
 * @param list 
 * @param index 
 */
void deleteAtIndex(DoublyLinkedList *list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Invalid index!\n");
        return;
    }
    if(index == 0) {
        deleteFirst(list);
        return;
    }
    else if(index == list->size - 1) {
        deleteLast(list);
        return;
    }
    Node *temp = list->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    list->size--;
}

/**
 * @brief Print the list
 * 
 * @param list 
 */
void printList(DoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Reverse the list
 * 
 * @param list 
 */
void reverseList(DoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
    Node *current = list->head;
    while(current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next;
    }
}

/**
 * @brief Print the list in reverse order
 * 
 * @param list 
 */
void printListReverse(DoublyLinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->tail;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/**
 * @brief Get the size of the list
 * 
 * @param list 
 * @return int 
 */
int getSize(DoublyLinkedList *list) {
    return list->size;
}

/**
 * @brief Get the data at the given index
 * 
 * @param list 
 * @param index 
 * @return int 
 */
int getDataAtIndex(DoublyLinkedList *list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Invalid index!\n");
        return -1;
    }
    Node *temp = list->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

/**
 * @brief Get the index of the given data
 * 
 * @param list 
 * @param data 
 * @return int 
 */
int getIndex(DoublyLinkedList *list, int data) {
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        if(temp->data == data) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

/**
 * @brief Check if the list is empty
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool isEmpty(DoublyLinkedList *list) {
    return list->head == NULL;
}

/**
 * @brief Clear the list
 * 
 * @param list 
 */
void clear(DoublyLinkedList *list) {
    Node *temp = list->head;
    while(temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Free the list
 * 
 * @param list 
 */
void freeList(DoublyLinkedList *list) {
    clear(list);
    free(list);
}

int main(int argc, char** argv)
{
    // Create a linked-list
    DoublyLinkedList *list = createDoublyLinkedList();

    // Insert some data
    insertAtBeginning(list, 1);
    insertAtBeginning(list, 2);
    insertAtBeginning(list, 3);
    insertAtEnd(list, 4);
    insertAtEnd(list, 5);
    insertAtEnd(list, 6);

    // Print the list
    printList(list);

    // Print the list in reverse order
    printListReverse(list);

    // Reverse the list
    reverseList(list);

    // Print the list
    printList(list);

    // Get the size of the list
    printf("Size: %d\n", getSize(list));

    // Get the data at the given index
    printf("Data at index 2: %d\n", getDataAtIndex(list, 2));

    // Get the index of the given data
    printf("Index of 5: %d\n", getIndex(list, 5));

    // Check if the list is empty
    printf("Is empty: %s\n", isEmpty(list) ? "true" : "false");

    // Delete the first node
    deleteFirst(list);

    // Delete the last node
    deleteLast(list);

    // Delete the node at the given index
    deleteAtIndex(list, 2);

    return 0;
}
