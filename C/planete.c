#include "planete.h"

//  Initialisation du premier point

Planete initPremierPoint(char nom[CARACTERE_MAX], double masse, double perihelie, double excentricite, double demiAxe, double massePlanete){

    Planete planete;

    strcpy(planete.nom,nom);
    planete.masse = masse;
    planete.perihelie = perihelie;
    planete.excentricite = excentricite;
    planete.demiAxe = demiAxe;

    planete.trajectoire.listePoint = malloc(NB_POINT * sizeof(Point));

    planete.trajectoire.listePoint[0].r.x = planete.perihelie;
    planete.trajectoire.listePoint[0].r.y = 0;
    planete.trajectoire.listePoint[0].r.z = 0;

    planete.trajectoire.listePoint[0].v.x = 0;
    planete.trajectoire.listePoint[0].v.y = vitessePerihelie(planete,massePlanete);
    planete.trajectoire.listePoint[0].v.z = 0;

    return planete;
}

//  Vitesse de la planète au momnet où la distance est la plus petite

double vitessePerihelie(Planete planete, double massePlanete){

    double r = planete.demiAxe * (1 - planete.excentricite);

    return sqrt((G * (massePlanete + planete.masse) * (1 + planete.excentricite))/r);
}

//  Première méthode de calcul 

Planete Euler(Planete planete){

    int t = PAS;

    for(int i = 0 ; i < NB_POINT ; i++){

        //  Accélération à t

        planete.trajectoire.listePoint[i].a = scalaire(planete.trajectoire.listePoint[i].r, acceleration(planete.trajectoire.listePoint[i].r));

        //  Position à t+1

        // Position en x
        planete.trajectoire.listePoint[i + 1].r.x = planete.trajectoire.listePoint[i].r.x + planete.trajectoire.listePoint[i].v.x * t;

        //  Position en y
        planete.trajectoire.listePoint[i + 1].r.y = planete.trajectoire.listePoint[i].r.y + planete.trajectoire.listePoint[i].v.y * t;

        //  Position en z
        planete.trajectoire.listePoint[i + 1].r.z = planete.trajectoire.listePoint[i].r.z + planete.trajectoire.listePoint[i].v.z * t;

        //  Vitesse à t+1

        //  Vitesse en x
        planete.trajectoire.listePoint[i + 1].v.x = planete.trajectoire.listePoint[i].v.x + planete.trajectoire.listePoint[i].a.x * t;

        //  Vitesse en y
        planete.trajectoire.listePoint[i + 1].v.y = planete.trajectoire.listePoint[i].v.y + planete.trajectoire.listePoint[i].a.y * t;

        //  Vitesse en z
        planete.trajectoire.listePoint[i + 1].v.z = planete.trajectoire.listePoint[i].v.z + planete.trajectoire.listePoint[i].a.z * t;
    }

    return planete;
}

Planete eulerLune(Planete lune, Planete terre){

    int t = PAS;

    for(int i = 0 ; i < NB_POINT ; i++){

        //  Accélération à t

        lune.trajectoire.listePoint[i].a = scalaire(lune.trajectoire.listePoint[i].r, accelerationTerrelune(lune.trajectoire.listePoint[i].r));

        //  Position à t+1

        // Position en x
        lune.trajectoire.listePoint[i + 1].r.x = lune.trajectoire.listePoint[i].r.x + lune.trajectoire.listePoint[i].v.x * t + terre.trajectoire.listePoint[i].r.x;

        //  Position en y
        lune.trajectoire.listePoint[i + 1].r.y = lune.trajectoire.listePoint[i].r.y + lune.trajectoire.listePoint[i].v.y * t + terre.trajectoire.listePoint[i].r.y;

        //  Position en z
        lune.trajectoire.listePoint[i + 1].r.z = lune.trajectoire.listePoint[i].r.z + lune.trajectoire.listePoint[i].v.z * t + terre.trajectoire.listePoint[i].r.z;

        //  Vitesse à t+1

        //  Vitesse en x
        lune.trajectoire.listePoint[i + 1].v.x = lune.trajectoire.listePoint[i].v.x + lune.trajectoire.listePoint[i].a.x * t;

        //  Vitesse en y
        lune.trajectoire.listePoint[i + 1].v.y = lune.trajectoire.listePoint[i].v.y + lune.trajectoire.listePoint[i].a.y * t;

        //  Vitesse en z
        lune.trajectoire.listePoint[i + 1].v.z = lune.trajectoire.listePoint[i].v.z + lune.trajectoire.listePoint[i].a.z * t;
    }

    return lune;
}
//  Calcul accélération 

double acceleration(Vecteur u){

    return (-G * MASSE_SOLEIL)/pow(norme(u),3);
}

double accelerationTerrelune(Vecteur u){

    return (-G * MASSE_TERRE)/pow(norme(u),3);
}


//  Deuxième méthode de calcul

Planete eulerAsymetrique(Planete planete){

    int t = PAS;

    for(int i = 0 ; i < NB_POINT ; i++){

        //  Position à t+1

        //  Postion en x
        planete.trajectoire.listePoint[i + 1].r.x = planete.trajectoire.listePoint[i].r.x + planete.trajectoire.listePoint[i].v.x * t;

        //  Position en y
        planete.trajectoire.listePoint[i + 1].r.y = planete.trajectoire.listePoint[i].r.y + planete.trajectoire.listePoint[i].v.y * t;

        //  Position en z
        planete.trajectoire.listePoint[i + 1].r.z = planete.trajectoire.listePoint[i].r.z + planete.trajectoire.listePoint[i].v.z * t;

        //  Accélération à t + 1

        planete.trajectoire.listePoint[i + 1].a = scalaire(planete.trajectoire.listePoint[i + 1].r,acceleration(planete.trajectoire.listePoint[i + 1].r));

        //  Vitesse à t+1

        //  Vitesse en x
        planete.trajectoire.listePoint[i + 1].v.x = planete.trajectoire.listePoint[i].v.x + planete.trajectoire.listePoint[i + 1].a.x * t;

        //  Vitesse en y
        planete.trajectoire.listePoint[i + 1].v.y = planete.trajectoire.listePoint[i].v.y + planete.trajectoire.listePoint[i + 1].a.y * t;

        //  Vitesse en z
        planete.trajectoire.listePoint[i + 1].v.z = planete.trajectoire.listePoint[i].v.z + planete.trajectoire.listePoint[i + 1].a.z * t;
    }

    return planete;
}


//Energie potentielle

double Ep(Planete p1, Planete p2, int indice){

    return (G * p1.masse * p2.masse)/pow(norme(p1.trajectoire.listePoint[indice].r),2);
}

//Energie cinétique

double Ec(Planete p1, int indice){

    return (1/2) * p1.masse * pow(norme(p1.trajectoire.listePoint[indice].v),2);
}


//Energie mécanique

double Em(double Ep, double Ec){

    return Ep + Ec;
}

//  Persistance mémoire

void save(Planete *planete,char *fichierNom){

    FILE *fichier = NULL;

    if(strcmp(fichierNom,"euler.json") == 0){

        fichier = fopen("euler.json","w+");

    }else if(strcmp(fichierNom,"eulerAsym.json") == 0){

        fichier = fopen("eulerAsym.json","w+");
    }

    if(fichier != NULL){

        fprintf(fichier,"{");

        for(int i = 0 ; i < NB_PLANETE ; i++){

            fprintf(fichier,"\"%s\" : [",planete[i].nom);

            for(int j = 0 ; j < NB_POINT ; j++){

                if(j != NB_POINT - 1){

                    fprintf(fichier,"[[%e, %e, %e],[%e,%e,%e],%d],\n",planete[i].trajectoire.listePoint[j].r.x,planete[i].trajectoire.listePoint[j].r.y,planete[i].trajectoire.listePoint[j].r.z,planete[i].trajectoire.listePoint[j].v.x,planete[i].trajectoire.listePoint[j].v.y,planete[i].trajectoire.listePoint[j].v.z,j);

                }else if(i == NB_PLANETE - 1 && j == NB_POINT - 1){

                    fprintf(fichier,"[[%e, %e, %e],[%e,%e,%e],%d]]",planete[i].trajectoire.listePoint[j].r.x,planete[i].trajectoire.listePoint[j].r.y,planete[i].trajectoire.listePoint[j].r.z,planete[i].trajectoire.listePoint[j].v.x,planete[i].trajectoire.listePoint[j].v.y,planete[i].trajectoire.listePoint[j].v.z,j);

                }else{

                    fprintf(fichier,"[[%e, %e, %e],[%e,%e,%e],%d]],\n",planete[i].trajectoire.listePoint[j].r.x,planete[i].trajectoire.listePoint[j].r.y,planete[i].trajectoire.listePoint[j].r.z,planete[i].trajectoire.listePoint[j].v.x,planete[i].trajectoire.listePoint[j].v.y,planete[i].trajectoire.listePoint[j].v.z,j);
                }
            }
        }

        fprintf(fichier,"\n}");
    }
}