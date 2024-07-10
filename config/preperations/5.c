#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main () {
	proc1();
}

void proc1() {
	int secret = 1234;
	proc2();
}

void proc2() {
	int public = 024;
	f();
	printf("f is done");
	g();
	printf("The area code is %i", public);
}