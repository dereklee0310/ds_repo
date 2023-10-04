#include <stdio.h>

void swap(char *num1, char *num2) 
{ 	
	// cannot use pointer like this:
	// 1. because it actually use the content of the whole array instead of specific characters
	char temp = *num1; 
	*num1 = *num2; 
	*num2 = temp; 
}  

int main(int argc, char **argv) {
	// char *str = "abc"; // this is read-only!!
	char str[5] = "abc"; // this is the right way to declare a string

	swap(&str[0], &str[1]);
	// swap(&num[0], &num[1]);
	// swap(str, str + 1);


	return 0;
}
