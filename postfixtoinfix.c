#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convert postfix expression to infix notation
void postfixToInfix(char postfix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    int i;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isalnum(postfix[i])) {
            push(stack, postfix[i]);
        } else if (isOperator(postfix[i])) {
            char operand1 = pop(stack);
            char operand2 = pop(stack);
            char temp[100];

            // Construct the infix expression
            sprintf(temp, "(%c%c%c)", operand2, postfix[i], operand1);
            strcat(temp, "\0");

            // Push the infix expression back to stack
            push(stack, temp[0]);
        }
    }

    // The final infix expression is present at the top of stack
    printf("Infix Expression: %c\n", stack->items[stack->top]);
    free(stack);
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfixToInfix(postfix);

    return 0;
}
