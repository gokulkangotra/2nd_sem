#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insert(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct LinkedList* list, int key) {
    struct Node* currentNode = list->head;
    struct Node* prevNode = NULL;

    // If the head node itself holds the key to be deleted
    if (currentNode != NULL && currentNode->data == key) {
        list->head = currentNode->next;
        free(currentNode);
        return;
    }

    // Search for the key to be deleted, keeping track of the previous node
    while (currentNode != NULL && currentNode->data != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // If the key was not found in the linked list
    if (currentNode == NULL) {
        printf("Key not found in the linked list.\n");
        return;
    }

    // Unlink the node from the linked list
    prevNode->next = currentNode->next;
    free(currentNode);
}

// Function to perform linear search on the linked list
struct Node* search(struct LinkedList* list, int key) {
    struct Node* currentNode = list->head;

    // Traverse the linked list until the key is found
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    // If the key was not found in the linked list
    return NULL;
}

// Function to display the elements of the linked list
void display(struct LinkedList* list) {
    struct Node* currentNode = list->head;

    // Traverse the linked list and print each element
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to clear the linked list and free memory
void clear(struct LinkedList* list) {
    struct Node* currentNode = list->head;
    struct Node* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
}

// Test the linked list implementation
int main() {
    struct LinkedList myList;
    myList.head = NULL;

    int choice, data, key;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Clear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&myList, data);
                printf("Elementnserted successfully.\n");
break;
case 2:
printf("Enter the element to delete: ");
scanf("%d", &key);
deleteNode(&myList, key);
break;
case 3:
printf("Enter the element to search: ");
scanf("%d", &key);
struct Node* searchResult = search(&myList, key);
if (searchResult != NULL) {
printf("Element found: %d\n", searchResult->data);
} else {
printf("Element not found.\n");
}
break;
case 4:
printf("Linked List: ");
display(&myList);
break;
case 5:
clear(&myList);
printf("Linked List cleared.\n");
break;
case 6:
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
    printf("\n");
}
return 0;
}
