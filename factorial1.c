
/*                      factorial1.c

   Author: Nyna of PHP-Games (I don't know her last name.)

   Last edited: January 19, 2009

   Compiled on GNU C running on Fedora 9.

   Requires the GNU MP arbitrary precision library. I used v. 4.2.2.

   To run, on the command line type: 

   gcc factorial1.c -lgmp [Enter]
   ./a.out   

   David Natale computed 260000000!. This number has 2,074,976,510
   digits, starts out with 6083364006 and ends with 0000000000.     */
                                                                   

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
	mpz_fac_ui(z, 5);

	outFile = fopen("factorialAnswer", "w");
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



