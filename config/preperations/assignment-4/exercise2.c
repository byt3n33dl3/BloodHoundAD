#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FREE_MEMORY 0 // Change this to 1 if you want this program to crash!

void heap_attack(void)
{
	char* raw_memory = malloc(8);
	char* s1_copy = NULL;
	char* s2_copy = NULL;
	free(raw_memory); // We only need the address as starting point

	while (1) {
		if(!strcmp(raw_memory, "4226887"))
		{
			printf("Studentnumber %s found at address %p\n", "4226887", raw_memory);
			s1_copy = raw_memory;
		} else if (!strcmp(raw_memory, "4226888"))
		{
			printf("Studentnumber %s found at address %p\n", "4226888", raw_memory);
			s2_copy = raw_memory;
		}
		raw_memory--;
    		if (!(s1_copy == NULL || s2_copy == NULL)) break;
	}
	memset(s1_copy + 7, ' ', s2_copy - s1_copy - 7);
}

int main(void)
{
	char *s1 = malloc(8);
	if(s1 == NULL) return -1;
	char *s2 = malloc(8);
	if(s2 == NULL) return -1;


	// Nice to know: https://stackoverflow.com/questions/43471724/strcpy-working-no-matter-the-malloc-size
	strcpy(s1, "4226887");
	strcpy(s2, "4226888"); // does not exist actually

	heap_attack();

	printf("student 1: %s\n", s1);
	printf("student 2: %s\n", s2);

	#if FREE_MEMORY
		free(s1);
		free(s2);
	#endif

	return 0;
}
