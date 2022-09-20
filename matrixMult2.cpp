
/*                      matrixMult2.cpp
 *
 *  Author: David Galilei Natale
 *
 *  May 2020
 *
 *  I used Intel compiler 19.0.5.
 *
 *  Compiled with: icpc -fma -pc80 -axSSE4.2 -O3 matrixMult2.cpp
 *                 /.a.out
 *
 *  The last entry in the MATRIXRESULT file is:           18256327827645939500.
 *
 *  NOTE: The highest value for an unsigned long long is: 18446744073709551615. 
 *
 *  Program ran in 35 seconds.                
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sys/timeb.h>


using namespace std;

int main()
{
     

	ofstream outFile1, outFile2, outFile3;

	unsigned long long  A[3253][3254];
	unsigned long long  B[3254][3257];
	unsigned long long  R[3253][3257];
	unsigned long long  r, c, p;
	unsigned long long sum = 0;

  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */


	t0 = time(NULL);
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);



	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n"; 	
	for(r = 0; r < 3253; r++)
	{
		for(p = 0; p < 3254; p++)
		{
			sum = sum + 10;
			A[r][p] = sum;
		}
	}


	
	for( r = 0; r < 3253; r++)
	{
		for(p = 0; p < 3254; p++)
		{
			outFile1<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();


	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";	
	sum = 0;
	for(p = 0; p < 3254; p++)
	{
		for(c = 0; c < 3257; c++)
		{
			sum = sum + 10;
			B[p][c] = sum;
		}
	}

	for(p = 0; p < 3254; p++)
	{
		for(c = 0; c < 3257; c++)
		{
			outFile2<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();


	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 3253; r++)
	{
		for(c = 0; c < 3257; c++)
		{
			R[r][c] = 0;
			for(p = 0; p < 3254; p++)
			{
				R[r][c] += A[r][p] * B[p][c];
			}
		}
	}

	
	for(r = 0; r < 3253; r++)
	{
		for(c = 0; c < 3257; c++)
		{
			outFile3<<R[r][c]<<" ";
		}
		outFile3<<endl;
	}

	outFile3.close();

	t1 = time(NULL);

	printf ("\n\tend (wall):              %ld seconds\n", (long) t1);

	printf ("\n\telapsed wall clock time: %ld seconds\n", (long) (t1 - t0));

	return 0;
}



