#ifndef JOUEUR
#define JOUEUR

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct
{
    int x;
    int y;
    int vie;
    int attaque;
    int defence;
    char **inventaire;
} joueur;

joueur * alloue_joueur();

void suppr_joueur(joueur * j);

#endif /* end of include guard: JOUEUR */
