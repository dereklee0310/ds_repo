#include <bits/stdc++.h>

using namespace std;

class Stack {
	queue<int> q1, q2;

public:
    // convert LIFO into FIFO in push operation
	void push(int x)
	{
		q2.push(x);

		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

        // swap
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		if (q1.empty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size() { return q1.size(); }
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size() << endl;
	return 0;
}

// reference: https://www.geeksforgeeks.org/implement-stack-using-queue/

// another approach:

// push(data) {
//     if(isFull(queue))
//         return full;
//     enqueue(queue, data);
// }

// pop() {
//     if(isEmpty(queue))
//         return empty;
//     for(int i = 0; i < len(queue) - 1; i++)
//         enqueue(queue, dequeue(queue));
//     return dequeue(queue);
// }
