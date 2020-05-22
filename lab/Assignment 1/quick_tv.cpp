#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<iomanip>
#include<cstring>
using namespace std;

int *arr = new int[10000];
static int count;

void readFileBest(){
  ifstream File("bestcase.txt",ios::in); //create file object and open file to read
  if(File.is_open()){ // if file is open
    int x=0,i=0;
    while(File >> x){ // read integer from file one by one
      arr[i++] = x; //store read integer into array
    }
  }
  else{
    cout << "Unable to read from file\n";
  }
}

void readFileWorst(){
  ifstream File("worstcase.txt",ios::in); //create file object and open file to read
  if(File.is_open()){ // if file is open
    int x=0,i=0;
    while(File >> x){ // read integer from file one by one
      arr[i++] = x; //store read integer into array
    }
  }
  else{
    cout << "Unable to read from file\n";
  }
}

void readFileAverage(){
  ifstream File("averagecase.txt",ios::in); //create file object and open file to read
  if(File.is_open()){ // if file is open
    int x=0,i=0;
    while(File >> x){ // read integer from file one by one
      arr[i++] = x; //store read integer into array
    }
  }
  else{
    cout << "Unable to read from file\n";
  }
}

void swap(int *a, int *b){
  count++; //count keeps track of number of swaps/exchanges
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int start, int end){
  int pivot = arr[start];
  int i=start,j=start+1;
  for(;j<=end;j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[j],&arr[i]);
    }
  }
  swap(&arr[i],&arr[start]);
  return i;
}


void quickSort(int arr[],int start, int end){
  if(start < end){
    int pivot_pos = partition(arr, start, end);
    quickSort(arr, start, pivot_pos);
    quickSort(arr, pivot_pos+1, end);
  }
}

void printArr(int arr[], int n){
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main(void)
{
  cout << "<--------------------------------------------------------------->\n";
  cout << "Average Case : \n";
  readFileAverage(); //read data form file
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  gettimeofday(&tvalEnd,NULL);
  double time_taken = (tvalEnd.tv_usec - tvalStart.tv_usec);
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << time_taken << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  struct timeval tvalStart1, tvalEnd1;
  gettimeofday(&tvalStart1,NULL);
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  gettimeofday(&tvalEnd1,NULL);
  double time_taken1 = (tvalEnd1.tv_usec - tvalStart1.tv_usec);
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << time_taken1 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  struct timeval tvalStart2, tvalEnd2;
  gettimeofday(&tvalStart2,NULL);
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  gettimeofday(&tvalEnd2,NULL);
  double time_taken2 = (tvalEnd2.tv_usec - tvalStart2.tv_usec);
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << time_taken2 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";

  //get current system time
  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str)-1] = '\0';
  cout << "Finished computation on : " << time_str;
  return 0;
}
