#include "SDL.h"
#include "clashloyal.h"
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

//typedef Tunite* ** TplateauJeu;

TplateauJeu AlloueTab2D(int largeur, int hauteur){
    TplateauJeu jeu;
    jeu = (Tunite***)malloc(sizeof(Tunite**)*largeur);
    for (int i=0;i<largeur;i++){
        jeu[i] = (Tunite**)malloc(sizeof(Tunite*)*hauteur);
    }
    return jeu;  //tab2D contenant des pointeurs
}
void initPlateauAvecNULL(TplateauJeu jeu,int largeur, int hauteur){
    for (int i=0;i<largeur;i++){
        for (int j=0;j<hauteur;j++){
            jeu[i][j] = NULL;
        }
    }

    //POUR LA DEMO D'AFFICHAGE UNIQUEMENT, A SUPPRIMER
    //(les tours ici ne sont pas liées aux listes des unités de vos joueurs)
    jeu[5][3]=creeTour(5,3);
    jeu[5][1]=creeTourRoi(5,1);
    jeu[5][15]=creeTour(5,15);
    jeu[5][17]=creeTourRoi(5,17);
    jeu[5][14]=creeArcher(5, 14);
    //FIN DEMO AFFICHAGE
}

void affichePlateauConsole(TplateauJeu jeu, int largeur, int hauteur){
    //pour un affichage sur la console, en relation avec enum TuniteDuJeu
    const char* InitialeUnite[6]={"T", "R", "A", "C", "D", "G"};

    printf("\n");
    for (int j=0;j<hauteur;j++){
        for (int i=0;i<largeur;i++){
                // A ne pas donner aux etudiants
            if (jeu[i][j] != NULL){
                    printf("%s",InitialeUnite[jeu[i][j]->nom]);
            }
            else printf(" ");  //cad pas d'unité sur cette case
        }
        printf("\n");
    }
}

Tunite *creeTour(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, tour);
    setCibleAttaquable(nouv, solEtAir);
    setMaPosition(nouv, sol);
    setPV(nouv, 500);
    setVitesseAttaque(nouv, 1.0);
    setDegats(nouv, 100);
    setPortee(nouv, 3);
    setVitesseDeplacement(nouv, 0.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 0);
    return nouv;
}

Tunite *creeTourRoi(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, tourRoi);
    setCibleAttaquable(nouv, solEtAir);
    setMaPosition(nouv, sol);
    setPV(nouv, 800);
    setVitesseAttaque(nouv, 1.2);
    setDegats(nouv, 120);
    setPortee(nouv, 4);
    setVitesseDeplacement(nouv, 0.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 0);
    return nouv;
}

bool tourRoiDetruite(TListePlayer player){
    return getPV(getPdata(player)) <= 0;
}

Tunite *creeArcher(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, archer);
    setCibleAttaquable(nouv, solEtAir);
    setMaPosition(nouv, sol);
    setPV(nouv, 80);
    setVitesseAttaque(nouv, 0.7);
    setDegats(nouv, 120);
    setPortee(nouv, 3);
    setVitesseDeplacement(nouv, 2.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 2);
    return nouv;
}

Tunite *creeGargouille(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, gargouille);
    setCibleAttaquable(nouv, solEtAir);
    setMaPosition(nouv, air);
    setPV(nouv, 80);
    setVitesseAttaque(nouv, 0.6);
    setDegats(nouv, 90);
    setPortee(nouv, 1);
    setVitesseDeplacement(nouv, 3.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 1);
    return nouv;
}

Tunite *creeDragon(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, dragon);
    setCibleAttaquable(nouv, solEtAir);
    setMaPosition(nouv, air);
    setPV(nouv, 200);
    setVitesseAttaque(nouv, 1.1);
    setDegats(nouv, 70);
    setPortee(nouv, 2);
    setVitesseDeplacement(nouv, 2.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 3);
    return nouv;
}

Tunite *creeChevalier(int posx, int posy){
    Tunite *nouv = (Tunite*)malloc(sizeof(Tunite));
    setNomU(nouv, chevalier);
    setCibleAttaquable(nouv, sol);
    setMaPosition(nouv, sol);
    setPV(nouv, 400);
    setVitesseAttaque(nouv, 1.5);
    setDegats(nouv, 250);
    setPortee(nouv, 1);
    setVitesseDeplacement(nouv, 2.0);
    setPosX(nouv, posx);
    setPosY(nouv, posy);
    setPeutAttaquer(nouv, 1);
    setCoutElixir(nouv, 4);
    return nouv;
}


void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite, TplateauJeu jeu){
    TListePlayer copie = player;
    int comp = 0;
    while (getPdata(copie) != UniteDetruite){
            copie = getptrNextCell(copie);
            comp ++;
    }
    SuppEnN(copie, comp);
    jeu[getPosx(UniteDetruite)][getPosy(UniteDetruite)] = NULL;
    free(getPdata(&copie));
    free(&copie);
}

/*
TListePlayer quiEstAPortee(TListePlayer player, Tunite *uneUniteDeLautreJoueur){
    TListePlayer attaquants;
    initListe(&attaquants);

}
*/
