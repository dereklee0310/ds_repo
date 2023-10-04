/* -------------------------------------------------------------------------- */
/*                              P.12 Permutation                              */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

void swap(char *num1, char *num2) 
{ 	
	int temp = *num1; 
	*num1 = *num2; 
	*num2 = temp; 
}  

void permutation(char *list, int i, int n) {
	if (i == n - 1) {
        for(int j = 0; j < n; j++)
			printf("%c", list[j]);
		puts("");
		return;		
    }

	for(int j = i; j < n; j++) {
		swap(&list[i], &list[j]);
		permutation(list, i + 1, n);
		swap(&list[i], &list[j]);
	}
};

int main(int argc, char **argv) {
	char str[] = "abc";
	permutation(str, 0, 3); // change the input here :)
	return 0;
}
