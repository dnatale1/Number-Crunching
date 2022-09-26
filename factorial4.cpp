
/*                           factorial4.cpp

   Author: David Natale

   Last edited: May 24, 2011

   This program approximates factorials faster than my factorial2.cpp and
   factorial3.cpp programs using Stirling's formula. The higher the 
   factorial, the more accurate the approximation is to the actual value.

   Stirling's formula: n! ~ sqrt(2*pi*n) * pow(n/e, n)

   The code below is very similar to that of my exponent2.cpp program.
   In cases where n is a base 10, 5, 3, 2, 1.5, 1.25 number, the factorial is
   computed instantaneously. In these cases where n is a very large number,
   the increase in computation speed is very impressive. For example, it took
   26 days to approximate 2 quadrillion! running my factorial3.cpp program,
   whereas it took a fraction of a second with this program! The results
   were 89% identical to each other. 

   My computer is powered with an Intel 3.8 GHz CPU.

   Compiled on GNU C++ running on Ubuntu 10.04.

   To run, on the command line type: 

   g++ -O3 factorial4.cpp -o proj1main [Enter]
   ./proj1main

   The -O3 option invokes the compiler optimizer.

   NOTE: This program approximates factorials that are powers of 10 from
         1 thru 1e+29.                                                    */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/timeb.h>
#include <ctime>
#include <cmath>
#include <cfloat>
#include <string.h>

using namespace std;

//18 digits are used for the two constants below, because this is the maximum
//number of significant digits used in the sqrt() function.
const long double PI = 3.1415926535897932;
const long double E  = 2.7182818284590452;


/* The rationale for using the constants below are as follows: the maximum
   value of a long double (LDBL_MAX) is around 1.18e+4932. When the
   base is multiplied repeatedly, the result is checked to ensure LDBL_MAX 
   is not exceeded. Each function uses one of these constants such that the 
   base will be <= 1e+4920.                                                  */

//This constant is 1e+2460.
const long double UPPER_THRESHOLD = 
(((((((((LDBL_MAX/1.18973149535723177)/1e+308)/1e+308)/1e+308)/1e+308)
/1e+308)/1e+308)/1e+308)/1e+308)/1e+8;

//This constant is 1e+1640.
const long double ONE_E_PLUS_1640 = ((UPPER_THRESHOLD/1e+308)/1e+308)/1e+204;

//This constant is 1e+984.
const long double ONE_E_PLUS_984 = ((ONE_E_PLUS_1640/1e+308)/1e+308)/1e+40;

//This constant is 1e+492.
const long double ONE_E_PLUS_492 = (ONE_E_PLUS_984/1e+308)/1e+184;

void getTime(time_t *, struct timeb *);

void baseToTheTenth(long double *counter, long double *exponent,
                    long double *base, long double *eCounter,
                    long double *eNumber);

void baseToTheFifth(long double *counter, long double *exponent,
                    long double *base, long double *eCounter,
                    long double *eNumber);

void baseCubed(long double *counter, long double *exponent,
               long double *base, long double *eCounter,
               long double *eNumber);

void baseSquared(long double *counter, long double *exponent,
                 long double *base, long double *eCounter,
                 long double *eNumber);

void baseToOnePointFivePower(long double *counter, long double *exponent,
                             long double *base, long double *sqbase,
                             long double *eCounter, long double *eNumber);

void baseToOnePointTwoFivePower(long double *counter, long double *exponent,
                                long double *base, long double *sqbase,
                                long double *eCounter, long double *eNumber);

void counterLessThanExponent(long double *counter, long double *exponent,
                             long double *base, long double *originalBase,
                             long double *eCounter, long double *eNumber);

void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);

int main()
{
    
     long double n = 0;

     long double counter = 1;

     //Variable to keep track of the # of "e+(number)"s in the calculation.
     long double eCounter = 0;

     //Variable to calculate the correct "e+(number)".
     long double eNumber = 0;

     struct timeb  startTimeW, endTimeW;
     time_t startTimeC, endTimeC;

     cout<<"\nENTER NUMBER: ";
     cin>>n;

     getTime(&startTimeC, &startTimeW);

     //Computes left half of Stirling's formula.
     long double leftHalf = sqrt(2 *PI*n);

   /* In Stirling's formula, the number whose factorial is to be determined,
      n, is also the base in the formula. */
     long double base = n;

   /* In Stirling's formula, the number whose factorial is to be determined,
      n, is also the exponent in the formula. */
     long double exponent = n;

     base = base / E;

     //Used in the counterLessThanExponent() function.
     long double originalBase = base;

    baseToTheTenth(&counter,&exponent,&base,&eCounter,&eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    baseToTheFifth(&counter,&exponent,&base,&eCounter,&eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    baseCubed(&counter,&exponent,&base,&eCounter,&eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    baseSquared(&counter,&exponent,&base,&eCounter,&eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    /* Variable used in the baseToOnePointFivePower() and
       baseToOnePointTwoFivePower() functions to calculate:
       (*base ^ 1.5) and (*base ^ 1.25), respectively.      */
    long double sqbase = 0;

    baseToOnePointFivePower(&counter,&exponent,&base,&sqbase,&eCounter,
                            &eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    baseToOnePointTwoFivePower(&counter,&exponent,&base,&sqbase,&eCounter,
                               &eNumber);

    //Reset eCounter to correctly calculate eNumber for the next function.
    eCounter = 0;

    counterLessThanExponent(&counter,&exponent,&base,&originalBase,&eCounter,
                            &eNumber);

    //Multiplying left half of Stirling's formula by the right half.
    base = base * leftHalf;

    if(base > UPPER_THRESHOLD)
    {
       base /= UPPER_THRESHOLD;
       eCounter++;
    }

    // 0! = 1
    if(n == 0)
    {
       cout<<"\n\n\n0! = 1\n\n\n";
    }
    else if(eNumber > 0)
    {
           cout<<"\n\n"<<setprecision(2460)<<base<<"  e+"<<eNumber<<"\n\n";
    }
    else
          cout<<"\n\n"<<setprecision(2460)<<base<<"\n\n";

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


void baseToTheTenth(long double *counter, long double *exponent,
                    long double *base, long double *eCounter,
                    long double *eNumber)
{
        while (*counter <=  (*exponent/10))
        {
          *base = *base * *base * *base * *base * *base *
                  *base * *base * *base * *base * *base;
          *eCounter *= 10;
          while(*base > ONE_E_PLUS_492)
          {
                 *base /= ONE_E_PLUS_492;
                 (*eCounter)++;
          }
          *counter *= 10;
        } //end while

        *eNumber = *eCounter * 492;
}


void baseToTheFifth(long double *counter, long double *exponent,
                    long double *base, long double *eCounter,
                    long double *eNumber)
{
        while (*counter <=  (*exponent/5))
        {
          *base = *base * *base * *base * *base * *base;
          *eCounter *= 5;
          while(*base > ONE_E_PLUS_984)



          {
              *base /= ONE_E_PLUS_984;
              (*eCounter)++;
          }
          *counter *= 5;
          *eNumber *= 5;
        }
        *eNumber = *eNumber + (*eCounter * 984);
}


void baseCubed(long double *counter, long double *exponent,
               long double *base, long double *eCounter,
               long double *eNumber)
{
        while (*counter <= (*exponent/3))
        {
          *base = *base * *base * *base;
          *eCounter *= 3;
          while(*base > ONE_E_PLUS_1640)
          {
                 *base /= ONE_E_PLUS_1640;
                 (*eCounter)++;
          }
          *counter *= 3;
          *eNumber *= 3;
        }
        *eNumber = *eNumber + (*eCounter * 1640);
}


void baseSquared(long double *counter, long double *exponent,
                 long double *base, long double *eCounter,
                 long double *eNumber)
{
        while (*counter <= (*exponent/2))
        {
          *base *= *base;
          *eCounter *= 2;
          while(*base > UPPER_THRESHOLD)
          {
              *base /= UPPER_THRESHOLD;
              (*eCounter)++;
          }
          *counter *= 2;
          *eNumber *= 2;
        } 
       *eNumber = *eNumber + (*eCounter * 2460);
}


void baseToOnePointFivePower(long double *counter, long double *exponent,
                             long double *base, long double *sqbase,
                             long double *eCounter, long double *eNumber)
{
        while (*counter <= (*exponent/1.5))
        {
          //The next two lines of code compute: *base = *base ^ 1.5;
          *sqbase = sqrt(*base);
          *base = *base * *sqbase;

          *eCounter *= 1.5;
          if(*base > 1e+308)
          {
              *base /= 1e+308;
              (*eCounter)++;
          }
          *counter *= 1.5;
          *eNumber *= 1.5;
        }
       *eNumber = *eNumber + (*eCounter * 308);
}


void baseToOnePointTwoFivePower(long double *counter, long double *exponent,
                                long double *base, long double *sqbase,
                                long double *eCounter, long double *eNumber)
{
        *sqbase = sqrt(*base);

        while(*base > ONE_E_PLUS_492)
        {
            *base /= ONE_E_PLUS_492;
            (*eCounter)++;
        }

        while (*counter <= (*exponent/1.25))
        {
            //The next several lines of code compute: *base = *base ^ 1.25;   
            *base = *base * *base * *base * *base * *base;
            *eCounter *= 1.25;
            while(*base > ONE_E_PLUS_492)
            {
                *base /= ONE_E_PLUS_492;
                (*eCounter)++;
            }
            *counter *= 1.25;
            *eNumber *= 1.25;
            *sqbase = sqrt(*base);
            *base = sqrt(*sqbase);
        }//end outer while

       *eNumber = *eNumber + (*eCounter * 492);
}


void counterLessThanExponent(long double *counter, long double *exponent,
                             long double *base, long double *originalBase,
                             long double *eCounter, long double *eNumber)
{
        while(*base > 1e+200)
        {
            *base /= 1e+200;
            (*eCounter)++;
        }

        while(*counter < (*exponent - 146))
        {
            *base *= ((*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase) *
                      (*originalBase) * (*originalBase) * (*originalBase));
            while(*base > 1e+200)
            {
                *base /= 1e+200;
                (*eCounter)++;
            }
            *counter += 147;
        }

        while(*counter < *exponent)
        {
          *base *= (*originalBase);
          if(*base > 1e+200)
          {
             *base /= 1e+200;
             (*eCounter)++;
          }
          (*counter)++;
        }

       *eNumber = *eNumber + (*eCounter * 200);
}


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"Wall-clock time = "<<(endWall->time - startWall->time)
      <<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}


/*                             SAMPLE RUNS:

ENTER NUMBER: 2000000000000000


6851249764485957389421054801016276955721749436286130058557262559742176432515731372584214427362575088875012018271816261144370676200417843202510018394243558426388686621208745303840152770099161325371392  e+29733471027521268

Wall-clock time = 0 seconds
CPU time = 0 seconds
_____________________________________________________________________

ENTER NUMBER: 1e+29


4668496512160873.7978515625  e+2856570551809674820095248957440

Wall-clock time = 0 seconds
CPU time = 0 seconds                                                     
										*/

