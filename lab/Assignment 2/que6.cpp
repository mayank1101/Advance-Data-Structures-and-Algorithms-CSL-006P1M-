#include<iostream>
#include<cstdlib>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

typedef unsigned long long LL;

void randomInput(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    arr[i] = (rand() % n)+1;
  }
}

void sortedInput(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    arr[i] = i+1;
  }
}

void reverseSortedInput(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    arr[i] = n-i;
  }
}

void swap(LL *a, LL *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Partition routine selects last element as pivot
LL partition(LL arr[], LL start, LL end){
  LL pivot = arr[end];
  LL i,j;
  i = start-1; //keeps track of elements smaller than pivot
  for(j=start;j<=end-1;j++){
    if(arr[j] <= pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[end]);
  return (i+1);
}

//quickSort routine 2 with partition 2
void quickSort(LL arr[], LL start, LL end){
  if(start < end){
    srand(time(NULL));
    LL random_pivot_pos = start + rand() % (end - start);
    swap(&arr[random_pivot_pos], &arr[end]);
    LL pivot_pos = partition(arr, start, end);
    quickSort(arr, start, pivot_pos-1);
    quickSort(arr, pivot_pos+1, end);
  }
}

void printArr(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main(void)
{
  LL n;
  cout << "Enter the number the size of array :";
  cin>>n;
  LL arr[n];
  LL arr2[n];
  randomInput(arr, n);
  randomInput(arr2, n);
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  quickSort(arr, 0, n-1);
  gettimeofday(&tvalEnd,NULL);
  printArr(arr,n);
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
