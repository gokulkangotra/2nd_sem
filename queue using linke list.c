#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the queue (push operation)
void push(Queue* queue, int data) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node at the end and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d pushed to the queue.\n", data);
}

// Function to remove an element from the queue (pop operation)
int pop(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    // Store the front node and its data
    Node* frontNode = queue->front;
    int data = frontNode->data;

    // Update the front pointer
    queue->front = queue->front->next;

    // If the front becomes NULL, update the rear pointer as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    // Free the memory of the front node
    free(frontNode);

    return data;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);

    int poppedElement = pop(&queue);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement);
    }

    poppedElement = pop(&queue);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement);
    }

    return 0;
}
