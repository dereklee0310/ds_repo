#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 4

int front = 0, rear = 0;

int *create()
{
	return (int *) malloc(sizeof(int) * LEN);
}

void enqueue(int *queue, int data)
{
	rear = (rear + 1) % LEN;
	if(front == rear) {
		rear = (rear - 1) % LEN;
		puts("queue full");
		return;
	}
	queue[rear] = data;
}

int dequeue(int *queue)
{
	if(front == rear) {
		puts("queue empty");
		return -1;
	}
	front = (front + 1) % LEN;
	return queue[front];
}

int main(int argc, char **argv) {
	int *queue = create();

	enqueue(queue, 1); // 1
	enqueue(queue, 2); // 1, 2
	enqueue(queue, 3); // 1, 2, 3
	enqueue(queue, 4); // 1, 2, 3
	printf("%d\n", dequeue(queue)); // 2, 3
	enqueue(queue, 5); // 2, 3, 5
	enqueue(queue, 6); // full
	printf("%d\n", dequeue(queue)); // 2, 3, 5
	printf("%d\n", dequeue(queue)); // 3, 5
	printf("%d\n", dequeue(queue)); // 5
	dequeue(queue); // empty

	return 0;
}


// reference: https://www.geeksforgeeks.org/introduction-to-circular-queue/
