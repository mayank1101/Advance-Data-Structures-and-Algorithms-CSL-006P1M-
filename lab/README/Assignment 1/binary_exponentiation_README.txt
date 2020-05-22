BINARY EXPONENTIATION

Binary Exponentiation is used to computer a ^ n.

-------------------------------------------------------------------------------------------------------------------------------------------------------
REQUIRED LIBRARIES:
-------------------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<chrono>
#include<sys/time.h>
#include<iomanip>

-------------------------------------------------------------------------------------------------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
-------------------------------------------------------------------------------------------------------------------------------------------------------

OS:Ubuntu Linux (64 bit)
Processor: i3-7th generation @ 2.50GHz x 4

-------------------------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS:-
-------------------------------------------------------------------------------------------------------------------------------------------------------

To analyze the running time complexity of the binary exponentiationa and square and multiply techniques, two  integers are used as input : base and exponent.

-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1. Read the numbers form the input file.
   
------------------------------------------------------TIME PROGRAM USING CHRONO------------------------------------------------------------------------

2.	To time the program, instantiate time_point object using chrono to capture starting point time, and call the binary_exponent procedure.

3.	Call the time_point object to capture end point time. Take the difference between the start and end time_point to calculate the computation 		time of binary_exponent procedure.

3.	To time the program, instantiate time_point object using chrono to capture starting point time, and call the sqr_mul procedure.

4.	Call the time_point object to capture end point time. Take the difference between the start and end time_point to calculate the computation 		time of sqr_mul procedure.

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION (CRITIQUE):
-------------------------------------------------------------------------------------------------------------------------------------------------------
1. In case of binary exponentiation techinque we get O(logn) time complexity and for square and multiply technique is O(logn).

2. Comparing Binary Exponentiation and Square and Multiply Method.


-------------------------------------------------------------------------------------------------------------------------------------------------------   
			BINARY_EXPONENTIATION				|			SQUARE AND MULTIPLY METHOD
-------------------------------------------------------------------------------------------------------------------------------------------------------
									|
	INPUT SIZE	OUTPUT			TIME	Multiplications	|	INPUT SIZE	OUTPUT			TIME	Multiplications
									|
1.	2 10		1024			1	5		| 1.	2 10	`	1024			0	2
  									|
2.	5 10		9765625			1	5		| 2.	5 10		9765625			0	2
   									|
3.	15 15		315602166		1	7		| 3.	15 15		315602166		0	3
									|
4.	22 20		969164667		0	6		| 4.	22 20		969164667		1	2
									|
5.	25 30		449874206		1	8		| 5.	25 30		449874206		0	4
									|
6.	35 31		495863083		0	9		| 6.	35 31  		495863083		0	4
									|
7.	42 63		537561749		1	11		| 7.	42 63		537561749		0	6
									|
8.	48 127		49954709		0	13		| 8.	48 127		49954709		1	7
									|
9.	52 255		977347196		1	15		| 6.	52 255  	977347196		1	8
									|
10.	66 63		738479280		1	11		| 7.	66 63		738479280		0	5

-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------

On analyzing square and multiply algorithm, it can be observed that, this algorithm uses floor(logn) squarings and at most floor(logn)  multiplications. More accuratley, we can say the number of multiplications is one less than the number of 1's present in the binary expansion of n. Each squaring results in approximately double the number of digits of the previous, and so, if multiplication of two d-digit numbers is implemented in O(d^k) operations for some fixed k, then the complexity of computing x^n is given by O(n(logx)^k).

From the observations we can clearly see that with increase in the input size execution time grows in order of (logn) (approximately). Though slight deviation can be observed from the actual asymptotic behaviour because of following reasons : - 

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
