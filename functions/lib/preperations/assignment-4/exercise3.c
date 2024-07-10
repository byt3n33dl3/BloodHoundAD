#include <stdlib.h>
#include <stdio.h>

// Copied from: https://stackoverflow.com/questions/1733881/c-correctly-freeing-memory-of-a-multi-dimensional-array
void freeArray(unsigned long long **a, int m) {
    int i;
    for (i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}



int main(void)
{
	int i,j;
	unsigned long long **m;
	unsigned long long **mt;

	while(1)
	{
	// allocate matrix m
	m = malloc(1000*sizeof(unsigned long long*));
	if(m == NULL) return -1;
	for(i=0;i<1000;i++)
	{
		m[i] = malloc(1000*sizeof(unsigned long long));
		if(m[i] == NULL) return -1;
	}

	// allocate matrix mt
	mt = malloc(1000*sizeof(unsigned long long*));
	if(mt == NULL) return -1;
	for(i=0;i<1000;i++)
	{
		mt[i] = malloc(1000*sizeof(unsigned long long));
		if(mt[i] == NULL) return -1;
	}

	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			m[i][j] = 1000*i+j;

	// transpose matrix m, write to mt
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			mt[i][j] = m[j][i];

	// FIXED: free matrices m and mt
	freeArray(m, 1000);
	freeArray(mt, 1000);
	//free(m);
	//free(mt);
	}
return 0;
}
