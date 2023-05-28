#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to the stack.\n", data);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

int main() {
    struct Node* top = NULL;

    // Pushing elements onto the stack
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    // Popping elements from the stack
    printf("%d popped from the stack.\n", pop(&top));
    printf("%d popped from the stack.\n", pop(&top));
    printf("%d popped from the stack.\n", pop(&top));

    return 0;
}

