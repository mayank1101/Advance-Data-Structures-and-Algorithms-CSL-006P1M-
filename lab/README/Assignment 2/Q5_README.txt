-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------

Implement MEDIAN-OF-THREE-PARTITION routine for Quicksort as discussed in the
class. Time the program on ten different randomly generated integer vectors of size 1024
each and time the programs. Analyze the result and document it.

-------------------------------------------------------------------------------------------------------------------------------------------------------
PROGRAMMING LANGUAGE USED : C/C++
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------
REQUIRED LIBRARIES:
-------------------------------------------------------------------------------------------------------------------------------------------------------

<iostream>
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
3.	Apply quick sort with variation in partition routine as Median of Three.
4.	Analyze the run time complexity this variation of quick sort. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Read the size of array as input from the user.
2.	Randomly generate the elements and store them in the input array.
3.	Apply quick sort with variation in partition routine as Median of Three.
4.	Here in MEDIAN-OF-THREE, we find the middle element and take median of start, mid and end positions to find the position of pivot element.
5.	Analyze the runtime complexity of this quick sort routine.

-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

i/p Size          Exection time of                
                  median partion(ms)                

  2048                  360            

  4096                  850                           

  5000                  950                            

  7000                  1599                         
  
  8192                  1820                         

  32768                 8264                      
 
  65536                 19106                     

  262144                95360                        
  
  1048576               799450               
              

------------------------------------------------------------------------
ANALYSIS:
------------------------------------------------------------------------
In above aoutput analysis we see that initially the algorithm is taking 
less time,
In general for the random input quick sort run with O(n log n) complexity.
But as we start increasing the the input size the median partition taking
signigficant time in n log n times approximately.

input 2048        -> 360 ms

input 4096(twice) -> 850 ms (around 2 times and above approximately nlog n)

input 8192(2 * 4096) -> 1820 ms 

here if we check as 8192 is twice of 4096 we should get 2 * n log n time 

2 * 4096 * 12 = 98304        here we can say they are approximately same
8192 * 13 = 106496           (considering some internal working of the 
                             cpu.)

so we can say that the time complexity is increasing n log n times.

------------------------------------------------------------------------
Chekcking with 1024 elements 10 times with random input
------------------------------------------------------------------------

 sr no.            Time Required
                      (in ms)
                  
   1                    724

   2                    767

   3                    870

   4                    874
 
   5                    771             

   6                    792         

   7                    745

   8                    827

   9                    785

   10                   804
------------------------------------------------------------------------

As we can see from the above outputs, there not much difference in the 
outputs for same size input.
In median of three elements partiotion method we actually randomly pick 
three elements and among them one meadian element is used as a pivot.
when we take pivot as this, the chances of getting a extreme element
which divide array in unbalanced way is less. even when we take median
of more elments say 7, 8, and so on this will take care of above issue.
As we are finding the medain between the selected elements it take 
some extra time to do this computation so time output is taking more
time than other partion techniques
