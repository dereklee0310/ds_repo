/* -------------------------------------------------------------------------- */
/*                   P.9 DP Solution for Fibonacci Sequence                   */
/* -------------------------------------------------------------------------- */

#include <stdio.h>

int fib(int n) {
	int dp[n];
	dp[0] = 0, dp[1] = 1;

	if(n <= 1)
		return n;

	for(int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}


int main(int argc, char **argv) {
	int ans = fib(10);
	printf("%d\n", ans);
	return 0;
}