
/*                           exponent1.cpp

   Author: David Galilei Natale

    May 2023

   This program computes X to the Yth power.
   The program prompts the user to enter a base (X) and an exponent (Y). 

   I used Intel compiler 2021.5.0.

   Compiled with: icpc -fma -pc80 -axSSE4.2 -O3 exponent1.cpp -o pExp1
                  ./pExp1                  
                                                                         */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/timeb.h>
#include <ctime>
#include <climits>
#include <cfloat>

using namespace std;

//This constant is 1e+2450.
const long double UPPER_THRESHOLD = (((((((((LDBL_MAX/1.18973149535723177)/
1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+18;


void getTime(time_t *, struct timeb *);

void counterLessThanOrEqualExponentDivBy2(unsigned long long *counter, 
                                          unsigned long long *exponent,
                                          long double *base,
                                          unsigned long long *eCounter,
                                          unsigned long long *i);

void counterLessThanExponent(unsigned long long  *counter, 
                             unsigned long long *exponent,
                             long double *base, long double  *originalBase,
                             unsigned long long *eCounter);

void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

int main()
{

     long double  base = 1;
     unsigned long long exponent = 1;

     unsigned long long i = 1,  counter = 1;

     //variable to keep track of the # of "e+2450"s in the calculation
     unsigned long long eCounter = 0;

     /* variable to calculate the correct "e+(number)" 
        for answers greater than 10 to the 2450th power  */
     unsigned long long eNumber = 0;

     struct timeb  startTimeW, endTimeW;
     time_t startTimeC, endTimeC;

     cout<<"\nENTER BASE THAT IS A POSITIVE OR NEGATIVE INTEGER: ";
     cin>>base;

     cout<<"\nENTER EXPONENT THAT IS A POSITIVE INTEGER: ";
     cin>>exponent;
     
     getTime(&startTimeC, &startTimeW);

     long double originalBase = base;


     counterLessThanOrEqualExponentDivBy2(&counter,&exponent,&base,&eCounter,
                                          &i);

     counterLessThanExponent(&counter,&exponent,&base,&originalBase,&eCounter);

     if(eCounter >= 1)
     {
           eNumber = eCounter * 2450;
           cout<<"\nANSWER: "<<base<<"   e+"<<eNumber<<"\n";
     }
     else
           cout<<"\nANSWER: "<<base<<"\n";

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


void counterLessThanOrEqualExponentDivBy2(unsigned long long  *counter, 
                                          unsigned long long *exponent,
                                          long double *base, 
                                          unsigned long long *eCounter, 
                                          unsigned long long *i)
{
        while (*counter <= (*exponent/2))
        {
          *base *= *base;
          if(*eCounter >= 1)
             *eCounter *= 2;
          if(*base > UPPER_THRESHOLD)
          {
              *base /= UPPER_THRESHOLD;
              (*eCounter)++;
          }
          *counter += *i;
          *i *= 2;
        }
}


void counterLessThanExponent(unsigned long long *counter, 
                             unsigned long long *exponent,
                             long double *base, long double  *originalBase,
                             unsigned long long *eCounter)
{
        while(*counter < *exponent)
        {
          *base *= *originalBase;
          if(*base > UPPER_THRESHOLD)
          {
              *base /= UPPER_THRESHOLD;
              (*eCounter)++;
          }
          (*counter)++;
        }
}


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}

