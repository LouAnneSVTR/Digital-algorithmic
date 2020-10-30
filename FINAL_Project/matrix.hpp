#ifndef PROJET_FINAL_TEST_H
#define PROJET_FINAL_TEST_H

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


double*     allocateMatrix      (uint64_t n,uint64_t m) ;
double*     allocateVector      (uint64_t n) ;
void        freeMatrix          (double *A);
void        freeVector          (double *v);
void        setMatrixZero       (double *A, uint64_t n, uint64_t m);
void        setMatrixIdentity   (double *A, uint64_t n);
void        copyMatrix          (double *B, double *A, uint64_t n, uint64_t m) ;
void        writeMatrix         (FILE *stream, double *A, uint64_t n, uint64_t m);
void        absMatrix           (double *Aabs,double *A, uint64_t n, uint64_t m);
int      getMaxInMatrix         (double *A, double max, uint64_t n, uint64_t m);
void        matrixSub           (double *S, double *A, double *B, uint64_t n, uint64_t m);
void        matrixAdd           (double *S, double *A, double *B, uint64_t n, uint64_t m);


/* Performs naive multiplication of matrix A (size p x k) by a matrix B (size k x r).
The result matrix S = A*B  is of size (k x r).
We assume that S has already been allocated outside the function.
*/
void        matrixMultiplyNaive (double *S, double *A, double *B, uint64_t p, uint64_t k, uint64_t r);

/*This function consists in performing first treatment for Strassen.
 * That is to say, firstTreatment test if size of matrix is two square. If not, firstTreatment create a matrix in correct size for Strassen application.
 */
double * firstTreatment(double *M, uint64_t oldSize);

/* Performs a multiplication of two sqaure matrices A and B (size n x n) by Strassen algorithm.
    We assume that S has already been allocated outside the function.
*/
void        matrixMultiplyStrassen (double *S, double *A, double *B, uint64_t n);

/* 
    Solves a system of linear equations Ax=b for a double-precision matrix A (size n x n).
    Uses iterative ascension algorithm. 
    After the procedure, x contains the solution of Ax=b.
    We assume that x has been allocated outside the function.
*/
void        SolveTriangularSystemUP   (double *x, double *A, double *b, uint64_t n);

/*
 * This function eneables to find the highest number in absolute value on the line.
 * choicePivot uses indexColumn and return index of maxPivot.
 */
double        choicePivot         (double *A, int nbVector, uint64_t n);

/* This function switch line in matrix.
 * When the result is the highest the line switches first place.
 */
void switchLineInMatrix ( double *A, int indexPivot, int index, uint64_t n);

/* This function finds if in the matrix there are an entire line of zeros.
 */
bool searchError (double *A, int indexColumn, uint64_t n);

/* 
    Performs Gauss elimination for given a matrix A (size n x n) and a vector b (size n).
    Modifies directly matrix A and vector b.
    In the end of the procedure, A is upper truangular and b is modified accordingly.
    Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is impossible to triangularize. 
*/
bool       Triangularize            (double *A, double *b, uint64_t n);

/*
    Solves a system of linear equations Ax=b, given a matrix A (size n x n) and vector b(size n).
    Uses Gauss elimination algorithm based on truangularization and the ascension solving.
    After the procedure, vector x contains the solution to Ax=b.
    We assume that x has been allocated outside the function.
        Returns a boolean variable: 
        *  true in case of success and 
        *  false in case of failure, for example matrix is of rank <n .
*/
bool        SolveSystemGauss        (double *x, double *A, double *b, uint64_t n);



//######################################################################################################################"
//FINAL PROJECT

/*
 *This function enables to carry out the LU decomposition.
 * This function uses searchError to search if in the matrix there are an entire line of zeros.
 * Uses iterative ascension algorithm.
 * We assume that x has been allocated outside the function.
 */
bool        decompLU           (double *A, uint64_t n);

/*
 * This method the method calculates determinant of A.
 * Det consist in multiply the coefficients of the diagonals between them and once done, returns result.
 */
double      Det         (double *A, uint64_t n);

/*
 * Solves a system of linear equations Ax=b for a double-precision matrix A (size n x n).
 *  SolveTriangularSystemDOWN uses iterative descent algorithm.
 *
 * After the procedure, x contains the solution of Ax=b.
 * We assume that x has been allocated outside the function.
 */
void        SolveTriangularSystemLOW   (double *x, double *A, double *b, uint64_t n);


/*
 * Solves a system of linear equations Ax=b, given a matrix A (size n x n) and vector b(size n).
 * This function uses LU system to solves matrix.
 * SolveSystemLU calls decompLU, SolveTriangularSystemDOWN and SolveTriangularSystemUP and, returns a boolean variable:
 *     →  true in case of success
 *     →  false in case of failure, for example matrix is of rank <n .
 *
 * After the procedure, vector result in SolveTriangularSystemUP contains the solution to Ax=b.
 * We assume that x and result have been allocated outside the function.
 */
bool        SolveSystemLU        (double *x, double *result, double *A, double *b, uint64_t n);


#endif //PROJET_FINAL_TEST_H