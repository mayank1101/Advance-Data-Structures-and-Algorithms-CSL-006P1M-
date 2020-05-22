#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<iomanip>
#include<cstring>
using namespace std;

int *arr = new int[50000]; // global array
static int count; //global count variable to count number of swaps

void readFileBest(){
  ifstream File("bestcase_50000.txt",ios::in); //create file object and open file to read
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
  ifstream File("worstcase_50000.txt",ios::in); //create file object and open file to read
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
  ifstream File("averagecase_50000.txt",ios::in); //create file object and open file to read
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

void merge(int arr[], int start, int mid, int end){
  int n1 = mid-start+1; // size of left sub array
  int n2 = end-mid; // size of right sub array
  int left[n1];
  int right[n2];
  for(int i=0;i<n1;i++){
    left[i] = arr[start+i];
  }
  for(int j=0;j<n2;j++){
    right[j] = arr[mid+1+j];
  }
  int i=0,j=0,k=start; // k index elements in final array
  while(i < n1 && j < n2){
    if(left[i] <= right[j]){
      arr[k] = left[i++];
      count++;
    }
    else{
      arr[k] = right[j++];
      count++;
    }
    k++;
  }
//copy remaning elements form left sub array if there
  while(i < n1){
    arr[k++] = left[i++];
    count++;
  }
//copy remaning elements form right sub array if there
  while(j < n2){
    arr[k++] = right[j++];
    count++;
  }
}


void mergeSort(int arr[], int start, int end)
{
  if(start < end){
    int mid = start + (end - start)/2; //divide problem into two sub problems
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end); //merge sub problems to get result of bigger problem
  }
}

// void printArr(int arr[], int n){
//   for(int i=0;i<n;i++){
//     cout << arr[i] << " ";
//   }
//   cout << "\n";
// }


int main(void)
{

  cout << "<--------------------------------------------------------------->\n";
  cout << "Average Case : \n";
  readFileAverage(); //read data form file
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  count=0;
  mergeSort(arr, 0, 49999); //invock mergeSort
  gettimeofday(&tvalEnd,NULL);
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  struct timeval tvalStart1, tvalEnd1;
  gettimeofday(&tvalStart1,NULL);
  count=0;
  mergeSort(arr, 0, 49999); //invock mergeSort
  gettimeofday(&tvalEnd1,NULL);
  double time_taken1 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken1 =  (time_taken1 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken1 * 1e6) << " micro seconds\n" << setprecision(6);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  struct timeval tvalStart2, tvalEnd2;
  gettimeofday(&tvalStart2,NULL);
  count=0;
  mergeSort(arr, 0, 49999); //invock mergeSort
  gettimeofday(&tvalEnd2,NULL);
  double time_taken2 = (tvalEnd2.tv_sec - tvalStart2.tv_sec) * 1e6;
  time_taken2 =  (time_taken2 + tvalEnd2.tv_usec - tvalStart2.tv_usec) * 1e-6;
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken2 * 1e6) << " micro seconds\n" << setprecision(6);
  cout << "<--------------------------------------------------------------->\n";

  //get current system time
  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str)-1] = '\0';
  cout << "Finished computation on : " << time_str;
  return 0;
}
