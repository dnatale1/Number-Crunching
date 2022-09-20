
/*                      fibonacci5.c

   Author: GNU MP arbitrary precision library developers

   Last edited: January 24, 2009

   Compiled on GNU C running on Fedora 9.

   Requires the GNU MP arbitrary precision library. I used v. 4.2.2.

   To run, on the command line type: 

   gcc fibonacci5.c -lgmp [Enter]
   ./a.out   

   David Natale computed the 10200000000th Fibonacci number. This number has 
   2,131,673,931 digits, starts with 1585981372 and ends with 6400000000.      */
                                                                   

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <gmp.h>
#include <time.h>

int main( void )
{
	mpz_t z;
	FILE *outFile;
  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */
	clock_t c0, c1; /* clock_t is defined on <bits/types.h> as long */


	t0 = time(NULL);
	c0 = clock();
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);
	printf ("\tbegin (CPU):             %ld cycles\n", (long) c0);

	mpz_init(z);
	mpz_fib_ui(z, 10); 

	outFile = fopen("fibonacciAnswer", "w");
	gmp_fprintf(outFile, "%Zd", z);
	fclose(outFile);
	mpz_clear(z);

	t1 = time(NULL);
	c1 = clock();
	printf ("\n\tend (wall):              %ld seconds\n", (long) t1);
	printf ("\tend (CPU);               %ld cycles\n", (long) c1);
	printf ("\n\telapsed wall clock time: %ld seconds\n", (long) (t1 - t0));
	printf ("\telapsed CPU time:        %f seconds\n", (float) (c1 - c0)/CLOCKS_PER_SEC);

	return 0;
}



