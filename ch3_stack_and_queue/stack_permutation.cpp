/* -------------------------------------------------------------------------- */
/*                              Stack Permutation                             */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

const char* isValid(char *input, char *target) {
	stack<char> st;
	int tail = 0;

	for(int i = 0; i < 3; i++) {
		st.push(input[i]);

		while(!st.empty() && st.top() == target[tail]) {
			st.pop();
			tail++;
		}
	}

	return (st.empty() ? "True" : "False");
};

int main(int argc, char **argv) {
	char input[3] = {'a', 'b', 'c'};

	char target1[3] = {'a', 'b', 'c'};
	char target2[3] = {'a', 'c', 'b'};
	char target3[3] = {'b', 'a', 'c'};
	char target4[4] = {'b', 'c', 'a'};
	char target5[4] = {'c', 'a', 'b'};
	char target6[4] = {'c', 'b', 'a'};

	printf("%s\n", isValid(input, target1));
	printf("%s\n", isValid(input, target2));
	printf("%s\n", isValid(input, target3));
	printf("%s\n", isValid(input, target4));
	printf("%s\n", isValid(input, target5));
	printf("%s\n", isValid(input, target6));

	return 0;
}

// reference: https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/