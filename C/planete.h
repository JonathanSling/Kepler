#include "point.h"

#define NB_PLANETE 8

#define CARACTERE_MAX 16
#define G 6.674184*pow(10,(-11))
#define MASSE_SOLEIL 1.98892*pow(10,30)

#define MASSE_TERRE 5.972*pow(10,24)
#define PERIHELIE_TERRE 147*pow(10,9)
#define EXCENTRICITE_TERRE 0.016
#define DEMI_GRAND_AXE_TERRE 149.6*pow(10,9)

#define MASSE_MERCURE 3.285*pow(10,23)
#define PERIHELIE_MERCURE 46*pow(10,9)
#define EXCENTRICITE_MERCURE 0.2
#define DEMI_GRAND_AXE_MERCURE 57.91*pow(10,9)

#define MASSE_MARS  0.642*pow(10,24)
#define PERIHELIE_MARS 206.7*pow(10,9)
#define EXCENTRICITE_MARS 0.093
#define DEMI_GRAND_AXE_MARS 227.9*pow(10,9)

#define MASSE_JUPITER 1.9*pow(10,27)
#define PERIHELIE_JUPITER 740.7*pow(10,9)
#define EXCENTRICITE_JUPITER 0.048
#define DEMI_GRAND_AXE_JUPITER 778.3*pow(10,9)

#define MASSE_VENUS 4.87*pow(10,24)
#define PERIHELIE_VENUS 107.5*pow(10,9)
#define EXCENTRICITE_VENUS 0.0068
#define DEMI_GRAND_AXE_VENUS 108.2*pow(10,9)

#define MASSE_SATURNE 568*pow(10,24)
#define PERIHELIE_SATURNE 1349.8*pow(10,9)
#define EXCENTRICITE_SATURNE 0.056
#define DEMI_GRAND_AXE_SATURNE 1429*pow(10,9)

#define MASSE_URANUS 86.8*pow(10,24)
#define PERIHELIE_URANUS 2735*pow(10,9)
#define EXCENTRICITE_URANUS 0.046
#define DEMI_GRAND_AXE_URANUS 2875*pow(10,9)

#define MASSE_NEPTUNE 102*pow(10,24)
#define PERIHELIE_NEPTUNE 4459.7*pow(10,9)
#define EXCENTRICITE_NEPTUNE 0.0086
#define DEMI_GRAND_AXE_NEPTUNE 4504*pow(10,9)

#define MASSE_LUNE 7.6*pow(10,22)
#define PERIGEE 356*pow(10,6)
#define EXCENTRICITE_LUNE 0.0515
#define DEMI_GRAND_AXE_LUNE 384.7*pow(10,6)

typedef struct Planete Planete;

struct Planete{

    char nom[CARACTERE_MAX];
    double masse;
    Trajectoire trajectoire;
    double perihelie;
    double excentricite;
    double demiAxe;
};

Planete initPremierPoint(char nom[CARACTERE_MAX], double masse, double perihelie, double excentricite, double demiAxe, double massePlanete);
double vitessePerihelie(Planete planete, double massePlanete);
Planete Euler(Planete planete);
Planete eulerLune(Planete lune, Planete terre);
Planete eulerAsymetrique(Planete planete);
double acceleration(Vecteur u);
double accelerationTerrelune(Vecteur u);
double Ep(Planete p1, Planete p2, int indice);
double Ec(Planete p1, int indice);
double Em(double Ep, double Ec);
void save(Planete *planete, char *fichier);