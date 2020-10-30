#include <iostream>  // cout, cin
using namespace std;

#ifndef UNTITLED1_DICHOTOMIE_H
#define UNTITLED1_DICHOTOMIE_H
#endif //UNTITLED1_DICHOTOMIE_H


//Definition du type intervalle utilisé pour la dichotomie
//Intervalle est composé de sa borne superieur et de sa borne inferieur
typedef struct intervalle {
    double borneMin ;
    double borneMax ;
} intervalle ;

//Permet a l'utilisateur de saisir l'intervalle de recherche de solution
void saisieIntervalle(intervalle & i){
    //Debut
    cout << "\nDICHOTOMIE" << endl;
    cout << "Quelle est la valeur de votre borne Min ?" << endl;
    cin >> i.borneMin ;
    cout << "Quelle est la valeur de votre borne Max ?" << endl;
    cin >> i.borneMax ;
}


//Algorithme de la Dichotomie
//Role : rend un intervalle contenant la solution pf(x0) = 0 avec une precision donné (e)
//Sortie : intervalle i
intervalle dichotomie(intervalle inter, double (*pointFonc)(double)) {
    //Variables
    double m; //Milieu de l'intervalle calcule entre min et max
    double eps; //Precision epsilon

    //Début :
    cout << "A quelle valeur votre resultat doit il approcher ?" << endl;
    cin >> eps;

    while (inter.borneMax - inter.borneMin > eps) {
        m = (inter.borneMin + inter.borneMax) / 2;

        if ((*pointFonc)(m) * (*pointFonc)(inter.borneMin) <= 0) {
            inter.borneMax = m;
        } else {
            inter.borneMin = m;
        }
    }
    return inter;
}

//Algorithme d'affichage de la Dichotomie
void affichageDichotomie (intervalle i){
    cout << "- L'intervalle est : " << "[" << i.borneMin << " ; " << i.borneMax << "]" << endl;
}

//Fin Dichotomie