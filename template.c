#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int func() {
	return 0;
};

int main(int argc, char **argv) {
	int ans = func("input");
	printf("%d\n", ans);
	return 0;
}

