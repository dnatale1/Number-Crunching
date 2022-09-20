
/*                        fibonacci8.cpp

   Author: David Natale

   Last edited: 5/14/07

   This program approximates the nth Fibonacci number entered by the user.
   This is implemented by repeatedly squaring the 2-D array {{1,1}{1,0}}

   NOTE: For Fibonacci values that are 2^n - 1, 2^n or 2^n + 1, the computation
         is performed instantaneously.

   Compiled on GNU C++ running on Fedora Core 6 Linux.                  */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/timeb.h>
#include <iomanip>
#include <cfloat>
#include <cmath>

using namespace std;

/* The below constant is 1e+2466. The rationale for using this
   value is as follows: The maximum long double value is 1.18e+4932.
   In the matrixSquare() function, the e-notation (e+) value of
   fibArray[i][j] is doubled after each complete iteration of
   the nested for loop. Thus 1e+2466 squared is 1e+4932.       */

const long double UPPER_THRESHOLD = (((((((((LDBL_MAX/1.18973149535723177)/
1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+308)/1e+2;

void getTime(time_t *cpuTime, struct timeb *wallClockTime);

void initializeMatrices(long double A[][2], long double B[][2],
                        long double fibArray[][2]);

void matrixSquare(long double A[][2], long double B[][2],
                  long double fibArray[][2], unsigned long long *n,
                  unsigned long long *eCounter1,
                  unsigned long long *eCounter2,
                  unsigned long long *eCounter3,
                  unsigned long long *eCounter4,
                  unsigned long long *fibTrackingVariable,
                  unsigned long long *fibTrackingVariableMinus,
                  unsigned long long *fibTrackingVariablePlus);

void fibonacciIterative(unsigned long long *n, long double fibArray[][2],
                        unsigned long long *eCounter1,
                        unsigned long long *eCounter2,
                        unsigned long long *eCounter3,
                        unsigned long long *eCounter4,
                        unsigned long long *fibTrackingVariable,
                        unsigned long long *fibTrackingVariableMinus,
                        unsigned long long *fibTrackingVariablePlus);

void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall);

int main()
{

    long double A[2][2], B[2][2], fibArray[2][2];
    unsigned long long n = 0;
    unsigned long long eCounter1 = 0, eCounter2 = 0,
                       eCounter3 = 0, eCounter4 = 0;
    unsigned long long fibTrackingVariable = 0,
                       fibTrackingVariableMinus = 0,
                       fibTrackingVariablePlus = 0;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;

    cout<<"\nEnter Nth Fibonacci number: ";
    cin>>n;

    getTime(&startTimeC, &startTimeW);

    if((n == 1) || (n == 2))
       cout<<"\n\nFIBONACCI # "<<n<<" = "<<"1"<<"\n\n\n";
    else
    {
       /*First, initialize A and B matrices with {{1,1}{1,0}}.
         Then, initialize fibArray matrix with {{0,0}{0,0}}.    */
       initializeMatrices(A, B, fibArray);

       /* Computes the number that's (pow(2,x) + 1) <= nth Fibonacci number
          (where x is a positive integer).                              */
       matrixSquare(A, B, fibArray, &n, &eCounter1, &eCounter2, &eCounter3,
                    &eCounter4, &fibTrackingVariable, &fibTrackingVariableMinus, &fibTrackingVariablePlus);

       fibonacciIterative(&n, fibArray, &eCounter1, &eCounter2, &eCounter3,
                          &eCounter4, &fibTrackingVariable,
                          &fibTrackingVariableMinus,
                          &fibTrackingVariablePlus);
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


/* First, initialize A and B matrices with {{1,1}{1,0}}.
   Then, initialize fibArray matrix with {{0,0}{0,0}}.   */
void initializeMatrices(long double A[][2], long double B[][2],
                        long double fibArray[][2])
{
    int i, j;

   //The 3 nested for loops below initialize A and B matrices with {{1,1}{1,0}}.
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
}

/* Computes the number that's (pow(2,x) + 1) <= nth Fibonacci number
   (where x is a positive integer).                                   */
void matrixSquare(long double A[][2], long double B[][2],
                  long double fibArray[][2], unsigned long long *n,
                  unsigned long long *eCounter1,
                  unsigned long long *eCounter2,
                  unsigned long long *eCounter3,
                  unsigned long long *eCounter4,
                  unsigned long long *fibTrackingVariable,
                  unsigned long long *fibTrackingVariableMinus,
                  unsigned long long *fibTrackingVariablePlus)
{
    int i, j, k;

    for(i = 0; i < 2; i++)
      for(j = 0; j < 2; j++)
         for(k = 0; k < 2; k++)
            fibArray[i][j] += (A[i][k] * B[k][j]);


   *fibTrackingVariable = 2;

   double exponent = 2.0;

   /* Below while loop computes the # that's (pow(2,x) + 1) <= nth Fibonacci #
      (where x is a positive integer).                                   */
   while(*n > (pow(2.0,exponent) - 2))
   {
      *eCounter1 *= 2;
      *eCounter2 *= 2;
      *eCounter3 *= 2; 
      *eCounter4 *= 2;
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
                      (*eCounter1)++;
                   if((i == 0) && (j == 1))
                      (*eCounter2)++;
                   if((i == 1) && (j == 0))
                      (*eCounter3)++;
                   if((i == 1) && (j == 1))
                      (*eCounter4)++;
              }
           }
        }
      }
    exponent = exponent + 1.0;
    *fibTrackingVariable *= 2;
   } //end while


  *fibTrackingVariableMinus = *fibTrackingVariable - 1;
  *fibTrackingVariablePlus  = *fibTrackingVariable + 1;

}//end matrixSquare


//Starts where the matrixSquare() function left off.
void fibonacciIterative(unsigned long long *n, long double fibArray[][2],
                        unsigned long long *eCounter1,
                        unsigned long long *eCounter2,
                        unsigned long long *eCounter3,
                        unsigned long long *eCounter4,
                        unsigned long long *fibTrackingVariable,
                        unsigned long long *fibTrackingVariableMinus,
                        unsigned long long *fibTrackingVariablePlus)
{
   unsigned long long eNumber1 = *eCounter1 * 2466;
   unsigned long long eNumber2 = *eCounter2 * 2466;
   unsigned long long eNumber3 = *eCounter3 * 2466;
   unsigned long long eNumber4 = *eCounter4 * 2466;

   if(*fibTrackingVariablePlus == *n)
   {
       cout<<"\nFIBONACCI # "<<*n<<" = "<<setprecision(2466)<<fibArray[0][0]
           <<" e+"<<eNumber1<<"\n";
   }

   //Note: This is the same value that's stored in fibArray[1][0] 
   else if(*fibTrackingVariable == *n) 
   {
       cout<<"\nFIBONACCI # "<<*n<<" = "<<setprecision(2466)<<fibArray[0][1]
           <<" e+"<<eNumber2<<"\n";
   }

   else if(*fibTrackingVariableMinus == *n) 
   {
       cout<<"\nFIBONACCI # "<<*n<<" = "<<setprecision(2466)<<fibArray[1][1]
           <<" e+"<<eNumber4<<"\n";
   }

   else
   {
      unsigned long long i = 0;
      long double result   = fibArray[0][0];
      long double previous = fibArray[0][1];
      long double sum = 0;

      if(result > UPPER_THRESHOLD)
      {
         result /= UPPER_THRESHOLD;
         previous /= UPPER_THRESHOLD;
         (*eCounter1)++;

      }

      for (i = *fibTrackingVariablePlus+1; i <= *n; i++)
      {
          if(result > UPPER_THRESHOLD)
          {
             result /= UPPER_THRESHOLD;
             previous /= UPPER_THRESHOLD;
             (*eCounter1)++;

          }

          sum = result + previous;
          previous = result;
          result = sum;
      }


      //if answer is <= 1e+2466
       if(*eCounter1 == 0)
       {
          cout<<"\nFIBONACCI # "<<*n<<" = "<<setprecision(2466)<<result<<"\n";
       }
       else
       {
          eNumber1 = *eCounter1 * 2466;
          cout<<"\nFIBONACCI # "<<*n<<" = "<<setprecision(2466)<<result<<" e+"
              <<eNumber1<<"\n";
       }
   }//end outer else
}//end fibonacciIterative


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}


/*                               SAMPLE RUN:

Enter Nth Fibonacci number: 18446744073709551615

FIBONACCI # 18446744073709551615 =   (NOTE: This is 2^64 - 1, the maximum Fibonacci number that can be approximated with this program.)

800464159236191319000822625224173186935006523156903669513431203036576703170331473133249503786251174261806914856855177521531844229518598106098799462657493348433651325442867109317203516671435781116928283911269633454885333174302178304453608542690912591576697559435798315742965734592655846641864520257702782171895932772769888215190104312741296857106125711418710401032371813132855745819412520052820068807841076130570977325757423114738983473023747655282473494533713101816585069805299857790857257705418034494153873126981522712185260748399227428710568982031160590790938088352837372954393575236508271227706958089462477759276835745806591115673501381617290535527835256214833969770436561511103891394964200522386738331576453287796461447484719346314086582718385268081129481062214654140947502165549871038118356393085880212883397986723219085362451799056017118223773508749784535049850876825495860017622335335409339032205572167343152899661759378150512177981493670551658453646961630148476013695072605797276615706451244441116395761112831781295983852267936969527245544194829372656721927508134254250807759430179122549893444289065973371210688190060916409077925529510578557488386672335286582411758415402336510991603961299617825468349336270971976543874038191526892608790679120667052125066393597198140380942640776305710096402573677676165205124960946628176565203131644192872031365846112193060629404884780185561855680634414818941136389527284710491745475827478390511276624515168109082736560388221687880173229162937435247460119203637826118114040204414451638216710759684886830468511997041740558699068279011033178542121649600977002554861939545159383304356815219027800830642815893951882351883091559965217662387174730653239099898960601398910964893913888824667671564188165099560293990388230039559183612415708267781210835295143577579292619470545444468180475278731202991795787509519067502391490690753765090198666801058928128531313201934687884155631580690544011084326214527949958727043124377770059968441392712451068245659379450665262563569600545706974004542773222268737996188307250933201291780514328791402389813403912381419830737581056506250471548777829344465346130608128 e+3855141514259836830

Wall-clock time = 0 seconds
CPU time = 0 seconds                                                                           */




