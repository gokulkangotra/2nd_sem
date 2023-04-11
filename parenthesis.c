#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push item onto stack
void push(struct Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow!");
        exit(EXIT_FAILURE);
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// Function to pop item from stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!");
        exit(EXIT_FAILURE);
    } else {
        char item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Function to check if expression is correctly parenthesized
int checkParentheses(char *expression) {
    struct Stack s;
    initialize(&s);

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&s, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&s)) {
                return 0;
            } else {
                char top = pop(&s);
                if ((top == '(' && expression[i] != ')') || 
                    (top == '[' && expression[i] != ']') || 
                    (top == '{' && expression[i] != '}')) {
                    return 0;
                }
            }
        }
    }

    return isEmpty(&s);
}

// Main function
int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (checkParentheses(expression)) {
        printf("Expression is correctly parenthesized!");
    } else {
        printf("Expression is not correctly parenthesized!");
    }

    return 0;
}
