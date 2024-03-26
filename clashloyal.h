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

Tunite *creeTour(int posx, int posy);
Tunite *creeTourRoi(int posx, int posy);

bool tourRoiDetruite(TListePlayer player);
/*
void PositionnePlayerOnPlateau(TListePlayer player, TplateauJeu jeu)

TListePlayer quiEstAPortee(TListePlayer player, Tunite *uneUniteDeLautreJoueur);
TListePlayer combat(TListePlayer player, Tunite *uneUniteDeLautreJoueur);
*/

Tunite *creeArcher(int posx, int posy);
Tunite *creeGargouille(int posx, int posy);
Tunite *creeDragon(int posx, int posy);
Tunite *creeChevalier(int posx, int posy);

void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite, TplateauJeu jeu);
/*
Tunite AcheteUnite(int *elixirEnStockduJoueur);
Void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite);

*/

#endif // JEU2048_H_INCLUDED