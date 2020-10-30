#ifndef UNTITLED1_FONCTION_H
#define UNTITLED1_FONCTION_H

#endif //UNTITLED1_FONCTION_H

//Exercice 2 : fonctions de création des polynomes

double polynome1 ( double x) { //x^3 − 2^x − 5 = 0
    return -5 - x*(2 - x*(x));
}

double polynome2 (double x){ // e^-x = x
    return -x+exp(-x);
}

double polynome3 (double x){ // xsin(x)=1
    return -1+x*(sin(x));
}

double polynome4 (double x) { // x^3−3x^2+3x−1=0
    return -1+x*(3+x*(3+1*x));
}

//Fin polynome

