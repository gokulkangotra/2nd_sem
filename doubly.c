#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insert(struct Node** head, int data) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Add the new node at the end
    current->next = new_node;
    new_node->prev = current;
}

// Function to delete a node from the doubly linked list
void delete(struct Node** head, int data) {
    // Check if the list is empty
    if (*head == NULL) {
        return;
    }

    // Find the node with the given data
    struct Node* current = *head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    // If the node is not found
    if (current == NULL) {
        return;
    }

    // If the node is the head node
    if (current == *head) {
        *head = current->next;
    }

    // If the node is not the last node
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // If the node is not the first node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    // Free the memory of the deleted node
    free(current);
}

// Function to search for a node in the doubly linked list
struct Node* search(struct Node* head, int data) {
    struct Node* current = head;

    // Traverse the list
    while (current != NULL) {
        // If the node is found
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    // Node not found
    return NULL;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Doubly linked list: ");
    printList(head);

    // Delete a node from the doubly linked list
    delete(&head, 3);
    printf("After deletion: ");
    printList(head);

    // Search for a node in the doubly linked list
    struct Node* searchResult = search(head, 2);
    if (searchResult != NULL) {
        printf("Node found: %d\n", searchResult->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}
