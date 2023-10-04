#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int front = -1, rear = -1;

int *create()
{
	return (int *) malloc(sizeof(int) * 128);
}

bool isEmpty(int *queue)
{
	return front == rear;
}

bool getFront(int *queue)
{	
	if(front == rear)
		return -1;
	return queue[front];
}

void enqueue(int *queue, int data)
{
	if(rear == 127)
		return;
	queue[++rear] = data;
}

int dequeue(int *queue)
{
	if(front == rear)
		return -1;
	return queue[++front];
}

int main(int argc, char **argv) {
    int *queue = create();

    printf("%s\n", isEmpty(queue) ? "True" : "False");
    enqueue(queue, 1); // 1
    printf("%s\n", isEmpty(queue) ? "True" : "False");
    printf("%d\n", getFront(queue));
    enqueue(queue, 2); // 1, 2
    printf("%d\n", getFront(queue));
    printf("%d\n", dequeue(queue)); // 1, 2
    printf("%d\n", dequeue(queue)); // 2
    printf("%s\n", isEmpty(queue) ? "True" : "False");

	return 0;
}

// reference: https://www.geeksforgeeks.org/array-implementation-of-queue-simple/

