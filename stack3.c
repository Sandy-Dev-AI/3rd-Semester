// WAP for the evaluation of postfix expression
#include <ctype.h>
#include <stdio.h>
#include <string.h>


// Global stack
int stack[50];
int top = -1;

// Push operand onto stack
void push(int val) {
  if (top == 49) {
    printf("Stack overflow!\n");
    return;
  }
  stack[++top] = val;
}

// Pop operand from stack
int pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    return -999;
  }
  return stack[top--];
}

// Perform operation
int operate(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    return a ^ b; // Simple power
  default:
    return 0;
  }
}

// Main function to evaluate postfix
int evaluatePostfix(char postfix[]) {
  int i, op1, op2, result;

  for (i = 0; postfix[i] != '\0'; i++) {
    if (isdigit(postfix[i])) {
      // If operand, push to stack
      push(postfix[i] - '0'); // Convert char to int
    } else {
      // If operator, pop two operands and evaluate
      op2 = pop();
      op1 = pop();

      if (op1 == -999 || op2 == -999) {
        printf("Invalid postfix expression!\n");
        return -999;
      }

      result = operate(op1, op2, postfix[i]);
      push(result);
    }
  }

  return pop();
}

int main() {
  char postfix[50];

  printf("Enter postfix expression: ");
  scanf("%s", postfix);

  int result = evaluatePostfix(postfix);

  if (result != -999)
    printf("Result: %d\n", result);

  return 0;
}