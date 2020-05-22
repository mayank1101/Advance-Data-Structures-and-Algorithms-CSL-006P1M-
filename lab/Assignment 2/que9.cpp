#include<iostream>
#include<vector>
#include <string>
#include <cstdlib>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

typedef long long LL;

vector<string> arr;
void generateGrayCode(LL n)
{
  //intialize with 1-bit graycode
  arr.push_back("0");
  arr.push_back("1");
	//In each iteration generate 2*i gray codes from previously  generated i gray codes.
	for(LL i=2;i < (1<<n);i = i<<1)
	{
		// Enter the prviously generate codes again in arr[] in reverse order. Now arr[] has double number of codes.
		for (LL j=i-1;j>=0;j--){
      arr.push_back(arr[j]);
    }

		// append 0 to the list L1
		for (LL j=0 ;j<i;j++){
      arr[j] = "0" + arr[j];
    }

		// append 1 to the second list L2
		for (LL j=i;j<2*i;j++){
      arr[j] = "1" + arr[j];
    }
	}
}

LL numToggles(LL n, string init_state)
{
  LL pos_init_state = 0, pos_onState = 0; //position of onState always 0 because all 0's represent onState
  //find the initial_state position
  for(LL i=0;i<arr.size();i++)
  {
    if(arr[i] == init_state){
      pos_init_state = i;
      break;
    }
  }
  // string onState = "";
  // for(LL i=0;i<n;i++){
  //   onState += "0";
  // }
  // //find the target point
  // for(LL i=0;i<arr.size();i++)
  // {
  //   if(arr[i] == onState){
  //     pos_onState = i;
  //     break;
  //   }
  // }
  //return (abs(pos_onState - pos_init_state));
  return (abs(pos_init_state - pos_onState));
}

//helper function to take xor of two strings
char xor_opn(char a, char b){
  return ((a == b)? '0':'1');
}

string convertBinaryToGray(string init_state)
{
  string grayCode = "";
  grayCode += init_state[0];
  for(LL i=1;i<init_state.size();i++)
  {
    grayCode += xor_opn(init_state[i-1],init_state[i]);
  }
  return grayCode;
}

void printArr()
{
  for(LL i=0;i<arr.size();i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main(void)
{
  LL n;
  string init_state;
  cout << "Enter the Number of Switches : ";
  cin>>n;
  cout << "Enter the initial state of a switch : ";
  cin>>init_state;
  init_state = convertBinaryToGray(init_state);
  //cout << "Graycode of Initial State : " << init_state << "\n";
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  generateGrayCode(n);
  LL num = numToggles(n, init_state);
  gettimeofday(&tvalEnd,NULL);
  cout << "Minimum number of toggles needed to switch on the Bulb : " << num << "\n";
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  //printArr();
  return 0;
}
