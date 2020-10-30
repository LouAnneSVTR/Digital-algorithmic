#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <stdint.h>

#include "matrix.hpp"

using namespace std;

int main(int argc, char** argv){

    //Variable
    double A[16] = {2,1,1,-3,6,2,5,-8,4,3,3,-9,-2,-2,-5,10};
    double AT[16] = {2,1,1,-3,6,2,5,-8,4,3,3,-9,-2,-2,-5,10};
    double b[4] = {7,29,17,-23};

    //Result
    double *S = allocateMatrix(4, 4); //multiply naive
    double *S2 = allocateMatrix(4, 4); //multiply Strassen
    double *x = allocateVector(4); //To solve Gauss.
    double b1[4] = {7,29,17,-23}; //To save vector b and compare with result of Gauss.
    double *b2 = allocateVector(4); //To proof Gauss.

    //Begin main
    //---------------------------------------------------------------------------------------------
    //Test of first function with matrix A : MULTIPLY NAIVE

    cout << "\n\n******************************** MULTIPLY NAIVE ********************************\n" << endl;
    cout << "------ STARTING MATRIX : ";
    writeMatrix(stdout, A, 4, 4);

    matrixMultiplyNaive (S,A,A, 4,4,4);

    cout << "\n\n------ RESULT : ";
    writeMatrix(stdout, S, 4, 4);

    //---------------------------------------------------------------------------------------------
    //Test of second function : STRASSEN

    cout << "\n\n****************************** MULTIPLY STRASSEN ******************************\n" << endl;

    cout << "------ STARTING MATRIX : ";
    writeMatrix(stdout, A, 4, 4);

    matrixMultiplyStrassen(S2,A,A,4);

    cout << "\n\n------ RESULT : ";
    writeMatrix(stdout, S2, 4, 4);

    //---------------------------------------------------------------------------------------------
    //Test of TRIANGULARIZE
    cout << "\n\n******************************** TRIANGULARIZE *******************************\n" << endl;

    cout << "------ STARTING MATRIX : -> A";
    writeMatrix(stdout, AT, 4, 4);
    cout << "\n-> b";
    writeMatrix(stdout, b1, 4, 1);

    Triangularize( AT, b1, 4);

    cout << "\n\n------ RESULT : -> A";
    writeMatrix(stdout, AT, 4, 4);
    cout << "\n-> b";
    writeMatrix(stdout, b1, 4, 1);


    //-----------------------------------------------------------------------------------------
    //Test of GAUSS
    cout << "\n\n*********************************** GAUSS **********************************\n" << endl;

    cout << "------ STARTING MATRIX : ";
    cout << "-> A";
    writeMatrix(stdout, A, 4, 4);
    cout << "\n-> b";
    writeMatrix(stdout, b, 4, 1);

    SolveSystemGauss(x,A,b,4);

    cout << "\n\n------ RESULT MATRIX TRIANGULAR : -> A";
    writeMatrix(stdout, A, 4, 4);
    cout << "\n------ COEFFICIENT -> b";
    writeMatrix(stdout, b, 4, 1);
    cout << "\n------ FINAL RESULT -> x";
    writeMatrix(stdout, x, 4, 1);

    cout << "\n\n******************************* PROOf GAUSS *******************************";
    //EVIDENCE OF RESULT
    //To check if the calculation is correct, we need to multiply A by x and one must find the matrix b.
    matrixMultiplyNaive (b2,A,x, 4,4,1);

    cout << "\n\n------ RESULT b Gauss : ";
    writeMatrix(stdout, b2, 4, 1);

    cout << "\n\n------ RESULT b Triangulize : ";
    writeMatrix(stdout, b1, 4, 1);

    cout << "\nb Gauss equals b Triangularize ! " << endl;
    return 0;

}
