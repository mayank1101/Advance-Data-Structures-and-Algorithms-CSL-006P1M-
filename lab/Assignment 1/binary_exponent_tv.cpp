#include<iostream>
#include<string>
#include<sys/time.h>
#include<iomanip>
#include <sstream>
#include<math.h>
#define N 1000000007 // prime modulo value
using namespace std;

typedef unsigned long long int LL;

static LL mul1 = 0;
static LL mul2 = 0;

LL binary_exponent(LL a, LL n)
{
  LL ans = 1;
  while(n > 0){
    LL q = n/2; // get the quotient
    LL r = n%2; // get the remainder
    if(r == 1){ //if power is odd
      ans = (ans * a) % N;
      mul1++;
    }
    if(q == 0){
      return ans;
    }
    n = q; //reduce the power to half
    a = (a * a) % N; // double the base
    mul1++;
  }
  return ans % N;
}

LL sqr_mul(LL res, LL a, LL n)
{
  if(n == 0){
    return 1;
  }
  else if(n == 1){
    return ((res*a) % N);
  }
  //bit 0 then square the number
  else if(n % 2 == 0){
    mul2++;
    return sqr_mul(res, ((a*a) % N), n/2);
  }
  //bit is 1 then square and multiply with result
  else{
    mul2++;
    return sqr_mul(((res*a) % N), ((a*a) % N), (n-1)/2);
  }
}



int main(void)
{
  LL a = 2, n = 63;
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL); // get start point time
  LL ans =  binary_exponent(a,n);
  gettimeofday(&tvalEnd,NULL);
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << a << " power " << n << " using Binary Exponentiation is : " << ans << "\n";
  cout << "Using timeval, Elapsed Time: " << time_taken << " micro seconds\n" << setprecision(9);
  cout << "Using Binary Exponentiation, Number of Multiplications : " << mul1 << "\n";
  cout << "<--------------------------------------------------------------->\n";

  struct timeval tvalStart1, tvalEnd1;
  gettimeofday(&tvalStart1,NULL);
  LL ans2 = sqr_mul(1,a,n); // initialize result as 1
  gettimeofday(&tvalEnd1,NULL);
  double time_taken1 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken1 =  (time_taken1 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << a << " power " << n << " using Square and Multiply Method of Exponentiation is : " << ans2 << "\n";
  cout << "Using timeval, Elapsed Time: " << time_taken1 << " micro seconds\n" << setprecision(9);
  cout << "Using Square And Multiply, Number of Multiplications : " << mul2 << "\n";
  return 0;
}
