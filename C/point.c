#include "point.h"

double norme(Vecteur u){

    return sqrt(pow(u.x,2) + pow(u.y,2) + pow(u.z,2));
}

Vecteur addition(Vecteur u, Vecteur v){

    Vecteur w;

    w.x = u.x + v.x;
    w.y = u.y + v.y;
    w.z = u.z + v.z;

    return w;
}

Vecteur soustraction(Vecteur u, Vecteur v){

    Vecteur w;

    w.x = u.x - v.x;
    w.y = u.y - v.y;
    w.z = u.z - v.z;

    return w;
}

Vecteur scalaire(Vecteur u, double v){

    Vecteur w = {u.x * v, u.y * v, u.z * v};

    return w;
}

// void test(){

//     Vecteur u;
//     Vecteur v;
//     Vecteur w;

//     scanf("%lf",&u.x);
//     scanf("%lf",&u.y);
//     scanf("%lf",&u.z);
//     scanf("%lf",&v.x);
//     scanf("%lf",&v.y);
//     scanf("%lf",&v.z);

//     w = addition(u,v);
//     printf("%lf ",w.x);
//     printf("%lf",scalaire(u,v));
// }

// Trajectoire initTrajectoire(Trajectoire trajectoire){

//     trajectoire.listePoint = malloc(NB_POINT * sizeof(Point));

//     return trajectoire;
// }