#include "planete.h"

int main(){

    //test();

    Planete Mercure = initPremierPoint("mercure",MASSE_MERCURE,PERIHELIE_MERCURE,EXCENTRICITE_MERCURE,DEMI_GRAND_AXE_MERCURE,MASSE_SOLEIL);
    Planete Venus = initPremierPoint("venus",MASSE_VENUS,PERIHELIE_VENUS,EXCENTRICITE_VENUS,DEMI_GRAND_AXE_VENUS,MASSE_SOLEIL);
    Planete Terre = initPremierPoint("earth",MASSE_TERRE,PERIHELIE_TERRE,EXCENTRICITE_TERRE,DEMI_GRAND_AXE_TERRE,MASSE_SOLEIL);
    Planete Mars = initPremierPoint("mars",MASSE_MARS,PERIHELIE_MARS,EXCENTRICITE_MARS,DEMI_GRAND_AXE_MARS,MASSE_SOLEIL);
    Planete Jupiter = initPremierPoint("jupiter",MASSE_JUPITER,PERIHELIE_JUPITER,EXCENTRICITE_JUPITER,DEMI_GRAND_AXE_JUPITER,MASSE_SOLEIL);
    Planete Saturne = initPremierPoint("saturne",MASSE_SATURNE,PERIHELIE_SATURNE,EXCENTRICITE_SATURNE,DEMI_GRAND_AXE_SATURNE,MASSE_SOLEIL);
    Planete Uranus = initPremierPoint("uranus",MASSE_URANUS,PERIHELIE_URANUS,EXCENTRICITE_URANUS,DEMI_GRAND_AXE_URANUS,MASSE_SOLEIL);
    Planete Neptune = initPremierPoint("neptune",MASSE_NEPTUNE,PERIHELIE_NEPTUNE,EXCENTRICITE_NEPTUNE,DEMI_GRAND_AXE_NEPTUNE,MASSE_SOLEIL);
    Planete Lune = initPremierPoint("moon",MASSE_LUNE,PERIGEE,EXCENTRICITE_LUNE,DEMI_GRAND_AXE_LUNE,MASSE_TERRE);

    Mercure = Euler(Mercure);
    Venus = Euler(Venus);
    Terre = Euler(Terre);
    Mars = Euler(Mars);
    Jupiter = Euler(Jupiter);
    Saturne = Euler(Saturne);
    Uranus = Euler(Uranus);
    Neptune = Euler(Neptune);
    Lune = eulerLune(Lune,Terre);

    Planete systemeSolaireEuler[9] = {Mercure,Venus,Terre,Lune,Mars,Jupiter,Saturne,Uranus,Neptune};

    Mercure = eulerAsymetrique(Mercure);
    Venus = eulerAsymetrique(Venus);
    Terre = eulerAsymetrique(Terre);
    Mars = eulerAsymetrique(Mars);
    Jupiter = eulerAsymetrique(Jupiter);
    Saturne = eulerAsymetrique(Saturne);
    Uranus = eulerAsymetrique(Uranus);
    Neptune = eulerAsymetrique(Neptune);

    Planete systemeSolaireAsymEuler[8] = {Mercure,Venus,Terre,Mars,Jupiter,Saturne,Uranus,Neptune};


    save(systemeSolaireEuler,"euler.json");
    //save(systemeSolaireAsymEuler,"eulerAsym.json");
}