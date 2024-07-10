#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNucleobase(char c);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        /* argv[0] is the name of the program  */
        printf( "Usage: %s filename\n", argv[0] );
	return (EXIT_FAILURE);
    }
    else
    {
        char const* const fileName = argv[1];
        FILE *file = fopen(fileName, "r");
	char line[256];

        if (file == 0)
        {
            printf("Could not open file\n");
        }
        else
        {
	    int lines = 0;
	    int totalNumberOfChars = 0;
	    int amountOfA = 0;
	    int amountOfC = 0;
	    int amountOfG = 0;
	    int amountOfT = 0;

	    // Loop through the file line by line
	    while (fgets(line, sizeof(line), file)) {
	    	lines++;

		// Check if the 101th character is a newline \n
            	if ( line[100] != '\n'){
	    		return -1; // Invalid format
	    	}

		// Check if the first 100 characters are nucleobases
		for(int i = 0; i <= 99; i++)
		{
			if ( ! isNucleobase(line[i]))
			{
				return -1; // Invalid format
			}

			totalNumberOfChars++;

			// Count the number of nucleobases
			switch(line[i]) {
				case 'A':
					amountOfA++;
     					break;
    				case 'C':
					amountOfC++;
      					break;
    				case 'G':
					amountOfG++;
     					break;
    				case 'T':
					amountOfT++;
  			}
		}
            }

	    // Check if there are 500 lines
            if (lines != 500) return -1; // Invalid format

	    printf("%s", "Valid format.\n");
	    printf("Total number of characters (without newlines): %d\n", totalNumberOfChars);
	    printf("Total number of lines: %d\n", lines);
	    printf("Occurrences of A: %d\n", amountOfA);
	    printf("Occurrences of C: %d\n", amountOfC);
	    printf("Occurrences of G: %d\n", amountOfG);
	    printf("Occurrences of T: %d\n", amountOfT);

    	    fclose(file);
            return 0;
        }
    }
}

bool isNucleobase(char c)
{
	if ( c == 'A' || c == 'C' || c == 'G' || c == 'T')
	{
		return true;
	}
	return false;
}
