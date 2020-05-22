-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------
Design a divide-and-conquer algorithm for computing the number of levels in a binary tree.
(In particular, the algorithm must return 0 and 1 for the empty and single-node trees, respectively.)
Analyze the time efficiency class of your algorithm. Now, implement the algorithm
you designed and find out the time taken an for empty, one-level, two-level and three-level
binary tree. Compare it with the theoretical analysis that you would have done before.

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
<queue>

-------------------------------------------------------------------------------------------------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

OS:Ubuntu Linux (64 bit)
Processor: i3-7th generation @ 2.50GHz x 4

-------------------------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS:-
-------------------------------------------------------------------------------------------------------------------------------------------------------

In this program we have made random function which will give use the random value it will ask us the no of Nodes and It will give us 
array of that much no. and we are going to give that array to our Insert function it will insert it into our tree as Level order tree 
or we can say almost complete binary tree and we are going to perform our operations on binary tree. 

-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

Final Output for the given program is : - 
1. No of level in a binary tree and Time taken by our algorithm to count it.
2. Time taken by 0 level tree
3. Time taken by 1 level tree
4. Time taken by 2 level tree
5. Time taken by 3 level tree

-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Read the numbers form the input file.

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION (CRITIQUE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

----Input---No of Level and Time taken--|-------0 LEVEL-----------|---------1 Level------------|-----2 Level----------|------3 Level-------------------
				    	|			  |			       |		      |
1. 10    Level=4   31867 Nanoseconds    | 22101 Nanoseconds    	  |  	  25 Nanoseconds       |   25 Nanoseconds     |	  25 Nanoseconds	
				        |			  |			       |		      |
2. 100   Level=7   22632 Nanoseconds    |  25493 Nanoseconds      |  	  29 Nanoseconds       |   16 Nanoseconds     |   31 Nanoseconds 
				        |			  |			       |		      |
3. 1000  Level=10  19989 Nanoseconds    |  27021 Nanoseconds      |   	  28 Nanoseconds       |   25 Nanoseconds     |   32 Nanoseconds 
				        |			  |			       |		      |
4. 10000 Level=14  27679 Nanoseconds    |  18953 Nanoseconds	  |  	  29 Nanoseconds       |   26 Nanoseconds     |   25 Nanoseconds 
				        |			  |			       |		      |	
5. 100000 Level=17 29381 Nanoseconds    |  28091 Nanoseconds      |       24 Nanoseconds       |   24 Nanoseconds     |   26 Nanoseconds 
	    			        |			  |			       |		      |
6. 10000000 Level=20 30523 Nanoseconds  |  27289 Nanoseconds      |       24 Nanoseconds       |   25 Nanoseconds     |   25 Nanoseconds 
-------------------------------------------------------------------------------------------------------------------------------------------------------	

								


In this Assignment we have taken almost complete or level order Binary tree so in worst case its height is going to be 
log(n) where n is no of nodes and to find out the the levels in almost complete binary tree by our algorithm T.C is O(log(n))
because we have to go to only left side of the tree to find out out the level of our binary tree.

Our program is taking more time to count 0 level than to count 1,2,3 level.
