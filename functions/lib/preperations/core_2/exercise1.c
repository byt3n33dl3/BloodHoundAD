#include <stdio.h>

void printByteByByte(char *input, int length)
{
        int i;
        for(i = 0; i < length; i++)
        {
                printf("%-20p 0x%-20x %-20u\n", input + i , *(input + i), *(input + i));
        }
}

int main (void)
{
	short i = 0x1234;
	char x = -127;
	long sn1 = 4226887;
	long sn2 = 4226887;
	int y[2] = {0x11223344,0x44332211};

	printf("Size of i (short): %ld bytes\n",sizeof(i));
    	printf("Size of x (char): %ld bytes\n",sizeof(x));
    	printf("Size of sn1 (long): %ld bytes\n",sizeof(sn1));
    	printf("Size of sn2 (long): %ld bytes\n",sizeof(sn2));
	printf("Size of y (int array): %ld bytes\n",sizeof(y));

	// Printing the header with left aligned width
	printf("\n%-20s%-20s%-20s\n", "address", "content (hex)", "content (dec)");

	// There is apparently no way to repeat a character
	// x times with printf
	int dash_counts;
    	for(dash_counts = 0; dash_counts < 60; dash_counts++) putchar('-');
	putchar('\n');

	printByteByByte((char*) &i, sizeof(i));
	printByteByByte((char*) &x, sizeof(x));
	printByteByByte((char*) &sn1, sizeof(sn1));
	printByteByByte((char*) &sn2, sizeof(sn2));
	printByteByByte((char*) &y, sizeof(y));
}
