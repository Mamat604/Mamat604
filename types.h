#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

typedef enum{tour, tourRoi, archer, chevalier, dragon, gargouille} TuniteDuJeu;
typedef enum{sol, solEtAir, air } Tcible;


typedef struct {
    TuniteDuJeu nom;
    Tcible cibleAttaquable;	//indique la position des unités que l’on peut attaquer
    Tcible maposition;		//indique soit « air » soit « sol », utile pour savoir
                            //qui peut nous attaquer
    int pointsDeVie;
    float vitesseAttaque;	//en seconde, plus c’est petit plus c’est rapide
    int degats;
    int portee ;			//en mètre, distance sur laquelle on peut atteindre une
                            //cible

    float vitessedeplacement;	//en m/s
    int posX, posY;			//position sur le plateau de jeu
    int peutAttaquer;		//permet de gérer le fait que chaque unité attaque une
                            //seule fois par tour ;
                            //0 = a déjà attaqué, 1 = peut attaquer ce tour-ci
                            // à remettre à 1 au début de chaque tour
    int coutEnElixir;
    int team; // 1 = équipe bleue (du bas) 2 = équipe rouge (du haut)
} Tunite;

typedef struct T_Cell{
    struct T_Cell *suiv;
    struct T_Cell *prec;
    Tunite *pdata; //pointeur vers une unité
} *T_liste;

typedef T_liste TListePlayer;

//getters
TListePlayer getSuivant(TListePlayer x);
Tunite *getPdata(TListePlayer x);
TuniteDuJeu getNom(Tunite *x);
Tcible getCibleAttaquable(Tunite *x);
Tcible getMaPosition(Tunite *x);
int getPV(Tunite *x);
float getVitesseAttaque(Tunite *x);
int getDegats(Tunite *x);
int getPortee(Tunite *x);
float getVitesseDeplacement(Tunite *x);
int getPosx(Tunite *x);
int getPosy(Tunite *x);
int getPeutAttaquer(Tunite *x);
int getCoutElixir(Tunite *x);
int getTeam(Tunite *x);

//setters
void setSuivant(TListePlayer x, TListePlayer y);
void setPdata(TListePlayer x, Tunite *y);
void setNomU(Tunite *x, TuniteDuJeu nouv);
void setCibleAttaquable(Tunite *x, Tcible attaque);
void setMaPosition(Tunite *x, Tcible position);
void setPV(Tunite *x, int pv);
void setVitesseAttaque(Tunite *x, float VitesseAtt);
void setDegats(Tunite *x, float Damage);
void setPortee(Tunite *x, int Lointain);
void setVitesseDeplacement(Tunite *x, float VitesseDep);
void setPosX(Tunite *x, int xi);
void setPosY(Tunite *x, int yi);
void setPeutAttaquer(Tunite *x, int oof);
void setCoutElixir(Tunite *x, int prix);
void setTeam(Tunite *x, int equipe);

#endif
