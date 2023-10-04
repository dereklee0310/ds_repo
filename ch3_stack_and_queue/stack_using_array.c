#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int topIdx = -1;

int *create() 
{
    return (int *) malloc(sizeof(int) * 128);
}

bool isEmpty(int *stack) 
{
    return topIdx == -1;
}

int top(int *stack)
{   
    if(topIdx == -1)
        return -1;
    return stack[topIdx];
}

void push(int *stack, int data)
{
   stack[++topIdx] = data;
   return;
}

int pop(int *stack)
{   
    if(topIdx == -1)
        return -1;
    return stack[topIdx--];
}

int main(int argc, char **argv) {
    int *stack = create();

    printf("%s\n", isEmpty(stack) ? "True" : "False");
    push(stack, 1); // 1
    printf("%s\n", isEmpty(stack) ? "True" : "False");
    printf("%d\n", top(stack));
    push(stack, 2); // 2, 1
    printf("%d\n", top(stack));
    printf("%d\n", pop(stack)); // 2, 1
    printf("%d\n", pop(stack)); // 1
    printf("%s\n", isEmpty(stack) ? "True" : "False");

    free(stack);
	return 0;
}