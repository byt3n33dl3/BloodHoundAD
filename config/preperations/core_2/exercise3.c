#include <stdio.h>
#include <string.h>

// I had to use a macro instead of a normal function
// declaration because passing an array as an argument
// is the same as passing a simple pointer. You cannot
// compute the size/length of the array inside the function.
#define ARRAY_LENGTH(X) (sizeof(X)/sizeof(*(X)))

void printArray(int intArray[], int length, char *name)
{
	printf("Elements of array %s: ", name);
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", intArray[i]);
	}
	printf("\n");
}

void addvector(int *r, const int *a, const int *b, unsigned int len)
{
	printf("Executing addvector function...\n");
	unsigned int i;
	for(i=0;i<len;i++)
	{
		// r[i] = a[i] + b[i]
		*(r+i) = (*(a+i)) + (*(b+i));
	}
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	// The memcmp() function shall return an integer greater than,
	// equal to, or less than 0, if the object pointed to by s1
	// is greater than, equal to, or less than the object pointed
	// to by s2, respectively.

	size_t i;
  	const unsigned char *s1_tmp = (const unsigned char*) s1;
  	const unsigned char *s2_tmp = (const unsigned char*) s2;

 	for (i = 0; i < n; i++)
 	{
 		if (*s1_tmp < *s2_tmp)
    		{
			return -1;
		}
   		else if (*s1_tmp > *s2_tmp)
		{
			return 1;
		}
		s1_tmp++;
		s2_tmp++;
	}
	return 0;
}

int memcmp_backwards(const void *s1, const void *s2, size_t n)
{
        // The memcmp() function shall return an integer greater than,
        // equal to, or less than 0, if the object pointed to by s1
        // is greater than, equal to, or less than the object pointed
        // to by s2, respectively.

        size_t i;
        const unsigned char *s1_tmp = (const unsigned char*) s1;
        const unsigned char *s2_tmp = (const unsigned char*) s2;

        for (i = (n-1); i >= 0; i--)
        {
                if (*s1_tmp < *s2_tmp)
                {
                        return -1;
                }
                else if (*s1_tmp > *s2_tmp)
                {
                        return 1;
                }
                s1_tmp--;
                s2_tmp--;
        }
        return 0;
}



int main (void)
{
	int r[9];
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	int length_of_r = ARRAY_LENGTH(r);
	int length_of_a = ARRAY_LENGTH(a);
	int length_of_b = ARRAY_LENGTH(b);

	printf("Length of r: %d\n", length_of_r);
	printf("Length of a: %d\n", length_of_a);
	printf("Length of b: %d\n", length_of_b);

	printArray(a, length_of_a, "a");
	printArray(b, length_of_b, "b");
	printArray(r, length_of_r, "r");

	addvector(r, a, b, length_of_r);

	printArray(r, length_of_r, "r");

	char *input1 = "test";
	char *input2 = "TEST";

	int input_size = sizeof(input1);

	// See: https://www.convertbinary.com/alphabet/
	// Uppercase letters take less space in binary represenation than lowercase letters. Crazy shit.
	printf("Memcmp between %s and %s results in: %d\n", input1, input2, memcmp(input1, input2, input_size));
	printf("Memcmp_backwards between %s and %s results in: %d\n", input1, input2, memcmp_backwards(input1, input2, input_size));
}
