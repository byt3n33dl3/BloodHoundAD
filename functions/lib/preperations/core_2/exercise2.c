#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	bool true_bool = true;
	bool false_bool = false;

	printf("Size of bool: %ld bytes\n",sizeof(bool));
	printf("Hex representation of true bool: 0x%u\n", true_bool);
	printf("Hex representation of false bool 0x%u\n", false_bool);

	true_bool = 0x2;
	false_bool = 0x443322;

	printf("true_bool is set to 0x2: %s\n", true_bool ? "true" : "false");
	printf("false_bool is set to 0x443322: %s\n", false_bool ? "true" : "false");

	false_bool = 0x0;

	printf("false_bool is set to 0x0: %s\n", false_bool ? "true" : "false");
}
