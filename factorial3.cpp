/*                              factorial3.cpp

   Author: David Natale

   Last edited: May 24, 2011

   This program approximates factorials significantly faster
   than my factorial2.cpp program.

   My computer is powered with an Intel 3.8 GHz CPU.

   Compiled on GNU C++ running on Ubuntu 10.04.

   To run, on the command line type:

   g++ -O3 factorial3.cpp -o proj1main [Enter]
   ./proj1main

   The -O3 option invokes the compiler optimizer.
                                                                            */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/timeb.h>
#include <ctime>
#include <climits>
#include <cfloat>

using namespace std;

//This constant is 1e+2776.
const long double UPPER_THRESHOLD = ((((((LDBL_MAX/1.18973149535723177)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)
/1e+308/1e+308;


void getTime(time_t *, struct timeb *);
void oneHundredTwentyFiveModFactorial(long double &n, long double &y, 
                                      long double &x, double &eCounter);
void oneHundredTwentyFourModFactorial(long double &n, long double &y, 
                                      long double &x, double &eCounter);
void oneHundredTwentyThreeModFactorial(long double &n, long double &y, 
                                       long double &x, double &eCounter);
void oneHundredTwentyTwoModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter);
void oneHundredTwentyOneModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter);
void oneHundredTwentyModFactorial(long double &n, long double &y, 
                                  long double &x, double &eCounter);
void oneHundredNineteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter);
void oneHundredEighteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter);
void oneHundredSeventeenModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter);
void oneHundredSixteenModFactorial(long double &n, long double &y, 
                                   long double &x, double &eCounter);
void oneHundredFifteenModFactorial(long double &n, long double &y, 
                                   long double &x, double &eCounter);
void oneHundredFourteenModFactorial(long double &n, long double &y,
                                    long double &x, double &eCounter);
void oneHundredThirteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter);
void oneHundredTwelveModFactorial(long double &n, long double &y,
                                  long double &x, double &eCounter);
void oneHundredElevenModFactorial(long double &n, long double &y, 
                                  long double &x, double &eCounter);
void oneHundredTenModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter);
void oneHundredNineModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter);
void oneHundredEightModFactorial(long double &n, long double &y, 
                                 long double &x, double &eCounter);
void oneHundredSevenModFactorial(long double &n, long double &y,
                                 long double &x, double &eCounter);
void oneHundredSixModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter);
void oneHundredFiveModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter);
void oneHundredFourModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter);
void oneHundredThreeModFactorial(long double &n, long double &y, 
                                 long double &x, double &eCounter);
void oneHundredTwoModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter);
void oneHundredOneModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter);
void oneHundredModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void ninetyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void ninetyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void ninetySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void ninetySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void ninetyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void ninetyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void ninetyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void ninetyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void ninetyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void ninetyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter);
void eightyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void eightyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void eightySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void eightySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void eightyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void eightyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void eightyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void eightyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void eightyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void eightyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter);
void seventyNineModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void seventyEightModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter);
void seventySevenModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter);
void seventySixModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void seventyFiveModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void seventyFourModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter);
void seventyThreeModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter);
void seventyTwoModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void seventyOneModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void seventyModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter);
void sixtyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void sixtyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void sixtySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void sixtySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void sixtyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void sixtyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void sixtyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void sixtyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void sixtyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void sixtyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter);
void fiftyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void fiftyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void fiftySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void fiftySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void fiftyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void fiftyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void fiftyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter);
void fiftyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void fiftyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);
void fiftyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter); 
void fortyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void fortyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void fortySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void fortySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter); 
void fortyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void fortyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void fortyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void fortyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter); 
void fortyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter); 
void fortyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter); 
void thirtyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void thirtyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void thirtySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void thirtySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void thirtyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void thirtyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void thirtyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void thirtyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void thirtyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void thirtyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter); 
void twentyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void twentyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void twentySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void twentySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void twentyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void twentyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter); 
void twentyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter); 
void twentyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);
void twentyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter); 
void twentyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter); 
void nineteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);   
void eighteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);   
void seventeenModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter);   
void sixteenModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter);    
void fifteenModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter);                          
void fourteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);  
void thirteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter);   
void twelveModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter);                             
void elevenModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter); 
void tenModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter);                         
void nineModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter);
void eightModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter);
void sevenModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter);
void sixModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter);
void fiveModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter);     
void fourModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter);
void threeModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter);
void twoModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter);
void otherFactorial(long double &n, long double &y, long double &x,
                    double &eCounter); 
void thresholdExceeded(long double &y, double &eCounter);
void displayTimes(time_t *, time_t *, struct timeb *, struct timeb *);


int main()
{
      //variable to store the number whose factorial is being computed
      long double n = 0;

   /* variable to compute the entered factorial in the '...Factorial' 
       function */
      long double y = 1;

   /* loop counter and variable to compute the entered factorial in the 
      '...Factorial' function  */
      long double x = 1;

   /* variable to keep track of the number of "e+2776"s in the factorial 
      calculation */
      double eCounter = 0;

   /* Variable to calculate the correct "e+(number)" for answers greater than
      10 to the 2776th power. */
      double eFactor = 0; 

      struct timeb  startTimeW, endTimeW;
      time_t startTimeC, endTimeC;

      cout<<"\nENTER A WHOLE NUMBER:  ";
      cin>>n;

      getTime(&startTimeC, &startTimeW);

     //if number entered is divisible by 125
     if(static_cast<unsigned long long>(n) % 125 == 0)
          oneHundredTwentyFiveModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 124
     else if(static_cast<unsigned long long>(n) % 124 == 0)
          oneHundredTwentyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 123
     else if(static_cast<unsigned long long>(n) % 123 == 0)
          oneHundredTwentyThreeModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 122
     else if(static_cast<unsigned long long>(n) % 122 == 0)
          oneHundredTwentyTwoModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 121
     else if(static_cast<unsigned long long>(n) % 121 == 0)
          oneHundredTwentyOneModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 120
     else if(static_cast<unsigned long long>(n) % 120 == 0)
          oneHundredTwentyModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 119
     else if(static_cast<unsigned long long>(n) % 119 == 0)
          oneHundredNineteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 118
     else if(static_cast<unsigned long long>(n) % 118 == 0)
          oneHundredEighteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 117
     else if(static_cast<unsigned long long>(n) % 117 == 0)
          oneHundredSeventeenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 116
     else if(static_cast<unsigned long long>(n) % 116 == 0)
          oneHundredSixteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 115
     else if(static_cast<unsigned long long>(n) % 115 == 0)
          oneHundredFifteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 114
     else if(static_cast<unsigned long long>(n) % 114 == 0)
          oneHundredFourteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 113
     else if(static_cast<unsigned long long>(n) % 113 == 0)
          oneHundredThirteenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 112
     else if(static_cast<unsigned long long>(n) % 112 == 0)
          oneHundredTwelveModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 111
     else if(static_cast<unsigned long long>(n) % 111 == 0)
          oneHundredElevenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 110
     else if(static_cast<unsigned long long>(n) % 110 == 0)
          oneHundredTenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 109
     else if(static_cast<unsigned long long>(n) % 109 == 0)
          oneHundredNineModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 108
     else if(static_cast<unsigned long long>(n) % 108 == 0)
          oneHundredEightModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 107
     else if(static_cast<unsigned long long>(n) % 107 == 0)
          oneHundredSevenModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 106
     else if(static_cast<unsigned long long>(n) % 106 == 0)
          oneHundredSixModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 105
     else if(static_cast<unsigned long long>(n) % 105 == 0)
          oneHundredFiveModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 104
     else if(static_cast<unsigned long long>(n) % 104 == 0)
          oneHundredFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 103
     else if(static_cast<unsigned long long>(n) % 103 == 0)
          oneHundredThreeModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 102
     else if(static_cast<unsigned long long>(n) % 102 == 0)
          oneHundredTwoModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 101
     else if(static_cast<unsigned long long>(n) % 101 == 0)
          oneHundredOneModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 100
     else if(static_cast<unsigned long long>(n) % 100 == 0)
          oneHundredModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 99
      else if(static_cast<unsigned long long>(n) % 99 == 0)
          ninetyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 98
      else if(static_cast<unsigned long long>(n) % 98 == 0)
          ninetyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 97
      else if(static_cast<unsigned long long>(n) % 97 == 0)
          ninetySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 96
      else if(static_cast<unsigned long long>(n) % 96 == 0)
          ninetySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 95
      else if(static_cast<unsigned long long>(n) % 95 == 0)
          ninetyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 94
      else if(static_cast<unsigned long long>(n) % 94 == 0)
          ninetyFourModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 93
      else if(static_cast<unsigned long long>(n) % 93 == 0)
          ninetyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 92
      else if(static_cast<unsigned long long>(n) % 92 == 0)
          ninetyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 91
      else if(static_cast<unsigned long long>(n) % 91 == 0)
          ninetyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 90
      else if(static_cast<unsigned long long>(n) % 90 == 0)
          ninetyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 89
      else if(static_cast<unsigned long long>(n) % 89 == 0)
          eightyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 88
      else if(static_cast<unsigned long long>(n) % 88 == 0)
          eightyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 87
      else if(static_cast<unsigned long long>(n) % 87 == 0)
          eightySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 86
      else if(static_cast<unsigned long long>(n) % 86 == 0)
          eightySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 85
      else if(static_cast<unsigned long long>(n) % 85 == 0)
          eightyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 84
      else if(static_cast<unsigned long long>(n) % 84 == 0)
          eightyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 83
      else if(static_cast<unsigned long long>(n) % 83 == 0)
          eightyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 82
      else if(static_cast<unsigned long long>(n) % 82 == 0)
          eightyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 81
      else if(static_cast<unsigned long long>(n) % 81 == 0)
          eightyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 80
      else if(static_cast<unsigned long long>(n) % 80 == 0)
          eightyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 79
      else if(static_cast<unsigned long long>(n) % 79 == 0)
          seventyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 78
      else if(static_cast<unsigned long long>(n) % 78 == 0)
          seventyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 77
      else if(static_cast<unsigned long long>(n) % 77 == 0)
          seventySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 76
      else if(static_cast<unsigned long long>(n) % 76 == 0)
          seventySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 75
      else if(static_cast<unsigned long long>(n) % 75 == 0)
          seventyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 74
      else if(static_cast<unsigned long long>(n) % 74 == 0)
          seventyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 73
      else if(static_cast<unsigned long long>(n) % 73 == 0)
          seventyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 72
      else if(static_cast<unsigned long long>(n) % 72 == 0)
          seventyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 71
      else if(static_cast<unsigned long long>(n) % 71 == 0)
          seventyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 70
      else if(static_cast<unsigned long long>(n) % 70 == 0)
          seventyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 69
      else if(static_cast<unsigned long long>(n) % 69 == 0)
          sixtyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 68
      else if(static_cast<unsigned long long>(n) % 68 == 0)
          sixtyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 67
      else if(static_cast<unsigned long long>(n) % 67 == 0)
          sixtySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 66
      else if(static_cast<unsigned long long>(n) % 66 == 0)
          sixtySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 65
      else if(static_cast<unsigned long long>(n) % 65 == 0)
          sixtyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 64
      else if(static_cast<unsigned long long>(n) % 64 == 0)
          sixtyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 63
      else if(static_cast<unsigned long long>(n) % 63 == 0)
          sixtyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 62
      else if(static_cast<unsigned long long>(n) % 62 == 0)
          sixtyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 61
      else if(static_cast<unsigned long long>(n) % 61 == 0)
          sixtyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 60
      else if(static_cast<unsigned long long>(n) % 60 == 0)
          sixtyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 59
      else if(static_cast<unsigned long long>(n) % 59 == 0)
          fiftyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 58
      else if(static_cast<unsigned long long>(n) % 58 == 0)
          fiftyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 57
      else if(static_cast<unsigned long long>(n) % 57 == 0)
          fiftySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 56
      else if(static_cast<unsigned long long>(n) % 56 == 0)
          fiftySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 55
      else if(static_cast<unsigned long long>(n) % 55 == 0)
          fiftyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 54
      else if(static_cast<unsigned long long>(n) % 54 == 0)
          fiftyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 53
      else if(static_cast<unsigned long long>(n) % 53 == 0)
          fiftyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 52
      else if(static_cast<unsigned long long>(n) % 52 == 0)
          fiftyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 51
      else if(static_cast<unsigned long long>(n) % 51 == 0)
          fiftyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 50
      else if(static_cast<unsigned long long>(n) % 50 == 0)
          fiftyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 49
      else if(static_cast<unsigned long long>(n) % 49 == 0)
          fortyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 48
      else if(static_cast<unsigned long long>(n) % 48 == 0)
          fortyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 47
      else if(static_cast<unsigned long long>(n) % 47 == 0)
          fortySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 46
      else if(static_cast<unsigned long long>(n) % 46 == 0)
          fortySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 45
      else if(static_cast<unsigned long long>(n) % 45 == 0)
          fortyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 44
      else if(static_cast<unsigned long long>(n) % 44 == 0)
          fortyFourModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 43
      else if(static_cast<unsigned long long>(n) % 43 == 0)
          fortyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 42
      else if(static_cast<unsigned long long>(n) % 42 == 0)
          fortyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 41
      else if(static_cast<unsigned long long>(n) % 41 == 0)
          fortyOneModFactorial(n,y,x,eCounter);

     //else if number entered is divisible by 40
      else if(static_cast<unsigned long long>(n) % 40 == 0)
          fortyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 39
      else if(static_cast<unsigned long long>(n) % 39 == 0)
          thirtyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 38
      else if(static_cast<unsigned long long>(n) % 38 == 0)
          thirtyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 37
      else if(static_cast<unsigned long long>(n) % 37 == 0)
          thirtySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 36
      else if(static_cast<unsigned long long>(n) % 36 == 0)
          thirtySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 35
      else if(static_cast<unsigned long long>(n) % 35 == 0)
          thirtyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 34
      else if(static_cast<unsigned long long>(n) % 34 == 0)
          thirtyFourModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 33
      else if(static_cast<unsigned long long>(n) % 33 == 0)
          thirtyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 32
      else if(static_cast<unsigned long long>(n) % 32 == 0)
          thirtyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 31
      else if(static_cast<unsigned long long>(n) % 31 == 0)
          thirtyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 30
      else if(static_cast<unsigned long long>(n) % 30 == 0)
          thirtyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 29
      else if(static_cast<unsigned long long>(n) % 29 == 0)
          twentyNineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 28
      else if(static_cast<unsigned long long>(n) % 28 == 0)
          twentyEightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 27
      else if(static_cast<unsigned long long>(n) % 27 == 0)
          twentySevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 26
      else if(static_cast<unsigned long long>(n) % 26 == 0)
          twentySixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 25
      else if(static_cast<unsigned long long>(n) % 25 == 0)
          twentyFiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 24
      else if(static_cast<unsigned long long>(n) % 24 == 0)
          twentyFourModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 23
      else if(static_cast<unsigned long long>(n) % 23 == 0)
          twentyThreeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 22
      else if(static_cast<unsigned long long>(n) % 22 == 0)
          twentyTwoModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 21
      else if(static_cast<unsigned long long>(n) % 21 == 0)
          twentyOneModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 20
      else if(static_cast<unsigned long long>(n) % 20 == 0)
          twentyModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 19
      else if(static_cast<unsigned long long>(n) % 19 == 0)
          nineteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 18
      else if(static_cast<unsigned long long>(n) % 18 == 0)
          eighteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 17
      else if(static_cast<unsigned long long>(n) % 17 == 0)
          seventeenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 16
      else if(static_cast<unsigned long long>(n) % 16 == 0)
          sixteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 15
      else if(static_cast<unsigned long long>(n) % 15 == 0)
          fifteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 14
      else if(static_cast<unsigned long long>(n) % 14 == 0)
          fourteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 13
      else if(static_cast<unsigned long long>(n) % 13 == 0)
          thirteenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 12
      else if(static_cast<unsigned long long>(n) % 12 == 0)
          twelveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 11
      else if(static_cast<unsigned long long>(n) % 11 == 0)
          elevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 10
      else if(static_cast<unsigned long long>(n) % 10 == 0)
          tenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 9
      else if(static_cast<unsigned long long>(n) % 9 == 0)
          nineModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 8
      else if(static_cast<unsigned long long>(n) % 8 == 0)
          eightModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 7
      else if(static_cast<unsigned long long>(n) % 7 == 0)
          sevenModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 6
      else if(static_cast<unsigned long long>(n) % 6 == 0)
          sixModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 5
      else if(static_cast<unsigned long long>(n) % 5 == 0)
          fiveModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 4
      else if(static_cast<unsigned long long>(n) % 4 == 0)
          fourModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 3
      else if(static_cast<unsigned long long>(n) % 3 == 0)
          threeModFactorial(n,y,x,eCounter);

      //else if number entered is divisible by 2
      else if(static_cast<unsigned long long>(n) % 2 == 0)
          twoModFactorial(n,y,x,eCounter);

      //else the number entered is not divisible by one of the mods
      else 
          otherFactorial(n,y,x,eCounter);


   //if answer is <= 10 to the 2776th power
   if(eCounter == 0)
         cout<<"\n"<<setprecision(2776)<<n<<"! = "<<y<<"\n\n";

   //answer is > 10 to the 2776th power
   else
   {
         eFactor = eCounter * 2776;
         cout<<"\n"<<setprecision(2776)<<static_cast<unsigned long long>(n)
             <<"! = "<<y<<" e+"
             <<static_cast<unsigned long long>(eFactor)<<"\n\n";
   }


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

//if number entered is divisible by 125 
void oneHundredTwentyFiveModFactorial(long double &n, long double &y, 
                                      long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 125)
   {
     y *= ((x+124)*(x+123)*(x+122)*
           (x+121)*(x+120)*(x+119)*(x+118)*(x+117)*(x+116)*(x+115)*(x+114)*(x+113)*
           (x+112)*(x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*
           (x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*
           (x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*
           (x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*
           (x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 124 
void oneHundredTwentyFourModFactorial(long double &n, long double &y, 
                                      long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 124)
   {
     y *= ((x+123)*(x+122)*(x+121)*
           (x+120)*(x+119)*(x+118)*(x+117)*(x+116)*(x+115)*(x+114)*(x+113)*(x+112)*
           (x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*
           (x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*
           (x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*
           (x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*
           (x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 123 
void oneHundredTwentyThreeModFactorial(long double &n, long double &y, 
                                       long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 123)
   {
     y *= ((x+122)*(x+121)*(x+120)*
           (x+119)*(x+118)*(x+117)*(x+116)*(x+115)*(x+114)*(x+113)*(x+112)*(x+111)*
           (x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*
           (x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*
           (x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*
           (x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*
           (x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 122 
void oneHundredTwentyTwoModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 122)
   {
     y *= ((x+121)*(x+120)*
           (x+119)*(x+118)*(x+117)*(x+116)*(x+115)*(x+114)*(x+113)*(x+112)*(x+111)*
           (x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*
           (x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*
           (x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*
           (x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*
           (x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 121 
void oneHundredTwentyOneModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 121)
   {
     y *= ((x+120)*(x+119)*
           (x+118)*(x+117)*(x+116)*(x+115)*(x+114)*(x+113)*(x+112)*(x+111)*(x+110)*
           (x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*
           (x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*
           (x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*
           (x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*
           (x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 120 
void oneHundredTwentyModFactorial(long double &n, long double &y, 
                                  long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 120)
   {
     y *= ((x+119)*(x+118)*
           (x+117)*(x+116)*(x+115)*(x+114)*(x+113)*(x+112)*(x+111)*(x+110)*(x+109)*
           (x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*
           (x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*
           (x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*
           (x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*
           (x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 119 
void oneHundredNineteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 119)
   {
     y *= ((x+118)*(x+117)*
           (x+116)*(x+115)*(x+114)*(x+113)*(x+112)*(x+111)*(x+110)*(x+109)*(x+108)*
           (x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*
           (x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*
           (x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*
           (x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*
           (x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 118 
void oneHundredEighteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 118)
   {
     y *= ((x+117)*(x+116)*
           (x+115)*(x+114)*(x+113)*(x+112)*(x+111)*(x+110)*(x+109)*(x+108)*(x+107)*
           (x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*
           (x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*
           (x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*
           (x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*
           (x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 117 
void oneHundredSeventeenModFactorial(long double &n, long double &y,
                                     long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 117)
   {
     y *= ((x+116)*(x+115)*
           (x+114)*(x+113)*(x+112)*(x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*
           (x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*
           (x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*
           (x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*
           (x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*
           (x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 116 
void oneHundredSixteenModFactorial(long double &n, long double &y, 
                                   long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 116)
   {
     y *= ((x+115)*(x+114)*
           (x+113)*(x+112)*(x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*
           (x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*
           (x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*
           (x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*
           (x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*
           (x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 115 
void oneHundredFifteenModFactorial(long double &n, long double &y, 
                                   long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 115)
   {
     y *= ((x+114)*(x+113)*
           (x+112)*(x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*
           (x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*
           (x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*
           (x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*
           (x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 114 
void oneHundredFourteenModFactorial(long double &n, long double &y,
                                    long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 114)
   {
     y *= ((x+113)*(x+112)*
           (x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*
           (x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*
           (x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*
           (x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*
           (x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 113 
void oneHundredThirteenModFactorial(long double &n, long double &y, 
                                    long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 113)
   {
     y *= ((x+112)*
           (x+111)*(x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*
           (x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*
           (x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*
           (x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*
           (x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 112 
void oneHundredTwelveModFactorial(long double &n, long double &y,
                                  long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 112)
   {
     y *= ((x+111)*
           (x+110)*(x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*
           (x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*
           (x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*
           (x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*
           (x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 111 
void oneHundredElevenModFactorial(long double &n, long double &y, 
                                  long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 111)
   {
     y *= ((x+110)*
           (x+109)*(x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*
           (x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*
           (x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*
           (x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*
           (x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 110 
void oneHundredTenModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 110)
   {
     y *= ((x+109)*
           (x+108)*(x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*
           (x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*
           (x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*
           (x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*
           (x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 109 
void oneHundredNineModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 109)
   {
     y *= ((x+108)*
           (x+107)*(x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*
           (x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*
           (x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*
           (x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*
           (x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 108 
void oneHundredEightModFactorial(long double &n, long double &y, 
                                 long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 108)
   {
     y *= ((x+107)*
           (x+106)*(x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*
           (x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*
           (x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*
           (x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*
           (x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 107 
void oneHundredSevenModFactorial(long double &n, long double &y,
                                 long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 107)
   {
     y *= ((x+106)*
           (x+105)*(x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*
           (x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*
           (x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*
           (x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*
           (x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 106 
void oneHundredSixModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 106)
   {
     y *= ((x+105)*
           (x+104)*(x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*
           (x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*
           (x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*
           (x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*
           (x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
       thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 105 
void oneHundredFiveModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 105)
   {
     y *= ((x+104)*
           (x+103)*(x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*
           (x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*
           (x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*
           (x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 104 
void oneHundredFourModFactorial(long double &n, long double &y, 
                                long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 104)
   {
     y *= ((x+103)*
           (x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*
           (x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*
           (x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*
           (x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 103 
void oneHundredThreeModFactorial(long double &n, long double &y, 
                                 long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 103)
   {
     y *= ((x+102)*(x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*
           (x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*
           (x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*
           (x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 102 
void oneHundredTwoModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 102)
   {
     y *= ((x+101)*(x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*
           (x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*
           (x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*
           (x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 101 
void oneHundredOneModFactorial(long double &n, long double &y, 
                               long double &x, double &eCounter)
{
   for(x = 1; x <= n; x += 101)
   {
     y *= ((x+100)*(x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*
           (x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*
           (x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*
           (x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 100 
void oneHundredModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 100)
   {
     y *= ((x+99)*(x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*
           (x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*
           (x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*
           (x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 99 
void ninetyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 99)
   {
     y *= ((x+98)*(x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*
           (x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*
           (x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*
           (x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 98 
void ninetyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 98)
   {
     y *= ((x+97)*(x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*
           (x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*
           (x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*
           (x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 97 
void ninetySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 97)
   {
     y *= ((x+96)*(x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*
           (x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*
           (x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*
           (x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 96 
void ninetySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 96)
   {
     y *= ((x+95)*(x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*
           (x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*
           (x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*
           (x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 95 
void ninetyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 95)
   {
     y *= ((x+94)*(x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*
           (x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*
           (x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 94 
void ninetyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 94)
   {
     y *= ((x+93)*(x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*
           (x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*
           (x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 93 
void ninetyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 93)
   {
     y *= ((x+92)*(x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*
           (x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*
           (x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 92 
void ninetyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 92)
   {
     y *= ((x+91)*(x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*
           (x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*
           (x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 91 
void ninetyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 91)
   {
     y *= ((x+90)*(x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*
           (x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*
           (x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 90 
void ninetyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 90)
   {
     y *= ((x+89)*(x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*
           (x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*
           (x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 89 
void eightyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 89)
   {
     y *= ((x+88)*(x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*
           (x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*
           (x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 88 
void eightyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 88)
   {
     y *= ((x+87)*(x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*
           (x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*
           (x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 87 
void eightySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 87)
   {
     y *= ((x+86)*(x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*
           (x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*
           (x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 86 
void eightySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 86)
   {
     y *= ((x+85)*(x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*
           (x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*
           (x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   } 
}

//else if number entered is divisible by 85 
void eightyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 85)
   {
     y *= ((x+84)*(x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*
           (x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 84 
void eightyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 84)
   {
     y *= ((x+83)*(x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*
           (x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 83 
void eightyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 83)
   {
     y *= ((x+82)*(x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*
           (x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 82 
void eightyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 82)
   {
     y *= ((x+81)*(x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*
           (x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*
           x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 81 
void eightyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 81)
   {
     y *= ((x+80)*(x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*
           (x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 80 
void eightyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 80)
   {
     y *= ((x+79)*(x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*
           (x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 79 
void seventyNineModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 79)
   {
     y *= ((x+78)*(x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*
           (x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 78 
void seventyEightModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter)
{
   for(x = 1; x <= n; x += 78)
   {
     y *= ((x+77)*(x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*
           (x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 77 
void seventySevenModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter)
{
   for(x = 1; x <= n; x += 77)
   {
     y *= ((x+76)*(x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*
           (x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 76 
void seventySixModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 76)
   {
     y *= ((x+75)*(x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*
           (x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 75 
void seventyFiveModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 75)
   {
     y *= ((x+74)*(x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*
           (x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 74 
void seventyFourModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 74)
   {
     y *= ((x+73)*(x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*
           (x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 73 
void seventyThreeModFactorial(long double &n, long double &y, long double &x,
                              double &eCounter)
{
   for(x = 1; x <= n; x += 73)
   {
     y *= ((x+72)*(x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*
           (x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 72 
void seventyTwoModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 72)
   {
     y *= ((x+71)*(x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*
           (x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*
           x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 71 
void seventyOneModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 71)
   {
     y *= ((x+70)*(x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*
           (x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 70 
void seventyModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter)
{
   for(x = 1; x <= n; x += 70)
   {
     y *= ((x+69)*(x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*
           (x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
      thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 69 
void sixtyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 69)
   {
     y *= ((x+68)*(x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*
           (x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
      thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 68 
void sixtyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 68)
   {
     y *= ((x+67)*(x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*
           (x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 67 
void sixtySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 67)
   {
     y *= ((x+66)*(x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*
           (x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 66 
void sixtySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 66)
   {
     y *= ((x+65)*(x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*
           (x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 65 
void sixtyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 65)
   {
     y *= ((x+64)*(x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*
           (x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 64 
void sixtyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 64)
   {
     y *= ((x+63)*(x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*
           (x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 63 
void sixtyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 63)
   {
     y *= ((x+62)*(x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*
           (x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 62 
void sixtyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 62)
   {
     y *= ((x+61)*(x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*
           (x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*
           x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 61 
void sixtyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 61)
   {
     y *= ((x+60)*(x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*
           (x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 60 
void sixtyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 60)
   {
     y *= ((x+59)*(x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*
           (x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 59 
void fiftyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 59)
   {
     y *= ((x+58)*(x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*
           (x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 58 
void fiftyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 58)
   {
     y *= ((x+57)*(x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*
           (x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 57 
void fiftySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 57)
   {
     y *= ((x+56)*(x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*
           (x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 56 
void fiftySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 56)
   {
     y *= ((x+55)*(x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*
           (x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 55 
void fiftyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 55)
   {
     y *= ((x+54)*(x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*
           (x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 54 
void fiftyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 54)
   {
     y *= ((x+53)*(x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*
           (x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 53 
void fiftyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 53)
   {
     y *= ((x+52)*(x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*
           (x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 52 
void fiftyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 52)
   {
     y *= ((x+51)*(x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*
           (x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*
           x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 51 
void fiftyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 51)
   {
     y *= ((x+50)*(x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*
           (x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 50 
void fiftyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 50)
   {
     y *= ((x+49)*(x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*
           (x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 49 
void fortyNineModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 49)
   {
     y *= ((x+48)*(x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*
           (x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 48 
void fortyEightModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 48)
   {
     y *= ((x+47)*(x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*
           (x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 47 
void fortySevenModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 47)
   {
     y *= ((x+46)*(x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*
           (x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 46 
void fortySixModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 46)
   {
     y *= ((x+45)*(x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*
           (x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 45 
void fortyFiveModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 45)
   {
     y *= ((x+44)*(x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*
           (x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 44 
void fortyFourModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 44)
   {
     y *= ((x+43)*(x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*
           (x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 43 
void fortyThreeModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 43)
   {
     y *= ((x+42)*(x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*
           (x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 42 
void fortyTwoModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 42)
   {
     y *= ((x+41)*(x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*
           (x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*
           x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 41 
void fortyOneModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 41)
   {
     y *= ((x+40)*(x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*
           (x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 40 
void fortyModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 40)
   {
     y *= ((x+39)*(x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*
           (x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 39
void thirtyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 39)
   {
     y *= ((x+38)*(x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*
           (x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 38
void thirtyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 38)
   {
     y *= ((x+37)*(x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*
           (x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 37
void thirtySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 37)
   {
     y *= ((x+36)*(x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*
           (x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 36
void thirtySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 36)
   {
     y *= ((x+35)*(x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*
           (x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 35
void thirtyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 35)
   {
     y *= ((x+34)*(x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*
           (x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 34
void thirtyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 34)
   {
     y *= ((x+33)*(x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*
           (x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 33
void thirtyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 33)
   {
     y *= ((x+32)*(x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*
           (x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 32
void thirtyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 32)
   {
     y *= ((x+31)*(x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*
           (x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 31 
void thirtyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 31)
   {
     y *= ((x+30)*(x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*
           (x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 30 
void thirtyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 30)
   {
     y *= ((x+29)*(x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*
           (x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 29 
void twentyNineModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 29)
   {
     y *= ((x+28)*(x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*
           (x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 28 
void twentyEightModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 28)
   {
     y *= ((x+27)*(x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*
           (x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 27
void twentySevenModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 27)
   {
     y *= ((x+26)*(x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*
           (x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 26 
void twentySixModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 26)
   {
     y *= ((x+25)*(x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*
           (x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*
           (x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 25 
void twentyFiveModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 25)
   {
     y *= ((x+24)*(x+23)*(x+22)*(x+21)*(x+20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*
           (x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 24 
void twentyFourModFactorial(long double &n, long double &y, long double &x,
                            double &eCounter)
{
   for(x = 1; x <= n; x += 24)
   {
     y *= ((x+23)*(x*22)*(x*21)*(x*20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*
           (x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);  
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 23 
void twentyThreeModFactorial(long double &n, long double &y, long double &x,
                             double &eCounter)
{
   for(x = 1; x <= n; x += 23)
   {
     y *= ((x*22)*(x*21)*(x*20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*
           (x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 22 
void twentyTwoModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 22)
   {
     y *= ((x*21)*(x*20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*
           (x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 21 
void twentyOneModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 21)
   {
     y *= ((x*20)*(x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*
           (x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 20 
void twentyModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 20)
   {
     y *= ((x+19)*(x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*
           (x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 19.
void nineteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 19)
   {
     y *= ((x+18)*(x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*
           (x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 18 
void eighteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 18)
   {
     y *= ((x+17)*(x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*
           (x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 17.
void seventeenModFactorial(long double &n, long double &y, long double &x,
                           double &eCounter)
{
   for(x = 1; x <= n; x += 17)
   {
     y *= ((x+16)*(x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*
           (x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 16 
void sixteenModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter)
{
   for(x = 1; x <= n; x += 16)
   {
     y *= ((x+15)*(x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*
           (x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 15
void fifteenModFactorial(long double &n, long double &y, long double &x,
                         double &eCounter)
{
   for(x = 1; x <= n; x += 15)
   {
     y *= ((x+14)*(x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*
           (x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 14
void fourteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 14)
   {
     y *= ((x+13)*(x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*
           (x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 13
void thirteenModFactorial(long double &n, long double &y, long double &x,
                          double &eCounter)
{
   for(x = 1; x <= n; x += 13)
   {
     y *= ((x+12)*(x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*
           (x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 12
void twelveModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 12)
   {
     y *= ((x+11)*(x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 11
void elevenModFactorial(long double &n, long double &y, long double &x,
                        double &eCounter)
{
   for(x = 1; x <= n; x += 11)
   {
     y *= ((x+10)*(x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 10
void tenModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter)
{
   for(x = 1; x <= n; x += 10)
   {
     y *= ((x+9)*(x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 9
void nineModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter)
{
   for(x = 1; x <= n; x += 9)
   {
     y *= ((x+8)*(x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 8
void eightModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 8)
   {
     y *= ((x+7)*(x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 7
void sevenModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 7)
   {
     y *= ((x+6)*(x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 6
void sixModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter)
{
   for(x = 1; x <= n; x += 6)
   {
     y *= ((x+5)*(x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 5
void fiveModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter)
{
   for(x = 1; x <= n; x += 5)
   {
     y *= ((x+4)*(x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 4
void fourModFactorial(long double &n, long double &y, long double &x,
                      double &eCounter)
{
   for(x = 1; x <= n; x += 4)
   {
     y *= ((x+3)*(x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 3
void threeModFactorial(long double &n, long double &y, long double &x,
                       double &eCounter)
{
   for(x = 1; x <= n; x += 3)
   {
     y *= ((x+2)*(x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else if number entered is divisible by 2
void twoModFactorial(long double &n, long double &y, long double &x,
                     double &eCounter)
{
   for(x = 1; x <= n; x += 2)
   {
     y *= ((x+1)*x);
     thresholdExceeded(y, eCounter);
   }
}

//else the number entered is not divisible by one of the mods
void otherFactorial(long double &n, long double &y, long double &x,
                    double &eCounter)
{
   for(x = 1; x <= n; x++)
   {
     y *= x;
     thresholdExceeded(y, eCounter);
   }
}

void thresholdExceeded(long double &y, double &eCounter)
{
     if(y > UPPER_THRESHOLD)
     {
       y /= UPPER_THRESHOLD;
       eCounter++;
     }
}

void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)
      <<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}



/*                      SAMPLE RUN:


ENTER A WHOLE NUMBER:  2000000000000000

2000000000000000! = 60969810734533462447104760884512351747105306977874740872249115096309859018618363302749569531056587897765590149795692808483364393212486934474193016661789870051639169511363341436487508576331249023879812796936271612398534950308079737189536791399004408134952183290572778796681947034271122325699316949794739745287941567464545853602469535431874319922145048865843519561479637349129321541080574096285739193367642908245312773627358243552189127738741608651678552901602649056944014567993636552274560811408271418758012036521994689756750536063291442118964542912945710895947625569454134741391954656971547355927765903360449989345435970829031693162578184378533654380878672888213807090261319397909287257534988420161061633115985443564049979888985925790558199830726133462866925380925835514663970918106987018687605508884030475314022638883254811299460274661628821197728688199117096936512252820363757911217656652290538237298080688928251514819219852369494560613974522571290323546966250848683507114658792316888995482169970690987338819039442486487892333690675946682041639395299147083270286283383677662000537485740061824280517598119087560653186871184934515013052218901045458720284870097456629160734604141442856331169017975898172962931074454872258968090162393873090083914586966201318733138047368300898858337711856174904157355873462682858236579823554282054765002700651222326012491447405491436474147690330445973531896249197811017214944587640963661966450534186569852211547997734563010244874478481984925329834944575733404105296068492437641700730808990401611532041544906513530503145925133200155584754410105786560696574702741944109421967321848954825238525574324379180590450955180474292192375060731184827259376931234943488239519754235704443194003511216361461011487693681883630390592449987664100554339474321771732747465040125131623341287550360242047494090150612244193911885570791855650641947467391500368486448641522341144258598127079952723062985326587533040469054321713242299430885907567397098557188339065126415891409218543234263921818457639042644928192885908685175804012118290317696993193218939603675938097457885714811161026164370660244607511463750326259421114836320297418877299433480175388645454618985333166109399338892771771926201991184708728396288893631689309558032857080600916679776069756199824077109727186802810123682776844164031526918081775445665628094227100403451781042502190832184505645209268274824776978954876786879166088780992971379088328566885609428603220066188002703882683329190319318287989805011844248705421882304484196035099196465472289540298429954208574302594100966410943837894521995972962744514717739182693495043772755891514201401277407314274458686947934341179363470371575421432990525408727057852154513875230559043584 e+29733471027518768


Wall-clock time = 2272290 seconds
CPU time = 2272290 seconds
                                                                                */
