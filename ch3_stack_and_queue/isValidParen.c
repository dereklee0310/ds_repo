#include <stdio.h>
#include <stdbool.h>

bool isValid(char *str) {
	int stack[32];
	int top = -1;

	while(*str) {
		if(*str == '(') {
			stack[++top] = *str;
		} else {
			if(top == -1)
				return false;
			else
				top--;
		}
		str++;
	}
	
	return top == -1;
};

int main(int argc, char **argv) {
	printf("%s\n", isValid("(((((((((())())))())))()))") ? "True" : "False" ); // valid
	printf("%s\n", isValid("(()") ? "True" : "False" ); // valid
	return 0;
}

