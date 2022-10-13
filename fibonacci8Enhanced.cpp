
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: October 2022

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n - 1, 2^n or 2^n + 1, the computation
         is performed instantaneously.

   I used Intel compiler 19.0.5 and Boost 1.75.0.   

   Compiled with:

   icpc -fma -pc80 -axSSE4.2 -O3 fibonacci8Enhanced.cpp -o pFibo8 -lboost_regex
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
    n = 309485009821345068724781055;
  
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


	    /* Computes the number that's (pow(2,x) + 1) <= nth Fibonacci number
               (where x is a positive integer).                              */
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

(Note:  This is 2 ^ 88 - 1)


FIBONACCI # 309485009821345068724781055 = 420142355175177343983405658648215739517719383665608816574278173875922414719525525417672578336769817317521439211597313584027880262954855254338941729856706816273906707264205400423808468010154563215772846211091095420846272042189065939650639953842374465530185757584527176989147788012235599425722339427021415938478890476109583046505679612509018945756428511303607677861934682803299865052790861027270556651469365194903005434304922095339942344572469338197939318339918540422339349431043100225171595539118296123953250307396425542962535772319223438531843675469660880559567654324154683270109618960219309358421989600258574911085510469816919380218979729588182656832332441711717468118361860525245399088456011120333974170377949900493796592368813344274214601814975464478380850025551419411481290335004960198430042286946246445005448825556196914609099013624197042815798120117204093082220166671260187706379807145754312386128277824869033726630761134149495336510735190197049367583651092065343311397044786307903242465713122372280207338426077351558516659053762932563528476091814877934831079142165734468986600332099766615969628160 e+64678541895304398415213866


Wall-clock time = 0 seconds
CPU time = 0 seconds

*/




