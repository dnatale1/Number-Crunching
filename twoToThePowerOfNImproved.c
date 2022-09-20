
/*                      twoToThePowerOfNImproved.c

   Author: David Natale

   Last edited: October 2014

   Compiled on GNU C running on Ubuntu 10.04.

   Requires the GNU MP arbitrary precision library. I used v. 5.0.1.

   To run, on the command line type: 

   gcc twoToThePowerOfNImproved.c -lgmp [Enter]
   ./a.out   

   I calculated and printed 2^7,100,000,000.
   This number has 2,137,312,970 digits, starts with 1637821191  
   and ends with 77877109376.   
									                                  */
                                                                   

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <gmp.h>
#include <time.h>

int main( void )
{
	mpz_t base, result;  //Sets these as GMP integers.
	unsigned long int exponent;
	FILE *outFile;
	clock_t c0, c1; /* clock_t is defined on <bits/types.h> as long */


	c0 = clock();
	printf ("\tbegin (CPU):             %ld cycles\n", (long) c0);

	mpz_init(base);
	mpz_init(result);

	gmp_printf("Enter Base: \n");
	gmp_scanf("%Zd", base);

	gmp_printf("Enter Exponent: \n");
	gmp_scanf("%ld", &exponent);

	mpz_pow_ui(result, base, exponent);
	
	outFile = fopen("powerAnswer", "w");
	gmp_fprintf(outFile, "%Zd", result);
	fclose(outFile);
	mpz_clear(result);

	c1 = clock();
	printf ("\tend (CPU);               %ld cycles\n", (long) c1);
	printf ("\telapsed CPU time:        %f seconds\n", (float) (c1 - c0)/CLOCKS_PER_SEC);

	return 0;
}



