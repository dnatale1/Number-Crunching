
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: July 2023

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n the computation
         is performed instantaneously.

   I used Intel compiler 19.0.5 and Boost 1.72.0.
 
   Compiled with: 
   icpc -fma -pc80 -axSSE4.2 -O3 fibonacci8Enhanced.cpp -o Fibo8 -lboost_regex
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
    uint512_t           n = 0;
    uint512_t           eCounter1 = 0;
    uint512_t           eCounter2 = 0;
    uint512_t           eCounter3 = 0;
    uint512_t           eCounter4 = 0;

    uint512_t           fibTrackingVariable = 0;
    uint512_t           fibTrackingVariableMinus = 0;
    uint512_t           fibTrackingVariablePlus = 0;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;

    cout<<"\nEnter Nth Fibonacci number: ";
    cin>>n;
  
    getTime(&startTimeC, &startTimeW);

    if((n == 1) || (n == 2))
       cout<<"\n\nFIBONACCI # "<<n<<" = "<<"1"<<"\n\n\n";
    else
    {
           /* First, initialize A and B matrices with {{1,1}{1,0}}.
              Then, initialize fibArray matrix with {{0,0}{0,0}}.    */
            int i, j;

	   /* The 3 nested for loops below initialize A and B matrices 
              with {{1,1}{1,0}}. */
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


	    // Computes the number that's (pow(2,x) + 1) <= nth Fibonacci number
           
            int k;

            for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                   for(k = 0; k < 2; k++)
                       fibArray[i][j] += (A[i][k] * B[k][j]);


   	   fibTrackingVariable = 2;

           uint512_t exponent = 2;

        // Below while loop computes the # that's (pow(2,x) + 1) <= nth Fibonacci #
                                                  
	    while(n >  (exponent * 2) - 2)
            {
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

      		//Re-initialize fibArray to {{0,0}{0,0}} 
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
   	   } //end while
           

           fibTrackingVariableMinus = fibTrackingVariable - 1;
           fibTrackingVariablePlus  = fibTrackingVariable + 1;
	   
	   //Starts where the matrixSquare() function left off.
   	   uint512_t eNumber1 = eCounter1 * 2466;
       	   uint512_t eNumber2 = eCounter2 * 2466;
           uint512_t eNumber3 = eCounter3 * 2466;
           uint512_t eNumber4 = eCounter4 * 2466;
           
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
		uint512_t z = 0;

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

(Note:  This is 2 ^ 511)


FIBONACCI # 6703903964971298549787012499102923063739682910296196688861780721860882015036773488400937149083451713845015929093243025426876941405973284973216824503042048 = 408521171595221500875830479247149244295674725651291181857819517622637646719994713288903274928661501064116970976488626815612804439256174348836862735954425474677177755558059604117377522607621034378203879371836737211699544453476283294535929560108076428746453218200062519122964738580000565460279029739041870302528338941392710404553630049851410034660245772083748395717791567980884181236143281782944987420109230908163808136482139321747346835907199117015385876249320918583794752039047407300251295576148352883675531365650434956635088896488108264576946690583846742504218377661269180042097540895902252803355227138696002102798284075355903512892221271718811801330473933482936610941549528158886528974193516132630619234630210548391274199518384982843090780346390585673746556451785207374116712688039236354039470635955884203744518568287873162578024948837559078197416421753152313818077780053397541780074876086195914616029695023755695791946095452330526057484663365696487424 e+1401033070101827776153015281382288410539949222943089912475224697384044602457047203698933556006516477526607515028679842994534306090137676860734633154633174


Wall-clock time = 0 seconds
CPU time = 0 seconds

*/
