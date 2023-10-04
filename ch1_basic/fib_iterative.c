/* -------------------------------------------------------------------------- */
/*                P.9 Iterative Solution for Fibonacci Sequence               */
/* -------------------------------------------------------------------------- */

#include <stdio.h>

int fib(int n) {
    int pre = 0, cur = 1, tmp;

	for(int i = 0; i < n - 1; i++) {
        tmp = cur + pre;
        pre = cur;
        cur = tmp;
    }
    return cur;
}

int fib2(int n) {
    int pre, cur = 1, tmp;

    if(n <= 1)
        return n;
    
    for(int i = 2; i <= n; i++) {
        tmp = cur + pre;
        pre = cur;
        cur = tmp;
    }
    return cur;
}


int main(int argc, char **argv) {
	int ans = fib(10);
	printf("%d\n", ans);
	return 0;
}