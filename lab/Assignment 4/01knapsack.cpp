//01knapsack Dynamic Programming
#include<iostream>
using namespace std;

struct item{
  int profit;
  int weight;
};

typedef struct item Item;

int max(int a, int b)
{
  return (a>b)? a:b;
}

int Knapsack01(Item arr[], int W, int n)
{
  int table[n+1][W+1];
  for(int i=0;i<=n;i++)
  {
    for(int w=0;w<=W;w++)
    {
      if(i == 0 || w == 0){ //if no items or Knapsack weight is 0
        table[i][w] = 0; //corresponding profit is 0
      }
      else if(arr[i-1].weight <= w) //ith object is present at index i-1
      {
        table[i][w] = max(arr[i-1].profit + table[i-1][w-arr[i-1].weight], table[i-1][w]);
      }
      else{ // if current object weight more than weight of Knapsack
        table[i][w] = table[i-1][w];
      }
    }
  }
  return table[n][W];
}

int main()
{
  int n,w;
  cout << "Enter the number of items : ";
  cin>>n;
  cout << "Enter the capacity of Knapsack : ";
  cin>>w;
  Item arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i].profit>>arr[i].weight;
  }
  cout << "Maximum Profit : " << Knapsack01(arr,w,n) << "\n";
  return 0;
}
