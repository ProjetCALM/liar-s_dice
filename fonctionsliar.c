/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "headerliar.h"


void letTheGameBegin(player table[]) {
    
    
    
}



void turn(player a/*table[], int p*/) {
    int rnd=1, end=0, i=0; //rnd permet de suivre le nombre de tours, end permet de mettre fin à la partie lorsqu'un joueur a gagné
    char enter=0; //utile pour certaines confirmations
    for(rnd=1; end != 6; rnd++) {
        system("cls");
        //for(i=0; i<p; i++) { //pour faire le tour de la table en fonction du nombre de participants
            printf("Joueur actuel : %s\n", a/*table[]*/.nom);
            printf("Jetons : %d\n\n", a/*table[]*/.bet);
        
            if(rnd == 1) {
              printf("ROLL THE DICE !\n");
              while (enter != '\r' && enter != '\n') { enter = getchar(); }
               enter=0;
               a/*table[p]*/=rollTheDice(a/*table[p)*/);
            }
        
            else {
                printf("Des actuels :\n");
                printTheDice(a/*table[p)*/);
            }
            end=rnd*2;
            locate(0, 12);
            printf("Press [Enter] to begin next turn.");
            while (enter != '\r' && enter != '\n') { enter = getchar(); }
            enter=0;
        //}
    }
        
    
}

void initTable(player table[], joueur rep[], int n) {
    int i=0, j=0;
    for (i=0; i<n; i++) {
        table[i].score=rep[i].score;
        strcpy(table[i].nom, rep[i].nom);
        for(j=0; j<5; j++) {
            table[i].dice[j]=0;
        }
        table[i].bet=100;
    }
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
