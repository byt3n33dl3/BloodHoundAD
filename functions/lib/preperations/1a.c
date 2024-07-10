#include <stdio.h>

void f();

int main()
{
    f();
}

// See: https://stackoverflow.com/questions/22250067/how-to-get-address-of-a-pointer-in-c-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

void f(){
	int* i; // int pointer
	int* a[5];	// array which contains 5 int pointers
	int** x = &i; // address of pointer -> pointer to a pointer
	int y = *i;
	int* z = a[3];
	int** w = a; // this gives a segmentation fault. Why?

	printf("i is at address %p\n", i);
	printf("a is at address %p\n", a);
	printf("x is at address %p\n", x);
	printf("y contains value of i which is %d\n", y);
	printf("z contains pointer address which is contained in a[3] which is %p\n", z);
	printf("a[3] should be the same as z which is %p\n", a[3]);
}
