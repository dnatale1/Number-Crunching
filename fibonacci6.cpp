/*                             fibonacci6.cpp

   Author: David Natale

   Last edited: May 16, 2011

   This program approximates the nth Fibonacci number entered by the user.

   My computer is powered with an Intel 3.8 GHz CPU.	

   Compiled on GNU C++ running on Ubuntu 10.04.

   To run, on the command line type:

   g++ -O3 fibonacci6.cpp -o proj1main [Enter]
   ./proj1main

   The -O3 option invokes the compiler optimizer.
                                                                            */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/timeb.h>
#include <iomanip>
#include <cfloat>

using namespace std;

//This constant is 1e+4910.
const long double UPPER_THRESHOLD = (LDBL_MAX/1.18973149535723177)/1e+22;

void getTime(time_t *, struct timeb *);
void fibonacci(long long *, long long *, long double *, long double *,
               long double *, long long);
void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

//Global variable used to echo: "FIBONACCI # "<<nthFibNum, at end of program.
long long nthFibNum;

int main()
{
    long long numEntered = 0;
    long long i = 0;
    long double previous = -1.0, result = 1.0, sum = 0.0;
    long long eCounter = 0;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;

    cout<<"\nEnter Nth Fibonacci number: ";
    cin>>numEntered;

    getTime(&startTimeC, &startTimeW);

    nthFibNum = numEntered;

    i = numEntered;

    fibonacci(&numEntered,&i,&previous,&result,&sum,eCounter);

    getTime(&endTimeC, &endTimeW);

    displayTimes(&startTimeC, &endTimeC, &startTimeW, &endTimeW);

    return 0;
}//end main


void getTime(time_t *cpuTime, struct timeb *wallClockTime)
{
   //get wall-clock time
   ftime(wallClockTime);

   //get cpu time
   time(cpuTime);
}


void fibonacci(long long *num, long long *i, long double *previous, 
               long double *result, long double *sum, long long eCounter)
{
    long long eNumber = 0;

    for (*i = 0; *i <= *num; (*i)++)
    {
      if(*result > UPPER_THRESHOLD)
      {
         *result /= UPPER_THRESHOLD;
         *previous /= UPPER_THRESHOLD;
         eCounter++;

      }
         *sum = *result + *previous;
         *previous = *result;
         *result = *sum;
    }

     //if answer is <= 1e+4910
     if(eCounter == 0)
     {
          cout<<"\nFIBONACCI # "<<nthFibNum<<" = "<<setprecision(4910)<<*sum
              <<"\n\n"; 
     }
     else
     {
       eNumber = eCounter * 4910;
       cout<<"\nFIBONACCI # "<<nthFibNum<<" = "<<setprecision(4910)<<*sum
           <<" e+"<<eNumber<<"\n\n";
     }
}


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)
      <<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}



/*                                SAMPLE RUN:


Enter Nth Fibonacci number: 1000000000000000

FIBONACCI # 1000000000000000 = 242261486293719904438234950905905808666468164242907374530723670149685542242862503193625350794462618157567736994617627390607277607236501657885808156973799804792904865985305907475823501699461410960672512307976452897441357441533510866450434165975849197202924761722531598788404514494225258799621283410702657176837738342505281673333516839529278067075013595068132013325171658321204345454384078871021044864647902770590685118367535848781886530754184237076962319815318900199148890846065661650201307574862272002362845970610199703196034420683104728808934775607020792008443864784291511931220762934344973174159486356227161323219902309070510298671205623793560837342187010747784830377442702007139831666324641997852207951170146360936898705544399532974409798703991533948166842330642515448252270176825093598370307041566615762830224930028376936005011105505793408305427547197070529649869001209018058735851131368156471253385313678214069496786898955184828458750107169695198441910276658393772145498733984198935886412330547299134206681325311505164673206910649217830193373698770366779649530541787180765835836671955980412438941031475173963945122317808475527714109998079705518121107869728861197516425634604325050008037783333662459619368491701859399794638548488347007003200390939760862107552633853762281095471348569625811038570054857148682197628667504635647154948429083256687835954719007543663511068256209240066903427506103531952671797325263288546977851320739373689864428443140160706584018900575060252367856620180557150701694146788205527330933996723988741007359297377142402789245701103562590321656852589395248563403027896276879416078863037372185809189339136 e+208987640248350


Wall-clock time = 1572467 seconds
CPU time = 1572467 seconds
                                                                                               */

