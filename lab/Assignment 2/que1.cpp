//create a binary tree using LevelOrder and find number of levels using divide and conquer
#include<iostream>
#include<queue>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

struct Node{
  int key;
  struct Node *left, *right;
  Node(int _key){
    this->key = _key;
    left = right = NULL;
  }
};

typedef struct Node Node;
typedef unsigned long long LL;

void randomInput(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    arr[i] = (rand() % n)+1;
  }
}

Node* insert(Node* root, LL data, queue<Node*>& q)
{
  //create a new node
  Node* newNode = new Node(data);
  //check if root is empty
  if(root == NULL){
    root = newNode;
  }
  //check for current node in queue
  else if(q.front()->left == NULL){
    q.front()->left = newNode;
  }
  else{
    q.front()->right = newNode;
    q.pop();
  }
  q.push(newNode);
  return root;
}

//Level Order Insertion
Node* LevelOrderInsert(LL arr[], LL n){
  Node* root = NULL;
  queue<Node*> q;
  for(LL i=0;i<n;i++){
    root = insert(root, arr[i], q);
  }
  return root;
}

LL countLevels(Node* root){
  if(root == NULL){
    return 0;
  }
  else if(root->left == NULL && root->right == NULL){
    return 1;
  }
  else{
    LL leftHeight = countLevels(root->left);
    LL rightHeight = countLevels(root->right);
    return (1 + ((leftHeight > rightHeight)? leftHeight: rightHeight));
  }
}

//Level Order traversal of Binary Tree
void LevelOrderTraversal(Node *root){
  if(root == NULL){
    cout << "Empty Binary Tree\n";
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    cout << q.front()->key << " ";
    if(q.front()->left != NULL){
      q.push(q.front()->left);
    }
    if(q.front()->right != NULL){
      q.push(q.front()->right);
    }
    q.pop();
  }
}

int main(void)
{

  LL n;
  cout << "Enter the number of nodes to be inserted : ";
  cin>>n;
  LL arr[n];
  randomInput(arr,n);
  Node* root = LevelOrderInsert(arr, n);
  LevelOrderTraversal(root);
  cout << "\n";
  struct timeval tvalStart, tvalEnd; //create struct timeval type variables
  gettimeofday(&tvalStart,NULL);
  LL numLevels = countLevels(root);
  gettimeofday(&tvalEnd,NULL);
  cout << "Number of Levels : " << numLevels << "\n";
  double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
  time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
  cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
  return 0;
}
