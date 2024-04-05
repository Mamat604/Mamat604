#include "SDL.h"
#include "clashloyal.h"
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "Listelib.h"

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
    jeu[5][3]=creeTour(5,3,2);
    jeu[5][1]=creeTourRoi(5,1,2);
    jeu[5][15]=creeTour(5,15,1);
    jeu[5][17]=creeTourRoi(5,17,1);
    jeu[5][14]=creeArcher(5,14,1);
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

Tunite *creeTour(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}

Tunite *creeTourRoi(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}

bool tourRoiDetruite(TListePlayer player){
    return getPV(getPdata(player)) <= 0;
}

Tunite *creeArcher(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}

Tunite *creeGargouille(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}

Tunite *creeDragon(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}

Tunite *creeChevalier(int posx, int posy, int equipe){
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
    setTeam(nouv, equipe);
    return nouv;
}


void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite, TplateauJeu jeu){
    TListePlayer unite = findCell(*player,UniteDetruite);
    if(unite != NULL){
        unite = SuppEnN(unite,0);
        int x = getPosx(UniteDetruite);int y = getPosy(UniteDetruite);
        jeu[x][y] = NULL;
        free(UniteDetruite);
    }
    else{
        printf("cannot supp__");
    }
}

void Move(Tunite *Unite,TplateauJeu jeu,int startc,int endc,bool clock_c,int x,int y){
    if(clock_c){
        for(int i = startc;i<=endc;i++){

        }
    }
    else{
        for(int i = endc;i>=startc;i--){

        }
    }
}
/*
void MoveUp(Tunite *Unite,TplateauJeu jeu){
    int x = getPosx(Unite);
    int y = getPosy(Unite);
    if((x>=1&&x<=5)&&((y>=1&&y<=7)||(y>=11&&y<=17))){

    }
    else if((x>=6&&x<=9)&&((y>=1&&y<=7)||(y>=11&&y<=17))){

    }
    else if((x>=1&&x<=5&&y==18)||(x>=1&&x<=3&&y==8)){

    }
    else if((x>=6&&x<=9&&y==18)||(x>=7&&x<=9&&y==8)){

    }
    else if((x>=1&&x<=5&&y==0)||(x>=1&&x<=3&&y==10)){

    }
    else if((x>=6&&x<=9&&y==0)||(x>=7&&x<=9&&y==10)){

    }
    else if(x==0&&((y>=1&&y<=7)||(y>=11&&y<=17))){

    }
    else if(x==10&&((y>=1&&y<=7)||(y>=11&&y<=17))){

    }
    else if((x==0&&y==0)||(x==0&&y==10)){

    }
    else if((x==0&&y==8)||(x==0&&y==18)){

    }
    else if((x==10&&y==0)||(x==10&&y==10)){

    }
    else if((x==10&&y==8)||(x==10&&y==18)){

    }
    else if(x==4&&y==10){

    }
    else if(x==5&&y==10){

    }
    else if(x==6&&y==10){

    }
    else if(x==4&&y==8){

    }
    else if(x==5&&y==8){

    }
    else if(x==6&&y==8){

    }
    else if(x==5&&y==9){

    }
*/
/*
TListePlayer quiEstAPortee(TListePlayer player, Tunite *uneUniteDeLautreJoueur) {
    TListePlayer courant = player;
    TListePlayer sortie = NULL;//la liste des unites a portee
    while(getSuivant(courant) != NULL){
        if((abs(getPosX(uneUniteDeLautreJoueur) - getPosX(courant->pdata)) <=  getPortee(getPdata(courant))) && (abs(getPosY(uneUniteDeLautreJoueur) - getPosY(getPdata(courant))) <=  getPortee(getPdata(courant)))) {
            ajoutEnFin(sortie, getPdata(courant));
        }
        courant = getSuivant(courant);
    }
    return sortie;
}
*/
Tunite* UnOuDeux(int *el){
    if(rand()%3 == 1){
        el --;
        return creeGargouille(0, 0, 0);
    }
    else{
        el --;
        return creeArcher(0, 0, 0);
    }
}

Tunite* AcheteUnite(int *elixirEnStockduJoueur){
    int el = elixirEnStockduJoueur;
    if(el < 1 || rand()%3 == 2 || el >= 5){
        return creeTour(0, 0, 0);
        //retourner NULL causait des problèmes, j'ai décidé de retourner "creeTour". Il faudra simplement vérifier si ça a été retourné lors de l'appel de cette fonction
    }
    else{
        if(el < 2){
            el --;
            return creeGargouille(0, 0, 0);
        }
        else{
            if(el < 3){
                return UnOuDeux(el);
            }
            else{
                if(el < 4){
                    if(rand()%4 == 3){
                        el --;
                        return creeDragon(0, 0, 0);
                    }
                    else{
                        return UnOuDeux(el);
                    }
                }
                else{
                    if(el < 5){
                        int pif = rand()%5;
                        if(pif == 4){
                            el --;
                            return creeChevalier(0, 0, 0);
                        }
                        else{
                            if(pif == 3){
                            el --;
                            return creeDragon(0, 0, 0);
                            }
                            else{
                                return UnOuDeux(el);
                            }
                        }
                    }
                }
            }
        }
    }
}

void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite, TplateauJeu jeu, int equipe){
    //equipe 1 = bleu, 2 = rouge
    if(!listeVide(*player) && nouvelleUnite != creeTour(0, 0, 0)){
        player = ajoutEnFin(*player, nouvelleUnite);
        int j;
        if(equipe == 1){
            j = 15;
        }
        else{
            if(equipe == 2){
                j = 3;
            }
        }
        if(equipe == 1 || equipe == 2){ //on ne passe dans l'ajout que si les valeurs de l'équipe sont valables
            for(int i = 3; i < 8; i++){
                if(jeu[i][j] == NULL){
                    setPosX(nouvelleUnite, i);
                    setPosY(nouvelleUnite, j);
                    setTeam(nouvelleUnite, equipe);
                    jeu[i][j] = nouvelleUnite;
                }
            }
        }
    }
}

