#include<iostream>
#include<fstream>
#include<chrono> //for high_resolution_clock time
#include<iomanip> // for setting precision
using namespace std;

int *arr = new int[50000]; //global array

//function to read bestcase input file
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

//function to read worstcase input file
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

//function to read averagecase input file
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

void insertion_sort(){
  int num_swaps = 0; //count number of swaps
  for(int i=1;i<50000;i++){ //iterate through array eelemnts
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j] >= key){ //find correct position of key
      arr[j+1] = arr[j];
      num_swaps++;
      j--;
    }
    arr[j+1] = key;
  }
  cout << "number of swaps/exchanges for Inserion Sort: " << num_swaps << "\n";
}

// void printArr(){
//   for(int i=0;i<10000;i++){
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
  insertion_sort(); //invock insertion_sort
  auto end = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Using chrono, Elapsed Time is : " << time_taken << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  auto start1 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  insertion_sort(); //invock insertion_sort
  auto end1 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Using chrono, Elapsed Time is : " << time_taken1 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  auto start2 = chrono::high_resolution_clock::now(); //staring time_point object(reprsent point time)
  insertion_sort(); //invock insertion_sort
  auto end2 = chrono::high_resolution_clock::now(); //ending time_point
  double time_taken2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count(); //typecast duration into microseconds and use count member function to on duration object
  cout << "Using chrono, Elapsed Time is : " << time_taken2 << " micro seconds\n" << setprecision(9);
  cout << "<--------------------------------------------------------------->\n";
  std::time_t end_time2 = std::chrono::system_clock::to_time_t(end1); //get current system time
  cout << "finished computation on " << std::ctime(&end_time2);
  return 0;
}
