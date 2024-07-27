
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: May 2024

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n the computation is performed instantaneously.

   I used Intel compiler 2021.5.0 and Boost 1.75.0.   

   Compiled with: icpc -O3 fibonacci8Enhanced.cpp -o pFibo8 -lboost_regex
                  ./pFibo8
                                                                                               */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/timeb.h>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

/* The below constant is 1e+2466. The rationale for using this
   value is as follows: The maximum long double value is 1.18e+4932.
   In the matrixSquare() function, the e-notation (e+) value of
   fibArray[i][j] is doubled after each complete iteration of
   the nested for loop. Thus 1e+2466 squared is 1e+4932.       */

const long double UPPER_THRESHOLD = (((((((((LDBL_MAX/1.18973149535723177)/
1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+2;

void getTime(time_t *cpuTime, struct timeb *wallClockTime);


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall);

int main()
{
    using namespace boost::multiprecision; 

    long double A[2][2], B[2][2], fibArray[2][2];
    uint1024_t           n = 0;
    uint1024_t           eCounter1 = 0;
    uint1024_t           eCounter2 = 0;
    uint1024_t           eCounter3 = 0;
    uint1024_t           eCounter4 = 0; 

    uint1024_t           fibTrackingVariable = 0;
    uint1024_t           fibTrackingVariableMinus = 0;
    uint1024_t           fibTrackingVariablePlus = 0;

    ofstream outFile1;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;


    cout<<"\nEnter Nth Fibonacci number: ";
    cin>>n;

    getTime(&startTimeC, &startTimeW);

    if((n == 1) || (n == 2))
       cout<<"\n\nFIBONACCI # "<<n<<" = "<<"1"<<"\n\n\n";
    else
    {
            /*First, initialize A and B matrices with {{1,1}{1,0}}.
              Then, initialize fibArray matrix with {{0,0}{0,0}}.    */
            int i, j;

	   //The 3 nested for loops below initialize A and B matrices with {{1,1}{1,0}}.
	    for(i = 0; i < 1; i++)
    	    {	
      		for(j = 0; j < 2; j++)
      		{
         	  A[i][j] = 1.0;
          	  B[i][j] = 1.0;
      		}
    	    }

    	    for(i = 1; i < 2; i++)
    	    {
      		for(j = 0; j < 1; j++)
      		{
          	  A[i][j] = 1.0;
          	  B[i][j] = 1.0;
      		}
    	    }

	    for(i = 1; i < 2; i++)
    	    {
      		for(j = 1; j < 2; j++)
      		{
                  A[i][j] = 0.0;
          	  B[i][j] = 0.0;
      		}
            }

    	    //initialize fibArray matrix with {{0,0}{0,0}}
    	    for(i = 0; i < 2; i++)
      	        for(j = 0; j < 2; j++)
                    fibArray[i][j] = 0.0;


	    /* Computes the number that's (pow(2,x) + 1) <= nth Fibonacci number
               (where x is a positive integer).                                   */
            int k;

            for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                   for(k = 0; k < 2; k++)
                       fibArray[i][j] += (A[i][k] * B[k][j]);


   	   fibTrackingVariable = 2;

           uint1024_t exponent = 2;

           /* Below while loop computes the # that's (pow(2,x) + 1) <= nth Fibonacci #
              (where x is a positive integer).                                   */
          
	    while(n >  (exponent * 2) - 2)
           {
		//cout<<"\n\nBeginning While Exponent = "<<exponent<<"  fibTrackingVariable = "<<fibTrackingVariable;
                //cout<<"\neCounter1 = "<<eCounter1<<"  eCounter2 = "<<eCounter2<<"  eCounter3 = "<<eCounter3<<"  eCounter4 = "<<eCounter4;
      		eCounter1 *= 2;
      		eCounter2 *= 2;
      		eCounter3 *= 2; 
      		eCounter4 *= 2;
      		for(i = 0; i < 2; i++)
      		{
        		for(j = 0; j < 2; j++) 
        		{
           			A[i][j] = fibArray[i][j];
           			B[i][j] = fibArray[i][j];
        		}
      		}

      		//re-initialize fibArray to {{0,0}{0,0}} 
      		for(i = 0; i < 2; i++)
        		for(j = 0; j < 2; j++)
            			fibArray[i][j] = 0.0;

      		for(i = 0; i < 2; i++)
      		{
        		for(j = 0; j < 2; j++)
        		{
           			for(k = 0; k < 2; k++)
           			{
              				fibArray[i][j] = fibArray[i][j] + (A[i][k] * B[k][j]);

              				if((fibArray[i][j] > UPPER_THRESHOLD) && (k == 1))
              				{
                   				fibArray[i][j] /= UPPER_THRESHOLD;
                   				if((i == 0) && (j == 0))
                      					eCounter1++;
                   				if((i == 0) && (j == 1))
                      					eCounter2++;
                   				if((i == 1) && (j == 0))
                      					eCounter3++;
                   				if((i == 1) && (j == 1))
                      					eCounter4++;
              				}	
           			}
        		}
      		}
    		exponent *= 2;
    		fibTrackingVariable *= 2;
		//cout<<"\nEnding While    Exponent = "<<exponent<<"  fibTrackingVariable = "<<fibTrackingVariable;
		//cout<<"\neCounter1 = "<<eCounter1<<"  eCounter2 = "<<eCounter2<<"  eCounter3 = "<<eCounter3<<"  eCounter4 = "<<eCounter4;
   	   } //end while
           cout<<"\n\nOutside While1\n";
           cout<<"\nOutside While2\n";
           cout<<"\nOutside While3\n";

           cout<<"\nfibTrackingVariable =  "<<fibTrackingVariable;
           fibTrackingVariableMinus = fibTrackingVariable - 1;
           fibTrackingVariablePlus  = fibTrackingVariable + 1;
	   cout<<"\nfibTrackingVariableMinus =  "<<fibTrackingVariableMinus;
	   cout<<"\nfibTrackingVariablePlus  =  "<<fibTrackingVariablePlus;

           cout<<"\neCounter1 = "<<eCounter1<<"  eCounter2 = "<<eCounter2<<"  eCounter3  =  "<<eCounter3<<"  eCounter4 =  "<<eCounter4;
	   //Starts where the matrixSquare() function left off.
   	   uint1024_t eNumber1 = eCounter1 * 2466;
           uint1024_t eNumber2 = eCounter2 * 2466;
           uint1024_t eNumber3 = eCounter3 * 2466;
           uint1024_t eNumber4 = eCounter4 * 2466;
           
   	   if(fibTrackingVariablePlus == n)
   	   {
       		cout<<"\nFIBONACCI # AYT1 "<<n<<" = "<<setprecision(2466)<<fibArray[0][0]
           	     <<" e+"<<eNumber1<<"\n";
           }	

   	   //Note: This is the same value that's stored in fibArray[1][0] 
           else if(fibTrackingVariable == n) 
   	   {
       		cout<<"\nFIBONACCI # AYT2 "<<n<<" = "<<setprecision(2466)<<fibArray[0][1]
                     <<" e+"<<eNumber2<<"\n";
                outFile1.open("FIBONACCIRESULT");
                outFile1<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<fibArray[0][1]
                        <<" e+"<<eNumber2<<"\n";
   	   }	

   	   else if(fibTrackingVariableMinus == n) 
   	   {
       		cout<<"\nFIBONACCI # AYT3 "<<n<<" = "<<setprecision(2466)<<fibArray[1][1]
                     <<" e+"<<eNumber4<<"\n";
   	   } 

   	  else
   	  {
      		unsigned long long i = 0;
      		long double result   = fibArray[0][0];
      		long double previous = fibArray[0][1];
      		long double sum = 0;
		uint1024_t z = 0;

      		if(result > UPPER_THRESHOLD)
      		{
         		result /= UPPER_THRESHOLD;
         		previous /= UPPER_THRESHOLD;
         		eCounter1++;

      		}

      		for (z = fibTrackingVariablePlus+1; z <= n; z++)
      		{
          		if(result > UPPER_THRESHOLD)
          		{
             			result /= UPPER_THRESHOLD;
             			previous /= UPPER_THRESHOLD;
             			eCounter1++;

          		}

          		sum = result + previous;
          		previous = result;
          		result = sum;
      		}


      		//if answer is <= 1e+2466
       		if(eCounter1 == 0)
       		{
          		cout<<"\nFIBONACCI # AYT4 "<<n<<" = "<<setprecision(2466)<<result<<"\n";
       		}		
       		else
       		{
          		eNumber1 = eCounter1 * 2466;
          		cout<<"\nFIBONACCI # AYT5 "<<n<<" = "<<setprecision(2466)<<result<<" e+"
              		    <<eNumber1<<"\n";
       		}
	}//end inner else

    }//end outer else

    
    getTime(&endTimeC, &endTimeW);

    displayTimes(&startTimeC, &endTimeC, &startTimeW, &endTimeW);


    return 0;
}//end main




void getTime(time_t *cpuTime, struct timeb *wallClockTime)
{
  ftime(wallClockTime);

  time(cpuTime);
}

void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}




