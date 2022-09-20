
/*                      mersennePrime2.cpp  
           (20X faster than my mersennePrime1.py program)

   Code posted as of November 2008 at:  
   http://www.rosettacode.org/wiki/Lucas-Lehmer_test

   Compiled on GNU C++ running on Linux.

   Requires the GNU MP arbitrary precision library. 

   To run, on the command line type: 

   g++ -O3 mersennePrime2.cpp -lgmpxx [Enter]
   ./a.out   

   The -O3 option invokes the compiler optimizer.

   David Galilei Natale started testing from 2^132,050-1 (after the 30th Mersenne prime),
   and discovered the 31st Mersenne prime (2^216,091-1) in March 2009.
   Then David Galilei Natale continued on and discovered the 32nd Mersenne prime
   (2^756,839-1) in October 2011, the 33rd Mersenne prime (2^859,433-1) in 
   May 2012, the 34th Mersenne prime (2^1,257,787-1) in February 2016,
   and the 35th Mersenne prime (2^1,398,269-1) in May 2018.

   NOTE: See mersennePrimes.docx for the list.

                                                                                          */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sys/timeb.h>
#include <gmpxx.h>

using namespace std;


void getTime(struct timeb *);
bool is_mersenne_prime(mpz_class p);
mpz_class pow2(mpz_class exp);
void displayTimes(struct timeb *, struct timeb *);

int main()
{
        struct timeb  startTimeW, endTimeW;


        getTime(&startTimeW);

        mpz_class maxcount(13);
        mpz_class found(0);
        mpz_class check(0);
        for( mpz_nextprime(check.get_mpz_t(), check.get_mpz_t());
             found < maxcount;
             mpz_nextprime(check.get_mpz_t(), check.get_mpz_t()))
        {  
                if( is_mersenne_prime(check) )
                {
                        ++found;
                        std::cout <<"\n\nMersenne " <<found <<" = "<< std::flush;
                        cout<<((pow2(check))-1);
                }               
        }

        getTime(&endTimeW);

        displayTimes(&startTimeW, &endTimeW);

        return 0;
}//end main


void getTime(struct timeb *wallClockTime)
{
   ftime(wallClockTime);
}


bool is_mersenne_prime(mpz_class p)
{
        if( 2 == p )
                return true;
        else
        {
                mpz_class div = pow2(p) - mpz_class(1);
                mpz_class s(4);
                for( mpz_class i(3); i <= p; ++i )
                {
                        s =  (s * s - mpz_class(2)) % div ;
                }

                return ( s == mpz_class(0) );
        }
}


mpz_class pow2(mpz_class exp)
{
        mpz_class ret(2);
        for(mpz_class i(1); i < exp; ++i)
                ret *= mpz_class(2);

        return ret; 
}


void displayTimes(struct timeb *startWall, struct timeb *endWall)
{
  cout<<"\n\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n\n";
}

