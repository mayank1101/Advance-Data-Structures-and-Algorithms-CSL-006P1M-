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

void swap(int *a, int *b)
{
  count++;
  int temp = *a;
  *a = *b;
  *b = temp;
}

void max_heapify(int arr[], int n, int parent_index)
{
  int largest = parent_index;
  int left_child_index = 2*parent_index+1;
  int right_child_index = 2*parent_index+2;
  if(left_child_index < n && arr[left_child_index] > arr[largest]){
    largest = left_child_index;
  }
  else if(right_child_index < n && arr[right_child_index] > arr[largest]){
    largest = right_child_index;
  }
  if(largest != parent_index){
    swap(&arr[largest], &arr[parent_index]);
    max_heapify(arr,n,largest);
  }
}

void heapSort(int arr[], int n)
{
  for(int i=n/2-1;i>=0;i--)
  {
    max_heapify(arr,n,i);
  }
  for(int i=n-1;i>=0;i--)
  {
    swap(&arr[i],&arr[0]);
    max_heapify(arr,i,0);
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
  auto start = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  heapSort(arr,10000); //invock heapSort
  auto end = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using chrono, Elapsed Time is : " << time_taken << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  auto start1 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  heapSort(arr,10000); //invock heapSort
  auto end1 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Number of swaps/exchanges : " << count << "\n";
  cout << "Using chrono, Elapsed Time is : " << time_taken1 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  auto start2 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  count=0;
  heapSort(arr,10000); //invock heapSort
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
