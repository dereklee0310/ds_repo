/* -------------------------------------------------------------------------- */
/*              P.9 Recursive solution for binomial coefficients              */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int binomial(int n, int k) {
	if(k == 0 || k == n)
        return 1;
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
};

int main(int argc, char **argv) {
	int ans = binomial(5, 3); // change the input here :)
	printf("%d\n", ans);
	return 0;
}