#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *create()
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->next = NULL;
	return newNode;
}

bool isEmpty(struct Node *front, struct Node *rear)
{
	return front == rear;
}

int getFront(struct Node *front, struct Node *rear)
{	
	if(front == rear)
		return -1;
	return front->next->data;
}

void enqueue(struct Node **rearPtr, int data)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	(*rearPtr)->next = newNode;
	*rearPtr = (*rearPtr)->next;
}

int dequeue(struct Node *front, struct Node **rearPtr)
{
	if(front == *rearPtr)
		return -1;
	int data = front->next->data;
	struct Node *tmp = front->next;
	if(tmp == *rearPtr)
		*rearPtr = front;
	front->next = front->next->next;
	free(tmp);
	return data;
}

int main(int argc, char **argv) {
    struct Node *front = create();
	struct Node *rear = front;

    printf("%s\n", isEmpty(front, rear) ? "True" : "False");
    enqueue(&rear, 1); // 1
    printf("%s\n", isEmpty(front, rear) ? "True" : "False");
    printf("%d\n", getFront(front, rear));
    enqueue(&rear, 2); // 1, 2
    printf("%d\n", getFront(front, rear));
    printf("%d\n", dequeue(front, &rear)); // 1, 2
    printf("%d\n", dequeue(front, &rear)); // 2
    printf("%s\n", isEmpty(front, rear) ? "True" : "False");

	return 0;
}

// reference: https://www.geeksforgeeks.org/queue-linked-list-implementation/