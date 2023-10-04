/* -------------------------------------------------------------------------- */
/*                           P.8 Recursive Fibonacci                          */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

// 0, 1, 1, 2, ...
int fib(int n) {
	if(n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main(int argc, char **argv) {
	int ans = fib(5);
	printf("%d\n", ans);
}