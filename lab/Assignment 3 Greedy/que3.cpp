#include<bits/stdc++.h>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

struct activity
{
  int start, end;
};

typedef struct activity Activity;

bool cmpInc(Activity a1, Activity a2)
{
  return (a1.end < a2.end);
}

bool cmpDec(Activity a1, Activity a2)
{
  return (a1.start < a2.start);
}

int main(void)
{
  int n,count=0;
  cout << "Enter number of activites to be scheduled  : ";
  cin>>n;
  Activity arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i].start>>arr[i].end;
  }
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  sort(arr,arr+n,cmpInc);
  cout << "Activity 1 " << "(" << arr[0].start << ", "<< arr[0].end << ") runs \n";
  int currActivity = 0; //keep track of recently scheduled activity
  count++;
  for(int i=1;i<n;i++)
  {
    if(arr[i].start >= arr[currActivity].end)
    {
      cout << "Activity "<< i+1 << "(" << arr[i].start << ", "<< arr[i].end << ") runs \n";
      currActivity = i;
      count++;
    }
  }
  gettimeofday(&tvalEnd,NULL);
  cout << count << " Activities were successfully scheduled Using Greedy Technique\n";
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);


  //Greedy Technique 2
  struct timeval tvalStart1, tvalEnd1; //create struct timeval type variables
  gettimeofday(&tvalStart1,NULL);
  sort(arr, arr+n, cmpDec);
  count=0;
  cout << "Activity 1 " << "(" << arr[n-1].start << ", "<< arr[n-1].end << ") runs \n";
  currActivity = n-1; //keep track of recently scheduled activity
  count++;
  for(int i=n-2;i>=0;i--)
  {
    if(arr[i].end <= arr[currActivity].start)
    {
      cout << "Activity "<< n-i-1 << "(" << arr[i].start << ", "<< arr[i].end << ") runs \n";
      currActivity = i;
      count++;
    }
  }
  gettimeofday(&tvalEnd1,NULL);
  cout << count << " Activities were successfully scheduled Using Greedy Technique2\n";
  double time_taken1 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken1 =  (time_taken1 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken1 * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
