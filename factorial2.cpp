
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


8000000000000! = 2424930934893139210358592153986655399563668602902270607480132209381834767694556271310729748359599960293482505486895812648874420506871596120226345162714082826541471863561334775326063522140956997379292776863558592424282626829237679179257095200051976120083183478766450381757550852403504112657813611800692462889651108801376916701041727643093799983000341970884253660888453479105554015872942855932396290318608130564141544389770788164876553170742178929391099539880466383989969203701868979346631196925614049828529189902428193550739652766915260732437145961894198161565389889774688283562647778596412410182089850080764562037925913480461403792683803442225444089804145173588333329355553454194635446839221599192235085126702762131316988736039467354301193317512097079631455710549198546414994165406811379855307090547312942807936663552 e+99750364039900


Wall-clock time = 8181 seconds
CPU time = 8181 seconds

*/
