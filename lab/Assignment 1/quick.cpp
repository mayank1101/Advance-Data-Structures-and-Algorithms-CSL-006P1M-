#include<iostream>
#include<fstream>
#include<chrono>
#include<iomanip>
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
  int i=start;
  for(j=start+1;j<=end;j++){
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
    quickSort(arr, start, pivot_pos-1);
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
  auto start = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  auto end = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using chrono, Elapsed Time is : " << time_taken << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  auto start1 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  auto end1 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using chrono, Elapsed Time is : " << time_taken1 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  auto start2 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  quickSort(arr,0,9999); //invock quickSort
  auto end2 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count(); //typecast duration into microseconds and use count member function to on duration object
  //printArr(); // print array
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using chrono, Elapsed Time is : " << time_taken2 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2); //get current system time
  cout << "finished computation on " << std::ctime(&end_time2);
  return 0;
}
