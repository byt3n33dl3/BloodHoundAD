#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	char const* const fileName = "/dev/urandom";
	FILE *file = fopen(fileName, "r");

        if (file == 0)
        {
            printf("Could not open file\n");
        }
        else
	{
	    uint16_t a = 0;

	    // Loop through the file and get two bytes
	    while (1) {
		fread(&a, 2, 2, file);
		// Use 0 to get zero padding and 4 to set the width to 4.
		// %x = Unsigned hexadecimal integer
		// See: https://stackoverflow.com/questions/8060170/printing-hexadecimal-characters-in-c
		printf("%04x\n", a);
		if (a == 42) break;
            }

    	    fclose(file);
            return 0;
        }
}
