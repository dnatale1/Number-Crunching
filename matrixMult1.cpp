
/*                      matrixMult1.cpp
 *
 *  Author:  David Galilei Natale
 *
 *  July 2004
 *
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
        
	ofstream outFile1, outFile2, outFile3;

	int  A[3][4];
	int  B[4][7];
	int  R[3][7];
	int  r, c, p;
	int sum = 0;


	outFile1.open("MATRIX1");
	outFile1<<"\nMATRIX 1:\n\n"; 	
	for(r = 0; r < 3; r++)
	{
		for(p = 0; p < 4; p++)
		{
			sum = sum + 10;
			A[r][p] = sum;
		}
	}


	
	for( r = 0; r < 3; r++)
	{
		for(p = 0; p < 4; p++)
		{
			outFile1<<A[r][p]<<" ";
		}
		outFile1<<endl;
	}

	outFile1.close();

	outFile2.open("MATRIX2");
	outFile2<<"\nMATRIX 2:\n\n";	
	sum = 0;
	for(p = 0; p < 4; p++)
	{
		for(c = 0; c < 7; c++)
		{
			sum = sum + 10;
			B[p][c] = sum;
		}
	}

	for(p = 0; p < 4; p++)
	{
		for(c = 0; c < 7; c++)
		{
			outFile2<<B[p][c]<<" ";
		}
		outFile2<<endl;
	}

	outFile2.close();

	outFile3.open("MATRIXRESULT");
	outFile3<<"\nMATRIX RESULT:\n\n";
	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 7; c++)
		{
			R[r][c] = 0;
			for(p = 0; p < 4; p++)
			{
				R[r][c] += A[r][p] * B[p][c];
			}
		}
	}

	
	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 7; c++)
		{
			outFile3<<R[r][c]<<" ";
		}
		outFile3<<endl;
	}

	outFile3.close();


	return 0;
}



