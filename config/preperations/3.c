#include <stdio.h>
#include <stdint.h>

int main() {
	int32_t x[4];
	x[0] = -2;
	x[1] = 34;
	x[2] = 1|2|4; // | is bitwise OR
	printf("%lx \n", x);  // -> 62fe40
	printf("%lx \n", x+2); // (a) -> 62fe48
	printf("%lx \n", &x); // (b) -> 62fe40
	printf("%lx \n", &x+2); // (c) -> 62fe60
	printf("%lx \n", *(x+1) & 2); // (d) & is bitwise AND -> 2
	printf("%lx \n", *x + x[2]); // (e) -> 5
	return 0;
}