#include<bits/stdc++.h>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

struct lecture
{
  int start, end;
};

typedef struct lecture Lecture;

//sort in increasing order of start time
bool cmpInc(Lecture a1, Lecture a2)
{
  return (a1.start < a2.start);
}

int main(void)
{
  int n,count=0, flag=0;
  cout << "Enter number of lectures to be scheduled  : ";
  cin>>n;
  Lecture arr[n];
  vector< pair<int, pair<int,int> > > halls;
  //input all the lectures
  for(int i=0;i<n;i++)
  {
    cin>>arr[i].start>>arr[i].end;
  }
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  sort(arr,arr+n,cmpInc);
  int k = 1;//keep track of lectures
  int hallIndex=0; //keep track lectures hall in the array of halls
  halls.push_back(make_pair(k, make_pair(1, arr[0].end)));
  cout << "Lecture 1 " << "(" << arr[0].start << ", "<< arr[0].end << ") runs in  Hall " << halls[0].first << "\n";
  int currActivity = 0; //keep track of recently scheduled activity
  for(int i=1;i<=n-1;i++)
  {
      int Index = 0;
      flag = 0;
      for(int j=0;j<halls.size();j++)
      {
        if(halls[j].second.second < arr[i].start)
        {
          flag = 1;
          halls[j].second.first = 0;
          Index = j;
          //cout << Index << "\n";
          halls[Index].second.first = 1; //lecture arr[i] is being scheduled so set 1
          halls[Index].second.second = arr[i].end;
          cout << "Activity "<< i+1 << "(" << arr[i].start << ", "<< arr[i].end << ") runs in Hall " << halls[Index].first << "\n";
          currActivity = i;
        }
      }
    if(flag != 1){
      hallIndex++; //index of next hall
      k++; //next hall number
      halls.push_back(make_pair(k, make_pair(1 ,arr[i].end)));
      cout << "Activity "<< i+1 << "(" << arr[i].start << ", "<< arr[i].end << ") runs in Hall  " << halls[hallIndex].first << "\n";
      currActivity = i;
    }
  }
  gettimeofday(&tvalEnd,NULL);
  cout << n << " Activities were successfully scheduled Using Greedy Technique with halls " << halls.size() << "\n";
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
