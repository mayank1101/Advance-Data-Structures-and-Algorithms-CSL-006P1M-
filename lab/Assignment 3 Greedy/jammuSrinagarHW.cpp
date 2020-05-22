//Jammu - Srinagar Highway Billboard Problem Dynamic Programming
#include<iostream>
#include<cstring>
using namespace std;

struct billboards{
  int position; //position of billboard measured in miles from one end of road
  int revenue; //revenue from the billboard placed at position pos
};

typedef struct billboards Billboards;

int max(int a, int b){
  return((a>b)?a:b);
}

int maxRevenue(Billboards arr[], int n, int length, int range){
  int maxRevTable[length+1];
  memset(maxRevTable,0,sizeof(maxRevTable));
  int indextoBBPos=0; //index to the position of next billboard
  for(int m=1;m<=length;m++)
  {
    if(indextoBBPos < n){ // position of current billboard is within length of highway
      if(arr[indextoBBPos].position != m){
        maxRevTable[m] = maxRevTable[m-1];
      }
      else{
        if(m < range){ //current billboard position is within the range
          maxRevTable[m] = max(maxRevTable[m-1], arr[indextoBBPos].revenue);
        }
        else{ //remove previously placed billboard within range
          maxRevTable[m] = max(maxRevTable[m-range-1] + arr[indextoBBPos].revenue, maxRevTable[m-1]);
        }
        indextoBBPos++; //process next billboard
      }
    }
    else{ //no more billboards to place
      maxRevTable[m] = maxRevTable[m-1];
    }
  }
  return maxRevTable[length];
}

int main()
{
  int length,n,range;
  cout << "Enter the length of highway in miles : ";
  cin>>length;
  cout << "Enter the number of billboards to be placed on the heighway : ";
  cin>>n;
  cout << "Enter the range within which no two billboards can be placed : ";
  cin>>range;
  Billboards arr[n]; //array to store all the positions and corresponding revenue for each billboard
  for(int i=0;i<n;i++){
    cout << "Enter the position and associated revenue for billboard : ";
    cin>>arr[i].position>>arr[i].revenue;
  }
  cout << "Maximum Revenue : " << maxRevenue(arr,n,length,range) << "\n";
  return 0;
}
