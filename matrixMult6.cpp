
/*                      matrixMult6.cpp
 *
 *  Author: David Galilei Natale
 *
 *  January 2024
 *
 *  I used Intel compiler 2021.5.0.
 *
 *  Compiled with:
 *  icpc -O3 matrixMult6.cpp -o proj6
 *  ./proj6
 *
 *  This program requires 128GB RAM to run.
 *
 *  The last entry in the MATRIXRESULT file is: 18404861690925451886723072. 
 *
 *  Program ran for 3.5 days on the Pitzer cluster at the Ohio Supercomputer Center.                
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <sys/timeb.h>
#include <iomanip>

using namespace std;


int main()
{ 

	ofstream outFile1, outFile2, outFile3;

	long double  A[51663][51664];
	long double  B[51664][51667];
	long double  R[51663][51667];
	unsigned long long  r, c, p;
	unsigned long long  sum = 0;

  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */


	t0 = time(NULL);
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);



	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n"; 	
	for(r = 0; r < 51663; r++)
	{
		for(p = 0; p < 51664; p++)
		{
			sum = sum + 10;
			A[r][p] = sum;
		}
	}


	
	for( r = 0; r < 51663; r++)
	{
		for(p = 0; p < 51664; p++)
		{
			outFile1<<setprecision(30)<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();


	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";	
	sum = 0;
	for(p = 0; p < 51664; p++)
	{
		for(c = 0; c < 51667; c++)
		{
			sum = sum + 10;
			B[p][c] = sum;
		}
	}

	for(p = 0; p < 51664; p++)
	{
		for(c = 0; c < 51667; c++)
		{
			outFile2<<setprecision(30)<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();


	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 51663; r++)
	{
		for(c = 0; c < 51667; c++)
		{
			R[r][c] = 0;
			for(p = 0; p < 51664; p++)
			{
				R[r][c] += A[r][p] * B[p][c];
			}
		}
	}

	
	for(r = 0; r < 51663; r++)
	{
		for(c = 0; c < 51667; c++)
		{
			outFile3<<setprecision(30)<<R[r][c]<<" ";
		}
		outFile3<<endl;
	}

	outFile3.close();

	t1 = time(NULL);

	printf ("\n\tend (wall):              %ld seconds\n", (long) t1);

	printf ("\n\telapsed wall clock time: %ld seconds\n", (long) (t1 - t0));

	return 0;
}



