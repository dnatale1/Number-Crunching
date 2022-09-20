
/*                      matrixMult3.cpp
 *
 *  Author: David Galilei Natale
 *
 *  October 2020
 *
 *  I used Intel compiler 19.0.5 and GNU Multiple Precision Arithmetic Library 6.0.
 *
 *  Compiled with: icpc -fma -pc80 -axSSE4.2 -O3 matrixMult3.cpp -lgmp -lgmpxx
 *                 ./a.out 
 *  
 *  This program requires 196GB RAM to run.
 *
 *  The last entry in the MATRIXRESULT file is: 1695008528530121059500.
 *
 *  Program ran in 27 hours. 
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sys/timeb.h>
#include <gmpxx.h>


using namespace std;

int main()
{
        
	mpz_t sum;

	ofstream outFile1, outFile2, outFile3;

	mpz_t  A[8053][8054];
	mpz_t  B[8054][8057];
	mpz_t  R[8053][8057];
	unsigned long long  r, c, p;
	mpz_init(sum);


  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */
	t0 = time(NULL);
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);

	
	printf("%s", gmp_version);
	cout<<endl<<endl;


 	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n";
	for(r = 0; r < 8053; r++)
	{
		for(p = 0; p < 8054; p++)
		{
			mpz_init2(A[r][p], 8054);
		}
	}

 	
	for(r = 0; r < 8053; r++)
	{
		for(p = 0; p < 8054; p++)
		{
			mpz_add_ui(sum, sum, 10);
			mpz_set(A[r][p], sum);
		}
	}


	
	for( r = 0; r < 8053; r++)
	{
		for(p = 0; p < 8054; p++)
		{
			outFile1<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();


	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";
	mpz_init(sum);
	for(p = 0; p < 8054; p++)
	{
		for(c = 0; c < 8057; c++)
		{
			mpz_init2(B[p][c], 8057);
		}
	}
	
	
	for(p = 0; p < 8054; p++)
	{
		for(c = 0; c < 8057; c++)
		{
			mpz_add_ui(sum, sum, 10);
			mpz_set(B[p][c], sum);
		}
	}

	for(p = 0; p < 8054; p++)
	{
		for(c = 0; c < 8057; c++)
		{
			outFile2<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();

	
	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 8053; r++)
	{
		for(c = 0; c < 8057; c++)
		{
			mpz_init2(R[r][c], 8057);
		}
	}

  
	for(r = 0; r < 8053; r++)
	{
		for(c = 0; c < 8057; c++)
		{
			mpz_init(R[r][c]);
			for(p = 0; p < 8054; p++)
			{
				mpz_addmul(R[r][c], A[r][p], B[p][c]);				
			}
		}
	}

	
	for(r = 0; r < 8053; r++)
	{
		for(c = 0; c < 8057; c++)
		{
			outFile3<<R[r][c]<<" ";
		}
		outFile3<<endl;
	}

	outFile3.close();


	t1 = time(NULL);
	printf ("\n\tend (wall):              %ld seconds\n", (long) t1);
	printf ("\n\telapsed wall clock time: %ld seconds\n", (long) (t1 - t0);

	return 0;
}



