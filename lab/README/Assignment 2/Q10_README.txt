-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------

Implement the Counting sort covered in the class and analyze the running time of your code

-------------------------------------------------------------------------------------------------------------------------------------------------------
PROGRAMMING LANGUAGE USED : C/C++
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------
REQUIRED LIBRARIES:
-------------------------------------------------------------------------------------------------------------------------------------------------------

<iostream>
<fstream>
<iomanip>
<chrono>
<sys/time.h>
<cstring>

-------------------------------------------------------------------------------------------------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

OS:Ubuntu Linux (64 bit)
Processor: i3-7th generation @ 2.50GHz x 4

-------------------------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS:-
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	We take size of array as input from the user.
2.	We take range of input elements [0:n] from the user.
2.	Randomly generate elements within the range [0:n] and store them into array.
3.	Apply the procedure counting sort.
4.	Analyze the run time complexity. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	We take size of array as input from the user.
2.	We take range of input elements [0:n] from the user.
2.	Randomly generate elements within the range [0:n] and store them into array.
3.	Create a count array to store the count of all the arrays elements and output array to store the final sorted elements.
4.	Analyze the run time complexity. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

Our final Output is 
1. Time taken by count sort

-------------------------------------------------------------------------------------------------------------------------------------------------------

 Input Range.            Time Required
                      	 
                  
   [0:10]                  46.000000 micro seconds

   [0:20]                  43.000000 micro seconds          

   [0:30]                  52.000000 micro seconds

   [0:50]                  51.000000 micro seconds       

   [0:100]                 72.000000 micro seconds    

   [0:300]                 93.000000 micro seconds

   [0:500]                 194.000000 micro seconds

   [0:700]                 274.000000 micro seconds

   [0:1000]                75.000000 micro seconds
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key 		values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

2.	The problem with the previous counting sort was that we could not sort the elements if we have negative numbers in it. Because there are no 		negative array indices

3.	Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
	Auxiliary Space: O(n+k)
