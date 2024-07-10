#include <stdio.h>
#include <stdint.h>

int main()
{
	int32_t i = 5; // Recall: int32_t is the type of signed 32 bit integers
	int32_t *p = &i;
	int32_t **q = &p;
	int32_t *r = *q;
	int32_t s = **q;
	(*p)++;
	(*q)++;
	(*r)++;
	s++;

	printf("i is %d\n", i); // i is 7
	printf("s is %d\n", s); // s is 6
}


