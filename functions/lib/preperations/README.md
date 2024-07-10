# Hacking in C - Exam Preparation

## Lecture 1: General information and the C programming language

* **The C programming language**
	* Invented by Dennis Ritchie in the early 70s
* **C standards and "standards"**
* **C vs. C++**
* **A "portable assembler"**
* **"If programming languages were..."**
* **Syntax and semantics**
* **Unspecified behavior**
* **C compilation**
* **Memory abstraction 1: where data is stored**
* **Where is data allocated?**
* **register**
* **Memory abstraction 2: how data is stored**
* **char**
* **Another quick question...**
* **Other integral types**
* **Floating-point and complex values**
* **Printing values**
* **stdint.h**
* **Implicit type conversion**
* **Explicit casts**
* **A small quiz**
* **Two's complement**
* **Endianess**
* **Endianess, let's try again**
* **Endianess, the conclusion**

## Lecture 2: Pointers

* **Allocation of multiple variables**
* **Printing addresses where data is located**
* **Data alignment**
* **Arrays**
* **Array bounds checking**
* **Typical software security vulnerabilities**
* **Array bound checking**
* **Overrunning arrays**
* **Arrays and alignment**
* **Arrays are passed by reference**
* **Retrieving addresses of pointers using &**
* **Declaring pointers**
* **Creating and dereferencing pointers**
* **Confused? draw pictures!**
* **Pointer quiz**
* **Style debate: int&ast; p or int &ast;p?**
* **Still not confused?**
* **Still not confused? pointers to pointers**
* **Pointer test (Hint: example exam question)**
* **Pointers (continued), arrays and strings**
* **Pointer arithmetic**
* **Using pointers as arrays**
* **Pointer arithmetic for strings**
* **Arrays vs pointers**
* **Using pointers as arrays**
* **A problem with pointers: ...**
* **Two pointers are called aliases if they point to the same location**
* **Recap - so far**
* **The potentical of pointers: inspecting raw memory**
* **Turning pointers into numbers**
* **Strings**
* **String problems**
* **Safer strings and array?**
* **A final string pecularity**
* **Recap**

## Lecture 3: Memory layout

* **A short recap**
* **Memory segments**
* **/proc/&lt;pid&gt;/maps, ps, and size**
* **Virtual memory**
* **Advantages of virtual memory**
* **Bare-metal "memory management"**
* **Global variables**
* **Static variables**
* **The stack - a simple datastructure**
* **Stack frames and the stack pointer**
* **A zoom into the stack frame**
* **The frame pointer**
* **Size of the stack**
* **Things that may go wrong on the stack**
* **... how bad is "wrong" exactly?**
* **What went wrong?**
* **Hardware specifics**
* **Limitations of the stack**
* **The heap**
* **malloc**
* **NULL**
* **Always check for malloc failure!**
* **free**
* **realloc**
* **Dangling pointers, double free, ...**
* **Stack vs. heap vs. data segment**
* **What's wrong with this code?**
* **valgrind**


## Lecture 4: Attacks, part I

* **A short recap**
* **calloc**
* **malloc vs. calloc**
* **Heap management**
* **Reading and manipulating data**
* **Attack scenario**
* **Format-string attacks**
* **A simple main**
* **argc and argv**
* **Arguments passing, the "easy" way**
* **Arguments passing on AMD64**
* **Format strings**
* **Leaking data with format strings**
* **Corrupting data with format strings**
* **Evil formatstrings (summary)**
* **The first format-string attack**
* **Getting rif of format-string attacks**
* **Buffer Overflows**
* **No bounds checking - what could go wrong?**
* **How Heartbleed works**
* **Overwriting data on the stack**
* **The return of the ping of death**


## Lecture 5: Attacks, part II

* **A short recap**
* **Failing at demos...**
* **gets**
* **A simple example**
* **Changing program flow**
* **Overwriting return addresses**
* **Running our own code**
* **Launching a shell**
* **execve**
* **Shell code, part I**
* **Shell code, part II**
* **The complete shell code**
* **Why did we use this shift?**
* **A nop sled**
* **Putting it together**
* **... but gets is deprecated**
* **The underlying problem**
* **Defense mechanisms**
* **Fixing programs**
* **libsafe**
* **Dynamic analysis**
* **Static analysis**
* **What can the compiler do to help?**
* **Can you attack the following code?**
* **Stack protection with canaries**
* **Compiler-generated canaries**
* **W &oplus; X**
* **Enabling/disabling NX**

## Lecture 6: Attacks, part III

* **A short recap**
* **Return to libc**
* **Preparing arguments**
* **"The olds days" (x86)**
* **Nowadays: AMD64 (x64, x86-64)**
* **Countermeasures**
* **Return Oriented Programming (ROP)**
* **ROP: Example**
* **ASLR**
* **Attacks against ASLR**
* **Spot the defect - Heartbleed**
* **Spot the defect - Cloudbleed**
* **How common are these problems?**
* **CWE classification**
* **Example vulnerable code**
* **Normal execution**
* **Attack scenario 1**
* **Attack scenario 2**
* **Attack scenario 3**
* **Attack scenario 4**
* **Attack scenario 5**
* **Attack scenario 6**
* **Attack scenario 7**

## Mock Exam

1. **(6 points)** 


	* a) What should be filled in for the ... below to declare **x, y, z,** and **w** with the right types?

		* ```
			void f(){
				int* i;
				int* a[5];
				... x = &i;
				... y = *i;
				... z = a[3];
				... w = a;
			} 

		* Answer:




	* b) In the code sample above, will **a** be allocated on the heap or the stack?

		* Answer:


	* c) What are the values of **i** and **s** after executing the code below? Assume that **p, q, r** and **s**, have been declared with the correct types.

		* ```
			int32_t i = 5; // Recall: int32_t is the type of signed 32 bit integers
			p = &i;
			q = &p;
			r = *q;
			s = **q;
			(*p)++;
			(*q)++;
			(*r)++;
			s++;

		* Answer:


2. **(5 points)** Suppose the code below is compiled for a 64 bit architecture.

	* ```
		void f(){
			int32_t a[4]; // Recall: int32_t is the type of signed 32 bit integers
			char c;
			int32_t d[2];
			char b[7];
			int64_t i; // Recall: int64_t is the type of signed 64 bit integers
			...
		} 


	* a) What would be an obvious way for a compiler to minimise the amount of stack space needed for this function, without compromising execution speed?

		* Answer:

	* b) Write a piece of C code that could go in the place of the dots that would return "yes" if the compiler has optimised the stack layout as you suggested in a). Explain the idea behind the code.

		* Answer:
	



3. **(5 points)** Consider the following code

	* ```
		#include <stdio.h>
		#include <stdint.h>

		int main() {
			int32_t x[4];
			x[0] = -2;
			x[1] = 34;
			x[2] = 1|2|4; // | is bitwise OR

			printf("%lx \n", x);
			printf("%lx \n", x+2); // (a)
			printf("%lx \n", &x); // (b)
			printf("%lx \n", &x+2); // (c)
			printf("%lx \n", *(x+1) & 2); // (d) & is bitwise AND
			printf("%lx \n", *x + x[2]); // (e)
			return 0;
		}

	* Recall that **%lx** prints a long in hexadecimal notation. Assume that the target machine uses two's complement to represent negative integers. If the first call to **printf** prints **abcdabcdef00**, what do the other calls to **printf** print?	

		* Answer:



4. **(8 points)** Consider the code below. The code is legal C.

	* ```
		1. char* f(char* w) {
		2. 		char *groet = "hello";
		3. 		char *t = malloc(50);
		4. 		char *u = malloc(50);
		5. 		char z[50];
		6. 		strcpy(u,groet); // copies the string groet to u
		7. 		u[5] = ’!’;
		8. 		t = w;
		9. 		printf("String t is now %s.\n", t);
		10. 	t = u;
		11. 	printf("String t is now %s.\n", t);
		12. 	free(t);
		13. 	free(z);
		14. 	return u;
		15. }

	* a) What are the 5 errors in the program above? (One error occurs two times, so there are in fact 6 errors.) For each error, mention the line number(s) involved, and explain what is wrong.

		* Answer:

	* b) Could the print statement in line 9 cause a segmentation fault? Motivate your answer.
	
		* Answer:

	* c) Is it possible to say what the **printf** statement in line 11 will print (if the program does not crash before)? If so, say what it prints; if not, explain why.
	
		* Answer:		





5. **(8 points)** Consider the code below. We assume the compiler does not optimise away redundant variables such as **secret**. The code for functions **f** and **g** is not shown.

	* ```
		1. main () {
		2. 		proc1();
		3. }
		4.
		5. proc1() {
		6. 		int secret = 1234;
		7. 		proc2();
		8. }
		9.
		10. proc2() {
		11. 	int public = 024;
		12. 	f();
		13. 	printf("f is done");
		14. 	g();
		15. 	printf("The area code is %i", public);
		16. }


		

	* Suppose that the function **f** contains some memory weaknesses, which an attacker can exploit to inspect and/or corrupt the stack by supplying malicious input. We assume there are not countermeasures against this, such as stack canaries or a non-executable stack. In answering the questions below, when talking about stack frames always make it clear to which function these belong.


	* a) Could an attacker corrupt the stack during the call to **f** in such a way that after returning from **f** the print statement on line 13 is not executed, but in all other respects execution continues as it normally would? Moativate your answer, by explaining why not, or by explaining how the attacker might achieve this.
	
		* Answer:

	* b) Could an attacker corrupt the stack during the call to **f** so that the value of **secret** will be printed instead of the value of **public** when execution reaches line 15? Motivate your answer, by explaining why not, or by explaining how the attacker might achieve this.

		* Answer:

	* c) Would having a non-executable stack prevent any attacks you discussed in your answers to a) or b) above?
	
		* Answer:

	* d) To provide some additional security, the programmer replaces line 12 with the following lines:

		* ```
			12a.	int test = 2525;
			12b.	f();
			12c.	if (test != 2525) { exit(-1); }

		* Does this provide any additional security? Motivate your answer. (Here assume that the compiler does not optimise the superfluous if-statement away because the **then**-branch is unreachable.)

			* Answer:	

5. **(8 points)** The code running on the vulnerable server hackme.cs.ru.nl for the last assignment was something like

	* ```
		1. #include <stdio.h>
		2.
		3. void echostr(void) {
		4.		char buffer[80];
		5.		gets(buffer);
		6.		printf(buffer);
		7.		printf("\n");
		8. }
		9.
		10. int main(void) {
		11. 	while (1) { echostr(); }
		12. 	return 0;
		13. }

	* a) What are the two security vulnerabilities in this code?
	
		* Answer:

	* b) How would you fix these vulnerabilities?
	
		* Answer:

	* c) To craft the attack string to launch a shell, in addition to the actual shell code, the attacker needs still some additional information. What is additional information that the attacker needs?
	
		* Answer:

	* d) Did the vulnerable server that you had to take over using the given shell code run with a non-executable stack? Or was the impossible to tell from the attack? Motivate your answer.
	
		* Answer:				




