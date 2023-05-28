#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // Only one node in the list, it points to itself
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }

    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // Only one node in the list, it points to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }

    printf("Node inserted at the end.\n");
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node *curr = *head, *prev;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with value %d not found.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head && curr->next == *head) { // Only one node in the list
        *head = NULL;
        free(curr);
    } else if (curr == *head) { // Delete the head node
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = curr->next;
        prev->next = *head;
        free(curr);
    } else if (curr->next == *head) { // Delete the last node
        prev->next = *head;
        free(curr);
    } else { // Delete a node in the middle
        prev->next = curr->next;
        free(curr);
    }

    printf("Node with value %d deleted from the list.\n", key);
}

// Function to perform linear search on the circular linked list
void search(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Search not possible.\n");
        return;
    }

    struct Node* temp = head;
    int position = 0;
    while (temp->next != head) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    if (temp->data == key) {
        printf("Element %d found at position %d.\n", key, position);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initializing an empty circular linked list

    // Inserting nodes
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);

    // Displaying the circular linked list
    printf("Circular linked list: ");
    display(head);

    // Deleting a node
    deleteNode(&head, 5);

    // Displaying the circular linked list after deletion
    printf("Circular linked list after deletion: ");
    display(head);

    // Searching for a node
    search(head, 10);

    return 0;
}
