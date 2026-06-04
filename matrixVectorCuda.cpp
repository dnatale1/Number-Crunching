
/*                      matrixVectorCuda.cu

   Author: David Galilei Natale

   Last edited: May 2026

   Ran program on JarvisLabs Cloud in India utilizing NVIDIA H200 GPUs. 

   Compiled with:
   nvcc -O3 matrixVectorCuda.cu -o pMVC
   ./pMVC
                                                                           */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/timeb.h>
#include <ctime>
#include <cfloat>
#include <cuda_runtime.h>

using namespace std;



__global__ void matrix_vector_product(float *A, float *v1, float *v2, unsigned long long matrix_size)
{
	int row = blockIdx.x * blockDim.x + threadIdx.x;
	int col = blockIdx.y * blockDim.y + threadIdx.y;  //i * matrix_size + j;

	if(col == 0  && row < matrix_size)
	{
		float sum = 0.0;
		for(unsigned long long i = 0; i < matrix_size; i++)
		{
			sum = sum + A[row * matrix_size + i] * v1[i];
		}
		v2[row] = sum;
	}
}	
	

	

void getTime(time_t *, struct timeb *);

void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

int main()
{
	
	struct timeb  startTimeW, endTimeW;
	time_t startTimeC, endTimeC;

	float *A,  *A_gpu;
	float *v1, *v1_gpu;
	float *v2, *v2_gpu;

	unsigned long long matrix_size = 300000;

	getTime(&startTimeC, &startTimeW);

	dim3 block_shape = dim3(32, 32); //each block contains 32 times 32 threads

	dim3 grid_shape  = dim3(max(1.0, ceil((float) matrix_size / (float) block_shape.x)),
			        max(1.0, ceil((float) matrix_size / (float) block_shape.y)));

	//Allocating memory space for the host CPU
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



	//Allocating memory space for the device GPU
	cudaMalloc((void **)  &A_gpu, matrix_size * matrix_size * sizeof(float));
	cudaMalloc((void **)  &v1_gpu, matrix_size * sizeof(float));
	cudaMalloc((void **)  &v2_gpu, matrix_size * sizeof(float));

	cudaMemcpy(A_gpu, A, matrix_size * matrix_size * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(v1_gpu, v1, matrix_size * sizeof(float), cudaMemcpyHostToDevice);

	matrix_vector_product<<<grid_shape, block_shape>>>(A_gpu, v1_gpu, v2_gpu, matrix_size);

	//Now to get the resulting products of v2 back to the host device
	cudaMemcpy(v2, v2_gpu, matrix_size * sizeof(float), cudaMemcpyDeviceToHost);

	for(unsigned long long i = 0; i < matrix_size; i++)
	{
		cout<<setprecision(22)<<v2[i]<<"\n";
	}

	free(A);
	free(v1);
	free(v2);
	cudaFree(A_gpu);
	cudaFree(v1_gpu);
	cudaFree(v2_gpu);

	getTime(&endTimeC, &endTimeW);

	displayTimes(&startTimeC, &endTimeC, &startTimeW, &endTimeW);


      return 0;
} //end main


void getTime(time_t *cpuTime, struct timeb *wallClockTime)
{
	//get wall-clock time
	ftime(wallClockTime);

	//get cpu time
	time(cpuTime);
}



void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall, 
                  struct timeb *endWall)
{
	cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
	cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}

