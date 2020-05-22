-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------

Implement Probabilistic-Quicksort routine discussed in the class. Time the program on ten
different randomly generated integer vectors of size 1024 each and time the programs. Analyze
the result and document it.

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
3.	Apply quick sort with variation in partition routine as randomly select the pivot element.
4.	Analyze the run time complexity this variation of quick sort. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Read the size of array as input from the user.
2.	Randomly generate the elements and store them in the input array.
3.	Apply quick sort with variation in partition routine as randomly select the pivot element.
4.	Analyze the runtime complexity of this quick sort routine.

-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

i/p Size          Exection time of                
                  median partion(ms)                

  2048                  1100            

  4096                  3001                          

  5000                  4100                            

  7000                  6500                         
  
  8192                  9000                         

  32768                 79741                      
 
  65536                 234501                     

  262144                1544784                        
  
  1048576               12696195  

------------------------------------------------------------------------
ANALYSIS:
------------------------------------------------------------------------
In above aoutput analysis we see that initially the algorithm is taking 
less time,
In general for the random input quick sort run with O(n log n) complexity.
But as we start increasing the the input size the median partition taking
signigficant time in n log n times approximately.

input 2048        -> 1100 ms

input 4096(twice) -> 3001 ms (around 2 times and above approximately nlog n)

input 8192(2 * 4096) -> 9000 ms 

This type of the partion method is suprisingly taking very high time as 
compared to the other partion routines.

so we can say that the time complexity is increasing n log n times.

------------------------------------------------------------------------
Chekcking with 1024 elements 10 times with random input
------------------------------------------------------------------------

 sr no.            Time Required
                      (in ms)
                  
   1                    254

   2                    238            

   3                    209

   4                    1281
 
   5                    941       

   6                    296    

   7                    234

   8                    261

   9                    285

   10                   1181
------------------------------------------------------------------------

In above we have given 1024 element input 10 times, we can see that there
are 3 outputs which are taking significant more time than that of others.
other all outputs are in the range of 230-290 ms mostly.
