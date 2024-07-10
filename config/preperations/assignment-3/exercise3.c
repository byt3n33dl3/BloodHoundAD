#include <stdio.h>
#include <stdint.h>

int main() {
	int32_t x[4];
	x[0] = 23;
	x[1] = 42;
	x[2] = 5;
	x[3] = (1<<7);
	printf("%p\n", x);
	printf("%p\n", &x); // (a)
	printf("%p\n", x+1); // (b)
	printf("%p\n", &x+1); // (c)
	printf("%d\n", *x); // (d)
	printf("%d\n", *x+x[2]); // (e)
	printf("%d\n", *x+*(x+3)); // (f)
	return 0;
}
