
/*                                 fibonacci7.cpp

   Author: David Natale

   Last edited: February 28, 2013 

   This program approximates the nth Fibonacci number entered by the user.
   This program runs much faster than my fibonacci6.cpp program because of
   the ability to compute 93 Fibonacci numbers at a time.  The trade-off
   is a margin of error for very large for Fibonacci numbers.

   (NOTE: I'm making the assumption that the fibonacci6.cpp program is
    more accurate for large values because it incrementally computes
    these #s rather than 93 at once.)

   The logic for computing 93 Fibonacci numbers at a time is based on
   the fact that this program can compute the 1st thru the 93rd Fibonacci
   number with 100% accuracy. This way, I'm starting with a precise
   calculation.

   In cases where the inputted value is very large, the increase in computation
   speed is impressive. For example, it took 18 days to approximate the
   1 quadrillionth Fibonacci number with my fibonacci6.cpp program, whereas
   it took 22 hours with this program.  The results obtained were almost 
   100% identical to each other!

   My computer is powered with an Intel 3.5 GHz CPU.

   Compiled on the Intel C++ Compiler running on openSUSE 11.4. 

   To run, on the command line type:

   icpc -fma -pc80 -axSSE4.2 -O3 fibonacci7.cpp -o pFib7 [Enter]
   ./pFib7

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

void getTime(time_t *cpuTime, struct timeb *wallClockTime);

void Fibonacci(long long *n, long long *i, long double *previous,
               long double *result, long double *sum, long long *eCounter,
               long long *eNumber, unsigned long long *fibNum91,
               unsigned long long *fibNum92, unsigned long long *fibNum93);

void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall);

//Global variable used to echo: "FIBONACCI # "<<nthFibNum, at end of program.
long long nthFibNum;

int main()
{
    long long n = 0;

    long long i = 0;

    /* Variable to keep track of the number of "e+4910"s in the Fibonacci
       calculation. */
    long long eCounter = 0;

    /* Variable to calculate the correct "e+(number)" for answers greater than
       10 to the 4910th power. */
    long long eNumber = 0;

    long double previous = -1.0;
    long double result = 1.0;
    long double sum = 0.0;

    unsigned long long fibNum91 = 0, fibNum92 = 0, fibNum93 = 0;

    struct timeb  startTimeW, endTimeW;
    time_t startTimeC, endTimeC;

    /* The user is prompted to enter the 91st, 92nd and 93rd Fibonacci numbers.
       These numbers are used in the 'Fibonacci' function to compute 93
       Fibonacci numbers at a time. */
    cout<<"\nEnter the 91st Fibonacci # (\"4660046610375530309\"): ";
    cin>>fibNum91;

    cout<<"\nEnter the 92nd Fibonacci # (\"7540113804746346429\"): ";
    cin>>fibNum92;

    cout<<"\nEnter the 93rd Fibonacci # (\"12200160415121876738\"): ";
    cin>>fibNum93;

    cout<<"\n\nEnter Nth Fibonacci number you want computed: ";
    cin>>n;

    getTime(&startTimeC, &startTimeW);

    nthFibNum = n;

    Fibonacci(&n,&i,&previous,&result,&sum,&eCounter,&eNumber, &fibNum91,
              &fibNum92, &fibNum93);

    getTime(&endTimeC, &endTimeW);

    displayTimes(&startTimeC, &endTimeC, &startTimeW, &endTimeW);

    return 0;
}// end main


void getTime(time_t *cpuTime, struct timeb *wallClockTime)
{
   //get wall-clock time
   ftime(wallClockTime);

   //get cpu time
   time(cpuTime);
}


void Fibonacci(long long *n, long long *i, long double *previous,
               long double *result, long double *sum, long long *eCounter,
               long long *eNumber, unsigned long long *fibNum91,
               unsigned long long *fibNum92, unsigned long long *fibNum93)
{

    // This loop computes 93 Fibonacci #s at a time; provided *n-*i >= 93.
    for (*i = 0; *i <= (*n - 93); *i += 93)
    {
       if(*result > UPPER_THRESHOLD)
       {
          *result /= UPPER_THRESHOLD;
          *previous /= UPPER_THRESHOLD;
          (*eCounter)++;

       }

       *sum = *result + *previous;
       *previous = (*fibNum92 * *sum) + (*fibNum91 * *result);
       *result   = (*fibNum93 * *sum) + (*fibNum92 * *result);
    }

    long long j = *i;

    /* This loop computes Fibonacci numbers the traditional way from the
       point where the above loop terminated.                            */
    for (*i = j; *i <= *n; (*i)++)
    { 
       if(*result > UPPER_THRESHOLD)
       {
         *result /= UPPER_THRESHOLD;
         *previous /= UPPER_THRESHOLD;
         (*eCounter)++;

       }

       *sum = *result + *previous;
       *previous = *result;
       *result = *sum;
    }



     //if answer is <= 1e+4910
     if(*eCounter == 0)
     {
          cout<<"\nFIBONACCI # "<<nthFibNum<<" = "<<setprecision(4910)<<*sum
              <<"\n";
     }
     else
     {
       *eNumber = *eCounter * 4910;
       cout<<"\nFIBONACCI # "<<nthFibNum<<" = "<<setprecision(4910)<<*sum
           <<" e+"<<*eNumber<<"\n";
     }
}


void displayTimes(time_t *startCPU, time_t *endCPU, struct timeb *startWall,
                  struct timeb *endWall)
{
  cout<<"\nWall-clock time = "<<(endWall->time - startWall->time)<<" seconds\n";
  cout<<"CPU time = "<<(*endCPU - *startCPU)<<" seconds\n\n";
}

/*                           SAMPLE RUNS:


Enter the 91st Fibonacci # ("4660046610375530309"): 4660046610375530309

Enter the 92nd Fibonacci # ("7540113804746346429"): 7540113804746346429

Enter the 93rd Fibonacci # ("12200160415121876738"): 12200160415121876738


Enter Nth Fibonacci number you want computed: 1000000000000000

FIBONACCI # 1000000000000000 = 242261486293631654664848348326528335113116753558623446440982409042262805218390729054864225055828015109822416771613111621058563230440847626741978359392473147683078592786391355022330045121061661066108050773874640716008827525019438795395513996457434548354730130259646092914553207184537806365684548232466757418410271135551850291118061875449999392972955754484679345072958347516893165152844626203928323881256806668323491408772317972831619879469871678696309403362240515221944621798790890764859319636247971344000448967523259215168984257298297848074514176039818086100550742504378995437162220843278489536181982058076440791847556274874486811424297561907580937513141869221759679567272195358343531741735884911845624083226919997297389560162906136211315433708899275413197890035489644402447145512457925602523135229906161526553231678381239576086014368799935312068130633215314028324670033420379981520460320713667089155799952843712172610771972929236743250092704158554290699949356057484190573536539230521252232520882888146424332026545879080128428202901926172679535914361452385257803090038537125331170243933975883989643040120984080985884868994479665481040543725413589030197473564652663344994150885262249119252445557680794105273341257622127349176329993128286995343046386602099163948080461887237614010274415501369323858790649698860693148358398817945979688051266508908665537446956354051604376210235836310732882630939225919661777166490254339724526735788454810813774744837414272262328270689694988526246409806725874001107684088251710137290034732493852155100904002469984404263487048152476770134267243019382598978195827098289945164068897603596140636132081664 e+208987640248350

Wall-clock time = 79344 seconds
CPU time = 79344 seconds


________________________________________________________________________________________


Enter the 91st Fibonacci # ("4660046610375530309"): 4660046610375530309                                                                                                                                            
                                                                                                                                                                                                                   
Enter the 92nd Fibonacci # ("7540113804746346429"): 7540113804746346429                                                                                                                                            
                                                                                                                                                                                                                   
Enter the 93rd Fibonacci # ("12200160415121876738"): 12200160415121876738                                                                                                                                          
                                                                                                                                                                                                                   
                                                                                                                                                                                                                   
Enter Nth Fibonacci number you want computed: 50000000000000000  (50 quadrillion)                                                                                                                                                    
                                                                                                                                                                                                                   
FIBONACCI # 50000000000000000 = 218264936033994371120042908738514809038072291683603483492895467609257069894633795356314952386256478314145786638833216256338888362636688000966236440507016006777021869429303868031173071299497353907237706509387288297153193192016946184684019966213917546159179181938400218064492034015619503998128268290794517137035091267908452942375457412850755818244532364184102412661034143248594376789470775990500515996389030320248410327670818392146688238653194185540377147342053292390853968653029356511639104215526342234036815549622076220564547589649510350564661380861613710860320958799025845907120986440925049680009582227980558868386811025856063588612759904114022036733707855385704037006360968088584601660444269118115550878262173279983405823479261872956862288767339854687808165169817323050250298173271522838209807648380868453573245627525796347416842248308914621428971914570244466379163449254771603781489785239344651196833020493799392013138832362456644680717571429396190900609766645338742812167119882940447875653041340565755097419920871120149485359917563877526764308188064492158080824270686860091699099915791171399445556396672169785415948533317899577105854484722839344761682028169713912614646560187551246681801191268384114035498480513481828579953631924291998940788516377638872988960257832127525659292928884352136671624214986918910654533733727643383783675049237097341695404528564919645029838740362556199254984093674822494275874550514490256539410959345052807129228038983745168241604565149912669170273557973592942894271909005145522903203735803746663435671894496496192980219819813959261109392561325574722780927149227253670624376277844467216452351149531452982684284612067848160445747206679132458844019722168612690229750761452767627448551022597308411881768231534059692010627887092802568166555423948612242644248269349356409769631924878352370828898570199681358641465522229504198681125193244930258960847261915378427570240354771126779673855160858185410617154164620677969712576531241993707653395260288578996662732755613876095055449938173499358571565632183862806872737969966648285616967156475834693454373038898089924619917459004848048782526787241501187728818456502149436094327870771272321963486497948736981168812720384026702280948487916301324317900248549102706746390612940525358203668137514230055865686446104397585061767882542247347204596689691540987129540299523667835015736994448162475243521207957505734014447284139941027408355897394253853312477085352471380144427743649001573133919671827313244231379606544041592674666385934093567741658628678408653527802635828212569590418707693222965721494729397905840337839360113245545359271156265337777281097806751987176848033632418666034827427747640853274159465020726487459714137226341825609271332859220807700534361894011976551178999199425214705393926651263658215957867730326267010859463140310982627830539551090213386337435133301387255191510938925022665827770587752169472 e+10449382012496060

Wall-clock time = 2830871 seconds
CPU time = 2830871 seconds
                                                                                           */



