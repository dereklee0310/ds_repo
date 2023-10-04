/* -------------------------------------------------------------------------- */
/*                             P.13 Tower of Hanoi                            */
/* -------------------------------------------------------------------------- */
#include <stdio.h>

void hanoi(int n, int src, int aux, int des) {
	if(n == 1)
        printf("move disk1 from %d to %d\n", src, des);
    else {
        hanoi(n - 1, src, des, aux);
        printf("move disk%d from %d to %d\n", n, src, des);
        hanoi(n - 1, aux, src, des);
    }
};

int main(int argc, char **argv) {
	hanoi(3, 1, 2, 3);
	return 0;
}