#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s1, s2;

	void enQueue(int x)
	{
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

    // examples:
    // insert 1 -> s1: 1
    // insert 2 -> s1: 2, 1
    // insert 3 -> s1: 3, 2, 1
    // dequeue -> 1, s1: 3, 2
    // dequeue -> 2, s1: 3
    // dequeue -> 3, s1: empty

	int deQueue()
    {
		if (s1.empty())
			return -1;
		
		int x = s1.top();
		s1.pop();
		return x;
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}

// reference: https://www.geeksforgeeks.org/queue-using-stacks/



// another approach:

// enqueue(data) {
//     if(isFull(s1))
//         return full;
//     push(s1, data);
// }

// dequeue() {
//     if(isEmpty(s1)) {
//         if(isEmpty(s2))
//             return empty;
//         while(!isempty(s2))
//             push(s1, pop(s2));
//     }
//     return pop(s1);
// }

