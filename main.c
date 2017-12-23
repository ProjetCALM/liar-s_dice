/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: prico
 *
 * Created on 20 décembre 2017, 16:55
 */

#include <stdio.h>
#include <stdlib.h>
#include "headerliar.h"

/*
 * 
 */
int main(int argc, char** argv) {
    /*int id=0; //tracks le nombre de joueurs
    int p=0; //tracks le nombre de participants
    joueur rep[];*/
    srand(time(0));
    player a;
    char temp[NOM]="Test";
    strcpy(a.nom, temp);
    a.score=0;
    a.bet=100;
    turn(a);
    
    joueur rep[REP];
    
    return (EXIT_SUCCESS);
}

joueur liarDice(joueur rep[], int p) {
    player table[p]; //crée un tableau contenant toutes les données de tous les joueurs de la table
}

