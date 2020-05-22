#include<iostream>
#include <bits/stdc++.h>
#include<sys/time.h>
using namespace std;

typedef unsigned long long ULL;

//structure of AVL Tree Node
struct Node{
  ULL key, count, height;
  struct Node *left, *right;
  Node(ULL _key){
    key = _key;
    this->count = 1; //to handle duplicate elements
    this->height = 1;
    left = right = NULL;
  }
};
typedef struct Node Node;

// Declarations
void bubbleSort (ULL a []);
void insertionSort(ULL a []);
void mergeSort (ULL a [], ULL start, ULL end);
void mySort (ULL a []);
void semibubbleSort(ULL a[]);
void fillRandom (ULL a []);
void check (ULL a []);
ULL max(ULL x, ULL y);
ULL height(Node* node);
ULL getBalance(Node* node);
Node* leftRotate(Node* x);
Node* rightRotate(Node* y);
Node* insert(Node* node, ULL key);
Node* createTree(Node* root, ULL a[]);
void inOrder(Node* root, ULL a[]);
ULL N = 0; //number of elements in array
ULL indx = 0; //to fill array while inorder traversal

int main (void) {
  struct timeval starttime1 , endtime1, starttime2, endtime2, starttime3, endtime3, starttime4, endtime4,
  starttime5, endtime5; // for timing the sorts
  cout << "Enter the value of N : ";
  cin>>N;
  ULL a[N];
  fillRandom(a); //fill array with random values
  // time taken by bubbleSort
  gettimeofday(&starttime1, NULL);
  bubbleSort(a);
  gettimeofday(&endtime1, NULL);
  double time_taken1 = (endtime1.tv_sec - starttime1.tv_sec) * 1e6;
  time_taken1 =  (time_taken1 + (endtime1.tv_usec - starttime1.tv_usec)) * 1e-6;
  cout << "Bubble Sort Time : "<< fixed << time_taken1 << setprecision(8)  << " sec\n";
  check(a) ;

  //time taken by semi bubbleSort
  fillRandom(a);
  gettimeofday(&starttime5, NULL);
  bubbleSort(a);
  gettimeofday(&endtime5, NULL);
  double time_taken5 = (endtime5.tv_sec - starttime5.tv_sec) * 1e6;
  time_taken5 =  (time_taken5 + endtime5.tv_usec - starttime5.tv_usec) * 1e-6;
  cout << "Bubble Sort Time : "<< fixed << time_taken5 << setprecision(8)  << " sec\n";
  check(a) ;

  //time taken by insertionSort
  fillRandom(a);
  gettimeofday(&starttime2, NULL);
  insertionSort(a);
  gettimeofday(&endtime2, NULL);
  double time_taken2 = (endtime2.tv_sec - starttime2.tv_sec) * 1e6;
  time_taken2 =  (time_taken2 + (endtime2.tv_usec - starttime2.tv_usec)) * 1e-6;
  cout << "Insertion Sort Time : " << fixed << time_taken2 << setprecision(8)<< " sec\n";
  check(a) ;
  //time taken by mergeSort
  fillRandom(a);
  gettimeofday(&starttime3, NULL);
  mergeSort(a,0,N-1);
  gettimeofday(&endtime3, NULL);
  double time_taken3 = (endtime3.tv_sec - starttime3.tv_sec) * 1e6;
  time_taken3 =  (time_taken3 + (endtime3.tv_usec - starttime3.tv_usec)) * 1e-6;
  cout << "Merge Sort Time : " << fixed << time_taken3 << setprecision(8)<< " sec\n";
  check(a);
  //time taken by mysort
  fillRandom(a);
  gettimeofday(&starttime4, NULL);
  mySort(a);
  gettimeofday(&endtime4, NULL);
  double time_taken4 = (endtime4.tv_sec - starttime4.tv_sec) * 1e6;
  time_taken4 =  (time_taken4 + (endtime4.tv_usec - starttime4.tv_usec)) * 1e-6;
  cout << "My Sort Time : " << fixed << (time_taken4) << setprecision(8) << " sec\n";
  check(a);
  return 0;
}

//function to fill array with random numbers
void fillRandom(ULL a []){
  for(ULL i=0;i<N;i++){
    a[i] = (rand() % N)+1;
  }
}

//check for sorted array
void check(ULL a []){
  for(ULL i=0;i<N-1;i++){
    if (a[i] > a[i+1]){
      cout <<  "Failed to sort. See item : " << i  << "\n" ;
      return;
    }
  }
  cout << "Check passed" << "\n";
}

void swap(ULL* a, ULL* b){
  ULL temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(ULL a []){
  for(ULL i=0;i<N-1;i++){
    for(ULL j=0;j<N-i-1;j++){
      if(a[j+1] < a[j]){
        swap(&a[j],&a[j+1]);
      }
    }
  }
}

//Semi bubbleSort
void semiBubbleSort(ULL a[]){
  for(ULL i=0;i<N;i++){
    int flag = 0;
    for(ULL j=0;j<N-i-1;j++){
      if(a[j+1] < a[j]){
        swap(&a[j+1], &a[j]);
        flag = 1;
      }
    }
    if(!flag){ //if no swap occur in an iteration then the array is sorted break the loop
      break;
    }
  }
}

void insertionSort(ULL a[]){
  ULL j=0,key=0;
  for(ULL i=1;i<N;i++){
    key = a[i];
    j = i-1;
    while((j > 0) && (a[j] >= key)){
      a[j+1] = a[j];
      j--;
    }
    if(a[j] > key){
      a[j+1] = a[j];
    }
    a[j] = key;
  }
  return;
}

void merge(ULL a[], ULL start, ULL mid, ULL end){
  ULL n1,n2;
  n1 = mid-start+1; //size of left sub array
  n2 = end-mid; //size of right sub array
  ULL left[n1],right[n2];
  for(ULL i=0;i<n1;i++){
    left[i] = a[start+i];
  }
  for(ULL j=0;j<n2;j++){
    right[j] = a[mid+1+j];
  }
  ULL j=0,i=0,k=start;
  while(i < n1 && j < n2){ //filling auxillary array with sorted values
    if(left[i] <= right[j]){
      a[k++] = left[i++];
    }
    else{
      a[k++] = right[j++];
    }
  }
  while(i < n1){
    a[k++] = left[i++];
  }
  while(j<n2){
    a[k++] = right[j++];
  }
}

void mergeSort(ULL a [],ULL start, ULL end){
  if(start < end){
    ULL mid = start + (end-start)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a, start, mid, end);
  }
}

//find height of AVL Tree
ULL height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

//find max of two integers
ULL max(ULL x, ULL y)
{
    return ((x > y)? x : y);
}

//perfrom right rotation
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

//perform left rotation
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

//function to compute balance factor for a node
ULL getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return (height(node->left) - height(node->right));
}

//inseriton into AVL
Node* insert(Node* node, ULL key)
{
	//if empty root then insert new child just below it
  if (node == NULL)
		return(new Node(key));

    //if keys are equal
  if(node->key == key){
    node->count++;
    return node;
  }

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	//update height of this ancestor node
	node->height = 1 + max(height(node->left),
						height(node->right));
  //get the  balance factor this ancestor node and check for unbalanced condition
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// LL Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// RR Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// LR Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// RL Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	//return the (unchanged) node pointer
	return node;
}

//Create Tree from input array values
Node* createTree(Node* root, ULL a[])
{
  for(ULL i=0;i<N;i++){
    root = insert(root, a[i]);
  }
  cout << "\n";
  return root;
}

//In Order Tree Traversal
void inOrder(Node* root, ULL a[]){
  if(root == NULL){
    return;
  }
  inOrder(root->left, a);
  {
    if(root->count >=2){
      ULL temp = root->count;
      while(temp){
        a[indx++] = root->key;
        temp--;
      }
    }
    else{
      a[indx++] = root->key;
    }
  }
  inOrder(root->right, a);
}

//Improving Tree Sort by implementing AVL tree
void mySort(ULL a []){
  Node *root = NULL;
  root = createTree(root, a);
  inOrder(root, a);
}
