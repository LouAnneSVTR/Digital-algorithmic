#include <iostream>  // cout, cin
#include <math.h>  // partie entière (floor)
#include <iomanip> // pour setprecision
#include "Fonction.h"
#include "Dichotomie.h"
#include "Newton.h"
#include "Sommation.h"

using namespace std;


int main() {

    //Variables :
    intervalle i, iFinal;

    //Debut :

    //Exercice 1 : Affichage des sommations
   /* cout << "\nExercice 1 :" << endl;
    affichageSommation(); //donne les resultats pour les 6 fonctions de sommations pour une valeur n saisie par l'utilisateur

    //---------------------------------------------------------------------------------
    //Exercice 2*/
    cout << "\n\nExercice 2 :"<<endl;

    //Polynome 1 :
    cout << "\n************* Polynome 1 *************"<<endl;
    saisieIntervalle(i); //Permet de saisir l'intevalle de debut pour la recherche de Dichotomie
    iFinal = dichotomie(i,polynome1); //Appel de la methode Dichotomie
    affichageDichotomie(iFinal);

    appelNewton(polynome1);

    //Polynome 2 :
    cout << "\n\n************* Polynome 2 *************"<<endl;
    saisieIntervalle(i);
    iFinal = dichotomie(i,polynome2);
    affichageDichotomie(iFinal);

    appelNewton(polynome2);

    //Polynome 3 :
    cout << "\n\n************* Polynome 3 *************"<<endl;
    saisieIntervalle(i);
    iFinal = dichotomie(i,polynome3);
    affichageDichotomie(iFinal);

    appelNewton(polynome3);

    //Polynome 4 :
    cout << "\n\n************* Polynome 4 *************"<<endl;
    saisieIntervalle(i);
    iFinal = dichotomie(i,polynome4);
    affichageDichotomie(iFinal);

    appelNewton(polynome4);
}

//Fin du Main

