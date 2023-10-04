#include <stdio.h>
#include <stdbool.h>

int isPalindrome(char *str, int len) {
	char stack[32];
	int top = -1;

	int i;
	for(i = 0; i < len / 2; i++)
		stack[++top] = str[i];
	
	if(len % 2)
		top--;

	for(; i < len; i++) {
		if(str[i] != stack[top])
			return false;
		else
			top--;
	}

	return true;
}

int main(int argc, char **argv) {
	printf("%s\n", isPalindrome("abccba", 6) ? "True" : "False");
	printf("%s\n", isPalindrome("abcde", 5) ? "True" : "False");
	return 0;
}

// reference: https://www.geeksforgeeks.org/check-whether-the-given-string-is-palindrome-using-stack/
