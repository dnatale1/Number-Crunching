

/*                      twoToThePowerOfN.cpp  

   Author: David Natale

   Last edited: October 17, 2010

   Compiled on GNU C++ running on Ubuntu 10.04.

   Requires the GNU MP arbitrary precision library. I used v. 4.3.2.

   To run, on the command line type: 

   g++ -O3 twoToThePowerOfN.cpp -lgmpxx [Enter]
   ./a.out   

   The -O3 option invokes the compiler optimizer.

   Works for n >= 1.

   I calculated and printed 2^6,632,000,252.
   This number has 1,996,431,008 digits, starts with 1267891802 
   and ends with 7690602496.
                                                                      */

#include <iostream>
#include <fstream>
#include <sys/timeb.h>
#include <gmpxx.h>

using namespace std;


void getTime(struct timeb *);
void pow2(mpz_class exp);
void displayTimes(struct timeb *, struct timeb *);


int main()
{     
        struct timeb  startTimeW, endTimeW;

        getTime(&startTimeW);

        pow2(5);

        getTime(&endTimeW);

        displayTimes(&startTimeW, &endTimeW);

        return 0;
}//end main


void getTime(struct timeb *wallClockTime)
{
   ftime(wallClockTime);
}


void pow2(mpz_class exp)
{
      ofstream outFile;

      outFile.open("PowerAnswer");


      if(mpz_class(exp) == 1 || (exp) == 2 || (exp) == 3)
      { 
        mpz_class ret(2);
        for(mpz_class i(1); i < exp; ++i)
                ret *= mpz_class(2);

        outFile<<ret;
      }

      else if(mpz_class(exp%62) == 0)
      { 
                      //2^62
        mpz_class ret(4611686018427387904);
        for(mpz_class i(1); i < (exp/62); ++i)
                ret *= mpz_class(4611686018427387904);

        outFile<<ret;
      }

      else if(mpz_class(exp%61) == 0)
      { 
                      //2^61
        mpz_class ret(2305843009213693952);
        for(mpz_class i(1); i < (exp/61); ++i)
                ret *= mpz_class(2305843009213693952);

        outFile<<ret;
      }

      else if(mpz_class(exp%60) == 0)
      { 
                      //2^60
        mpz_class ret(1152921504606846976);
        for(mpz_class i(1); i < (exp/60); ++i)
                ret *= mpz_class(1152921504606846976);

        outFile<<ret;
      }

      else if(mpz_class(exp%59) == 0)
      { 
        mpz_class ret(576460752303423488);
        for(mpz_class i(1); i < (exp/59); ++i)
                ret *= mpz_class(576460752303423488);

        outFile<<ret;
      }

      else if(mpz_class(exp%58) == 0)
      { 
        mpz_class ret(288230376151711744);
        for(mpz_class i(1); i < (exp/58); ++i)
                ret *= mpz_class(288230376151711744);

        outFile<<ret;
      }

      else if(mpz_class(exp%57) == 0)
      { 
        mpz_class ret(144115188075855872);
        for(mpz_class i(1); i < (exp/57); ++i)
                ret *= mpz_class(144115188075855872);

        outFile<<ret;
      }

      else if(mpz_class(exp%56) == 0)
      { 
        mpz_class ret(72057594037927936);
        for(mpz_class i(1); i < (exp/56); ++i)
                ret *= mpz_class(72057594037927936);

        outFile<<ret;
      }

      else if(mpz_class(exp%55) == 0)
      { 
        mpz_class ret(36028797018963968);
        for(mpz_class i(1); i < (exp/55); ++i)
                ret *= mpz_class(36028797018963968);

        outFile<<ret;
      }

      else if(mpz_class(exp%54) == 0)
      { 
        mpz_class ret(18014398509481984);
        for(mpz_class i(1); i < (exp/54); ++i)
                ret *= mpz_class(18014398509481984);

        outFile<<ret;
      }

      else if(mpz_class(exp%53) == 0)
      { 
        mpz_class ret(9007199254740992);
        for(mpz_class i(1); i < (exp/53); ++i)
                ret *= mpz_class(9007199254740992);

        outFile<<ret;
      }

      else if(mpz_class(exp%52) == 0)
      { 
        mpz_class ret(4503599627370496);
        for(mpz_class i(1); i < (exp/52); ++i)
                ret *= mpz_class(4503599627370496);

        outFile<<ret;
      }

      else if(mpz_class(exp%51) == 0)
      { 
        mpz_class ret(2251799813685248);
        for(mpz_class i(1); i < (exp/51); ++i)
                ret *= mpz_class(2251799813685248);

        outFile<<ret;
      }

      else if(mpz_class(exp%50) == 0)
      { 
        mpz_class ret(1125899906842624);
        for(mpz_class i(1); i < (exp/50); ++i)
                ret *= mpz_class(1125899906842624);

        outFile<<ret;
      }

      else if(mpz_class(exp%49) == 0)
      { 
        mpz_class ret(562949953421312);
        for(mpz_class i(1); i < (exp/49); ++i)
                ret *= mpz_class(562949953421312);

        outFile<<ret;
      }

      else if(mpz_class(exp%48) == 0)
      { 
        mpz_class ret(281474976710656);
        for(mpz_class i(1); i < (exp/48); ++i)
                ret *= mpz_class(281474976710656);

        outFile<<ret;
      }

      else if(mpz_class(exp%47) == 0)
      { 
        mpz_class ret(140737488355328);
        for(mpz_class i(1); i < (exp/47); ++i)
                ret *= mpz_class(140737488355328);

        outFile<<ret;
      }

      else if(mpz_class(exp%46) == 0)
      { 
        mpz_class ret(70368744177664);
        for(mpz_class i(1); i < (exp/46); ++i)
                ret *= mpz_class(70368744177664);

        outFile<<ret;
      }

      else if(mpz_class(exp%45) == 0)
      { 
        mpz_class ret(35184372088832);
        for(mpz_class i(1); i < (exp/45); ++i)
                ret *= mpz_class(35184372088832);

        outFile<<ret;
      }

      else if(mpz_class(exp%44) == 0)
      { 
        mpz_class ret(17592186044416);
        for(mpz_class i(1); i < (exp/44); ++i)
                ret *= mpz_class(17592186044416);

        outFile<<ret;
      }

      else if(mpz_class(exp%43) == 0)
      { 
        mpz_class ret(8796093022208);
        for(mpz_class i(1); i < (exp/43); ++i)
                ret *= mpz_class(8796093022208);

        outFile<<ret;
      }

      else if(mpz_class(exp%42) == 0)
      { 
        mpz_class ret(4398046511104);
        for(mpz_class i(1); i < (exp/42); ++i)
                ret *= mpz_class(4398046511104);

        outFile<<ret;
      }

      else if(mpz_class(exp%41) == 0)
      { 
        mpz_class ret(2199023255552);
        for(mpz_class i(1); i < (exp/41); ++i)
                ret *= mpz_class(2199023255552);

        outFile<<ret;
      }

      else if(mpz_class(exp%40) == 0)
      { 
        mpz_class ret(1099511627776);
        for(mpz_class i(1); i < (exp/40); ++i)
                ret *= mpz_class(1099511627776);

        outFile<<ret;
      }

      else if(mpz_class(exp%39) == 0)
      { 
        mpz_class ret(549755813888);
        for(mpz_class i(1); i < (exp/39); ++i)
                ret *= mpz_class(549755813888);

        outFile<<ret;
      }

      else if(mpz_class(exp%38) == 0)
      { 
        mpz_class ret(274877906944);
        for(mpz_class i(1); i < (exp/38); ++i)
                ret *= mpz_class(274877906944);

        outFile<<ret;
      }

      else if(mpz_class(exp%37) == 0)
      { 
        mpz_class ret(137438953472);
        for(mpz_class i(1); i < (exp/37); ++i)
                ret *= mpz_class(137438953472);

        outFile<<ret;
      }

      else if(mpz_class(exp%36) == 0)
      { 
        mpz_class ret(68719476736);
        for(mpz_class i(1); i < (exp/36); ++i)
                ret *= mpz_class(68719476736);

        outFile<<ret;
      }

      else if(mpz_class(exp%35) == 0)
      { 
        mpz_class ret(34359738368);
        for(mpz_class i(1); i < (exp/35); ++i)
                ret *= mpz_class(34359738368);

        outFile<<ret;
      }

      else if(mpz_class(exp%34) == 0)
      { 
        mpz_class ret(17179869184);
        for(mpz_class i(1); i < (exp/34); ++i)
                ret *= mpz_class(17179869184);

        outFile<<ret;
      }

      else if(mpz_class(exp%33) == 0)
      { 
        mpz_class ret(8589934592);
        for(mpz_class i(1); i < (exp/33); ++i)
                ret *= mpz_class(8589934592);

        outFile<<ret;
      }

      else if(mpz_class(exp%32) == 0)
      { 
        mpz_class ret(4294967296);
        for(mpz_class i(1); i < (exp/32); ++i)
                ret *= mpz_class(4294967296);

        outFile<<ret;
      }

      else if(mpz_class(exp%31) == 0)
      { 
        mpz_class ret(2147483648);
        for(mpz_class i(1); i < (exp/31); ++i)
                ret *= mpz_class(2147483648);

        outFile<<ret;
      }

      else if(mpz_class(exp%30) == 0)
      { 
        mpz_class ret(1073741824);
        for(mpz_class i(1); i < (exp/30); ++i)
                ret *= mpz_class(1073741824);

        outFile<<ret;
      }

      else if(mpz_class(exp%29) == 0)
      { 
        mpz_class ret(536870912);
        for(mpz_class i(1); i < (exp/29); ++i)
                ret *= mpz_class(536870912);

        outFile<<ret;
      }

      else if(mpz_class(exp%28) == 0)
      { 
        mpz_class ret(268435456);
        for(mpz_class i(1); i < (exp/28); ++i)
                ret *= mpz_class(268435456);

        outFile<<ret;
      }

      else if(mpz_class(exp%27) == 0)
      { 
        mpz_class ret(134217728);
        for(mpz_class i(1); i < (exp/27); ++i)
                ret *= mpz_class(134217728);

        outFile<<ret;
      }

      else if(mpz_class(exp%26) == 0)
      { 
        mpz_class ret(67108864);
        for(mpz_class i(1); i < (exp/26); ++i)
                ret *= mpz_class(67108864);

        outFile<<ret;
      }

      else if(mpz_class(exp%25) == 0)
      { 
        mpz_class ret(33554432);
        for(mpz_class i(1); i < (exp/25); ++i)
                ret *= mpz_class(33554432);

        outFile<<ret;
      }

      else if(mpz_class(exp%24) == 0)
      { 
        mpz_class ret(16777216);
        for(mpz_class i(1); i < (exp/24); ++i)
                ret *= mpz_class(16777216);

        outFile<<ret;
      }

      else if(mpz_class(exp%23) == 0)
      { 
        mpz_class ret(8388608);
        for(mpz_class i(1); i < (exp/23); ++i)
                ret *= mpz_class(8388608);

        outFile<<ret;
      }

      else if(mpz_class(exp%22) == 0)
      { 
        mpz_class ret(4194304);
        for(mpz_class i(1); i < (exp/22); ++i)
                ret *= mpz_class(4194304);

        outFile<<ret;
      }

      else if(mpz_class(exp%21) == 0)
      { 
        mpz_class ret(2097152);
        for(mpz_class i(1); i < (exp/21); ++i)
                ret *= mpz_class(2097152);

        outFile<<ret;
      }

      else if(mpz_class(exp%20) == 0)
      { 
        mpz_class ret(1048576);
        for(mpz_class i(1); i < (exp/20); ++i)
                ret *= mpz_class(1048576);

        outFile<<ret;
      }

      else if(mpz_class(exp%19) == 0)
      { 
        mpz_class ret(524288);
        for(mpz_class i(1); i < (exp/19); ++i)
                ret *= mpz_class(524288);

        outFile<<ret;
      }

      else if(mpz_class(exp%18) == 0)
      { 
        mpz_class ret(262144);
        for(mpz_class i(1); i < (exp/18); ++i)
                ret *= mpz_class(262144);

        outFile<<ret;
      }

      else if(mpz_class(exp%17) == 0)
      { 
        mpz_class ret(131072);
        for(mpz_class i(1); i < (exp/17); ++i)
                ret *= mpz_class(131072);

        outFile<<ret;
      }

      else if(mpz_class(exp%16) == 0)
      { 
        mpz_class ret(65536);
        for(mpz_class i(1); i < (exp/16); ++i)
                ret *= mpz_class(65536);

        outFile<<ret;
      }

      else if(mpz_class(exp%15) == 0)
      { 
        mpz_class ret(32768);
        for(mpz_class i(1); i < (exp/15); ++i)
                ret *= mpz_class(32768);

        outFile<<ret;
      }

      else if(mpz_class(exp%14) == 0)
      { 
        mpz_class ret(16384);
        for(mpz_class i(1); i < (exp/14); ++i)
                ret *= mpz_class(16384);

        outFile<<ret;
      }

      else if(mpz_class(exp%13) == 0)
      { 
        mpz_class ret(8192);
        for(mpz_class i(1); i < (exp/13); ++i)
                ret *= mpz_class(8192);

        outFile<<ret;
      }

      else if(mpz_class(exp%12) == 0)
      { 
        mpz_class ret(4096);
        for(mpz_class i(1); i < (exp/12); ++i)
                ret *= mpz_class(4096);

        outFile<<ret;
      }

      else if(mpz_class(exp%11) == 0)
      { 
        mpz_class ret(2048);
        for(mpz_class i(1); i < (exp/11); ++i)
                ret *= mpz_class(2048);

        outFile<<ret;
      }

      else if(mpz_class(exp%10) == 0)
      { 
        mpz_class ret(1024);
        for(mpz_class i(1); i < (exp/10); ++i)
                ret *= mpz_class(1024);

        outFile<<ret;
      }

      else if(mpz_class(exp%9) == 0)
      { 
        mpz_class ret(512);
        for(mpz_class i(1); i < (exp/9); ++i)
                ret *= mpz_class(512);

        outFile<<ret;
      }

      else if(mpz_class(exp%8) == 0)
      { 
        mpz_class ret(256);
        for(mpz_class i(1); i < (exp/8); ++i)
                ret *= mpz_class(256);

        outFile<<ret;
      }

      else if(mpz_class(exp%7) == 0)
      { 
        mpz_class ret(128);
        for(mpz_class i(1); i < (exp/7); ++i)
                ret *= mpz_class(128);

        outFile<<ret;
      }

      else if(mpz_class(exp%6) == 0)
      { 
        mpz_class ret(64);
        for(mpz_class i(1); i < (exp/6); ++i)
                ret *= mpz_class(64);

        outFile<<ret;
      }

      else if(mpz_class(exp%5) == 0)
      { 
        mpz_class ret(32);
        for(mpz_class i(1); i < (exp/5); ++i)
                ret *= mpz_class(32);

        outFile<<ret;
      }

      else if(mpz_class(exp%4) == 0)
      { 
        mpz_class ret(16);
        for(mpz_class i(1); i < (exp/4); ++i)
                ret *= mpz_class(16);

        outFile<<ret;
      }

      else if(mpz_class(exp%3) == 0)
      { 
        mpz_class ret(8);
        for(mpz_class i(1); i < (exp/3); ++i)
                ret *= mpz_class(8);

        outFile<<ret;
      }

      else if(mpz_class(exp%2) == 0)
      { 
        mpz_class ret(16);
        for(mpz_class i(1); i < (exp/4); ++i)
                ret *= mpz_class(16);

        for(mpz_class i(exp/4); i < ((exp-6) / 4 + 3); ++i)
                ret *= mpz_class(2);

        outFile<<ret;       
      }

      /* if exponent does not fit the above criteria
         and is in the sequence 5,9,13,17,. . .      */
      else if(mpz_class((exp-5) % 4) == 0)
      { 
        mpz_class ret(16);
        for(mpz_class i(1); i < (exp/4); ++i)
                ret *= mpz_class(16);

        for(mpz_class i(exp/4); i < (exp/4) + 1; ++i)
                ret *= mpz_class(2);

        outFile<<ret;
      }

      /* if exponent does not fit the above criteria
         and is in the sequence 7,11,15,19,. . .      */
      else if(mpz_class((exp-7) % 4) == 0)
      { 
        mpz_class ret(16);
        for(mpz_class i(1); i < (exp/4); ++i)
                ret *= mpz_class(16);

        for(mpz_class i(exp/4); i < ((exp-6) / 4 + 4); ++i)
                ret *= mpz_class(2);

        outFile<<ret;       
      }
    
      else
      {
        mpz_class ret(2);
        for(mpz_class i(1); i < exp; ++i)
                ret *= mpz_class(2);

        outFile<<ret;
      }
    
      
      outFile.close();
}// end pow2


void displayTimes(struct timeb *startWall, struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)
      <<" seconds\n\n";
}
