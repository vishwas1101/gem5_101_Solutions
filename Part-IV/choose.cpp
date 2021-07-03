#include <stdio.h>

/* How many iterations? */
#define ITERATIONS (1000000)

/* Which bit of the counter to test? */
#define BIT 2

//#ifdef CMOV

/*

#define choose(i, a, b) ({			\
	unsigned long result;			\
	asm("testl %1,%2 ; cmovne %3,%0"	\
		:"=r" (result)			\
		:"i" (BIT),			\
		 "g" (i),			\
		 "rm" (a),			\
		 "0" (b));			\
	result; })
*/

//#else
#define choose(i, a, b) ({			\
	unsigned long result;			\
	asm("testl %1,%2 ; je 1f ; mov %3,%0\n1:"	\
		:"=r" (result)			\
		:"i" (BIT),			\
		 "g" (i),			\
		 "g" (a),			\
		 "0" (b));			\
	result; })

//#endif
int main(int argc, char **argv)
{
	int i;
	unsigned long sum = 0;

	for (i = 0; i < ITERATIONS; i++) {
		unsigned long a = 5, b = 7;
		sum += choose(i, a, b);
	}
	printf("%lu\n", sum);
	return 0;
}
