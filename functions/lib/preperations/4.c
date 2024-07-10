#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* f(char* w);

int main() {
	f("Chris");
}

char* f(char* w) {
	char *groet = "hello";
	char *t = malloc(50);
	char *u = malloc(50);
	char z[50];
	strcpy(u,groet); // copies the string groet to u
	u[5] = '!';
	t = w;
	printf("String t is now %s.\n", t); // -> String t is now Chris.
	t = u;
	printf("String t is now %s.\n", t); // -> String t is now hello!.
	free(t);
	free(z); //  warning: attempt to free a non-heap object 'z'
	return u;
}

