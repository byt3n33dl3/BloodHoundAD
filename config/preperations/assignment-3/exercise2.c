#include <stdio.h>
#include <stdlib.h>


// Warning: This probably takes forever
// Another approach involves the ulimit -a command
// which gives you information about different
// memory sections
int main (void)
{

	unsigned int heap_size = 1;

	int limit_reached = 0;

	while(!limit_reached){
		void *tmp = malloc(heap_size);

		// Malloc cannot allocate memory when it returns NULL
		if(tmp == NULL){
			limit_reached = 1;
		}
		free(tmp);
		heap_size++;
	}

	printf("\nOne malloc can allocate at most %d bytes.", heap_size);

}
