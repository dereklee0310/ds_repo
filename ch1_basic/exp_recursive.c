/* -------------------------------------------------------------------------- */
/*                            Recursive Exponential                           */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int exponent(int x, int n) {
	if(n == 0)
        return 1;
    return x * exponent(x, n - 1);
};

int main(int argc, char **argv) {
	int ans = exponent(5, 3);
	printf("%d\n", ans);
	return 0;
}