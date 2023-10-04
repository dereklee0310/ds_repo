/* -------------------------------------------------------------------------- */
/*                   P.10 Ackerman's function implementation                  */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

int ackerman(int m, int n) {
	if(m == 0)
        return n + 1;
    if (n == 0)
        return ackerman(m - 1, 1);
    return ackerman(m - 1, ackerman(m, n - 1));    
};

int main(int argc, char **argv) {
	int ans = ackerman(2, 2); // change the input here :)
	printf("%d\n", ans);
	return 0;
}
