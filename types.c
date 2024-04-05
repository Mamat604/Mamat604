#include "types.h"

TListePlayer getSuivant(TListePlayer x){
    return x->suiv;
}


Tunite *getPdata(TListePlayer x){
    return x->pdata;
}

TuniteDuJeu getNom(Tunite *x){
    return x->nom;
}

Tcible getCibleAttaquable(Tunite *x){
    return x->cibleAttaquable;
}

Tcible getMaPosition(Tunite *x){
    return x->maposition;
}

int getPV(Tunite *x){
    return x->pointsDeVie;
}

float getVitesseAttaque(Tunite *x){
    return x->vitesseAttaque;
}

int getDegats(Tunite *x){
    return x->degats;
}

int getPortee(Tunite *x){
    return x->portee;
}

float getVitesseDeplacement(Tunite *x){
    return x->vitessedeplacement;
}

int getPosx(Tunite *x){
    return x->posX;
}

int getPosy(Tunite *x){
    return x->posY;
}

int getPeutAttaquer(Tunite *x){
    return x->peutAttaquer;
}

int getCoutElixir(Tunite *x){
    return x->coutEnElixir;
}

int getTeam(Tunite *x){
    return x->team;
}

void setSuivant(TListePlayer x, TListePlayer y){
    x->suiv = y;
}

void setPdata(TListePlayer x, Tunite *y){
    x->pdata = y;
}

void setNomU(Tunite *x, TuniteDuJeu nouv){
    x->nom = nouv;
}

void setCibleAttaquable(Tunite *x, Tcible attaque){
    x->cibleAttaquable = attaque;
}

void setMaPosition(Tunite *x, Tcible position){
    x->maposition = position;
}

void setPV(Tunite *x, int pv){
    x->pointsDeVie = pv;
}

void setVitesseAttaque(Tunite *x, float VitesseAtt){
    x->vitesseAttaque = VitesseAtt;
}

void setDegats(Tunite *x, float Damage){
    x->degats = Damage;
}

void setPortee(Tunite *x, int Lointain){
    x->portee = Lointain;
}

void setVitesseDeplacement(Tunite *x, float VitesseDep){
    x->vitessedeplacement = VitesseDep;
}

void setPosX(Tunite *x, int xi){
    x->posX = xi;
}

void setPosY(Tunite *x, int yi){
    x->posY = yi;
}

void setPeutAttaquer(Tunite *x, int oof){
    x->peutAttaquer = oof;
}

void setCoutElixir(Tunite *x, int prix){
    x->coutEnElixir = prix;
}

void setTeam(Tunite *x, int equipe){
    x->team = equipe;
}
