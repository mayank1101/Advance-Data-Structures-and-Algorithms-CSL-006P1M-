#include<iostream>
using namespace std;
#define N 20 //heap can never have more than  20 elements
//Global Variables
int heapstate = 0; // 0 = heap , 1 = maxheap , 2 = minheap
int heapsize = 0;// heap size
//utility function to swap two integer values
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


//print heap elements
void printHeap(int A[]){
  cout << "\nPrinting heap after operation\n";
  for(int i=0;i<heapsize;i++)
  {
    cout << A[i] << " ";
  }
  cout << "\n";
}

//helper function for make_max_heap
void maxHeapify(int A[], int node_index)
{
  int leftChild_index = 2*node_index+1;
  int rightChild_index = 2*node_index+2;
  int largest = node_index;
  if(leftChild_index < heapsize && A[leftChild_index] > A[largest])
  {
    largest = leftChild_index;
  }
  if(rightChild_index < heapsize && A[rightChild_index] > A[largest])
  {
    largest = rightChild_index;
  }
  if(largest != node_index){
    swap(&A[largest], &A[node_index]);
    maxHeapify(A, largest);
  }
}

//helper function for make_min_heap
void minHeapify(int A[], int node_index)
{
  int leftChild_index = 2*node_index+1;
  int rightChild_index = 2*node_index+2;
  int smallest = node_index;
  if(leftChild_index < heapsize && A[leftChild_index] < A[smallest])
  {
    smallest = leftChild_index;
  }
  if(rightChild_index < heapsize && A[rightChild_index] < A[smallest])
  {
    smallest = rightChild_index;
  }
  if(smallest != node_index){
    swap(&A[smallest], &A[node_index]);
    minHeapify(A, smallest);
  }
}

//helper function for insertion into min heap
void minHeapifyBottomUp(int A[], int node_index)
{
  int parent_index = (node_index-1)/2;
  if(parent_index > 0){
    if(A[node_index] < A[parent_index]){
      minHeapifyBottomUp(A, parent_index);
    }
  }
}

//healper function for insertion into maxheap
void maxHeapifyBottomUp(int A[], int node_index)
{
  int parent_index = (node_index-1)/2;
  if(parent_index > 0){
    if(A[node_index] > A[parent_index]){
      maxHeapifyBottomUp(A, parent_index);
    }
  }
}
void add(int A [], int val){
  if(heapsize == N){
    cout << "Heap capacity if full \n";
    return;
  }
  cout << "Heap Size " <<heapsize << "\n";
  heapsize = heapsize + 1;
  A[heapsize-1] = val;
  if(heapstate == 1)
  {
    maxHeapifyBottomUp(A, heapsize-1);
  }
  else if(heapstate == 2)
  {
    minHeapifyBottomUp(A, heapsize-1);
  }
  cout << "Added " << val;
  printHeap(A);
}

int extract(int A []){
  int elementToDelete = A[0];
  A[0] = A[heapsize-1];
  heapsize = heapsize-1;
  if(heapstate == 1){
    maxHeapify(A, 0);
  }
  else if(heapstate == 2){
    minHeapify(A, 0);
  }
  cout << "Extracting . . . . . . . .\n";
  return elementToDelete;
}

void make_max_heap(int A []){
  cout << "Making a max heap \n";
  int start_index = (heapsize/2)-1;
  for(int i=start_index;i>=0;i--)
  {
    maxHeapify(A, i);
  }
}

void make_min_heap(int A []){
  cout << "Making a min heap \n";
  int start_index = (heapsize/2)-1;
  for(int i=start_index;i>=0;i--)
  {
    minHeapify(A, i);
  }
}

//utility function for heapsort
void heapSortMaxHeapify(int A[], int heapsize, int node_index)
{
  int leftChild_index = 2*node_index+1;
  int rightChild_index = 2*node_index+2;
  int largest = node_index;
  if(leftChild_index < heapsize && A[leftChild_index] > A[largest])
  {
    largest = leftChild_index;
  }
  if(rightChild_index < heapsize && A[rightChild_index] > A[largest])
  {
    largest = rightChild_index;
  }
  if(largest != node_index){
    swap(&A[largest], &A[node_index]);
    heapSortMaxHeapify(A, heapsize, largest);
  }
}

void heapSortMinHeapify(int A[], int heapsize, int node_index)
{
  int leftChild_index = 2*node_index+1;
  int rightChild_index = 2*node_index+2;
  int smallest = node_index;
  if(leftChild_index < heapsize && A[leftChild_index] < A[smallest])
  {
    smallest = leftChild_index;
  }
  if(rightChild_index < heapsize && A[rightChild_index] > A[smallest])
  {
    smallest = rightChild_index;
  }
  if(smallest != node_index){
    swap(&A[smallest], &A[node_index]);
    heapSortMinHeapify(A, heapsize, smallest);
  }
}

void heapsort(int A[]){
  if(heapstate == 0 ){
    cout << "heap state 0\n";
  }
  else if(heapstate == 1) //max heap
  {
    for(int i=heapsize-1;i>=0;i--)
    {
      swap(&A[i], &A[0]);
      heapSortMaxHeapify(A, i, 0);
    }
  }
  else if(heapstate == 2){ //min heap
    for(int i=heapsize-1;i>=0;i--)
    {
      swap(&A[i], &A[0]);
      heapSortMinHeapify(A, i, 0);
    }
  }
}

int main (void)
{
  //initialize
  // Remember that our arrays start with index 1 .
  int A[N+1] = {0};
  string command = "";
  int val=0;
// for(int i=1;i<=N;i++){
//   A[i] = 0;
// }
//printHeap(A,N);
cout << "Enter the command text to be performed on Heap : ";
while(command != "end")
{
  cout << "Enter the command : \n";
  cout << "1. add\n";
  cout << "2. extract\n";
  cout << "3. neither\n";
  cout << "4. max\n";
  cout << "5. min\n";
  cout << "6. sort\n";
  cin>>command;
  if(command == "add"){
    // Add value to the end of the heap.
    //should maintain min heap property according to heap state
    cout << "Enter the value to be inserted : ";
    cin>>val;
    add(A, val);
    //print the heap after performing the operation
    // printHeap(A, heapsize);
  }
  else if(command == "extract"){
    // Should extract A[1] and maintain min heap property according to heap state
    cout << "Extracted " << extract(A) << "\n";
    //print the heap after performing the operation
    printHeap(A);
  }
  else if(command == "neither"){
    heapstate = 0;
    cout << "Heap state set to 0\n";
  }
  else if(command == "max"){
    heapstate = 1;
    make_max_heap(A);
    //print the heap after performing the operation
    printHeap(A);
  }
  else if(command == "min"){
    heapstate = 2;
    make_min_heap(A);
    //print the heap after performing the operation
    printHeap(A);
  }
  else if(command == "sort"){
    // Sort into increasing order if heap state = 1, and into decreasing order if heap state = 2 .
    heapsort(A);
    //print the heap after performing the operation
    printHeap(A);
  }
}
  return 0;
}
