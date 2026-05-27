
/*                      matrixVector.cpp

   Author: David Galilei Natale

   Last edited: May 2026

   This program multiplies a 2-D matrix and a vector and stores the 
   products in another vector.

   Ran program on JarvisLabs GPU Cloud.

   Compiled with:
   g++ -O3 matrixVector.cpp -o pMV [Enter]
   ./pMV
                                                                           */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/timeb.h>
#include <ctime>
#include <cfloat>

using namespace std;

//This constant is 1e+4900.
const long double UPPER_THRESHOLD = (LDBL_MAX/1.18973149535723177)/1e+32;


void getTime(time_t *, struct timeb *);
void matrix_vector_product(float *, float *, float *, unsigned long long);
void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

int main()
{
	
	struct timeb  startTimeW, endTimeW;
	time_t startTimeC, endTimeC;

	float *A, *v1, *v2;

	unsigned long long matrix_size = 3;

	getTime(&startTimeC, &startTimeW);

	A =  (float *) malloc(matrix_size * matrix_size * sizeof(float));
	v1 = (float *) malloc(matrix_size * sizeof(float));
	v2 = (float *) malloc(matrix_size * sizeof(float));

	for(unsigned long long i = 0; i < matrix_size; i++)
	{
		for(unsigned long long j = 0; j < matrix_size; j++)
		{
			A[i * matrix_size + j] = (float) i * matrix_size + j;
		}
	}

	
	for(unsigned long long i = 0; i < matrix_size; i++)
	{
		v1[i] = (float) i;
	}

	matrix_vector_product(A, v1, v2, matrix_size);

	for(unsigned long long i = 0; i < matrix_size; i++)
	{
		cout<<setprecision(19)<<v2[i]<<"\n";
	}

	free(A);
	free(v1);
	free(v2);

	getTime(&endTimeC, &endTimeW);

	displayTimes(&startTimeC, &endTimeC, &startTimeW, &endTimeW);

	//Should get: 5.00, 14.00, 23.00 

      return 0;
} //end main


void getTime(time_t *cpuTime, struct timeb *wallClockTime)
{
	//get wall-clock time
	ftime(wallClockTime);

	//get cpu time
	time(cpuTime);
}


void matrix_vector_product(float *A, float *v1, float *v2, unsigned long long matrix_size)
{
	for(unsigned long long i = 0; i < matrix_size; i++)
	{
		float sum = 0.0;
		for(unsigned long long j = 0; j < matrix_size; j++)
		{
			sum = sum + A[i * matrix_size + j] * v1[j];
		}
		v2[i] = sum;
	}
}


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall, 
                  struct timeb *endWall)
{
	cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
	cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}


/*                  SAMPLE RUN

Matrix Size =       225,000  

Last entry in *v2:  1,281,450,860,272,280,403,968 

Time:               130 seconds  
                                                          */
