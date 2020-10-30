#include <stdio.h>
#include <iostream>

#include "matrix.hpp"
#include "matrix.cpp"

using namespace std;

int main(int argc, char** argv){

    //VARIABLE

    //PART 1
    double A[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};

    //To proof A = L*U
    double U[16]={10,7,8,7,0,0.1,0.4,0.1,0,0,2,3,0,0,0,0.5};
    double L[16]={1,0,0,0,0.7,1,0,0,0.8,4,1,0,0.7,1,1.5,1};
    double *resultLU = allocateMatrix(4,4);

    //Determinant
    double ADet[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};

    //PART 2
    //QUESTION 1
    double A1[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};
    double A1proof[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};
    double A2[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};
    double A2proof[16] = {10,7,8,7,7,5,6,5,8,6,10,9,7,5,9,10};

    double b1[4] = {32,23,33,31};
    double b2[4] = {32.1,22.9,33.1,30.9};

    double *v1 = allocateVector(4);
    double *v2 = allocateVector(4);

    double *proof1 = allocateVector(4);//To proof Solve LU.
    double *proof2 = allocateVector(4);

    double *result1 = allocateVector(4); //For final result of. Represent x in Ax = b.
    double *result2 = allocateVector(4);

    //QUESTION 2
    double B1[16] = {1,7,2,1,7,5,1,5,8,6,10,9,7,5,9,1};
    double B1proof[16] = {1,7,2,1,7,5,1,5,8,6,10,9,7,5,9,1};
    double B2[16] = {1,7,2,1,7,5,1,5,8,6,10,9,7,5,9,1};
    double B2proof[16] = {1,7,2,1,7,5,1,5,8,6,10,9,7,5,9,1};

    double *proof3 = allocateVector(4);//To proof Solve LU.
    double *proof4 = allocateVector(4);

    double d1[4] = {11,18,33,22};
    double d2[4] = {11.1,17.9,33.1,21.9};

    double *x1 = allocateVector(4);
    double *x2 = allocateVector(4);

    double *result3 = allocateVector(4);//For final result of. Represent x in Bx = d.
    double *result4 = allocateVector(4);



    //FIRST PART : TASKS
    //---------------------------------------------------------------------------------------------
    //Test of first function : DECOMP LU
    cout << "\n\n*********************************** DECOMP LU **********************************\n" << endl;
    cout << "------ STARTING MATRIX : \n-> A";
    writeMatrix(stdout, A, 4, 4);

    decompLU(A,4);

    cout << "\n\n------ RESULT : \n-> A";
    writeMatrix(stdout, A, 4, 4);

    cout << "\n\n****************************** PROOf DECOMP LU *********************************";
    //EVIDENCE OF RESULT
    //To check if the calculation is correct, we need to multiply L by U and one must find the matrix A.

    matrixMultiplyNaive (resultLU,L,U, 4,4,4);

    cout << "\n\n------ RESULT MULTIPLY : ";
    writeMatrix(stdout, resultLU, 4, 4);

    cout << "\n\nL*U equals A ! " << endl;


    //---------------------------------------------------------------------------------------------
    //Test of second function : DET
    cout << "\n\n\n************************************* DET **************************************\n" << endl;

    cout << "------ STARTING MATRIX : \n-> A";
    writeMatrix(stdout, A, 4, 4);

    double resultatDetALU = Det(A, 4);

    cout << "\n\n------ RESULT : " << resultatDetALU;


    //SECOND PART : TEST
    //---------------------------------------------------------------------------------------------

    cout << "\n\n\n******************************** SOLVE LU ***************************************" << endl;

    //QUESTION 1 :

    cout << "\n------------ QUESTION 1.1 : A1 with b1\n" << endl;

    cout << "\n------ STARTING MATRIX : \n\n-> A";
    writeMatrix( stdout, A1, 4, 4);
    cout << "\n-> b ";
    writeMatrix( stdout, b1, 4, 1);

    SolveSystemLU(v1,result1, A1, b1, 4);

    cout << "\n\n------ RESULT Ax=b1 : ";
    writeMatrix(stdout, result1, 4,1);


    //PROOF
    //To proof LU decomposition, we multiply A by result in order to find b.
    cout << "\n\n------ Proof, A by result1 ";
    matrixMultiplyNaive (proof1,A1proof,result1, 4,4,1);

    cout << "\n\n------ RESULT MULTIPLY : ";
    writeMatrix(stdout, proof1, 4, 1);

    cout << "\n\nresult equals b ! " << endl;



    cout << "\n\n\n------------QUESTION 1.2 : A2 with b2\n" << endl;

    cout << "\n------ STARTING MATRIX : \n\n-> A";
    writeMatrix( stdout, A2, 4, 4);
    cout << "\n-> b ";
    writeMatrix( stdout, b2, 4, 1);

    SolveSystemLU(v2,result2, A2, b2, 4);

    cout << "\n\n------ RESULT ax=b2 : ";
    writeMatrix(stdout, result2, 4,1);


    //PROOF
    //To proof LU decomposition, we multiply A by result in order to find b.
    cout << "\n\n------ Proof, A by result2 ";
    matrixMultiplyNaive (proof2, A2proof, result2, 4, 4, 1);

    cout << "\n\n------ RESULT MULTIPLY : ";
    writeMatrix(stdout, proof2, 4, 1);

    cout << "\n\nresult equals b ! " << endl;


    //QUESTION 2 :

    cout << "\n\n\n------------QUESTION 2.1 : B1 with d1\n" << endl;

    cout << "\n------ STARTING MATRIX : \n\n-> B";
    writeMatrix( stdout, B1, 4, 4);
    cout << "\n-> d1 ";
    writeMatrix( stdout, d1, 4, 1);

    SolveSystemLU(x1,result3, B1, d1, 4);

    cout << "\n\n------ RESULT Bx=d1 : ";
    writeMatrix(stdout, result3, 4,1);


    //PROOF
    //To proof LU decomposition, we multiply A by result in order to find b.
    cout << "\n\n------ Proof, B by result3 ";
    matrixMultiplyNaive (proof3, B1proof, result3, 4, 4, 1);

    cout << "\n\n------ RESULT MULTIPLY : ";
    writeMatrix(stdout, proof3, 4, 1);

    cout << "\n\nresult equals d ! " << endl;


    cout << "\n\n\n------------QUESTION 2.2 : B2 with d2\n" << endl;

    cout << "\n------ STARTING MATRIX : \n\n-> B";
    writeMatrix( stdout, B2, 4, 4);
    cout << "\n-> d2 ";
    writeMatrix( stdout, d2, 4, 1);

    SolveSystemLU(x2,result4, B2, d2, 4);

    cout << "\n\n------ RESULT Bx=d2 : ";
    writeMatrix(stdout, result4, 4,1);


    //PROOF
    //To proof LU decomposition, we multiply A by result in order to find b.
    cout << "\n\n------ Proof, B by result4 ";
    matrixMultiplyNaive (proof4, B1proof, result4, 4, 4, 1);

    cout << "\n\n------ RESULT MULTIPLY : ";
    writeMatrix(stdout, proof4, 4, 1);

    cout << "\n\nresult equals d ! " << endl;


   }