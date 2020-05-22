--------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT
--------------------------------------------------------------------------------------------------------------------------------------------------
A light bulb is connected to n switches in such a way that it lights up only when all the switches are closed. Each switch is controlled by a push button; pressing the button toggles the switch, but there is no way to know the state of the switch. Design an algorithm to turn on the light bulb with the minimum number of button pushes needed in the worst case. Use the concept of the Binary Gray codes and imagine the switches as a collection of bits, each bit representing a switch. Implement the program and analyse the time taken by your program to execute.

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

---------------------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS
---------------------------------------------------------------------------------------------------------------------------------------------------
1.	The number of switches to which the bulb is connected as n.
2.	The initial state of the n switches as input from user.

---------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
---------------------------------------------------------------------------------------------------------------------------------------------------
The problem can be solved by the following recursive algorithm for pushing the buttons numbered from 1 to n . If n = 1 and the light is off, push
button 1. If n > 1 and the light is off, apply the algorithm recursively to the first n − 1 buttons. If this fails to turn the light on, push button n and, if the light is still off, apply the algorithm to the first n − 1 buttons again.
The recurrence for the number of button pushes in the worst case is:
	M(n)=2M(n − 1) + 1 for n > 1 
	M(1) = 1 
Alternatively, since a switch can be in one of the two states, it can be thought of as a bit in an n-bit string in which 0 and 1 represent, say, the initial and opposite states of the switch, respectively. The total number of such bit strings (switch configurations) is equal to 2 n ; one of them represents an initial state, the remaining 2^n − 1 bit strings contain the one that will turn on the light bulb. In the worst case, all these 2^n-1 switch combinations will have to be checked. To accomplish this with the minimum number of button pushes, every push must produce a new
switch combination.
There are several algorithms that start with a bit string of n zeros and generate all the other 2^n − 1 bit strings by changing just a single bit at a time. The most well-known of them is the so-called binary reflected Gray code,

---------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION
---------------------------------------------------------------------------------------------------------------------------------------------------
S.No | No of bits | Initial state of switch  | No of set bits | Min no of button pushes | execution time    | Empirical time (assuming c=2.3/0.8)
     |            |                          |                |                         |                   | is 73.6 & 819.2 microseconds.Improvement
1    | 5          | 00000                    | 0              |          0              |  70 microseonds   | 1.05                        
2    | 5          | 00011                    | 2              |          3              |  60 mcroseconds   | 1.22
3    | 5          | 00111                    | 3              |          7              |  58 microseconds  | 1.26
4    | 5          | 01111                    | 4              |          15             |  72 microseconds  | 1.02
5    | 5          | 11111                    | 5              |          31             |  77 microseconds  | 0.95  
6    | 10         | 0000000000               | 0              |          0              |  723 microseconds | 1.13
7    | 10         | 0000000011               | 2              |          3              |  727 microseconds | 1.12
8    | 10         | 0000000111               | 3              |          7              |  733 microseconds | 1.11
9    | 10         | 0000011111               | 5              |          31             |  745 microseconds | 1.09 
10   | 10         | 1111111111               | 10             |          1023           |  764 microseconds | 1.07
---------------------------------------------------------------------------------------------------------------------------------------------------

1.	If there are N switches, there can be 2^N possible sets of 'required' as each switch can either be in or out of the 'required' set.

2.	From above we can irrespective of number of switches it's always taking same number of toggles to light up the bulb.But with the
	increase in number of switches the execution time is increasing, since the number of test cases that we need to search is increasing 
	exponentially with power of 2 for n bit string(n switches,assuming each switch as a bit in bit string sequence).

3.	This happens because initial state was unknown to us.If initial state were to be known we can bring this O(2^n) to O(n) where n will
	be number of attempts to check whether light bulb is on or off in worst case and O(log N) in best case.

4.	From above we can conclude that calculated execution time and empirical time both are close to each other.Also, if the number of switches
	are off more then the number of toggles will be more in worst case and time taken to enable these switches is almost same.

5.	If we take higher number of switches then also the number of toggles is same,this is due to gray code logic as we know that distance between
	any two code is 1 in gray code.So in order to change initial state to final position state we have to go through same cycle.Thus gray code is
	also know as cyclic code generator.The time taken to toggle buttons for large number of switches is more in comparison to lower number of 
	switches.

6.	We saw as increase number of switches to double then the time taken to light up the bulb increases to 10 times.Since 2^(2n) is 4^n .

7.	The performance of this algorithm is decreasing with the increase in input size, but not drastically. 
