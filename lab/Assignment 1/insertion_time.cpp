#include<iostream>
#include<fstream>
using namespace std;

int *arr = new int[10000]; //global array

//function to read bestcase input file
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

//function to read worstcase input file
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

//function to read averagecase input file
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

void insertion_sort(){
  int num_swaps = 0; //count number of swaps
  for(int i=1;i<10000;i++){ //iterate through array eelemnts
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j] >= key){ //find correct position of key
      arr[j+1] = arr[j];
      num_swaps++;
      j--;
    }
    if(num_swaps == 0){ // if no swaps occurs then break, no need to iterate over rest elements
      break;
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
  insertion_sort(); //invock insertion_sort
  cout << "<--------------------------------------------------------------->\n";
  cout << "Worst Case : \n";
  readFileWorst(); //read data form file
  insertion_sort(); //invock insertion_sort
  cout << "<--------------------------------------------------------------->\n";
  cout << "Best Case : \n";
  readFileBest(); //read data form file
  insertion_sort(); //invock insertion_sort
  cout << "<--------------------------------------------------------------->\n";
  return 0;
}
