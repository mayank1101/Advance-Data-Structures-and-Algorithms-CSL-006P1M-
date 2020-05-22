MERGE SORT

Merge sort is a comparison based sorting technique.

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

1. averagecase_500.txt : - Contains randomly generated 500 numbers.

2. worstcase_500.txt   : - Contain 500 numbers sorted in decreasing order.

3. bestcase_500.txt    : - Contain 500 numbers sorted in increasing order.

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

2.	To time the program, instantiate time_point object using chrono to capture starting point time, and call the merge sort.

3. 	Call the time_point object to capture end point time. Take the difference between the start and end time_point to calculate the computation 		time of merge sort.

------------------------------------------------------TIME PROGRAM USING TIME_VAL----------------------------------------------------------------------

2.	To time the program, instantiate tv_usec object and call gettimeofday() method to capture starting point time, and call the merge sort 		procedure.

3.	Call the gettimeofday() method to capture end point time. Take the difference between the start and end times to calculate the computation 		time of merge sort procedure.

4.	Print the number of swaps and time taken for computation.


-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION (CRITIQUE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	In case of merge sort we get O(nlogn) time complexity for random input, sorted increasing input, and sorted decresing input numbers.

2.	Comparing chrono and time_val microsecond times.

-------------------------------------------------------------------------------------------------------------------------------------------------------   
			TIME_VAL (gettimeofday)				|			CHRONO (high_resolution_clock)
-------------------------------------------------------------------------------------------------------------------------------------------------------
									|
	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE	|	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE
									|
1.	1000		220		374		223		| 1.	1000	`	160		273		160
  									|
2.	5000		932		1494		902		| 2.	5000		680		1141		682
   									|
3.	10000		1477		2318		1704		| 3.	10000		1571		3276		2033
									|
4.	20000		2891		4691		2965		| 4.	20000		3067		5576		3103
									|
5.	30000		4662		7685		4729		| 5.	30000		4659		7554		4708
									|
6.	40000		6360		10711		6300		| 6.	40000		6325		10344		6360
									|
7.	50000		7984		13535		7979		| 7.	50000		8109		13188		8085
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------------------------------------------------------   
								NUMBERS OF SWAPS
-------------------------------------------------------------------------------------------------------------------------------------------------------
					
	INPUT SIZE	BEST CASE	AVERAGE CASE	WORST CASE

							
1.	1000		9976		9976		9976		
  									
2.	5000		61808		61808		61808		
   									
3.	10000		133616		133616		133616		
									
4.	20000		287232		287232		287232
									
5.	30000		447232		447232		447232	

6.	40000		614464		614464		614464								
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------

From the observations we can clearly see that with increase in the input size execution time grows in order of (nlogn) (approximately). Though slight deviation can be observed from the actual asymptotic behaviour because of following reasons : - 

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
