#include <stdio.h>

int magic_function();

int main (void)
{
	magic_function();

	// I was not able to finish this part in time.
	// I would probably work with the /proc/<pid>/maps file
	// where I get the stack base of the currently running
	// process. Pid could be extracted by invoking getpid()
	// see: http://man7.org/linux/man-pages/man2/getpid.2.html
	// I then would calculate the offsets between the rsp and
	// rbp registers from the stack base.
	// See: https://stackoverflow.com/questions/15515708/determine-a-threads-stack-size-and-location
	// and: https://stackoverflow.com/questions/1401359/understanding-linux-proc-id-maps
}
