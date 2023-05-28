#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the linked list
struct Node {
    int data;                // Data of the node
    int priority;            // Priority of the node
    struct Node* next;       // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node into the priority queue
void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the queue is empty or the new node has higher priority, insert it at the beginning
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        // Find the position to insert the new node
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }

        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Inserted %d with priority %d\n", data, priority);
}

// Function to remove and return the node with the highest priority
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty!\n");
        return -1;
    }

    struct Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);

    return data;
}

// Function to display the elements in the priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }

    struct Node* current = head;
    printf("Priority Queue: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* pq = NULL;

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    display(pq);

    int removedElement = dequeue(&pq);
    printf("Removed element: %d\n", removedElement);

    display(pq);

    return 0;
}

