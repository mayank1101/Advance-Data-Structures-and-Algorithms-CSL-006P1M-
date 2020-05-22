#include<iostream>
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

//Partition routine selects first element as pivot
LL partition1(LL arr[], LL start, LL end){
  LL pivot = arr[start];
  LL i = start+1; //keeps track of elements smaller than pivot
  for(LL j=start+1;j<=end;j++){
    if(arr[j] <= pivot){
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[start], &arr[i-1]);
  return (i-1);
}

//quickSort routine 1 with partition 1
void quickSort1(LL arr[], LL start, LL end){
  if(start < end){
    LL pivot_pos = partition1(arr, start, end);
    quickSort1(arr, start, pivot_pos-1);
    quickSort1(arr, pivot_pos+1, end);
  }
}

//Partition routine selects last element as pivot
LL partition2(LL arr[], LL start, LL end){
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
void quickSort2(LL arr[], LL start, LL end){
  if(start < end){
    LL pivot_pos = partition2(arr, start, end);
    quickSort2(arr, start, pivot_pos-1);
    quickSort2(arr, pivot_pos+1, end);
  }
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
  quickSort1(arr, 0, n-1);
  gettimeofday(&tvalEnd,NULL);
  cout << "Sorted array after quickSort1 : \n";
  for(LL i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  struct timeval tvalStart1, tvalEnd1; //create struct timeval type variables
  gettimeofday(&tvalStart1,NULL);
  quickSort2(arr2, 0, n-1);
  gettimeofday(&tvalEnd1,NULL);
  cout << "Sorted array after quickSort2 : \n";
  for(LL i=0;i<n;i++){
    cout << arr2[i] << " ";
  }
  double time_taken2 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken2 =  (time_taken2 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken2 * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
