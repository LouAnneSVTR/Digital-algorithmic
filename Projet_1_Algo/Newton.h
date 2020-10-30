#include <iostream>  // cout, cin
#include <math.h>  // partie entière (floor)
using namespace std;

#ifndef UNTITLED1_NEWTON_H
#define UNTITLED1_NEWTON_H
#endif //UNTITLED1_NEWTON_H

//Algorithme pour calculer la dérivé, utilise la methode de la secante donne dans le sujet
double secante(double (*pointFonc)(double), double x0, double x1) {
    return ((*pointFonc)(x1) - (*pointFonc)(x0)) / (x1 - x0);
}


//Algorithme de Newton
//Role : calcule en double une valeur x telle que f(x)=0 a une precision e donnée
//Sortie : double resultat de f(x)=0
void newton (double x0, double (*pointFonc)(double)) {

    //Variables

    double e; //represente la precision epsilon
    double x1, deriveFonc; //derive de la fonction en parametre

    //Début :

    cout << "A quelle valeur votre resultat doit il approcher ?" << endl;
    cin >> e ;

    x1 = x0 - e; //Pour obtenir le x1 très proche du x0 sans passer par la méthode de la secante

    while (fabs((pointFonc)(x0)) > e) {
        deriveFonc = secante(pointFonc, x0, x1);
        x1 = x0;
        x0 = x0 - ((*pointFonc)(x0) / deriveFonc); //iteration de Newton
    }

    cout << "- Le resultat est par la methode de Newton est : " << x0 << endl;
}


//Appel la methode de Newton et introduit la valeur x0 qui debutera la recherche de solution
void appelNewton(double (*pointFonc)(double)){

    //Variable
    double x_0;

    //Debut
    cout << "\nNEWTON\nA quelle valeur voulez-vous commencer votre recherche de solution ?"<< endl;
    cin >> x_0;
    newton(x_0, pointFonc);
}

//Fin Newton