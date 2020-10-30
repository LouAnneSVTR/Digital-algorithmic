#include <iostream>  // cout, cin
using namespace std;

#ifndef UNTITLED1_SOMMATION_H
#define UNTITLED1_SOMMATION_H

#endif //UNTITLED1_SOMMATION_H

//------------------------------------------------------------------------------------
//Fonctions croissantes
double sommationCroissante1(int n){
    //Variables
     double resultat;

    //Debut
    resultat = 0;

    for(int i = 1; i <= n ; i++){
        resultat = resultat + 1.0/i;
    }
    return resultat;
}

float sommationCroissante2(int n){
    //Variables
    float resultat;

    //Debut
    resultat = 0;

    for(int i = 1; i <= n ; i++){
        resultat = resultat + 1.0/i;
    }
    return resultat;
}

//------------------------------------------------------------------------------------
//Fonctions décroissantes
double sommationDecroissante1(int n){
    //Variables
    double resultat;

    //Debut
    resultat = 0;

    for(int i = n; i >= 1 ; i--){
        resultat = resultat + 1.0/i;
    }
    return resultat;
}

float sommationDecroissante2(int n){
    //Variables
    float resultat;

    //Debut
    resultat = 0;

    for(int i = n; i >= 1 ; i--){
        resultat = resultat + 1.0/i;
    }
    return resultat;
}

//------------------------------------------------------------------------------------
//Fonctions décroissantes
double sommationPrecision1(int n){
    //Variables
    double s, c, y, t;

    //Debut
    s = 1.0/1;
    c = 0 ;// c représente l’erreur à chaque addition

    for(int i = 2 ; i<= n ; i++ ){
        y =  (1.0/i) - c ;// on additionne l’erreur de l’addition précédente au terme courant
        t = s + y;
        c = (t - s) - y;
        s = t;
    }
    return s;
}

float sommationPrecision2(int n){
    //Variables
    float s, c, y, t;

    //Debut
    s = 1.0/1;
    c = 0 ;// c représente l’erreur à chaque addition

    for(int i = 2 ; i<= n ; i++ ){
        y =  (1.0/i) - c ;// on additionne l’erreur de l’addition précédente au terme courant
        t = s + y; //addition du x_i + x_i+1
        c = (t - s) - y;
        s = t;
    }
    return s;
}

//------------------------------------------------------------------------------------
//Fonctions d'affichage

string affichageSommation (){

    //Variables
    int n;

    //Debut
    cout << "Quelle est la valeur de fin de vos sommes ?" << endl;
    cin >> n;

    cout << "\nRESULTATS DES SOMMATIONS\n\nSomme croissante :"<< endl;
    cout << "   - double : " << setprecision(16) << sommationCroissante1(n) << endl;
    cout << "   - float : " << setprecision(7) << sommationCroissante2(n) << endl;

    cout << "\nSomme decroissante :"<< endl;
    cout << "   - double : " << setprecision(16) << sommationDecroissante1(n) << endl;
    cout << "   - float : " << setprecision(7) << sommationDecroissante1(n) << endl;

    cout << "\nSomme avec precision :"<< endl;
    cout << "   - double : " << setprecision(16) << sommationPrecision1(n)<< endl;
    cout << "   - float : " << setprecision(7) << sommationPrecision2(n) << endl;

}

//Fin Sommation