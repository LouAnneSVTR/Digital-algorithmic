#include "matrix.hpp"
#include <iostream>
#include <math.h>


using namespace std;

/*
    Nous allons stocker des matrices dans des tablaux à 1 dimension:
    Par exemple, matrice de taille n x m est stockué comme:
        A_tab = [A_11, A_12, ... A_1m, A_21, ... A_2m, ... , A_1n, ..., A_nm]

    Par conséquant, un élement A_ij aurait quelle indice dans le tableau A_tab ? 

 */

/* Memory allocation for a matrix of size n x m and initilization to 0  */
double *allocateMatrix(uint64_t n,uint64_t m) {
  double *A;
  A = (double *) calloc (n * m, sizeof(double));
  return A;
}


/* Frees the memory allocated to matrix A
*/
void freeMatrix(double *A) {
    free(A);
}

/* Allocates a n sized vector and initializes all entries to 0 
*/
double *allocateVector(uint64_t n) {
  double *v; 
  v = (double *) calloc(n, sizeof(double));
  return v;
}

/* Trees the memory allocated to a vector
*/
void freeVector(double *v) {
  free(v);
}


/* Sets a n * m matrix A to all zeros */
void setMatrixZero(double *A, uint64_t n, uint64_t m) {
  uint64_t i, j;

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
        /* Note that for a n x m matrix flattened to a 1D array, 
        element A_ij has index i * m + j
        */
      A[i * m + j] = 0.0; 
    }
  }
}

/* Sets a n * n matrix A to identity */
void setMatrixIdentity(double *A, uint64_t n) {
  uint64_t i, j;

  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
     A[i * n + j] = 0.0;
    }
    A[i * n + i] = 1.0;
  }
}



/* Copies a matrix  
*/
void copyMatrix(double *B, double *A, uint64_t n, uint64_t m) {
  uint64_t i,j;

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
      B[i * m + j] = A[i * m + j]; 
    }
  }
}

/*
Writes a matrix to a stream. For example, writing a matrix to standard output is
writeMatrix(stdout, A, n, m);
A sream can also be a file. 
*/
void writeMatrix(FILE *stream, double *A, uint64_t n, uint64_t m)
{
    cout << "\n\nSize matrix : ";
	fprintf(stream, "%d %d \n", (int)n, (int)m);
	cout << "\n";
	int i, j;
	for(i = 0; i < n; ++i)
	{
	      for(j = 0; j < m; ++j)
	      {
		      fprintf(stream, "%f \t", A[i * m + j]);
	      }
	      fprintf(stream, "\n");
	}
}



//The function computes the element-by-element abs of matrix A
void absMatrix(double *Aabs,double *A, uint64_t n, uint64_t m)
{
	uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            Aabs[i*m + j] = fabs(A[i*m + j]);
		}
	}
}


/*
Performs addition of two matrix A (size n x m) and B (size n x m).
The result S = A + B is a n x m matrix.
We consider that S is allocated outside the function.
*/
void matrixAdd(double *S, double *A, double *B, uint64_t n, uint64_t m){
    uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            S[i*m + j] = A[i*m + j] + B[i*m + j];
		}
	}
}

/*
Performs subtraction of two matrix A (size n x m) and B (size n x m).
The result S = A - B is a n x m matrix.
We consider that S is allocated outside the function.
*/
void matrixSub(double *S, double *A, double *B, uint64_t n, uint64_t m){
    uint64_t i,j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
            S[i*m + j] = A[i*m + j] - B[i*m + j];
		}
	}
}


/* For a double m x n matrix A the function returns its maximum in absolute value
element. 
*/
int getMaxInMatrix( double *A, double max, uint64_t n, uint64_t m)
{
   double maxA = fabs(A[0]);
   double current = fabs(A[0]);
   int i,j, index;
 
   for(i = 0; i < n; ++i)
   {
      for(j = 0; j < m; ++j)
      {
         current = fabs(A[i * m + j]);

         if(current > maxA){
            maxA = current;
            index = i*m+j; //to search index of current element
         }
      }
   }
   return index;
}


/* Performs naive multiplication of matrix A (size p x k) by a matrix B (size k x r).
The result matrix S = A*B  is of size (p x r).
We assume that S has already been allocated outside the function.
*/
void        matrixMultiplyNaive (double *S, double *A, double *B, uint64_t p, uint64_t k, uint64_t r){
    //Begin
    for (int line = 0 ; line < p ; ++line){ //To access the line.

       for (int column = 0 ; column < r ; ++column){ //To access the column.

           for(int iterator = 0 ; iterator < k ; iterator++){ //To multiply coefficients with iterator.
                 S[line*r + column] += A[line*k+iterator]*B[iterator*r + column]; //Multiply coefficients in line i of matrix A by coefficients in column j of matrix B and add on S in correct index.
           }
       }
    }
}

/* This function performs first treatment for Strassen.
 * That is to say, firstTreatment test if size of matrix is two square. Otherwise, firstTreatment creates a matrix in correct size for Strassen application.
 */
double * firstTreatment(double *oldMatrix, uint64_t oldSize) {
   //Variable
    uint64_t newSize; //If size of matrix change.
    double *newMatrix ; //Modified matrix.

    //Begin
    if (log2(oldSize) != floor(log2(oldSize))) { //Test if size of matrix is two square.
        newSize = oldSize;

        while (log2(newSize) != floor(log2(newSize))) { //While size is not a square of two
            newSize++;
        }
        newMatrix = allocateMatrix(newSize, newSize); //Once we get correct size, allocation.
        setMatrixZero(newMatrix, newSize, newSize);
        copyMatrix(newMatrix, oldMatrix, oldSize, newSize); //Copy old matrix in new. We get new matrix with columns and lines of 0.
    }
    return newMatrix;
}

/* Performs a multiplication of two sqaure matrices A and B (size n x n) by Strassen algorithm.
   We assume that S has already been allocated outside the function.
*/
void        matrixMultiplyStrassen (double *S, double *A, double *B, uint64_t n) {

    //Begin
    if (n == 1) { //If size = 1, we no need Strassen.
        S[0] = A[0]*B[0];
        
    } else if( n == 2) { //As n = 1, is n = 2, we only need matrixMultiplyNaive.
        matrixMultiplyNaive(S, A, B, n, n, n);
        
    } else {
        if (log2(n) != floor(log2(n))) { //Test if size of matrix is two square. If test is valide, change matrix A and B.
            A = firstTreatment(A, n); //Change A.
            B = firstTreatment(B, n); //Change B.
            while (log2(n) != floor(log2(n))) { //Calculate new size of A and B.
                n++;
            }
            setMatrixZero(S, n, n); //Adapt size of result.
        }

        int newSize = n / 2; //Divided size.

        /**
         * Allocation of all blocks in size n/2. 
         * a = matrix A.
         * b = matrix B.
         * p = intermediate operation.
         * aResult or bResult = result of p.
         * c = blocks operation.
         */
         
        double  *a11 = allocateMatrix(newSize,newSize), *a12 = allocateMatrix(newSize,newSize),
                *a21 = allocateMatrix(newSize,newSize), *a22 = allocateMatrix(newSize,newSize);

        double  *b11 = allocateMatrix(newSize,newSize), *b12 = allocateMatrix(newSize,newSize),
                *b21 = allocateMatrix(newSize,newSize), *b22 = allocateMatrix(newSize,newSize);

        double  *c11 = allocateMatrix(newSize,newSize), *c12 = allocateMatrix(newSize,newSize),
                *c21 = allocateMatrix(newSize,newSize), *c22 = allocateMatrix(newSize,newSize);

        double  *p1 = allocateMatrix(newSize,newSize), *p2 = allocateMatrix(newSize,newSize),
                *p3 = allocateMatrix(newSize,newSize), *p4 = allocateMatrix(newSize,newSize),
                *p5 = allocateMatrix(newSize,newSize), *p6 = allocateMatrix(newSize,newSize),
                *p7 = allocateMatrix(newSize,newSize);

        double   *aResult = allocateMatrix(newSize,newSize), *bResult = allocateMatrix(newSize,newSize);

        for ( int line= 0 ; line< newSize ; ++line) {
            for ( int column = 0 ;column < newSize ; ++column ) {
                /**
                 * Block selection.
                 * a(line,column) and b(line,column) = Filled matrix a and b with old term of A and B.
                 *
                 * Warning ! a and b are of new size !
                 */
                a11[line* newSize +column] = A[line* n +column];
                a12[line* newSize +column] = A[line* n + (column + newSize)];
                a21[line* newSize +column] = A[(line+ newSize) * n +column];
                a22[line* newSize +column] = A[(line+ newSize)  * n + (column + newSize)];

                b11[line* newSize +column] = B[line* n +column];
                b12[line* newSize +column] = B[line* n + (column + newSize)];
                b21[line* newSize +column] = B[(line+ newSize) * n +column];
                b22[line* newSize +column] = B[(line+ newSize)  * n + (column + newSize)];
            }
        }

        ///(a11 + a22)
        matrixAdd(aResult, a11, a22, newSize, newSize);
        //(b11 + b22)
        matrixAdd(bResult, b11, b22, newSize, newSize);
        //recursion up to p1 = (a11 + a22)(b11 + b22)
        matrixMultiplyStrassen(p1, aResult, bResult, newSize);


        ///(a21 + a22)
        matrixAdd(aResult, a21, a22, newSize, newSize);
        //recursion up to p2 = multiplier (a21 + a22)b11
        matrixMultiplyStrassen(p2, aResult, b11, newSize);


        ///(b12 - b22)
        matrixSub(bResult, b12, b22, newSize, newSize);
        //recursion up to p3 = a11(b12 - b22)
        matrixMultiplyStrassen(p3, a11, bResult, newSize);


        ///(b21 - b11)
        matrixSub(bResult, b21, b11, newSize, newSize);
        //recursion up to p4 = a22(b21 - b11)
        matrixMultiplyStrassen(p4, a22, bResult, newSize);


        ///(a11 + a12)
        matrixAdd(aResult, a11, a12, newSize, newSize);
        //recursion up to p5 = (a11 + a12)b22
        matrixMultiplyStrassen(p5, aResult, b22, newSize);

        ///(a21 - a11)
        matrixSub(aResult, a21, a11, newSize, newSize);
        //(b11 + b12)
        matrixAdd(bResult, b11, b12, newSize, newSize);
        //recursion up to p6 = (a21 - a11)(b11 + b12)
        matrixMultiplyStrassen(p6, aResult, bResult, newSize);


        ///(a12 - a22)
        matrixSub(aResult, a12, a22, newSize, newSize);
        //(b21 + b12)
        matrixAdd(bResult, b21, b22, newSize, newSize);
        //recursion up to p7 = (a12 - a22)(b21 + b12)
        matrixMultiplyStrassen(p7, aResult, bResult, newSize);


        /**
         * calculation of c11, c12, c21, c22
         */

        ///c12 = p3 + p5
        matrixAdd(c12, p3, p5, newSize, newSize);

        ///c21 = p2 + p4
        matrixAdd(c21, p2, p4, newSize, newSize);
        //aResult = p1 + p4
        matrixAdd(aResult, p1, p4, newSize, newSize);
        //bResult = p1 + p4 + p7 ou bResult = aResult + p7
        matrixAdd(bResult, aResult, p7, newSize, newSize);

        ///c11 = p1 + p4 - p5 + p7
        matrixSub(c11, bResult, p5, newSize, newSize);
        //aResult = p1 + p3
        matrixAdd(aResult, p1, p3, newSize, newSize);
        //bResult = p1 + p3 + p6 ou bResult = aResult + p6
        matrixAdd(bResult, aResult, p6, newSize, newSize);

        ///c22 = p1 + p3 - p 5 + p6
        matrixSub(c22, bResult, p2, newSize, newSize);

        ///Brings together the 4 results of c in new matrix S.
        for ( int i = 0 ; i < newSize ; ++i ) {
            for ( int j = 0 ; j < newSize ; ++j )  {
                S[i * n + j]                          = c11[i * newSize + j];
                S[i * n + (j + newSize)]              = c12[i * newSize + j];
                S[(i + newSize) * n + j]              = c21[i * newSize + j];
                S[(i + newSize) * n + (j + newSize)]  = c22[i * newSize + j];
            }
        }
    }
}



/* 
    Solves a system of linear equations Ax=b for a double-precision matrix A (size n x n).
    Uses iterative ascension algorithm. 
    After the procedure, x contains the solution of Ax=b.
    We assume that x has been allocated outside the function.
*/
void        SolveTriangularSystemUP   (double *x, double *A, double *b, uint64_t n){
    //Variable
    double coefficient; //For solves variable in column.
    
    //Begin
     for ( int column = n-1 ; column >= 0 ; column--){

         for ( int line = column-1 ; line >= 0 ; line--){
             coefficient = A[n*line + column] / A[column*n+column]; //Find the coefficient to make all the coefficient in column j to 0.
             b[line] = b[line] - coefficient*b[column]; //Subtract vector b at line with coefficient.
            }
        }
for ( int index = 0 ; index < n ; index++){
          x[index] = b[index] / A[index*n + index]; //Solves equation at vector x such that Ax = b with pivot.
    }
}

/*
 * This function eneables to find the highest number in absolute value on the line.
 * choicePivot uses indexColumn and return index of maxPivot.
 */
double choicePivot(double *A, int indexColumn, uint64_t n){
    //Variable
    double max = A[indexColumn*n+indexColumn]; //Save it for later.
    int maxPivot = indexColumn;

    //Begin
    for(int line = indexColumn ; line < n ; ++line){
        if(fabs(A[line*n+indexColumn]) >  fabs(max)){ //Test if absolute value is bigger than variable in column.
            max = A[line*n+indexColumn] ; //Replace max by new Pivot
            maxPivot = line ;
        }
    }
    return maxPivot ;
}

/* This function switch line in matrix.
 * When the result is the highest the line switches first place.
 */
void switchLineInMatrix ( double *A, double *b, int indexNewPivot, int indexOldPivot, uint64_t n){
    //Variable
    double memoryA;
    double memoryB;

    //Begin
    if ( indexNewPivot != indexOldPivot ) { //Check if the highest number is already in first line.
        for (int column = 0 ; column < n ; ++column) {
            memoryA = A[indexNewPivot * n + column]; //Save temporary index of Pivot.
            A[indexNewPivot * n + column] = A[indexOldPivot * n + column]; //Place pivot at first line in matrix.
            A[indexOldPivot * n + column] = memoryA; //Save old position.
        }
        memoryB = b[indexNewPivot]; //
        b[indexNewPivot] = b[indexOldPivot];
        b[indexOldPivot] = memoryB;
    }
}

/*This function finds if in the matrix there are an entire line of zeros.  */
bool searchError (double *A, int indexColumn, uint64_t n) {
    for (int line = 0 ; line < n ; line++) {
        if (A[line * n + indexColumn] != 0) { //Test if coefficient = 0.
            return true;
        }
    }
    return false;
}


/* 
    Performs Gauss elimination for given a matrix A (size n x n) and a vector b (size n).
    Modifies directly matrix A and vector b.
    In the end of the procedure, A is upper truangular and b is modified accordingly.
    Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is impossible to triangularize. 
*/
bool        Triangularize           (double *A, double *b, uint64_t n){
    //Variable
    int pivot;
    double coefficient = 0;
    bool error = true;

    //Begin
    for (int column = 0 ; column < n - 1; column++) {
        pivot = choicePivot(A, column, n); //It is called choicePivot.
        switchLineInMatrix(A, b, pivot, column, n); //It is called switchLineInMatrix depending on pivot.

        if (!searchError(A,column,n)) { //If searchError returns true, it has to stop the function because the system can't be solved.
            error = false;
        }

        for (int line = column; line < n - 1 ; line++) {
            coefficient = A[n*(line + 1) + column] / A[n*column + column]; //Search coefficient depending pivot.

            for (int column2 = column; column2 < n; column2++) {
                A[n * (line + 1) +  column2] -= A[n*column + column2] * coefficient; //Multiply variable in matrix by coefficient.
            }
            b[line + 1] = b[line + 1] - ( b[column] * coefficient ); //Solve vector b by coefficient.
        }
    }
    return error; //If searchError returns true.
}

/*
    Solves a system of linear equations Ax=b, given a matrix A (size n x n) and vector b(size n).
    Uses Gauss elimination algorithm based on triangularization and the ascension solving.
    After the procedure, vector x contains the solution to Ax=b.
    We assume that x has been allocated outside the function.
        Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is of rank <n .
*/
bool        SolveSystemGauss        (double *x, double *A, double *b, uint64_t n) {

    //Begin
    if (Triangularize(A, b, n)) { //Test if triangularize return true.
        SolveTriangularSystemUP(x, A, b, n);
        return true;
    } else {
        return false; //If system can't be solved.
    }
}



