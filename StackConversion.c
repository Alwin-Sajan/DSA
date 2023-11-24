#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int isOperator(char c);
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
   
    printf("Enter the infix expression : ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression is : %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result after evaluation is : %d\n", result);

    return 0;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (symbol == ' ' || symbol == '\t') {
            // Ignore whitespace
            i++;
        } else if (isdigit(symbol)) {
            // If the symbol is a digit, copy it to the postfix expression
            postfix[j++] = symbol;
            i++;
        } else if (isOperator(symbol)) {
            // If the symbol is an operator, pop operators from the stack and append to the postfix expression
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, symbol);
            i++;
        } else if (symbol == '(') {
            // If the symbol is an open parenthesis, push it onto the stack
            push(&stack, symbol);
            i++;
        } else if (symbol == ')') {
            // If the symbol is a closing parenthesis, pop operators from the stack and append to the postfix expression
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1) {
                printf("Invalid expression: Unmatched parenthesis\n");
                exit(1);
            }
            // Pop the open parenthesis from the stack
            pop(&stack);
            i++;
        } else {
            // Invalid character in the infix expression
            printf("Invalid character in the infix expression: %c\n", symbol);
            exit(1);
        }
    }

    // Pop any remaining operators from the stack and append to the postfix expression
    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression: Unmatched parenthesis\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    int i, operand1, operand2;
    i = 0;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        if (isdigit(symbol)) {
                  push(&stack, symbol - '0');
        } else if (isOperator(symbol)) {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
  switch (symbol) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;}   }

        i++;
    }
    return pop(&stack);
}
