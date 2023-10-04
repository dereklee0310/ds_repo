#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

void enqueue(struct Node **rearPtr, int data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	if(!*rearPtr)
		newNode->next = newNode;
	else {
		newNode->next = (*rearPtr)->next;
		(*rearPtr)->next = newNode; // place the new Node after the rear
	}
	*rearPtr = newNode;
}

int dequeue(struct Node **rearPtr)
{
	if(!*rearPtr) {
		puts("queue empty");
		return -1;
	}

	struct Node *tmpNode = (*rearPtr)->next;
	int data = tmpNode->data;
	if(*rearPtr == (*rearPtr)->next)
		*rearPtr = NULL;
	else
		(*rearPtr)->next = (*rearPtr)->next->next;
	free(tmpNode);
	return data;
}

int main(int argc, char **argv) {
	struct Node *rear = NULL;
	enqueue(&rear, 1);
	enqueue(&rear, 2);
	enqueue(&rear, 3);

	printf("%d\n", dequeue(&rear));
	printf("%d\n", dequeue(&rear));
	printf("%d\n", dequeue(&rear));
	dequeue(&rear);

	return 0;
}

// reference: https://www.geeksforgeeks.org/circular-linked-list-implementation-of-circular-queue/