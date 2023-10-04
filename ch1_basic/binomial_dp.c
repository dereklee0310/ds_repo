/* -------------------------------------------------------------------------- */
/*                  P.9 DP solution for binomial coefficients                 */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
// int min(int a, int b) { return (a < b) ? a : b; }

int binomial(int n, int k) {
	int dp[n + 1][k + 1];
	
	// i for n, j for k
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= min(i, k); j++) {
			if(j == 0 || j == i) // when n = 0 or n choose n, base cases
			    dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // notice that here might occur an out of range error (i < 1)!
		}
	
	// printf("%d\n", dp[0][-1]);

	return dp[n][k];
}


int main(int argc, char **argv) {
	int ans = binomial(5, 3);
	printf("%d\n", ans);
	return 0;
}