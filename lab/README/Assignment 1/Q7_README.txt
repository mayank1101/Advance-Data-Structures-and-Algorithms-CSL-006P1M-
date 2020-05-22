My Sort

-------------------------------------------------------------------------------------------------------------------------------------------------------
REQUIRED LIBRARIES:
-------------------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<sys/time.h>

-------------------------------------------------------------------------------------------------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

OS:Ubuntu Linux (64 bit)
Processor: i3-7th generation @ 2.50GHz x 4

-------------------------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS:-
-------------------------------------------------------------------------------------------------------------------------------------------------------
The given program takes number of array elements N as command line argumnet. use fillRandom() function to fill the array with random elements. And on the array of random elements, following sorting algorithms are called and timed: -

1. Bubble Sort
2. Insertion Sort
3. Merge Sort
4. My Sort   

-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1. The program takes as input, the number of array elemnts from command line argument. And using fillRandom(), array is filled with random elements.
2. Different sorting algorithms Bubble Sort, Insetion Sort, Merge Sort is called upon this array and their execution is timed using time_val library.
3. Here mySort algorithm is basically a variation of Tree Sort algorithm, in an attempt to imporve over performance of merge sort. 
3. Based on hit and trial input N is determined for which these sorting algorithms will take not more than 10 seconds.
4. A variant of bubble sort, that is "semibubbleSort" is programmed to improve the Bubble sort by factor of 2. 

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION:
-------------------------------------------------------------------------------------------------------------------------------------------------------

When the program is run over different inputs, it can be clearly observed that with increase in the input size,the sorting algorithms bubble sort, inserion sort, and merge sort exhibits their theoritically computed asymptotic behaviour i.e with increase in the input size, their time complexity grow as O(n^2), O(n^2), and O(nlogn) respectively.

The maximum input for which the each sorting algorithms take not more than 10sec are as follows : -
  
1) Bubble sort can give output in less than 10 sec for input of size upto 45000 elements.
2) Insertion sort can give output in less than 10 sec for input of size upto 100000 elements.
3) Semi Bubble sort can give output in less than 10 sec for input of size upto 47000 elements.


Semibubble Sort:
This semibubble sort is a variation of bubble sort with an attempt to improve the time complexity by factor of 2. bubble sort iterate over array always from left to right, placing largest element to its correct position, then in next iteration, it places second largest element to its correct postion. Where as this semi bubble sort, runs in both the directions alternatively, that is left to right in first iteration, then right to left in second iteration, then again left to right followed by right to left. And this process goes on untill the complete array is sorted. This algothim runs in two stages : -

Stage 1: 
The first stage this algorithm loops through the array from left to right, just like the normal bubble sort. During iteration, adjacent items are compared and if they are out of order, then the items are swapped. At the end of first iteration, largest number will be present at its correct postion.

Stage 2:
The second stage the algorithm loops through the array in opposite direction. That is, it starts from the item just before the most recently sorted item, and moving back to the start of the array. while iterating, adjacent items are compared and if found out of order, then  they are swapped.


MyOwnSort:
myownsort is a variation of existing sorting algorithm in an attempt to improve upone the performance of the merge sort. Here Tree sort, an existing sorting algorithm is taken, which is then improved to beat the performance of merge sort.

Tree Sort : -
This algorithm, constructs a binary search tree from the input array elements and then appy inorder traversal on the tree to get sorted result.
This algorithm takes time on an average O(nlogn), but in worst case it takes O(n^2).

Time Complexity = Insertion Time + Inorder traversal time.

Wrost Case = O(n^2) + O(n) = O(n^2)

The worst case can be improved upon by using AVL tree, instead of Binary Search Tree.

Since AVL or BST tree generally deals with distinct elements, but here our array can contain duplicate elements as well. So to handle duplicate elements we can use we can modify the structure of BST node, and store key along with its count.

Node structure of AVL

struct Node{
	int key;
	int height;
	struct Node* left, right;
};
  

Modified Node Structure

struct Node{
	int key;
	int height;
	int count;
	struct Node* left, right;
};

Modified Tree Sort : -

The algorithm now constructs an AVL tree, and the apply inorder traversal to get sorted order of elements. Here worst case time complexity is O(nlogn).

Time Complexity = Insertion Time + Inorder traversal time.

Wrost Case = O(nlogn) + O(n) = O(nlogn)

The algorithm performs comparable to merge sort, but not better than merge sort.

