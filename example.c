#include "DoublyLinkedList.h"

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
