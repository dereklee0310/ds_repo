/* -------------------------------------------------------------------------- */
/*               P. 11 Recursive solution for GCD of two numbers              */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int gcd(int a, int b) {
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
};

int main(int argc, char **argv) {
	int ans = gcd(18, 33);
	printf("%d\n", ans);
	return 0;
}
