
/*                        fibonacci8Enhanced.cpp

   Author: David Galilei Natale

   Last edited: January 2023

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n the computation
         is performed instantaneously.

   I used Boost 1.72 and GNU compiler 9.1.0.
 
   Compiled with: g++ -O3 fibonacci8Enhanced.cpp -o projFibo8 -lboost_regex
                  ./projFibo8

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

(Note:  This is 2 ^ 300)


FIBONACCI # 2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376 = 4097010772001509747442812525794094537557490996025267814310664204033134647976638820350986166357304082724743953643676252145414513604997081876155472200125445701311099306661501031767761094454634273612038319720711258446839678008073461831872337500370221922572152305587322878511549382261407882981509109742871557406104515949582492824819448841551696494610041511677750624753142401683335108963652144900399738569821689889323111633429637190196365185451078092909367605915344212920985386965004129462634993288553004028346261811335197616517995839578533002847245325172191360144909251006839776084921395085611758186212884108256880818484510468981013099569467926276283808626664445788344539671427387755895624641875139810692308351606282205235597571166334249215572324194516207592534094208805278517280635659203812131380846818143301542521763208442880053363354045651023172926158570215529267434540044896410755986234181112719965034578362395553914803379657067229059134038209832305099512501281692064928732654903422674214816721653941973668805660180516348094844947450628770967514874445919789629576738580282275248089271204458791762857624189151956129003404971445926505045247254533884575238890666349524752467815103179747165840794688714069163671741271547606347888326979214446862120613265947642871772597322796664696709382452497160330897821966641955255036696968104506044958735088934563471140784164474254922465373254764310282670862746942162514653637165599234126306862925484031128403933608909156026031826151336394565405458582331912251237308613128874826112258768482774811631485806812289945051055193017700392700614680339028746406581383548564637914522251542673655412096734282886080208796286580988870349445481509392666310282581692931596216254889088753854477115217777608148764750526148760579477978398518057602385709957348884423237714073244727587004028668948640535530276982554051074115250110773328817211066096199819583589833037763465911056729758577831429422332538300423648331691721622345981324083456125808521568208897559341220878188686791345444862614506229271421039631652653911314968275145023602625169229639666058708401148515702672877564592237051904 e+425715341798455771795699586142174717803338820740460156326788863883537709927608299296791210


Wall-clock time = 0 seconds
CPU time = 0 seconds

*/
