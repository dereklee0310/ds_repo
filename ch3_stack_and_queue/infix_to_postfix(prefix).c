#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
  
#define MAX_EXPR_SIZE 100
  
// Function to return precedence of operators
int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
  
// Function to check if the scanned character 
// is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
  
// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*) malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;
    

    // i for input, j for output
    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        
        if (isalnum(infix[i])) { // isalnum: check if the character is a alphabet or a number
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--; // remove '('
        }
        
        // operator
        else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
  
    // pop remaining operators
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}
  
// Driver code
int main()
{
    char infix[MAX_EXPR_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";

    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}

// reference: https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/

// infix to prefix: reverse the input, apply infixToPostfix algo, then reverse the output to get the prefix notation
// note that the direction of parentheses needs to be reversed!
// referenec: https://www.geeksforgeeks.org/convert-infix-prefix-notation/