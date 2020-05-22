#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#include <chrono>
using namespace std::chrono;
long long int ** create(long long int ,long long int );
long long int ** createZeroMatrix(long long int );
long long int ** strassensMultiplication(long long int  **, long long int  **,long long int );
long long int ** standardMultiplication(long long int  **,long long int  **,long long int );
long long int ** strassensMultRec(long long int  **, long long int **,long long int  n);
long long int ** divide(long long int  ** matrixA,long long int  n, long long int  row,long long int  col);
void printMatrix(long long int  **, long long int );
long long int  ** addMatrix(long long int **,long long int **,long long int );
long long int ** subMatrix(long long int **,long long int **,long long int );
void compose(long long int **,long long int **,long long int ,long long int ,long long int );

 int  main() {
	long long int  i=0,j=0,n=0;
	long long int N;
   // struct timeval time_curr;
	printf("enter the size of an Array");
    scanf("%lld",&n);
	N=n;
	if(n<1){
		printf("\nError: Invalid matrix dimension!\n\n");
		return 0;

	}
	//To handle when n is not power of k we do the padding with zero
	long long int  pow = 1;
	while(pow<n){
		pow=pow*2;
	}
	long long int  ** matrixA = create(n,pow);
	long long int  ** matrixB = create(n,pow);
	n = pow;
	high_resolution_clock::time_point start1 = high_resolution_clock::now();
	//printf("\nStrassen's Multiplication Output:\n");

	long long int  ** strassensRes = strassensMultiplication(matrixA,matrixB,n);
	//printMatrix(strassensRes,N);
  	high_resolution_clock::time_point end1 = high_resolution_clock::now();


	auto exec_time3= duration_cast<microseconds>(end1 - start1).count();
    	printf("\nTotal Time using strassens for %lld*%lld matrix is %ld microseconds\n",N,N,exec_time3);


     	high_resolution_clock::time_point start2 = high_resolution_clock::now();
	long long int  ** stdRes = standardMultiplication(matrixA,matrixB,n);
	//printf("\nStandard Multiplication Output:\n");
	//printMatrix(stdRes,N);

 	high_resolution_clock::time_point end2 = high_resolution_clock::now();
	auto exec_time2 = duration_cast<microseconds>(end2 - start2).count();
    	printf("\nTotal Time using standard for %lld*%lld matrix is %ld microseconds\n",N,N,exec_time2);
	return 0;
}

/*
* Create the matrix with random floating point numbers betweeen 0 to 99
*/
long long int  ** create(long long int  n,long long int  pow){
	long long int  ** array = createZeroMatrix(pow);
	long long int  i,j;
	srand(time(0));
	for(i = 0;i < n; i++) {
   	 	for(j = 0; j < n; j++) {
	    		array[i][j] = rand()%100;
			}
	}
	return array;
}

/*
* This function creates the matrix and initialize all elements to zero
*/
long long int  ** createZeroMatrix(long long int  n){
	long long int  ** array = (long long int **)malloc(n*sizeof(long long int  *));
	long long int  i,j;
	for(i = 0;i < n; i++) {
	    	array[i] = (long long int *)malloc(n*sizeof(long long int ));
   	 	for(j = 0; j < n; j++) {
	        	array[i][j] = 0;
	    	}
	}
	return array;
}
/*
* Function to Print Matrix
*/
void printMatrix(long long int  ** matrix,long long int  n) {
	long long int  i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("   %lld   ",matrix[i][j]);
		}
		printf("\n");
	}
}
/*
* Standard Matrix multiplication with O(n) time complexity.
*/
long long int  ** standardMultiplication(long long int  ** matrixA,long long int  ** matrixB,long long int  n) {
	long long int  ** result;
	long long int  i,j,k;

	result = (long long int **)malloc(n*sizeof(long long int  *));


	for(i=0;i<n;i++){
		result[i]=(long long int *)malloc(n*sizeof(long long int ));
		for(j=0;j<n;j++){
			result[i][j]=0;
			for(k=0;k<n;k++) {
				result[i][j]=result[i][j]+(matrixA[i][k]*matrixB[k][j]);
			}
		}
	}
	return result;
}

/*
* Wrapper function over strassensMultRec.
*/
long long int  ** strassensMultiplication(long long int  ** matrixA, long long int ** matrixB,long long int  n){

	//long long int  ** result = strassensMultRec(matrixA,matrixB,n);


	//return result;
	return strassensMultRec(matrixA,matrixB,n);
}

/*
* Strassen's Multiplication algorithm using Divide and Conquer technique.
*/
long long int ** strassensMultRec(long long int  ** matrixA, long long int ** matrixB,long long int  n){

	long long int  ** result = createZeroMatrix(n);
	long long int ** m1;
	long long int ** m2;
	long long int ** m3;
	long long int ** m4;
	long long int ** m5;
	long long int ** m6;
	long long int ** m7;
	long long int Recursion_Limit=50;
	if(n>1) {
		//Divide the matrix
		long long int  ** a11 = divide(matrixA, n, 0, 0);
		long long int  ** a12 = divide(matrixA, n, 0, (n/2));
		long long int  ** a21 = divide(matrixA, n, (n/2), 0);
		long long int  ** a22 = divide(matrixA, n, (n/2), (n/2));
		long long int  ** b11 = divide(matrixB, n, 0, 0);
		long long int  ** b12 = divide(matrixB, n, 0, n/2);
		long long int  ** b21 = divide(matrixB, n, n/2, 0);
		long long int  ** b22 = divide(matrixB, n, n/2, n/2);

		//Recursive call for Divide and Conquer
		if(n>Recursion_Limit)
			m1= strassensMultRec(addMatrix(a11,a22,n/2),addMatrix(b11,b22,n/2),n/2);
		else
			m1=standardMultiplication(addMatrix(a11,a22,n/2),addMatrix(b11,b22,n/2),n/2);
		if(n>Recursion_Limit)
			m2= strassensMultRec(addMatrix(a21,a22,n/2),b11,n/2);
		else
			m2=standardMultiplication(addMatrix(a21,a22,n/2),b11,n/2);
		if(n>Recursion_Limit)
			m3= strassensMultRec(a11,subMatrix(b12,b22,n/2),n/2);
		else
			m3=standardMultiplication(a11,subMatrix(b12,b22,n/2),n/2);
		if(n>Recursion_Limit)
			m4= strassensMultRec(a22,subMatrix(b21,b11,n/2),n/2);
		else
			m4=standardMultiplication(a22,subMatrix(b21,b11,n/2),n/2);
		if(n>Recursion_Limit)
			m5= strassensMultRec(addMatrix(a11,a12,n/2),b22,n/2);
		else
			m5=standardMultiplication(addMatrix(a11,a12,n/2),b22,n/2);
		if(n>Recursion_Limit)
			m6= strassensMultRec(subMatrix(a21,a11,n/2),addMatrix(b11,b12,n/2),n/2);
		else
			m6=standardMultiplication(subMatrix(a21,a11,n/2),addMatrix(b11,b12,n/2),n/2);
		if(n>Recursion_Limit)
			m7= strassensMultRec(subMatrix(a12,a22,n/2),addMatrix(b21,b22,n/2),n/2);
		else
			m7=standardMultiplication(subMatrix(a12,a22,n/2),addMatrix(b21,b22,n/2),n/2);

		long long int ** c11 = addMatrix(subMatrix(addMatrix(m1,m4,n/2),m5,n/2),m7,n/2);
		long long int ** c12 = addMatrix(m3,m5,n/2);
		long long int ** c21 = addMatrix(m2,m4,n/2);
		long long int ** c22 = addMatrix(subMatrix(addMatrix(m1,m3,n/2),m2,n/2),m6,n/2);
		//Compose the matrix
		compose(c11,result,0,0,n/2);
		compose(c12,result,0,n/2,n/2);
		compose(c21,result,n/2,0,n/2);
		compose(c22,result,n/2,n/2,n/2);
	}
	else {
		//This is the terminating condition for recursion.
		result[0][0]=matrixA[0][0]*matrixB[0][0];
	}

	return result;
}

/*
* This method combines the matrix in the result matrix
*/
void compose(long long int ** matrix,long long int ** result,long long int  row,long long int  col,long long int  n){
	long long int  i,j,r=row,c=col;
	for(i=0;i<n;i++){
		c=col;
		for(j=0;j<n;j++){
			result[r][c]=matrix[i][j];
			c++;
		}
		r++;
	}
}

/*
* Sub-divide the matrix according to row and col specified
*/
long long int ** divide(long long int  ** matrix,long long int  n, long long int  row,long long int  col) {
	long long int  n_new=n/2;

	long long int  ** array = createZeroMatrix(n_new);
	long long int  i,j,r=row,c=col;
	for(i = 0;i < n_new; i++) {
		c=col;
   	 	for(j = 0; j < n_new; j++) {
        		array[i][j] = matrix[r][c];
			c++;
    		}
		r++;
	}
	return array;
}

/*
* Add the two input matrix
*/
long long int ** addMatrix(long long int ** matrixA,long long int ** matrixB,long long int  n){
	long long int  ** res = createZeroMatrix(n);
	long long int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			res[i][j]=matrixA[i][j]+matrixB[i][j];

	return res;
}
/*
* Substract the two matrix
*/
long long int ** subMatrix(long long int ** matrixA,long long int ** matrixB,long long int  n){
	long long int  ** res = createZeroMatrix(n);
	long long int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			res[i][j]=matrixA[i][j]-matrixB[i][j];

	return res;
}
