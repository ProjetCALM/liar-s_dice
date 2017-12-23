/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "headerliar.h"


void liarDice(joueur rep[]) {
    int p=0;
    srand(time(0));
    system("cls");
    printf("**** LIAR'S DICE ****\n\nEntrer nombre de participants : ");
    scanf("%d", &p);
    
    player table[p]; //crée un tableau contenant toutes les données de tous les joueurs de la table
    initTable(table, rep, p);
    printf("Initialise");
    turn(table, p);
}








void letTheGameBegin(player table[]) {
    
    
    
}



void turn(player table[], int p) {
    int rnd=1, end=0, i=0; //rnd permet de suivre le nombre de tours, end permet de mettre fin à la partie lorsqu'un joueur a gagné
    char enter=0; //utile pour certaines confirmations
    for(rnd=1; end != 6; rnd++) {
        for(i=0; i<p; i++) { //pour faire le tour de la table en fonction du nombre de participants
            system("cls");
            printf("Joueur actuel : %s\n", table[i].nom);
            printf("Jetons : %d\n\n", table[i].bet);
        
            if(rnd == 1) {
                printf("ROLL THE DICE !\n");
                fflush(stdin);
                while (enter != '\r' && enter != '\n') { enter = getchar(); }
                enter=0;
                table[i]=rollTheDice(table[i]);
            }
        
            else {
                printf("Des actuels :\n");
                printTheDice(table[i]);
            }
            end=rnd*2;
            locate(0, 12);
            printf("Press [Enter] to begin next turn.");
            while (enter != '\r' && enter != '\n') { enter = getchar(); }
            enter=0;
        }
    }
        
    
}

void initTable(player table[], joueur rep[], int p) {
    int i=0, j=0;
    for (i=0; i<p; i++) {
        table[i].score=rep[i].score;
        strcpy(table[i].nom, rep[i].nom);
        for(j=0; j<5; j++) {
            table[i].dice[j]=0;
        }
        table[i].bet=100;
    }
}

player rollTheDice(player a) {
    int i=0;
    for(i=0; i<5; i++) { 
        a.dice[i]=(rand()%6)+1; //calcule un résultat entre 1 et 6 pour le dé
    }
    printTheDice(a);
    return a;
} //note : pas certain que le fonctionnement des pointeurs permette de récupérer le résultat des dés. A vérifier.
 
void locate(int x,int y) { 
    //permet de replacer le curseur à l'endroit désiré, afin que votre prochain printf se fasse à l'endroit que vous souhaitez
    //fonctionne grâce à windows.h, pensez à l'inclure. Ne marchera probablement pas pour toi, Adrien.
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=x;
    C.Y=y;
    SetConsoleCursorPosition(H,C);
}

void printTheDice(player a) { //permet de lancer et d'afficher les 6 dés
    int i=0;
    for(i=0; i<5; i++) { 
        if(a.dice[i] == 1) { //affiche le dé qui nous intéresse en fonction du résultat
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("|         |");
            locate(14*i, 6);
            printf("|    O    |");
            locate(14*i, 7);
            printf("|         |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 2) {
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("|       O |");
            locate(14*i, 6);
            printf("|         |");
            locate(14*i, 7);
            printf("| O       |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 3) {
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("|       O |");
            locate(14*i, 6);
            printf("|    O    |");
            locate(14*i, 7);
            printf("| O       |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 4) {
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("| O     O |");
            locate(14*i, 6);
            printf("|         |");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 5) {
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("| O     O |");
            locate(14*i, 6);
            printf("|    O    |");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 6) {
            locate(14*i, 4);
            printf("+---------+");
            locate(14*i, 5);
            printf("| O     O |");
            locate(14*i, 6);
            printf("| O     O |");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("+---------+\n");
        }
    }
}
