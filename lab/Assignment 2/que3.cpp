//counting number of inversions in an array using brute force and merge procedure
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

//Brute Force Method for counting number of inversions
LL BruteForceCount(LL arr[], LL n){
  LL inv_count=0;
  for(LL i=0;i<n-1;i++){
    for(LL j=i+1;j<n;j++){
      if(arr[i] > arr[j]){
        inv_count++;
      }
    }
  }
  return inv_count;
}

LL merge(LL arr[], LL temp[], LL start, LL mid, LL end){
  LL inv_count=0;
  LL i,j,k;
  i = k = start;
  j = mid;
  while((i <= mid-1) && (j <= end)){
    if(arr[i] <= arr[j]){
      temp[k++] = arr[i++];
    }
    else{
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid-i);
    }
  }
  //copy remaning elements from left sub array
  while(i <= mid-1){
    temp[k++] = arr[i++];
  }
  //copy remaning elements from right sub array
  while(j <= end){
    temp[k++] = arr[j++];
  }
  for(LL i=start;i<=end;i++){
    arr[i] = temp[i];
  }
  return inv_count;
}

LL mergeSort(LL arr[], LL temp[], LL start, LL end){
  LL inv_count=0;
  if(start < end){
    LL mid = start + (end - start)/2;
    inv_count = mergeSort(arr, temp, start, mid);
    inv_count += mergeSort(arr, temp, mid+1, end);
    inv_count += merge(arr, temp, start, mid+1, end);
  }
  return inv_count;
}

int main(void)
{
  LL n;
  cout << "Enter the number the size of array :";
  cin>>n;
  LL arr[n];
  reverseSortedInput(arr, n);
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  LL inv_count1 = BruteForceCount(arr,n);
  gettimeofday(&tvalEnd,NULL);
  cout << "Number of Inversions using Brute Force Method : "<< inv_count1 << "\n";
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  LL temp[n];
  struct timeval tvalStart1, tvalEnd1; //create struct timeval type variables
  gettimeofday(&tvalStart1,NULL);
  LL inv_count2 = mergeSort(arr, temp, 0, n-1);
  gettimeofday(&tvalEnd1,NULL);
  cout << "Number of Inversions using Merge Sort merge Procedure : "<< inv_count2 << "\n";
  double time_taken2 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken2 =  (time_taken2 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken2 * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
