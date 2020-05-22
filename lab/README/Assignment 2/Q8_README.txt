-------------------------------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :
-------------------------------------------------------------------------------------------------------------------------------------------------------

Topological ordering of a graph is defined as follows: Let G = (V,E) be a directed graph. A
topological ordering of G is an assignment f(v) of every vertex v belongs to V to a different number such
that: for every (v, w) belongs to E, f(v) < f(w). Topological ordering is typically useful when one
is given, say, a bunch of tasks to complete, and there are precedence constraints, meaning
that one cannot start some of the tasks until he’she has completed others. As for example,
the courses in a university degree program, some of which are prerequisites for others. One
application of topological orderings is to sequencing tasks so that all precedence constraints
are respected. Depth-first search is perfectly suited for computing a topological ordering of a
directed acyclic graph.
Does every graph have a topological ordering ? Reason your answer with appropriate justi-
fications. Now, implement a program that uses DFS of a given Directed Acyclic Graph and
outputs topological ordering of the graph. Time your program and analyze the same.

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

1.	We create an instance of Class Graph and initialize it with number of vertices.
2.	Create adjacency list for every vertex v using the input edges.
3.	We create a topologicalSort procedure and helper function topologicalSortProcedure to find the topological sort of the DAG.
4.	Analyze the run time complexity this variation of Topological Sort. 


-------------------------------------------------------------------------------------------------------------------------------------------------------
HOW PROGRAM IS EXECUTING:
-------------------------------------------------------------------------------------------------------------------------------------------------------

1.	We create an instance of Class Graph and initialize it with number of vertices.
2.	Create adjacency list for every vertex v using the input edges.
3.	We create a topologicalSort procedure and helper function topologicalSortProcedure to find the topological sort of the DAG.
4.	Helper function topologicalSortProcedure uses DFS algorithm which uses stack data structure to find the topological sort.
5.	In DFS we use visited array to avoid processing same vertex again.
4.	We finally analyze the run time complexity this variation of Topological Sort.

-------------------------------------------------------------------------------------------------------------------------------------------------------
FINAL OUTPUT
-------------------------------------------------------------------------------------------------------------------------------------------------------

Our final Output is 
1. Topological Sort

INPUT 1 : Graph 1								Time_taken
	V = 6,  Edges = (5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1); |	57.000000 micro seconds   
OUTPUT : 5 4 2 3 1 0 
	
INPUT 2 : Graph 2
	V = 6,  Edges = (0, 1), (0, 2), (1, 2), (1, 3) (2, 3) (2, 4)	|	22.000000 micro seconds
OUTPUT : 5 0 1 2 4 3 

INPUT 3 : Graph 3
	V = 6,  Edges = (0, 1), (0, 2), (1, 3), (1, 4) (2, 4) (3, 4)	|	22.000000 micro seconds
OUTPUT : 5 0 2 1 3 4 

INPUT 4 : Graph 4
	V = 6,  Edges = (5, 0), (5, 2), (2, 3), (0, 4) (4, 1) (1, 3)	|	32.00000 micro seconds
OUTPUT : 5 2 0 4 1 3 

INPUT 5 : Graph 5
	V = 5,  Edges = (4, 0), (4, 1), (1, 2), (0, 3)  (2,3)		|	70.00000 micro seconds
OUTPUT : 4 1 2 0 3 

INPUT 6 : Graph 6
	V = 5,  Edges = (4, 0), (4, 1), (1, 2), (0, 3)  (2,3) (1,3) 	|	54.00000 micro seconds
OUTPUT :  4 1 2 0 3 

INPUT 7 : Graph 7
	V = 4,  Edges = (3, 0), (3, 1), (2,0),  (2,1) (0,1)		|	42.00000 micro seconds
OUTPUT :  4 3 2 0 1 

INPUT 8 : Graph 8
	V = 4,  Edges =  (2, 3), (0, 3) (1,3) (0, 2)			|	40.00000 micro seconds
OUTPUT : 1 0 2 3  

INPUT 9 : Graph 9
	V = 3,  Edges = (2, 0), (2, 1), (1, 0)				|	55.00000 micro seconds
OUTPUT : 2 1 0 

INPUT 10 : Graph 10
	V = 3,  Edges = (2, 0), (0, 1)	 				|	44.00000 micro seconds
OUTPUT : 0 1 

-------------------------------------------------------------------------------------------------------------------------------------------------------
CONCLUSION
-------------------------------------------------------------------------------------------------------------------------------------------------------

In this Assignment we have used Depth First Search (DFS) algorithm  for topological sort. We can also use Breadth First Search for topological sort.
But DFS is preferred for DAG because of the following reasons : -
1. Memory requirement is Linear with respect to Nodes.
2. Less time and space complexity compared to BFS.
3. Solution can be found out by without much more exhaustive search.
