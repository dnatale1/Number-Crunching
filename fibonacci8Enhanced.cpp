
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: June 2023

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

(Note:  This is 2 ^ 404)


FIBONACCI # 41315998049390537434494706752048189989275292685267576205290549704650361952269459114074325652482205302974450751563959894016 = 93289925499471187856315834769129731009400672545182676562313104099160423681632702447619398890763130882270107346271429159659656023316316560310742535173173723995112782823203474657670695706555931254058933529292060851210252646972884355880065567225490706825197453901254964140201240977641993067504739233940113909042136427519792403419272574971258093342026307775343670666550862869396933350768431213193398985795718691405132021635526049325944546074619815057012012911160449852052672883268198771478516002721801710984622868821715913963525053557907012692831146047155277805256518257260843045749567767611015764901951268773316876435388273702948357143356925030850511166052344070384202943441524164752649121428864350447873934905568595854012603992092166150193167066418091977717662532430013723128873853803650208503015900964148962259542322583717307356353958221885489568438691506122374237401721229548191362073515876195358561516637604013638169505796583149839713035707281620936203286911920627451955714085299999691370826039744990496571860351669737573223773589263353577713268452631719079231689568276757063554454100275157845574497788100817323075408726000994937893933147195670618990287163434965641751426881825049488177386326892939082805402670327768493447891153750673945468297869008317324761154702294121274284528100563478775025261915094707081827737277297622938996418556585840398626958306779621617467268263875411419157875649053112093742376636126169253109062191040791068748075613611219702054511868093996446155389025573827156327884765714994025289744890103789321419998920661284917019930914666819848690865585363688816091183280841075988120437319935229123571956221059961694451087913573435305327519070025060237262411306070567357409358415659008 e+8634532936914852733710522498621393466676824554331386059099775090798027523051184596710143268922473033883672085315665819866


Wall-clock time = 0 seconds
CPU time = 0 seconds

*/
