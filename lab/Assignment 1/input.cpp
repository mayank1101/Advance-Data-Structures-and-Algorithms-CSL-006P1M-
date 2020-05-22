#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

typedef unsigned long long int ULL;

void createFile(ULL arr[], ULL n){
  fstream File; //create a new file object
  File.open("averagecase_70000.txt",ios::out); // open file in out mode
  if(!File){
    cout << "Error in creating file\n";
  }
  else{
    cout << "File Successfully created\n";
    for(ULL i=0;i<n;i++){
      File << arr[i] << " ";
    }
    File.close(); //close file
  }
}

void BestCase(ULL arr[], ULL n)
{
  fstream File;
  File.open("bestcase_70000.txt",ios::out);
  if(!File)
  {
    cout << "Error in creating file\n";
  }
  else{
    cout << "File Successfully created\n";
    for(ULL i=0;i<n;i++){
      File << arr[i] << " ";
    }
    File.close();
  }
}

void WorstCase(ULL arr[], ULL n)
{
  fstream File;
  File.open("worstcase_70000.txt",ios::out);
  if(!File)
  {
    cout << "Error in creating file\n";
  }
  else{
    cout << "File Successfully created\n";
    for(ULL i=0;i<n;i++){
      File << arr[i] << " ";
    }
    File.close();
  }
}

int main(void){
  ULL n;
  cout << "Enter the input size for test cases : ";
  cin>>n;
  ULL arr[n];
  //random generating number between 1 to 100
  for(ULL i=0;i<n;i++){
    arr[i] = (rand() % n)+1;
  }
  createFile(arr,n);

  //Sorted in incresing order
  for(ULL i=0;i<n;i++){
    arr[i] = i+1;
  }
  BestCase(arr,n);

  //sorted in decreasing order
  for(ULL i=0;i<n;i++){
    arr[i] = n-i;
  }
  WorstCase(arr,n);
  return 0;
}
