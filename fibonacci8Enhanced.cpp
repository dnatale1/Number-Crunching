
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: October 2023

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n the computation
         is performed instantaneously.

   I used Intel compiler 19.0.5 and Boost 1.72.0.
 
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
    uint1024_t           n = 0;
    uint1024_t           eCounter1 = 0;
    uint1024_t           eCounter2 = 0;
    uint1024_t           eCounter3 = 0;
    uint1024_t           eCounter4 = 0;

    uint1024_t           fibTrackingVariable = 0;
    uint1024_t           fibTrackingVariableMinus = 0;
    uint1024_t           fibTrackingVariablePlus = 0;

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

           uint1024_t exponent = 2;

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
   	   uint1024_t eNumber1 = eCounter1 * 2466;
       	   uint1024_t eNumber2 = eCounter2 * 2466;
           uint1024_t eNumber3 = eCounter3 * 2466;
           uint1024_t eNumber4 = eCounter4 * 2466;
           
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

(Note:  This is 2 ^ 584)


FIBONACCI # 63316582777114760719488645381029680648993625369910231018000142359781689627272157995600998671678219517337003885060131670873949448782528309751691815706084650986651333670066978816 = 31567438531583639418010797650453623084159742042259135240062453749810670120996283500434206525926717115424453863764867369519519439456428451220460046796110171302611113539581010796062163754873410449909826427649142990847366687937562184987935479495838111475889366406954272394356312944044545310602454283053475948219181053730625598494180157359361266345958048647369857157553281958046738610662605994552384854745619497546103243522421283459884093038387803761393423263447737125026592166204734754076333334121207962006763591124178110635072011219192969732976524269683273450423333625618135302025959279827125715063477199320855573704642094488765906860489681850863885742497843196119518308352443412652146642150631691538998095109860544398646364058217811776143364245367539777607811937020482010623784979233029425238062456163408163402658303856274204106545888625024415260295850368975176531728558498558950752115743627812500085429579377043147857420323472430699900386900456492637924943945176178215431905679870653044959445895142414295866144844703518828901679191546295333550603918423456156449160270021300719117091380163625160689998209212844447268721903991081208062580236926087479199755864975911515550198102475613042195270913745720319173989204727023212023247202363324258405284787319060228966024254919733251726727014451144976339373515274509633021605447186018206813140520605818156935243770575643140492153872154982457578141364733159398092863101561422923997308163739842179009081970384068192723927168090415558616073776497526054063993857049873476881317607988925875561875056497315982007573650179604058006129127194527234181368771009111636899074083567943158340746267184392542946719221734338488353414082738787214218883451432753415259547313736268041893638849129281937571749151651829939438211945490300324518950530543323641948582442334071775302648843966116214003234534900905799520655031602354410793674566234320734092187470145915384548904064993333935705319472848172816445802126146996469039061838975611392919623574053075172779909454192636611261810273493692036962926422010816970163419910056511823992547589066825608219680105162065645005682365092162635206406854730338584705929247063650027015636298723965213472831748575905892998496387072 e+13232383223281659041370930465812589691126731014923823033833294678652128060996677919848448852304323002025899597215841466398894259817888302304482135475249386672433259575241921588


Wall-clock time = 0 seconds
CPU time = 0 seconds

*/
