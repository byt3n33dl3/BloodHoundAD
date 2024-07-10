#include <stdio.h>
#include <stdint.h>

void f();

int main()
{
	f();
}

void f(){
	int32_t a[4]; // Recall: int32_t is the type of signed 32 bit integers
	char c;
	int32_t d[2];
	char b[7];
	int64_t i; // Recall: int62_t is the type of signed 64 bit integers
	// print "yes" if the compiler has optimised the stack layout
}

