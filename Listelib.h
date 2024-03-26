#ifndef LISTELIB_H_INCLUDED
#define LISTELIB_H_INCLUDED

#include <stdbool.h>
#include "types.h"

void initListe(T_liste *l);

bool listeVide(T_liste l);

T_liste ajoutEnTete(T_liste l, Tunite mydata);

T_liste ajoutEnFin(T_liste l, Tunite mydata);

T_liste ajoutEnN(T_liste l,int pos, Tunite mydata);

T_liste SuppEnTete(T_liste l);

T_liste SuppEnFin(T_liste l);

T_liste SuppEnN(T_liste l, int pos);

T_liste getptrFirstCell(T_liste l);

T_liste getptrLastCell(T_liste l);

T_liste getptrNextCell(T_liste l);

T_liste getptrPrevCell(T_liste l);

int getNbreCell(T_liste l);

int getSizeBytes(T_liste l);

T_liste creatNewListeFromFusion(T_liste l1,T_liste l2);

T_liste addBehind(T_liste debut,T_liste suite);

#endif // LISTELIB_H_INCLUDED
