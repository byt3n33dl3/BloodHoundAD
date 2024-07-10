#include <stdio.h>
#include <stdlib.h>

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
	    char a = 'a';
  	    //printf("Size of char : %d\n", (char)sizeof(a));
	    // char = 1 byte

	    // Loop through the file and get one byte
	    while (1) {
		fread(&a, 1, 1, file);
		// %d = Signed decimal integer
		// %u = Unsigned decimal integer
		// %x = Unsigned hexadecimal integer
		// See: http://www.cplusplus.com/reference/cstdio/printf/
		printf("%d %u %x\n", a, a, a);
		if (a == 42) break;
            }

    	    fclose(file);
            return 0;
        }
}
