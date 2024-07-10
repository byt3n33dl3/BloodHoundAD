#include <stdio.h>

void echostr(void) {
	char buffer[80];
	gets(buffer);
	printf(buffer);
	printf("\n");
}

int main(void) {
	while (1) { echostr(); }
	return 0;
}