INSERTION SORT

Insertion sort is a comparison based sorting technique.

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

To analyze the running time complexity of the algorithm,
three different input text file with aleast 10000 numbers 
is used.

1. averagecase_1000.txt : - Contains randomly generated 500 numbers.

2. worstcase_1000.txt   : - Contain 500 numbers sorted in decreasing order.

3. bestcase_1000.txt    : - Contain 500 numbers sorted in increasing order.

4. averagecase_1000.txt : - Contains randomly generated 1000 numbers.

5. worstcase_1000.txt   : - Contain 1000 numbers sorted in decreasing order.

6. bestcase_1000.txt    : - Contain 1000 numbers sorted in increasing order.

7. averagecase_5000.txt : - Contains randomly generated 5000 numbers.

8. worstcase_5000.txt   : - Contain 5000 numbers sorted in decreasing order.

9. bestcase_5000.txt    : - Contain 5000 numbers sorted in increasing order.

10. averagecase_20000.txt : - Contains randomly generated 20000 numbers.

11. worstcase_20000.txt   : - Contain 20000 numbers sorted in decreasing order.

12. bestcase_20000.txt    : - Contain 20000 numbers sorted in increasing order.


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Read the numbers form the input file.
   
------------------------------------------------------TIME PROGRAM USING CHRONO------------------------------------------------------------------------

2.	To time the program, instantiate time_point object using chrono to capture starting point time, and call the 
	insertion sort.

3.	Call the time_point object to capture end point time. Take the difference between the start and end time_point to calculate the computation 		time of insertion sort.

------------------------------------------------------TIME PROGRAM USING TIME_VAL----------------------------------------------------------------------


2.	To time the program, instantiate tv_usec object and call gettimeofday() method to capture starting point time, and call the insertion sort.

3.	Call the gettimeofday() method to capture end point time. Take the difference between the start and end times to calculate the computation 		time of insertion sort.

4.	Print the number of swaps and time taken for computation.  


-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION (CRITIQUE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	In case of insertion we get best time complexity in case of input which is already sorted in ascending order. O(n).

2.	In case of Descending order input gives worst case time complexity. O(n^2).

3.	Comparing chrono and time_val microsecond times.

-------------------------------------------------------------------------------------------------------------------------------------------------------   
			CHRONO (high_resolution_clock)			|			TIME_VAL (gettimeofday)
-------------------------------------------------------------------------------------------------------------------------------------------------------
									|
	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE	|	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE
									|
1.	1000		10		2002		3799		| 1.	1000	`	8		1638		3031
  									|
2.	5000		29		46224		85457		| 2.	5000		28		26244		52092
   									|
3.	10000		56		117393		225544		| 3.	10000		104		107671		209029		
									|
4.	20000		186		435100		900711		| 4.	20000		112		510485		874152
									|
5.	30000		165		987607		1879874		| 5.	30000		166		978026		1945981
									|
6.	40000		223		17351700	3519167		| 6.	40000		222		1728483		3472705
									|
7.	50000		276		2569928		5159522		| 7.	50000		279		2651380		5247642
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------------------------------------------------------   
								NUMBERS OF SWAPS
-------------------------------------------------------------------------------------------------------------------------------------------------------
					
	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE

1.	500		0		64122		124750
							
2.	1000		0		255128		499500		
  									
3.	5000		0		6246640		12497500		
   									
4.	10000		0		24888363	49995000		
									
5.	20000		0		99990206	199990000

6.	30000		0		225265258	449985000

7.	40000		0		400239691	799980000

8.	50000		0		623376325	1249975000	
									
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------


From the observations we can clearly see that with increase in the input size execution time squares (approximately). Though slight deviation
can be observed from the actual asymptotic behaviour because of following reasons : - 

1.	Execution time dependence on implementation of chrono and time_val library.

2.	CPU Time = Instruction_count * clock_per_instruction * clock_time. These parameter vary from system to system, because of difference in 	hardware configuration.

3.	Amount of storage space taken by the program. And design of program recursive program will take more space compared of iterative one.
	Though execution time is independet of whether program is recursive or iterative.

4.	Number of processes the program is parallely running along side the execution of our insertion sort program.

5.	Choice of Programming language : - Comparativly python and Java takes more time than c/C++. Here our choice of programming language
	is c/c++.

And there are many more factors affecting program execution time, but here our program is mainly affected by chrono and time_val library implementation because we are using them to time our programs. 

Chrono (high_resolution_clock)

The starting point of std::chrono:high_resolution_clock is the 1.1.1970, the so called UNIX-epoch. Chrono creates a time_point object, which expresses a point in time relative to a clock's epoch. This clock will only increase as the clock ticks every time with a constant rate relative to real time, unlike wall clock time which can jump forward and backward in time. In other words the clock will not be adjusted here.

Time_Val (gettimeofday)

In Time_Val, here we use gettimeofday() method. This method returns system-wide real time or wall clock time to the user. The problem with this is it isn't monotonic and also suffers from discontinous jumps. Here the time can move forwards or backwards depending upon the NTP. Therefore gettimeofday() method might result in incorrect timings if NTPD (Network Time protocol Daemon) want to synchronize the system time with time servers while executing your program resulting in increased or decreased execution time.
