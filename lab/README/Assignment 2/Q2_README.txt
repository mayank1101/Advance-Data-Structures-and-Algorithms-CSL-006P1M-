------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT
------------------------------------------------------------------------------------------------------------------------------------
Implement the Strassen’s matrix multiplication algorithm.Test your program on matrices of 
different sizes and time your program. As the matrix size becomes smaller, does the 
algorithm yield efficiency better than the brute force ? If yes, argue how is it so and 
show it with consistent results. If NO, there must be a crossover point beyond which 
the Strassen’s algorithm yields better efficiecny as compared to the bruteforce method.
Run an experiment to determine such a crossover point on your computer system.

--------------------------------------------------------------------------------------------------------------------------------------
REQUIRED LIBRARIES
--------------------------------------------------------------------------------------------------------------------------------------
<stdio.h>
<stdlib.h>
<time.h>
<sys/time.h>
<chrono>

--------------------------------------------------------------------------------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
--------------------------------------------------------------------------------------------------------------------------------------
OS:Kali GNU/linux Rolling(64 bit)
Processor: i5-7200U CPU @ 2.50GHz x 4

---------------------------------------------------------------------------------------------------------------------------------------
INPUT PARAMETERS
---------------------------------------------------------------------------------------------------------------------------------------
The complexity of matrix multiplication using the classic method(using 3 for loops) is O(n 3 ). But there are other algorithms which 
have a lower complexity than O(n^3).Strassen's algorithm achieves a lower complexity by using 7 multiplications, instead of 8, as is
used in the traditional 3 loop matrix multiplication.

->For input we are taking size of an array from user.We are creating three matrix N*N matrix using rand() function,since C(N*N)=A(N*N).B
(N*N).For Strassen's if size is less than recursion limit then we are calculating submatrices value using conventional method because for
small size input conventional method takes less time than strassen's else we will use strassen's method of calculation.

Strassen's multiplication takes 7 as multiplier in comparison to conventional method which takes 8 as multiplier.This 1 mulitplication
difference causes drastic change in time complexity from O(n^3) to O(n^2.81).

---------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION
----------------------------------------------------------------------------------------------------------------------------------------
S.No| Matrix-size(N*N)| Strassen's execution time-O(n^2.81) |Recursion_Limit  | BruteForce execution time-O(n^3)|Strassen's improvement
----------------------------------------------------------------------------------------------------------------------------------------
1   | 5*5             | 130 microseconds                    | 50              | 32 microseconds          	|	0.24
----------------------------------------------------------------------------------------------------------------------------------------
2   | 10*10           | 249 microseconds                    | 50              | 252 microseconds                |	0.24
----------------------------------------------------------------------------------------------------------------------------------------
3   | 50*50           | 4714 microseconds              	    | 50              | 1097 microseconds               |	0.23
----------------------------------------------------------------------------------------------------------------------------------------
4   | 100*100         | 14268 microseconds             	    | 50              | 8786 microseconds               |	0.61
----------------------------------------------------------------------------------------------------------------------------------------
5   | 150*150         | 91724 microseconds                  | 50 	      | 82845 microseconds              |	0.90
----------------------------------------------------------------------------------------------------------------------------------------
6   | 200*200         | 90701 microseconds                  | 50 	      | 92206 microseconds              |	1.01
----------------------------------------------------------------------------------------------------------------------------------------
7   | 250*250         | 95957 microseconds             	    | 50 	      | 89498 microseconds              |	0.93
----------------------------------------------------------------------------------------------------------------------------------------
8   | 300*300         | 917265 microseconds                 | 50	      | 798691 microseconds             |	0.87
----------------------------------------------------------------------------------------------------------------------------------------
9   | 400*400         | 654711 microseconds            	    | 50              | 816000 microseconds             |	1.22
----------------------------------------------------------------------------------------------------------------------------------------
10  | 500*500         | 654789 microseconds            	    | 50	      | 816602 microseconds             |	1.25
----------------------------------------------------------------------------------------------------------------------------------------

->In the above algorithm we have multiplied matrices using Strassen’s algorithm, but only to a certain limit. 
Once the size of the matrices becomes less than “Recursion_Limit,”we use the brute force method of matrix 
multiplication to multiply them. This is because,we have found from our experiments that below a certain size,
there is negligible difference between the brute force method of matrix multiplication and matrix multiplication
using Strassen’s algorithm.

->Considering there are 2 input matrices and 1 output matrix,each of equal size; for 50x50 the total size of three
matrices is 8 KB. For 100x100 the total size of three matrices is 30 KB. We have calculated the size of each
matrix by multiplying the space occupied by each element of the matrix(1 byte) with the number of elements of the
matrix. Since 8 KB and 30 KB are both less than the total cache memory size of the CPU, the matrices can be stored
in the cache. So there will always be a cache hit and data transfer will be much faster. Now for matrices of size
200x200, the total size of 3 matrices is 120 KB. This exceeds the capacity of the cache memory. Hence, the
matrices have to be stored on the external memory, which is the RAM. So there always be a cache miss. Therefore data
transfer on the external memory will always take more time.Thereon, all matrices have to be stored on the external memory.

->Experimental Multiplier = (Time taken for matrix of size nxn)/(Time taken for matrix of size (n/2)x(n/2))

->There is also an explanation as to why the value of the multiplier does not come exactly as 8. Since we are running
the program on an OS with many applications running in the background, the CPU is unable to devote it’s full power to
executing the program. This is why the multiplier is varying a bit. For some cases, the applications in the background
may not be consuming much resources, or in other cases it might be consuming a lot of resources. Taking multiple
readings, and calculating their average is the best way to eliminate this inconsistency, and that is what we have done
while taking these readings.

->Strassen Improvement = (Time for BruteForce Method)/(Time for Strassen)

->From above table we can see the strassens improvement which is 1.25 for 500*500 matrix.

->Now for matrix multiplication using Strassen’s algorithm we can see that the multiplier is uniform. There is no drastic
increase in the multiplier for matrices of size 200x200.This is because we are using recursion. We are constantly
splitting the matrices until we get matrices that reach the recursion limit. Only then do we multiply the matrices using
the brute force method of multiplication. The Recursion Limit has been set to 50 because we found that L1 cache size is 32K 
using "lscpu" command,only then do we multiply the matrices using the classic method of multiplication. Matrices
of this size can easily fit inside the cache memory of the CPU, thus ensuring fast data transfer. That is why there is no
drastic change in the multiplier, as matrix size increases from 200 onwards.

->Matrix multiplication using Strassen’s algorithm,as expected takes less time than the brute force method of matrix
multiplication. We have drawn further inferences from the above table.Thus we can see as the matrices increase in size, the
improvement in the Strassen’s algorithm increases. Thus we can say that, Strassen’s algorithm is effective for matrices of
large size.












