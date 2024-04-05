#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Listelib.h"
#include "types.h"


void initListe(T_liste *l){
    *l = NULL;
}

bool listeVide(T_liste l){
    return (l==NULL);
}

T_liste ajoutEnTete(T_liste l, Tunite *mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_Cell));
    nouv->pdata = mydata;

    nouv->suiv = l;
    nouv->prec = NULL;
    if(l!=NULL){
        l->prec = nouv;
    }
    return nouv;
}

T_liste ajoutEnFin(T_liste l, Tunite *mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_Cell));
    nouv->pdata = mydata;

    if(l==NULL){
        nouv->prec=NULL;
        nouv->suiv=NULL;
        return nouv;
    }
    else{
        T_liste temp = l;
        while(temp->suiv!=NULL){
            temp=temp->suiv;
        }
        temp->suiv=nouv;
        nouv->prec=temp;
        nouv->suiv=NULL;
    }
    return l;
}

T_liste ajoutEnN(T_liste l,int pos, Tunite *mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_Cell));
    nouv->pdata = mydata;

    if(l==NULL){
        nouv->prec=NULL;
        nouv->suiv=NULL;
        return NULL;
    }
    else{
        if(pos<=0){
            return ajoutEnTete(l,mydata);
        }
        else{
            int comp = 0;
            T_liste temp = l;
            while(temp->suiv!=NULL&&pos>comp){
                temp=temp->suiv;
                comp++;
            }
            if(comp==pos){
                temp->prec->suiv=nouv;
                nouv->prec=temp->prec;
                temp->prec=nouv;
                nouv->suiv=temp;
                return l;
            }
            else{
                return ajoutEnFin(l,mydata);
            }
        }
    }
}

T_liste SuppEnTete(T_liste l){
    if(l!=NULL){
        if(l->suiv!=NULL){
            T_liste nouv = l->suiv;
            free(l);
            return nouv;
        }
        else{
            free(l);
            return NULL;
        }
    }
    else{
        return NULL;
    }
}

T_liste SuppEnFin(T_liste l){
    if(l!=NULL){
        T_liste nouv = l;
        while(nouv->suiv!=NULL){
            nouv=nouv->suiv;
        }
        if(nouv->prec==NULL){
            return NULL;
        }
        else{
            nouv->prec->suiv=NULL;
            nouv->prec=NULL;
            nouv->suiv=NULL;
            free(nouv);
            return l;
        }
    }
    else{
        return NULL;
    }
}

T_liste SuppEnN(T_liste l,int pos){
    if(pos<=0){
        return SuppEnTete(l);
    }
    else{
        int comp = 0;
        T_liste nouv = l;
        while(nouv->suiv!=NULL&&comp<pos){
            nouv=nouv->suiv;
            comp++;
        }
        if(comp==pos){
            if(nouv->suiv!=NULL){
                nouv->prec->suiv=nouv->suiv;
                nouv->suiv->prec=nouv->prec;
                nouv->suiv=NULL;
                nouv->prec=NULL;
                free(nouv);
            }
            else{
                nouv->prec->suiv=NULL;
                nouv->suiv=NULL;
                nouv->prec=NULL;
                free(nouv);
            }
            return l;
        }
        else{
            return SuppEnFin(l);
        }
    }
}

T_liste getptrFirstCell(T_liste l){
    T_liste actual = l;
    while(actual->prec!=NULL){
        actual = actual->prec;
    }
    return actual;
}

T_liste getptrLastCell(T_liste l){
    T_liste actual = l;
    while(actual->suiv!=NULL){
        actual = actual->suiv;
    }
    return actual;
}

T_liste getptrNextCell(T_liste l){
    return l->suiv;
}

T_liste getptrPrevCell(T_liste l){
    return l->prec;
}

int getNbreCell(T_liste l){
    int comp = 0;
    T_liste temp = getptrFirstCell(l);
    while(temp!=NULL){
        temp=temp->suiv;
        comp++;
    }
    return comp;
}

int getSizeBytes(T_liste l){
    int taille = sizeof(struct T_Cell)*getNbreCell(l);
    return taille;
}

T_liste creatNewListeFromFusion(T_liste l1,T_liste l2){
    T_liste nouv;initListe(&nouv);
    T_liste l1bis=l1;T_liste l2bis=l2;
    while(l1bis!=NULL){
        nouv=ajoutEnFin(nouv,l1bis->pdata);
        l1bis=l1bis->suiv;
    }
    while(l2bis!=NULL){
        nouv=ajoutEnFin(nouv,l2bis->pdata);
        l2bis=l2bis->suiv;
    }
    return nouv;
}

T_liste addBehind(T_liste debut,T_liste suite){
    T_liste start = getptrFirstCell(suite);
    T_liste end = getptrLastCell(debut);
    if(start==NULL){
        return debut;
    }
    else if(end==NULL){
        return suite;
    }
    else{
        end->suiv=start;
        start->prec=end;
        return debut;
    }
}

T_liste findCell(T_liste l, Tunite *data){
    int verif = 0;
    T_liste temp = l;
    while(temp != NULL && verif != 1){
        if(temp->pdata != data){
            temp = temp->suiv;
        }
        else{
            verif = 1;
            printf("ok");
        }
    }
    return temp;
}
