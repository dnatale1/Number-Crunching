
/*                      factorial2.cpp

   Author: David Galilei Natale

   Last edited: November 2023

   Ran program on the Intel Developer Cloud.

   Used Intel C++ compiler 2021.10.0.

   Running on Intel's i9-11900K CPU at 3.5 GHz, this program can            
   approximate 46 billion! in 47 seconds. This is a 5411-fold increase in 
   speed compared to a similar program I ran on a VAX computer back in 1992.

   Compiled with:
   icpc -O3 factorial2.cpp -o proj2main [Enter]
   ./proj2main
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
void factorial(long long);
void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

int main()
{
      long long num = 0;
      struct timeb  startTimeW, endTimeW;
      time_t startTimeC, endTimeC;

      cout<<"\nENTER A WHOLE NUMBER: ";
      cin>>num;

      getTime(&startTimeC, &startTimeW);

      factorial(num);

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

void factorial(long long n)
{

  long long x = 1;
  long double y = 1;

  //variable to keep track of the # of "e+4900"s in the factorial calculation
  long long eCounter = 0;

  /* Variable to calculate the correct "e+(number)" for answers greater than
     10 to the 4900th power. */
  long long eNumber = 0;

  for(x = 1; x <= n; x++)
  {
    y *= x;
    if(y > UPPER_THRESHOLD)
    {
      y /= UPPER_THRESHOLD;
      eCounter++;
    }
  }

   //if answer is <= 10 to the 4900th power
   if(eCounter == 0)
       cout<<"\n"<<setprecision(4900)<<n<<"! = "<<y<<endl;
   else
   {
       eNumber = eCounter * 4900;
       cout<<"\n"<<setprecision(4900)<<n<<"! = "<<y<<" e+"
           <<eNumber<<endl;
   }

}

void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall, 
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}


/*                               SAMPLE RUN:


20000000000000! = 43346849690774600700777061002835876204756134541177212653979201225927309357609479500733146576162811496488503539120301979383250835033525494581723601166693996068103911390710451090142169643744721562330051396969517282770318684596104491057583142632189504141226108705183125339599268621592463491359300780647575392495077320606250922853957580263620853995954410376809148123619517082542781766563042463982044719683973543621117572895447752800170929852550154054875796181500574550409393398767826343000045710632928644117382269355717797757506783666484863580573688980680555206502850815524666774668148964044539325780943254334581276245879312205103509886779944327175022798729330440142891028345262174632891831180909222503954391599581579486144878519833077604540597855839311502842054814319779425042767554566788038091431692156756836316042774288505803879959488946937787651712646461530438160053677897062174491849610525016934401746107145385427248229374566767459685040558701414321374962553875476161821549286873047375889716359730953279298635801660755233986751260802709945561249413449550727763468874211891107330988490443102961539272036407676608426848726523516006030263476038317685323812921195519971115289342279910863557929442017913783847262779188672942224943360209023173588030284582046128869964372912554063752560457198307871935065744682842174977516503040 e+257334710273900


Wall-clock time = 20465 seconds
CPU time = 20465 seconds

*/
