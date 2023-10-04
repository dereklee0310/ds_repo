/* -------------------------------------------------------------------------- */
/*                      P.11 O(logn) exponential function                     */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int exponent(int x, int n) {
    int tmp;

    // handle the odd and even cases due to the integer division n / 2
    // if(n % 2 == 0)
    //     tmp = 1;
    // else
    //     tmp = x;

    // if(n < 2)
    //     return tmp;
    // else
    //     return tmp * exponent(x * x, n / 2);

    // use ternary operator to simplify the code
    tmp = n % 2 == 0 ? 1 : x;
    // base case: odd: 1 -> tmp = x, even: 0 -> tmp = 1  
    tmp = n < 2 ? tmp : tmp * exponent(x * x, n / 2);
    return tmp;
};

int main(int argc, char **argv) {
	int ans = exponent(3, 4);
	printf("%d\n", ans);
	return 0;
}
