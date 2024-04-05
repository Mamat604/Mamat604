#ifndef JEU2048_H_INCLUDED
#define JEU2048_H_INCLUDED

#define LARGEURJEU 11
#define HAUTEURJEU 19
#include "types.h"
#include <stdbool.h>


typedef Tunite* ** TplateauJeu;  ////tableau a deux dimensions de largeur 11 et hauteur 19 contenant des pointeurs (Tunite*)

TplateauJeu AlloueTab2D(int largeur, int hauteur);
void initPlateauAvecNULL(TplateauJeu jeu,int largeur, int hauteur);
void affichePlateauConsole(TplateauJeu jeu, int largeur, int hauteur);

Tunite *creeTour(int posx, int posy, int equipe);
Tunite *creeTourRoi(int posx, int posy, int equipe);

bool tourRoiDetruite(TListePlayer player);

TListePlayer quiEstAPortee(TListePlayer player, Tunite *uneUniteDeLautreJoueur);
//TListePlayer combat(TListePlayer player, Tunite *uneUniteDeLautreJoueur);

Tunite *creeArcher(int posx, int posy, int equipe);
Tunite *creeGargouille(int posx, int posy, int equipe);
Tunite *creeDragon(int posx, int posy, int equipe);
Tunite *creeChevalier(int posx, int posy, int equipe);

void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite, TplateauJeu jeu);

Tunite* UnOuDeux(int *el);
Tunite* AcheteUnite(int *elixirEnStockduJoueur);

void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite, TplateauJeu jeu, int team);

#endif // JEU2048_H_INCLUDED
