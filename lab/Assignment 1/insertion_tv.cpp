#include<iostream>
#include<fstream>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

int *arr = new int[50000]; //global array
static int num_swaps = 0;

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
  //int num_swaps = 0; //count number of swaps
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
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  num_swaps = 0;
  insertion_sort(); //invock insertion_sort
  gettimeofday(&tvalEnd,NULL);
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  //printArr();
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  struct timeval tvalStart1, tvalEnd1;
  gettimeofday(&tvalStart1,NULL);
  num_swaps = 0;
  insertion_sort(); //invock insertion_sort
  gettimeofday(&tvalEnd1,NULL);
  double time_taken1 = (tvalEnd1.tv_sec - tvalStart1.tv_sec) * 1e6;
  time_taken1 =  (time_taken1 + tvalEnd1.tv_usec - tvalStart1.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken1 * 1e6) << " micro seconds\n" << setprecision(6);
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  struct timeval tvalStart2, tvalEnd2;
  gettimeofday(&tvalStart2,NULL);
  num_swaps = 0;
  insertion_sort(); //invock insertion_sort
  gettimeofday(&tvalEnd2,NULL);
  double time_taken2 = (tvalEnd2.tv_sec - tvalStart2.tv_sec) * 1e6;
  time_taken2 =  (time_taken2 + tvalEnd2.tv_usec - tvalStart2.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken2 * 1e6) << " micro seconds\n" << setprecision(6);
  cout << "<--------------------------------------------------------------->\n";
  //get current system time
  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str)-1] = '\0';
  cout << "Finished computation on : " << time_str;
  return 0;
}
