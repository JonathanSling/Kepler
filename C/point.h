#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NB_POINT 1000000000
#define PAS 8640

typedef struct Vecteur Vecteur;
typedef struct Position Position;
typedef struct Vitesse Vitesse;
typedef struct Acceleration Acceleration;
typedef struct Point Point;
typedef struct Trajectoire Trajectoire;

//--------------------------------------------------------
//  Structure
//--------------------------------------------------------

struct Vecteur{

    double x;
    double y;
    double z;
};

struct Position{

    Vecteur r;
};

struct Vitesse{

    Vecteur v;
};

struct Acceleration{

    Vecteur a;
};

struct Point{

    Vecteur r;
    Vecteur v;
    Vecteur a;
};

struct Trajectoire{

    Point *listePoint;
};

//--------------------------------------------------------
//  Fonction
//--------------------------------------------------------

double norme(Vecteur u);
Vecteur addition(Vecteur u, Vecteur v);
Vecteur soustraction(Vecteur u, Vecteur v);
Vecteur scalaire(Vecteur u, double v);
void test();
//Trajectoire initTrajectoire(Trajectoire trajectoire);