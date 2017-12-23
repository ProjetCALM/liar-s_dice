/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: prico
 *
 * Created on 20 décembre 2017, 16:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //permet d'utiliser la fonction locate

#include "headerrep.h"

#define NOM ((int)100) //taille max du nom de joueur
#define REP ((int)50) //taille max du répertoire de joueurs

typedef struct Player
{   //crée une structure similaire à Joueur, en ajoutant un tableau prenant en compte les 5 dés, ainsi qu'une valeur pour le pari
    char nom[NOM];
    int score;
    int dice[5];
    int bet;
}player;


void liarDice(joueur rep[]);
void letTheGameBegin(player table[]);
void turn(player table[], int);
void initTable(player table[], joueur rep[], int);
player rollTheDice(player);
void printTheDice(player);
void locate(int, int);
