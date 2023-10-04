/* -------------------------------------------------------------------------- */
/*                           P.8 Recursive Factorial                          */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int fac(int n) {
	if (n == 0)
        return 1;
    return n * fac(n - 1);
};

int main(int argc, char **argv) {
	printf("%d\n", fac(3));
	return 0;
}