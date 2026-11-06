// WAP to convert infix to postfix expression using stack

#include <ctype.h>
#include <stdio.h>
#include <string.h>


// Global stack
char stack[50];
int top = -1;

// Push operator onto stack
void push(char op) {
  if (top == 49) {
    printf("Stack overflow!\n");
    return;
  }
  stack[++top] = op;
}

// Pop operator from stack
char pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    return '\0';
  }
  return stack[top--];
}

// Get precedence of operator
int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0; // For operands
}

// Check if character is an operator
int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Main function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
  int i, j = 0;
  top = -1;

  for (i = 0; infix[i] != '\0'; i++) {
    if (isalnum(infix[i])) {
      // If operand, add directly to postfix
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      // Push opening parenthesis
      push(infix[i]);
    } else if (infix[i] == ')') {
      // Pop until matching parenthesis
      while (top != -1 && stack[top] != '(') {
        postfix[j++] = pop();
      }
      if (top != -1)
        pop(); // Remove '('
    } else if (isOperator(infix[i])) {
      // Pop operators with higher or equal precedence
      while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
        postfix[j++] = pop();
      }
      push(infix[i]);
    }
  }

  // Pop remaining operators from stack
  while (top != -1) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0'; // Null-terminate postfix string
}

int main() {
  char infix[50], postfix[50];

  printf("Enter infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}