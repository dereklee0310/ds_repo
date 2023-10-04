#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create()
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct Node *head)
{
    return !head->next;
}

int top(struct Node *head)
{
    return head->next->data;
}

void push(struct Node *headPtr, int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = headPtr->next;
    headPtr->next = newNode;
}

int pop(struct Node *headPtr){
    if(!headPtr->next)
        return -1;

    int data = headPtr->next->data;
    struct Node *tmp = headPtr->next;
    headPtr->next = headPtr->next->next;
    free(tmp);
    return data;
}

int main(int argc, char **argv) {
    struct Node *stack = create();

    printf("%s\n", isEmpty(stack) ? "True" : "False");
    push(stack, 1); // 1
    printf("%s\n", isEmpty(stack) ? "True" : "False");
    printf("%d\n", top(stack));
    push(stack, 2); // 2, 1
    printf("%d\n", top(stack));
    printf("%d\n", pop(stack)); // 2, 1
    printf("%d\n", pop(stack)); // 1
    printf("%s\n", isEmpty(stack) ? "True" : "False");

	return 0;
}

// reference: https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/

