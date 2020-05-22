#include<iostream>
#include<chrono>
#include<iomanip>
using namespace std;

typedef unsigned long long int LL;

LL binary_exponent(LL a, LL n)
{
  LL ans = 1;
  while(n > 0){
    LL q = n/2; // get the quotient
    LL r = n%2; // get the remainder
    if(r == 1){ //if power is odd
      ans *= a;
    }
    if(q == 0){
      return ans;
    }
    n = q; //reduce the power to half
    a = a * a; // double the base
  }
  return ans;
}

LL sqr_mul(LL a, LL n)
{
  if(n == 0){ //if power is 0
    return 1;
  }
  else if(n == 1){ //if power is 1
    return a;
  }
  else if(n % 2 == 0){ // if power is even
    return sqr_mul(a*a, n/2);
  }
  else if(n % 2 != 0){ // if power is odd
    return a* sqr_mul(a*a, (n-1)/2);
  }
}

int main(void)
{
  LL a = 54, n = 900;
  auto start = chrono::high_resolution_clock::now(); //start time_point object instantiation
  LL ans =  binary_exponent(a,n);
  auto end = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count(); //typecast duration into microseconds and use count member function to on duration object
  std::time_t end_time = std::chrono::system_clock::to_time_t(end); //get current system time
  cout << a << " power " << n << " using Binary Exponentiation is : " << ans << "\n";
  std::cout << "finished computation at " << std::ctime(&end_time) << "Using chrono, elapsed time: " << (time_taken * 1000) << " nano seconds\n" << setprecision(9);

  cout << "<--------------------------------------------------------------->\n";

  auto start1 = chrono::high_resolution_clock::now();
  LL ans2 = sqr_mul(a,n);
  auto end1 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); //typecast duration into microseconds and use count member function to on duration object
  std::time_t end_time1 = std::chrono::system_clock::to_time_t(end); //get current system time
  cout << a << " power " << n << " using Square and Multiply Method of Exponentiation is : " << ans2 << "\n";
  std::cout << "finished computation at " << std::ctime(&end_time1) << "Using chrono, elapsed time: " << (time_taken1 * 1000) << " nano seconds\n" << setprecision(9);
  return 0;
}
