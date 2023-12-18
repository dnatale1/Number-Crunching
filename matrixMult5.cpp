
/*                      matrixMult5.cpp
 *
 *  Author: David Galilei Natale
 *
 *  December 2023
 *
 *  I used Boost 1.72 and GNU compiler 11.2.0.
 *
 *  Compiled with: g++ -O3 matrixMult5.cpp -o proj5Main -lboost_regex
 *                 ./proj5Main
 *
 *  This program requires 96GB RAM to run.
 *
 *  The last entry in the MATRIXRESULT file is:   1887947597387608203251000. 
 *
 *  Program ran for 1 week on the Pitzer cluster at the Ohio Supercomputer Center.                
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

	int128_t  A[32763][32764];
	int128_t  B[32764][32767];
	int128_t  R[32763][32767];
	unsigned long long  r, c, p;
	int128_t  sum = 0;

  	time_t  t0, t1; /* time_t is defined on <bits/types.h> as long */


	t0 = time(NULL);
	printf ("\tbegin (wall):            %ld seconds\n", (long) t0);



	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n"; 	
	for(r = 0; r < 32763; r++)
	{
		for(p = 0; p < 32764; p++)
		{
			sum = sum + 10;
			A[r][p] = sum;
		}
	}


	
	for( r = 0; r < 32763; r++)
	{
		for(p = 0; p < 32764; p++)
		{
			outFile1<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();


	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";	
	sum = 0;
	for(p = 0; p < 32764; p++)
	{
		for(c = 0; c < 32767; c++)
		{
			sum = sum + 10;
			B[p][c] = sum;
		}
	}

	for(p = 0; p < 32764; p++)
	{
		for(c = 0; c < 32767; c++)
		{
			outFile2<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();


	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 32763; r++)
	{
		for(c = 0; c < 32767; c++)
		{
			R[r][c] = 0;
			for(p = 0; p < 32764; p++)
			{
				R[r][c] += A[r][p] * B[p][c];
			}
		}
	}

	
	for(r = 0; r < 32763; r++)
	{
		for(c = 0; c < 32767; c++)
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



