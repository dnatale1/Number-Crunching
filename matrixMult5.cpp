
/*                      matrixMult5.cpp
 *
 *  Author: David Galilei Natale
 *
 *  August 2023
 *
 *  I used Boost 1.72 and GNU compiler 9.1.0.
 *
 *  Compiled with: g++ -O3 matrixMult5.cpp -o proj5Main -lboost_regex
 *                 /.proj5Main
 *
 *  This program requires 80GB RAM to run.
 *
 *  The last entry in the MATRIXRESULT file is:    1053174833938909533274500. 
 *
 *  Program ran for 4 days on the Pitzer cluster at the Ohio Supercomputer Center.                
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sys/timeb.h>
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;

int main()
{
        using namespace boost::multiprecision;

	ofstream outFile1, outFile2, outFile3;

	int128_t  A[29153][29154];
	int128_t  B[29154][29157];
	int128_t  R[29153][29157];
	unsigned long long  r, c, p;
	int128_t  sum = 0;

  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */


	t0 = time(NULL);
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);



	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n"; 	
	for(r = 0; r < 29153; r++)
	{
		for(p = 0; p < 29154; p++)
		{
			sum = sum + 10;
			A[r][p] = sum;
		}
	}


	
	for( r = 0; r < 29153; r++)
	{
		for(p = 0; p < 29154; p++)
		{
			outFile1<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();


	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";	
	sum = 0;
	for(p = 0; p < 29154; p++)
	{
		for(c = 0; c < 29157; c++)
		{
			sum = sum + 10;
			B[p][c] = sum;
		}
	}

	for(p = 0; p < 29154; p++)
	{
		for(c = 0; c < 29157; c++)
		{
			outFile2<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();


	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 29153; r++)
	{
		for(c = 0; c < 29157; c++)
		{
			R[r][c] = 0;
			for(p = 0; p < 29154; p++)
			{
				R[r][c] += A[r][p] * B[p][c];
			}
		}
	}

	
	for(r = 0; r < 29153; r++)
	{
		for(c = 0; c < 29157; c++)
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



