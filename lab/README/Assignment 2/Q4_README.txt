-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------

Observe that the algorithm PARTITION() for Quicksort given in the text is different from
the one discussed in the class. Implement two different Quicksort routines that use the two
different PARTITION routines. Test your implementation on an input vector of size at least
a 2048 integers and time the programs. Analyze the result and document it.

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
2.	Randomly generate elements and store them into array.
3.	Apply 2 diffirent variations of quicksort.
4.	Analyze the run time complexity these two variation of quick sort. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Read the size of array as input from the user.
2.	Randomly generate the elements and store them in the input array.
3.	Call QuickSort1 routine whose partition selects first element as pivot.
4.	Analyze the runtime complexity of this routine QuickSort1.
5.	Call QuickSort2 routine whose partition selects last element as pivot.
6.	Analyze the runtime complexity of this routine QuickSort2.

-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

Our final Output is 
1. Time Taken by QuickSort1
2. Time taken by QuickSort2

Comparison table:

-------------------------------------------------------------------------------------------------------------------------------------------------------									                       
Input		Time taken By QuickSort1 Routine		  |		Time taken by QuickSort2 Routine
-------------------------------------------------------------------------------------------------------------------------------------------------------				    									  |	
1. 10	    	    2 Microseconds				  |			2 Microseconds	
				        			  |
2. 100      	    24 Microseconds				  |			24 Microseconds 
				  				  |	
3. 1000     	    434 Microseconds				  |			439 Microseconds 
				        			  |
4. 10000    	    4106 Microseconds				  |			3884 Microseconds 
				        			  |	
5. 100000         50994 Microseconds	  			  |			53913 Microseconds 
	    			        			  |	
6. 1000000 	  558793 Microseconds				  |			682778	Microseconds 
	    			        			  |	
7. 10000000 	  6036925 Microseconds				  |			18647263 Microseconds 
								  |
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION
-------------------------------------------------------------------------------------------------------------------------------------------------------

In this Assignment we have two Partition algorithm  for Quick sort we have used them on same vector and as we can see them they both 
give the Asymptotic time complexity of O(nlogn) on an average case but QuickSort1 is 3.0889 times faster than our QuickSort2 but for this Size of vector has to be Size>10000000 as per My laptop becouse it is empirical analysis so it very from System to system.
