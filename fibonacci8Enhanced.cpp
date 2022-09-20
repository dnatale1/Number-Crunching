
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: September 2022

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n - 1, 2^n or 2^n + 1, the computation
         is performed instantaneously.

   I used Boost 1.75.0 and Intel compiler 19.0.5.   

   Compiled with: icpc -fma -pc80 -axSSE4.2 -O3 fibonacci8Enhanced.cpp -o pFibo8 -lboost_regex
                  ./pFibo8
                                                                                               */

#include <iostream>
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
    int128_t           n = 0;
    int128_t           eCounter1 = 0;
    int128_t           eCounter2 = 0;
    int128_t           eCounter3 = 0;
    int128_t           eCounter4 = 0;

    int128_t           fibTrackingVariable = 0;
    int128_t           fibTrackingVariableMinus = 0;
    int128_t           fibTrackingVariablePlus = 0;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;

    //Fibonacci number to be approximated.
    n = 295147905179352825855;
  
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

           int128_t exponent = 2;

           /* Below while loop computes the # that's (pow(2,x) + 1) <= nth Fibonacci #
              (where x is a positive integer).                                   */
          
	    while(n >  (exponent * 2) - 2)
	  // while(n > (pow(2.0,exponent) - 2))
           {
		cout<<"\n\nBeginning While Exponent = "<<exponent<<"  fibTrackingVariable = "<<fibTrackingVariable;
                cout<<"\neCounter1 = "<<eCounter1<<"  eCounter2 = "<<eCounter2<<"  eCounter3 = "<<eCounter3<<"  eCounter4 = "<<eCounter4;
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
		cout<<"\nEnding While    Exponent = "<<exponent<<"  fibTrackingVariable = "<<fibTrackingVariable;
		cout<<"\neCounter1 = "<<eCounter1<<"  eCounter2 = "<<eCounter2<<"  eCounter3 = "<<eCounter3<<"  eCounter4 = "<<eCounter4;
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
   	   int128_t eNumber1 = eCounter1 * 2466;
           int128_t eNumber2 = eCounter2 * 2466;
           int128_t eNumber3 = eCounter3 * 2466;
           int128_t eNumber4 = eCounter4 * 2466;
           
   	   if(fibTrackingVariablePlus == n)
   	   {
       		cout<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<fibArray[0][0]
           	     <<" e+"<<eNumber1<<"\n";
           }	

   	   //Note: This is the same value that's stored in fibArray[1][0] 
           else if(fibTrackingVariable == n) 
   	   {
       		cout<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<fibArray[0][1]
                     <<" e+"<<eNumber2<<"\n";
   	   }	

   	   else if(fibTrackingVariableMinus == n) 
   	   {
       		cout<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<fibArray[1][1]
                     <<" e+"<<eNumber4<<"\n";
   	   } 

   	  else
   	  {
      		unsigned long long i = 0;
      		long double result   = fibArray[0][0];
      		long double previous = fibArray[0][1];
      		long double sum = 0;
		int128_t z = 0;

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
          		cout<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<result<<"\n";
       		}		
       		else
       		{
          		eNumber1 = eCounter1 * 2466;
          		cout<<"\nFIBONACCI # "<<n<<" = "<<setprecision(2466)<<result<<" e+"
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



/*                               SAMPLE RUN:

(Note:  This is 2 ^ 70 - 1)


FIBONACCI # 1180591620717411303423 = 99462073072777424683175587269390254453046561360119147340051096117664564598460916529933677516310218847068351003698424015896360519215118634458237359210956456052393033989124661587872053291098349034845175915588787906553555625824858547496816910946413509936225722257533593057207255103048136057964712512315521395644641550345840481513759465466733104155491598579879570844395773423180623919865374953802795596084924477655506149739102214730882939716219091429013152208922111296878611910606734901091999399106760260474659849074014764062851306734412232967851711577139853893873667609729828429548607466205840117445231158398616664863020396232977795171904883891494068149796921535249374420676268179524798408351735603173082661733417387759880205599285078201518154038297557396638538251581411489921065235806586251497874748170032389213048261896388858343152521142008603213297739853883318819859143555143938918861646463840239103178958700544 e+246729056912629692750


Wall-clock time = 0 seconds
CPU time = 0 seconds

                                                                          */




